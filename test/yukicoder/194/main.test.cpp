#define PROBLEM "https://yukicoder.me/problems/no/194"


#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/LinearAlgebra/Square/square_matrix.cpp"
#include "Mylib/LinearAlgebra/Square/inverse_matrix.cpp"
#include "Mylib/LinearAlgebra/Square/power.cpp"

using mint = ModInt<1000000007>;
using M = SquareMatrix<mint>;

std::pair<mint,mint> solve1(int64_t N, int64_t K, std::vector<int> A){
  M m(N);

  for(int i = 0; i < N; ++i) m[0][i] = 1;
  for(int i = 0; i < N-1; ++i) m[i+1][i] = 1;

  std::reverse(A.begin(), A.end());

  mint f = 0;
  
  {
    auto m2 = power(m, K-N);
    for(int i = 0; i < N; ++i) f += m2[0][i] * A[i];
  }

  mint s = std::accumulate(A.begin(), A.end(), mint(0));
  
  {
    auto t = M::make_unit(N) - m;
    M c;
    inverse_matrix(t, c);

    auto temp = (M::make_unit(N) - power(m, K-N+1)) * c;
    temp -= M::make_unit(N);

    for(int i = 0; i < N; ++i) s += temp[0][i] * A[i];
  }

  return {f, s};
}

std::pair<mint,mint> solve2(int64_t N, int64_t K, std::vector<int> A){
  std::vector<mint> v(K);

  mint temp = 0;
  for(int i = 0; i < N; ++i){
    temp += A[i];
    v[i] = A[i];
  }

  for(int i = N; i < K; ++i){
    v[i] = temp;
    temp += v[i];
    temp -= v[i-N];
  }

  mint f = v.back();
  mint s = std::accumulate(v.begin(), v.end(), mint(0));
  
  return {f, s};
}




int main(){
  int64_t N, K; std::cin >> N >> K;

  std::vector<int> A(N);
  for(auto &x : A) std::cin >> x;

  auto [f, s] = K > 1000000 ? solve1(N, K, A) : solve2(N, K, A);
  std::cout << f << " " << s << "\n";

  return 0;
}
