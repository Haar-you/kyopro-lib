---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../assets/css/copy-button.css" />


# :heavy_check_mark: Hopcroft-Karp法

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#65eb1c5db2b1bd726d58cf661f149e7c">Mylib/Graph/Matching</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/Matching/hopcroft_karp.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




## Operations

- `HopcroftKarp(L, R)`
- `add_edge(i, j)`
- `solve()`
	- Time complexity $O(E \sqrt V)$
- `get_matching()`

## Requirements

## Notes

## Problems

## References


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/GRL_7_A/main.hopcroft_karp.test.cpp.html">test/aoj/GRL_7_A/main.hopcroft_karp.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/yosupo-judge/bipartitematching/main.test.cpp.html">test/yosupo-judge/bipartitematching/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <queue>
#include <utility>
#include <cassert>

/**
 * @title Hopcroft-Karp法
 * @docs hopcroft_karp.md
 */
class HopcroftKarp{
  struct edge{
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

    return dist[N-1] != -1;
  }

  bool dfs(int cur){
    if(cur == N-1) return true;

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
  HopcroftKarp(int L, int R): L(L), R(R), N(L+R+2), graph(N), dist(N){
    for(int i = 0; i < L; ++i){
      graph[0].push_back((edge){0, i+1, -1, false});
    }

    for(int i = 0; i < R; ++i){
      graph[i+L+1].push_back((edge){i+L+1, N-1, -1, false});
    }
  }

  void add_edge(int i, int j){
    assert(0 <= i and i < L);
    assert(0 <= j and j < R);

    int x = i+1;
    int y = j+L+1;

    graph[x].push_back((edge){x, y, (int)graph[y].size(), false});
    graph[y].push_back((edge){y, x, (int)graph[x].size()-1, true});
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
  
  std::vector<std::pair<int,int>> get_matching(){
    std::vector<std::pair<int,int>> ret;
    for(int i = 0; i < L; ++i){
      for(auto &e : graph[i+1]){
        if(e.used) ret.emplace_back(i, e.to-L-1);
      }
    }
    return ret;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/Matching/hopcroft_karp.cpp"
#include <vector>
#include <queue>
#include <utility>
#include <cassert>

/**
 * @title Hopcroft-Karp法
 * @docs hopcroft_karp.md
 */
class HopcroftKarp{
  struct edge{
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

    return dist[N-1] != -1;
  }

  bool dfs(int cur){
    if(cur == N-1) return true;

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
  HopcroftKarp(int L, int R): L(L), R(R), N(L+R+2), graph(N), dist(N){
    for(int i = 0; i < L; ++i){
      graph[0].push_back((edge){0, i+1, -1, false});
    }

    for(int i = 0; i < R; ++i){
      graph[i+L+1].push_back((edge){i+L+1, N-1, -1, false});
    }
  }

  void add_edge(int i, int j){
    assert(0 <= i and i < L);
    assert(0 <= j and j < R);

    int x = i+1;
    int y = j+L+1;

    graph[x].push_back((edge){x, y, (int)graph[y].size(), false});
    graph[y].push_back((edge){y, x, (int)graph[x].size()-1, true});
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
  
  std::vector<std::pair<int,int>> get_matching(){
    std::vector<std::pair<int,int>> ret;
    for(int i = 0; i < L; ++i){
      for(auto &e : graph[i+1]){
        if(e.used) ret.emplace_back(i, e.to-L-1);
      }
    }
    return ret;
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

