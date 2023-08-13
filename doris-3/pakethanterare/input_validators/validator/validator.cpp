#include "validator.h"
#include <cmath>
#include <cstring>
#include <sstream>
#include <string_view>
#include <vector>
#include <map>

typedef long long ll;
using pll = pair<ll, ll>;

void run() {
	int max_t = Arg("max_t", 1e6);
	int max_b = Arg("max_b", 1e3);
	int all_diff_1 = Arg("all_diff_1", 0);

	istringstream inp1{Line()};

	string ts, bs;
	inp1 >> ts >> bs;


	if (ts.find("0") == 0)
			die("leading zero added to t");
	if (bs.find("0") == 0)
			die("leading zero added to b");

	int t = stoi(ts), b = stoi(bs);
	if (t < 1 || t > max_t) {
			die("t is out of range");
	}
	if (b < 1 || b > max_b) {
			die("b is out of range");
	}
	if (t * b > 1e6) {
			die("b is out of range");
	}

	vector<int> storeCounts;
	istringstream inp2{Line()};

	for (int i = 0; i < b; i++) {
		string tis;
		inp2 >> tis;

		if (tis.find("0") == 0)
				die("leading zero added to ti");

		int ti = stoi(tis);

		if (ti < 1 || ti > t) {
				die("ti is out of range");
		}

		storeCounts.push_back(ti);
	}


	map<string, int> packs;
	for (int i = 0; i < t; i++) {
		istringstream inpi{Line()};
		string name, vs;

		inpi >> name >> vs;

		if (vs.find("0") == 0)
				die("leading zero added to v");

		int v = stoi(vs);

		if (v < 1 || v > 1e3) {
				die("v is out of range");
		}

		if (packs.count(name))
				die("name is not unique");

		if (name.length() < 3 || name.length() > 10)
				die("name length is out of range");

		packs[name] = v;
	}

	for (int i = 0; i < b; i++) {
			map<string, int> pack_sel;
			int diff = 0;
			for (int j = 0; j < storeCounts[i]; j++) {
					istringstream inpi{Line()};
					string name, vs;

					inpi >> name >> vs;

					if (vs.find("0") == 0)
							die("leading zero added to v");

					int v = stoi(vs);

					if (!packs.count(name))
							die("Undefined pack name");

					if (v < 1 || v > packs[name]) {
							die("old v is out of range");
					}

					if (pack_sel.count(name))
							die("pack said twice in one store");

					if (packs[name] != v)
							diff += 1;

					pack_sel[name] = v;
			}

			if (all_diff_1 && diff != 1)
				die("not all_diff_1");
		}
}
