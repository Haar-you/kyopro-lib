#pragma once
#include <vector>
#include <queue>
#include <optional>
#include "Mylib/Graph/graph_template.cpp"

/**
 * @title Undirected shortest cycle
 * @docs undirected_shortest_cycle.md
 */
template <typename T>
std::optional<int> shortest_cycle(const Graph<T> &g, const int src){
  for(auto &e : g[src]){
    if(e.to == src) return 1; // self loop
  }
  
  if(g[src].size() <= 1) return {};
  
  const int N = g.size();
  std::vector<int> visit(N);
  std::vector<int> dist(N);

  visit[src] = -1;
  
  std::queue<int> q;
  for(int i = 0; i < (int)g[src].size(); ++i){
    int j = g[src][i].to;
    if(visit[j]) return 2; // multiple edges
    q.push(j);
    visit[j] = i + 1;
    dist[j] = 1;
  }

  while(not q.empty()){
    int i = q.front(); q.pop();

    for(auto &e : g[i]){
      if(not visit[e.to]){
        visit[e.to] = visit[i];
        dist[e.to] = dist[i] + 1;
        q.push(e.to);
      }else{
        if(e.to != src and visit[e.from] != visit[e.to]){
          return dist[e.from] + dist[e.to] + 1;
        }
      }
    }
  }

  return {};
}
