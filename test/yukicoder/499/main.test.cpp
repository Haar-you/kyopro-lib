#define PROBLEM "https://yukicoder.me/problems/no/499"

#include <iostream>
#include <algorithm>
#include "Mylib/Misc/convert_base.cpp"
#include "Mylib/IO/join.cpp"

int main(){
  int N; std::cin >> N;

  auto res = convert_base_to(N, 7);

  std::cout << join(res.begin(), res.end(), "") << "\n";

  return 0;
}
