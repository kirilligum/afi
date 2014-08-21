#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <random>

using namespace std;

template <typename t>
typename t::value_type find_majority(t const &v) {
  typename std::remove_reference<decltype(v)>::type::value_type candidate;
  int count=0;
  for(auto i:v){
    if(count==0) {
      candidate=i;
      count =1;
    } else if (candidate==i) count++;
    else count--;
  }
  return candidate;
}

int main() {
  random_device rd;
  mt19937 g(rd());
  uniform_int_distribution<> d(0,9);
  vector<int> v(100);
  generate( begin(v), end(v),[&](){return d(g);});
  std::copy( std::begin(v), std::end(v),std::ostream_iterator<decltype(v)::value_type>(cout," ")); cout << endl;
  cout << "find majority = " << find_majority(v) << endl;
  return 0;
}
