#define PROBLEM "https://yukicoder.me/problems/no/658"

#include <iostream>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/DynamicProgramming/SpeedupTechnique/kitamasa_algorithm.cpp"
#include "Mylib/IO/input_tuples.cpp"

using mint = ModInt<17>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int Q; std::cin >> Q;

  for(auto [N] : input_tuples<int64_t>(Q)){
    KitamasaAlgorithm<mint> ka(4, {0, 0, 0, 1}, {1, 1, 1, 1});
    std::cout << ka[N-1] << std::endl;
  }

  return 0;
}
