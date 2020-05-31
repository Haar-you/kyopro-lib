#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include <iostream>
#include <vector>
#include "Mylib/DataStructure/UnionFind/persistent_unionfind.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, Q; std::cin >> N >> Q;

  std::vector<PersistentUnionFind> G(Q+1);

  G[0] = PersistentUnionFind(N);

  for(int i = 1; i <= Q; ++i){
    int t; std::cin >> t;
    int k, u, v; std::cin >> k >> u >> v;
    ++k;

    if(t == 0){
      G[i] = G[k].merge(u, v);
    }else{
      std::cout << G[k].is_same(u, v) << "\n";
    }
  }

  return 0;
}
