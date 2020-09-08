#pragma once
#include <algorithm>
#include <vector>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/DataStructure/UnionFind/unionfind.cpp"

/**
 * @title Kruskal algorithm
 * @docs kruskal.md
 */
namespace haar_lib {
  template <typename T>
  std::vector<Edge<T>> kruskal(const Graph<T> &graph){
    const int n = graph.size();
    std::vector<Edge<T>> edges;
    for(auto &v : graph){
      for(auto &e : v){
        edges.push_back(e);
      }
    }

    std::sort(edges.begin(), edges.end(), [](const auto &a, const auto &b){return a.cost < b.cost;});

    UnionFind uf(n);

    std::vector<Edge<T>> ret;

    for(auto &e : edges){
      if(!uf.is_same(e.from, e.to)){
        uf.merge(e.from, e.to);
        ret.push_back(e);
      }
    }

    return ret;
  }
}
