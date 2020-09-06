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


# :x: Borůvka algorithm

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#cb5ed95d97b7ee8efcbdf177a47dc7b7">Mylib/Graph/MinimumSpanningTree</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/MinimumSpanningTree/boruvka.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 11:15:59+09:00




## Operations

## Requirements

## Notes

## Problems

## References

- [https://en.wikipedia.org/wiki/Bor%C5%AFvka%27s_algorithm](https://en.wikipedia.org/wiki/Bor%C5%AFvka%27s_algorithm)
- [http://spinda2.blog48.fc2.com/blog-entry-560.html](http://spinda2.blog48.fc2.com/blog-entry-560.html)


## Depends on

* :x: <a href="../../DataStructure/UnionFind/unionfind.cpp.html">Union-find</a>
* :x: <a href="../Template/graph.cpp.html">Basic graph</a>


## Verified with

* :x: <a href="../../../../verify/test/aoj/GRL_2_A/main.boruvka.test.cpp.html">test/aoj/GRL_2_A/main.boruvka.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <utility>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/DataStructure/UnionFind/unionfind.cpp"

/**
 * @title Borůvka algorithm
 * @docs boruvka.md
 */
template <typename T>
auto boruvka(const Graph<T> &g){
  std::vector<Edge<T>> ret;
  const int N = g.size();

  UnionFind uf(N);
  std::vector<std::vector<int>> c(N);
  for(int i = 0; i < N; ++i) c[i].push_back(i);

  while((int)(ret.size()) < N - 1){
    std::vector<Edge<T>> temp;

    for(auto &a : c){
      Edge<T> m;
      bool ok = false;

      if(a.empty()) continue;

      for(auto i : a){
        for(auto &e : g[i]){
          if(uf.is_same(e.from, e.to)) continue;
          if(not std::exchange(ok, true) or e.cost < m.cost){
            m = e;
          }
        }
      }

      temp.push_back(m);
    }

    for(auto &e : temp){
      if(uf.is_same(e.from, e.to)) continue;

      const int i = uf.root_of(e.from);
      const int j = uf.root_of(e.to);
      const int k = uf.merge(i, j);

      if(c[i].size() < c[j].size()) std::swap(c[i], c[j]);

      c[i].insert(c[i].end(), c[j].begin(), c[j].end());
      c[j].clear();

      std::swap(c[k], c[i]);

      ret.push_back(e);
    }
  }

  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/MinimumSpanningTree/boruvka.cpp"
#include <vector>
#include <utility>
#line 3 "Mylib/Graph/Template/graph.cpp"
#include <iostream>

/**
 * @title Basic graph
 * @docs graph.md
 */
template <typename T>
struct Edge {
  int from, to;
  T cost;
  int index = -1;
  Edge(){}
  Edge(int from, int to, T cost): from(from), to(to), cost(cost){}
  Edge(int from, int to, T cost, int index): from(from), to(to), cost(cost), index(index){}
};

template <typename T>
struct Graph {
  using weight_type = T;
  using edge_type = Edge<T>;

  std::vector<std::vector<Edge<T>>> data;

  auto& operator[](size_t i){return data[i];}
  const auto& operator[](size_t i) const {return data[i];}

  auto begin() const {return data.begin();}
  auto end() const {return data.end();}

  Graph(){}
  Graph(int N): data(N){}

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
using Tree = Graph<T>;
#line 3 "Mylib/DataStructure/UnionFind/unionfind.cpp"
#include <numeric>

/**
 * @title Union-find
 * @docs unionfind.md
 */
class UnionFind {
  std::vector<int> parent, depth, size;
  int count;

public:
  UnionFind(){}
  UnionFind(int n): parent(n), depth(n, 1), size(n, 1), count(n){
    std::iota(parent.begin(), parent.end(), 0);
  }

  int root_of(int i){
    if(parent[i] == i) return i;
    else return parent[i] = root_of(parent[i]);
  }

  bool is_same(int i, int j){return root_of(i) == root_of(j);}

  int merge(int i, int j){
    const int ri = root_of(i), rj = root_of(j);
    if(ri == rj) return ri;
    else{
      --count;
      if(depth[ri] < depth[rj]){
        parent[ri] = rj;
        size[rj] += size[ri];
        return rj;
      }else{
        parent[rj] = ri;
        size[ri] += size[rj];
        if(depth[ri] == depth[rj]) ++depth[ri];
        return ri;
      }
    }
  }

  int size_of(int i){return size[root_of(i)];}

  int count_group(){return count;}
};
#line 6 "Mylib/Graph/MinimumSpanningTree/boruvka.cpp"

/**
 * @title Borůvka algorithm
 * @docs boruvka.md
 */
template <typename T>
auto boruvka(const Graph<T> &g){
  std::vector<Edge<T>> ret;
  const int N = g.size();

  UnionFind uf(N);
  std::vector<std::vector<int>> c(N);
  for(int i = 0; i < N; ++i) c[i].push_back(i);

  while((int)(ret.size()) < N - 1){
    std::vector<Edge<T>> temp;

    for(auto &a : c){
      Edge<T> m;
      bool ok = false;

      if(a.empty()) continue;

      for(auto i : a){
        for(auto &e : g[i]){
          if(uf.is_same(e.from, e.to)) continue;
          if(not std::exchange(ok, true) or e.cost < m.cost){
            m = e;
          }
        }
      }

      temp.push_back(m);
    }

    for(auto &e : temp){
      if(uf.is_same(e.from, e.to)) continue;

      const int i = uf.root_of(e.from);
      const int j = uf.root_of(e.to);
      const int k = uf.merge(i, j);

      if(c[i].size() < c[j].size()) std::swap(c[i], c[j]);

      c[i].insert(c[i].end(), c[j].begin(), c[j].end());
      c[j].clear();

      std::swap(c[k], c[i]);

      ret.push_back(e);
    }
  }

  return ret;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

