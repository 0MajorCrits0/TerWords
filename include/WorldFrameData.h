#pragma once

#include <vector>

class ActiveArea;

class WorldFrameData
{
public:
    std::vector<ActiveArea*> areas;
    ~WorldFrameData();
};