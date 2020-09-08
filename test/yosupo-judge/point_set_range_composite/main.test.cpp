#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include <iostream>
#include <utility>
#include "Mylib/DataStructure/SegmentTree/segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/affine.cpp"
#include "Mylib/AlgebraicStructure/Monoid/dual.cpp"
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/IO/input_tuples_with_index.cpp"

namespace hl = haar_lib;

using mint = hl::modint<998244353>;
using M = hl::dual_monoid<hl::affine_monoid<mint>>;

int main(){
  int N, Q; std::cin >> N >> Q;

  auto seg = hl::segment_tree<M>(N);

  for(auto [i, a, b] : hl::input_tuples_with_index<int, int>(N)){
    seg.update(i, {a, b});
  }

  for(auto [t] : hl::input_tuples<int>(Q)){
    if(t == 0){
      int p, c, d; std::cin >> p >> c >> d;
      seg.update(p, {c, d});
    }else{
      int l, r, x; std::cin >> l >> r >> x;
      auto [a, b] = seg.get(l, r);
      std::cout << a * x + b << std::endl;
    }
  }

  return 0;
}
