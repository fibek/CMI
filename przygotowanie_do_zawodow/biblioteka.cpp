#include <iostream>
#include <list>

using namespace std;

int main() {
	int n, id, count, a;
	char T[200000];
	char ch;
	list<int> shelf;
	list<int>::iterator it;
	list<int>::reverse_iterator itr;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> ch >> id;
		switch(ch) {
			case 'L':
				T[id] = 'L';	
				shelf.push_front(id);
				break;
			case 'R':
				T[id] = 'R';	
				shelf.push_back(id);
				break;
			case '?':
				count = 0;
				if( T[id] == 'L' ) {
					it = shelf.begin();
					while(*it != id) {
						count++;
						it++;
					}
				} else {
					itr = shelf.rbegin();
					while(*itr != id) {
						count++;
						itr++;
					}
				}
				cout << count << '\n';
				break;
		}	
	}
}
