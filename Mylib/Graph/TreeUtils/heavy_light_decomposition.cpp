#pragma once
#include <vector>
#include <utility>
#include <algorithm>
#include "Mylib/Graph/Template/graph.cpp"

namespace haar_lib {
  template <typename T>
  class hl_decomposition {
    int n_;

    std::vector<int> sub_, // subtree size
      par_, // parent id
      head_, // chain head id
      id_, // id[original id] = hld id
      rid_, // rid[hld id] = original id
      next_, // next node in a chain
      end_; //

    int dfs_sub(tree<T> &tr, int cur, int p){
      par_[cur] = p;
      int t = 0;
      for(auto &e : tr[cur]){
        if(e.to == p) continue;
        sub_[cur] += dfs_sub(tr, e.to, cur);
        if(sub_[e.to] > t){
          t = sub_[e.to];
          next_[cur] = e.to;
          std::swap(e, tr[cur][0]);
        }
      }
      return sub_[cur];
    }

    void dfs_build(const tree<T> &tr, int cur, int &i){
      id_[cur] = i;
      rid_[i] = cur;
      ++i;

      for(auto &e : tr[cur]){
        if(e.to == par_[cur]) continue;
        head_[e.to] = (e.to == tr[cur][0].to ? head_[cur] : e.to);
        dfs_build(tr, e.to, i);
      }

      end_[cur] = i;
    }

  public:
    hl_decomposition(){}
    hl_decomposition(tree<T> tr, int root):
      n_(tr.size()), sub_(n_, 1), par_(n_, -1), head_(n_), id_(n_), rid_(n_), next_(n_, -1), end_(n_, -1){
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
          if(id_[x] > id_[y]) std::swap(x, y), d = not d;
          int l = std::max(id_[head_[y]], id_[x]), r = id_[y] + 1;
          if(l != r) ret.emplace_back(l, r, d);
          if(head_[x] == head_[y]) break;
          y = par_[head_[y]];
        }
      }

      x = y;
      y = w;

      {
        std::vector<std::tuple<int, int, bool>> temp;
        bool d = false;
        while(1){
          if(id_[x] > id_[y]) std::swap(x, y), d = not d;
          int l = std::max({id_[head_[y]], id_[x], id_[w] + 1}), r = id_[y] + 1;
          if(l != r) temp.emplace_back(l, r, d);
          if(head_[x] == head_[y]) break;
          y = par_[head_[y]];
        }

        std::reverse(temp.begin(), temp.end());
        ret.insert(ret.end(), temp.begin(), temp.end());
      }

      return ret;
    }

    std::vector<std::pair<int, int>> path_query_edge(int x, int y) const {
      std::vector<std::pair<int, int>> ret;
      while(1){
        if(id_[x] > id_[y]) std::swap(x, y);
        if(head_[x] == head_[y]){
          if(x != y) ret.emplace_back(id_[x] + 1, id_[y] + 1);
          break;
        }
        ret.emplace_back(id_[head_[y]], id_[y] + 1);
        y = par_[head_[y]];
      }
      return ret;
    }

    std::pair<int, int> subtree_query_edge(int x) const {
      return {id_[x] + 1, end_[x]};
    }

    std::pair<int, int> subtree_query_vertex(int x) const {
      return {id_[x], end_[x]};
    }

    int get_edge_id(int u, int v) const { // 辺に対応するid
      if(par_[u] == v) return id_[u];
      if(par_[v] == u) return id_[v];
      return -1;
    }

    int parent(int x) const {return par_[x];};

    int lca(int u, int v) const {
      while(1){
        if(id_[u] > id_[v]) std::swap(u, v);
        if(head_[u] == head_[v]) return u;
        v = par_[head_[v]];
      }
    }

    int get_id(int x) const {
      return id_[x];
    }
  };
}
