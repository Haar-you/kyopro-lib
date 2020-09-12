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


# :x: Lowest common ancestor (HLD)

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a41ea9974466d4f509bcbf59f2ee921e">Mylib/Graph/TreeUtils</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/TreeUtils/lca_hld.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 18:36:08+09:00




## Depends on

* :question: <a href="../Template/graph.cpp.html">Basic graph</a>


## Verified with

* :x: <a href="../../../../verify/test/aoj/GRL_5_C/main.hld.test.cpp.html">test/aoj/GRL_5_C/main.hld.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <utility>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Lowest common ancestor (HLD)
 * @docs lca_hld.md
 */
namespace haar_lib {
  template <typename T>
  class lowest_common_ancestor_hld {
    int n;
    std::vector<int> sub, par, head, id;

    int dfs_sub(int cur, int p, tree<T> &tr){
      par[cur] = p;
      int t = 0;
      for(auto &e : tr[cur]){
        if(e.to == p) continue;
        sub[cur] += dfs_sub(e.to, cur, tr);
        if(sub[e.to] > t){
          t = sub[e.to];
          std::swap(e, tr[cur][0]);
        }
      }
      return sub[cur];
    }

    void dfs_build(int cur, int &i, tree<T> &tr){
      id[cur] = i;
      ++i;

      for(auto &e : tr[cur]){
        if(e.to == par[cur]) continue;
        head[e.to] = (e.to == tr[cur][0].to ? head[cur] : e.to);
        dfs_build(e.to, i, tr);
      }
    }

  public:
    lowest_common_ancestor_hld(tree<T> tr, int root):
      n(tr.size()), sub(n, 1), par(n, -1), head(n), id(n){
      dfs_sub(root, -1, tr);
      int i = 0;
      dfs_build(root, i, tr);
    }

    int lca(int u, int v) const {
      while(1){
        if(id[u] > id[v]) std::swap(u, v);
        if(head[u] == head[v]) return u;
        v = par[head[v]];
      }
    }

    int operator()(int u, int v) const {return lca(u, v);}

    T distance(int u, int v, const std::vector<T> &dist) const {
      return dist[u] + dist[v] - 2 * dist[lca(u, v)];
    }
  };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/TreeUtils/lca_hld.cpp"
#include <vector>
#include <utility>
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
#line 5 "Mylib/Graph/TreeUtils/lca_hld.cpp"

/**
 * @title Lowest common ancestor (HLD)
 * @docs lca_hld.md
 */
namespace haar_lib {
  template <typename T>
  class lowest_common_ancestor_hld {
    int n;
    std::vector<int> sub, par, head, id;

    int dfs_sub(int cur, int p, tree<T> &tr){
      par[cur] = p;
      int t = 0;
      for(auto &e : tr[cur]){
        if(e.to == p) continue;
        sub[cur] += dfs_sub(e.to, cur, tr);
        if(sub[e.to] > t){
          t = sub[e.to];
          std::swap(e, tr[cur][0]);
        }
      }
      return sub[cur];
    }

    void dfs_build(int cur, int &i, tree<T> &tr){
      id[cur] = i;
      ++i;

      for(auto &e : tr[cur]){
        if(e.to == par[cur]) continue;
        head[e.to] = (e.to == tr[cur][0].to ? head[cur] : e.to);
        dfs_build(e.to, i, tr);
      }
    }

  public:
    lowest_common_ancestor_hld(tree<T> tr, int root):
      n(tr.size()), sub(n, 1), par(n, -1), head(n), id(n){
      dfs_sub(root, -1, tr);
      int i = 0;
      dfs_build(root, i, tr);
    }

    int lca(int u, int v) const {
      while(1){
        if(id[u] > id[v]) std::swap(u, v);
        if(head[u] == head[v]) return u;
        v = par[head[v]];
      }
    }

    int operator()(int u, int v) const {return lca(u, v);}

    T distance(int u, int v, const std::vector<T> &dist) const {
      return dist[u] + dist[v] - 2 * dist[lca(u, v)];
    }
  };
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

