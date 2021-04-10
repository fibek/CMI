#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::string;

typedef long long ll;

string sum(string a, string b) {
    /* cout << "SUM\n"; */
    while(a.size() > b.size())
	b = '0'+b;
    while(b.size() > a.size())
	a = '0'+a;
    int carry = 0;
    string result;
    for(int i = a.size(); i >= 0; i--) {
	int tmp = a[i]-'0'+b[i]-'0';
	result = char((tmp+carry)%10+'0')+result;
	carry = tmp/10;
    }
    if(carry != 0)
	result = char(carry+'0')+result;
    return result;
}

string divide_2(const string &a) {
    /* cout << "DIV " << a << '\n'; */
    if(a == "0" || a == "1")
	return "0";
    string result;
    int dividend = 0;
    for(int i = 0; i < a.size(); i++) {
	dividend += a[i] - '0';
	result += char(dividend / 2 + '0');
	dividend = (dividend % 2) * 10;
    }
    if(result[0] == '0')
	result.erase(0,1);
    return result;
}


string product_1(string a, char d) {
    /* cout << "PRO1\n"; */
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

string product_ru(string a, string b) {
    /* cout << "PROD\n"; */
    if(a == "0")
	return "0";
    string result = "0";
    while(b > "0") {
	if(b[b.size() - 1] % 2 > 0)
	    result = sum(result, a);
	a = product_1(a, '2');
	b = divide_2(b);
    }
    return result;
}

string ll2str(ll a) {
    /* cout << "2STR\n"; */
    string result;
    while(a > 0) {
	char ch = a%10+'0';
	result = ch+result;
	a/=10;
    }
    return result;
}

string modulo(string a, ll n) {
    /* cout << "MOD\n"; */
    ll result;
    for(int i = 0; i < a.size(); i++)
	result = (result * 10 + a[i]-'0') % n;
    string res = ll2str(result);
    if(res == "")
	return "0";
    return res;
}

string modular_power(string p, string exponent, ll n) {
    /* cout << "MOD_POW " << exponent << '\n'; */
    if(exponent == "0")
	return "1";
    string x = modular_power(p, divide_2(exponent), n);
    x = modulo(product_ru(x,x), n);
    if(modulo(exponent, 2) != "0")
	x = modulo(product_ru(x,p), n);
    return x;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    string x,y;
    ll n;
    cin >> t;
    for(int i = 0; i < t; i++) {
	cin >> x >> y >> n;
	cout << modular_power(x,y,n) << '\n';
    }
}

