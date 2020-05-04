#define PROBLEM "https://yukicoder.me/problems/no/658"

#include <iostream>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/DynamicProgramming/SpeedupTechnique/kitamasa_algorithm.cpp"

using mint = ModInt<17>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int Q; std::cin >> Q;

  while(Q--){
    int64_t N; std::cin >> N;

    KitamasaAlgorithm<mint> ka(4, {0, 0, 0, 1}, {1, 1, 1, 1});
    std::cout << ka[N-1] << std::endl;
  }

  return 0;
}
