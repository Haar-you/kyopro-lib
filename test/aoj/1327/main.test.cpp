#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1327"

#include <iostream>
#include <vector>
#include "Mylib/Number/Mint/runtime_mint.cpp"
#include "Mylib/LinearAlgebra/square_matrix.cpp"
#include "Mylib/IO/join.cpp"
#include "Mylib/IO/input_vector.cpp"

namespace hl = haar_lib;

static int n, m;
using mint = hl::runtime_modint<m>;
using M = hl::square_matrix_dyn<mint, n>;

int main(){
  int a, b, c, t;

  while(std::cin >> n >> m >> a >> b >> c >> t, n){
    auto s = hl::input_vector<mint>(n);

    M mat;

    for(int i = 0; i < n; ++i){
      if(i - 1 >= 0) mat[i][i - 1] = a;
      mat[i][i] = b;
      if(i + 1 < n) mat[i][i + 1] = c;
    }

    mat = mat.pow(t);

    auto ans = mat * M::vector_type(s);

    std::cout << hl::join(ans.begin(), ans.end()) << "\n";
  }

  return 0;
}
