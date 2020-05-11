#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include <iostream>
#include <vector>
#include "Mylib/DataStructure/SegmentTree/Static/Lazy/lazy_segment_tree.cpp"
#include "Mylib/AlgebraicStructure/MonoidAction/affine_sum.cpp"
#include "Mylib/Number/Mint/mint.cpp"

using mint = ModInt<998244353>;


int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;

  auto seg = LazySegmentTree<AffineSum<mint,mint>>(N);

  std::vector<mint> a(N);
  for(int i = 0; i < N; ++i) std::cin >> a[i];
  
  seg.init_with_vector(a);

  while(Q--){
    int t; std::cin >> t;

    if(t == 0){
      int l, r, b, c; std::cin >> l >> r >> b >> c;

      seg.update(l, r, std::make_pair(b, c));
    }else{
      int l, r; std::cin >> l >> r;

      std::cout << seg.get(l, r) << "\n";
    }
  }

  return 0;
}
