#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include <iostream>
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/IO/join.cpp"
#include "Mylib/Number/Prime/pollard_rho.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int Q; std::cin >> Q;

  for(auto [a] : input_tuples<int64_t>(Q)){
    auto res = PollardRho::prime_factorize(a);
    
    std::vector<int64_t> ans;
    for(auto [x, k] : res){
      while(k--) ans.push_back(x);
    }

    std::cout << ans.size() << " " << join(ans.begin(), ans.end()) << "\n";
  }

  return 0;
}
