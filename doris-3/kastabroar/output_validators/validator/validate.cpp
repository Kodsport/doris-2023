#include "validate.h"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

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



int main(int argc, char **argv) {
    init_io(argc, argv);

    int n, m;
    judge_in >> n >> m;

    set<pii> edges;
    rep(i,0,m) {
        int a, b;
        judge_in >> a >> b;
        if (a>b) swap(a,b);
        edges.emplace(a,b);
    }

    auto check = [&](istream& sol, feedback_function feedback){
        string ans;
        if(!(sol >> ans))
        {
            author_message("Did not answer \"Ja\" or \"Nej\"");
            feedback("Expected more output");
        }
        for (char& c : ans) c = (char)toupper(c);

        if(ans != "JA" && ans != "NEJ")
        {
            author_message("Did not answer \"Ja\" or \"Nej\"");
            feedback("Answer \'%s\' is not {YES|NO}", ans.c_str());
        }

        if(ans == "NEJ") {
            string trailing;
            if(sol >> trailing)
            {
                author_message("You should not output anything after \"Nej\"");
                feedback("Trailing output");
            }
            return tuple<int,int,int>(false, int(1e9), false);
        }

        int k;
        if(!(sol >> k))
        {
            author_message("Did not output number of moves");
            feedback("Expected more output");
        }

        set<pii> edgescopy(edges);

        tuple<int,int,int> ret_on_error = tuple<int,int,int>(true, k, false); // We can't give WA if they fail here, as they still potentially have 50% score
        rep(i,0,k) {
            int a,b,u,v;
            if(!(sol >> a >> b >> u >> v))
            {
                author_message("Outputted too few moves");
                return ret_on_error; //feedback("Expected more output");
            }
            for (auto x : {a,b,u,v}) if(x < 1 || x > n)
            {
                author_message("Outputted vertex that does not exist");
                return ret_on_error; //feedback("vertex x = %d is out of range", x);
            }

            if (a>b) swap(a,b);
            if (u>v) swap(u,v);
            pii rem = {a,b};
            pii add = {u,v};
            if (edgescopy.find(rem)==edgescopy.end())
            {
                author_message("You tried removing an edge that doesn't exist");
                return ret_on_error; //feedback("Edge does not exist"); 
            }
            if (edgescopy.find(add)!=edgescopy.end())
            {
                // Although not explicit in statement, doing this will be suboptimal and thus WA. No need to report this
                return ret_on_error; //feedback("Edge already exists"); 
            } 
            edgescopy.erase(rem);
            edgescopy.insert(add);
        }

        UF uf(n+1);
        int components = n;
        for (auto edge : edgescopy)
        {
            components -= uf.join(edge.first, edge.second);
        }
        
        bool works = components == 1;

        string trailing;
        if(sol >> trailing)
        {
            author_message("Outputted more than K lines of moves");
            return ret_on_error; //feedback("Trailing output");
        }
        return tuple<int,int,int>(true, k, works);
    };

    tuple<int,int,int> judge = check(judge_ans, judge_error);
    tuple<int,int,int> author = check(author_out, wrong_answer);

    bool correctdecision = get<0>(judge)==get<0>(author);
    bool correctamount = false;
    if (get<1>(author) < get<1>(judge))
    {
        if (get<2>(author)) judge_error("Contestant found better solution");
        else
        {
            author_message("Did not identify the correct amount of moves");
            wrong_answer("Did not identify the correct amount of moves");
        }
    }
    else if (get<1>(author) == get<1>(judge))
    {
        correctamount = true;
    }
    else 
    {
        correctamount = false;
    }

    if (!correctdecision)
    {
        author_message("Did not correctly identify whether possible");
        wrong_answer("Did not correctly identify whether possible");
    }
    if (!correctamount)
    {
        author_message("Did not identify the correct amount of moves");
        wrong_answer("Did not identify the correct amount of moves");
    }
    if (get<1>(judge)!=0&&!get<2>(author)&&get<2>(judge))
    {
        author_message("Correct number of moves, but moves did not make everything connected");
        accept_with_score(0.5);
    }

    accept_with_score(1.0);
}
