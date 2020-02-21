#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int n, z, j;
	int T[10000];
	int S[10000] = {0};
	cin >> n;
	for(int i = 0; i < n; i++) 
		cin >> T[i];

	z = 0;
	//for(j = 1; j < n; j++,z++) {
	j = 1;
	while( j <= n) {
		while( T[j-1] < T[j] ) {
			S[z]++;
			j++;
		} 
		j++;
		z++;
	}
		
	cout << z << '\n';
	for(int i = 0; i < z; i++)
		cout << S[i]+1 << ' ';			
	cout << '\n';
}
