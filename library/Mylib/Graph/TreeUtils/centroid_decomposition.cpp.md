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


# :warning: Centroid decomposition

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a41ea9974466d4f509bcbf59f2ee921e">Mylib/Graph/TreeUtils</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/TreeUtils/centroid_decomposition.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 18:36:08+09:00




## Operations

## Requirements

## Notes

## Problems

- [Codeforces Round #199 (Div. 2) E. Xenia and Tree](https://codeforces.com/contest/342/problem/E)

## References

- [https://www.hamayanhamayan.com/entry/2017/12/19/152143](https://www.hamayanhamayan.com/entry/2017/12/19/152143)
- [http://techtipshoge.blogspot.com/2016/09/centroid-decomposition.html](http://techtipshoge.blogspot.com/2016/09/centroid-decomposition.html)
- [https://ferin-tech.hatenablog.com/entry/2020/03/06/162311](https://ferin-tech.hatenablog.com/entry/2020/03/06/162311)


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
 * @title Centroid decomposition
 * @docs centroid_decomposition.md
 */
namespace haar_lib {
  template <typename T>
  class centroid_decomposition {
    int N;
    std::vector<int> parent;
    std::vector<std::vector<int>> children;
    std::vector<int> subsize;
    std::vector<bool> check;

  public:
    centroid_decomposition(const tree<T> &tr):
      N(tr.size()), parent(N), children(N), subsize(N), check(N)
    {
      decompose(tr, 0, -1);
    }

  private:
    void decompose(const tree<T> &tr, int cur, int par){
      dfs_subsize(tr, cur, -1);
      auto c = get_centroid(tr, cur, -1, subsize[cur]);

      check[c] = true;
      parent[c] = par;
      if(par != -1) children[par].push_back(c);

      for(auto &e : tr[c]){
        if(check[e.to]) continue;
        decompose(tr, e.to, c);
      }
    }

    int get_centroid(const tree<T> &tr, int cur, int par, int total_size){
      for(auto &e : tr[cur]){
        if(e.to == par or check[e.to]) continue;

        if(2 * subsize[e.to] > total_size){
          return get_centroid(tr, e.to, cur, total_size);
        }
      }

      return cur;
    }

    void dfs_subsize(const tree<T> &tr, int cur, int par){
      subsize[cur] = 1;
      for(auto &e : tr[cur]){
        if(e.to == par or check[e.to]) continue;
        dfs_subsize(tr, e.to, cur);
        subsize[cur] += subsize[e.to];
      }
    }

  public:
    auto bottom_up(int i) const {
      std::vector<int> ret;
      while(i >= 0){
        ret.push_back(i);
        i = parent[i];
      }
      return ret;
    }
  };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/TreeUtils/centroid_decomposition.cpp"
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
#line 4 "Mylib/Graph/TreeUtils/centroid_decomposition.cpp"

/**
 * @title Centroid decomposition
 * @docs centroid_decomposition.md
 */
namespace haar_lib {
  template <typename T>
  class centroid_decomposition {
    int N;
    std::vector<int> parent;
    std::vector<std::vector<int>> children;
    std::vector<int> subsize;
    std::vector<bool> check;

  public:
    centroid_decomposition(const tree<T> &tr):
      N(tr.size()), parent(N), children(N), subsize(N), check(N)
    {
      decompose(tr, 0, -1);
    }

  private:
    void decompose(const tree<T> &tr, int cur, int par){
      dfs_subsize(tr, cur, -1);
      auto c = get_centroid(tr, cur, -1, subsize[cur]);

      check[c] = true;
      parent[c] = par;
      if(par != -1) children[par].push_back(c);

      for(auto &e : tr[c]){
        if(check[e.to]) continue;
        decompose(tr, e.to, c);
      }
    }

    int get_centroid(const tree<T> &tr, int cur, int par, int total_size){
      for(auto &e : tr[cur]){
        if(e.to == par or check[e.to]) continue;

        if(2 * subsize[e.to] > total_size){
          return get_centroid(tr, e.to, cur, total_size);
        }
      }

      return cur;
    }

    void dfs_subsize(const tree<T> &tr, int cur, int par){
      subsize[cur] = 1;
      for(auto &e : tr[cur]){
        if(e.to == par or check[e.to]) continue;
        dfs_subsize(tr, e.to, cur);
        subsize[cur] += subsize[e.to];
      }
    }

  public:
    auto bottom_up(int i) const {
      std::vector<int> ret;
      while(i >= 0){
        ret.push_back(i);
        i = parent[i];
      }
      return ret;
    }
  };
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

