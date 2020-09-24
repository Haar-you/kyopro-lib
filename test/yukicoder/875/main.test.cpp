#define PROBLEM "https://yukicoder.me/problems/no/875"

#include <iostream>
#include <vector>
#include <utility>
#include "Mylib/DataStructure/SegmentTree/segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/min.cpp"
#include "Mylib/AlgebraicStructure/Monoid/with_min_index.cpp"
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/IO/input_tuples_with_index.cpp"

namespace hl = haar_lib;

using M = hl::with_min_index<hl::min_monoid<int>>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;

  hl::segment_tree<M> seg(N);

  std::vector<M::value_type> a(N);
  for(auto [i, x] : hl::input_tuples_with_index<int>(N)){
    a[i] = {x, i};
  }

  seg.init_with_vector(a);

  for(auto [type, l, r] : hl::input_tuples<int, int, int>(Q)){
    switch(type){
    case 1: {
      --l, --r;

      auto x = seg[l].value;
      auto y = seg[r].value;

      seg.set(l, {y, l});
      seg.set(r, {x, r});

      break;
    }
    case 2: {
      --l, --r;

      std::cout << seg.fold(l, r + 1).index + 1 << "\n";

      break;
    }
    }
  }

  return 0;
}
