#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <random>

using namespace std;

vector<int> intersect(const vector<int> &a, const vector<int> &b) {
  vector<int> c;
  size_t ac=0,bc=0;
  int last=0;
  while(ac<a.size()&&bc<b.size()) {
    if(a[ac]==b[bc]&&a[ac]!=last) {
      last=a[ac];
      c.push_back(last);
      ac++;bc++;
    } else if(a[ac]<b[bc]) ac++;
    else bc++;
  }
  return c;
}

int main() {
  vector<int> a(20),b(30);
  std::mt19937 gen; std::uniform_int_distribution<> d(0,40);
  generate( begin(a), end(a), [&]() {return d(gen);});
  generate( begin(b), end(b), [&]() {return d(gen);});
  std::copy( std::begin(a), std::end(a),std::ostream_iterator<int>(cout," ")); cout << endl;
  std::copy( std::begin(b), std::end(b),std::ostream_iterator<int>(cout," ")); cout << endl;
  sort( begin(a), end(a));
  sort( begin(b), end(b));
  std::copy( std::begin(a), std::end(a),std::ostream_iterator<int>(cout," ")); cout << endl;
  std::copy( std::begin(b), std::end(b),std::ostream_iterator<int>(cout," ")); cout << endl;
  auto c = intersect(a,b);
  std::copy( std::begin(c), std::end(c),std::ostream_iterator<int>(cout," ")); cout << endl;
  return 0;
}
