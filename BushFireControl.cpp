#include "Bush.h"

#include <stdio.h>

int main() 
{
    Bush testBadBush = Bush(0, true, false);
    Bush testGoodBush = Bush(1, false, false);

    testBadBush.IsHazard();
    testGoodBush.IsHazard();

    testBadBush.OnFire();
    testGoodBush.OnFire();

    return 0;
}