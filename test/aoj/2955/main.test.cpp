#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2955"

#include <iostream>
#include <vector>
#include <map>
#include "Mylib/TypicalProblem/SubsetSumProblem/subset_sum_limited.cpp"
#include "Mylib/DataStructure/UnionFind/unionfind.cpp"

int main(){
  int N,R; std::cin >> N >> R;
  
  std::vector<int> p(N);
  for(int i = 0; i < N; ++i){
    std::cin >> p[i];
    p[i] -= 1;
  }
  
  UnionFind uf(N);
  
  for(int i = 0; i < N; ++i){
    uf.merge(i, p[i]);
  }
  
  std::map<int, int> cycles;
  for(int i = 0; i < N; ++i){
    if(i == uf.get_root(i)) cycles[uf.get_size(i)] += 1;
  }
  
  std::vector<int> a,m;
  for(auto &kv : cycles){
    a.push_back(kv.first);
    m.push_back(kv.second);
  }
  
  bool ans = subset_sum_limited(a.size(), R, a, m);
  
  std::cout << (ans ? "Yes" : "No") << std::endl;
  
  return 0;
}
