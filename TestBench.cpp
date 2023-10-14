#include "TestBench.h"

#include <iostream>

TestBench::TestBench()
{
    // Create the bushland
    std::cout << "Initialising the bushland..." << std::endl;

    // Initialise the bushland
    bushland = new Maps();

    // Create the reservoir
    std::cout << "Initialising the reservoir..." << std::endl;

    // Initialise the reservoir
    reservoir = new Reservoir();

    // Create the bush fire control devices
    std::cout << "Setting up the bushfire control devices..." << std::endl;

    hydroBlaster = new HydroBlaster();
    flameThrower = new FlameThrower();
}

TestBench::~TestBench()
{
    
}

void TestBench::RunSufficientReservoirForHazards ()
{
    // Create the bushes and add them to the vector of bushes
    std::cout << "Creating the bushes..." << std::endl;

    bushes.push_back(new Bush(0, hazardous, notOnFire));
    bushes.push_back(new Bush(1, notHazardous, notOnFire));
    bushes.push_back(new Bush(2, hazardous, notOnFire));
    bushes.push_back(new Bush(3, hazardous, notOnFire));
    bushes.push_back(new Bush(4, notHazardous, notOnFire));

    std::cout << std::endl;

    // Give the reservoir level 100 water and gas initially
    reservoir->WaterTopUp(100);
    reservoir->GasTopUp(100);

    // Check the water and gas level of the reservoir
    reservoir->CheckWaterLevel();
    reservoir->CheckGasLevel();

    // Load the bush fire control devices with the required resources
    hydroBlaster->Load(reservoir, 10);
    flameThrower->Load(reservoir, 10);

    // Perform controlled burning in the bushland
    std::cout << "\nPerforming controlled burning in the bushland...\n" << std::endl;

    // Add the hazardous bushes into the hazard map
    for (int i = 0; i < bushes.size(); i++)
    {
        if (bushes[i]->IsHazard() == true)
        {
            // Save the bush to the map of hazards
            bushland->AddHazard(bushes[i]->ID(), bushes[i]);

            // Eliminate the hazard
            flameThrower->Deploy(bushland, bushes[i]->ID());
        }    
    }

    CheckControlledBurningOutcome();
}

void TestBench::CheckControlledBurningOutcome()
{
    // Check controlled burning outcome
    std::cout << "\nChecking result of controlled burning...\n" << std::endl;

    // Counter for any remaining hazards
    int remainingHazards = 0;

    // Count the number of remaining hazards
    for (int i = 0; i < bushes.size(); i++)
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
}

void TestBench::CheckFireEliminationOutcome()
{
    // Check fire elimination outcome
    std::cout << "\nChecking result of fire elimination...\n" << std::endl;

    // Counter for any remaining fires
    int remainingFires = 0;

    // Count the number of remaining fires
    for (int i = 0; i < bushes.size(); i++)
    {
        if (bushes[i]->OnFire() == true)
        {
            // Increment the ramaining fires counter
            remainingFires++;
        }
    }

    // Indicate successfulness
    if (remainingFires != 0)
    {
        std::cout << "Mission failed... Bad bot" << std::endl;
    }
    else
    {
        std::cout << "Mission succeeded... Good bot" << std:: endl;
    }
}