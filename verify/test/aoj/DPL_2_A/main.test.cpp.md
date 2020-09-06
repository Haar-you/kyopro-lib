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


# :x: test/aoj/DPL_2_A/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#ae5415aafc03e8f08c8f632e7ef1d421">test/aoj/DPL_2_A</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DPL_2_A/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 11:15:59+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Graph/Template/graph.cpp.html">Basic graph</a>
* :x: <a href="../../../../library/Mylib/Graph/travelling_salesman_problem.cpp.html">Travelling salesman problem</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A"

#include <iostream>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/travelling_salesman_problem.cpp"

int main(){
  int V, E; std::cin >> V >> E;

  Graph<int> g(V);
  g.read<0>(E);

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
#line 2 "Mylib/Graph/Template/graph.cpp"
#include <vector>
#line 4 "Mylib/Graph/Template/graph.cpp"

/**
 * @title Basic graph
 * @docs graph.md
 */
template <typename T>
struct Edge {
  int from, to;
  T cost;
  int index = -1;
  Edge(){}
  Edge(int from, int to, T cost): from(from), to(to), cost(cost){}
  Edge(int from, int to, T cost, int index): from(from), to(to), cost(cost), index(index){}
};

template <typename T>
struct Graph {
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
#line 3 "Mylib/Graph/travelling_salesman_problem.cpp"
#include <optional>
#include <algorithm>
#line 6 "Mylib/Graph/travelling_salesman_problem.cpp"

/**
 * @title Travelling salesman problem
 * @docs travelling_salesman_problem.md
 */
template <typename T>
std::optional<T> travelling_salesman_problem(const Graph<T> &g, int src){
  const int n = g.size();

  std::vector<std::vector<std::optional<T>>> dp(n, std::vector<std::optional<T>>(1 << n));

  for(auto &e : g[src]){
    if(not dp[e.to][1 << e.to]){
      dp[e.to][1 << e.to] = e.cost;
    }else{
      dp[e.to][1 << e.to] = std::min(*dp[e.to][1 << e.to], e.cost);
    }
  }

  for(int s = 1; s < (1 << n); ++s){
    for(int i = 0; i < n; ++i){
      if(not (s & (1 << i))) continue;

      for(auto &e : g[i]){
        if(s & (1 << e.to)) continue;

        if(dp[i][s]){
          if(not dp[e.to][s | (1 << e.to)]){
            dp[e.to][s | (1 << e.to)] = *dp[i][s] + e.cost;
          }else{
            dp[e.to][s | (1 << e.to)] = std::min(*dp[e.to][s | (1 << e.to)], *dp[i][s] + e.cost);
          }
        }
      }
    }
  }

  return dp[src][(1 << n) - 1];
}
#line 6 "test/aoj/DPL_2_A/main.test.cpp"

int main(){
  int V, E; std::cin >> V >> E;

  Graph<int> g(V);
  g.read<0>(E);

  std::cout << travelling_salesman_problem(g, 0).value_or(-1) << std::endl;

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

