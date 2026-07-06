#include "WorldSystem/WorldDatabase.h"

#include "Config.h"
#include "World.h"

#include <unordered_map>
#include <filesystem>
#include <fstream>

struct WorldMetadata
{
    vec2 position;
    vec2 velocity;

    int width;
    int height;
};

WorldDatabase::WorldDatabase(std::string directory)
{
    saveDirectory = directory;
}

std::vector<World*> WorldDatabase::readWorlds()
{
    std::vector<World*> result;

    int id = 0;

    while (true)
    {
        std::string path = saveDirectory + "world" + std::to_string(id) + "/metadata";

        std::ifstream file(path, std::ios::binary);

        if (!file.is_open())
            break;

        WorldMetadata metadata;

        file.read(reinterpret_cast<char*>(&metadata), sizeof(metadata));

        if (!file)
            break;

        World* world = new World;
        world->position = metadata.position;
        world->width = metadata.width;
        world->height = metadata.height;
        world->id = id;
        result.push_back(world);

        id++;
    }

    return result;
}
inline int iddd = 0;

inline int chunkIndex(int x, int y, int worldChunkWidth)
{
    return y * worldChunkWidth + x;
}

std::vector<PositionedChunk*> WorldDatabase::readChunks(World* world)
{
    std::vector<PositionedChunk*> result;

    int w = world->width;
    int h = world->height;

    std::string path =
        saveDirectory + "world" + std::to_string(world->id) + ".bin";

    std::ifstream file(path, std::ios::binary);
    if (!file.is_open())
        return result;

    std::vector<Chunk> buffer(w * h);

    file.read(reinterpret_cast<char*>(buffer.data()),
              buffer.size() * sizeof(Chunk));

    if (!file)
        return result;

    for (const vec2& p : world->visibleChunksPos)
    {
        int cx = (int)p.x;
        int cy = (int)p.y;

        if (cx < 0 || cy < 0 || cx >= w || cy >= h)
            continue;

        int i = chunkIndex(cx, cy, w);

        PositionedChunk* pc = new PositionedChunk;
        pc->position = vec2((float)cx, (float)cy);
        pc->chunk = new Chunk(buffer[i]);

        result.push_back(pc);
    }

    return result;
}

std::vector<PositionedChunk*> WorldDatabase::readAllChunks(World* world)
{
    std::vector<PositionedChunk*> result;

    int w = world->width;
    int h = world->height;

    std::string path = saveDirectory + "world" + std::to_string(world->id) + ".bin";

    std::ifstream file(path, std::ios::binary);
    if (!file.is_open())
        return result;

    std::vector<Chunk> buffer(w * h);
    file.read(reinterpret_cast<char*>(buffer.data()), buffer.size() * sizeof(Chunk));
    file.close();
    
    for (int y = 0; y < h; ++y)
        for (int x = 0; x < w; ++x)
        {
            int i = y * w + x;

            PositionedChunk* pc = new PositionedChunk;
            pc->position = vec2((float)x, (float)y);
            pc->chunk = new Chunk(buffer[i]);

            result.push_back(pc);
        }

    return result;
}

void WorldDatabase::writeChunks(World* world,
                                const std::vector<PositionedChunk*> chunks)
{
    int w = world->width;
    int h = world->height;

    std::string path = saveDirectory + "world" + std::to_string(world->id) + ".bin";

    std::vector<Chunk> buffer(w * h);

    std::ifstream in(path, std::ios::binary);
    if (in.is_open())
        in.read(reinterpret_cast<char*>(buffer.data()), buffer.size() * sizeof(Chunk));
    else
        std::fill(buffer.begin(), buffer.end(), Chunk{});

    for (auto* pc : chunks)
    {
        if (!pc || !pc->chunk)
            continue;

        int x = (int)pc->position.x;
        int y = (int)pc->position.y;

        int i = y * w + x;

        buffer[i] = *pc->chunk;
    }

    std::ofstream out(path, std::ios::binary | std::ios::trunc);
    out.write(reinterpret_cast<char*>(buffer.data()), buffer.size() * sizeof(Chunk));
    out.close();
}

void WorldDatabase::createWorld(World* world)
{
    std::string path =
        saveDirectory + "world" + std::to_string(world->id);

    std::filesystem::create_directories(path);

    WorldMetadata metadata;
    metadata.position = world->position;
    metadata.velocity = world->velocity;
    metadata.width = world->width;
    metadata.height = world->height;

    std::ofstream file(path + "/metadata", std::ios::binary);

    if (!file.is_open())
        return;

    file.write(reinterpret_cast<const char*>(&metadata),
               sizeof(metadata));

    file.close();
}

void WorldDatabase::deleteWorld(uint64_t worldId)
{
    std::filesystem::remove_all(
        saveDirectory + "world" + std::to_string(worldId));
}