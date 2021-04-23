#include <bits/stdc++.h>

using namespace std;

const int BASE = 1000000;
const int BZ = 6;

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

BigInt product_1(BigInt a, int n) {
    BigInt result;
    result.num.resize(a.size());
    int carry = 0;
    int s = a.num.size();
    for(int i = 0; i < s; i++) {
	int tmp = a.num[i]*n + carry;
	result.num[i] = tmp%BASE;
	carry = tmp/BASE;
    }
    if(carry > 0) 
	result.num.push_back(carry);
    return result;
}

BigInt div_2(BigInt a) {
    BigInt result;
    result.num.resize(a.size());
    if(a.size() == 1 && (a.num[0] == 0 || a.num[0] == 1)) {
	BigInt t("0");
	return t;
    }
    int dividend = 0;
    for(int i = a.size()-1; i >= 0; i--) {
	dividend += a.num[i];
	int tmp = dividend/2;
	result.num[i] = tmp;
	dividend = (dividend % 2)*10;
    }
    if(result.num.back() == 0)
	result.num.pop_back();
    return result;
}

BigInt operator*(BigInt a, BigInt b) {
    BigInt result("0");
    if(a.num.back() == 0) 
	return result;
    while(b.num.back() > 0) {
	if(b.num.front() % 2 > 0)
	    result = result+a;
	a = product_1(a,2);
	b = div_2(b);
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string sa,sb;
    cin >> n;
    for(int i = 0; i < n; i++) {
	cin >> sa >> sb;
	BigInt a(sa), b(sb);
	BigInt result = a*b;
	result.display();
    }
}

/* BigInt karatsuba(BigInt a, BigInt b) { */
/*     int n = max(a.size(), b.size())/2; */

/*     BigInt a_0,a_1,b_0,b_1; */
/*     a_1.num.assign(a.num.begin(), a.num.begin()+n); */
/*     a_0.num.assign(a.num.begin()+n, a.num.end()); */
/*     b_1.num.assign(b.num.begin(), b.num.begin()+n); */
/*     b_0.num.assign(b.num.begin()+n, b.num.end()); */

/*     BigInt k0,k1,k2; */
/*     k0 = karatsuba(a_0, b_0); */
/*     k2 = karatsuba(a_1, b_1); */
/*     k1 = karatsuba(a_0+a_1, b_0+b_1); */
    
/*     BigInt tmp1(string(2*n, '0')), */
/* 	   tmp2(string(n, '0')); */
/*     BigInt tmp3,tmp4; */
/*     tmp3.num.assign(k2.num.begin(), k2.num.end()); */  
/*     tmp3.num.insert(tmp3.num.end(), tmp1.num.begin(), tmp1.num.end()); */
/*     tmp4.num.assign(k1.num.begin(), k1.num.end()); */  
/*     tmp4.num.insert(tmp4.num.end(), tmp2.num.begin(), tmp2.num.end()); */
/*     return tmp3+(tmp2+k0); */
/* } */

