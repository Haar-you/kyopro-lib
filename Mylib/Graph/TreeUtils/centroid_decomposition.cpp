#pragma once
#include <vector>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Centroid decomposition
 * @docs centroid_decomposition.md
 */
template <typename T>
struct CentroidDecomposition {
  Tree<T> tree;
  const int N;

  std::vector<int> size;
  std::vector<bool> checked;
  std::vector<int> depth;

  CentroidDecomposition(const Tree<T> &tree):
    tree(tree), N(tree.size()), size(N), checked(N), depth(N)
  {
    decompose(0, 0);
  }

  void decompose(int cur, int d){
    dfs_subsize(cur, -1);
    auto c = get_centroid(cur, -1, size[cur]);

    checked[c] = true;
    depth[c] = d;

    for(auto &e : tree[c]){
      if(checked[e.to]) continue;
      decompose(e.to, d + 1);
    }
  }

  int get_centroid(int cur, int par, int total_size){
    for(auto &e : tree[cur]){
      if(e.to == par or checked[e.to]) continue;

      if(2 * size[e.to] > total_size){
        return get_centroid(e.to, cur, total_size);
      }
    }

    return cur;
  }

  void dfs_subsize(int cur, int par){
    size[cur] = 1;
    for(auto &e : tree[cur]){
      if(e.to == par or checked[e.to]) continue;
      dfs_subsize(e.to, cur);
      size[cur] += size[e.to];
    }
  }
};
