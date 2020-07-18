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


# :x: Detect cycle

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a962efc2861dbe1e0963e7d8bf7dda18">Mylib/Graph/Cycle</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/Cycle/detect_cycle.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-18 02:27:30+09:00




## Depends on

* :question: <a href="../graph_template.cpp.html">Graph template</a>


## Verified with

* :x: <a href="../../../../verify/test/yosupo-judge/cycle_detection/main.test.cpp.html">test/yosupo-judge/cycle_detection/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <optional>
#include <vector>
#include <algorithm>
#include "Mylib/Graph/graph_template.cpp"

/**
 * @title Detect cycle
 * @docs detect_cycle.md
 */
template <typename T>
std::optional<std::vector<int>> detect_cycle(int V, int E, std::vector<Edge<T>> edges){
  std::vector<std::vector<std::pair<Edge<T>, int>>> g(V);
  std::vector<int> check(V);

  constexpr int SEARCHED = 1;
  constexpr int SEARCHING = 2;

  for(int i = 0; i < E; ++i){
    g[edges[i].from].emplace_back(edges[i], i);
  }

  auto rec =
    [&](auto &rec, int cur, std::vector<int> &temp, std::vector<int> &ret) -> std::optional<int> {
      if(check[cur] == SEARCHED) return std::nullopt;
      if(check[cur] == SEARCHING) return {cur};
      check[cur] = SEARCHING;

      for(auto [e, i] : g[cur]){
        temp.push_back(i);

        if(auto res = rec(rec, e.to, temp, ret); res){
          if(*res != -1){
            ret.push_back(i);
            if(*res == cur){
              return {-1};
            }
          }
          
          return res;
        }

        temp.pop_back();
      }

      check[cur] = SEARCHED;
      
      return std::nullopt;
    };

  for(int i = 0; i < V; ++i){
    if(check[i] == 0){
      std::vector<int> temp, ret;
      rec(rec, i, temp, ret);
      if(not ret.empty()){
        std::reverse(ret.begin(), ret.end());
        return {ret};
      }
    }
  }

  return std::nullopt;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/Cycle/detect_cycle.cpp"
#include <optional>
#include <vector>
#include <algorithm>
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
#line 6 "Mylib/Graph/Cycle/detect_cycle.cpp"

/**
 * @title Detect cycle
 * @docs detect_cycle.md
 */
template <typename T>
std::optional<std::vector<int>> detect_cycle(int V, int E, std::vector<Edge<T>> edges){
  std::vector<std::vector<std::pair<Edge<T>, int>>> g(V);
  std::vector<int> check(V);

  constexpr int SEARCHED = 1;
  constexpr int SEARCHING = 2;

  for(int i = 0; i < E; ++i){
    g[edges[i].from].emplace_back(edges[i], i);
  }

  auto rec =
    [&](auto &rec, int cur, std::vector<int> &temp, std::vector<int> &ret) -> std::optional<int> {
      if(check[cur] == SEARCHED) return std::nullopt;
      if(check[cur] == SEARCHING) return {cur};
      check[cur] = SEARCHING;

      for(auto [e, i] : g[cur]){
        temp.push_back(i);

        if(auto res = rec(rec, e.to, temp, ret); res){
          if(*res != -1){
            ret.push_back(i);
            if(*res == cur){
              return {-1};
            }
          }
          
          return res;
        }

        temp.pop_back();
      }

      check[cur] = SEARCHED;
      
      return std::nullopt;
    };

  for(int i = 0; i < V; ++i){
    if(check[i] == 0){
      std::vector<int> temp, ret;
      rec(rec, i, temp, ret);
      if(not ret.empty()){
        std::reverse(ret.begin(), ret.end());
        return {ret};
      }
    }
  }

  return std::nullopt;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

