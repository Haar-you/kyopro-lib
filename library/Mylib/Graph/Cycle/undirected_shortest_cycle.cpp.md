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


# :warning: Undirected shortest cycle

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a962efc2861dbe1e0963e7d8bf7dda18">Mylib/Graph/Cycle</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/Cycle/undirected_shortest_cycle.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Operations

- `shortest_cycle(g, src)`
	- `src`始点の最小閉路を検出する。
	- Time complexity $O(E)$

## Requirements

## Notes

## Problems

- [Codeforces Round #628 (Div. 2) E. Ehab's REAL Number Theory Problem](https://codeforces.com/contest/1325/problem/E)

## References


## Depends on

* :question: <a href="../Template/graph.cpp.html">Basic graph</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <queue>
#include <optional>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Undirected shortest cycle
 * @docs undirected_shortest_cycle.md
 */
namespace haar_lib {
  template <typename T>
  std::optional<int> shortest_cycle(const graph<T> &g, const int src){
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
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/Cycle/undirected_shortest_cycle.cpp"
#include <vector>
#include <queue>
#include <optional>
#line 3 "Mylib/Graph/Template/graph.cpp"
#include <iostream>

/**
 * @title Basic graph
 * @docs graph.md
 */
namespace haar_lib {
  template <typename T>
  struct edge {
    int from, to;
    T cost;
    int index = -1;
    edge(){}
    edge(int from, int to, T cost): from(from), to(to), cost(cost){}
    edge(int from, int to, T cost, int index): from(from), to(to), cost(cost), index(index){}
  };

  template <typename T>
  struct graph {
    using weight_type = T;
    using edge_type = edge<T>;

    std::vector<std::vector<edge<T>>> data;

    auto& operator[](size_t i){return data[i];}
    const auto& operator[](size_t i) const {return data[i];}

    auto begin() const {return data.begin();}
    auto end() const {return data.end();}

    graph(){}
    graph(int N): data(N){}

    bool empty() const {return data.empty();}
    int size() const {return data.size();}

    void add_edge(int i, int j, T w, int index = -1){
      data[i].emplace_back(i, j, w, index);
    }

    void add_undirected(int i, int j, T w, int index = -1){
      add_edge(i, j, w, index);
      add_edge(j, i, w, index);
    }

    template <size_t I, bool DIRECTED = true, bool WEIGHTED = true>
    void read(int M){
      for(int i = 0; i < M; ++i){
        int u, v; std::cin >> u >> v;
        u -= I;
        v -= I;
        T w = 1;
        if(WEIGHTED) std::cin >> w;
        if(DIRECTED) add_edge(u, v, w, i);
        else add_undirected(u, v, w, i);
      }
    }
  };

  template <typename T>
  using tree = graph<T>;
}
#line 6 "Mylib/Graph/Cycle/undirected_shortest_cycle.cpp"

/**
 * @title Undirected shortest cycle
 * @docs undirected_shortest_cycle.md
 */
namespace haar_lib {
  template <typename T>
  std::optional<int> shortest_cycle(const graph<T> &g, const int src){
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
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
