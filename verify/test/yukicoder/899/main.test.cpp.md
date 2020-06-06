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
    - Last commit date: 2020-06-03 05:13:49+09:00


* see: <a href="https://yukicoder.me/problems/no/899">https://yukicoder.me/problems/no/899</a>


## Depends on

* :question: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/sum.cpp.html">Mylib/AlgebraicStructure/Monoid/sum.cpp</a>
* :x: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/update.cpp.html">Mylib/AlgebraicStructure/Monoid/update.cpp</a>
* :x: <a href="../../../../library/Mylib/AlgebraicStructure/MonoidAction/update_sum.cpp.html">Mylib/AlgebraicStructure/MonoidAction/update_sum.cpp</a>
* :question: <a href="../../../../library/Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp.html">Lazy segment tree</a>
* :x: <a href="../../../../library/Mylib/Graph/TreeUtils/euler_tour_bfs.cpp.html">Euler tour (BFS)</a>
* :question: <a href="../../../../library/Mylib/Graph/graph_template.cpp.html">Graph template</a>
* :question: <a href="../../../../library/Mylib/IO/input_graph.cpp.html">Mylib/IO/input_graph.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/899"

#include <iostream>

#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/TreeUtils/euler_tour_bfs.cpp"
#include "Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp"
#include "Mylib/AlgebraicStructure/MonoidAction/update_sum.cpp"
#include "Mylib/IO/input_graph.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N; std::cin >> N;

  auto tree = convert_to_graph<int, false>(N, input_edges<int, 0, false>(N-1));

  auto res = EulerTourBFS<int>(tree, 0);

  auto A = input_vector<int64_t>(N);
  LazySegmentTree<UpdateSum<int64_t, int64_t>> seg(N);
  
  for(int i = 0; i < N; ++i){
    res.query_at(i, [&](int l, int r){seg.update(l, r, A[i]);});
  }
    
  int Q; std::cin >> Q;
  
  for(auto [x] : input_tuples<int>(Q)){
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

#line 2 "Mylib/Graph/graph_template.cpp"
#include <vector>
#line 4 "Mylib/Graph/graph_template.cpp"

/**
 * @title Graph template
 * @docs graph_template.md
 */
template <typename Cost = int> class Edge{
public:
  int from,to;
  Cost cost;
  Edge() {}
  Edge(int to, Cost cost): to(to), cost(cost){}
  Edge(int from, int to, Cost cost): from(from), to(to), cost(cost){}
};

template <typename T> using Graph = std::vector<std::vector<Edge<T>>>;
template <typename T> using Tree = std::vector<std::vector<Edge<T>>>;

template <typename T, typename C> void add_edge(C &g, int from, int to, T w = 1){
  g[from].emplace_back(from, to, w);
}

template <typename T, typename C> void add_undirected(C &g, int a, int b, T w = 1){
  add_edge<T, C>(g, a, b, w);
  add_edge<T, C>(g, b, a, w);
}
#line 3 "Mylib/Graph/TreeUtils/euler_tour_bfs.cpp"
#include <queue>
#line 5 "Mylib/Graph/TreeUtils/euler_tour_bfs.cpp"

/**
 * @title Euler tour (BFS)
 * @docs euler_tour_bfs.md
 */
template <typename T> struct EulerTourBFS{
  int N;
  std::vector<int> parent;
  std::vector<int> depth;

  std::vector<std::vector<int>> bfs_order;
  std::vector<std::vector<int>> dfs_order;
  std::vector<int> left, right;

  EulerTourBFS(const Tree<T> &tree, int root):
    N(tree.size()), parent(N), depth(N), left(N), right(N)
  {
    {
      int ord = 0;
      dfs(tree, root, -1, 0, ord);
    }

    {
      std::queue<std::pair<int,int>> q;
      q.emplace(root, 0);
      int ord = 0;

      while(not q.empty()){
        auto [i, d] = q.front(); q.pop();

        if((int)bfs_order.size() <= d) bfs_order.push_back(std::vector<int>());
        bfs_order[d].push_back(ord);
        ++ord;

        for(auto &e : tree[i]){
          if(e.to == parent[i]) continue;
          q.emplace(e.to, d + 1);
        }
      }
    }
  }

  void dfs(const Tree<T> &tree, int cur, int par, int d, int &ord){
    parent[cur] = par;
    depth[cur] = d;

    if((int)dfs_order.size() <= d) dfs_order.push_back(std::vector<int>());
    dfs_order[d].push_back(ord);
    left[cur] = ord;
    ++ord;

    for(auto &e : tree[cur]){
      if(e.to == par) continue;
      dfs(tree, e.to, cur, d + 1, ord);
    }

    right[cur] = ord;
  }

public:
  template <typename Func>
  inline void query_children(int i, int d, const Func &f) const {
    if(i != -1){
      d += depth[i];
      if((int)bfs_order.size() > d){
        int l = std::lower_bound(dfs_order[d].begin(), dfs_order[d].end(), left[i]) - dfs_order[d].begin();
        int r = std::lower_bound(dfs_order[d].begin(), dfs_order[d].end(), right[i]) - dfs_order[d].begin();

        if(l >= (int)bfs_order[d].size()) return;
        if(r == l) return;

        f(bfs_order[d][l], bfs_order[d][r-1] + 1);
      }
    }
  }

  template <typename Func>
  inline void query_at(int i, const Func &f) const {
    query_children(i, 0, f);
  }
  
  inline int get_parent(int i) const {
    if(i == -1) return -1;
    return parent[i];
  }

  inline int get_ancestor(int i, int k) const {
    int ret = i;
    for(int i = 0; i < k; ++i){
      ret = get_parent(ret);
      if(ret == -1) break;
    }
    return ret;
  }
};
#line 3 "Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp"

/**
 * @title Lazy segment tree
 * @docs lazy_segment_tree.md
 */
template <typename Monoid>
class LazySegmentTree{
  using value_type_get = typename Monoid::value_type_get;
  using value_type_update = typename Monoid::value_type_update;
  using monoid_get = typename Monoid::monoid_get;
  using monoid_update = typename Monoid::monoid_update;
  
  const int depth, size, hsize;
  std::vector<value_type_get> data;
  std::vector<value_type_update> lazy;

  inline void propagate(int i){
    if(lazy[i] == monoid_update::id()) return;
    if(i < hsize){
      lazy[i << 1 | 0] = monoid_update::op(lazy[i], lazy[i << 1 | 0]);
      lazy[i << 1 | 1] = monoid_update::op(lazy[i], lazy[i << 1 | 1]);
    }
    int len = hsize >> (31 - __builtin_clz(i));
    data[i] = Monoid::op(data[i], lazy[i], len);
    lazy[i] = monoid_update::id();
  }

  inline value_type_get update_aux(int i, int l, int r, int s, int t, const value_type_update &x){
    propagate(i);
    if(r <= s || t <= l) return data[i];
    else if(s <= l && r <= t){
      lazy[i] = monoid_update::op(x, lazy[i]);
      propagate(i);
      return data[i];
    }
    else return data[i] = monoid_get::op(update_aux(i << 1 | 0, l, (l+r) / 2, s, t, x), update_aux(i << 1 | 1, (l+r) / 2, r, s, t, x));
  }
  
  inline value_type_get get_aux(int i, int l, int r, int x, int y){
    propagate(i);
    if(r <= x || y <= l) return monoid_get::id();
    else if(x <= l && r <= y) return data[i];
    else return monoid_get::op(get_aux(i << 1 | 0, l, (l+r) / 2, x, y), get_aux(i << 1 | 1, (l+r) / 2, r, x, y));
  }

public:
  LazySegmentTree(){}
  LazySegmentTree(int n):
    depth(n > 1 ? 32-__builtin_clz(n-1) + 1 : 1),
    size(1 << depth),
    hsize(size / 2),
    data(size, monoid_get::id()),
    lazy(size, monoid_update::id())
  {}

  inline void update(int l, int r, const value_type_update &x){update_aux(1, 0, hsize, l, r, x);}
  inline void update_at(int i, const value_type_update &x){update(i, i+1, x);}
  inline value_type_get get(int l, int r){return get_aux(1, 0, hsize, l, r);}
  inline value_type_get at(int i){return get(i, i+1);}

  template <typename T>
  inline void init(const T &val){
    init_with_vector(std::vector<T>(hsize, val));
  }

  template <typename T>
  inline void init_with_vector(const std::vector<T> &val){
    data.assign(size, monoid_get::id());
    lazy.assign(size, monoid_update::id());
    for(int i = 0; i < (int)val.size(); ++i) data[hsize + i] = val[i];
    for(int i = hsize-1; i > 0; --i) data[i] = monoid_get::op(data[i << 1 | 0], data[i << 1 | 1]);
  }
};
#line 2 "Mylib/AlgebraicStructure/Monoid/update.cpp"
#include <optional>

/**
 * @docs update.md
 */
template <typename T>
struct UpdateMonoid{
  using value_type = std::optional<T>;
  constexpr inline static value_type id(){return std::nullopt;}
  constexpr inline static value_type op(const value_type &a, const value_type &b){return (a ? a : b);}
};
#line 2 "Mylib/AlgebraicStructure/Monoid/sum.cpp"

/**
 * @docs sum.md
 */
template <typename T>
struct SumMonoid{
  using value_type = T;
  constexpr inline static value_type id(){return 0;}
  constexpr inline static value_type op(const value_type &a, const value_type &b){return a + b;}
};
#line 4 "Mylib/AlgebraicStructure/MonoidAction/update_sum.cpp"

/**
 * @docs update_sum.md
 */
template <typename T, typename U>
struct UpdateSum{
  using monoid_get = SumMonoid<T>;
  using monoid_update = UpdateMonoid<U>;
  using value_type_get = typename monoid_get::value_type;
  using value_type_update = typename monoid_update::value_type;

  constexpr inline static value_type_get op(const value_type_get &a, const value_type_update &b, int len){
    return b ? *b * len : a;
  }
};
#line 4 "Mylib/IO/input_graph.cpp"

/**
 * @docs input_graph.md
 */
template <typename T, size_t I, bool WEIGHTED>
std::vector<Edge<T>> input_edges(int M){
  std::vector<Edge<T>> ret;
  
  for(int i = 0; i < M; ++i){
    int s, t; std::cin >> s >> t;
    s -= I;
    t -= I;
    T w = 1; if(WEIGHTED) std::cin >> w;
    ret.emplace_back(s, t, w);
  }
  
  return ret;  
}

template <typename T, bool DIRECTED>
Graph<T> convert_to_graph(int N, const std::vector<Edge<T>> &edges){
  Graph<T> g(N);

  for(const auto &e : edges){
    add_edge(g, e.from, e.to, e.cost);
    if(not DIRECTED) add_edge(g, e.to, e.from, e.cost);
  }
  
  return g;
}
#line 4 "Mylib/IO/input_vector.cpp"

/**
 * @docs input_vector.md
 */
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
#line 4 "Mylib/IO/input_tuples.cpp"
#include <tuple>
#include <utility>
#include <initializer_list>
#line 5 "Mylib/IO/input_tuple.cpp"
#include <initializer_list>

/**
 * @docs input_tuple.md
 */
template <typename T, size_t ... I>
static void input_tuple_helper(std::istream &s, T &val, std::index_sequence<I...>){
  (void)std::initializer_list<int>{(void(s >> std::get<I>(val)), 0)...};
}

template <typename T, typename U>
std::istream& operator>>(std::istream &s, std::pair<T, U> &value){
  s >> value.first >> value.second;
  return s;
}

template <typename ... Args>
std::istream& operator>>(std::istream &s, std::tuple<Args...> &value){
  input_tuple_helper(s, value, std::make_index_sequence<sizeof...(Args)>());
  return s;
}
#line 8 "Mylib/IO/input_tuples.cpp"

/**
 * @docs input_tuples.md
 */
template <typename ... Args>
class InputTuples{
  struct iter{
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
#line 12 "test/yukicoder/899/main.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N; std::cin >> N;

  auto tree = convert_to_graph<int, false>(N, input_edges<int, 0, false>(N-1));

  auto res = EulerTourBFS<int>(tree, 0);

  auto A = input_vector<int64_t>(N);
  LazySegmentTree<UpdateSum<int64_t, int64_t>> seg(N);
  
  for(int i = 0; i < N; ++i){
    res.query_at(i, [&](int l, int r){seg.update(l, r, A[i]);});
  }
    
  int Q; std::cin >> Q;
  
  for(auto [x] : input_tuples<int>(Q)){
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

