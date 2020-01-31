#include <iostream>

using namespace std;

int main() {
	int n;
	int a[100000];
	int o[100000];
	cin >> n;
	for(int i = 1; i <= n; i++) 
		cin >> a[i];

	int tmp;
	int l = n;
	for(int i = 1; i <= n; i++) {
		tmp = a[i];
		if(o[tmp] == 0) 
			o[tmp] = i;
	//	else if(tmp == 1 && a[i] == 1)
	//		o[i] = i;
		else {
			while(o[l] != 0)
				l--;	
			o[l] = i;
		}
	}
	for(int i = 1; i <= n; i++) 
		cout << o[i] << ' ';
	cout << '\n';
}
