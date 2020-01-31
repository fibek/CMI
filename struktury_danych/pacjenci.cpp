#include <iostream>

using namespace std;

int main() {
	int n;
	int a[100000];
	int o[100000];
	cin >> n;
	for(int i = 1; i <= n; i++) 
		cin >> a[i];

	int tmp = a[1];
	int l = n;
	bool all = true;
	int k = 1;
	while(all && k <= n) {
		if(tmp == a[k]) {
			o[k] = k;
			k++;
		} else {
			all = false;
			for(int i = 1; i <= k; i++)
				o[i] = 0;
		}
	}
	if(!all) {	
		for(int i = 1; i <= n; i++) {
			tmp = a[i];
			if(o[tmp] == 0) 
				o[tmp] = i;
			else {
				while(o[l] != 0)
					l--;	
				o[l] = i;
			}
		}
	}

	for(int i = 1; i <= n; i++) 
		cout << o[i] << ' ';
	cout << '\n';
}
