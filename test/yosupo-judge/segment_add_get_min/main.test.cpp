#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"

#include <iostream>
#include <vector>
#include <utility>
#include <variant>
#include <tuple>
#include "Mylib/DataStructure/ConvexHullTrick/lichao_segment_tree.cpp"
#include "Mylib/IO/input_tuples.cpp"

using Segment = std::tuple<int64_t, int64_t, int64_t, int64_t>;
using Query = std::variant<Segment, int64_t>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;

  std::vector<int64_t> xs;

  std::vector<Segment> lines;

  for(auto [l, r, a, b] : input_tuples<int64_t, int64_t, int64_t, int64_t>(N)){
    lines.emplace_back(l, r, a, b);
  }

  std::vector<Query> query;

  for(auto [type] : input_tuples<int>(Q)){
    switch(type){
    case 0: {
      int64_t l, r, a, b; std::cin >> l >> r >> a >> b;
      query.push_back(Segment({l, r, a, b}));
      break;
    }
    case 1: {
      int64_t p; std::cin >> p;
      query.push_back(p);
      xs.push_back(p);
      break;
    }
    }
  }

  if(not xs.empty()){
    auto lc = make_lichao_min(xs);

    for(auto [l, r, a, b] : lines){
      lc.add_segment(l, r, a, b);
    }

    for(auto &q : query){
      if(q.index() == 0){
        auto [l, r, a, b] = std::get<0>(q);
        lc.add_segment(l, r, a, b);
      }else{
        auto p = std::get<1>(q);
        auto res = lc(p);

        if(res){
          std::cout << *res << "\n";
        }else{
          std::cout << "INFINITY" << "\n";
        }
      }
    }
  }

  return 0;
}
