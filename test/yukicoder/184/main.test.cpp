#define PROBLEM "https://yukicoder.me/problems/no/184"

#include <iostream>
#include <bitset>
#include <vector>
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/LinearAlgebra/gaussian_elimination_binary.cpp"

namespace hl = haar_lib;

int main(){
  int n; std::cin >> n;
  auto a = hl::input_vector<int64_t>(n);

  int rank = hl::gaussian_elimination(std::vector<std::bitset<64>>(a.begin(), a.end()));

  std::cout << (1LL << rank) << "\n";

  return 0;
}
