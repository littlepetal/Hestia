#include "Maps.h"
#include "Reservoir.h"
#include "Device.h"
#include "Bush.h"
#include "TestBench.h"

#include <stdio.h>
#include <iostream>

int main() 
{
    // Simulate controlled burning mode
    TestBench* testBench = new TestBench();
    testBench->RunSufficientReservoirForHazards();

    return 0;
}