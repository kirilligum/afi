#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <queue>
#include <random>

using namespace std;

struct node{
  int d;
  node* l;
  node* r;
};

void insert(int x, node*&n) {
  if(!n) n=new node{x,nullptr,nullptr};
  else if(n->d<x) insert(x,n->r);
  else insert(x,n->l);
}

node*  find_next(int x, node* n){
  decltype(n)  last = nullptr;
  while(n!=nullptr) {
    if (n->d>x) {
      last = n;
      n=n->l;
    }else{
      n=n->r;
    }
  }
  return last;
}
//int  find_next(int x, node* n){
  //queue<node*> q;
  //auto in = n;
  //while(in) {
    //if(in->d==x) break;
    //if(in->d<x) {
      //q.push(in);
      //in=in->r;
    //} else {
      //decltype(q) empty;
      //swap(q,empty);
      //q.push(in);
      //in=in->l;
    //}
  //}
  //in=q.front()->r;
  //while (in->l) in=in->l;
  //return in->d;
//}

int main() {
  vector<int> v(40);
  iota( begin(v), end(v), -20);
  std::copy( std::begin(v), std::end(v),std::ostream_iterator<decltype(v)::value_type>(cout," ")); cout << endl;
  std::random_shuffle( begin(v), end(v));
  v.resize(20);
  std::copy( std::begin(v), std::end(v),std::ostream_iterator<decltype(v)::value_type>(cout," ")); cout << endl;
  auto root = new node{v.back(),nullptr,nullptr};
  v.pop_back();
  for(auto i:v) insert(i,root);
  sort( begin(v), end(v));
  std::copy( std::begin(v), std::end(v),std::ostream_iterator<decltype(v)::value_type>(cout," ")); cout << endl;
  cout <<" next (" << 3 << ") = " << find_next(3,root)->d << endl;
  cout <<" next (" << 6 << ") = " << find_next(6,root)->d << endl;
  cout <<" next (" << 7 << ") = " << find_next(7,root)->d << endl;
  return 0;
}
