#pragma once
#include <vector>
#include <map>
#include <optional>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Undirected Eulerian path
 * @docs undirected_eulerian_path.md
 */
class UndirectedEulerianPath {
  const int n; // node count
  int edges = 0; // edge count
  std::vector<std::map<int, int>> graph;
  std::vector<int> degree;

  void del(int i, int j){
    if(graph[i][j] == 1) graph[i].erase(j);
    else --graph[i][j];

    if(graph[j][i] == 1) graph[j].erase(i);
    else --graph[j][i];
  }

  void dfs(int cur, std::vector<int> &path){
    if(not graph[cur].empty()){
      int next = graph[cur].begin()->first;
      del(cur, next);
      dfs(next, path);
    }

    while(not graph[cur].empty()){
      int next = graph[cur].begin()->first;
      del(cur, next);
      std::vector<int> temp;
      dfs(next, temp);
      path.insert(path.end(), temp.begin(), temp.end());
    }

    path.push_back(cur);
  }

public:
  UndirectedEulerianPath(int n): n(n), graph(n), degree(n){}

  void add(int i, int j){
    ++graph[i][j];
    ++graph[j][i];

    ++degree[i];
    ++degree[j];

    ++edges;
  }

  std::optional<std::vector<int>> build(){
    std::vector<int> ret;

    int odd = 0;
    int start = 0;
    for(int i = 0; i < n; ++i){
      if(degree[i] % 2 == 1){
        ++odd;
        start = i;
      }
    }

    if(odd != 0 and odd != 2) return std::nullopt;

    dfs(start, ret);

    if((int)ret.size() == edges + 1){
      return {ret};
    }else{
      return std::nullopt;
    }
  }
};
