#pragma once
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <cmath>
#include "Mylib/AlgebraicStructure/Monoid/min.cpp"
#include "Mylib/DataStructure/SegmentTree/segment_tree.cpp"
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/MinimumSpanningTree/kruskal.cpp"

namespace haar_lib {
  template <typename T>
  std::vector<edge<T>> manhattan_minimum_spanning_tree(std::vector<T> x, std::vector<T> y){
    const int N = x.size();
    graph<T> g(N);
    segment_tree<min_monoid<std::pair<T, int>>> seg(N);

    auto f =
      [&](){
        std::vector<T> Y(y);
        std::sort(Y.begin(), Y.end());
        Y.erase(std::unique(Y.begin(), Y.end()), Y.end());

        seg.init(std::nullopt);

        std::vector<int> ord(N);
        std::iota(ord.begin(), ord.end(), 0);
        std::sort(
          ord.begin(), ord.end(),
          [&](int i, int j){
            if(y[i] - x[i] == y[j] - x[j]) return x[i] > x[j];
            return y[i] - x[i] < y[j] - x[j];
          }
        );

        for(int i : ord){
          int lb = std::lower_bound(Y.begin(), Y.end(), y[i]) - Y.begin();

          if(auto res = seg.fold(lb, N); res){
            auto j = res->second;
            T c = std::abs(x[i] - x[j]) + std::abs(y[i] - y[j]);
            g.add_edge(i, j, c);
          }

          if(auto res = seg[lb]; not res or x[i] + y[i] < res->first){
            seg.set(lb, {{x[i] + y[i], i}});
          }
        }
      };

    for(int i = 0; i < 2; ++i){
      for(int j = 0; j < 2; ++j){
        for(int k = 0; k < 2; ++k){
          f();
          for(int l = 0; l < N; ++l) std::swap(x[l], y[l]);
        }
        for(int l = 0; l < N; ++l) x[l] = -x[l];
      }
      for(int l = 0; l < N; ++l) y[l] = -y[l];
    }

    return kruskal(g);
  }
}
