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


# :heavy_check_mark: Mylib/Graph/ShortestPath/dijkstra.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#9a0780c4ad89eac4e850657d1e57c23a">Mylib/Graph/ShortestPath</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/ShortestPath/dijkstra.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-01 05:19:32+09:00




## Depends on

* :question: <a href="../graph_template.cpp.html">Mylib/Graph/graph_template.cpp</a>


## Verified with

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
#include "Mylib/Graph/graph_template.cpp"

template <typename T>
class Dijkstra{
public:
  std::vector<std::optional<T>> dist;

private:
  void run(const Graph<T> &graph, std::vector<int> src){
    const int n = graph.size();
    dist.assign(n, std::nullopt);
    
    std::vector<bool> check(n, false);
    std::priority_queue<std::pair<T,int>, std::vector<std::pair<T,int>>, std::greater<std::pair<T,int>>> pq;

    for(auto s : src){
      dist[s] = 0;
      pq.emplace(0, s);
    }

    while(not pq.empty()){
      const auto [d,i] = pq.top(); pq.pop();

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
  }

public:
  Dijkstra(const Graph<T> &graph, int src){run(graph, {src});}
  Dijkstra(const Graph<T> &graph, const std::vector<int> &src){run(graph, src);}
};

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
#line 3 "Mylib/Graph/graph_template.cpp"
#include <iostream>

template <typename Cost = int> class Edge{
public:
  int from,to;
  Cost cost;
  Edge() {}
  Edge(int to, Cost cost): to(to), cost(cost){}
  Edge(int from, int to, Cost cost): from(from), to(to), cost(cost){}

  Edge rev() const {return Edge(to,from,cost);}
  
  friend std::ostream& operator<<(std::ostream &os, const Edge &e){
    os << "(FROM: " << e.from << "," << "TO: " << e.to << "," << "COST: " << e.cost << ")";
    return os;
  }
};

template <typename T> using Graph = std::vector<std::vector<Edge<T>>>;
template <typename T> using Tree = std::vector<std::vector<Edge<T>>>;

template <typename C, typename T> void add_edge(C &g, int from, int to, T w){
  g[from].emplace_back(from, to, w);
}

template <typename C, typename T> void add_undirected(C &g, int a, int b, T w){
  add_edge(g, a, b, w);
  add_edge(g, b, a, w);
}
#line 8 "Mylib/Graph/ShortestPath/dijkstra.cpp"

template <typename T>
class Dijkstra{
public:
  std::vector<std::optional<T>> dist;

private:
  void run(const Graph<T> &graph, std::vector<int> src){
    const int n = graph.size();
    dist.assign(n, std::nullopt);
    
    std::vector<bool> check(n, false);
    std::priority_queue<std::pair<T,int>, std::vector<std::pair<T,int>>, std::greater<std::pair<T,int>>> pq;

    for(auto s : src){
      dist[s] = 0;
      pq.emplace(0, s);
    }

    while(not pq.empty()){
      const auto [d,i] = pq.top(); pq.pop();

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
  }

public:
  Dijkstra(const Graph<T> &graph, int src){run(graph, {src});}
  Dijkstra(const Graph<T> &graph, const std::vector<int> &src){run(graph, src);}
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

