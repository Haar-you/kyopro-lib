#pragma once
#include <vector>
#include <queue>
#include "Mylib/Graph/graph_template.cpp"

/**
 * @title Pseudotreeの分解
 * @see https://en.wikipedia.org/wiki/Pseudoforest
 * @brief 閉路を丁度1つだけもつ無向グラフを閉路と森に分解する。
 */
template <typename T>
struct PseudoTree{
  const int n;
  std::vector<bool> in_loop;
  std::vector<int> group;

  void dfs(int cur, int par, const Graph<T> &g){
    group[cur] = group[par];

    for(auto &e : g[cur]){
      if(e.to == par) continue;
      dfs(e.to, cur, g);
    }
  }
  
  PseudoTree(const Graph<T> &g): n(g.size()), in_loop(n, true), group(n){
    std::vector<int> indeg(n);
    std::vector<bool> visited(n);
    std::queue<int> q;

    for(int i = 0; i < n; ++i){
      for(auto &e : g[i]){
        ++indeg[e.to];
      }
    }

    for(int i = 0; i < n; ++i){
      if(indeg[i] == 1){
        q.push(i);
      }
    }

    while(not q.empty()){
      int cur = q.front(); q.pop();

      in_loop[cur] = false;

      if(visited[cur]) continue;
      visited[cur] = true;
      
      for(auto &e : g[cur]){
        if(not visited[e.to]){
          --indeg[e.to];
          if(indeg[e.to] == 1){
            q.push(e.to);
          }
        }
      }
    }

    for(int i = 0; i < n; ++i){
      if(in_loop[i]){
        for(auto &e : g[i]){
          if(not in_loop[e.to]){
            group[i] = i;
            dfs(e.to, i, g);
            break;
          }
        }
      }
    }
  }
};
