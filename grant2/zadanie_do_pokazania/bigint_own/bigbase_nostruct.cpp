#include <bits/stdc++.h>

using namespace std;

typedef vector<int> BigInt;

const int BASE = 100, BZ = 2;

void display(BigInt n) {
    for(auto x = n.rbegin(); x != n.rend(); x++)
	cout << *x;
    cout << '\n';
}

BigInt add(BigInt a, BigInt b) {
    BigInt sum;
    while(a.size() < b.size())
	a.push_back(0);
    while(b.size() < a.size())
	b.push_back(0);
    sum.resize(a.size(), 0);
    int carry = 0;
    for(int i = b.size()-1; i >= 0; i--) {
	int tmp = a[i]+b[i];
	sum[i] = (tmp+carry)%BASE;
	carry = tmp/BASE;
    }
    if(carry > 0)
	sum.push_back(carry);
    return sum;
}

int main() {
    BigInt a,b,n;
    string sa,sb;
    cin >> sa >> sb;
    int ss1 = sa.size(), ss2 = sb.size();
    a.resize( (ss1+BZ-1)/BZ );
    b.resize( (ss2+BZ-1)/BZ );
    for(int i = 0; i < ss1; i++) 
	a[(ss1-i-1)/BZ] = 10*a[(ss1-i-1)/BZ]+sa[i]-'0';
    for(int i = 0; i < ss2; i++) 
	b[(ss2-i-1)/BZ] = 10*b[(ss2-i-1)/BZ]+sb[i]-'0';
    n = add(a,b);
    display(n);
}

