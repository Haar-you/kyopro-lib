#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1327"

#include <iostream>
#include <vector>
#include "Mylib/Number/Mint/runtime_mint.cpp"
#include "Mylib/LinearAlgebra/Square/square_matrix.cpp"
#include "Mylib/LinearAlgebra/Square/power.cpp"
#include "Mylib/IO/join.cpp"
#include "Mylib/IO/input_vector.cpp"

struct tag {};
using mint = RuntimeModInt<tag>;
using M = SquareMatrix<mint, tag>;

int main(){
  int n, m, a, b, c, t;
  while(std::cin >> n >> m >> a >> b >> c >> t, n){
    mint::init(m);
    M::init(n);

    auto s = input_vector<mint>(n);

    M mat;

    for(int i = 0; i < n; ++i){
      if(i - 1 >= 0) mat[i][i - 1] = a;
      mat[i][i] = b;
      if(i + 1 < n) mat[i][i + 1] = c;
    }

    mat = power(mat, t);

    std::vector<mint> ans(n);

    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
        ans[i] += mat[i][j] * s[j];
      }
    }

    std::cout << join(ans.begin(), ans.end()) << "\n";
  }

  return 0;
}
