#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations"

#include <vector>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/LinearAlgebra/SimultaneousLinearEquations/simultaneous_linear_equations.cpp"
#include "Mylib/IO/join.cpp"

using mint = ModInt<998244353>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, M; std::cin >> N >> M;

  std::vector<std::vector<mint>> A(N, std::vector<mint>(M));

  for(int i = 0; i < N; ++i){
    for(int j = 0; j < M; ++j){
      int x; std::cin >> x;
      A[i][j] = x;
    }
  }

  std::vector<mint> B(N);
  for(int i = 0; i < N; ++i){
    int x;
    std::cin >> x;
    B[i] = x;
  }

  auto res = simulaneous_linear_equations::solve(A, B);
  
  if(not res){
    std::cout << -1 << "\n";
  }else{
    std::cout << (*res).dim << "\n";

    std::cout << join((*res).solution.begin(), (*res).solution.end()) << "\n";

    for(auto &b : (*res).basis){
      std::cout << join(b.begin(), b.end()) << "\n";
    }
  }
  
  return 0;
}
