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


# :x: Tree distance

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a41ea9974466d4f509bcbf59f2ee921e">Mylib/Graph/TreeUtils</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/TreeUtils/tree_distance.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Depends on

* :question: <a href="../Template/graph.cpp.html">Basic graph</a>


## Required by

* :x: <a href="tree_height.cpp.html">Tree height</a>


## Verified with

* :x: <a href="../../../../verify/test/aoj/GRL_5_B/main.test.cpp.html">test/aoj/GRL_5_B/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yukicoder/922/main.test.cpp.html">test/yukicoder/922/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <stack>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Tree distance
 * @docs tree_distance.md
 */
namespace haar_lib {
  template <typename T>
  std::vector<T> tree_distance(const tree<T> &tr, int root){
    const int n = tr.size();
    std::vector<T> ret(n);
    std::vector<bool> visited(n);

    std::stack<int> st;
    st.push(root);
    ret[root] = 0;

    while(not st.empty()){
      int cur = st.top(); st.pop();
      visited[cur] = true;

      for(auto &e : tr[cur]){
        if(not visited[e.to]){
          ret[e.to] = ret[cur] + e.cost;
          st.push(e.to);
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
#line 2 "Mylib/Graph/TreeUtils/tree_distance.cpp"
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
#line 5 "Mylib/Graph/TreeUtils/tree_distance.cpp"

/**
 * @title Tree distance
 * @docs tree_distance.md
 */
namespace haar_lib {
  template <typename T>
  std::vector<T> tree_distance(const tree<T> &tr, int root){
    const int n = tr.size();
    std::vector<T> ret(n);
    std::vector<bool> visited(n);

    std::stack<int> st;
    st.push(root);
    ret[root] = 0;

    while(not st.empty()){
      int cur = st.top(); st.pop();
      visited[cur] = true;

      for(auto &e : tr[cur]){
        if(not visited[e.to]){
          ret[e.to] = ret[cur] + e.cost;
          st.push(e.to);
        }
      }
    }

    return ret;
  }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

