#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <random>
#include <stack>
#include <boost/range/algorithm.hpp>
#include <boost/range/algorithm_ext.hpp>
#include <boost/range/adaptors.hpp>
#include <ro/ro.h>

using namespace std;
using namespace boost;
using namespace boost::adaptors;
using namespace ro;

template <typename rg>
auto operator~(rg&& r) -> decltype(back_inserter(r)) {return back_inserter(r);}

vector<int> contains(int bi, int ei, const vector<int>& bv, const vector<int>& ev) {
  auto bnv=bv, env=ev;
  bnv.push_back(bi); sort(bnv);
  env.push_back(ei); sort(env);
  auto bit = find(bnv,bi);
  auto eit = find(env,ei);
  if(distance(+bnv,bit)<distance(+env,eit)) {
    auto br = bit+1;
    auto er = eit-1;
    return vector<int>{*br,*er};
    cout << "contains around\n";
  }
  else if(distance(+bnv,bit)>distance(+env,eit)) {
    auto br = bit-1;
    auto er = eit+1;
    return vector<int>{*br,*er};
    cout << "contains inside\n";
  }
  else {
    cout << "contains partially inside\n";
    if(bit!=-bnv && *(bit+1)<*eit) {
      auto br = bit+1;
      auto er = eit+1;
      return vector<int>{*br,*er};
    } else if(eit!=+env && *bit<*(eit-1)) {
      auto br = bit-1;
      auto er = eit-1;
      return vector<int>{*br,*er};
    }
  }
  cout << "doesn't contain\n";
  return vector<int>{bi,ei};
}

int main() {
  mt19937 g; uniform_int_distribution<> d(0,200);
  vector<int> v(200),w(200),b,e;
  iota(v,0); random_shuffle(v); v.resize(30); sort(v); __ v;
  iota(w,0); random_shuffle(w); w.resize(30); sort(w); __ w;
  copy(v|strided(2),~b); __ b;
  copy(v|sliced(1,v.size())|strided(2),~e); __ e;
  __ contains(5,6,b,e);
  __ contains(12,13,b,e);
  return 0;
}
