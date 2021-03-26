#include <bits/stdc++.h>

using namespace std;

int update_position(vector<int> P, vector<bool> &visited, int pos, int n) {
    if(P[pos] != 0) {
	int new_pos = pos+P[pos];
	visited[pos] = true;
	if(visited[new_pos]) 
	    return -1;
	return update_position(P, visited, new_pos, n);
    } 
    return pos;
}

void take_turn(vector<int> P, vector<bool> visited, int pos, int n, int moves, int &min_moves) {
    int i = 1;
    if(!visited[pos]) {
	visited[pos] = true;
	int new_pos = pos+i;
	while(new_pos < n && i <= 6) {
	    int new_pos = pos+i;
    	    int position = update_position(P, visited, new_pos, n);
	    if(position == n-1) {
		if(min_moves > -1)
		    min_moves = min(moves, min_moves);
		else
		    min_moves = moves;
		return;
	    } else if(position > 0) 
		take_turn(P, visited, position, n, moves+1, min_moves);
    	    i++;
    	}
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> P(n);
    vector<bool> visited(n);
    for(int i = 0; i < n; i++) 
	cin >> P[i];
    int min_moves = -1;
    take_turn(P, visited, 0, n, 1, min_moves); 
    cout << min_moves << '\n';
}
