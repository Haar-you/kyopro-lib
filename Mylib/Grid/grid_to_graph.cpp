#pragma once
#include <vector>
#include "Mylib/Grid/grid.cpp"
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Convert grid to graph
 * @docs grid_to_graph.md
 */
template <typename T, typename Directions, typename Index, typename Checker, typename Generator>
Graph<T> grid_to_graph(
  int H, int W,
  const Directions &dir,
  const Index &index,
  const Checker &check_passable,
  const Generator &generate_edge_cost
){
  Graph<T> ret(H * W);

  for(int i = 0; i < H; ++i){
    for(int j = 0; j < W; ++j){
      auto p = Point(i, j);

      for(auto &d : dir){
        auto q = Point(i, j) + d;

        if(q.x < 0 or q.x >= H or q.y < 0 or q.y >= W or not check_passable(p, q)) continue;

        ret.add_edge(index(p.x, p.y), index(q.x, q.y), generate_edge_cost(p, q));
      }
    }
  }
  
  return ret;
}
