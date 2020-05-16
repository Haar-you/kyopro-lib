#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H"

#include <iostream>
#include "Mylib/DataStructure/SegmentTree/starry_sky_tree_min.cpp"

int main(){
  int n, q; std::cin >> n >> q;

  StarrySkyTreeMin<int> seg(n);

  while(q--){
    int type; std::cin >> type;

    if(type == 0){
      int s,t,x; std::cin >> s >> t >> x;

      seg.update(s, t+1, x);
    }else{
      int s,t; std::cin >> s >> t;

      std::cout << seg.get(s, t+1) << std::endl;
    }
  }

  return 0;
}
