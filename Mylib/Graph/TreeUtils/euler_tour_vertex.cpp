#pragma once
#include <vector>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Euler tour (Vertex)
 * @docs euler_tour_vertex.md
 */
namespace haar_lib {
  template <typename T>
  class EulerTourVertex {
    int pos = 0;
    std::vector<int> begin, end;

    void dfs(int cur, int par, const Tree<T> &tree){
      begin[cur] = pos++;

      for(auto &e : tree[cur]){
        if(e.to == par) continue;
        dfs(e.to, cur, tree);
      }

      end[cur] = pos;
    }

  public:
    EulerTourVertex(const Tree<T> &tree, int root): begin(tree.size()), end(tree.size()){
      dfs(root, -1, tree);
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
