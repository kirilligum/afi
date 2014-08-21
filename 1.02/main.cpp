#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

int binary_search( int x, const vector<int> &v) {
  int b=0, e=v.size()-1;
  while(b<=e) {
    int mid = (e+b)/2;
    if(x==v[mid]) return mid;
    else if(x<v[mid]) e=mid-1;
    else b=mid+1;
  }
  return -1;
}

int main() {
  vector<int> v={12,234,75,23,1,243,342,787,798};
  sort( begin(v), end(v));
  copy( begin(v), end(v), ostream_iterator<int>(cout," ")); cout << endl;
  cout << binary_search(23,v); cout << endl;
  cout << binary_search(22,v); cout << endl;
  return 0;
}
