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


# :x: Two edge connected components

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#0520734517f09caa086d1aa01fa4b9e4">Mylib/Graph/GraphUtils</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/GraphUtils/two_edge_connected_components.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Depends on

* :question: <a href="../Template/graph.cpp.html">Basic graph</a>


## Verified with

* :x: <a href="../../../../verify/test/yosupo-judge/two_edge_connected_components/main.test.cpp.html">test/yosupo-judge/two_edge_connected_components/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <stack>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Two edge connected components
 * @docs two_edge_connected_components.md
 */
namespace haar_lib {
  namespace two_edge_connected_components_impl {
    template <typename T>
    int dfs(
      const graph<T> &g,
      int cur,
      int par,
      std::vector<int> &low,
      std::vector<int> &order,
      std::vector<std::vector<int>> &ret,
      std::stack<int> &st,
      int &v
    ){
      if(order[cur] != -1) return order[cur];
      order[cur] = v;
      int temp = v++;
      st.push(cur);

      int count = 0;

      for(const auto &e : g[cur]){
        if(e.to == par){
          ++count;
          if(count == 1) continue;
        }

        const int t = dfs(g, e.to, cur, low, order, ret, st, v);
        temp = std::min(temp, t);

        if(low[e.to] > order[cur]){ // e is a bridge
          std::vector<int> cc;
          while(true){
            int c = st.top();
            cc.emplace_back(c);
            st.pop();
            if(c == e.to) break;
          }
          ret.emplace_back(cc);
        }
      }

      return low[cur] = temp;
    }
  }

  template <typename T>
  auto two_edge_connected_components(const graph<T> &g){
    const int n = g.size();

    std::vector<int> low(n, -1), order(n, -1);
    std::vector<std::vector<int>> ret;
    std::stack<int> st;
    int v = 0;

    for(int i = 0; i < n; ++i){
      if(order[i] == -1){
        two_edge_connected_components_impl::dfs(g, i, -1, low, order, ret, st, v);
        if(not st.empty()){
          std::vector<int> cc;
          while(not st.empty()) cc.emplace_back(st.top()), st.pop();
          ret.emplace_back(cc);
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
#line 2 "Mylib/Graph/GraphUtils/two_edge_connected_components.cpp"
#include <vector>
#include <stack>
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
#line 5 "Mylib/Graph/GraphUtils/two_edge_connected_components.cpp"

/**
 * @title Two edge connected components
 * @docs two_edge_connected_components.md
 */
namespace haar_lib {
  namespace two_edge_connected_components_impl {
    template <typename T>
    int dfs(
      const graph<T> &g,
      int cur,
      int par,
      std::vector<int> &low,
      std::vector<int> &order,
      std::vector<std::vector<int>> &ret,
      std::stack<int> &st,
      int &v
    ){
      if(order[cur] != -1) return order[cur];
      order[cur] = v;
      int temp = v++;
      st.push(cur);

      int count = 0;

      for(const auto &e : g[cur]){
        if(e.to == par){
          ++count;
          if(count == 1) continue;
        }

        const int t = dfs(g, e.to, cur, low, order, ret, st, v);
        temp = std::min(temp, t);

        if(low[e.to] > order[cur]){ // e is a bridge
          std::vector<int> cc;
          while(true){
            int c = st.top();
            cc.emplace_back(c);
            st.pop();
            if(c == e.to) break;
          }
          ret.emplace_back(cc);
        }
      }

      return low[cur] = temp;
    }
  }

  template <typename T>
  auto two_edge_connected_components(const graph<T> &g){
    const int n = g.size();

    std::vector<int> low(n, -1), order(n, -1);
    std::vector<std::vector<int>> ret;
    std::stack<int> st;
    int v = 0;

    for(int i = 0; i < n; ++i){
      if(order[i] == -1){
        two_edge_connected_components_impl::dfs(g, i, -1, low, order, ret, st, v);
        if(not st.empty()){
          std::vector<int> cc;
          while(not st.empty()) cc.emplace_back(st.top()), st.pop();
          ret.emplace_back(cc);
        }
      }
    }

    return ret;
  }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

