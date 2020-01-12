#include <iostream>

bool s[10000];

int main() {
	int n;
	std::cin >> n;
	for(int i = 2 ; i*i <= n; i++) {
		if(!s[i]) {
			for(int k=i*i; k <= n; k =k+i)
				s[k] = 1;
		}
	}
	for(int i = 2; i <= n; i++)
		if(!s[i]) 
			std::cout << i << ' ';
	std::cout << '\n';
}
			
	
