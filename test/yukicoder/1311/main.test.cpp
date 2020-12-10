#define PROBLEM "https://yukicoder.me/problems/no/1311"

#include <iostream>
#include "Mylib/Math/permutation.cpp"

namespace hl = haar_lib;

int main(){
  int64_t N, S; std::cin >> N >> S;
  int64_t ans =  hl::permutation_to_index(hl::inverse_permutation(hl::index_to_permutation(N, S)));

  std::cout << ans << "\n";

  return 0;
}
