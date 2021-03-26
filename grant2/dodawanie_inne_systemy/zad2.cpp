#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a;
    int diff;
    cin >> a;
    string result(a.size(), '0');
    int i = 0,
	j = a.size()-1;
    while(j >= a.size()/2) {
	if(a[i] != a[j]) {
	    if(a[i] < a[j]) {
		diff = (a[j]-'0')-(a[i]-'0');
		result[i] = diff+'0';
	    } else {
		diff = (a[i]-'0')-(a[j]-'0');
		cout << diff << '\n';
		result[j] = diff+'0';
	    }
	}
	i++;
	j--;
    }
    cout << result.substr(result.find_first_not_of("0")) << '\n';
}

