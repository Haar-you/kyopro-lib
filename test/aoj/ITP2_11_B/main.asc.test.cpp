#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_11_B"

#include <iostream>
#include <vector>
#include <map>
#include "Mylib/Bit/enumerate_supersets_asc.cpp"
#include "Mylib/IO/input_vector.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n, k; std::cin >> n >> k;

  int t = 0;
  for(auto b : hl::input_vector<int>(k)){
    t |= 1 << b;
  }

  std::map<int, std::vector<int>> ans;
  hl::enumerate_supersets_asc(
    t, n,
    [&](int d){
      ans[d];
      for(int i = 0; i < n; ++i){
        if(d & (1 << i)) ans[d].push_back(i);
      }
      return true;
    }
  );

  for(auto &[m, v] : ans){
    std::cout << m << ":";
    for(auto x : v) std::cout << " " << x;
    std::cout << "\n";
  }

  return 0;
}
