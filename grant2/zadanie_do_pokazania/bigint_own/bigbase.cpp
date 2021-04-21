#include <bits/stdc++.h>

using namespace std;

const int BASE = 10;
const int BZ = 1;

struct BigInt {
    vector<int> num;

    BigInt() {
	num.resize(1, 0);
    }

    BigInt(string s) {
	int ss = s.size();
	num.resize( (ss+BZ-1)/BZ );
	for(int i = 0; i < ss; i++)
	    num[ (ss-i-1)/BZ ] = 10*num[ (ss-i-1)/BZ ] + s[i]-'0';
    }

    int size() { return num.size(); }

    void display() {
	for(auto x = num.rbegin(); x != num.rend(); x++)
	    cout << *x;
	cout << '\n';
    }
    
};

BigInt operator+(BigInt a, BigInt b) {
    BigInt sum;
    while(b.num.size() < a.num.size())
        b.num.push_back(0);
    while(b.num.size() > a.num.size())
        a.num.push_back(0);
    int s = a.size();
    sum.num.resize(s);
    int carry = 0;
    for(int i = 0; i < s; i++) {
        int tmp = a.num[i] + b.num[i];
        sum.num[i] = (tmp+carry)%BASE;
        carry = tmp/BASE;
    }
    if(carry > 0)
        sum.num.push_back(carry);
    return sum;
}

BigInt operator-(BigInt a, BigInt b) {
    BigInt diff("0");
    bool negative = false;
    if(a.size() < b.size()) {
	BigInt tmp = b;
	b = a;
	a = tmp;
	negative = true;
    }
    while(b.num.size() < a.num.size())
        b.num.push_back(0);
    int s = a.size();
    diff.num.resize(s);
    int borrow = 0;
    for(int i = 0; i < s; i++) {
	int tmp = a.num[i]-b.num[i]+borrow;
	borrow = 0;
	if(tmp < 0) {
	    tmp += BASE;
	    borrow = -1;
	}
	diff.num[i] = tmp;	
    }
    if(borrow < 0)
	diff.num.push_back(borrow);
    if(negative) 
	diff.num[s-1] *= -1;
    return diff;
}

/* BigInt karatsuba(BigInt a, BigInt b) { */
/*     BigInt z0, z1, z2, */
/* 	   h0, h1, */ 
/* 	   l0, l1; */
/*     int n = min(a.size(), b.size())/2; */
/*     l0.num(a.num.begin(), a.num.begin()+n); */
/*     h0.num(a.num.begin()+n, a.num.end()); */
/*     l1.num(b.num.begin(), b.num.begin()+n); */
/*     h1.num(b.num.begin()+n, b.num.end()); */

/*     z0 = karatsuba(l0, l1); */
/*     z1 = karatsuba(); */
/*     z2 = karatsuba(h0, h1); */

/*     return 0; */
/* } */

int main() {
    BigInt a("124125125"), b("51235"), sumab, proab, diffab;
    a.display(); b.display();
    sumab = a+b; sumab.display();
    diffab = b-a; diffab.display();
    /* proab = karatsuba(a,b); proab.display(); */
}
