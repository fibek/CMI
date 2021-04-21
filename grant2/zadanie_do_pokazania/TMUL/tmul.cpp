#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

string sum(const string &a, const string &b) {
    string c;
    int ia = a.size() - 1, ib = b.size() - 1;
    int carry = 0;
    while(ia >= 0 || ib >= 0) {
	int result = carry;
	if(ia >= 0) {
	    result += a[ia] - '0';
	    ia--;
	}
	if(ib >= 0) {
	    result += b[ib]-'0';
	    ib--;
	}
	c = char(result % 10 + '0') + c;
	carry = result/10;
    }
    if(carry > 0)
	c = '1'+c;
    return c;
}

string product_1(const string &a, char d) {
    if(d == '0')
	return "0";
    int d_int = d-'0';
    int carry = 0;
    string product;
    for(int i = a.size() - 1; i >= 0; i--) {
	int result = (a[i] - '0') * d_int + carry;
	product = char(result % 10 + '0') + product;
	carry = result / 10;
    }
    if(carry > 0)
	product = char(carry + '0') + product;
    return product;
}

bool smaller(const string &a, const string &b) {
    if(a.size() == b.size())
	return a < b;
    return a.size() < b.size();
}

string subtract(const string &a, const string &b) {
    string c;
    int ia = a.size() - 1, ib = b.size() - 1;
    int borrow = 0;
    while(ia >= 0) {
	int result = a[ia] - '0' - borrow;
	ia--;
	if(ib >= 0) {
	    result -= b[ib] - '0';
	    ib--;
	}
	if(result < 0) {
	    result += 10;
	    borrow = 1;
	} else
	    borrow = 0;
	c = char(result + '0') + c;
    }
    int zeros = 0;
    while(zeros < c.size() && c[zeros] == '0')
	zeros++;
    if(zeros == c.size())
	return "0";
    return c.substr(zeros);
}

string difference(const string &a, const string &b) {
    if(smaller(a,b))
	return '-'+subtract(b,a);
    return subtract(a,b);
}

string karatsuba(const string &a, const string &b) {
    if(a.size() == 1)
	return product_1(b, a[0]);
    if(b.size() == 1)
	return product_1(a, b[0]);
    int as = a.size(), bs = b.size();
    int n = max(as,bs)/2;
    while(n>=as || n>=bs)
	n /= 2;
    string a_1 = a.substr(0, a.size() - n),
	   a_0 = a.substr(a.size() - n),
	   b_1 = b.substr(0, b.size() - n),
	   b_0 = b.substr(b.size() - n);
    string k0 = karatsuba(a_0, b_0),
	   k2 = karatsuba(a_1, b_1),
	   k1 = karatsuba(sum(a_0, a_1), sum(b_0, b_1));
    k1 = difference(k1, sum(k2, k0));
    return sum(k2 + string(2*n, '0'), sum(k1 + string(n, '0'), k0));
}

ll str2ll(string a) {
    ll result;
    for(int i = 0; i < a.size(); i++) 
	result = result*10+a[i]-'0';
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    string x,y;
    cin >> t;
    for(int i = 0; i < t; i++) {
	cin >> x >> y;
	if(x.size() < 20 && y.size() < 20)
	    cout << str2ll(x)*str2ll(y) << '\n';
	else 
	    cout << karatsuba(x,y) << '\n';
    }
}
