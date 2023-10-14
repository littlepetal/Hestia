#ifndef _TESTBENCH_H
#define _TESTBENCH_H

#include "Maps.h"
#include "Reservoir.h"
#include "Device.h"
#include "Bush.h"

#include <vector>

class TestBench
{
    public:

        // Constructs a test bench
        TestBench();

        // Deconstructs the test bench
        ~TestBench();

        // Runs the test
        void RunSufficientReservoirForHazards ();

    private:

        // Define constants
        const bool hazardous = true;
        const bool notHazardous = false;

        // Define constants
        const bool onFire = true;
        const bool notOnFire = false;

        // Keep track of the bushland
        Maps* bushland;

        // Keep track of the reservoir
        Reservoir* reservoir;

        // Keep track of the devices on the bushfire manager bot
        HydroBlaster* hydroBlaster;
        FlameThrower* flameThrower;

        // Keep track of all th ebushes
        std::vector<Bush*> bushes;

        // Display controlled burning outcome
        void CheckControlledBurningOutcome();

        // Display fire elimination outcome
        void CheckFireEliminationOutcome();
};

#endif
