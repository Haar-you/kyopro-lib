#define PROBLEM "https://yukicoder.me/problems/no/782"

#include <iostream>
#include "Mylib/Misc/convert_base.cpp"
#include "Mylib/IO/join.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int T, B; std::cin >> T >> B;
  for(auto [N] : hl::input_tuples<int>(T)){
    auto ans = hl::convert_base_to(N, B);

    std::cout << hl::join(ans.begin(), ans.end(), "") << "\n";
  }

  return 0;
}
