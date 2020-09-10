#pragma once
#include <vector>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Centroid decomposition
 * @docs centroid_decomposition.md
 */
namespace haar_lib {
  template <typename T>
  class centroid_decomposition {
    int N;
    std::vector<int> parent;
    std::vector<std::vector<int>> children;
    std::vector<int> subsize;
    std::vector<bool> check;

  public:
    centroid_decomposition(const tree<T> &tr):
      N(tr.size()), parent(N), children(N), subsize(N), check(N)
    {
      decompose(tr, 0, -1);
    }

  private:
    void decompose(const tree<T> &tr, int cur, int par){
      dfs_subsize(tr, cur, -1);
      auto c = get_centroid(tr, cur, -1, subsize[cur]);

      check[c] = true;
      parent[c] = par;
      if(par != -1) children[par].push_back(c);

      for(auto &e : tr[c]){
        if(check[e.to]) continue;
        decompose(tr, e.to, c);
      }
    }

    int get_centroid(const tree<T> &tr, int cur, int par, int total_size){
      for(auto &e : tr[cur]){
        if(e.to == par or check[e.to]) continue;

        if(2 * subsize[e.to] > total_size){
          return get_centroid(tr, e.to, cur, total_size);
        }
      }

      return cur;
    }

    void dfs_subsize(const tree<T> &tr, int cur, int par){
      subsize[cur] = 1;
      for(auto &e : tr[cur]){
        if(e.to == par or check[e.to]) continue;
        dfs_subsize(tr, e.to, cur);
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
}
