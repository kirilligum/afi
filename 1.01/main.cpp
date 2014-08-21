#include <iostream>
#include <cmath>

using namespace std;

int sqrt_search(unsigned int input) {
  int begin=0;
  int end =65536;
  while(begin+1<end){
    int mid = (end+begin)/2;
    unsigned int mid2=mid*mid;
    if(input == mid2) return mid;
    else if (input < mid2) end=mid;
    else begin=mid;
  }
  return begin;
}

int main() {
 int n = 3245;
 cout << n << endl;
  cout <<  sqrt_search(n) << endl;
  cout <<  pow(sqrt_search(n),2) << endl;
  cout <<  pow(sqrt_search(n)+1,2) << endl;
  return 0;
}

