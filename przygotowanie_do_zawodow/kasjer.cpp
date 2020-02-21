#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n,L,a, t,l;
	cin >> n >> L >> a;
	//int T[1000000000] = {0};
	vector<int> work_hours;
	for(int i = 0; i < L; i++)
		work_hours.push_back(0);
	for(int i = 0; i < n; i++) {
		cin >> t >> l;
		for(int j = 0, in = t; j < l; j++, in++)
			work_hours[in] = 1;
	}
	int breaks = 0, j, tmp;
/*
	for(int i = 0; i <= L-a; i+=a) {
		j = i;
		j+a > L ? tmp = L  : tmp = j+a;
		cout << j << ' ' << tmp << '\n';
		while(work_hours[j] == 0 && j < tmp) 
			j++;
		cout << j << "==" << i+a << '\n';
		if( j == i+a ) 
			breaks++;
		cout << i << "+" << a << '\n';
	}
*/
	int i = 0, in=0;
	while(in < L) {
		if(work_hours[in] == 0 && in+a <= L) {
			i = 0;
			while(work_hours[in] == 0 && i < a) {
				i++;	
				in++;
			}
			if(i == a )
				breaks++;
		} else
			in++;
	}
	cout << breaks << '\n';
	/*for(int i = 0; i < L; i++)
		cout << work_hours[i] << ' '; 
	cout << '\n'; */
}
