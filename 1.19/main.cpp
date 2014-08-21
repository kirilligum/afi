#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <random>
#include <stack>

using namespace std;

double le(const vector<double>& lc, double x) { return lc[0]*x+lc[1]; }

bool intersect( const vector<double> &l1, const vector<double> &l2, double lower, double higher){
  if(lower>higher) swap(lower,higher);
  auto y1l=le(l1,lower);
  auto y2l=le(l2,lower);
  auto y1h=le(l1,higher);
  auto y2h=le(l2,higher);
  if((y1l<y2l&&y1h<y2h)||(y1l>y2l&&y1h>y2h)) return 0;
  else return 1;
}

int main() {
  vector<double> l1(2),l2(2),l3(2);
  mt19937 g; uniform_real_distribution<double> d(-10,10);
  generate( begin(l1), end(l1),[&](){return d(g);});
  generate( begin(l2), end(l2),[&](){return d(g);});
  l3=l2;
  for(auto&i:l3) i+=1;
  std::copy( std::begin(l1), std::end(l1),std::ostream_iterator<decltype(l1)::value_type>(cout," ")); cout << endl;
  std::copy( std::begin(l2), std::end(l2),std::ostream_iterator<decltype(l2)::value_type>(cout," ")); cout << endl;
  std::copy( std::begin(l3), std::end(l3),std::ostream_iterator<decltype(l3)::value_type>(cout," ")); cout << endl;
  cout << "intersect = " << intersect(l1,l2,0,10) << endl;
  cout << "intersect = " << intersect(l2,l3,0,10) << endl;
  return 0;
}
