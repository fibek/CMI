#include <bits/stdc++.h>

using namespace std;

int main() {
    int T[] = {0, 1, -2, 6, -5, 7, -3};
    int P[7] = {0};

    int ind_max = 0;
    for(int i = 1; i < 7; i++) {
	P[i] = P[i-1] + T[i];
	ind_max = (P[i] > P[ind_max]) ? i : ind_max;
    }
    int sum_max = 0, s;
    for(int i = ind_max; i >= 0; i--) {
	s = P[ind_max]-P[i-1];
	sum_max = (s > sum_max) ? s : sum_max ;
    }
    cout << sum_max << '\n';
}

