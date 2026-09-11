#include "validator.h"

void run() {
	int max_n = Arg("max_n", 1e5);
	int max_t = Arg("max_t", 1e5);
	int all_s_same = Arg("all_s_same", 0);

	int t = Int(1, max_t);
	Space();
	int n = Int(1, max_n);
	Endl();

	vector<int> times = SpacedInts(n, 1, t*60);

	if (all_s_same) {
		for (int i = 0; i < n; i++) {
			assert(times[i] == times[0]);
		}
	}
}
