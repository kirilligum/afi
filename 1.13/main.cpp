#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <random>

using namespace std;

template <typename T>
auto battery_capacity( const T& v) -> typename std::remove_reference<decltype(v)>::type::value_type {
  typename std::remove_reference<decltype(v)>::type::value_type b=0;
  auto hmin=v.front();
  for(auto i:v) {
    auto tb=i-hmin;
    if(tb>b) b=tb;
    if(i<hmin)  hmin=i;
  }
  return b;
}

int main() {
  vector<double> v(100);
  random_device rd;
  mt19937 gen(rd());
  uniform_real_distribution<double> dis(-100,100);
  generate( begin(v), end(v), [&]() {return dis(gen);});
  std::copy( std::begin(v), std::end(v),std::ostream_iterator<decltype(v)::value_type>(cout," ")); cout << endl;
  cout << "capacity = " <<  battery_capacity<vector<double>>(v) << endl;
  return 0;
}
