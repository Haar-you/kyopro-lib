#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <iostream>
#include "Mylib/DataStructure/UnionFind/unionfind.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;

  UnionFind uf(N);

  for(auto [t, u, v] : input_tuples<int, int, int>(Q)){
    if(t == 0){
      uf.merge(u, v);
    }else{
      std::cout << uf.is_same(u, v) << std::endl;
    }
  }

  return 0;
}
