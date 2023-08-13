#include "validator.h"
#include <cmath>
#include <cstring>
#include <sstream>
#include <string_view>

typedef long long ll;
using pll = pair<ll, ll>;

void run() {
	int max_n = Arg("max_n", 1e5);
	int max_t = Arg("max_t", 1e5);
	int all_s_same = Arg("all_s_same", 0);

	istringstream inp1{Line()};

	string ts, ns;
	inp1 >> ts >> ns;


	if (ts.find("0") == 0)
			die("leading zero added to t");
	if (ns.find("0") == 0)
			die("leading zero added to s");

	int t = stoi(ts), n = stoi(ns);
	if (t < 1 || t > max_t) {
			die("t is out of range");
	}
	if (n < 1 || n > max_n) {
			die("n is out of range");
	}

	istringstream inp2{Line()};

	if (all_s_same) {
		string ss1;
		inp2 >> ss1;
		int s1 = stoi(ss1);
		if (ss1.find("0") == 0)
				die("leading zero added to s");

		if (s1 < 1 || s1 >= max_t * 60) {
				die("s is out of range");
		}

		for (int i = 1; i < n; i++) {
			string ss;
			inp2 >> ss;
			if (ss.find("0") == 0)
					die("leading zero added to s");
			int s = stoi(ss);

			if (s != s1) {
				die("s is not same");
			}
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			string ss;
			inp2 >> ss;
			int s = stoi(ss);

		if (ss.find("0") == 0)
				die("leading zero added to s");

			if (s < 1 || s >= max_t * 60){
					die("s is out of range");
			}
		}
	}
}
