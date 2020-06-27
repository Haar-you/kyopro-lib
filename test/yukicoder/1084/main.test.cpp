#define PROBLEM "https://yukicoder.me/problems/no/1084"

#include <iostream>
#include <vector>
#include <algorithm>

#include "Mylib/IO/input_vector.cpp"
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Algorithm/Imos/linear_imos_1d.cpp"

using mint = ModInt<1000000007>;
const int MAX = 1000000000;

int main(){
  int N; std::cin >> N;
  auto A = input_vector<int64_t>(N);

  mint ans = 0;

  if(std::count(A.begin(), A.end(), 0) == 0){
    LinearImos1D<int64_t> p(N);
    
    std::vector<int> next(N);
    for(int i = N-1; i >= 0; --i){
      if(A[i] == 1){
        if(i == N-1) next[i] = N;
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