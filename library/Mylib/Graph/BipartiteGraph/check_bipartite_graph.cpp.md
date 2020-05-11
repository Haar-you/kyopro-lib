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


# :warning: 二部グラフ判定 (連結グラフ)

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#3b87eee7aef75da88610c966a8da844f">Mylib/Graph/BipartiteGraph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/BipartiteGraph/check_bipartite_graph.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-03 16:28:32+09:00




## Depends on

* :heavy_check_mark: <a href="../graph_template.cpp.html">グラフ用テンプレート</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <optional>
#include <stack>
#include "Mylib/Graph/graph_template.cpp"

/**
 * @title 二部グラフ判定 (連結グラフ)
 * @docs check_bipartite_graph.md
 */
template <typename T>
std::optional<std::vector<int>> is_bipartite_graph(const Graph<T> &graph){
  std::vector<int> check(graph.size(), -1);
  std::vector<bool> visit(graph.size(), false);
  std::stack<int> st;

  st.push(0);
  check[0] = 0;

  while(not st.empty()){
    auto cur = st.top(); st.pop();
    if(visit[cur]) continue;
    visit[cur] = true;

    for(auto &e : graph[cur]){
      if(check[e.to] == check[e.from]) return std::nullopt;

      if(check[e.to] == -1){
        check[e.to] = (check[e.from] == 0 ? 1 : 0);
      }

      st.push(e.to);
    }
  }

  for(auto x : check) if(x == -1) return std::nullopt;

  return {check};
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/BipartiteGraph/check_bipartite_graph.cpp"
#include <vector>
#include <optional>
#include <stack>
#line 3 "Mylib/Graph/graph_template.cpp"
#include <iostream>

/**
 * @title グラフ用テンプレート
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
#line 6 "Mylib/Graph/BipartiteGraph/check_bipartite_graph.cpp"

/**
 * @title 二部グラフ判定 (連結グラフ)
 * @docs check_bipartite_graph.md
 */
template <typename T>
std::optional<std::vector<int>> is_bipartite_graph(const Graph<T> &graph){
  std::vector<int> check(graph.size(), -1);
  std::vector<bool> visit(graph.size(), false);
  std::stack<int> st;

  st.push(0);
  check[0] = 0;

  while(not st.empty()){
    auto cur = st.top(); st.pop();
    if(visit[cur]) continue;
    visit[cur] = true;

    for(auto &e : graph[cur]){
      if(check[e.to] == check[e.from]) return std::nullopt;

      if(check[e.to] == -1){
        check[e.to] = (check[e.from] == 0 ? 1 : 0);
      }

      st.push(e.to);
    }
  }

  for(auto x : check) if(x == -1) return std::nullopt;

  return {check};
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

