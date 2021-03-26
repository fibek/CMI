#include <bits/stdc++.h>

using namespace std;

int main() {
   int n,x;
   vector<int> V;
   cin >> n;
   for(int i = 0; i < n*n; i++) {
       cin >> x;
       V.push_back(x);
   }
   sort(V.begin(), V.end());
   int bia = ( (n*n)-n ) / 2;
   int sum_b, sum_s;
   sum_b = sum_s = 0;
   for(int i = V.size(); i >= 0; i--)
       if(i == bia-1 ) { 
           sum_b += V[i];
           bia--;
       } else 
           sum_s += V[i];

   cout << sum_s - sum_b << '\n';
}

