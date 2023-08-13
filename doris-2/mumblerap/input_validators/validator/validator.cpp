#include "validator.h"

#include <cstring>
#include <string>

#include <cmath>
#include <iostream>
#include <regex>

void run()
{
    int n_max = Arg("maxN", 1'000'000);

    int AMaxDigits = Arg("AMaxDigits", 9);
    int last = Arg("last", 0);

    int n = Int(1, n_max);

    Endl();

    string s = Line();

    if (s.length() != n)
    {
        die("n is not equal to the length of the string");
    }


    long long curr = 0;
    long long max = 0;

    long long lastNum = 0;

    for (char c : s)
    {
        if ('0' <= c && c <= '9')
        {
            curr = curr * 10 + c - '0';
            max = std::max(max, curr);
            lastNum = curr;
        }
        else
        {
            curr = 0;
        }
    }


    

    if (max > pow(10, AMaxDigits))
    {
        die("Answer is larger than 10^" + to_string(AMaxDigits) +". The answer is " + to_string(max));
    }

    if (last && lastNum != max)
    {
        die("The answer is not the last number in the string.");
    }

    Eof();
}