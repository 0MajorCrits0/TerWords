#include "WorldSystem/WorldManager.h"
#include "WorldSystem/WorldDatabase.h"
#include "WorldSystem/WorldGenerator.h"
#include "WorldSystem/WorldChunkSelector.h"

#include "World.h"
#include "PlayerMessage.h"
#include "Config.h"
#include "WorldsMessage.h"

void WorldManager::init(WorldsMessage* worlds)
{
    this->db = new WorldDatabase(PATHSAVES);
    this->generator = new WorldGenerator();
    /*
    World* world1 = new World();
    world1->id = 0;
    world1->width = 8;
    world1->height = 8;
    world1->position = vec2(0, -20);
    world1->velocity = vec2(0, 0);
    this->db->createWorld(world1);
    this->generator->generate(world1, db);
    delete world1;

    World* world2 = new World();
    world2->id = 1;
    world2->width = 8;
    world2->height = 8;
    world2->position = vec2(0, 20);
    world2->velocity = vec2(0, 0);
    this->db->createWorld(world2);
    this->generator->generate(world2, db);
    delete world2;
    */
    worlds->worlds = db->readWorlds();

    this->selector = new WorldChunkSelector();

    this->debug = false;
}

void WorldManager::update(PlayerMessage* player, WorldsMessage* worlds)
{
    
    vec2 curPos = player->position;
    curPos.x = (int)curPos.x - (int)curPos.x % CHUNKSIZE;
    curPos.y = (int)curPos.y - (int)curPos.y % CHUNKSIZE;

    vec2 oldPos = player->oldPosition;
    oldPos.x = (int)oldPos.x - (int)oldPos.x % CHUNKSIZE;
    oldPos.y = (int)oldPos.y - (int)oldPos.y % CHUNKSIZE;

    if (/*curPos != oldPos*/ true) 
    {
        for (World* world : worlds->worlds) {

            world->visibleChunksPos.clear();
            selector->getChunks(world, player); 

            for (auto chunk : worlds->chunks[world])
                delete chunk;
            worlds->chunks[world].clear();

            if (debug)  
                worlds->chunks[world] = db->readAllChunks(world);
            else
                worlds->chunks[world] = db->readChunks(world);
        }
    }

    player->oldPosition = player->position;
    
}

void WorldManager::deinit()
{
    delete selector;
    delete generator;
    delete db;
}

void WorldManager::switchDebugging()
{
    debug = !debug;
}