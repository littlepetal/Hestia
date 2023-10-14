#include "TestBench.h"

#include <stdio.h>
#include <iostream>

int main() 
{
    // Simulate fire elimination mode
    // TestBench* testBench = new TestBench();
    // testBench->RunSufficientReservoirForFires();

    // Simulate controlled burning mode
    // TestBench* testBench = new TestBench();
    // testBench->RunSufficientReservoirForHazards();

    // Simulate fire elimination mode with insufficient water in the reservoir
    TestBench* testBench = new TestBench();
    testBench->RunInsufficientReservoirForFires();

    delete testBench;

    return 0;
}