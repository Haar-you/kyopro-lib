#pragma once
#include <vector>
#include <cmath>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Lowest common ancestor (Doubling)
 * @docs lca_based_on_doubling.md
 */
template <typename T> class LCA{
private:
  std::vector<std::vector<int>> parent;
  int n, log2n;
  
  void dfs(const Tree<T> &tree, int cur, int par, int d){
    parent[cur][0] = par;
    depth[cur] = d;

    for(auto &e : tree[cur]){
      if(e.to != par){
        dist[e.to] = dist[cur] + e.cost;
        dfs(tree, e.to, cur, d+1);
      }
    }
  }
  
public:
  std::vector<int> depth;
  std::vector<T> dist;

  LCA(){}
  LCA(const Tree<T> &tree, int root):
    n(tree.size()), depth(n), dist(n)
  {
    log2n = (int)ceil(log(n) / log(2)) + 1;
    parent = std::vector<std::vector<int>>(n, std::vector<int>(log2n, 0));

    dfs(tree, root, -1, 0);
    for(int k = 0; k < log2n-1; ++k){
      for(int v = 0; v < n; ++v){
        if(parent[v][k] == -1) parent[v][k+1] = -1;
        else parent[v][k+1] = parent[parent[v][k]][k];
      }
    }
  }

  int lca(int a, int b) const {
    if(depth[a] >= depth[b]) std::swap(a,b);
    for(int k = 0; k < log2n; ++k) if((depth[b] - depth[a]) >> k & 1) b = parent[b][k];
    if(a == b) return a;
    for(int k = log2n-1; k >= 0; --k) if(parent[a][k] != parent[b][k]){a = parent[a][k]; b = parent[b][k];}
    return parent[a][0];
  }

  int operator()(int a, int b) const {return lca(a, b);}

  T distance(int a, int b) const {
    return dist[a] + dist[b] - 2 * dist[lca(a,b)];
  }
};
