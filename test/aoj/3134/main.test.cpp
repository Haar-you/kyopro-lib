#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3134"

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include "Mylib/Convolution/fast_zeta_transform_subset.cpp"
#include "Mylib/IO/input_vector.cpp"

int main(){
  int N,K; std::cin >> N >> K;

  auto A = input_vector<int>(N);

  std::vector<int> sum(1 << N);

  for(int i = 0; i < 1<<N; ++i){
    for(int j = 0; j < N; ++j){
      if(not (i & (1 << j))){
        sum[i | (1 << j)] = sum[i] + A[j];
      }
    }
  }

  std::vector<int> f(1 << N);
  for(int i = 0; i < 1<<N; ++i){
    if(sum[i] == K) f[i] = true;
  }
  
  f = fast_zeta_transform_subset(f, std::logical_or<bool>());

  int ans = N;

  for(int i = 0; i < 1<<N; ++i){
    if(not f[i]){
      ans = std::min(ans, N - __builtin_popcount(i));
    }
  }

  std::cout << ans << std::endl;

  return 0;
}
