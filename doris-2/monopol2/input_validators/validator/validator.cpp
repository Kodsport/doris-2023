#include "validator.h"

#include <cstring>
#include <string>

void run() {
    int n_max = Arg("nMax", 11);
    int n_actual;

    istringstream inp{Line()};

    inp >> n_actual;

    vector<int> v = SpacedInts(n_actual, 2, 13);
    set<int> sorted_unique(v.begin(), v.end());
    assert(vector(sorted_unique.begin(), sorted_unique.end()) == v && "elements have to be unique and sorted");
    Eof();
}