#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <random>

using namespace std;

int unbound_bin_search(int x, const vector<int> &v) {
  int k=0;
  while(true) {
    int c =0;
    try{
      c=v[(1<<k)-1];
      if(c==x) return (1<<k)-1;
      else if(c>x) break;
    } catch (std::out_of_range& oor){
      cerr << "out of range: " << oor.what() << endl;
      break;
    }
    k++;
  }
  int b=1<<(k-1),e=(1<<k)-1;
  while(b<=e) {
    int m = (b+e)/2;
    try{
      if(x==v[m]) return m;
      else if (x<v[m]) e=m-1;
      else b=m+1;
    } catch (std::out_of_range &oor) {
      e=m;
    }
  }
  return -1;
}

int main() {
  vector<int> v(1000);
  iota( begin(v), end(v),-100);
  std::random_shuffle( begin(v), end(v));
  for (int i = 0; i < 100; ++i) { v.pop_back(); }
  sort( begin(v), end(v));
  int suka= 223;
  while(1) {
    int blyat = unbound_bin_search(suka,v);
    cout << blyat << endl;
    if(blyat!=-1) { cout << v[blyat] << endl; break;}
    ++suka;
  }
  return 0;
}
