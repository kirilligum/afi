#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <random>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<pair<int,int>> addsto(int sum, const vector<int> &v){
  vector<pair<int,int>> pairs;
  unordered_set<int> m;
  for(int i=0; i<static_cast<int>(v.size()); ++i){
    m.insert(v[i]);
    if(m.count(sum-v[i])) pairs.push_back(make_pair(v[i],sum-v[i]));
  }
  return pairs;
}

int main() {
  vector<int> v(50);
  mt19937 gen;
  uniform_int_distribution<> d(-20,80);
  generate( begin(v), end(v), [&]() {return d(gen);});
  std::copy( std::begin(v), std::end(v),std::ostream_iterator<decltype(v)::value_type>(cout," ")); cout << endl;
  int num=110;
  while(num<115) {
    cout << num << " -- ";
    auto pairs = addsto(num,v);
    for(auto i: pairs) { cout << i.first << "  " << i.second << endl;}
    num++;
  }
  return 0;
}
