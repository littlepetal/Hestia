#include "Reservoir.h"

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
    return waterLevel;
}

// Returns the gas level
int Reservoir::CheckGasLevel()
{
    return gasLevel;
}

// Tops up the water level of the reservoir by numWater
void Reservoir::WaterTopUp(int numWater)
{
    waterLevel += numWater;
}

// Tops up the gas level of the reservoir by numGas
void Reservoir::GasTopUp(int numGas)
{
    gasLevel += numGas;
}