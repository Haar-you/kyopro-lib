#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B"

#include <iostream>
#include "Mylib/DataStructure/UnionFind/weighted_unionfind.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main(){
  int n, q; std::cin >> n >> q;

  hl::weighted_unionfind<int> uf(n);

  for(auto [type, x, y] : hl::input_tuples<int, int, int>(q)){
    if(type == 0){
      int z; std::cin >> z;
      uf.merge(x, y, z);
    }else{
      if(uf.is_same(x, y)){
        std::cout << uf.diff(x, y) << std::endl;
      }else{
        std::cout << "?" << std::endl;
      }
    }
  }

  return 0;
}
