#pragma once
#include <vector>
#include <optional>
#include <queue>
#include <algorithm>
#include <climits>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Directed shortest cycle
 * @docs directed_shortest_cycle.md
 */
namespace haar_lib {
  template <typename T>
  struct direct_shortest_cycle {
    const int N;
    std::optional<std::vector<int>> cycle;

    void bfs(int i, const graph<T> &g, int &min_len){
      std::queue<int> q;
      q.push(i);

      std::vector<int> dist(N), pre(N);
      std::vector<bool> visited(N);

      while(not q.empty()){
        int cur = q.front(); q.pop();

        if(visited[cur]) continue;
        visited[cur] = true;

        for(auto &e : g[cur]){
          if(e.to == i){
            if(dist[cur] < min_len){
              min_len = dist[cur];
              cycle = std::vector<int>();

              int j = cur;
              while(1){
                (*cycle).push_back(j);
                if(j == i) break;

                j = pre[j];
              }

              std::reverse((*cycle).begin(), (*cycle).end());
            }

            return;
          }

          if(not visited[e.to]){
            dist[e.to] = dist[cur] + 1;
            pre[e.to] = cur;
            q.push(e.to);
          }
        }
      }
    }

    direct_shortest_cycle(const graph<T> &g): N(g.size()){
      int min_len = INT_MAX;

      for(int i = 0; i < N; ++i){
        bfs(i, g, min_len);
      }
    }
  };
}