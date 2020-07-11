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

* category: <a href="../../../../index.html#ac2a729ce4878019d16697115af3ef73">Mylib/Graph/ShortestCycle</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/ShortestCycle/undirected_shortest_cycle.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




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

* :question: <a href="../graph_template.cpp.html">Graph template</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <queue>
#include <optional>
#include "Mylib/Graph/graph_template.cpp"

/**
 * @title Undirected shortest cycle
 * @docs undirected_shortest_cycle.md
 */
template <typename T>
std::optional<int> shortest_cycle(const Graph<T> &g, const int src){
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/ShortestCycle/undirected_shortest_cycle.cpp"
#include <vector>
#include <queue>
#include <optional>
#line 3 "Mylib/Graph/graph_template.cpp"
#include <iostream>

/**
 * @title Graph template
 * @docs graph_template.md
 */
template <typename Cost = int> class Edge{
public:
  int from,to;
  Cost cost;
  Edge() {}
  Edge(int to, Cost cost): to(to), cost(cost){}
  Edge(int from, int to, Cost cost): from(from), to(to), cost(cost){}
};

template <typename T> using Graph = std::vector<std::vector<Edge<T>>>;
template <typename T> using Tree = std::vector<std::vector<Edge<T>>>;

template <typename T, typename C> void add_edge(C &g, int from, int to, T w = 1){
  g[from].emplace_back(from, to, w);
}

template <typename T, typename C> void add_undirected(C &g, int a, int b, T w = 1){
  add_edge<T, C>(g, a, b, w);
  add_edge<T, C>(g, b, a, w);
}
#line 6 "Mylib/Graph/ShortestCycle/undirected_shortest_cycle.cpp"

/**
 * @title Undirected shortest cycle
 * @docs undirected_shortest_cycle.md
 */
template <typename T>
std::optional<int> shortest_cycle(const Graph<T> &g, const int src){
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

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

