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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :x: Enumerate triangles

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#791a56799ce3ef8e4fb5da8cbce3a9bf">Mylib/Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/enumerate_triangles.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Depends on

* :question: <a href="Template/graph.cpp.html">Basic graph</a>


## Verified with

* :x: <a href="../../../verify/test/yosupo-judge/enumerate_triangles/main.test.cpp.html">test/yosupo-judge/enumerate_triangles/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <tuple>
#include <unordered_set>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Enumerate triangles
 * @docs enumerate_triangles.md
 */
namespace haar_lib {
  template <typename T>
  std::vector<std::tuple<int, int, int>> enumerate_triangles(const graph<T> &g){
    const int N = g.size();
    std::vector<std::tuple<int, int, int>> ret;

    std::vector<std::unordered_set<int>> adjacent(N);

    for(int i = 0; i < N; ++i){
      for(auto &e : g[i]){
        if(g[e.from].size() < g[e.to].size()){
          adjacent[e.from].insert(e.to);
        }else if(g[e.from].size() == g[e.to].size()){
          if(e.from < e.to){
            adjacent[e.from].insert(e.to);
          }
        }
      }
    }

    for(int i = 0; i < N; ++i){
      for(int j : adjacent[i]){
        for(int k : adjacent[j]){
          if(adjacent[i].find(k) != adjacent[i].end()){
            ret.emplace_back(i, j, k);
          }
        }
      }
    }

    return ret;
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/enumerate_triangles.cpp"
#include <vector>
#include <tuple>
#include <unordered_set>
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
#line 6 "Mylib/Graph/enumerate_triangles.cpp"

/**
 * @title Enumerate triangles
 * @docs enumerate_triangles.md
 */
namespace haar_lib {
  template <typename T>
  std::vector<std::tuple<int, int, int>> enumerate_triangles(const graph<T> &g){
    const int N = g.size();
    std::vector<std::tuple<int, int, int>> ret;

    std::vector<std::unordered_set<int>> adjacent(N);

    for(int i = 0; i < N; ++i){
      for(auto &e : g[i]){
        if(g[e.from].size() < g[e.to].size()){
          adjacent[e.from].insert(e.to);
        }else if(g[e.from].size() == g[e.to].size()){
          if(e.from < e.to){
            adjacent[e.from].insert(e.to);
          }
        }
      }
    }

    for(int i = 0; i < N; ++i){
      for(int j : adjacent[i]){
        for(int k : adjacent[j]){
          if(adjacent[i].find(k) != adjacent[i].end()){
            ret.emplace_back(i, j, k);
          }
        }
      }
    }

    return ret;
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

