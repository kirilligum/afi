#include "../headers.hpp"

using namespace std;

vector<size_t>  find(const vector<vector<int>> &m, int c){
  size_t row=0;
  size_t col=m.front().size()-1;
  while(col!=0 && row!=m.size()-1) {
    if(c==m[col][row]) {
      return vector<size_t>{col,row};
    }
    else if(c<m[col][row]) --col;
    else ++row;
  }
  return vector<size_t>{m.size(),m.front().size()};
}

int main() {
  vector<vector<int>> m = { {10, 20, 30, 40}, {15, 25, 35, 45}, {27, 29, 37, 48}, {32, 33, 39, 50} };
  __ m;
  __ find(m,37);
  __ find(m,38);
  __ find(m,33);
  return 0;
}
