#pragma once
#include <vector>
#include "Mylib/Graph/Template/graph.cpp"

template <typename T>
class CentroidDecomposition {
  int N;
  std::vector<int> parent;
  std::vector<std::vector<int>> children;
  std::vector<int> subsize;
  std::vector<bool> check;

public:
  CentroidDecomposition(const Tree<T> &tree):
    N(tree.size()), parent(N), children(N), subsize(N), check(N)
  {
    decompose(tree, 0, -1);
  }

private:
  void decompose(const Tree<T> &tree, int cur, int par){
    dfs_subsize(tree, cur, -1);
    auto c = get_centroid(tree, cur, -1, subsize[cur]);

    check[c] = true;
    parent[c] = par;
    if(par != -1) children[par].push_back(c);

    for(auto &e : tree[c]){
      if(check[e.to]) continue;
      decompose(tree, e.to, c);
    }
  }

  int get_centroid(const Tree<T> &tree, int cur, int par, int total_size){
    for(auto &e : tree[cur]){
      if(e.to == par or check[e.to]) continue;

      if(2 * subsize[e.to] > total_size){
        return get_centroid(tree, e.to, cur, total_size);
      }
    }

    return cur;
  }

  void dfs_subsize(const Tree<T> &tree, int cur, int par){
    subsize[cur] = 1;
    for(auto &e : tree[cur]){
      if(e.to == par or check[e.to]) continue;
      dfs_subsize(tree, e.to, cur);
      subsize[cur] += subsize[e.to];
    }
  }

public:
  auto bottom_up(int i) const {
    std::vector<int> ret;
    while(i >= 0){
      ret.push_back(i);
      i = parent[i];
    }
    return ret;
  }
};
