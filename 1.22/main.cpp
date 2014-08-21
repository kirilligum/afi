#include "headers.hpp"

using namespace std;
using namespace boost;
using namespace boost::adaptors;
using namespace ro;

int total_pay(const vector<int> &v, int sig) {
  int sum =0;
  for(auto i:v) {
    sum += min(i,sig);
  }
  return sum;
}

int cutoff(const vector<int> &v, int ss) {
  typename std::remove_const<std::remove_reference<decltype(v)>::type>::type ksum;
  partial_sum(v,back_inserter(ksum));
  int b = 0;
  int e = v.size();
  int m=0;
  while(b<=e){
    m = b+(e-b)/2;
    int f = (v.size()-m)*v[m]+ksum[m];
    if(ss<f) e=m-1;
    else if(ss>f) b = m+1;
    else break;
  }
  return (ss-ksum[m])/(v.size()-m-1);
}

int main() {
  vector<int> v = {90,30,100,40,20};
  int ss= 210;
  cout << ss<< endl;
  __ v;
  sort(v);
  cout << cutoff(v,ss) << endl;
  return 0;
}
