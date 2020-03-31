#pragma once
#include <vector>
#include <algorithm>
#include "Mylib/Graph/graph_template.cpp"

template <typename T>
struct SCC{
  std::vector<int> result;
  int scc_size;
  
private:
  std::vector<bool> visit;
  std::vector<int> check;
  
  void dfs(int cur, const Graph<T> &graph){
    visit[cur] = true;
    for(auto &e : graph[cur]){
      if(not visit[e.to]) dfs(e.to,graph);
    }
    check.push_back(cur);
  }

  void rdfs(int cur, int i, const Graph<T> &rgraph){
    result[cur] = i;
    for(auto &e : rgraph[cur]){
      if(result[e.to] == -1) rdfs(e.to,i,rgraph);
    }
  }

public:
  SCC(const Graph<T> &graph){
    const int n = graph.size();
    result.assign(n, -1);
    visit.assign(n, false);
    
    for(int i = 0; i < n; ++i) if(!visit[i]) dfs(i,graph);
    std::reverse(check.begin(), check.end());
    
    Graph<T> rgraph(n);
    for(int i = 0; i < n; ++i) for(auto &e : graph[i]) rgraph[e.to].push_back(e.rev());

    int i = 0;
    for(auto c : check) if(result[c] == -1) {rdfs(c,i,rgraph); ++i;}
    scc_size = i;
  }

  inline const int operator[](int i) const {return result[i];}
};
