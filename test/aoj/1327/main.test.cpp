#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1327"
     
#include <iostream>
#include <vector>
#include "Mylib/Number/Mint/runtime_mint.cpp"
#include "Mylib/LinearAlgebra/Square/square_matrix.cpp"
#include "Mylib/LinearAlgebra/Square/power.cpp"
     
using mint = RuntimeModInt;
using M = SquareMatrix<mint>;
     
int main(){
  int n, m, a, b, c, t;
  while(std::cin >> n >> m >> a >> b >> c >> t, n){
    mint::M = m;
     
    std::vector<mint> s(n);
    for(int i = 0; i < n; ++i) std::cin >> s[i];
     
    M mat(n);
     
    for(int i = 0; i < n; ++i){
      if(i-1 >= 0) mat[i][i-1] = a;
      mat[i][i] = b;
      if(i+1 < n) mat[i][i+1] = c;
    }
     
    mat = power(mat, t);
     
    std::vector<mint> ans(n);
     
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
        ans[i] += mat[i][j] * s[j];
      }
    }
     
    for(int i = 0; i < n; ++i){
      if(i) std::cout << " ";
      std::cout << ans[i];
    }
    std::cout << std::endl;
  }
     
  return 0;
}
