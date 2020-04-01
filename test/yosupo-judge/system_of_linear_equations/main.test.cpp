#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations"

#include <vector>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/LinearAlgebra/SimultaneousLinearEquations/simultaneous_linear_equations.cpp"


using mint = ModInt<998244353>;

int main(){
  int N, M; scanf("%d%d", &N, &M);

  std::vector<std::vector<mint>> A(N, std::vector<mint>(M));

  for(int i = 0; i < N; ++i){
    for(int j = 0; j < M; ++j){
      int x; scanf("%d", &x);
      A[i][j] = x;
    }
  }

  std::vector<mint> B(N);
  for(int i = 0; i < N; ++i){
    int x;
    scanf("%d", &x);
    B[i] = x;
  }

  auto res = simulaneous_linear_equations::solve(A, B);
  
  if(not res){
    printf("-1\n");
  }else{
    printf("%d\n", (*res).dim);

    for(int i = 0; i < M; ++i){
      printf("%lld ", (*res).solution[i].val);
    }
    puts("");
    
    for(auto &b : (*res).basis){
      for(auto &x : b){
        printf("%lld ", x.val);
      }
      puts("");
    }
  }
  
  return 0;
}
