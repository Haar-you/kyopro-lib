#pragma once
#include <vector>
#include <queue>
#include "Mylib/Graph/graph_template.cpp"

/**
 * @title Prim algorithm
 * @docs prim.md
 */
template <typename T>
std::vector<Edge<T>> prim(const Graph<T> &graph){
  int n = graph.size();
  std::vector<bool> visit(n, false);
  std::vector<Edge<T>> ret;

  auto cmp = [](const auto &a, const auto &b){return a.cost > b.cost;};
  std::priority_queue<Edge<T>, std::vector<Edge<T>>, decltype(cmp)> pq(cmp);
  
  visit[0] = true;
  for(auto &e : graph[0]) pq.push(e);

  while(not pq.empty()){
    auto t = pq.top(); pq.pop();

    if(visit[t.from] == visit[t.to]) continue;

    int i = visit[t.from] ? t.to : t.from;
    for(auto &e : graph[i]){
      pq.push(e);
    }

    visit[i] = true;
    ret.push_back(t);
  }

  return ret;
}
