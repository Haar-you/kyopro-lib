#define PROBLEM "https://yukicoder.me/problems/no/3030"

#include <iostream>
#include "Mylib/Number/Prime/miller_rabin.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N; std::cin >> N;

  for(auto [x] : hl::input_tuples<int64_t>(N)){
    std::cout << x << " " << hl::miller_rabin(x) << "\n";
  }

  return 0;
}
