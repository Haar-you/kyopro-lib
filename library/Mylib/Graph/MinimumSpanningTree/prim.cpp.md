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


# :question: Prim algorithm

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#cb5ed95d97b7ee8efcbdf177a47dc7b7">Mylib/Graph/MinimumSpanningTree</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/MinimumSpanningTree/prim.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Depends on

* :question: <a href="../Template/graph.cpp.html">Basic graph</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/2559/main.binomial_heap.test.cpp.html">test/aoj/2559/main.binomial_heap.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/2559/main.leftist_heap.test.cpp.html">test/aoj/2559/main.leftist_heap.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/2559/main.skew_heap.test.cpp.html">test/aoj/2559/main.skew_heap.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/GRL_2_A/main.prim.test.cpp.html">test/aoj/GRL_2_A/main.prim.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <queue>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Prim algorithm
 * @docs prim.md
 */
namespace haar_lib {
  template <typename T>
  std::vector<edge<T>> prim(const graph<T> &graph){
    const int n = graph.size();
    std::vector<bool> visit(n, false);
    std::vector<edge<T>> ret;

    auto cmp = [](const auto &a, const auto &b){return a.cost > b.cost;};
    std::priority_queue<edge<T>, std::vector<edge<T>>, decltype(cmp)> pq(cmp);

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
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/MinimumSpanningTree/prim.cpp"
#include <vector>
#include <queue>
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
#line 5 "Mylib/Graph/MinimumSpanningTree/prim.cpp"

/**
 * @title Prim algorithm
 * @docs prim.md
 */
namespace haar_lib {
  template <typename T>
  std::vector<edge<T>> prim(const graph<T> &graph){
    const int n = graph.size();
    std::vector<bool> visit(n, false);
    std::vector<edge<T>> ret;

    auto cmp = [](const auto &a, const auto &b){return a.cost > b.cost;};
    std::priority_queue<edge<T>, std::vector<edge<T>>, decltype(cmp)> pq(cmp);

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
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

