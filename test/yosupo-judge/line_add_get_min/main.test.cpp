#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include <iostream>
#include <vector>
#include <utility>
#include <variant>
#include <tuple>
#include "Mylib/DataStructure/ConvexHullTrick/lichao_segment_tree.cpp"
#include "Mylib/IO/input_tuples.cpp"

using Query = std::variant<std::pair<int64_t,int64_t>, int64_t>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;

  std::vector<int64_t> xs;

  std::vector<std::pair<int64_t, int64_t>> lines;

  for(auto [a, b] : input_tuples<int64_t, int64_t>(N)){
    lines.emplace_back(a, b);
  }

  std::vector<Query> query;

  for(auto [type] : input_tuples<int>(Q)){
    switch(type){
    case 0: {
      int64_t a, b; std::cin >> a >> b;
      query.push_back(std::make_pair(a, b));
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

  auto lc = make_lichao_min(xs);

  for(auto [a, b] : lines){
    lc.add_line(a, b);
  }
  
  for(auto &q : query){
    if(q.index() == 0){
      auto [a, b] = std::get<0>(q);
      lc.add_line(a, b);
    }else{
      auto p = std::get<1>(q);
      auto res = lc(p);

      std::cout << *res << "\n";
    }
  }

  return 0;
}
