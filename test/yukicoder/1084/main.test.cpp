#define PROBLEM "https://yukicoder.me/problems/no/1084"

#include <iostream>
#include <vector>
#include <algorithm>
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Algorithm/Imos/linear_imos_1d.cpp"

namespace hl = haar_lib;

using mint = hl::modint<1000000007>;
const int MAX = 1000000000;

int main(){
  int N; std::cin >> N;
  auto A = hl::input_vector<int64_t>(N);

  mint ans = 0;

  if(std::count(A.begin(), A.end(), 0) == 0){
    hl::linear_imos_1d<int64_t> p(N);

    std::vector<int> next(N);
    for(int i = N; --i >= 0;){
      if(A[i] == 1){
        if(i == N - 1) next[i] = N;
        else{
          if(A[i + 1] == 1){
            next[i] = next[i + 1];
          }else{
            next[i] = i + 1;
          }
        }
      }else{
        next[i] = i + 1;
      }
    }

    for(int l = 0; l < N; ++l){
      int64_t prod = 1;

      int r = l;

      for(int i = 0; i < 100; ++i){
        if(r == N or prod * A[r] >= MAX) break;
        prod *= A[r];
        r = next[r];
      }

      p.add(l, r, -1, r);
    }

    p.build();

    ans = 1;
    for(int i = 0; i < N; ++i){
      ans *= mint::power(A[i], p[i]);
    }
  }

  std::cout << ans << "\n";

  return 0;
}
