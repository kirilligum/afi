#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <random>

using namespace std;

struct node {
  int d;
  node* l;
  node* r;
};

void insert(int x, node* &n){
  if(!n) n = new node{x,nullptr,nullptr};
  else if(x==n->d) return;
  else if (x<n->d) insert(x,n->l);
  else insert(x,n->r);
}

node* find_recursive(int x, node* n){
  if(!n) return nullptr;
  else if (x==n->d) return n;
  else if (x<n->d) return find_recursive(x,n->l);
  else return find_recursive(x,n->r);
}

node* find_iterative(int x, node* n){
  auto it=n;
  while(x!=it->d||it!=nullptr) {
    if(it->d==x) return it;
    else if(it->d>x) it=it->l;
    else  it=it->r;
  }
  return nullptr;
}

int main() {
  auto root= new node{5,nullptr,nullptr};
  insert(4,root);
  insert(1,root);
  insert(9,root);
  insert(3,root);
  insert(7,root);

  auto n=find_recursive(3,root);
  if(n) cout << n->d<<endl;
  else cout << "nope" << endl;
  auto ni=find_iterative(3,root);
  if(ni) cout << ni->d<<endl;
  else cout << "nope" << endl;
  return 0;
}
