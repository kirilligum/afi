#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <random>

using namespace std;

int searchaii(const vector<int> &v) {
  int b=0,e=v.size();
  while(b<=e) {
    int mid = (b+e)/2;
    if(v[mid]==mid) return mid;
    else if(v[mid]>mid) e=mid-1;
    else b=mid+1;
  }
  return -1;
}

int main(){
  vector<int> v(40);
  iota( begin(v), end(v),-10);
  std::random_shuffle( begin(v), end(v));
  for(int i=0; i<10; i++) v.pop_back();
  //random_device rd;
  //mt19937 gen(rd());
  //uniform_int_distribution<> dis(-10,25);
  //generate( begin(v), end(v), [&](){ return dis(gen);});
  copy( begin(v), end(v),ostream_iterator<int>(cout," ")); cout << endl;
  sort( begin(v), end(v));
  copy( begin(v), end(v),ostream_iterator<int>(cout," ")); cout << endl;
  cout << searchaii(v) << endl;
  return 0;
}
