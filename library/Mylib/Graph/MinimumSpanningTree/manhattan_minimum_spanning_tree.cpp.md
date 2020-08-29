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


# :heavy_check_mark: Manhattan distance MST

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#cb5ed95d97b7ee8efcbdf177a47dc7b7">Mylib/Graph/MinimumSpanningTree</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/MinimumSpanningTree/manhattan_minimum_spanning_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-28 18:23:32+09:00




## Operations

## Requirements

## Notes

## Problems

## References

- [https://knuu.github.io/manhattan_mst.html](https://knuu.github.io/manhattan_mst.html)


## Depends on

* :heavy_check_mark: <a href="../../AlgebraicStructure/Monoid/min.cpp.html">Mylib/AlgebraicStructure/Monoid/min.cpp</a>
* :question: <a href="../../DataStructure/SegmentTree/segment_tree.cpp.html">Segment tree</a>
* :heavy_check_mark: <a href="../../DataStructure/UnionFind/unionfind.cpp.html">Union-find</a>
* :heavy_check_mark: <a href="kruskal.cpp.html">Kruskal algorithm</a>
* :question: <a href="../Template/graph.cpp.html">Basic graph</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/yosupo-judge/manhattanmst/main.test.cpp.html">test/yosupo-judge/manhattanmst/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <cmath>

#include "Mylib/AlgebraicStructure/Monoid/min.cpp"
#include "Mylib/DataStructure/SegmentTree/segment_tree.cpp"
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/MinimumSpanningTree/kruskal.cpp"

/**
 * @title Manhattan distance MST
 * @docs manhattan_minimum_spanning_tree.md
 */
template <typename T>
std::vector<Edge<T>> manhattan_minimum_spanning_tree(std::vector<T> x, std::vector<T> y){
  const int N = x.size();
  Graph<T> g(N);
  SegmentTree<MinMonoid<std::pair<T, int>>> seg(N);
  
  auto f =
    [&](){
      std::vector<T> Y(y);
      std::sort(Y.begin(), Y.end());
      Y.erase(std::unique(Y.begin(), Y.end()), Y.end());

      seg.init(std::nullopt);

      std::vector<int> ord(N);
      std::iota(ord.begin(), ord.end(), 0);
      std::sort(
        ord.begin(), ord.end(),
        [&](int i, int j){
          if(y[i] - x[i] == y[j] - x[j]) return x[i] > x[j];
          return y[i] - x[i] < y[j] - x[j];
        }
      );

      for(int i : ord){
        int lb = std::lower_bound(Y.begin(), Y.end(), y[i]) - Y.begin();

        if(auto res = seg.get(lb, N); res){
          auto j = res->second;
          T c = std::abs(x[i] - x[j]) + std::abs(y[i] - y[j]);
          g.add_edge(i, j, c);
        }

        if(auto res = seg.at(lb); not res or x[i] + y[i] < res->first){
          seg.update(lb, {{x[i] + y[i], i}});
        }
      }
    };

  for(int i = 0; i < 2; ++i){
    for(int j = 0; j < 2; ++j){
      for(int k = 0; k < 2; ++k){
        f();
        for(int l = 0; l < N; ++l) std::swap(x[l], y[l]);
      }
      for(int l = 0; l < N; ++l) x[l] = -x[l];
    }
    for(int l = 0; l < N; ++l) y[l] = -y[l];
  }
  
  return kruskal(g);
}


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/MinimumSpanningTree/manhattan_minimum_spanning_tree.cpp"

#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <cmath>

#line 3 "Mylib/AlgebraicStructure/Monoid/min.cpp"
#include <optional>

/**
 * @docs min.md
 */
template <typename T>
struct MinMonoid{
  using value_type = std::optional<T>;
  
  value_type id() const {return {};}
  value_type op(const value_type &a, const value_type &b) const {
    if(not a) return b;
    if(not b) return a;
    return {std::min(*a, *b)};
  }
};
#line 3 "Mylib/DataStructure/SegmentTree/segment_tree.cpp"

/**
 * @title Segment tree
 * @docs segment_tree.md
 */
template <typename Monoid>
class SegmentTree{
  using value_type = typename Monoid::value_type;
  Monoid M;
  
  int depth, size, hsize;
  std::vector<value_type> data;

public:
  SegmentTree(){}
  SegmentTree(int n):
    depth(n > 1 ? 32-__builtin_clz(n-1) + 1 : 1),
    size(1 << depth), hsize(size / 2),
    data(size, M.id())
  {}

  auto operator[](int i) const {return at(i);}
  auto at(int i) const {return data[hsize + i];}
  
  auto get(int x, int y) const { // [x,y)
    value_type ret_left = M.id();
    value_type ret_right = M.id();
    
    int l = x + hsize, r = y + hsize;
    while(l < r){
      if(r & 1) ret_right = M.op(data[--r], ret_right);
      if(l & 1) ret_left = M.op(ret_left, data[l++]);
      l >>= 1, r >>= 1;
    }
    
    return M.op(ret_left, ret_right);
  }

  void update(int i, const value_type &x){
    i += hsize;
    data[i] = x;
    while(i > 1) i >>= 1, data[i] = M.op(data[i << 1 | 0], data[i << 1 | 1]);
  }

  template <typename T>
  void init_with_vector(const std::vector<T> &val){
    data.assign(size, M.id());
    for(int i = 0; i < (int)val.size(); ++i) data[hsize + i] = val[i];
    for(int i = hsize-1; i >= 1; --i) data[i] = M.op(data[i << 1 | 0], data[i << 1 | 1]);
  }

  template <typename T>
  void init(const T &val){
    init_with_vector(std::vector<value_type>(hsize, val));
  }  
};
#line 3 "Mylib/Graph/Template/graph.cpp"

/**
 * @title Basic graph
 * @docs graph.md
 */
template <typename T>
struct Edge{
  int from, to;
  T cost;
  int index = -1;
  Edge(){}
  Edge(int from, int to, T cost): from(from), to(to), cost(cost){}
  Edge(int from, int to, T cost, int index): from(from), to(to), cost(cost), index(index){}
};

template <typename T>
struct Graph{
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
#line 4 "Mylib/DataStructure/UnionFind/unionfind.cpp"

/**
 * @title Union-find
 * @docs unionfind.md
 */
class UnionFind{
  std::vector<int> parent, depth, size;
  int count;

public:
  UnionFind(){}
  UnionFind(int n): parent(n), depth(n,1), size(n,1), count(n){
    std::iota(parent.begin(), parent.end(), 0);
  }
  
  int root_of(int i){
    if(parent[i] == i) return i;
    else return parent[i] = root_of(parent[i]);
  }
  
  bool is_same(int i, int j){return root_of(i) == root_of(j);}

  int merge(int i, int j){
    int ri = root_of(i), rj = root_of(j);
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
#line 6 "Mylib/Graph/MinimumSpanningTree/kruskal.cpp"

/**
 * @title Kruskal algorithm
 * @docs kruskal.md
 */
template <typename T>
std::vector<Edge<T>> kruskal(const Graph<T> &graph){
  int n = graph.size();
  std::vector<Edge<T>> edges;
  for(auto &v : graph){
    for(auto &e : v){
      edges.push_back(e);
    }
  }

  std::sort(edges.begin(), edges.end(), [](const auto &a, const auto &b){return a.cost < b.cost;});

  UnionFind uf(n);

  std::vector<Edge<T>> ret;

  for(auto &e : edges){
    if(!uf.is_same(e.from, e.to)){
      uf.merge(e.from, e.to);
      ret.push_back(e);
    }
  }

  return ret;
}
#line 13 "Mylib/Graph/MinimumSpanningTree/manhattan_minimum_spanning_tree.cpp"

/**
 * @title Manhattan distance MST
 * @docs manhattan_minimum_spanning_tree.md
 */
template <typename T>
std::vector<Edge<T>> manhattan_minimum_spanning_tree(std::vector<T> x, std::vector<T> y){
  const int N = x.size();
  Graph<T> g(N);
  SegmentTree<MinMonoid<std::pair<T, int>>> seg(N);
  
  auto f =
    [&](){
      std::vector<T> Y(y);
      std::sort(Y.begin(), Y.end());
      Y.erase(std::unique(Y.begin(), Y.end()), Y.end());

      seg.init(std::nullopt);

      std::vector<int> ord(N);
      std::iota(ord.begin(), ord.end(), 0);
      std::sort(
        ord.begin(), ord.end(),
        [&](int i, int j){
          if(y[i] - x[i] == y[j] - x[j]) return x[i] > x[j];
          return y[i] - x[i] < y[j] - x[j];
        }
      );

      for(int i : ord){
        int lb = std::lower_bound(Y.begin(), Y.end(), y[i]) - Y.begin();

        if(auto res = seg.get(lb, N); res){
          auto j = res->second;
          T c = std::abs(x[i] - x[j]) + std::abs(y[i] - y[j]);
          g.add_edge(i, j, c);
        }

        if(auto res = seg.at(lb); not res or x[i] + y[i] < res->first){
          seg.update(lb, {{x[i] + y[i], i}});
        }
      }
    };

  for(int i = 0; i < 2; ++i){
    for(int j = 0; j < 2; ++j){
      for(int k = 0; k < 2; ++k){
        f();
        for(int l = 0; l < N; ++l) std::swap(x[l], y[l]);
      }
      for(int l = 0; l < N; ++l) x[l] = -x[l];
    }
    for(int l = 0; l < N; ++l) y[l] = -y[l];
  }
  
  return kruskal(g);
}


```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

