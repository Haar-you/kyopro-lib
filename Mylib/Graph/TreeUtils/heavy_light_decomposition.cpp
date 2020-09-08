#pragma once
#include <vector>
#include <utility>
#include <algorithm>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Heavy-light decomposition
 * @docs heavy_light_decomposition.md
 */
namespace haar_lib {
  template <typename T>
  class HLDecomposition {
    int n;

    std::vector<int> sub, // subtree size
      par, // parent id
      head, // chain head id
      id, // id[original id] = hld id
      rid, // rid[hld id] = original id
      next, // next node in a chain
      end; //

    int dfs_sub(Tree<T> &tree, int cur, int p){
      par[cur] = p;
      int t = 0;
      for(auto &e : tree[cur]){
        if(e.to == p) continue;
        sub[cur] += dfs_sub(tree, e.to, cur);
        if(sub[e.to] > t){
          t = sub[e.to];
          next[cur] = e.to;
          std::swap(e, tree[cur][0]);
        }
      }
      return sub[cur];
    }

    void dfs_build(const Tree<T> &tree, int cur, int &i){
      id[cur] = i;
      rid[i] = cur;
      ++i;

      for(auto &e : tree[cur]){
        if(e.to == par[cur]) continue;
        head[e.to] = (e.to == tree[cur][0].to ? head[cur] : e.to);
        dfs_build(tree, e.to, i);
      }

      end[cur] = i;
    }

  public:
    HLDecomposition(Tree<T> tree, int root):
      n(tree.size()), sub(n, 1), par(n, -1), head(n), id(n), rid(n), next(n, -1), end(n, -1){
      dfs_sub(tree, root, -1);
      int i = 0;
      dfs_build(tree, root, i);
    }

    template <typename Func> // std::function<void(int, int)>
    void path_query_vertex(int x, int y, const Func &f) const {
      while(1){
        if(id[x] > id[y]) std::swap(x, y);
        f(std::max(id[head[y]], id[x]), id[y] + 1);
        if(head[x] == head[y]) return;
        y = par[head[y]];
      }
    }

    template <typename LeftFunc, typename RightFunc>
    void path_query_vertex(int x, int y, const LeftFunc &f, const RightFunc &g) const {
      const int w = lca(x, y);

      path_query_vertex(x, w, f);

      x = y;
      y = w;

      while(1){
        if(id[x] > id[y]){
          std::swap(x, y);
        }
        g(std::max({id[head[y]], id[x], id[w] + 1}), id[y] + 1);
        if(head[x] == head[y]) return;
        y = par[head[y]];
      }
    }

    template <typename Func> // std::function<void(int, int)>
    void path_query_edge(int x, int y, const Func &f) const {
      while(1){
        if(id[x] > id[y]) std::swap(x, y);
        if(head[x] == head[y]){
          if(x != y) f(id[x] + 1, id[y] + 1);
          return;
        }
        f(id[head[y]], id[y] + 1);
        y = par[head[y]];
      }
    }

    template <typename Func> // std::function<void(int, int)>
    void subtree_query_edge(int x, const Func &f) const {
      f(id[x] + 1, end[x]);
    }

    template <typename Func> // std::function<void(int, int)>
    void subtree_query_vertex(int x, const Func &f) const {
      f(id[x], end[x]);
    }

    int get_edge_id(int u, int v) const { // 辺に対応するid
      if(par[u] == v){
        return id[u];
      }else if(par[v] == u){
        return id[v];
      }

      return -1;
    }

    int parent(int x) const {return par[x];};

    int lca(int u, int v) const {
      while(1){
        if(id[u] > id[v]) std::swap(u, v);
        if(head[u] == head[v]) return u;
        v = par[head[v]];
      }
    }

    int get_id(int x) const {
      return id[x];
    }
  };
}
