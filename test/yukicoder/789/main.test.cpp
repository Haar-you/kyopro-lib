#define PROBLEM "https://yukicoder.me/problems/no/789"

#include <iostream>
#include "Mylib/DataStructure/SegmentTree/dynamic_segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n; std::cin >> n;

  hl::DynamicSegmentTree<hl::SumMonoid<int64_t>> seg(1000000001);

  int64_t ans = 0;

  for(auto [q, x, y] : hl::input_tuples<int, int, int>(n)){
    if(q == 0){
      seg.update(x, seg[x] + y);
    }else{
      ans += seg.get(x, y + 1);
    }
  }

  std::cout << ans << "\n";

  return 0;
}
