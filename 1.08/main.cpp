#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <random>
#include <map>

using namespace std;

string sort_letters(string  word) {
  sort( begin(word), end(word));
  return word;
}

map<string,vector<string>> anagrams(const vector<string> &dict) {
  map<string,vector<string>> c;
  for(auto i:dict) {
    c[sort_letters(i)].push_back(i);
  }
  return c;
}

int main() {
  vector<string> dict = {"algorithm","god","logarithm","dog","snute"};
  std::copy( std::begin(dict), std::end(dict),std::ostream_iterator<string>(cout," ")); cout << endl;
  auto an = anagrams(dict);
  for(auto i:an) {
    std::copy( std::begin(i.second), std::end(i.second),std::ostream_iterator<decltype(i.second)::value_type>(cout," ")); cout << endl;
  }
  return 0;
}
