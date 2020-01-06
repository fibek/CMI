// Zadanie 58.
#include <iostream>
#include <algorithm>
#include <utility>
#include <fstream>
#include <array>
#include <string>

using namespace std;

const int pom = 1095;

int main() { 
	ifstream s1("dane_systemy1.txt");	
	ifstream s2("dane_systemy2.txt");	
	ifstream s3("dane_systemy3.txt");	
	ofstream out("wyniki_systemy.txt");

	array<pair<string, string>, pom> wyniki1;
	array<pair<string, string>, pom> wyniki2;
	array<pair<string, string>, pom> wyniki3;

	int a,b;
	for(int k=0; k < pom; k++) {
		s1 >> a >> b;
		wyniki1[k] = make_pair(a, b);
	}
	for(int k=0; k < pom; k++) {
		s1 >> a >> b;
		wyniki2[k] = make_pair(a, b);
	}
	for(int k=0; k < pom; k++) {
		s1 >> a >> b;
		wyniki3[k] = make_pair(a, b);
	}
	
	out << "58.1:\n\n";
	
	
	
	s1.close();
	s2.close();
	s3.close();
	out.close();
	
}

void from_system(string s) {
		
}
