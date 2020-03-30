#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B"

#include <iostream>
#include "Mylib/DataStructure/UnionFind/weighted_unionfind.cpp"

int main(){
  int n, q; std::cin >> n >> q;

  WeightedUnionFind<int> uf(n);

  while(q--){
    int type; std::cin >> type;

    if(type == 0){
      int x, y, z; std::cin >> x >> y >> z;
      uf.merge(x, y, z);
    }else{
      int x, y; std::cin >> x >> y;

      if(uf.is_same(x, y)){
        std::cout << uf.diff(x, y) << std::endl;
      }else{
        std::cout << "?" << std::endl;
      }
    }
  }

  return 0;
}
