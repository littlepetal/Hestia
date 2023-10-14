#ifndef _RESERVOIR_H
#define _RESERVOIR_H

//--Reservoir Interface---------------------------------------------------
class Reservoir
{
    public:

        // Constructs an empty reservoir
        Reservoir();

        // Destructs the reservoir
        ~Reservoir();

        // Returns the water level
        int CheckWaterLevel();

        // Returns the gas level
        int CheckGasLevel();

        // Tops up the water level of the reservoir by numWater
        void WaterTopUp(int level);

        // Tops up the gas level of the reservoir by numGas
        void GasTopUp(int level);

        // Give out numBombs amount of water bombs
        bool SupplyWater(int level);

        // Give out numBombs amount of flame bombs
        bool SupplyGas(int level);

    private:

        // Water level indicating the number of water bombs in the reservoir
        int waterLevel;

        // Gas level indicating the number of flame bombs in the reservoir
        int gasLevel;

};

#endif