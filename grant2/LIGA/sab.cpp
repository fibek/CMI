#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, letters_count = 0;
    cin >> n;
    map<int, vector<string>> fragments;
    for(int i = 0; i < 2*n; i++) {
	string s;
	cin >> s;
	fragments[s.size()].push_back(s);
	letters_count += s.size();
    }
    int word_size;
    if(letters_count % n == 1) 
	cout << "nie wiem\n";
    else {
	word_size = letters_count / n;
	auto last_fragment = fragments.rend();
	set<string> possible_chains;
	set<string> candidates;
	int i = 1, j = word_size-1;
	for(auto x : fragments[i]) {
	    for(auto y : fragments[j]) {
		string s1 = x, s2 = y;
		if(s1.size() + s2.size() == word_size) {
		    reverse(s1.begin(), s1.end());
		    reverse(s2.begin(), s2.end());
		    string K[8] = {x+y, y+x, s1+y, y+s1,
		    	       x+s2, s2+x, s1+s2, s2+s1};
		    for(int ii = 0; ii < 8; ii++)
		        if(possible_chains.count(K[ii]) == 0)
		    	possible_chains.insert(K[ii]);
		        else
		    	candidates.insert(K[ii]);
		}
	    }
	    if(i+1+j-1 == word_size) {
		i++;
		j--;
	    }
	}
	if(candidates.size() == 0) 
	    cout << "nie wiem\n";
	else {
	    auto it = candidates.begin();
	    cout << *it << '\n';
	}
    }
}
