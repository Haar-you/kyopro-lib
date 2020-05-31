#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include <iostream>
#include <vector>

#include "Mylib/Misc/sort_simultaneously.cpp"
#include "Mylib/DataStructure/SegmentTree/persistent_segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"
#include "Mylib/Misc/compressor.cpp"
#include "Mylib/IO/input_tuple_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"

using Seg = PersistentSegmentTree<SumMonoid<int64_t>>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, Q; std::cin >> N >> Q;

  auto [x, y, w] = input_tuple_vector<int64_t, int64_t, int64_t>(N);

  sort_simultaneously(
    [&](int i, int j){
      return y[i] < y[j];
    },
    N, x, y, w
  );

  auto c = Compressor<int64_t>().add(x).build().compress(x);
  const int m = c.size();
  
  std::vector<Seg> seg;
  seg.push_back(Seg(m));

  for(int i = 0; i < N; ++i){
    auto &s = seg.back();
    seg.push_back(s.update(x[i], s.at(x[i]) + w[i]));
  }
  
  for(auto [l, d, r, u] : input_tuples<int64_t, int64_t, int64_t, int64_t>(Q)){
    l = c.get_index(l);
    r = c.get_index(r);

    u = std::lower_bound(y.begin(), y.end(), u) - y.begin();
    d = std::lower_bound(y.begin(), y.end(), d) - y.begin();

    auto ans = seg[u].get(l, r) - seg[d].get(l, r);
    std::cout << ans << "\n";
  }
  
  return 0;
}
