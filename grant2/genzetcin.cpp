#include <bits/stdc++.h>

using namespace std;

int main() {
    srand(time(NULL));
   for(int i = 0; i < 1000000; i++)  
       if(rand()%1 == 0)
           cout << 'R';
        else
            cout << 'A';

   for(int i = 0; i < 1000000; i++)  
       cout << rand()%10000+1 << ' ' << rand()%10000+1 << '\n';
}

