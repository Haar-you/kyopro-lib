#pragma once
#include <vector>
#include <optional>
#include <queue>
#include <utility>
#include <functional>
#include "Mylib/Graph/graph_template.cpp"

template <typename T>
class Dijkstra{
public:
  std::vector<std::optional<T>> dist;

private:
  void run(const Graph<T> &graph, std::vector<int> src){
    const int n = graph.size();
    dist.assign(n, std::nullopt);
    
    std::vector<bool> check(n, false);
    std::priority_queue<std::pair<T,int>, std::vector<std::pair<T,int>>, std::greater<std::pair<T,int>>> pq;

    for(auto s : src){
      dist[s] = 0;
      pq.emplace(0, s);
    }

    while(not pq.empty()){
      const auto [d,i] = pq.top(); pq.pop();

      if(check[i]) continue;
      check[i] = true;

      for(auto &e : graph[i]){
        if(not dist[e.to]){
          dist[e.to] = d + e.cost;
          pq.emplace(*dist[e.to], e.to);
        }else{
          if(*dist[e.to] > d + e.cost){
            dist[e.to] = d + e.cost;
            if(not check[e.to]) pq.emplace(*dist[e.to], e.to);
          }
        }
      }
    }
  }

public:
  Dijkstra(const Graph<T> &graph, int src){run(graph, {src});}
  Dijkstra(const Graph<T> &graph, const std::vector<int> &src){run(graph, src);}
};
