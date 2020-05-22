#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"

#include <iostream>
#include <vector>
#include <utility>
#include <variant>
#include <tuple>
#include "Mylib/DataStructure/ConvexHullTrick/lichao_segment_tree.cpp"

using Segment = std::tuple<int64_t, int64_t, int64_t, int64_t>;
using Query = std::variant<Segment, int64_t>;

int main(){
  int N, Q; scanf("%d %d", &N, &Q);

  std::vector<int64_t> xs;

  std::vector<Segment> lines;

  for(int i = 0; i < N; ++i){
    int64_t l, r, a, b; scanf("%lld %lld %lld %lld", &l, &r, &a, &b);
    lines.emplace_back(l, r, a, b);
  }

  std::vector<Query> query;

  for(int i = 0; i < Q; ++i){
    int type; scanf("%d", &type);
    
    switch(type){
    case 0: {
      int64_t l, r, a, b; scanf("%lld %lld %lld %lld", &l, &r, &a, &b);
      query.push_back(Segment({l, r, a, b}));
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
        auto res = lc.query(p);

        if(res){
          printf("%lld\n", *res);
        }else{
          puts("INFINITY");
        }
      }
    }
  }

  return 0;
}
