
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,m,a,b;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
    }   
    if(n <= m) 
        cout << "TAK\n";
    else
        cout << "NIE\n";
}

