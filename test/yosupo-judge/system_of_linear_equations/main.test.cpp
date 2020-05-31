#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations"

#include <vector>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/LinearAlgebra/SimultaneousLinearEquations/simultaneous_linear_equations.cpp"
#include "Mylib/IO/join.cpp"
#include "Mylib/IO/input_vector.cpp"

using mint = ModInt<998244353>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, M; std::cin >> N >> M;

  auto A = input_vector<mint>(N, M);
  auto B = input_vector<mint>(N);

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
