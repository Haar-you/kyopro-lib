#pragma once
#include <vector>
#include "Mylib/Grid/grid.cpp"
#include "Mylib/Graph/graph_template.cpp"

/**
 * @title グリッドをグラフに変換する
 * @docs grid_to_graph.md
 */
template <typename T, typename Directions, typename Checker, typename Generator>
Graph<T> grid_to_graph(int H, int W,
                       const Directions &dir,
                       const Checker &check_passable,
                       const std::vector<std::vector<int>> &index,
                       const Generator &generate_edge_cost)
{
  Graph<T> ret(H * W);

  for(int i = 0; i < H; ++i){
    for(int j = 0; j < W; ++j){
      auto p = Point(i, j);

      for(auto &d : dir){
        auto q = Point(i, j) + d;

        if(q.x < 0 or q.x >= H or q.y < 0 or q.y >= W or not check_passable(p, q)) continue;

        auto e = Edge<T>(index[p.x][p.y], index[q.x][q.y], generate_edge_cost(p, q));
        
        ret[index[p.x][p.y]].emplace_back(e);
      }
    }
  }
  
  return ret;
}
