#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508"

#include <iostream>
#include "Mylib/DataStructure/Treap/treap.cpp"
#include "Mylib/AlgebraicStructure/Monoid/min.cpp"
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/IO/input_tuples_with_index.cpp"

int main(){
  int n, q; std::cin >> n >> q;
  
  treap::Treap<MinMonoid<int>> s(n);
  
  for(auto [i, a] : input_tuples_with_index<int>(n)){
    s.update(i, a);
  }
  
  for(auto [x, y, z] : input_tuples<int, int, int>(q)){
    if(x == 0){
      auto temp = s.get(z);
      s.erase(z);
      s.insert(y, temp);
    }else if(x == 1){
      auto ans = s.fold(y, z+1);
      std::cout << ans << std::endl;
    }else{
      s.update(y, z);
    }
  }
  
  return 0;
}
