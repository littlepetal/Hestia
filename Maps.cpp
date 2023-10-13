#include "Maps.h"

Maps::Maps()
{

}

Maps::~Maps()
{

}

// Adds the specified bush to the hazards map with its ID as the key
void Maps::AddHazard(int bushID, Bush* hazard)
{
    hazardsMap.insert({bushID, hazard});
}

// Adds the specified bush to the fires map with its ID as the key
void Maps::AddFire(int bushID, Bush* fire)
{
    firesMap.insert({bushID, fire});
}

// Returns the pointer to the hazard with the given bush ID
Bush* Maps::LocateHazard(int bushID)
{
    // Check that the desired gate exists
    if(hazardsMap.find(bushID) == hazardsMap.end())
    {
        return nullptr;
    }

    return hazardsMap[bushID];
}

// Returns the pointer to the bushfire with the given bush ID
Bush* Maps::LocateFire(int bushID)
{
    // Check that the desired gate exists
    if(firesMap.find(bushID) == firesMap.end())
    {
        return nullptr;
    }

    return firesMap[bushID];
}