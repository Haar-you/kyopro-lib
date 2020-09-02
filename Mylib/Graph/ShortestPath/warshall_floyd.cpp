#pragma once
#include <vector>
#include <optional>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Warshall-Floyd algorithm
 * @docs warshall_floyd.md
 */
template <typename T>
struct WarshallFloyd {
  const int n;
  std::vector<std::vector<std::optional<T>>> dist;
  bool has_negative_cycle;

  WarshallFloyd(const Graph<T> &graph):
    n(graph.size()),
    dist(n, std::vector<std::optional<T>>(n)),
    has_negative_cycle(false)
  {
    for(int i = 0; i < n; ++i) dist[i][i] = 0;

    for(int i = 0; i < n; ++i){
      for(auto &e : graph[i]){
        dist[e.from][e.to] = e.cost;
      }
    }

    for(int k = 0; k < n; ++k){
      for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
          if(dist[i][k] and dist[k][j]){
            if(not dist[i][j]){
              dist[i][j] = *dist[i][k] + *dist[k][j];
            }else{
              dist[i][j] = std::min(*dist[i][j], *dist[i][k] + *dist[k][j]);
            }
          }
        }
      }
    }

    for(int i = 0; i < n; ++i) if(*dist[i][i] < 0) has_negative_cycle = true;
  }
};
