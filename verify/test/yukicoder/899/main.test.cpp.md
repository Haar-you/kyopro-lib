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


# :x: test/yukicoder/899/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#dbd13c44c1e9ae40565e636bcb62bc45">test/yukicoder/899</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yukicoder/899/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00


* see: <a href="https://yukicoder.me/problems/no/899">https://yukicoder.me/problems/no/899</a>


## Depends on

* :x: <a href="../../../../library/Mylib/AlgebraicStructure/MonoidAction/update_sum.cpp.html">Range update / Range sum</a>
* :question: <a href="../../../../library/Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp.html">Lazy segment tree</a>
* :question: <a href="../../../../library/Mylib/Graph/Template/graph.cpp.html">Basic graph</a>
* :x: <a href="../../../../library/Mylib/Graph/TreeUtils/euler_tour_bfs.cpp.html">Euler tour (BFS)</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/899"

#include <iostream>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/TreeUtils/euler_tour_bfs.cpp"
#include "Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp"
#include "Mylib/AlgebraicStructure/MonoidAction/update_sum.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N; std::cin >> N;

  hl::tree<int> tree(N);
  tree.read<0, false, false>(N - 1);

  auto res = hl::euler_tour_bfs<int>(tree, 0);

  auto A = hl::input_vector<int64_t>(N);
  hl::lazy_segment_tree<hl::update_sum<int64_t, int64_t>> seg(N);

  for(int i = 0; i < N; ++i){
    res.query_at(i, [&](int l, int r){seg.update(l, r, A[i]);});
  }

  int Q; std::cin >> Q;

  for(auto [x] : hl::input_tuples<int>(Q)){
    int64_t ans = 0;

    auto f =
      [&](int l, int r){
        ans += seg.get(l, r);
        seg.update(l, r, 0);
      };

    // 親の親
    res.query_at(res.get_ancestor(x, 2), f);

    // 親
    res.query_at(res.get_ancestor(x, 1), f);

    // 親の子
    res.query_children(res.get_parent(x), 1, f);

    // 自分
    res.query_at(x, f);

    // 子
    res.query_children(x, 1, f);

    // 子の子
    res.query_children(x, 2, f);

    res.query_at(
      x,
      [&](int l, int r){
        seg.update(l, r, ans);
      }
    );

    std::cout << ans << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yukicoder/899/main.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/899"

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
#line 3 "Mylib/Graph/TreeUtils/euler_tour_bfs.cpp"
#include <queue>
#line 5 "Mylib/Graph/TreeUtils/euler_tour_bfs.cpp"

/**
 * @title Euler tour (BFS)
 * @docs euler_tour_bfs.md
 */
namespace haar_lib {
  template <typename T>
  struct euler_tour_bfs {
    int N;
    std::vector<int> parent;
    std::vector<int> depth;

    std::vector<std::vector<int>> bfs_order;
    std::vector<std::vector<int>> dfs_order;
    std::vector<int> left, right;

    euler_tour_bfs(const tree<T> &tr, int root):
      N(tr.size()), parent(N), depth(N), left(N), right(N)
    {
      {
        int ord = 0;
        dfs(tr, root, -1, 0, ord);
      }

      {
        std::queue<std::pair<int, int>> q;
        q.emplace(root, 0);
        int ord = 0;

        while(not q.empty()){
          auto [i, d] = q.front(); q.pop();

          if((int)bfs_order.size() <= d) bfs_order.emplace_back();
          bfs_order[d].push_back(ord);
          ++ord;

          for(auto &e : tr[i]){
            if(e.to == parent[i]) continue;
            q.emplace(e.to, d + 1);
          }
        }
      }
    }

    void dfs(const tree<T> &tr, int cur, int par, int d, int &ord){
      parent[cur] = par;
      depth[cur] = d;

      if((int)dfs_order.size() <= d) dfs_order.emplace_back();
      dfs_order[d].push_back(ord);
      left[cur] = ord;
      ++ord;

      for(auto &e : tr[cur]){
        if(e.to == par) continue;
        dfs(tr, e.to, cur, d + 1, ord);
      }

      right[cur] = ord;
    }

  public:
    template <typename Func>
    void query_children(int i, int d, const Func &f) const {
      if(i != -1){
        d += depth[i];
        if((int)bfs_order.size() > d){
          int l = std::lower_bound(dfs_order[d].begin(), dfs_order[d].end(), left[i]) - dfs_order[d].begin();
          int r = std::lower_bound(dfs_order[d].begin(), dfs_order[d].end(), right[i]) - dfs_order[d].begin();

          if(l >= (int)bfs_order[d].size()) return;
          if(r == l) return;

          f(bfs_order[d][l], bfs_order[d][r - 1] + 1);
        }
      }
    }

    template <typename Func>
    void query_at(int i, const Func &f) const {
      query_children(i, 0, f);
    }

    int get_parent(int i) const {
      if(i == -1) return -1;
      return parent[i];
    }

    int get_ancestor(int i, int k) const {
      int ret = i;
      for(int i = 0; i < k; ++i){
        ret = get_parent(ret);
        if(ret == -1) break;
      }
      return ret;
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
#line 2 "Mylib/AlgebraicStructure/MonoidAction/update_sum.cpp"
#include <optional>

/**
 * @title Range update / Range sum
 * @docs update_sum.md
 */
namespace haar_lib {
  template <typename T, typename U>
  struct update_sum {
    using value_type_get = T;
    using value_type_update = std::optional<U>;

    value_type_get id_get() const {return 0;}
    value_type_update id_update() const {return {};}

    value_type_get op_get(value_type_get a, value_type_get b) const {return a + b;}
    value_type_update op_update(value_type_update a, value_type_update b) const {return (a ? a : b);}

    value_type_get op(value_type_get a, value_type_update b, int len) const {
      return b ? *b * len : a;
    }
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
#include <utility>
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
#line 10 "test/yukicoder/899/main.test.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N; std::cin >> N;

  hl::tree<int> tree(N);
  tree.read<0, false, false>(N - 1);

  auto res = hl::euler_tour_bfs<int>(tree, 0);

  auto A = hl::input_vector<int64_t>(N);
  hl::lazy_segment_tree<hl::update_sum<int64_t, int64_t>> seg(N);

  for(int i = 0; i < N; ++i){
    res.query_at(i, [&](int l, int r){seg.update(l, r, A[i]);});
  }

  int Q; std::cin >> Q;

  for(auto [x] : hl::input_tuples<int>(Q)){
    int64_t ans = 0;

    auto f =
      [&](int l, int r){
        ans += seg.get(l, r);
        seg.update(l, r, 0);
      };

    // 親の親
    res.query_at(res.get_ancestor(x, 2), f);

    // 親
    res.query_at(res.get_ancestor(x, 1), f);

    // 親の子
    res.query_children(res.get_parent(x), 1, f);

    // 自分
    res.query_at(x, f);

    // 子
    res.query_children(x, 1, f);

    // 子の子
    res.query_children(x, 2, f);

    res.query_at(
      x,
      [&](int l, int r){
        seg.update(l, r, ans);
      }
    );

    std::cout << ans << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
