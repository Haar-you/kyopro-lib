#define PROBLEM "https://yukicoder.me/problems/no/782"

#include <iostream>
#include "Mylib/Misc/convert_base.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int T, B; std::cin >> T >> B;
  while(T--){
    int N; std::cin >> N;
    auto ans = convert_base_to(N, B);
    for(auto x : ans) std::cout << x;
    std::cout << "\n";
  }
  
  return 0;
}
