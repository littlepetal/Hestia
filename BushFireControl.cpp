#include "Maps.h"
#include "Reservoir.h"
#include "Device.h"
#include "Bush.h"

#include <stdio.h>
#include <iostream>

int main() 
{
    // Simulate controlled burning mode

    // Define constants
    const int numOfBushes = 5;

    const bool hazardous = true;
    const bool notHazardous = false;

    // Define constants
    const bool onFire = true;
    const bool notOnFire = false;

    // Create the maps
    std::cout << "\nInitialising the bushland...\n" << std::endl;

    Maps* bushland = new Maps();

    // Create the reservoir
    std::cout << "\nInitialising the reservoir...\n" << std::endl;

    Reservoir* reservoir = new Reservoir();

    // Give the reservoir level 100 water and gas initially
    reservoir->WaterTopUp(100);
    reservoir->GasTopUp(100);

    // Check the water and gas level of the reservoir
    reservoir->CheckWaterLevel();
    reservoir->CheckGasLevel();

    // Create the bush fire control devices
    std::cout << "\nSetting up the bushfire control devices...\n" << std::endl;

    HydroBlaster* hydroBlaster = new HydroBlaster();
    FlameThrower* flameThrower = new FlameThrower();

    // Load the bush fire control devices with the required resources
    hydroBlaster->Load(reservoir, 10);
    flameThrower->Load(reservoir, 10);

    // Create the bushes
    std::cout << "\nCreating the bushes...\n" << std::endl;

    Bush* bush0 = new Bush(0, hazardous, notOnFire);
    Bush* bush1 = new Bush(1, notHazardous, notOnFire);
    Bush* bush2 = new Bush(2, hazardous, notOnFire);
    Bush* bush3 = new Bush(3, hazardous, notOnFire);
    Bush* bush4 = new Bush(4, notHazardous, notOnFire);

    // Place the bushes in an array to simulate the pushfire manager bot
    // discovering them one by one
    Bush* bushes[numOfBushes] = {bush0, bush1, bush2, bush3, bush4};

    std::cout << "\nPerforming controlled burning in the bushland...\n" << std::endl;

    for (int i = 0; i < numOfBushes; i++)
    {
        if (bushes[i]->IsHazard() == true)
        {
            // Save the bush to the map of hazards
            bushland->AddHazard(bushes[i]->ID(), bushes[i]);

            // Eliminate the hazard
            flameThrower->Deploy(bushland, bushes[i]->ID());
        }
    }

    // Check controlled burning outcome
    std::cout << "\nChecking result of controlled burning...\n" << std::endl;

    // Counter for any remaining hazards
    int remainingHazards = 0;

    // Count the number of remaining hazards
    for (int i = 0; i < numOfBushes; i++)
    {
        if (bushes[i]->IsHazard() == true)
        {
            // Increment the ramaining hazards counter
            remainingHazards++;
        }
    }

    // Indicate successfulness
    if (remainingHazards != 0)
    {
        std::cout << "Mission failed... Bad bot" << std::endl;
    }
    else
    {
        std::cout << "Mission succeeded... Good bot" << std:: endl;
    }

    return 0;
}