#pragma once
#include <utility>
#include <cassert>
#include "Mylib/Graph/Template/graph.cpp"

namespace haar_lib {
  template <typename T>
  class range_edge_graph : public graph<T> {
    using super = graph<T>;

    int k, N;
    int calc_size(int N) const {
      int ret = 1;
      while(ret < N) ret *= 2;
      return ret;
    }

  public:
    range_edge_graph(int N): graph<T>(5 * (k = (calc_size(N)))), N(N){
      for(int i = 2; i < 2 * k; ++i){
        super::add_edge(k + (i >> 1), k + i, 0);
        super::add_edge(3 * k + i, 3 * k + (i >> 1), 0);
      }

      for(int i = 0; i < N; ++i){
        super::add_edge(2 * k + i, i, 0);
        super::add_edge(i, 4 * k + i, 0);
      }
    }

    void add_edge(int i, int j, T w){
      super::add_edge(i, j, w);
    }

    void add_edge(int i, std::pair<int, int> p, T w){
      auto [l, r] = p;
      for(l += k, r += k; l < r; l >>= 1, r >>= 1){
        if(l & 1) super::add_edge(i, l + k, w), ++l;
        if(r & 1) --r, super::add_edge(i, r + k, w);
      }
    }

    void add_edge(std::pair<int, int> p, int i, T w){
      auto [l, r] = p;
      for(l += k, r += k; l < r; l >>= 1, r >>= 1){
        if(l & 1) super::add_edge(l + 3 * k, i, w), ++l;
        if(r & 1) --r, super::add_edge(r + 3 * k, i, w);
      }
    }

    void add_edge(std::pair<int, int> p, std::pair<int, int> q, T w){
      int x = super::size();
      super::ds.emplace_back();
      int y = super::size();
      super::ds.emplace_back();

      add_edge(p, x, 0);
      add_edge(x, y, w);
      add_edge(y, q, 0);
    }
  };
}
