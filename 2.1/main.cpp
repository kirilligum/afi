#include "headers.hpp"
#include <ro/ro.h>

using namespace std;
namespace b=boost;

void insertion_sort(vector<int> &v) {
  for (size_t i = 0; i < v.size(); ++i) {
    auto tmp = std::move(v[i]);
    int j;
    for(j=i;j>0&&tmp<v[j-1];--j){
      v[j]=std::move(v[j-1]);
    }
    v[j]=tmp;
  }
}

void simple_quicksort(vector<int>& v){
  if(v.size()>1) {
    vector<int> smaller, larger, same;
    auto pivot = v[v.size()/2];
    for(size_t i = 0; i<v.size(); ++i) {
      if(v[i]<pivot) {
        smaller.push_back(move(v[i]));
      } else if (v[i]>pivot) {
        larger.push_back(move(v[i]));
      } else {
        same.push_back(move(v[i]));
      }
    }
    simple_quicksort(smaller);
    simple_quicksort(larger);

    move( std::begin(smaller), std::end(smaller), begin(v));
    move( std::begin(same), std::end(same), begin(v)+smaller.size());
    move( std::begin(larger), std::end(larger), std::end(v)-larger.size());
  }
}

int median3(vector<int>& v, size_t left, size_t right) {
  auto center = left + (right - left)/2;
  if(v[left]>v[center])
    swap(v[left],v[center]);
  if(v[left]>v[right])
    swap(v[left],v[right]);
  if(v[center]>v[right])
    swap(v[center],v[right]);
  swap(v[center],v[right-1]);
  return v[right-1];
}

void quicksort(vector<int>& v, size_t left, size_t right) {
  if(left+10<=right){
    auto pivot = median3(v,left,right);
    size_t i=left, j=right-1;
    for(;;){
      while(v[++i]<pivot) {}
      while(v[--j]>pivot) {}
      if(i<j)
        swap(v[i],v[j]);
      else
        break;
    }
    swap(v[i],v[right-1]);
    quicksort(v,left,i-1);
    quicksort(v,i+1,right);
  } else {
    for(auto i = left; i<=right; ++i) {
      auto tmp = move(v[i]);
      auto j=i;
      for(; j>0 && tmp<v[j-1]; --j) {
        v[j]=move(v[j-1]);
      }
      v[j]=tmp;
    }
  }
}

void quicksort(vector<int>& v) {
  quicksort(v, 0, v.size()-1);
}

int main() {
  vector<int> v(25);
  b::iota(v,0);
  b::random_shuffle(v);
  __ v;
  insertion_sort(v);
  __ v;
  b::random_shuffle(v);
  __ v;
  simple_quicksort(v);
  __ v;
  b::random_shuffle(v);
  __ v;
  quicksort(v);
  __ v;
  return 0;
}
