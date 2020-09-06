#pragma once
#include <vector>
#include <queue>
#include <utility>
#include <cassert>

/**
 * @title Hopcroft-Karp algorithm
 * @docs hopcroft_karp.md
 */
class HopcroftKarp {
  struct edge {
    int from, to;
    int rev;
    bool used;
  };

  int L, R, N;
  std::vector<std::vector<edge>> graph;
  std::vector<int> dist;

  bool bfs(){
    dist.assign(N, -1);
    std::queue<int> q;

    q.push(0);
    dist[0] = 0;

    while(not q.empty()){
      int i = q.front(); q.pop();

      for(auto &e : graph[i]){
        if(not e.used and dist[e.to] == -1){
          dist[e.to] = dist[i] + 1;
          q.push(e.to);
        }
      }
    }

    return dist[N - 1] != -1;
  }

  bool dfs(int cur){
    if(cur == N - 1) return true;

    for(auto &e : graph[cur]){
      if(not e.used and dist[cur] + 1 == dist[e.to]){
        if(dfs(e.to)){
          e.used = true;
          if(e.rev >= 0) graph[e.to][e.rev].used = false;
          return true;
        }
      }
    }

    return false;
  }

public:
  HopcroftKarp(int L, int R): L(L), R(R), N(L + R + 2), graph(N), dist(N){
    for(int i = 0; i < L; ++i){
      graph[0].push_back((edge){0, i + 1, -1, false});
    }

    for(int i = 0; i < R; ++i){
      graph[i + L + 1].push_back((edge){i + L + 1, N - 1, -1, false});
    }
  }

  void add_edge(int i, int j){
    assert(0 <= i and i < L);
    assert(0 <= j and j < R);

    const int x = i + 1;
    const int y = j + L + 1;

    graph[x].push_back((edge){x, y, (int)graph[y].size(), false});
    graph[y].push_back((edge){y, x, (int)graph[x].size() - 1, true});
  }

  int solve(){
    int ret = 0;

    while(bfs()){
      int flow = 0;
      for(int i = 0; i < L; ++i){
        auto &e = graph[0][i];
        if(not e.used and dfs(e.to)){
          e.used = true;
          ++flow;
        }
      }
      if(flow == 0) break;
      ret += flow;
    }

    return ret;
  }

  auto get_matching(){
    std::vector<std::pair<int, int>> ret;
    for(int i = 0; i < L; ++i){
      for(auto &e : graph[i + 1]){
        if(e.used) ret.emplace_back(i, e.to - L - 1);
      }
    }
    return ret;
  }
};
