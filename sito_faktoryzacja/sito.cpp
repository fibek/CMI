#include <iostream>

using namespace std;

bool sito[1000];

int main() {
	int n;
	cin >> n;
	for(int i = 2; i*i <= n; i++) 
		if(!sito[i])
			for(int k = i*i; k <= n; k += i) 
				sito[k] = true;
	for(int i = 2; i <= n; i++) 
		if(!sito[i])
			cout << i << ' ';
	cout << '\n';
}	
