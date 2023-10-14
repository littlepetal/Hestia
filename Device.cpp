#include "Device.h"
#include "Maps.h"
#include "Reservoir.h"
#include "Bush.h"

#include <iostream>

// Constructs an empty device
Device::Device()
{
    // std::cout << "Device[CTor]: Device signing on." << std::endl;

    // Initialise number of available resource
    availableResource = 0;
}

// Virtual deconstructor
Device::~Device()
{
    // std::cout << "Device[DTor]: Device signing off." << std::endl;
}

// Loads the device with resource
void Device::Load(Reservoir* reservoir, int level)
{

}

// Deploys the device using the available resources
void Device::Deploy(Maps* bushland, int bushID)
{
   
}

HydroBlaster::HydroBlaster()
{
    // std::cout << "HydroBlaster[CTor]: HydroBlster signing on." << std::endl;
}

HydroBlaster::~HydroBlaster()
{
    // std::cout << "HydroBlaster[DTor]: HydroBlster signing off." << std::endl;
}

// Loads the device with water
void HydroBlaster::Load(Reservoir* reservoir, int level)
{
    // Decrease the water level of the reservoir by level amount
    reservoir->ProvideWater(level);

    // Notification
    std::cout << "Loading " << level << " water for the hydro blaster..." << std::endl;

    // Increases the number of available water by level amount
    availableResource += level;

    // Output result
    std::cout << availableResource << " water is now available for the hydro blaster" << std::endl;
}

// Blasts water at the fire indicated by the bushID
void HydroBlaster::Deploy(Maps* bushland, int bushID)
{
    // Notification
    std::cout << "Deploying hydro blaster..." << std::endl;

    // Put out the fire
    bushland->LocateFire(bushID)->EliminateFire();  

    // Decrement number of available water
    availableResource--;
}

FlameThrower::FlameThrower()
{
    // std::cout << "FlameThrower[CTor]: FlameThrower signing on." << std::endl;
}

FlameThrower::~FlameThrower()
{
    // std::cout << "FlameThrower[DTor]: FlameThrower signing off." << std::endl;
}

// Loads the device with gas
void FlameThrower::Load(Reservoir* reservoir, int level)
{
    // Decrease the gas level of the reservoir by level amount
    reservoir->ProvideGas(level);

    // Notification
    std::cout << "Loading " << level << " gas for the flame thrower..." << std::endl;

    // Increases the number of available gas by level amount
    availableResource += level;

    // Output result
    std::cout << availableResource << " gas is now available for the flame thrower" << std::endl;
}

// Throws flames at the hazard indicated by the bushID
void FlameThrower::Deploy(Maps* bushland, int bushID)
{
    // Notification
    std::cout << "Deploying flame thrower..." << std::endl;

    // Rid the hazard
    bushland->LocateHazard(bushID)->ControlledBurning(); 

    // Decrement number of available gas
    availableResource--;
}
