#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations"

#include <vector>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/LinearAlgebra/SimultaneousLinearEquations/simultaneous_linear_equations.cpp"
#include "Mylib/IO/join.cpp"
#include "Mylib/IO/input_vector.cpp"

namespace hl = haar_lib;

using mint = hl::modint<998244353>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, M; std::cin >> N >> M;

  auto A = hl::input_vector<mint>(N, M);
  auto B = hl::input_vector<mint>(N);

  auto res = hl::simulaneous_linear_equations(A, B);

  if(not res){
    std::cout << -1 << "\n";
  }else{
    std::cout << (*res).dim << "\n";

    std::cout << hl::join((*res).solution.begin(), (*res).solution.end()) << "\n";

    for(auto &b : (*res).basis){
      std::cout << hl::join(b.begin(), b.end()) << "\n";
    }
  }

  return 0;
}
