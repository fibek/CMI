#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, br;
    long long aa,bb,cc;
    string a,b,c;
    cin >> n;
    for(int k = 0; k < n; k++) {
        cin >> a >> b >> c;
        if(a.find('*') != -1) {
            br = a.find('*');
            bb = stoi(b);
            cc = stoi(c);
            for(int i = 0; i < 10; i++) {
                a[br] = i+'0';
                aa = stoi(a);
                if(aa + bb == cc) {
                    cout << i << '\n';
                    break;
                }
            }
        }
        if(b.find('*') != -1) {
            br = b.find('*');
            aa = stoi(a);
            cc = stoi(c);
            for(int i = 0; i < 10; i++) {
                b[br] = i+'0';
                bb = stoi(b);
                if(aa + bb == cc) {
                    cout << i << '\n';
                    break;
                }
            }
        }
        if(c.find('*') != -1) {
            br = c.find('*');
            aa = stoi(a);
            bb = stoi(b);
            for(int i = 0; i < 10; i++) {
                c[br] = i+'0';
                cc = stoi(c);
                if(aa + bb == cc) {
                    cout << i << '\n';
                    break;
                }
            }
        }

    }
}

