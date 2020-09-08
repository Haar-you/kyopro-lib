#pragma once
#include <vector>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Euler tour (Vertex)
 * @docs euler_tour_vertex.md
 */
namespace haar_lib {
  template <typename T>
  class euler_tour_vertex {
    int pos = 0;
    std::vector<int> begin, end;

    void dfs(int cur, int par, const tree<T> &tr){
      begin[cur] = pos++;

      for(auto &e : tr[cur]){
        if(e.to == par) continue;
        dfs(e.to, cur, tr);
      }

      end[cur] = pos;
    }

  public:
    euler_tour_vertex(const tree<T> &tr, int root): begin(tr.size()), end(tr.size()){
      dfs(root, -1, tr);
    }

    template <typename F> // F = std::function<void(int, int)>
    void subtree_query(int i, const F &f){
      f(begin[i], end[i]);
    }

    template <typename F> // F = std::function<void(int)>
    void point_query(int i, const F &f){
      f(begin[i]);
    }
  };
}
