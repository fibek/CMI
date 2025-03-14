#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> VI;
typedef long long LL;

#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define PB push_back
#define ST first
#define ND second
template<class V, class E> struct Graph {
	struct Ed : E {
		int v; 
		Ed(E p, int w) : E(p), v(w) {}
	};
	struct Ve : V,vector<Ed> {};
	vector<Ve> g;
	Graph(int n=0) : g(n) {}
	void EdgeU(int b, int e, E d = E()) {
	    Ed eg(d,e); eg.rev=SIZE(g[e])+(b==e); g[b].PB(eg);
	    eg.rev=SIZE(g[eg.v=b])-1; g[e].PB(eg);
	}
bool EulerU(VI &ce) {
	int v=-1;
	ce.clear();
	VI l, st(SIZE(g), 0), of(SIZE(g)+1, 0);
	REP(x, SIZE(g)) {
		of[x+1] = of[x] + (st[x] = SIZE(g[x]));
		if ((st[x] & 1) || (v == -1 && st[x])) v = x;
	}
	vector<bool> us(of[SIZE(g)],0);
	if (v != -1) l.PB(v);
	while(SIZE(l)) {
		v = l.back();
		while(st[v] && us[of[v]+st[v]-1]) --st[v];
		if (!st[v]) {
			l.pop_back();
			ce.PB(v);
		} else {
			int u=g[v][--st[v]].v;
			us[of[u]+g[v][st[v]].rev]=1;
			l.PB(v=u);
		}
	}
	return 2*(SIZE(ce)-1) == of[SIZE(g)];
}
};
struct Vs{};
struct Ve{int rev;};

int main() {
	int n,m,b,e;
	cin >> n >> m;
	Graph<Vs,Ve> gr(n+1);
	REP(x,m) {
		cin >> b >> e;
		gr.EdgeU(b-1, e-1);
	}
	REP(x,n) 
		if (SIZE(gr.g[x]) & 1) gr.EdgeU(x, n);
	cout << max(1, SIZE(gr.g[n])/2) << endl;
	VI res;
	gr.EulerU(res);
	FORD(x,SIZE(res)-1,0) {
		int y = x;
		while (y >= 0 && res[y] != n) y--;
		if (x > y+1) {
			cout << x-y;
			FOR(z,y+1,x) cout << " " << res[z]+1;
			cout << endl;
		}
		x=y;
	}
	return 0;
}
