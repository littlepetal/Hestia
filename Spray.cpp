#include "Spray.h"
#include "Bush.h"
#include "Maps.h"

#include <iostream>

// Constructs a bush with a hazard inidicator given by hazard
Spray::Spray()
{
    // Initialise number of available water bombs
    waterBombs = 0;

    // Initialise number of available flame bombs
    flameBombs = 0;
}

// Deconstructs a bush
Spray::~Spray()
{
    
}

// Increases the number of available water bombs by numWaterBombs amount
void Spray::LoadWaterBombs(int numWaterBombs)
{
    waterBombs += numWaterBombs;
}

// Throws a water bomb at the bush indicated by the bush ID
void Spray::ThrowWaterBomb(Maps* bushland, int bushID)
{
    // Decrement number of available water bombs
    waterBombs--;

    // Put out the fire
    bushland->LocateFire(bushID)->EliminateFire();    
}

// Increases the number of available flame bombs by numFlameBombs amount
void Spray::LoadFlameBombs(int numFlameBombs)
{
    flameBombs += numFlameBombs;
}

// Throws a flame bomb at the bush indicated by the bush ID
void Spray::ThrowFlameBomb(Maps* bushland, int bushID)
{
    // Decrement number of available flame bombs
    flameBombs--;

    // Rid the hazard
    bushland->LocateHazard(bushID)->ControlledBurning();     
}