#pragma once
#include <vector>
#include "Mylib/Grid/grid.cpp"
#include "Mylib/Graph/Template/graph.cpp"

namespace haar_lib {
  template <typename T, typename Directions, typename Index, typename Checker, typename Generator>
  graph<T> grid_to_graph(
    int H, int W,
    const Directions &dir,
    const Index &index,
    const Checker &check_passable,
    const Generator &generate_edge_cost
  ){
    graph<T> ret(H * W);

    for(int i = 0; i < H; ++i){
      for(int j = 0; j < W; ++j){
        auto p = cell(i, j);

        for(auto &d : dir){
          auto q = cell(i, j) + d;

          if(q.x < 0 or q.x >= H or q.y < 0 or q.y >= W or not check_passable(p, q)) continue;

          ret.add_edge(index(p.x, p.y), index(q.x, q.y), generate_edge_cost(p, q));
        }
      }
    }

    return ret;
  }
}
