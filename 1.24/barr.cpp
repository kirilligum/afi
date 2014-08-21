#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <random>
#include <stack>
#include <boost/range/adaptors.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/algorithm_ext.hpp>
#include <boost/fusion/adapted/boost_array.hpp>
#include <boost/fusion/include/boost_array.hpp>
#include <boost/array.hpp>
#include <boost/fusion/sequence/io.hpp>
#include <boost/fusion/include/io.hpp>
#include <boost/fusion/container/vector.hpp>
#include <boost/fusion/include/vector.hpp>
#include <boost/fusion/sequence/intrinsic/at_c.hpp>
#include <boost/fusion/include/at_c.hpp>
#include <tuple>

using namespace std;

int main() {
  boost::fusion::vector<float, int, std::string> a(1.0f, 2, std::string("Howdy folks!"));
  //tuple<float, int, std::string> a(1.0f, 2, std::string("Howdy folks!"));
  cout << boost::fusion::at_c<0>(a);
  cout << a;
  //boost::array<int,3> arr = {{1,2,3}};
  //cout << arr << endl;
  //std::cout << *begin(arr) << std::endl;
  //std::cout << *next(begin(arr)) << std::endl;
  //std::cout << *advance_c<2>(begin(arr)) << std::endl;
  //std::cout << *prior(end(arr)) << std::endl;
  //std::cout << at_c<2>(arr) << std::endl;

  return 0;
}

