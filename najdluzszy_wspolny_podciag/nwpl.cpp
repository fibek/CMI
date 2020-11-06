//NWPL
#include <iostream>

using namespace std;

int S[10000][10000] = {0}; //zakladajac, ze max dlugosc ciagu to 10000

int main() {
	string s1,s2;
	cin >> s1 >> s2;
	int najd = 0;
	for(int i = 1; i <= s1.size(); i++) 
		for(int j = 1; j <= s2.size(); j++) 
			if( s1[i-1] == s2[j-1] ) {
				S[i][j] = S[i-1][j-1]+1;
				najd = (S[i][j] > najd) ? S[i][j] : najd;
			} else
				S[i][j] = max(S[i-1][j], S[i][j-1]);
	cout << najd << '\n';
}
