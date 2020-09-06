#define PROBLEM "https://yukicoder.me/problems/no/184"

#include <iostream>
#include <bitset>
#include <vector>
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/LinearAlgebra/GaussianElimination/binary_gaussian_elimination.cpp"

int main(){
  int n; std::cin >> n;
  auto a = input_vector<int64_t>(n);

  int rank = gaussian_elimination(std::vector<std::bitset<64>>(a.begin(), a.end()));

  std::cout << (1LL << rank) << "\n";

  return 0;
}
