#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> V(n), SUBS_L; 
    vector<bool> F(n, true);
    for(int i = 0; i < n; i++)
	cin >> V[i];

    int current;
    for(int i = 0;i < n; i++) {
	current = V[i];
	int count{1};
	if(F[i]) {
	/* cout << V[i] << ' '; */
	    for(int j = i+1; j < n; j++) {
		if(count < n-1 && F[j]) {
		    int diff = abs(current-V[j]);
	            if(diff != 0 && (diff == 1 || diff%11 == 0) ) {
		       current = V[j];
		       /* cout << V[j] << ' '; */
	    	       F[j] = false;
		       count++;
		    }
		}
	    }
	}
	F[i] = false;
	SUBS_L.push_back(count);
	/* cout << '\n'; */
    }
    sort(SUBS_L.begin(), SUBS_L.end());
    auto it = SUBS_L.rbegin();
    int sum_l = *it;
    it++;
    sum_l += *it;
    cout << sum_l << '\n';
    /* for(auto x : SUBS_L) */
	/* cout << x << ' '; */
    /* cout << '\n'; */
}

