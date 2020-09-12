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


# :x: Decompose pseudotree

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#0520734517f09caa086d1aa01fa4b9e4">Mylib/Graph/GraphUtils</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/GraphUtils/decompose_pseudotree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Operations

## Requirements

## Notes

## Problems

## References

- [https://en.wikipedia.org/wiki/Pseudoforest](https://en.wikipedia.org/wiki/Pseudoforest)


## Depends on

* :question: <a href="../Template/graph.cpp.html">Basic graph</a>


## Verified with

* :x: <a href="../../../../verify/test/aoj/2891/main.test.cpp.html">test/aoj/2891/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <queue>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Decompose pseudotree
 * @docs decompose_pseudotree.md
 */
namespace haar_lib {
  template <typename T>
  struct pseudo_tree {
    const int n;
    std::vector<bool> in_loop;
    std::vector<int> group;

    void dfs(int cur, int par, const graph<T> &g){
      group[cur] = group[par];

      for(auto &e : g[cur]){
        if(e.to == par) continue;
        dfs(e.to, cur, g);
      }
    }

    pseudo_tree(const graph<T> &g): n(g.size()), in_loop(n, true), group(n){
      std::vector<int> indeg(n);
      std::vector<bool> visited(n);
      std::queue<int> q;

      for(int i = 0; i < n; ++i){
        for(auto &e : g[i]){
          ++indeg[e.to];
        }
      }

      for(int i = 0; i < n; ++i){
        if(indeg[i] == 1){
          q.push(i);
        }
      }

      while(not q.empty()){
        int cur = q.front(); q.pop();

        in_loop[cur] = false;

        if(visited[cur]) continue;
        visited[cur] = true;

        for(auto &e : g[cur]){
          if(not visited[e.to]){
            --indeg[e.to];
            if(indeg[e.to] == 1){
              q.push(e.to);
            }
          }
        }
      }

      for(int i = 0; i < n; ++i){
        if(in_loop[i]){
          for(auto &e : g[i]){
            if(not in_loop[e.to]){
              group[i] = i;
              dfs(e.to, i, g);
              break;
            }
          }
        }
      }
    }
  };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/GraphUtils/decompose_pseudotree.cpp"
#include <vector>
#include <queue>
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
#line 5 "Mylib/Graph/GraphUtils/decompose_pseudotree.cpp"

/**
 * @title Decompose pseudotree
 * @docs decompose_pseudotree.md
 */
namespace haar_lib {
  template <typename T>
  struct pseudo_tree {
    const int n;
    std::vector<bool> in_loop;
    std::vector<int> group;

    void dfs(int cur, int par, const graph<T> &g){
      group[cur] = group[par];

      for(auto &e : g[cur]){
        if(e.to == par) continue;
        dfs(e.to, cur, g);
      }
    }

    pseudo_tree(const graph<T> &g): n(g.size()), in_loop(n, true), group(n){
      std::vector<int> indeg(n);
      std::vector<bool> visited(n);
      std::queue<int> q;

      for(int i = 0; i < n; ++i){
        for(auto &e : g[i]){
          ++indeg[e.to];
        }
      }

      for(int i = 0; i < n; ++i){
        if(indeg[i] == 1){
          q.push(i);
        }
      }

      while(not q.empty()){
        int cur = q.front(); q.pop();

        in_loop[cur] = false;

        if(visited[cur]) continue;
        visited[cur] = true;

        for(auto &e : g[cur]){
          if(not visited[e.to]){
            --indeg[e.to];
            if(indeg[e.to] == 1){
              q.push(e.to);
            }
          }
        }
      }

      for(int i = 0; i < n; ++i){
        if(in_loop[i]){
          for(auto &e : g[i]){
            if(not in_loop[e.to]){
              group[i] = i;
              dfs(e.to, i, g);
              break;
            }
          }
        }
      }
    }
  };
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

