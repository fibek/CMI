#include <bits/stdc++.h>

using namespace std;

int T[16];
int base = 8;

void add(int v, int x) {
    /* v -= 1; */
    v += base;
    T[v] += x;
    v /= 2;
    while(v > 0) {
	T[v] = T[2*v] + T[2*v+1];
	v /= 2;
    }
}

void remove(int v, int x) {
    /* v -= 1; */
    v += base;
    T[v] -= x;
    v /= 2;
    while(v > 0) {
	T[v] -= x;
	v /= 2;
    }
}

int query(int a, int b) {
    a += base-1;
    b += base+1;
    int result = 0;
    while(a/2 != b/2) {
	if(a%2 == 0)
	    result += T[a+1];
	if(b%2 == 1)
	    result += T[b-1];
	a/=2;
	b/=2;
    }
    return result;
}

int main() {
    for(int i = 2, j=1; i <= 9; i++, j++)
	add(j,i);

    for(int x : T)
	cout << x << ' ';
    cout << '\n';
    /* add(1,3); */
    /* remove(1,3); */    
    cout << query(2,6) << '\n';
}

