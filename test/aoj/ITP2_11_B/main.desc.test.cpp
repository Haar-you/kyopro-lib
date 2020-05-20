#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_11_B"

#include <iostream>
#include <vector>
#include <map>
#include "Mylib/Bit/for_each_superset_desc.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int n, k; std::cin >> n >> k;

  int t = 0;
  for(int i = 0; i < k; ++i){
    int b; std::cin >> b;
    t |= 1 << b;
  }

  std::map<int, std::vector<int>> ans;
  for(int d : SupersetDesc(t, n)){
    ans[d];
    for(int i = 0; i < n; ++i){
      if(d & (1 << i)) ans[d].push_back(i);
    }
  }
  
  for(auto &[m, v] : ans){
    std::cout << m << ":";
    for(auto x : v) std::cout << " " << x;
    std::cout << "\n";
  }

  return 0;
}
