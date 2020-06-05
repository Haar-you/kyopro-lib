#pragma once

#include <vector>
#include <utility>
#include <optional>
#include <queue>
#include <functional>

#include "Mylib/Graph/graph_template.cpp"

/**
 * @title Yen's algorithm
 * @docs yen_algorithm.md
 */
template <typename T>
auto yen_algorithm(Graph<T> g, int s, int t, int K){
  using Path = std::pair<T, std::vector<int>>;
  using P = std::pair<T, int>;

  const int N = g.size();

  std::vector<std::vector<bool>> valid(N);
  std::vector<std::optional<Path>> result(K);
  std::priority_queue<Path, std::vector<Path>, std::greater<Path>> stock;

  for(int i = 0; i < N; ++i){
    valid[i].assign(g[i].size(), true);
  }
  
  auto shortest_path =
    [&](int from, const std::vector<bool> &usable){
      std::vector<bool> visited(N, false);
      std::vector<std::optional<T>> dist(N);
      std::vector<std::pair<int, int>> restore(N);

      std::priority_queue<P, std::vector<P>, std::greater<P>> pq;

      dist[from] = 0;
      pq.emplace(0, from);

      while(not pq.empty()){
        auto [d, i] = pq.top(); pq.pop();

        if(visited[i]) continue;
        visited[i] = true;

        for(int k = 0; k < (int)g[i].size(); ++k){
          if(not valid[i][k] or not usable[g[i][k].to]) continue;
          auto &e = g[i][k];

          if(not dist[e.to] or *dist[e.to] > d + e.cost){
            dist[e.to] = d + e.cost;
            restore[e.to] = std::make_pair(i, k);
            if(not visited[e.to]) pq.emplace(*dist[e.to], e.to);
          }
        }
      }

      std::optional<Path> ret;
    
      if(dist[t]){
        std::vector<int> p;

        int cur = t;
        while(cur != from){
          auto [i, j] = restore[cur];
          p.push_back(j);
          cur = i;
        }
      
        std::reverse(p.begin(), p.end());

        ret = std::make_pair(*dist[t], p);
      }

      return ret;
    };

  for(int i = 0; i < K; ++i){
    if(i == 0){
      std::vector<bool> usable(N, true);
      if(auto res = shortest_path(s, usable); res) stock.push(*res);
    }else{
      std::vector<int> prev_path;

      {
        int cur = s;
        for(auto u : result[i-1]->second){
          prev_path.push_back(cur);
          cur = g[cur][u].to;
        }
        prev_path.push_back(t);
      }

      std::vector<bool> check(i, true);
      std::vector<bool> usable(N, true);

      for(int k = 0; k < (int)prev_path.size() - 1; ++k){
        const int u = prev_path[k];
        
        for(int j = 0; j < i; ++j){
          if(check[j]){
            valid[prev_path[k]][result[j]->second[k]] = false;
          }
        }

        if(auto res = shortest_path(u, usable); res){

          auto [c, p] = *res;

          std::vector<int> temp;
          for(int j = 0; j < k; ++j){
            int v = result[i-1]->second[j];

            c += g[prev_path[j]][v].cost;
            temp.push_back(v);
          }

          temp.insert(temp.end(), p.begin(), p.end());
          stock.emplace(c, temp);
        }

        usable[u] = false;

        for(int j = 0; j < i; ++j){
          if(check[j]){
            valid[prev_path[k]][result[j]->second[k]] = true;
          }
        }

        for(int j = 0; j < i; ++j){
          if(check[j]){
            if(prev_path[k+1] != g[prev_path[k]][result[j]->second[k]].to){
              check[j] = false;
            }
          }
        }
      }
    }

    if(stock.empty()) break;

    result[i] = stock.top(); stock.pop();

    while(not stock.empty() and stock.top() == result[i]){
      stock.pop();
    }
  }

  return result;
}
