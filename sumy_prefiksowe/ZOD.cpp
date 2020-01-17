#include <iostream>

using namespace std;

int main() {
	int n,z, a,b, x;
	int bd[400000];
	int pfix[400000];
	int pfix2[400000];
	cin >> n >> z;
	for(int i = 0; i < n; i++) 
		cin >> bd[i];

	for(int i = 1; i <= n; i++)  {
		pfix[i] = pfix[i-1] + int(bd[i-1] % 2 == 0);
		pfix2[i] = pfix2[i-1] + int(bd[i-1] % 2 != 0);
	}	
	for(int i = 0; i < z; i++) {
		cin >> a >> b;
		cout << pfix[b] - pfix[a-1] << ' ' << pfix2[b] - pfix2[a-1]<< '\n';
	}
}
