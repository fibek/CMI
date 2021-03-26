#include <bits/stdc++.h>

using namespace std;

#define ZZ c[c.size()-br]-'0'
#define GG b[b.size()-br]-'0'
#define CC a[a.size()-br]-'0'
#define D a[a.size()-br+1]-'0'
#define H b[b.size()-br+1]-'0'


int main() {
    int n,br, cyf;
    cin >> n;
    string a,b,c;
    for(int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        if(a.find('*') != -1) {
            br = a.find('*');
            cyf = ZZ-GG-(D+H)/10;
        } else if(b.find('*') != -1) {
            br = b.find('*');
            cout << ZZ << ' ' << CC << ' ' << D << ' ' << H << '\n';
            cyf = ZZ-CC-(D+H)/10;
        } else {
            br = c.find('*');
            cout << CC << ' ' << GG << ' ' << D << ' ' << H << '\n';
            cyf = CC+GG+(D+H)/10;
        }
        cout << cyf << '\n';
    }
}

