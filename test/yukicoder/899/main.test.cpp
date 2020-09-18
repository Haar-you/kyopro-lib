#define PROBLEM "https://yukicoder.me/problems/no/899"

#include <iostream>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/TreeUtils/euler_tour_bfs.cpp"
#include "Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/update.cpp"
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"
#include "Mylib/AlgebraicStructure/MonoidAction/update_sum.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N; std::cin >> N;

  hl::tree<int> tree(N);
  tree.read<0, false, false>(N - 1);

  auto res = hl::euler_tour_bfs<int>(tree, 0);

  auto A = hl::input_vector<int64_t>(N);
  hl::lazy_segment_tree<hl::sum_monoid<int64_t>, hl::update_monoid<int64_t>, hl::update_sum> seg(N);

  for(int i = 0; i < N; ++i){
    res.query_at(i, [&](int l, int r){seg.update(l, r, A[i]);});
  }

  int Q; std::cin >> Q;

  for(auto [x] : hl::input_tuples<int>(Q)){
    int64_t ans = 0;

    auto f =
      [&](int l, int r){
        ans += seg.get(l, r);
        seg.update(l, r, 0);
      };

    // 親の親
    res.query_at(res.get_ancestor(x, 2), f);

    // 親
    res.query_at(res.get_ancestor(x, 1), f);

    // 親の子
    res.query_children(res.get_parent(x), 1, f);

    // 自分
    res.query_at(x, f);

    // 子
    res.query_children(x, 1, f);

    // 子の子
    res.query_children(x, 2, f);

    res.query_at(
      x,
      [&](int l, int r){
        seg.update(l, r, ans);
      }
    );

    std::cout << ans << std::endl;
  }

  return 0;
}
