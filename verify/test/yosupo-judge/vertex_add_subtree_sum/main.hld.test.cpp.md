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


# :x: test/yosupo-judge/vertex_add_subtree_sum/main.hld.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#5182f60ed9f69992a8eee7b8b1003f24">test/yosupo-judge/vertex_add_subtree_sum</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/vertex_add_subtree_sum/main.hld.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-12 11:23:53+09:00


* see: <a href="https://judge.yosupo.jp/problem/vertex_add_subtree_sum">https://judge.yosupo.jp/problem/vertex_add_subtree_sum</a>


## Depends on

* :x: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/sum.cpp.html">Sum monoid</a>
* :question: <a href="../../../../library/Mylib/DataStructure/SegmentTree/segment_tree.cpp.html">Segment tree</a>
* :question: <a href="../../../../library/Mylib/Graph/Template/graph.cpp.html">Basic graph</a>
* :question: <a href="../../../../library/Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp.html">Heavy-light decomposition</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include <iostream>
#include <vector>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp"
#include "Mylib/DataStructure/SegmentTree/segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;

  auto a = hl::input_vector<int64_t>(N);

  hl::tree<int> tree(N);
  for(int i = 1; i < N; ++i){
    int p; std::cin >> p;
    tree.add_edge(p, i, 1);
  }

  auto seg = hl::segment_tree<hl::sum_monoid<int64_t>>(N);
  auto hld = hl::hl_decomposition(tree, 0);

  for(int i = 0; i < N; ++i){
    seg.update(hld.get_id(i), a[i]);
  }

  for(auto [t, u] : hl::input_tuples<int, int>(Q)){
    if(t == 0){
      int x; std::cin >> x;

      int i = hld.get_id(u);
      seg.update(i, seg[i] + x);
    }else{
      int64_t ans = 0;
      hld.subtree_query_vertex(
        u,
        [&](int l, int r){
          ans += seg.get(l, r);
        }
      );

      std::cout << ans << "\n";
    }
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/vertex_add_subtree_sum/main.hld.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include <iostream>
#include <vector>
#line 4 "Mylib/Graph/Template/graph.cpp"

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
#line 3 "Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp"
#include <utility>
#include <algorithm>
#line 6 "Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp"

/**
 * @title Heavy-light decomposition
 * @docs heavy_light_decomposition.md
 */
namespace haar_lib {
  template <typename T>
  class hl_decomposition {
    int n;

    std::vector<int> sub, // subtree size
      par, // parent id
      head, // chain head id
      id, // id[original id] = hld id
      rid, // rid[hld id] = original id
      next, // next node in a chain
      end; //

    int dfs_sub(tree<T> &tr, int cur, int p){
      par[cur] = p;
      int t = 0;
      for(auto &e : tr[cur]){
        if(e.to == p) continue;
        sub[cur] += dfs_sub(tr, e.to, cur);
        if(sub[e.to] > t){
          t = sub[e.to];
          next[cur] = e.to;
          std::swap(e, tr[cur][0]);
        }
      }
      return sub[cur];
    }

    void dfs_build(const tree<T> &tr, int cur, int &i){
      id[cur] = i;
      rid[i] = cur;
      ++i;

      for(auto &e : tr[cur]){
        if(e.to == par[cur]) continue;
        head[e.to] = (e.to == tr[cur][0].to ? head[cur] : e.to);
        dfs_build(tr, e.to, i);
      }

      end[cur] = i;
    }

  public:
    hl_decomposition(tree<T> tr, int root):
      n(tr.size()), sub(n, 1), par(n, -1), head(n), id(n), rid(n), next(n, -1), end(n, -1){
      dfs_sub(tr, root, -1);
      int i = 0;
      dfs_build(tr, root, i);
    }

    template <typename Func> // std::function<void(int, int)>
    void path_query_vertex(int x, int y, const Func &f) const {
      while(1){
        if(id[x] > id[y]) std::swap(x, y);
        f(std::max(id[head[y]], id[x]), id[y] + 1);
        if(head[x] == head[y]) return;
        y = par[head[y]];
      }
    }

    template <typename LeftFunc, typename RightFunc>
    void path_query_vertex(int x, int y, const LeftFunc &f, const RightFunc &g) const {
      const int w = lca(x, y);

      path_query_vertex(x, w, f);

      x = y;
      y = w;

      while(1){
        if(id[x] > id[y]){
          std::swap(x, y);
        }
        g(std::max({id[head[y]], id[x], id[w] + 1}), id[y] + 1);
        if(head[x] == head[y]) return;
        y = par[head[y]];
      }
    }

    template <typename Func> // std::function<void(int, int)>
    void path_query_edge(int x, int y, const Func &f) const {
      while(1){
        if(id[x] > id[y]) std::swap(x, y);
        if(head[x] == head[y]){
          if(x != y) f(id[x] + 1, id[y] + 1);
          return;
        }
        f(id[head[y]], id[y] + 1);
        y = par[head[y]];
      }
    }

    template <typename Func> // std::function<void(int, int)>
    void subtree_query_edge(int x, const Func &f) const {
      f(id[x] + 1, end[x]);
    }

    template <typename Func> // std::function<void(int, int)>
    void subtree_query_vertex(int x, const Func &f) const {
      f(id[x], end[x]);
    }

    int get_edge_id(int u, int v) const { // 辺に対応するid
      if(par[u] == v){
        return id[u];
      }else if(par[v] == u){
        return id[v];
      }

      return -1;
    }

    int parent(int x) const {return par[x];};

    int lca(int u, int v) const {
      while(1){
        if(id[u] > id[v]) std::swap(u, v);
        if(head[u] == head[v]) return u;
        v = par[head[v]];
      }
    }

    int get_id(int x) const {
      return id[x];
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
#line 2 "Mylib/AlgebraicStructure/Monoid/sum.cpp"

/**
 * @title Sum monoid
 * @docs sum.md
 */
namespace haar_lib {
  template <typename T>
  struct sum_monoid {
    using value_type = T;
    value_type operator()() const {return 0;}
    value_type operator()(value_type a, value_type b) const {return a + b;}
  };
}
#line 4 "Mylib/IO/input_vector.cpp"

/**
 * @docs input_vector.md
 */
namespace haar_lib {
  template <typename T>
  std::vector<T> input_vector(int N){
    std::vector<T> ret(N);
    for(int i = 0; i < N; ++i) std::cin >> ret[i];
    return ret;
  }

  template <typename T>
  std::vector<std::vector<T>> input_vector(int N, int M){
    std::vector<std::vector<T>> ret(N);
    for(int i = 0; i < N; ++i) ret[i] = input_vector<T>(M);
    return ret;
  }
}
#line 4 "Mylib/IO/input_tuples.cpp"
#include <tuple>
#line 6 "Mylib/IO/input_tuples.cpp"
#include <initializer_list>
#line 6 "Mylib/IO/input_tuple.cpp"

/**
 * @docs input_tuple.md
 */
namespace haar_lib {
  template <typename T, size_t ... I>
  static void input_tuple_helper(std::istream &s, T &val, std::index_sequence<I ...>){
    (void)std::initializer_list<int>{(void(s >> std::get<I>(val)), 0) ...};
  }

  template <typename T, typename U>
  std::istream& operator>>(std::istream &s, std::pair<T, U> &value){
    s >> value.first >> value.second;
    return s;
  }

  template <typename ... Args>
  std::istream& operator>>(std::istream &s, std::tuple<Args ...> &value){
    input_tuple_helper(s, value, std::make_index_sequence<sizeof ... (Args)>());
    return s;
  }
}
#line 8 "Mylib/IO/input_tuples.cpp"

/**
 * @docs input_tuples.md
 */
namespace haar_lib {
  template <typename ... Args>
  class InputTuples {
    struct iter {
      using value_type = std::tuple<Args ...>;
      value_type value;
      bool fetched = false;
      int N, c = 0;

      value_type operator*(){
        if(not fetched){
          std::cin >> value;
        }
        return value;
      }

      void operator++(){
        ++c;
        fetched = false;
      }

      bool operator!=(iter &) const {
        return c < N;
      }

      iter(int N): N(N){}
    };

    int N;

  public:
    InputTuples(int N): N(N){}

    iter begin() const {return iter(N);}
    iter end() const {return iter(N);}
  };

  template <typename ... Args>
  auto input_tuples(int N){
    return InputTuples<Args ...>(N);
  }
}
#line 11 "test/yosupo-judge/vertex_add_subtree_sum/main.hld.test.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;

  auto a = hl::input_vector<int64_t>(N);

  hl::tree<int> tree(N);
  for(int i = 1; i < N; ++i){
    int p; std::cin >> p;
    tree.add_edge(p, i, 1);
  }

  auto seg = hl::segment_tree<hl::sum_monoid<int64_t>>(N);
  auto hld = hl::hl_decomposition(tree, 0);

  for(int i = 0; i < N; ++i){
    seg.update(hld.get_id(i), a[i]);
  }

  for(auto [t, u] : hl::input_tuples<int, int>(Q)){
    if(t == 0){
      int x; std::cin >> x;

      int i = hld.get_id(u);
      seg.update(i, seg[i] + x);
    }else{
      int64_t ans = 0;
      hld.subtree_query_vertex(
        u,
        [&](int l, int r){
          ans += seg.get(l, r);
        }
      );

      std::cout << ans << "\n";
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

