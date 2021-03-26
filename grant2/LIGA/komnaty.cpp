#include <bits/stdc++.h>

using namespace std;

void bfs(vector<vector<char>> V, int x, int y,int i, vector<vector<int>> &visited, int &perimeter) {
    queue<pair<int,int>> Q;
    pair<int, int> xy = make_pair(x, y);
    Q.push(xy);
    int xx,yy;
    while(!Q.empty()) {
        pair<int,int> v = Q.front();
        Q.pop();
        xx = v.first;
        yy = v.second;
        if(visited[xx][yy]==0) {
            if(V[xx-1][yy] == '.') {
                xy = make_pair(xx-1, yy);
                Q.push(xy);
            } else {
                perimeter++;
            }

            if(V[xx+1][yy] == '.') {
                xy = make_pair(xx+1, yy);
                Q.push(xy);
            } else {
                perimeter++;
            }

            if(V[xx][yy+1] == '.') {
                xy = make_pair(xx, yy+1);
                Q.push(xy);
            } else {
                perimeter++;
            }

            if(V[xx][yy-1] == '.') {
                xy = make_pair(xx, yy-1);
                Q.push(xy);
            } else {
                perimeter++;
            }
        }
        visited[xx][yy] = i;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<char>> V;
    vector<vector<int>> visited;
    vector<int>T;
    int n;
    cin >> n;
    V.resize(n+100);
    visited.resize(n+100);
    T.resize(n);
    for(int i = 0; i < n; i++) {
        V[i].resize(n+100);
        visited[i].resize(n+100,0);
        for(int j = 0; j < n; j++)
            cin >> V[i][j];
    }
    int x,y, per;
    for(int i = 1; i <= n; i++) {
        cin >> x >> y;
        per = 0;
        if(visited[x-1][y-1]!=0)
        {
         cout<<T[visited[x-1][y-1]]<<'\n';
        }
        else
        {
         bfs(V, x-1,y-1,i, visited, per);
         T[i]=per;
         cout << per << '\n';
        }

    }
}
