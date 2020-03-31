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


# :heavy_check_mark: Mylib/Graph/Matching/bipartite_matching.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#65eb1c5db2b1bd726d58cf661f149e7c">Mylib/Graph/Matching</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/Matching/bipartite_matching.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-01 05:19:32+09:00




## Depends on

* :heavy_check_mark: <a href="../Flow/ford_fulkerson.cpp.html">Mylib/Graph/Flow/ford_fulkerson.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/GRL_7_A/main.test.cpp.html">test/aoj/GRL_7_A/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <utility>
#include <climits>
#include <cassert>
#include "Mylib/Graph/Flow/ford_fulkerson.cpp"

class BipartiteMatching{
  int x, y;
  FordFulkerson<int, INT_MAX> f;
  int s, t;
  
public:
  BipartiteMatching(int x, int y): x(x), y(y), f(x+y+2), s(x+y), t(s+1){
    for(int i = 0; i < x; ++i) f.add_edge(s,i,1);
    for(int i = 0; i < y; ++i) f.add_edge(x+i,t,1);
  }

  void add_edge(int i, int j){
    assert(0 <= i and i < x and 0 <= j and j < y);
    f.add_edge(i,x+j,1);
  }

  int solve(){
    return f.solve(s, t);
  }

  std::vector<std::pair<int,int>> get_matching_edges(){
    auto g = f.get_graph();
    std::vector<std::pair<int,int>> ret;

    for(int i = 0; i < (int)g.size()-2; ++i){
      for(const auto &e : g[i]){
        if((not e.is_rev) and e.cap == 0 and e.to != t) ret.emplace_back(i, e.to-x);
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
#line 2 "Mylib/Graph/Matching/bipartite_matching.cpp"
#include <vector>
#include <utility>
#include <climits>
#include <cassert>
#line 3 "Mylib/Graph/Flow/ford_fulkerson.cpp"
#include <algorithm>

template <typename T, T INF> class FordFulkerson{
public:
  struct edge{
    int to, rev;
    T cap;
    bool is_rev;
  };
  
private:
  int size;

  std::vector<std::vector<edge>> graph;
  std::vector<bool> visit;
  
  T dfs(int from, int to, T flow){
    if(from == to) return flow;
    visit[from] = true;

    for(auto &e : graph[from]){
      if(!visit[e.to] and e.cap > 0){
        T d = dfs(e.to, to, std::min(flow, e.cap));
        if(d > 0){
          e.cap -= d;
          graph[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }
  
public:  
  FordFulkerson(int size): size(size), graph(size), visit(size){}

  void add_edge(int from, int to, const T &cap){
    graph[from].push_back((edge){to, (int)graph[to].size(), cap, false});
    graph[to].push_back((edge){from, (int)graph[from].size()-1, 0, true});
  }

  void reset_flow(){
    for(auto &v : graph){
      for(auto &e : v){
        if(e.is_rev){
          graph[e.to][e.rev].cap += e.cap;
          e.cap = 0;
        }
      }
    }
  }

  T solve(int s, int t){
    T ret = 0;

    while(1){
      visit.assign(size, false);
      T flow = dfs(s,t,INF);
      if(flow == 0) return ret;
      ret += flow;
    }
  }

  const std::vector<std::vector<edge>>& get_graph(){
    return graph;
  }
};
#line 7 "Mylib/Graph/Matching/bipartite_matching.cpp"

class BipartiteMatching{
  int x, y;
  FordFulkerson<int, INT_MAX> f;
  int s, t;
  
public:
  BipartiteMatching(int x, int y): x(x), y(y), f(x+y+2), s(x+y), t(s+1){
    for(int i = 0; i < x; ++i) f.add_edge(s,i,1);
    for(int i = 0; i < y; ++i) f.add_edge(x+i,t,1);
  }

  void add_edge(int i, int j){
    assert(0 <= i and i < x and 0 <= j and j < y);
    f.add_edge(i,x+j,1);
  }

  int solve(){
    return f.solve(s, t);
  }

  std::vector<std::pair<int,int>> get_matching_edges(){
    auto g = f.get_graph();
    std::vector<std::pair<int,int>> ret;

    for(int i = 0; i < (int)g.size()-2; ++i){
      for(const auto &e : g[i]){
        if((not e.is_rev) and e.cap == 0 and e.to != t) ret.emplace_back(i, e.to-x);
      }
    }

    return ret;
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

