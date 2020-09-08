#pragma once
#include <vector>
#include <utility>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/DataStructure/UnionFind/unionfind.cpp"

/**
 * @title Borůvka algorithm
 * @docs boruvka.md
 */
namespace haar_lib {
  template <typename T>
  auto boruvka(const Graph<T> &g){
    std::vector<Edge<T>> ret;
    const int N = g.size();

    UnionFind uf(N);
    std::vector<std::vector<int>> c(N);
    for(int i = 0; i < N; ++i) c[i].push_back(i);

    while((int)(ret.size()) < N - 1){
      std::vector<Edge<T>> temp;

      for(auto &a : c){
        Edge<T> m;
        bool ok = false;

        if(a.empty()) continue;

        for(auto i : a){
          for(auto &e : g[i]){
            if(uf.is_same(e.from, e.to)) continue;
            if(not std::exchange(ok, true) or e.cost < m.cost){
              m = e;
            }
          }
        }

        temp.push_back(m);
      }

      for(auto &e : temp){
        if(uf.is_same(e.from, e.to)) continue;

        const int i = uf.root_of(e.from);
        const int j = uf.root_of(e.to);
        const int k = uf.merge(i, j);

        if(c[i].size() < c[j].size()) std::swap(c[i], c[j]);

        c[i].insert(c[i].end(), c[j].begin(), c[j].end());
        c[j].clear();

        std::swap(c[k], c[i]);

        ret.push_back(e);
      }
    }

    return ret;
  }
}
