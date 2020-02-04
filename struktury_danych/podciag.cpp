#include <iostream>
#include <list>

using namespace std;

int main() {
	string str;
	list<char> s;
	int n, k;
	cin >> n >> k >> str;
	for(int i = 0; i < n; i++)
		s.push_back(str[i]);
	list<char>::iterator it; 
	s.unique();
	it = s.begin();
	char tmp = *it;
	it++;	
	for(int i = 0 ; i < k; i++, it++) {
			if( tmp > *it ) 
				it = s.erase(it);
			tmp = *it;
	}
	int max = s.size() ;
	s.sort();
	s.unique();
	if(s.size() == k)
		cout << max;
	else
		cout << 0;	
	cout << '\n';
}
