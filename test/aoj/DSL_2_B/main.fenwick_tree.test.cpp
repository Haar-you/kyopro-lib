#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include <iostream>
#include "Mylib/DataStructure/FenwickTree/fenwick_tree.cpp"
#include "Mylib/AlgebraicStructure/Group/sum_group.cpp"

int main(){
  int n, q; std::cin >> n >> q;

  auto fen = FenwickTree<SumGroup<int>>(n);

  for(int i = 0; i < q; ++i){
    int type; std::cin >> type;

    if(type == 0){
      int x,y; std::cin >> x >> y;
      fen.update(x-1, y);
    }else{
      int x,y; std::cin >> x >> y;
      std::cout << fen.get(x-1, y) << std::endl;
    }
  }

  return 0;
}
