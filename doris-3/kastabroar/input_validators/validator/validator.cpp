#include "validator.h"
#include <cmath>
#include <cstring>
#include <sstream>
#include <string_view>
#include <set>

struct UF {
	vector<int> e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};


void run() {
	int maxn = Arg("n", 1e5);
	int maxm = Arg("m", 1e5);
	int acyclic = Arg("acyclic", 0);

	int n = Int(0, maxn); Space(); int m = Int(0, maxm); Endl();

	set<pair<int,int>> edges;
	UF uf(n);
	for (int i = 0; i < m; i++)
	{
		int a = Int(1, n);
		Space();
		int b = Int(1, n);
		Endl();
		a--; b--;
		assert(a!=b);
		if (a>b) swap(a,b);

		pair<int,int> p = {a,b};
		assert(edges.find(p)==edges.end());
		edges.insert(p);
		if (acyclic) assert(uf.join(a,b));
	}
	Eof();
}
