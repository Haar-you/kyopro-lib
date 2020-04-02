#pragma once
#include <vector>
#include <utility>
#include "Mylib/Graph/graph_template.cpp"

/**
 * @title HLD実装の最小共通祖先
 */
template <typename T> class LCA{
  int n;
  std::vector<int> sub, par, head, id;
  
  int dfs_sub(int cur, int p, Tree<T> &tree){
    par[cur] = p;
    int t = 0;
    for(auto &e : tree[cur]){
      if(e.to == p) continue;
      sub[cur] += dfs_sub(e.to, cur, tree);
      if(sub[e.to] > t){
        t = sub[e.to];
        std::swap(e, tree[cur][0]);
      }
    }
    return sub[cur];
  }

  void dfs_build(int cur, int &i, Tree<T> &tree){
    id[cur] = i;
    ++i;

    for(auto &e : tree[cur]){
      if(e.to == par[cur]) continue;
      head[e.to] = (e.to == tree[cur][0].to ? head[cur] : e.to);
      dfs_build(e.to, i, tree);
    }
  }
  
public:
  LCA(Tree<T> tree, int root):
    n(tree.size()), sub(n,1), par(n,-1), head(n), id(n){
    dfs_sub(root, -1, tree);
    int i = 0;
    dfs_build(root, i, tree);
  }

  int lca(int u, int v) const {
    while(1){
      if(id[u] > id[v]) std::swap(u, v);
      if(head[u] == head[v]) return u;
      v = par[head[v]];
    }
  }
};
