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


# :heavy_check_mark: Dijkstra algorithm

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#9a0780c4ad89eac4e850657d1e57c23a">Mylib/Graph/ShortestPath</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/ShortestPath/dijkstra.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-28 18:23:32+09:00




## Depends on

* :question: <a href="../Template/graph.cpp.html">Basic graph</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/0575/main.test.cpp.html">test/aoj/0575/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/GRL_1_A/main.test.cpp.html">test/aoj/GRL_1_A/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <optional>
#include <queue>
#include <utility>
#include <functional>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Dijkstra algorithm
 * @docs dijkstra.md
 */
template <typename T>
auto dijkstra(const Graph<T> &graph, std::vector<int> src){
  using P = std::pair<T, int>;
  
  const int n = graph.size();
  std::vector<std::optional<T>> dist(n);
  
  std::vector<bool> check(n, false);
  std::priority_queue<P, std::vector<P>, std::greater<P>> pq;

  for(auto s : src){
    dist[s] = 0;
    pq.emplace(0, s);
  }

  while(not pq.empty()){
    const auto [d, i] = pq.top(); pq.pop();

    if(check[i]) continue;
    check[i] = true;

    for(auto &e : graph[i]){
      if(not dist[e.to]){
        dist[e.to] = d + e.cost;
        pq.emplace(*dist[e.to], e.to);
      }else{
        if(*dist[e.to] > d + e.cost){
          dist[e.to] = d + e.cost;
          if(not check[e.to]) pq.emplace(*dist[e.to], e.to);
        }
      }
    }
  }

  return dist;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/ShortestPath/dijkstra.cpp"
#include <vector>
#include <optional>
#include <queue>
#include <utility>
#include <functional>
#line 3 "Mylib/Graph/Template/graph.cpp"

/**
 * @title Basic graph
 * @docs graph.md
 */
template <typename T>
struct Edge{
  int from, to;
  T cost;
  int index = -1;
  Edge(){}
  Edge(int from, int to, T cost): from(from), to(to), cost(cost){}
  Edge(int from, int to, T cost, int index): from(from), to(to), cost(cost), index(index){}
};

template <typename T>
struct Graph{
  using weight_type = T;
  using edge_type = Edge<T>;
  
  std::vector<std::vector<Edge<T>>> data;

  auto& operator[](size_t i){return data[i];}
  const auto& operator[](size_t i) const {return data[i];}
  
  auto begin() const {return data.begin();}
  auto end() const {return data.end();}

  Graph(){}
  Graph(int N): data(N){}

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
using Tree = Graph<T>;
#line 8 "Mylib/Graph/ShortestPath/dijkstra.cpp"

/**
 * @title Dijkstra algorithm
 * @docs dijkstra.md
 */
template <typename T>
auto dijkstra(const Graph<T> &graph, std::vector<int> src){
  using P = std::pair<T, int>;
  
  const int n = graph.size();
  std::vector<std::optional<T>> dist(n);
  
  std::vector<bool> check(n, false);
  std::priority_queue<P, std::vector<P>, std::greater<P>> pq;

  for(auto s : src){
    dist[s] = 0;
    pq.emplace(0, s);
  }

  while(not pq.empty()){
    const auto [d, i] = pq.top(); pq.pop();

    if(check[i]) continue;
    check[i] = true;

    for(auto &e : graph[i]){
      if(not dist[e.to]){
        dist[e.to] = d + e.cost;
        pq.emplace(*dist[e.to], e.to);
      }else{
        if(*dist[e.to] > d + e.cost){
          dist[e.to] = d + e.cost;
          if(not check[e.to]) pq.emplace(*dist[e.to], e.to);
        }
      }
    }
  }

  return dist;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

