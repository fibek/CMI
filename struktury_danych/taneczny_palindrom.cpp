#include <iostream>

using namespace std;

int main() {
	int n,a,b;
	int k[1001];
	cin >> n >> a >> b;
	for(int i = 0; i < n; i++) 
		cin >> k[i];	

	for(int i = 0; i < n; i++) {
		if(k[i] == 0)
			k[i] = 1;	
	}
