#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include <iostream>
#include <vector>
#include <utility>
#include <variant>
#include <tuple>
#include "Mylib/DataStructure/ConvexHullTrick/lichao_segment_tree.cpp"

using Query = std::variant<std::pair<int64_t,int64_t>, int64_t>;

int main(){
  int N, Q; scanf("%d %d", &N, &Q);

  std::vector<int64_t> xs;

  std::vector<std::pair<int64_t, int64_t>> lines;

  for(int i = 0; i < N; ++i){
    int64_t a, b; scanf("%lld %lld", &a, &b);
    lines.emplace_back(a, b);
  }

  std::vector<Query> query;

  for(int i = 0; i < Q; ++i){
    int type; scanf("%d", &type);
    
    switch(type){
    case 0: {
      int64_t a, b; scanf("%lld %lld", &a, &b);
      query.push_back(std::make_pair(a, b));
      break;
    }
    case 1: {
      int64_t p; scanf("%lld", &p);
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
      auto res = lc.query(p);

      printf("%lld\n", *res);
    }
  }

  return 0;
}
