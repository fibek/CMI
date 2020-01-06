#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;

const int SIZE = 1095;

int fsys(string s, int sys);

int main() {
	ifstream s1("dane_systemy1.txt");
	ifstream s2("dane_systemy2.txt");
	ifstream s3("dane_systemy3.txt");
	ofstream out("wyniki_systemy.txt");

	int h1[SIZE], h2[SIZE], h3[SIZE];
	int t1[SIZE], t2[SIZE], t3[SIZE];

	string t, h;
	for(int i=0; i < SIZE; i++) {
		s1 >> h >> t;
		h1[i]=fsys(h, 2);
		t1[i]=fsys(t, 2);		
		s2 >> h >> t;
		h2[i]=fsys(h, 4);
		t2[i]=fsys(t, 4);		
		s3 >> h >> t;	
		h3[i]=fsys(h, 8);
		t3[i]=fsys(t, 8);		
	}	
	out << "Zad 58.1:\n";
	int min = t1[0], min2 = t2[0], min3 = t3[0]; 
	for(int i = 1; i < SIZE; i++) {
		if(min > t1[i])
			min = t1[i];
		if(min2 > t2[i])
			min2 = t2[i];
		if(min2 > t3[i])
			min3 = t3[i];
	}
	bitset<8> minbin = min;
	out << "S1: " << minbin << '\n';	
	minbin = min2;
	out << "S2: " << minbin << '\n';	
	minbin = min3;
	out << "S3" << minbin << '\n';	

	out << "\nZad 58.2:\n";
	int er, ms = 12;
	for(int i = 0; i < SIZE; i++) {
		if(h1[i] != ms && h2[i] != ms && h3[i] != ms) 
			er++;
		ms += 24;
	}
	out << "Bledne: " << er << '\n';

	s1.close();
	s2.close();
	s3.close();
	out.close();
}

int fsys(string s, int sys) {
	int i = 0, 
	    out = 0,
	    posneg = 1; // 1 * x = +x | -1 * x = -x;
	if(s[0] == '-')
		posneg = -1;
		i=1;
	for(; i < s.size(); i++)
		out = out*sys+(s[i]-48); // ASCII 0 = 48 (dec)
	return out;
}
