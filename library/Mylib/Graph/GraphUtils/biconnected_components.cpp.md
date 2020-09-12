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


# :warning: Biconnected components

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#0520734517f09caa086d1aa01fa4b9e4">Mylib/Graph/GraphUtils</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/GraphUtils/biconnected_components.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Operations

## Requirements

## Notes

## Problems

- [ARC062 F - AtCoDeerくんとグラフ色塗り](https://atcoder.jp/contests/arc062/tasks/arc062_d)

## References

- [http://www.prefield.com/algorithm/graph/articulation_point.html](http://www.prefield.com/algorithm/graph/articulation_point.html)
- [https://ei1333.github.io/luzhiled/snippets/graph/bi-connected-components.html](https://ei1333.github.io/luzhiled/snippets/graph/bi-connected-components.html)


## Depends on

* :question: <a href="../Template/graph.cpp.html">Basic graph</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <stack>
#include <algorithm>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Biconnected components
 * @docs biconnected_components.md
 */
namespace haar_lib {
  namespace biconnected_components_impl {
    template <typename T>
    void dfs(
      const graph<T> &g,
      int cur,
      int par,
      std::vector<bool> &check,
      std::vector<int> &low,
      std::vector<int> &ord,
      std::vector<std::vector<edge<T>>> &ret,
      std::stack<edge<T>> &st,
      int &t
    ){
      check[cur] = true;
      ord[cur] = t;
      low[cur] = t;
      ++t;

      for(auto &e : g[cur]){
        if(e.to == par) continue;

        if(ord[e.to] < ord[cur]){
          auto f = e;
          if(f.from > f.to) std::swap(f.from, f.to);
          st.push(f);
        }
        if(not check[e.to]){
          dfs(g, e.to, cur, check, low, ord, ret, st, t);
          low[cur] = std::min(low[cur], low[e.to]);
          if(low[e.to] >= ord[cur]){
            ret.emplace_back();
            while(true){
              auto f = st.top(); st.pop();
              ret.back().push_back(f);
              if(f.from == std::min(e.from, e.to) and f.to == std::max(e.from, e.to)) break;
            }
          }
        }else{
          low[cur] = std::min(low[cur], ord[e.to]);
        }
      }
    }
  }

  template <typename T>
  auto biconnected_components(const graph<T> &g){
    const int n = g.size();

    std::vector<bool> check(n);
    std::vector<int> low(n, -1), ord(n, -1);
    std::vector<std::vector<edge<T>>> ret;
    std::stack<edge<T>> st;
    int t = 0;

    for(int i = 0; i < n; ++i){
      if(not check[i]) biconnected_components_impl::dfs(g, i, -1, check, low, ord, ret, st, t);
    }

    return ret;
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/GraphUtils/biconnected_components.cpp"
#include <vector>
#include <stack>
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
#line 6 "Mylib/Graph/GraphUtils/biconnected_components.cpp"

/**
 * @title Biconnected components
 * @docs biconnected_components.md
 */
namespace haar_lib {
  namespace biconnected_components_impl {
    template <typename T>
    void dfs(
      const graph<T> &g,
      int cur,
      int par,
      std::vector<bool> &check,
      std::vector<int> &low,
      std::vector<int> &ord,
      std::vector<std::vector<edge<T>>> &ret,
      std::stack<edge<T>> &st,
      int &t
    ){
      check[cur] = true;
      ord[cur] = t;
      low[cur] = t;
      ++t;

      for(auto &e : g[cur]){
        if(e.to == par) continue;

        if(ord[e.to] < ord[cur]){
          auto f = e;
          if(f.from > f.to) std::swap(f.from, f.to);
          st.push(f);
        }
        if(not check[e.to]){
          dfs(g, e.to, cur, check, low, ord, ret, st, t);
          low[cur] = std::min(low[cur], low[e.to]);
          if(low[e.to] >= ord[cur]){
            ret.emplace_back();
            while(true){
              auto f = st.top(); st.pop();
              ret.back().push_back(f);
              if(f.from == std::min(e.from, e.to) and f.to == std::max(e.from, e.to)) break;
            }
          }
        }else{
          low[cur] = std::min(low[cur], ord[e.to]);
        }
      }
    }
  }

  template <typename T>
  auto biconnected_components(const graph<T> &g){
    const int n = g.size();

    std::vector<bool> check(n);
    std::vector<int> low(n, -1), ord(n, -1);
    std::vector<std::vector<edge<T>>> ret;
    std::stack<edge<T>> st;
    int t = 0;

    for(int i = 0; i < n; ++i){
      if(not check[i]) biconnected_components_impl::dfs(g, i, -1, check, low, ord, ret, st, t);
    }

    return ret;
  }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

