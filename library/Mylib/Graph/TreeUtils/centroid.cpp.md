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


# :warning: Enumerate centroids

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a41ea9974466d4f509bcbf59f2ee921e">Mylib/Graph/TreeUtils</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/TreeUtils/centroid.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 18:36:08+09:00




## Depends on

* :question: <a href="../Template/graph.cpp.html">Basic graph</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Enumerate centroids
 * @docs centroid.md
 */
namespace haar_lib {
  namespace enumerate_centroids_impl {
    template <typename T>
    void dfs(const tree<T> &tr, std::vector<int> &subtree, std::vector<int> &ret, int N, int cur, int par){
      subtree[cur] = 1;
      bool check = true;

      for(auto &e : tr[cur]){
        if(e.to == par) continue;
        dfs(tr, subtree, ret, N, e.to, cur);

        if(subtree[e.to] > N / 2) check = false;
        subtree[cur] += subtree[e.to];
      }

      if(N - subtree[cur] > N / 2) check = false;

      if(check) ret.push_back(cur);
    }
  }

  template <typename T>
  auto enumerate_centroids(const tree<T> &tr){
    const int N = tr.size();
    std::vector<int> subtree(N), ret;
    enumerate_centroids_impl::dfs(tr, subtree, ret, N, 0, -1);
    return ret;
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/TreeUtils/centroid.cpp"
#include <vector>
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
#line 4 "Mylib/Graph/TreeUtils/centroid.cpp"

/**
 * @title Enumerate centroids
 * @docs centroid.md
 */
namespace haar_lib {
  namespace enumerate_centroids_impl {
    template <typename T>
    void dfs(const tree<T> &tr, std::vector<int> &subtree, std::vector<int> &ret, int N, int cur, int par){
      subtree[cur] = 1;
      bool check = true;

      for(auto &e : tr[cur]){
        if(e.to == par) continue;
        dfs(tr, subtree, ret, N, e.to, cur);

        if(subtree[e.to] > N / 2) check = false;
        subtree[cur] += subtree[e.to];
      }

      if(N - subtree[cur] > N / 2) check = false;

      if(check) ret.push_back(cur);
    }
  }

  template <typename T>
  auto enumerate_centroids(const tree<T> &tr){
    const int N = tr.size();
    std::vector<int> subtree(N), ret;
    enumerate_centroids_impl::dfs(tr, subtree, ret, N, 0, -1);
    return ret;
  }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

