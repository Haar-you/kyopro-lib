#define PROBLEM "https://yukicoder.me/problems/no/782"

#include <iostream>
#include "Mylib/Misc/convert_base.cpp"
#include "Mylib/IO/join.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int T, B; std::cin >> T >> B;
  while(T--){
    int N; std::cin >> N;
    auto ans = convert_base_to(N, B);

    std::cout << join(ans.begin(), ans.end(), "") << "\n";
  }
  
  return 0;
}
