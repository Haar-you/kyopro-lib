#pragma once
#include <vector>
#include <optional>

/**
 * @title Warshall-Floyd algorithm (For adjacency matrix graph)
 * @docs warshall_floyd_for_matrix_graph.md
 */
namespace haar_lib {
  namespace warshall_floyd_for_matrix_impl {
    template <typename T>
    struct Result {
      std::vector<std::vector<std::optional<T>>> dist;
      bool has_negative_cycle;
      const auto& operator[](int i) const {return dist[i];}
    };
  }

  template <typename T, T INVALID>
  auto warshall_floyd_for_matrix(const std::vector<std::vector<T>> &g){
    const int n = g.size();
    auto dist = std::vector(n, std::vector<std::optional<T>>(n));

    for(int i = 0; i < n; ++i) dist[i][i] = 0;

    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
        if(g[i][j] != INVALID){
          dist[i][j] = g[i][j];
        }
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

    bool has_negative_cycle = false;
    for(int i = 0; i < n; ++i) if(*dist[i][i] < 0) has_negative_cycle = true;

    return warshall_floyd_for_matrix_impl::Result<T>{dist, has_negative_cycle};
  }
}
