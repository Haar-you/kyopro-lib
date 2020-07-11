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
    - Last commit date: 2020-06-17 19:17:20+09:00




## Depends on

* :question: <a href="graph_template.cpp.html">Graph template</a>


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
#include "Mylib/Graph/graph_template.cpp"

/**
 * @title Enumerate triangles
 * @docs enumerate_triangles.md
 */
template <typename T>
std::vector<std::tuple<int,int,int>> enumerate_triangles(Graph<T> g){
  const int N = g.size();
  std::vector<std::tuple<int,int,int>> ret;

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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/enumerate_triangles.cpp"
#include <vector>
#include <tuple>
#include <unordered_set>
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
#line 6 "Mylib/Graph/enumerate_triangles.cpp"

/**
 * @title Enumerate triangles
 * @docs enumerate_triangles.md
 */
template <typename T>
std::vector<std::tuple<int,int,int>> enumerate_triangles(Graph<T> g){
  const int N = g.size();
  std::vector<std::tuple<int,int,int>> ret;

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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

