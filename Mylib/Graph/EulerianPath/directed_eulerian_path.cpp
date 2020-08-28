#pragma once
#include <vector>
#include <map>
#include <optional>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Directed Eulerian path
 * @docs directed_eulerian_path.md
 */
class DirectedEulerianPath{
  const int n; // node count
  int edges = 0; // edge count
  std::vector<std::map<int,int>> graph;
  std::vector<int> indegree, outdegree;

  void del(int i, int j){
    if(graph[i][j] == 1) graph[i].erase(j);
    else --graph[i][j];
  }

  void dfs(int cur, std::vector<int> &path){
    if(not graph[cur].empty()){
      int next = graph[cur].begin()->fst;
      del(cur, next);
      dfs(next, path);
    }

    while(not graph[cur].empty()){
      int next = graph[cur].begin()->fst;
      del(cur, next);
      std::vector<int> temp;
      dfs(next, temp);
      path.insert(path.end(), ALL(temp));
    }

    path.push_back(cur);
  }

public:
  DirectedEulerianPath(int n): n(n), graph(n), indegree(n), outdegree(n){}

  void add(int i, int j){
    ++graph[i][j];

    ++outdegree[i];
    ++indegree[j];

    ++edges;
  }

  std::optional<std::vector<int>> build(){
    int in = 0, out = 0;
    int start = 0;
    
    for(int i = 0; i < n; ++i){
      int d = outdegree[i] - indegree[i];
      if(abs(d) > 1) return std::nullopt;
      if(d == 1){
        ++out;
        start = i;
      }else if(d == -1){
        ++in;
      }
    }
    
    if(not ((in == 0 and out == 0) or (in == 1 and out == 1))) return std::nullopt;

    std::vector<int> ret;
    
    dfs(start, ret);
    std::reverse(ret.begin(), ret.end());
    if((int)ret.size() == edges+1){
      return {ret};
    }else{
      return std::nullopt;
    }
  }
};
