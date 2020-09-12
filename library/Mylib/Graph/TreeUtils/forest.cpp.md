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


# :x: Decompose forest

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a41ea9974466d4f509bcbf59f2ee921e">Mylib/Graph/TreeUtils</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/TreeUtils/forest.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Depends on

* :question: <a href="../Template/graph.cpp.html">Basic graph</a>


## Verified with

* :x: <a href="../../../../verify/test/yukicoder/922/main.test.cpp.html">test/yukicoder/922/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <algorithm>
#include <utility>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Decompose forest
 * @docs forest.md
 */
namespace haar_lib {
  template <typename T>
  struct forest {
    std::vector<tree<T>> trees;
    std::vector<int> tree_id;
    std::vector<int> vertex_id;
    std::vector<std::vector<int>> rid;

    forest(const graph<T> &g){
      const int N = g.size();

      tree_id.resize(N);
      vertex_id.resize(N);

      std::vector<bool> check(N);

      auto dfs =
        [&](auto &dfs, int cur, std::vector<int> &vertices, std::vector<edge<T>> &edges) -> void {
          check[cur] = true;
          vertices.push_back(cur);

          for(auto &e : g[cur]){
            edges.push_back(e);

            if(not check[e.to]){
              dfs(dfs, e.to, vertices, edges);
            }
          }
        };

      for(int i = 0; i < N; ++i){
        if(not check[i]){
          std::vector<int> vertices;
          std::vector<edge<T>> edges;
          dfs(dfs, i, vertices, edges);

          const int m = vertices.size();
          const int k = trees.size();

          rid.emplace_back(m);

          for(int i = 0; i < (int)vertices.size(); ++i){
            tree_id[vertices[i]] = k;
            vertex_id[vertices[i]] = i;
            rid[k][i] = vertices[i];
          }

          trees.push_back(m);

          for(auto &e : edges){
            trees[k].add_edge(vertex_id[e.from], vertex_id[e.to], e.cost);
          }
        }
      }
    }

    bool in_same_tree(int i, int j) const {
      return tree_id[i] == tree_id[j];
    }
  };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/TreeUtils/forest.cpp"
#include <vector>
#include <algorithm>
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
#line 6 "Mylib/Graph/TreeUtils/forest.cpp"

/**
 * @title Decompose forest
 * @docs forest.md
 */
namespace haar_lib {
  template <typename T>
  struct forest {
    std::vector<tree<T>> trees;
    std::vector<int> tree_id;
    std::vector<int> vertex_id;
    std::vector<std::vector<int>> rid;

    forest(const graph<T> &g){
      const int N = g.size();

      tree_id.resize(N);
      vertex_id.resize(N);

      std::vector<bool> check(N);

      auto dfs =
        [&](auto &dfs, int cur, std::vector<int> &vertices, std::vector<edge<T>> &edges) -> void {
          check[cur] = true;
          vertices.push_back(cur);

          for(auto &e : g[cur]){
            edges.push_back(e);

            if(not check[e.to]){
              dfs(dfs, e.to, vertices, edges);
            }
          }
        };

      for(int i = 0; i < N; ++i){
        if(not check[i]){
          std::vector<int> vertices;
          std::vector<edge<T>> edges;
          dfs(dfs, i, vertices, edges);

          const int m = vertices.size();
          const int k = trees.size();

          rid.emplace_back(m);

          for(int i = 0; i < (int)vertices.size(); ++i){
            tree_id[vertices[i]] = k;
            vertex_id[vertices[i]] = i;
            rid[k][i] = vertices[i];
          }

          trees.push_back(m);

          for(auto &e : edges){
            trees[k].add_edge(vertex_id[e.from], vertex_id[e.to], e.cost);
          }
        }
      }
    }

    bool in_same_tree(int i, int j) const {
      return tree_id[i] == tree_id[j];
    }
  };
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
