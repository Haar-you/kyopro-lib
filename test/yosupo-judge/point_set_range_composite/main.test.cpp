#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include <iostream>
#include <utility>
#include "Mylib/DataStructure/SegmentTree/Static/Normal/segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/affine_monoid.cpp"
#include "Mylib/AlgebraicStructure/Monoid/dual_monoid.cpp"
#include "Mylib/Number/Mint/mint.cpp"

using mint = ModInt<998244353>;
using M = DualMonoid<AffineMonoid<mint>>;

int main(){
  int N, Q; std::cin >> N >> Q;

  auto seg = SegmentTree<M>(N);

  for(int i = 0; i < N; ++i){
    int a, b; std::cin >> a >> b;
    seg.update(i, {a, b});
  }

  for(int i = 0; i < Q; ++i){
    int t; std::cin >> t;

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
