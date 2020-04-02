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
    - Last commit date: 2020-04-02 16:54:34+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667</a>


## Depends on

* :question: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/sum_monoid.cpp.html">Mylib/AlgebraicStructure/Monoid/sum_monoid.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/AlgebraicStructure/MonoidAction/add_sum.cpp.html">Mylib/AlgebraicStructure/MonoidAction/add_sum.cpp</a>
* :question: <a href="../../../../library/Mylib/DataStructure/SegmentTree/Static/Lazy/lazy_segment_tree.cpp.html">遅延セグメント木</a>
* :question: <a href="../../../../library/Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp.html">重軽分解</a>
* :question: <a href="../../../../library/Mylib/Graph/graph_template.cpp.html">Mylib/Graph/graph_template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp"
#include "Mylib/DataStructure/SegmentTree/Static/Lazy/lazy_segment_tree.cpp"
#include "Mylib/AlgebraicStructure/MonoidAction/add_sum.cpp"

int main(){
  int N, Q; std::cin >> N >> Q;
  
  Tree<int> tree(N);
  for(int i = 0; i < N-1; ++i){
    int a, b; std::cin >> a >> b;
    add_undirected(tree, a, b, 1);
  }
  
  auto hld = HLDecomposition(tree, 0);
  LazySegmentTree<AddSum<int64_t,int64_t>> seg(N);
  
  while(Q--){
    int c; std::cin >> c;
    
    if(c == 0){
      int u, v; std::cin >> u >> v;
      
      int64_t ans = 0;
      hld.path_query_edge(u, v, [&](int l, int r){ans += seg.get(l, r);});
      std::cout << ans << std::endl;
    }else{
      int v, x; std::cin >> v >> x;
      
      hld.subtree_query_edge(v, [&](int l, int r){seg.update(l, r, x);});
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
#line 2 "Mylib/Graph/graph_template.cpp"
#include <vector>
#line 4 "Mylib/Graph/graph_template.cpp"

template <typename Cost = int> class Edge{
public:
  int from,to;
  Cost cost;
  Edge() {}
  Edge(int to, Cost cost): to(to), cost(cost){}
  Edge(int from, int to, Cost cost): from(from), to(to), cost(cost){}

  Edge rev() const {return Edge(to,from,cost);}
  
  friend std::ostream& operator<<(std::ostream &os, const Edge &e){
    os << "(FROM: " << e.from << "," << "TO: " << e.to << "," << "COST: " << e.cost << ")";
    return os;
  }
};

template <typename T> using Graph = std::vector<std::vector<Edge<T>>>;
template <typename T> using Tree = std::vector<std::vector<Edge<T>>>;

template <typename C, typename T> void add_edge(C &g, int from, int to, T w){
  g[from].emplace_back(from, to, w);
}

template <typename C, typename T> void add_undirected(C &g, int a, int b, T w){
  add_edge(g, a, b, w);
  add_edge(g, b, a, w);
}
#line 3 "Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp"
#include <utility>
#include <algorithm>
#line 6 "Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp"

/**
 * @title 重軽分解
 * @see https://yukicoder.me/submissions/320138 (パスに対する頂点クエリ)
 * @see https://atcoder.jp/contests/cf16-tournament-round1-open/submissions/6875967 (パスに対する辺クエリ)
 * @see http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667 (パス・部分木に対する辺クエリ)
 * @see https://codeforces.com/contest/593/submission/58692123 (パスに対する辺クエリ)
 * @see https://yukicoder.me/submissions/377852 (パスに対する辺クエリ)
 * @see https://codeforces.com/contest/343/submission/61314485 (パス・部分木に対する頂点クエリ)
 */
template <typename T> class HLDecomposition{
  Tree<T> tree;
  int n;
  
  std::vector<int> sub, // subtree size
    par, // parent id
    head, // chain head id 
    id, // id[original id] = hld id
    rid, // rid[hld id] = original id
    next, // next node in a chain
    end; // 

  int dfs_sub(int cur, int p){
    par[cur] = p;
    int t = 0;
    for(auto &e : tree[cur]){
      if(e.to == p) continue;
      sub[cur] += dfs_sub(e.to, cur);
      if(sub[e.to] > t){
        t = sub[e.to];
        next[cur] = e.to;
        std::swap(e, tree[cur][0]);
      }
    }
    return sub[cur];
  }

  void dfs_build(int cur, int &i){
    id[cur] = i;
    rid[i] = cur;
    ++i;

    for(auto &e : tree[cur]){
      if(e.to == par[cur]) continue;
      head[e.to] = (e.to == tree[cur][0].to ? head[cur] : e.to);
      dfs_build(e.to, i);
    }

    end[cur] = i;
  }
  

public:
  HLDecomposition(const Tree<T> &tree, int root):
    tree(tree), n(tree.size()), sub(n,1), par(n,-1), head(n), id(n), rid(n), next(n,-1), end(n,-1){
    dfs_sub(root, -1);
    int i = 0;
    dfs_build(root, i);
  }

  template <typename Func> // std::function<void(int,int)>
  void path_query_vertex(int x, int y, const Func &f) const {
    while(1){
      if(id[x] > id[y]) std::swap(x, y);
      f(std::max(id[head[y]], id[x]), id[y]+1);
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
      g(std::max({id[head[y]], id[x], id[w]+1}), id[y]+1);
      if(head[x] == head[y]) return;
      y = par[head[y]];
    }
  }

  template <typename Func> // std::function<void(int,int)>
  void path_query_edge(int x, int y, const Func &f) const {
    while(1){
      if(id[x] > id[y]) std::swap(x, y);
      if(head[x] == head[y]){
        if(x != y) f(id[x]+1, id[y]+1);
        return;
      }
      f(id[head[y]], id[y]+1);
      y = par[head[y]];
    }
  }
  
  template <typename Func> // std::function<void(int,int)>
  void subtree_query_edge(int x, const Func &f) const {
    f(id[x]+1, end[x]);
  }

  template <typename Func> // std::function<void(int,int)>
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
#line 3 "Mylib/DataStructure/SegmentTree/Static/Lazy/lazy_segment_tree.cpp"

/**
 * @title 遅延セグメント木
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
#line 2 "Mylib/AlgebraicStructure/Monoid/sum_monoid.cpp"

template <typename T>
struct SumMonoid{
  using value_type = T;
  constexpr inline static value_type id(){return 0;}
  constexpr inline static value_type op(const value_type &a, const value_type &b){return a + b;}
};
#line 3 "Mylib/AlgebraicStructure/MonoidAction/add_sum.cpp"

template <typename T, typename U>
struct AddSum{
  using monoid_get = SumMonoid<T>;
  using monoid_update = SumMonoid<U>;
  using value_type_get = typename monoid_get::value_type;
  using value_type_update = typename monoid_update::value_type;

  constexpr inline static value_type_get op(const value_type_get &a, const value_type_update &b, int len){
    return a + b * len;
  }
};
#line 8 "test/aoj/2667/main.test.cpp"

int main(){
  int N, Q; std::cin >> N >> Q;
  
  Tree<int> tree(N);
  for(int i = 0; i < N-1; ++i){
    int a, b; std::cin >> a >> b;
    add_undirected(tree, a, b, 1);
  }
  
  auto hld = HLDecomposition(tree, 0);
  LazySegmentTree<AddSum<int64_t,int64_t>> seg(N);
  
  while(Q--){
    int c; std::cin >> c;
    
    if(c == 0){
      int u, v; std::cin >> u >> v;
      
      int64_t ans = 0;
      hld.path_query_edge(u, v, [&](int l, int r){ans += seg.get(l, r);});
      std::cout << ans << std::endl;
    }else{
      int v, x; std::cin >> v >> x;
      
      hld.subtree_query_edge(v, [&](int l, int r){seg.update(l, r, x);});
    }
  }
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

