#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <iostream>
#include "Mylib/DataStructure/UnionFind/unionfind.cpp"


int main(){
  int N, Q; std::cin >> N >> Q;

  UnionFind uf(N);

  while(Q--){
    int t; std::cin >> t;

    if(t == 0){
      int u, v; std::cin >> u >> v;
      uf.merge(u, v);
    }else{
      int u, v; std::cin >> u >> v;
      std::cout << uf.is_same(u, v) << std::endl;
    }
  }
  
  return 0;
}
