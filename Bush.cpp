#include "Bush.h"

#include <iostream>

// Constructs a bush with a hazard inidicator given by hazard
Bush::Bush(int iD, bool hazard, bool fire)
{
    // Sets the ID of the bush to the given ID number
    Bush::iD = iD;

    // Sets the hazard indicator of the bush to the given state
    Bush::hazard = hazard;

    // Sets the fire indicator of the bush to the given state
    Bush::fire = fire;
}

// Deconstructs a bush
Bush::~Bush()
{
}

int Bush::ID()
{
    return iD;
}

// Outputs whether the bush is hazardous 
// and returns the hazardous indicator as a boolean
bool Bush::IsHazard()
{
    if (hazard)
    {
        std::cout << "This bush is hazardous." << std::endl;

    }
    else
    {
        std::cout << "This bush is not hazardous." << std::endl;   
    }

    return hazard;
}

// Outputs whether the bush is on fire 
// and returns the fire indicator as a boolean
bool Bush::OnFire()
{
    if (fire)
    {
        std::cout << "This bush is on fire!" << std::endl;

    }
    else
    {
        std::cout << "This bush is not on fire." << std::endl;   
    }

    return fire;
}

// Performs controlled burning on the bush
// and sets the hazard indicator of the bush to false
void Bush::ControlledBurning()
{
    hazard = false;

    // Output result
    std::cout << "The hazard has been eliminated." << std::endl;
}

// Eliminates the bush fire
// and sets the fire indicator of the bush to false
void Bush::EliminateFire()
{
    fire = false;

    // Output result
    std::cout << "The fire has been eliminated." << std::endl;
}