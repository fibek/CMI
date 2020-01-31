#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main() {
	int n;
	long long x,y;
	priority_queue<pair<long long, long long> > points;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x >> y;
		points.push( make_pair(x,y) );
	}
	cout << points.top().first + points.top().second << '\n';	
}
