#include <bits/stdc++.h>

using namespace std;

vector<bool> vv;
vector<vector<bool>> V;

int make_move(int n, int x, int y, int m) {
    int xx, yy;
    int squares = 1;
    if(m > 0) {
	xx = x+2; yy = y+1;
	if(xx < n && yy < n)
	    if(!V[xx][yy]) {
		V[xx][yy] = true;
		squares+=make_move(n, xx, yy, m-1);
	    }
	xx = x+2; yy = y-1;
	if(xx < n && yy >= 0)
	    if(!V[xx][yy]) {
		V[xx][yy] = true;
		squares+=make_move(n, xx, yy, m-1);
	    }
	xx = x+1; yy = y+2;
	if(xx < n && yy < n)
	    if(!V[xx][yy]) {
		V[xx][yy] = true;
		squares+=make_move(n, xx, yy, m-1);
	    }
	xx = x-1; yy = y+2;
	if(xx >= 0 && yy < n)
	    if(!V[xx][yy]) {
		V[xx][yy] = true;
		squares+=make_move(n, xx, yy, m-1);
	    }
	xx = x-2; yy = y+1;
	if(xx >= 0 && yy < n)
	    if(!V[xx][yy]) {
		V[xx][yy] = true;
		squares+=make_move(n, xx, yy, m-1);
	    }
	xx = x-2; yy = y-1;
	if(xx >= 0 && yy < n) 
	    if(!V[xx][yy]) {
		V[xx][yy] = true;
		squares+=make_move(n, xx, yy, m-1);
	    }
	xx = x+1; yy = y-2;
	if(xx < n && yy >= 0)
	    if(!V[xx][yy]) {
		V[xx][yy] = true;
		squares+=make_move(n, xx, yy, m-1);
	    }
	xx = x-1; yy = y-2;
	if(xx >= 0 && yy >= 0) 
	    if(!V[xx][yy]) {
		V[xx][yy] = true;
		squares+=make_move(n, xx, yy, m-1);
	    }
    }
    return squares;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x,y,m;
    int squares = 0;
    cin >> n >> x >> y >> m;
    while(!(n == 0 && x == 0 && y == 0 && m == 0)) {
	vv.resize(n, false);
	V.resize(n, vv);
	V[x][y]=1;
	squares = make_move(n,x,y,m);
	cout << squares << '\n';
	cin >> n >> x >> y >> m;
    }
}

