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
  class hl_decomposition {
    int n;

    std::vector<int> sub, // subtree size
      par, // parent id
      head, // chain head id
      id, // id[original id] = hld id
      rid, // rid[hld id] = original id
      next, // next node in a chain
      end; //

    int dfs_sub(tree<T> &tr, int cur, int p){
      par[cur] = p;
      int t = 0;
      for(auto &e : tr[cur]){
        if(e.to == p) continue;
        sub[cur] += dfs_sub(tr, e.to, cur);
        if(sub[e.to] > t){
          t = sub[e.to];
          next[cur] = e.to;
          std::swap(e, tr[cur][0]);
        }
      }
      return sub[cur];
    }

    void dfs_build(const tree<T> &tr, int cur, int &i){
      id[cur] = i;
      rid[i] = cur;
      ++i;

      for(auto &e : tr[cur]){
        if(e.to == par[cur]) continue;
        head[e.to] = (e.to == tr[cur][0].to ? head[cur] : e.to);
        dfs_build(tr, e.to, i);
      }

      end[cur] = i;
    }

  public:
    hl_decomposition(tree<T> tr, int root):
      n(tr.size()), sub(n, 1), par(n, -1), head(n), id(n), rid(n), next(n, -1), end(n, -1){
      dfs_sub(tr, root, -1);
      int i = 0;
      dfs_build(tr, root, i);
    }

    std::vector<std::tuple<int, int, bool>> path_query_vertex(int x, int y) const {
      std::vector<std::tuple<int, int, bool>> ret;
      const int w = lca(x, y);

      {
        int y = w;
        bool d = true;
        while(1){
          if(id[x] > id[y]) std::swap(x, y), d = not d;
          int l = std::max(id[head[y]], id[x]), r = id[y] + 1;
          if(l != r) ret.emplace_back(l, r, d);
          if(head[x] == head[y]) break;
          y = par[head[y]];
        }
      }

      x = y;
      y = w;

      {
        std::vector<std::tuple<int, int, bool>> temp;
        bool d = false;
        while(1){
          if(id[x] > id[y]) std::swap(x, y), d = not d;
          int l = std::max({id[head[y]], id[x], id[w] + 1}), r = id[y] + 1;
          if(l != r) temp.emplace_back(l, r, d);
          if(head[x] == head[y]) break;
          y = par[head[y]];
        }

        std::reverse(temp.begin(), temp.end());
        ret.insert(ret.end(), temp.begin(), temp.end());
      }

      return ret;
    }

    std::vector<std::pair<int, int>> path_query_edge(int x, int y) const {
      std::vector<std::pair<int, int>> ret;
      while(1){
        if(id[x] > id[y]) std::swap(x, y);
        if(head[x] == head[y]){
          if(x != y) ret.emplace_back(id[x] + 1, id[y] + 1);
          break;
        }
        ret.emplace_back(id[head[y]], id[y] + 1);
        y = par[head[y]];
      }
      return ret;
    }

    std::pair<int, int> subtree_query_edge(int x) const {
      return {id[x] + 1, end[x]};
    }

    std::pair<int, int> subtree_query_vertex(int x) const {
      return {id[x], end[x]};
    }

    int get_edge_id(int u, int v) const { // 辺に対応するid
      if(par[u] == v) return id[u];
      if(par[v] == u) return id[v];
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
