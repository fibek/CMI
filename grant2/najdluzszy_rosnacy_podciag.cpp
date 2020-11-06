#include <bits/stdc++.h>

using namespace std;

int main() {
   int T[10];
   srand(time(NULL));
   for(int i = 0; i < 10; i++) {
       T[i] = rand()%21;
       cout << T[i] << ' ';
   }
   cout << '\n';

   int s = 0, najdl=0, i = 0, inds, indk;
   while( i < 10 ) {
       s = i; 
       while( T[s] < T[s+1] && s < 9) {
            s++;
       }
       if( s-i+1 > najdl ) {
           inds= i;
           indk= s;
           najdl = s-i+1;
       }
       i = s+1;
       s = 0;
   }
   cout << najdl << '\n' << inds << ' ' << indk << '\n';
}

