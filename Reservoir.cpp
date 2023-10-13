#include "Reservoir.h"

#include <iostream>

// Constructs an empty reservoir
Reservoir::Reservoir()
{
    // Initialises the water level of the reservoir
    waterLevel = 0;

    // Initialises the gas level of the reservoir
    gasLevel = 0;
}

// Destructs the reservoir
Reservoir::~Reservoir()
{
    
}

// Returns the water level
int Reservoir::CheckWaterLevel()
{
    // Output water level
    std::cout << "Reservoir now has " << waterLevel << " water" << std::endl;

    // Indicate the water situation
    if (waterLevel <= 10)
    {
        std::cout << "Water level is dangerously low" << std::endl;
    }
    else if (waterLevel <= 50)
    {
        std::cout << "Water level is moderately low" << std::endl;
    }
    else
    {
        std::cout << "Water level is high" << std::endl;
    }
    
    return waterLevel;
}

// Returns the gas level
int Reservoir::CheckGasLevel()
{
    // Output gas level
    std::cout << "Reservoir now has " << gasLevel << " gas" << std::endl;

    // Indicate the gas situation
    if (gasLevel <= 10)
    {
        std::cout << "Gas level is very low" << std::endl;
    }
    else if (gasLevel <= 50)
    {
        std::cout << "Gas level is moderately low" << std::endl;
    }
    else
    {
        std::cout << "Gas level is high" << std::endl;
    }

    return gasLevel;
}

// Tops up the water level of the reservoir
void Reservoir::WaterTopUp(int level)
{
    // Notification
    std::cout << "Topping up water in the resrvoir by " << level << "..." << std::endl;

    // Increase water level by level amount
    waterLevel += level;
}

// Tops up the gas level of the reservoir
void Reservoir::GasTopUp(int level)
{
    // Notification
    std::cout << "Topping up gas in the resrvoir by " << level << "..." << std::endl;

    // Increase gas level by level amount
    gasLevel += level;
}

// Provide water for the bushfire management bot
void Reservoir::ProvideWater(int level)
{
    // Notification
    std::cout << "Providing " << level << " water for the bushfire manager bot..." << std::endl;

    // Decrease water level by level amount
    waterLevel -= level;
}

// Provide gas for the bushfire management bot
void Reservoir::ProvideGas(int level)
{
    // Notification
    std::cout << "Providing " << level << " gas for the bushfire manager bot..." << std::endl;

    // Decrease gas level by level amount
    gasLevel -= level;   
}