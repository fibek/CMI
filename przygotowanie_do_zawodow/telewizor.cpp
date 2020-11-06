#include <iostream>

using namespace std;

long long nwd(long long a, long long b) {
	if(b == 0)
		return a;
	return nwd(b, a%b);
}
int main() {
	ios_base::sync_with_stdio(0);
	long long a,b,x,y,d, c = 0;
	cin >> a >> b >> x >> y;
	// nwd(6,4) = 2   x = 6/2 y =4/2 => (3,2)
	d = nwd(x,y);
	x /= d; y /= d;
	cout << min(a / x, b / y) << endl;
	return 0;
}
