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


# :x: Manhattan distance MST

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#cb5ed95d97b7ee8efcbdf177a47dc7b7">Mylib/Graph/MinimumSpanningTree</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/MinimumSpanningTree/manhattan_minimum_spanning_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-12 11:23:53+09:00




## Operations

## Requirements

## Notes

## Problems

## References

- [https://knuu.github.io/manhattan_mst.html](https://knuu.github.io/manhattan_mst.html)


## Depends on

* :question: <a href="../../AlgebraicStructure/Monoid/min.cpp.html">Min monoid</a>
* :question: <a href="../../DataStructure/SegmentTree/segment_tree.cpp.html">Segment tree</a>
* :question: <a href="../../DataStructure/UnionFind/unionfind.cpp.html">Union-find</a>
* :x: <a href="kruskal.cpp.html">Kruskal algorithm</a>
* :question: <a href="../Template/graph.cpp.html">Basic graph</a>


## Verified with

* :x: <a href="../../../../verify/test/yosupo-judge/manhattanmst/main.test.cpp.html">test/yosupo-judge/manhattanmst/main.test.cpp</a>


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
namespace haar_lib {
  template <typename T>
  std::vector<edge<T>> manhattan_minimum_spanning_tree(std::vector<T> x, std::vector<T> y){
    const int N = x.size();
    graph<T> g(N);
    segment_tree<min_monoid<std::pair<T, int>>> seg(N);

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

          if(auto res = seg[lb]; not res or x[i] + y[i] < res->first){
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
 * @title Min monoid
 * @docs min.md
 */
namespace haar_lib {
  template <typename T>
  struct min_monoid {
    using value_type = std::optional<T>;

    value_type operator()() const {return {};}
    value_type operator()(const value_type &a, const value_type &b) const {
      if(not a) return b;
      if(not b) return a;
      return {std::min(*a, *b)};
    }
  };
}
#line 4 "Mylib/DataStructure/SegmentTree/segment_tree.cpp"
#include <functional>

/**
 * @title Segment tree
 * @docs segment_tree.md
 */
namespace haar_lib {
  template <typename Monoid>
  class segment_tree {
    using value_type = typename Monoid::value_type;
    const static Monoid M;

    int depth, size, hsize;
    std::vector<value_type> data;

  public:
    segment_tree(){}
    segment_tree(int n):
      depth(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),
      size(1 << depth), hsize(size / 2),
      data(size, M())
    {}

    auto operator[](int i) const {return data[hsize + i];}

    auto get(int x, int y) const {
      value_type ret_left = M();
      value_type ret_right = M();

      int l = x + hsize, r = y + hsize;
      while(l < r){
        if(r & 1) ret_right = M(data[--r], ret_right);
        if(l & 1) ret_left = M(ret_left, data[l++]);
        l >>= 1, r >>= 1;
      }

      return M(ret_left, ret_right);
    }

    void update(int i, const value_type &x){
      i += hsize;
      data[i] = x;
      while(i > 1) i >>= 1, data[i] = M(data[i << 1 | 0], data[i << 1 | 1]);
    }

    template <typename T>
    void init_with_vector(const std::vector<T> &val){
      data.assign(size, M());
      for(int i = 0; i < (int)val.size(); ++i) data[hsize + i] = val[i];
      for(int i = hsize - 1; i >= 1; --i) data[i] = M(data[i << 1 | 0], data[i << 1 | 1]);
    }

    template <typename T>
    void init(const T &val){
      init_with_vector(std::vector<value_type>(hsize, val));
    }

  private:
    template <bool Lower, typename F>
    int bound(const int l, const int r, value_type x, F f) const {
      std::vector<int> pl, pr;
      int L = l + hsize;
      int R = r + hsize;
      while(L < R){
        if(R & 1) pr.push_back(--R);
        if(L & 1) pl.push_back(L++);
        L >>= 1, R >>= 1;
      }

      std::reverse(pr.begin(), pr.end());
      pl.insert(pl.end(), pr.begin(), pr.end());

      value_type a = M();

      for(int i : pl){
        auto b = M(a, data[i]);

        if((Lower and not f(b, x)) or (not Lower and f(x, b))){
          while(i < hsize){
            if(auto c = M(a, data[i << 1 | 0]); (Lower and not f(c, x)) or (not Lower and f(x, c))){
              i = i << 1 | 0;
            }else{
              a = c;
              i = i << 1 | 1;
            }
          }

          return i - hsize;
        }

        a = b;
      }

      return r;
    }

  public:
    template <typename F = std::less<value_type>>
    int lower_bound(int l, int r, value_type x, F f = F()) const {
      return bound<true>(l, r, x, f);
    }

    template <typename F = std::less<value_type>>
    int upper_bound(int l, int r, value_type x, F f = F()) const {
      return bound<false>(l, r, x, f);
    }
  };
}
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
#line 5 "Mylib/DataStructure/UnionFind/unionfind.cpp"

/**
 * @title Union-find
 * @docs unionfind.md
 */
namespace haar_lib {
  class unionfind {
    int n;
    mutable std::vector<int> parent;
    std::vector<int> depth, size;
    int count;

  public:
    unionfind(){}
    unionfind(int n): n(n), parent(n), depth(n, 1), size(n, 1), count(n){
      std::iota(parent.begin(), parent.end(), 0);
    }

    int root_of(int i) const {
      if(parent[i] == i) return i;
      else return parent[i] = root_of(parent[i]);
    }

    bool is_same(int i, int j) const {return root_of(i) == root_of(j);}

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

    int size_of(int i) const {return size[root_of(i)];}

    int count_groups() const {return count;}

    auto get_groups() const {
      std::vector<std::vector<int>> ret(n);

      for(int i = 0; i < n; ++i){
        ret[root_of(i)].push_back(i);
      }

      ret.erase(
        std::remove_if(
          ret.begin(), ret.end(),
          [](const auto &a){return a.empty();}
        ),
        ret.end()
      );

      return ret;
    }
  };
}
#line 6 "Mylib/Graph/MinimumSpanningTree/kruskal.cpp"

/**
 * @title Kruskal algorithm
 * @docs kruskal.md
 */
namespace haar_lib {
  template <typename T>
  std::vector<edge<T>> kruskal(const graph<T> &graph){
    const int n = graph.size();
    std::vector<edge<T>> edges;
    for(auto &v : graph){
      for(auto &e : v){
        edges.push_back(e);
      }
    }

    std::sort(edges.begin(), edges.end(), [](const auto &a, const auto &b){return a.cost < b.cost;});

    unionfind uf(n);

    std::vector<edge<T>> ret;

    for(auto &e : edges){
      if(!uf.is_same(e.from, e.to)){
        uf.merge(e.from, e.to);
        ret.push_back(e);
      }
    }

    return ret;
  }
}
#line 11 "Mylib/Graph/MinimumSpanningTree/manhattan_minimum_spanning_tree.cpp"

/**
 * @title Manhattan distance MST
 * @docs manhattan_minimum_spanning_tree.md
 */
namespace haar_lib {
  template <typename T>
  std::vector<edge<T>> manhattan_minimum_spanning_tree(std::vector<T> x, std::vector<T> y){
    const int N = x.size();
    graph<T> g(N);
    segment_tree<min_monoid<std::pair<T, int>>> seg(N);

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

          if(auto res = seg[lb]; not res or x[i] + y[i] < res->first){
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
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

