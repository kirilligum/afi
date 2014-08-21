#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <random>
#include <unordered_map>
#include <sstream>
#include <tuple>

using namespace std;

string pair_to_string(const pair<int,int>& p) {
  std::ostringstream str;
  str << "("<< p.first << "," << p.second << ") ";
  return str.str();
}

unordered_map<int,int> frequent_items( const vector<int>& v, size_t k) {
  unordered_map<int,int> h;
  h.reserve(k);
  for(auto i:v){
    //cout << "st " ;
    auto it = h.find(i);
    if(it!=end(h)) {
      //cout << "1 ";
      h[i]++;
      //cout << "+" <<  pair_to_string(make_pair(i,h[i]));
    }
    //if(h.count(i)) { cout << "1 "; h[i]++; cout << "+" <<  pair_to_string(make_pair(i,h[i]));}
    //if(h.count(i)) h[i]++;
    else{
      //cout << "0 ";
      //if(h.size()==k) for(auto j:h) j.second--;
      if(h.size()==k)
        //for(auto j=begin(h); j!=end(h);j++){
        for(auto j=begin(h); j!=end(h);){
          //cout << "- ";
          --(j->second);
          if(j->second==0) {
            //cout << "e" << pair_to_string(*j) << " ";
            //auto dj=j;
            //h.erase(dj);
            //j++;
            h.erase(j++);
          }
          //else { ++j; cout << "++" << pair_to_string(*j) << " ";}
          else ++j;
        }
      else {
        h.insert(make_pair(i,1));
        //cout << "a" << pair_to_string(make_pair(i,h[i]));
      }
      //else h[i]=1;
    }
    //cout << "--";
    //transform( begin(h), end(h), ostream_iterator<string>(cout," "), pair_to_string);
    //cout << endl;
  }
  return h;
}

int main() {
  random_device rd;
  mt19937 g(rd());
  uniform_int_distribution<> d(0,4);
  vector<int> v(10);
  generate( begin(v), end(v),[&](){return d(g);});
  std::copy( std::begin(v), std::end(v),std::ostream_iterator<decltype(v)::value_type>(cout," ")); cout << endl;
  auto hm = frequent_items(v,5);
  cout << "find frequent items =";
  transform( begin(hm), end(hm), ostream_iterator<string>(cout," "), pair_to_string); cout << endl;
  for(auto& i:hm) i.second=0;
  transform( begin(hm), end(hm), ostream_iterator<string>(cout," "), pair_to_string); cout << endl;
  for(auto i:v) if(hm.count(i)) hm[i]++;
  transform( begin(hm), end(hm), ostream_iterator<string>(cout," "), pair_to_string);
  return 0;
}
