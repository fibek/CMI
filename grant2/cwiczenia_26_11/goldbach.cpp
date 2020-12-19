#include <bits/stdc++.h>

using namespace std;

bool pierwsza(int a) {
    if(a == 2) 
        return true;
    int d = 2;
    while(d*d <= a) {
        if(a % d == 0)
            return false;
        d++;
    }
    return true;
}

int main() {
   int n,x; 
   cin >> n;
   for(int i = 0; i < n; i++) {
       cin >> x;
       int a = x/2 - 1;
       int b = a + 2;
       bool found = false;
       while(!found) {
            if(pierwsza(a) && pierwsza(b)) {
                found = true;
                cout << a << ' ' << b << '\n';
            }
            a -= 2;
            b += 2;
       }
           
   }
}

