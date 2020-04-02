#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508"

#include <iostream>
#include "Mylib/DataStructure/SplayTree/splay_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/min_monoid.cpp"

int main(){
  int n, q; std::cin >> n >> q;
  
  splay_tree::SplayTree<MinMonoid<int>> s(n);
  
  for(int i = 0; i < n; ++i){
    int a; std::cin >> a;
    s.update(i, a);
  }
  
  while(q--){
    int x, y, z; std::cin >> x >> y >> z;
    
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
