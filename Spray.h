#ifndef _SPRAY_H
#define _SPRAY_H

#include "Maps.h"

class Spray
{
    public:

        // Constructs a spray for deploying water and flame bombs
        Spray();

        // Deconstructs the spray
        ~Spray();

        // Increases the number of available water bombs by numWaterBombs amount
        void LoadWaterBombs(int numWaterBombs);

        // Throws a water bomb at the bush indicated by bushID
        void ThrowWaterBomb(Maps* bushland, int bushID);

        // Increases the number of available flame bombs by numFlameBombs amount
        void LoadFlameBombs(int numFlameBombs);

        // Throws a flame bomb at the bush indicated by bushID
        void ThrowFlameBomb(Maps* bushland, int bushID);

    private:

        // Keeps tracks of number of available water bombs
        int waterBombs;

        // Keeps tracks of number of available flame bombs
        int flameBombs;
};

#endif