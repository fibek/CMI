#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n,L,a, t,l;
	cin >> n >> L >> a;
	vector<int> work_hours;
	for(int i = 0; i < L; i++)
		work_hours.push_back(0);
	for(int i = 0; i < n; i++) {
		cin >> t >> l;
		for(int j = 0, in = t; j < l; j++, in++)
			work_hours[in] = 1;
	}
	int breaks = 0, j, tmp;
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
}
