#include "validator.h"
#include <cstring>

typedef long long ll;

void run() {
    int n = Int(0, Arg("maxn", 100000));
    Endl();
    string c = Line();
    if (c != "storlek" && c != "antal")
        die("Preference was not a correct value, was: '" + c + "'");
    // assert(c.size() == 1);
    assert(c == "storlek" || c=="antal");
    if (Arg("preferamount",0)) assert(c=="antal");

    set<pair<int,int>> seen;
    set<int> seensums;
    for (int i = 0; i < n; i++) {
        int a = Int(0, 1000000000);
        Space();
        int b = Int(0, 1000000000);
        Endl();
        seen.insert(make_pair(a,b));
        seensums.insert(a+b);
    }
    assert(seen.size()==n);

    if (Arg("uniquesums",0))
    {
        assert(seensums.size()==n);
    }
}