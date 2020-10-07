#pragma once
#include <vector>
#include <algorithm>
#include <cassert>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Math/unbounded.cpp"

namespace haar_lib {
  template <typename T>
  auto bellman_ford(const graph<T> &g, int src){
    using type = unbounded<T>;

    const int n = g.size();
    std::vector<type> dist(n, type::positive_inf());

    dist[src] = 0;

    for(int i = 0; i < n; ++i){
      for(int s = 0; s < n; ++s){
        for(auto &e : g[s]){
          int t = e.to;
          T d = e.cost;

          if(dist[s].is_finite() and
             dist[t].is_finite() and
             dist[s].value() + d < dist[t].value() and i == n - 1){
            dist[t] = type::negative_inf();
          }else{
            if(dist[s].is_finite()){
              if(dist[t].is_positive_inf()){
                dist[t] = dist[s].value() + d;
              }else if(dist[t].is_finite()){
                dist[t] = std::min(dist[t].value(), dist[s].value() + d);
              }
            }
          }
        }
      }
    }

    for(int i = 0; i < n; ++i){
      for(int s = 0; s < n; ++s){
        for(auto &e : g[s]){
          if(dist[s].is_negative_inf()){
            dist[e.to] = type::negative_inf();
          }
        }
      }
    }

    return dist;
  }
}
