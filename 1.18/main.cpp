#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <random>
#include <stack>
#include <cassert>

using namespace std;

int smallest(const vector<int>&a, const vector<int>&b, int k){
  assert(a.size()+b.size()>=k);
  assert(k>0);
  auto begin = max(0,k-static_cast<int>(b.size())), end = min(static_cast<int>(k),static_cast<int>(a.size()));
  while(begin<end){
    auto l = (begin+end)/2;
    if(l<static_cast<int>(a.size())&&(k-l)>0&&a[l]<b[k-l-1])
      begin=l+1;
    else if(l>0&&(k-l)<static_cast<int>(b.size())&&a[l-1]>b[k-l])
      end=l;
    //else begin=end=l;
    else {begin=l;break;}
  }
  if(begin==0) return b[k-1];
  else if (begin==k) return a[k-1];
  else return max(a[begin-1],b[k-begin-1]);
}

int main() {
  vector<int> a(100),b(100);
  iota( begin(a), end(a),0);
  iota( begin(b), end(b),0);
  random_shuffle( begin(a), end(a));
  random_shuffle( begin(b), end(b));
  a.resize(30);
  b.resize(30);
  sort( begin(a), end(a));
  sort( begin(b), end(b));
  std::copy( std::begin(a), std::end(a),std::ostream_iterator<decltype(a)::value_type>(cout," ")); cout << endl;
  std::copy( std::begin(b), std::end(b),std::ostream_iterator<decltype(b)::value_type>(cout," ")); cout << endl;
  cout << " smallest = " << smallest(a,b,10) << endl;
  return 0;
}
