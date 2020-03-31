#pragma once
#include <vector>
#include <utility>
#include <deque>
#include <algorithm>

template <typename T, T INF> class Dinic{
private:
  std::vector<std::vector<std::pair<int,T>>> graph;
  int size, s, t;
  std::vector<std::vector<T>> cap;
  std::vector<int> level;
  
  bool buildLevel(){
    std::fill(level.begin(), level.end(), 0);
    level[s] = 1;
    std::deque<int> deq = {s};
    while(not deq.empty()){
      int cur = deq.front(); deq.pop_front();
      for(int i = 0; i < size; ++i)
        if(level[i] == 0 and cap[cur][i] > 0){
          level[i] = level[cur] + 1;
          deq.push_back(i);
        }
    }
    return level[t] != 0;
  }
  void dfs(std::vector<int> &path, T &flow){
    if(path.empty()) return;
    int cur = path.back();
    if(cur == t){
      T f = INF;
      for(int i = 1; i < (int)path.size(); ++i) f = std::min(f, cap[path[i-1]][path[i]]);
      for(int i = 1; i < (int)path.size(); ++i){
        cap[path[i-1]][path[i]] -= f;
        cap[path[i]][path[i-1]] += f;
      }
      flow += f;
    }else{
      for(int i = 0; i < size; ++i){
        if(cap[cur][i] > 0 and level[i] > level[cur]){
          path.push_back(i);
          dfs(path, flow);
          path.pop_back();
        }
      }
    }
  }
  
  T augment(){
    T f = 0;
    std::vector<int> path = {s};
    dfs(path, f);
    return f;
  }
  
  T loop(){
    T f = 0;
    while(buildLevel()) f += augment();
    return f;
  }
 
public:
  Dinic(std::vector<std::vector<std::pair<int,T>>> &_graph): graph(_graph), size(graph.size()) {}
  Dinic(int size): graph(size), size(size){}
  Dinic(){}
 
  void add_edge(int from, int to, const T &cap){
    graph[from].push_back({to, cap});
  }
  
  T solve(int _s, int _t){
    cap = std::vector<std::vector<T>>(size, std::vector<T>(size, 0));
    level = std::vector<int>(size, 0);
 
    for(int i = 0; i < size; ++i)
      for(auto &p : graph[i]){
        int j = p.first;
        T d = p.second;
        cap[i][j] += d;
      }
 
    s = _s;
    t = _t;
 
    return loop();
  }
};
