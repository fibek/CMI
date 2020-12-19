#include <bits/stdc++.h>

using namespace std;

int main() {
    int a,b;
   string s;
   cin >> a >> s >> b;
   if( s == "|" ) 
       cout << (a | b) << '\n';
   else if( s == "&" )
       cout << (a & b) << '\n';
   else if(s == "^" )
       cout << (a ^ b) << '\n';
   else if( s == "<<" )
       cout << (a << b) << '\n';
   else if( s == ">>" )
       cout << (a >> b) << '\n';



}

