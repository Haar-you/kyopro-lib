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
    - Last commit date: 2020-09-10 06:29:03+09:00




## Depends on

* :question: <a href="../Template/graph.cpp.html">Basic graph</a>


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
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Detect cycle
 * @docs detect_cycle.md
 */
namespace haar_lib {
  namespace detect_cycle_impl {
    constexpr static int SEARCHED = 1;
    constexpr static int SEARCHING = 2;

    template <typename T>
    std::optional<int> rec(
      const graph<T> &g,
      int cur,
      std::vector<edge<T>> &temp,
      std::vector<edge<T>> &ret,
      std::vector<int> &check
    ){
      if(check[cur] == SEARCHED) return std::nullopt;
      if(check[cur] == SEARCHING) return {cur};
      check[cur] = SEARCHING;

      for(auto &e : g[cur]){
        temp.push_back(e);

        if(auto res = rec(g, e.to, temp, ret, check); res){
          if(*res != -1){
            ret.push_back(e);
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
    }
  }

  template <typename T>
  std::optional<std::vector<edge<T>>> detect_cycle(const graph<T> &g){
    const int N = g.size();
    std::vector<int> check(N);

    for(int i = 0; i < N; ++i){
      if(check[i] == 0){
        std::vector<edge<T>> temp, ret;
        detect_cycle_impl::rec(g, i, temp, ret, check);
        if(not ret.empty()){
          std::reverse(ret.begin(), ret.end());
          return {ret};
        }
      }
    }

    return std::nullopt;
  }
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
#line 6 "Mylib/Graph/Cycle/detect_cycle.cpp"

/**
 * @title Detect cycle
 * @docs detect_cycle.md
 */
namespace haar_lib {
  namespace detect_cycle_impl {
    constexpr static int SEARCHED = 1;
    constexpr static int SEARCHING = 2;

    template <typename T>
    std::optional<int> rec(
      const graph<T> &g,
      int cur,
      std::vector<edge<T>> &temp,
      std::vector<edge<T>> &ret,
      std::vector<int> &check
    ){
      if(check[cur] == SEARCHED) return std::nullopt;
      if(check[cur] == SEARCHING) return {cur};
      check[cur] = SEARCHING;

      for(auto &e : g[cur]){
        temp.push_back(e);

        if(auto res = rec(g, e.to, temp, ret, check); res){
          if(*res != -1){
            ret.push_back(e);
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
    }
  }

  template <typename T>
  std::optional<std::vector<edge<T>>> detect_cycle(const graph<T> &g){
    const int N = g.size();
    std::vector<int> check(N);

    for(int i = 0; i < N; ++i){
      if(check[i] == 0){
        std::vector<edge<T>> temp, ret;
        detect_cycle_impl::rec(g, i, temp, ret, check);
        if(not ret.empty()){
          std::reverse(ret.begin(), ret.end());
          return {ret};
        }
      }
    }

    return std::nullopt;
  }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

