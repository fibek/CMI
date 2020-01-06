#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  ofstream out("wyniki_4.txt");
  ifstream p("punkty.txt");
  vector<pair<double, double> > inp;
  double x,y;

  while(p >> x >> y) {
    inp.push_back(make_pair(x,y));
  }

  int r, a,b, inside;
  r = 200;
  a = b = 200;
  inside = 0;
  int row;
  out << "4.1\n\n";;

  for(int i = 0; i < inp.size(); i++) {
    row = ((inp[i].first-a)*(inp[i].first-a))+((inp[i].second-b)*(inp[i].second-b));
    if(row == r*r)
    //jezeli wynik rownania = r*r to nalezy do brzegu okregu
      out << inp[i].first << ' ' << inp[i].second << '\n';
    else if(row < r*r)
    //jezeli wynik rownania != r*r a jest mniejszy to nalezy to wnetrza
      inside++;
  }
  out << inside << '\n';
  out << '\n' << "4.2\n\n";;

  out.precision(4); // wyswietlaj 4 cyfry po przecinku
  out.setf(ios_base::fixed);
  inside = 0;
  double pi;
  for(int i = 0; i < 1000; i++) {
    row = ((inp[i].first-a)*(inp[i].first-a))+((inp[i].second-b)*(inp[i].second-b));
    if(row < r*r)
      inside++;
  }
  pi = (double(inside) * 4) / 1000;
  out << round(pi*10000)/10000 << '\n'; // zaokragla wynik

  inside = 0;
  for(int i = 0; i < 5000; i++) {
    row = ((inp[i].first-a)*(inp[i].first-a))+((inp[i].second-b)*(inp[i].second-b));
    if(row < r*r)
      inside++;
  }
  pi = (double(inside) * 4) / 5000;
  out << round(pi*10000)/10000 << '\n';

  inside = 0;
  for(int i = 0; i < inp.size(); i++) {
    row = ((inp[i].first-a)*(inp[i].first-a))+((inp[i].second-b)*(inp[i].second-b));
    if(row < r*r)
      inside++;
  }
  pi = (double(inside) * 4) / inp.size();
  out << round(pi*10000)/10000 << '\n';

  out << '\n' << "4.3\n\n";

  double e;
  inside = 0;
  for(int n = 1; n <= 1700; n++){
    inside=0;
    for(int i = 0; i <= n; i++) {
      row = ((inp[i].first-a)*(inp[i].first-a))+((inp[i].second-b)*(inp[i].second-b));
      if(row <= r*r)
        inside++;
    }
    e = M_PI - round(((double(inside) * 4) / n)*10000)/10000;
    out << abs(e) << '\n'; //abs() - wartosc bezwzglednia
  }
}
