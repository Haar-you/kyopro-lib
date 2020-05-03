#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/LinearAlgebra/Square/square_matrix.cpp"
#include "Mylib/LinearAlgebra/Square/determinant.cpp"

using mint = ModInt<998244353>;

struct tag{};
using Mat = SquareMatrix<mint, tag>;

int main(){
  int N; scanf("%d", &N);

  Mat::N = N;

  Mat m;

  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      int x; scanf("%d", &x);
      m[i][j] = x;
    }
  }

  auto ans = determinant(m);

  printf("%lld\n", ans.val);

  return 0;
}
