#include "validator.h"

#include <cstring>
#include <string>

#include <cmath>
#include <iostream>
#include <regex>

void run()
{
    int maxN = Arg("maxN", 1'000'000);
    int maxR = Arg("maxR", 1'000'000'000);
    int minR = Arg("minR",1);

    int n = Int(1, maxN);

    Endl();

    vector rows = SpacedInts(n,minR,maxR);

    Eof();
}