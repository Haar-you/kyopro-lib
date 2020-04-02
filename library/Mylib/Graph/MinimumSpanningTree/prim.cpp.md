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


# :heavy_check_mark: Mylib/Graph/MinimumSpanningTree/prim.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#cb5ed95d97b7ee8efcbdf177a47dc7b7">Mylib/Graph/MinimumSpanningTree</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/MinimumSpanningTree/prim.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-01 05:19:32+09:00




## Depends on

* :heavy_check_mark: <a href="../graph_template.cpp.html">Mylib/Graph/graph_template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/GRL_2_A/main.prim.test.cpp.html">test/aoj/GRL_2_A/main.prim.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <queue>
#include "Mylib/Graph/graph_template.cpp"

template <typename T>
std::vector<Edge<T>> prim(const Graph<T> &graph){
  int n = graph.size();
  std::vector<bool> visit(n, false);
  std::vector<Edge<T>> ret;

  auto cmp = [](const auto &a, const auto &b){return a.cost > b.cost;};
  std::priority_queue<Edge<T>, std::vector<Edge<T>>, decltype(cmp)> pq(cmp);
  
  visit[0] = true;
  for(auto &e : graph[0]) pq.push(e);

  while(not pq.empty()){
    auto t = pq.top(); pq.pop();

    if(visit[t.from] == visit[t.to]) continue;

    int i = visit[t.from] ? t.to : t.from;
    for(auto &e : graph[i]){
      pq.push(e);
    }

    visit[i] = true;
    ret.push_back(t);
  }

  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/MinimumSpanningTree/prim.cpp"
#include <vector>
#include <queue>
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
#line 5 "Mylib/Graph/MinimumSpanningTree/prim.cpp"

template <typename T>
std::vector<Edge<T>> prim(const Graph<T> &graph){
  int n = graph.size();
  std::vector<bool> visit(n, false);
  std::vector<Edge<T>> ret;

  auto cmp = [](const auto &a, const auto &b){return a.cost > b.cost;};
  std::priority_queue<Edge<T>, std::vector<Edge<T>>, decltype(cmp)> pq(cmp);
  
  visit[0] = true;
  for(auto &e : graph[0]) pq.push(e);

  while(not pq.empty()){
    auto t = pq.top(); pq.pop();

    if(visit[t.from] == visit[t.to]) continue;

    int i = visit[t.from] ? t.to : t.from;
    for(auto &e : graph[i]){
      pq.push(e);
    }

    visit[i] = true;
    ret.push_back(t);
  }

  return ret;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

