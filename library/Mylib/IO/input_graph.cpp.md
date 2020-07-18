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


# :question: Mylib/IO/input_graph.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#7f8c074a28e3c2f263a02491ce2132dd">Mylib/IO</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/IO/input_graph.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Depends on

* :question: <a href="../Graph/graph_template.cpp.html">Graph template</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/0575/main.test.cpp.html">test/aoj/0575/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/1595/main.test.cpp.html">test/aoj/1595/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2370/main.test.cpp.html">test/aoj/2370/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2559/main.binomial_heap.test.cpp.html">test/aoj/2559/main.binomial_heap.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2559/main.leftist_heap.test.cpp.html">test/aoj/2559/main.leftist_heap.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2559/main.skew_heap.test.cpp.html">test/aoj/2559/main.skew_heap.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2667/main.test.cpp.html">test/aoj/2667/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2891/main.test.cpp.html">test/aoj/2891/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DPL_2_A/main.test.cpp.html">test/aoj/DPL_2_A/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DPL_2_B/main.test.cpp.html">test/aoj/DPL_2_B/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_1_A/main.test.cpp.html">test/aoj/GRL_1_A/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_1_B/main.test.cpp.html">test/aoj/GRL_1_B/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_1_C/main.test.cpp.html">test/aoj/GRL_1_C/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_2_A/main.kruskal.test.cpp.html">test/aoj/GRL_2_A/main.kruskal.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_2_A/main.prim.test.cpp.html">test/aoj/GRL_2_A/main.prim.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_2_B/main.test.cpp.html">test/aoj/GRL_2_B/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_3_A/main.test.cpp.html">test/aoj/GRL_3_A/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_3_B/main.test.cpp.html">test/aoj/GRL_3_B/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_3_C/main.test.cpp.html">test/aoj/GRL_3_C/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_5_A/main.test.cpp.html">test/aoj/GRL_5_A/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_5_B/main.test.cpp.html">test/aoj/GRL_5_B/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/cycle_detection/main.test.cpp.html">test/yosupo-judge/cycle_detection/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/enumerate_triangles/main.test.cpp.html">test/yosupo-judge/enumerate_triangles/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/scc/main.test.cpp.html">test/yosupo-judge/scc/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/tree_diameter/main.test.cpp.html">test/yosupo-judge/tree_diameter/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/two_edge_connected_components/main.test.cpp.html">test/yosupo-judge/two_edge_connected_components/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/vertex_add_path_sum/main.test.cpp.html">test/yosupo-judge/vertex_add_path_sum/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/vertex_set_path_composite/main.test.cpp.html">test/yosupo-judge/vertex_set_path_composite/main.test.cpp</a>
* :x: <a href="../../../verify/test/yukicoder/1030/main.test.cpp.html">test/yukicoder/1030/main.test.cpp</a>
* :x: <a href="../../../verify/test/yukicoder/899/main.test.cpp.html">test/yukicoder/899/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yukicoder/922/main.test.cpp.html">test/yukicoder/922/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <iostream>
#include "Mylib/Graph/graph_template.cpp"

/**
 * @docs input_graph.md
 */
template <typename T, size_t I, bool WEIGHTED>
std::vector<Edge<T>> input_edges(int M){
  std::vector<Edge<T>> ret;
  
  for(int i = 0; i < M; ++i){
    int s, t; std::cin >> s >> t;
    s -= I;
    t -= I;
    T w = 1; if(WEIGHTED) std::cin >> w;
    ret.emplace_back(s, t, w);
  }
  
  return ret;  
}

template <typename T, bool DIRECTED>
Graph<T> convert_to_graph(int N, const std::vector<Edge<T>> &edges){
  Graph<T> g(N);

  for(const auto &e : edges){
    add_edge(g, e.from, e.to, e.cost);
    if(not DIRECTED) add_edge(g, e.to, e.from, e.cost);
  }
  
  return g;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/IO/input_graph.cpp"
#include <iostream>
#line 2 "Mylib/Graph/graph_template.cpp"
#include <vector>
#line 4 "Mylib/Graph/graph_template.cpp"

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
#line 4 "Mylib/IO/input_graph.cpp"

/**
 * @docs input_graph.md
 */
template <typename T, size_t I, bool WEIGHTED>
std::vector<Edge<T>> input_edges(int M){
  std::vector<Edge<T>> ret;
  
  for(int i = 0; i < M; ++i){
    int s, t; std::cin >> s >> t;
    s -= I;
    t -= I;
    T w = 1; if(WEIGHTED) std::cin >> w;
    ret.emplace_back(s, t, w);
  }
  
  return ret;  
}

template <typename T, bool DIRECTED>
Graph<T> convert_to_graph(int N, const std::vector<Edge<T>> &edges){
  Graph<T> g(N);

  for(const auto &e : edges){
    add_edge(g, e.from, e.to, e.cost);
    if(not DIRECTED) add_edge(g, e.to, e.from, e.cost);
  }
  
  return g;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

