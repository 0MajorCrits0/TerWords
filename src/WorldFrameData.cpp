#include "WorldFrameData.h"

WorldFrameData::~WorldFrameData()
{
    for (ActiveArea* area : areas)
        delete area;
    areas.clear();
}