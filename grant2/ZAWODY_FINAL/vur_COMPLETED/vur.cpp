#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct person{
    ll height;
    ll head_perimeter;
    ll sum;
    int id;
    person(ll a, ll b, int c) {
	height = a; head_perimeter = b; sum = a+b; id = c;
    }
};

bool comp(person a, person b) {
    return a.sum < b.sum;
}

ll match(vector<person> M, vector<person> W) {
    ll sum{ };
    vector<bool> M_paired(M.size(), false), W_paired(M.size(), false);
    for(auto i : M) {
	for(auto j : W) {
	    if(i.sum > j.sum) {
	       if(!M_paired[i.id] && !W_paired[j.id] &&
		  i.height > j.height && 
		  i.head_perimeter > j.head_perimeter) {
		   M_paired[i.id] = true;
		   W_paired[j.id] = true;
		   sum += i.sum - j.sum;
	       }
	    } else {
		return -1;
	    }
	}
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<person> M,W;
    ll sum_all_M{ }, sum_all_W{ };
    for(int i = 0; i < n; i++) {
	ll a,b;
	cin >> a >> b;
	M.push_back( person(a,b,i) );
	sum_all_M += a+b;
    }
    for(int i = 0; i < n; i++) {
	ll a,b;
	cin >> a >> b;
	W.push_back( person(a,b,i) );
	sum_all_W += a+b;
    }
    sort(W.begin(), W.end(), comp);
    sort(M.begin(), M.end(), comp);

    ll res = match(M,W);
    if(res > 0 && res == sum_all_M-sum_all_W) 
	cout << res << '\n';
    else
	cout << "NIE\n";
}

