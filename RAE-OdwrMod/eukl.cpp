#include <iostream>

using namespace std;

// nwd(188, 12) = 188 x + 12 y

int x, y;
void eukl(int a, int b) {
	int tmp;
	if(b == 0) return;	
	eukl(b, a%b);
	tmp = y;
	y = x - a/b * y;
	x = tmp;
}

int main() {
	int a,b;
	x = 1, y = 0;
	a = 188; b = 12;
	eukl(a, b);
	cout << "NWD(a,b): " << a << " X: " << x << " Y: " << y << "\n";
}
