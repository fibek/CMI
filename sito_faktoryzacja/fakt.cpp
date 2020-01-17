#include <iostream>

using namespace std;

int main() {
	int a, i = 2;
	cin >> a;
	while(a != 1) 
		if(a % i == 0) {
			a /= i;
			cout << i << ' ';	
		}
		else 
			i++;
	cout << '\n';
}
