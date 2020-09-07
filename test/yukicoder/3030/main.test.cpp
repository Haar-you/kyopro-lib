#define PROBLEM "https://yukicoder.me/problems/no/3030"

#include <iostream>
#include "Mylib/Number/Prime/miller_rabin.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N; std::cin >> N;

  for(auto [x] : input_tuples<int64_t>(N)){
    std::cout << x << " " << miller_rabin(x) << "\n";
  }

  return 0;
}
