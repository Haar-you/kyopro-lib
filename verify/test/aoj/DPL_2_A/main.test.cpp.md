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


# :heavy_check_mark: test/aoj/DPL_2_A/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#ae5415aafc03e8f08c8f632e7ef1d421">test/aoj/DPL_2_A</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DPL_2_A/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A</a>


## Depends on

* :question: <a href="../../../../library/Mylib/Graph/graph_template.cpp.html">Graph template</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/travelling_salesman_problem.cpp.html">Travelling salesman problem</a>
* :question: <a href="../../../../library/Mylib/IO/input_graph.cpp.html">Mylib/IO/input_graph.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/travelling_salesman_problem.cpp"
#include "Mylib/IO/input_graph.cpp"

int main(){
  int V, E; std::cin >> V >> E;

  auto g = convert_to_graph<int, true>(V, input_edges<int, 0, true>(E));
  
  std::cout << travelling_salesman_problem(g, 0).value_or(-1) << std::endl;
  
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DPL_2_A/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A"

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
#line 3 "Mylib/Graph/travelling_salesman_problem.cpp"
#include <optional>
#include <algorithm>
#line 6 "Mylib/Graph/travelling_salesman_problem.cpp"

/**
 * @title Travelling salesman problem
 * @docs travelling_salesman_problem.md
 */
template <typename Cost>
std::optional<Cost> travelling_salesman_problem(const Graph<Cost> &g, int src){
  const int n = g.size();

  std::vector<std::vector<std::optional<Cost>>> dp(n, std::vector<std::optional<Cost>>(1<<n));

  for(auto &e : g[src]){
    if(not dp[e.to][1 << e.to]){
      dp[e.to][1 << e.to] = e.cost;
    }else{
      dp[e.to][1 << e.to] = std::min(*dp[e.to][1 << e.to], e.cost);
    }
  }

  for(int s = 1; s < (1<<n); ++s){
    for(int i = 0; i < n; ++i){
      if(not (s & (1<<i))) continue;

      for(auto &e : g[i]){
        if(s & (1<<e.to)) continue;

        if(dp[i][s]){
          if(not dp[e.to][s | (1<<e.to)]){
            dp[e.to][s | (1<<e.to)] = *dp[i][s] + e.cost;
          }else{
            dp[e.to][s | (1<<e.to)] = std::min(*dp[e.to][s | (1<<e.to)], *dp[i][s] + e.cost);
          }
        }
      }
    }
  }

  return dp[src][(1<<n)-1];
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
#line 7 "test/aoj/DPL_2_A/main.test.cpp"

int main(){
  int V, E; std::cin >> V >> E;

  auto g = convert_to_graph<int, true>(V, input_edges<int, 0, true>(E));
  
  std::cout << travelling_salesman_problem(g, 0).value_or(-1) << std::endl;
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

