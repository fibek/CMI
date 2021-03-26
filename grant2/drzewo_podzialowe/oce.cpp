#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,c,a,b;
    int T[500000];
    int baza = 2;
    cin >> n;
    while(baza <= n)
	baza*=2;
    cout << baza << '\n';
    /* for(int i = 0; i < n; i++) { */
	/* cin >> c >> a >> b; */
	/* switch(c) { */
	    /* case 0: */
		/* a += baza; */
		/* b += baza; */
		/* if(a==b) */
		    /* cout << T[a] << '\n'; */
		/* else { */
		    /* int suma = T[a]+T[b]; */
		    /* while(a/2 != b/2) { */
			/* if(a%2==0) */
			    /* a = T[a+1]; */
			/* else */
			    /* b = */ 
		    /* } */
		/* break; */
	    /* case 1: */
		/* int p = baza + b; */
		/* while(p > 0) */
		    /* T[p]++; */
		/* p /= 2; */
		/* break; */
	    /* case 2: */
		/* int p = baza + b; */
		/* while(p > 0) { */
		    /* t[p] -= a; */
		    /* p /= 2; */
		/* } */
		/* break; */
	/* }; */
    /* } */
}

