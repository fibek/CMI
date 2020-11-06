#include <bits/stdc++.h>

using namespace std;

int main() {
    int T[10];
    srand(time(NULL));
    for(int i = 0; i < 10; i++) {
        T[i] = rand()%21;
        cout << T[i] << ' ';
    }
    int suma;
    cout << '\n';
    cin >> suma;

    int p=0, s=0;
    for(int k = 0; k < 10; k++) {
        while( s+T[p] <= suma && p < 10) {
            s += T[p];
            if( s == suma ) {
                cout << "TAK:\n";
                exit(0);
            }
            p++;
        }
        s -= T[k];
    }
    cout << "NIE\n";
}
