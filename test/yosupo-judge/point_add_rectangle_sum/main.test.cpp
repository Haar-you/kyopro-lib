#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include <iostream>
#include <variant>
#include <tuple>
#include <vector>
#include "Mylib/DataStructure/SegmentTree/segment_tree_on_segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"
#include "Mylib/IO/input_tuple_vector.cpp"

namespace hl = haar_lib;

using Query = std::variant<std::tuple<int, int, int>, std::tuple<int, int, int, int>>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;

  hl::segment_tree_on_segment_tree<hl::sum_monoid<int64_t>> seg;

  auto [x, y, w] = hl::input_tuple_vector<int, int, int>(N);
  for(int i = 0; i < N; ++i){
    seg.add(x[i], y[i]);
  }

  std::vector<Query> queries(Q);
  for(int i = 0; i < Q; ++i){
    int type; std::cin >> type;

    if(type == 0){
      int x, y, w; std::cin >> x >> y >> w;
      queries[i] = std::make_tuple(x, y, w);
      seg.add(x, y);
    }else{
      int l, d, r, u; std::cin >> l >> d >> r >> u;
      queries[i] = std::make_tuple(l, d, r, u);
    }
  }

  seg.build();

  for(int i = 0; i < N; ++i){
    seg.update({x[i], y[i]}, w[i]);
  }

  for(auto q : queries){
    if(q.index() == 0){
      auto [x, y, w] = std::get<0>(q);
      seg.update({x, y}, w);
    }else{
      auto [l, d, r, u] = std::get<1>(q);
      std::cout << seg.get({l, d}, {r, u}) << "\n";
    }
  }

  return 0;
}
