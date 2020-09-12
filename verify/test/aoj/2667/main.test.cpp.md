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


# :heavy_check_mark: test/aoj/2667/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#f80441644c784d0a46b75e1972ebee8e">test/aoj/2667</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/2667/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667</a>


## Depends on

* :question: <a href="../../../../library/Mylib/AlgebraicStructure/MonoidAction/add_sum.cpp.html">Range add / Range sum</a>
* :question: <a href="../../../../library/Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp.html">Lazy segment tree</a>
* :question: <a href="../../../../library/Mylib/Graph/Template/graph.cpp.html">Basic graph</a>
* :question: <a href="../../../../library/Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp.html">Heavy-light decomposition</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667"

#include <iostream>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp"
#include "Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp"
#include "Mylib/AlgebraicStructure/MonoidAction/add_sum.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main(){
  int N, Q; std::cin >> N >> Q;

  hl::tree<int> tree(N);
  tree.read<0, false, false>(N - 1);

  auto hld = hl::hl_decomposition(tree, 0);
  hl::lazy_segment_tree<hl::add_sum<int64_t, int64_t>> seg(N);

  for(auto [c] : hl::input_tuples<int>(Q)){
    if(c == 0){
      int u, v; std::cin >> u >> v;

      int64_t ans = 0;
      hld.path_query_edge(
        u, v,
        [&](int l, int r){
          ans += seg.get(l, r);
        }
      );
      std::cout << ans << std::endl;
    }else{
      int v, x; std::cin >> v >> x;

      hld.subtree_query_edge(
        v,
        [&](int l, int r){
          seg.update(l, r, x);
        }
      );
    }
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/2667/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667"

#include <iostream>
#line 2 "Mylib/Graph/Template/graph.cpp"
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
#line 3 "Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp"

/**
 * @title Lazy segment tree
 * @docs lazy_segment_tree.md
 */
namespace haar_lib {
  template <typename Monoid>
  class lazy_segment_tree {
    using value_type_get = typename Monoid::value_type_get;
    using value_type_update = typename Monoid::value_type_update;
    const static Monoid M;

    const int depth, size, hsize;
    std::vector<value_type_get> data;
    std::vector<value_type_update> lazy;

    void propagate(int i){
      if(lazy[i] == M.id_update()) return;
      if(i < hsize){
        lazy[i << 1 | 0] = M.op_update(lazy[i], lazy[i << 1 | 0]);
        lazy[i << 1 | 1] = M.op_update(lazy[i], lazy[i << 1 | 1]);
      }
      int len = hsize >> (31 - __builtin_clz(i));
      data[i] = M.op(data[i], lazy[i], len);
      lazy[i] = M.id_update();
    }

    value_type_get update_aux(int i, int l, int r, int s, int t, const value_type_update &x){
      propagate(i);
      if(r <= s || t <= l) return data[i];
      else if(s <= l && r <= t){
        lazy[i] = M.op_update(x, lazy[i]);
        propagate(i);
        return data[i];
      }
      else return data[i] = M.op_get(update_aux(i << 1 | 0, l, (l + r) / 2, s, t, x), update_aux(i << 1 | 1, (l + r) / 2, r, s, t, x));
    }

    value_type_get get_aux(int i, int l, int r, int x, int y){
      propagate(i);
      if(r <= x || y <= l) return M.id_get();
      else if(x <= l && r <= y) return data[i];
      else return M.op_get(get_aux(i << 1 | 0, l, (l + r) / 2, x, y), get_aux(i << 1 | 1, (l + r) / 2, r, x, y));
    }

  public:
    lazy_segment_tree(){}
    lazy_segment_tree(int n):
      depth(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),
      size(1 << depth),
      hsize(size / 2),
      data(size, M.id_get()),
      lazy(size, M.id_update())
    {}

    void update(int l, int r, const value_type_update &x){update_aux(1, 0, hsize, l, r, x);}
    void update_at(int i, const value_type_update &x){update(i, i + 1, x);}
    value_type_get get(int l, int r){return get_aux(1, 0, hsize, l, r);}
    value_type_get operator[](int i){return get(i, i + 1);}

    template <typename T>
    void init(const T &val){
      init_with_vector(std::vector<T>(hsize, val));
    }

    template <typename T>
    void init_with_vector(const std::vector<T> &val){
      data.assign(size, M.id_get());
      lazy.assign(size, M.id_update());
      for(int i = 0; i < (int)val.size(); ++i) data[hsize + i] = val[i];
      for(int i = hsize - 1; i > 0; --i) data[i] = M.op_get(data[i << 1 | 0], data[i << 1 | 1]);
    }
  };
}
#line 2 "Mylib/AlgebraicStructure/MonoidAction/add_sum.cpp"

/**
 * @title Range add / Range sum
 * @docs add_sum.md
 */
namespace haar_lib {
  template <typename T, typename U>
  struct add_sum {
    using value_type_get = T;
    using value_type_update = U;

    value_type_get id_get() const {return 0;}
    value_type_update id_update() const {return 0;}

    value_type_get op_get(value_type_get a, value_type_get b) const {return a + b;}
    value_type_update op_update(value_type_update a, value_type_update b) const {return a + b;}

    value_type_get op(value_type_get a, value_type_update b, int len) const {
      return a + b * len;
    }
  };
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
#line 9 "test/aoj/2667/main.test.cpp"

namespace hl = haar_lib;

int main(){
  int N, Q; std::cin >> N >> Q;

  hl::tree<int> tree(N);
  tree.read<0, false, false>(N - 1);

  auto hld = hl::hl_decomposition(tree, 0);
  hl::lazy_segment_tree<hl::add_sum<int64_t, int64_t>> seg(N);

  for(auto [c] : hl::input_tuples<int>(Q)){
    if(c == 0){
      int u, v; std::cin >> u >> v;

      int64_t ans = 0;
      hld.path_query_edge(
        u, v,
        [&](int l, int r){
          ans += seg.get(l, r);
        }
      );
      std::cout << ans << std::endl;
    }else{
      int v, x; std::cin >> v >> x;

      hld.subtree_query_edge(
        v,
        [&](int l, int r){
          seg.update(l, r, x);
        }
      );
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

