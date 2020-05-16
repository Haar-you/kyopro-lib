#define PROBLEM "https://yukicoder.me/problems/no/499"

#include <iostream>
#include <algorithm>
#include "Mylib/Misc/convert_base.cpp"

int main(){
  int N; std::cin >> N;

  auto res = convert_base_to(N, 7);

  for(auto x : res) std::cout << x;
  std::cout << "\n";
  
  return 0;
}
