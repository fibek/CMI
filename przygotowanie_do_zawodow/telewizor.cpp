#include <iostream>

using namespace std;

long long nwd(long long a, long long b) {
	if(b == 0)
		return a;
	return nwd(b, a%b);
}
int main() {
	ios_base::sync_with_stdio(0);
	long long a,b,x,y,nwdxy, c = 0, w, h, minw, minh;
	cin >> a >> b >> x >> y;
	// nwd(6,4) = 2   x = 6/2 y =4/2 => (3,2)
	nwdxy = nwd(x,y);
	w = minw = x / nwdxy;
	h = minh = y / nwdxy;
	while(w <= a && h <= b) {
		w += minw;
		h += minh;
		c++;	
	}
	cout << c << '\n';
}
