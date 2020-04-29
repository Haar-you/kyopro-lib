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


# :x: test/yosupo-judge/vertex_set_path_composite/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#4074bf88980bb06d903e38d47fb81c08">test/yosupo-judge/vertex_set_path_composite</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/vertex_set_path_composite/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-29 20:22:17+09:00


* see: <a href="https://judge.yosupo.jp/problem/vertex_set_path_composite">https://judge.yosupo.jp/problem/vertex_set_path_composite</a>


## Depends on

* :question: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/affine_monoid.cpp.html">Mylib/AlgebraicStructure/Monoid/affine_monoid.cpp</a>
* :question: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/dual_monoid.cpp.html">Mylib/AlgebraicStructure/Monoid/dual_monoid.cpp</a>
* :x: <a href="../../../../library/Mylib/DataStructure/SegmentTree/Static/Normal/segment_tree_both_foldable.cpp.html">双方向のセグメント木</a>
* :question: <a href="../../../../library/Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp.html">HL分解</a>
* :question: <a href="../../../../library/Mylib/Graph/graph_template.cpp.html">グラフ用テンプレート</a>
* :question: <a href="../../../../library/Mylib/Number/Mint/mint.cpp.html">modint</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"

#include <iostream>
#include <vector>
#include <utility>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp"
#include "Mylib/DataStructure/SegmentTree/Static/Normal/segment_tree_both_foldable.cpp"
#include "Mylib/AlgebraicStructure/Monoid/affine_monoid.cpp"
#include "Mylib/AlgebraicStructure/Monoid/dual_monoid.cpp"

using mint = ModInt<998244353>;
using M = DualMonoid<AffineMonoid<mint>>;

int main(){
  int N, Q; scanf("%d%d", &N, &Q);

  Tree<int> tree(N);

  std::vector<std::pair<mint,mint>> f(N);

  for(int i = 0; i < N; ++i){
    int64_t a, b; scanf("%lld%lld", &a, &b);
    f[i] = std::make_pair(a, b);
  }

  for(int i = 0; i < N-1; ++i){
    int u, v; scanf("%d%d", &u, &v);
    add_undirected(tree, u, v, 1);
  }
  
  HLDecomposition<int> hld(tree, 0);

  SegmentTreeBothFoldable<M> seg(N);
  
  for(int i = 0; i < N; ++i){
    seg.update(hld.get_id(i), f[i]);
  }

  while(Q--){
    int type; scanf("%d", &type);

    if(type == 0){
      int64_t p, c, d; scanf("%lld%lld%lld", &p, &c, &d);

      seg.update(hld.get_id(p), std::make_pair(c, d));
    }else{
      int64_t u, v, x; scanf("%lld%lld%lld", &u, &v, &x);

      auto left = M::id(), right = M::id();

      hld.path_query_vertex(u, v,
                            [&](int l, int r){
                              left = M::op(left, seg.fold_right(l, r));
                            },
                            [&](int l, int r){
                              right = M::op(seg.fold_left(l, r), right);
                            });
      
      auto a = M::op(left, right);

      mint ans = a.first * x + a.second;
      printf("%lld\n", ans.val);
    }
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/vertex_set_path_composite/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"

#include <iostream>
#include <vector>
#include <utility>
#line 4 "Mylib/Number/Mint/mint.cpp"

/**
 * @title modint
 */
template <uint32_t M> class ModInt{
public:
  constexpr static uint32_t MOD = M;
  uint64_t val;
  
  constexpr ModInt(): val(0){}
  constexpr ModInt(int64_t n){
    if(n >= M) val = n % M;
    else if(n < 0) val = n % M + M;
    else val = n;
  }
  
  inline constexpr auto operator+(const ModInt &a) const {return ModInt(val + a.val);}
  inline constexpr auto operator-(const ModInt &a) const {return ModInt(val - a.val);}
  inline constexpr auto operator*(const ModInt &a) const {return ModInt(val * a.val);}
  inline constexpr auto operator/(const ModInt &a) const {return ModInt(val * a.inv().val);}
  
  inline constexpr auto& operator=(const ModInt &a){val = a.val; return *this;}
  inline constexpr auto& operator+=(const ModInt &a){if((val += a.val) >= M) val -= M; return *this;}
  inline constexpr auto& operator-=(const ModInt &a){if(val < a.val) val += M; val -= a.val; return *this;}
  inline constexpr auto& operator*=(const ModInt &a){(val *= a.val) %= M; return *this;}
  inline constexpr auto& operator/=(const ModInt &a){(val *= a.inv().val) %= M; return *this;}
 
  inline constexpr bool operator==(const ModInt &a) const {return val == a.val;}
  inline constexpr bool operator!=(const ModInt &a) const {return val != a.val;}
 
  inline constexpr auto& operator++(){*this += 1; return *this;}
  inline constexpr auto& operator--(){*this -= 1; return *this;}
 
  inline constexpr auto operator++(int){auto t = *this; *this += 1; return t;}
  inline constexpr auto operator--(int){auto t = *this; *this -= 1; return t;}
 
  inline constexpr static ModInt power(int64_t n, int64_t p){
    if(p < 0) return power(n, -p).inv();
    
    int64_t ret = 1, e = n % M;
    for(; p; (e *= e) %= M, p >>= 1) if(p & 1) (ret *= e) %= M;
    return ret;
  }
 
  inline constexpr static ModInt inv(int64_t a){
    int64_t b = M, u = 1, v = 0;
    
    while(b){
      int64_t t = a / b;
      a -= t * b; std::swap(a,b);
      u -= t * v; std::swap(u,v);
    }
 
    u %= M;
    if(u < 0) u += M;
    
    return u;
  }
 
  inline constexpr static auto frac(int64_t a, int64_t b){return ModInt(a) / ModInt(b);}
  
  inline constexpr auto power(int64_t p) const {return power(val, p);}
  inline constexpr auto inv() const {return inv(val);}
 
  friend inline constexpr auto operator-(const ModInt &a){return ModInt(-a.val);}
 
  friend inline constexpr auto operator+(int64_t a, const ModInt &b){return ModInt(a) + b;}
  friend inline constexpr auto operator-(int64_t a, const ModInt &b){return ModInt(a) - b;}
  friend inline constexpr auto operator*(int64_t a, const ModInt &b){return ModInt(a) * b;}
  friend inline constexpr auto operator/(int64_t a, const ModInt &b){return ModInt(a) / b;}
 
  friend std::istream& operator>>(std::istream &s, ModInt<M> &a){s >> a.val; return s;}
  friend std::ostream& operator<<(std::ostream &s, const ModInt<M> &a){s << a.val; return s;}

  template <int N>
  inline static auto div(){
    static auto value = inv(N);
    return value;
  }

  explicit operator int32_t() const noexcept {return val;}
  explicit operator int64_t() const noexcept {return val;}
};
#line 4 "Mylib/Graph/graph_template.cpp"

/**
 * @title グラフ用テンプレート
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
#line 4 "Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp"
#include <algorithm>
#line 6 "Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp"

/**
 * @title HL分解
 * @docs heavy_light_decomposition.md
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
#line 3 "Mylib/DataStructure/SegmentTree/Static/Normal/segment_tree_both_foldable.cpp"

/**
 * @title 双方向のセグメント木
 */
template <typename Monoid>
class SegmentTreeBothFoldable{
  using value_type = typename Monoid::value_type;
  
protected:
  const int depth, size, hsize;
  std::vector<value_type> data_left, data_right;

public:
  SegmentTreeBothFoldable(int n):
    depth(n > 1 ? 32-__builtin_clz(n-1) + 1 : 1),
    size(1 << depth),
    hsize(size / 2),
    data_left(size, Monoid::id()),
    data_right(size, Monoid::id())
  {}

  inline auto operator[](int i) const {return at(i);}
  inline auto at(int i) const {return data_left[hsize + i];}
  
  inline auto fold_left(int x, int y) const { // [x,y)
    value_type ret_left = Monoid::id();
    value_type ret_right = Monoid::id();
    
    int l = x + hsize, r = y + hsize;
    while(l < r){
      if(r & 1) ret_right = Monoid::op(data_left[--r], ret_right);
      if(l & 1) ret_left = Monoid::op(ret_left, data_left[l++]);
      l >>= 1, r >>= 1;
    }
    
    return Monoid::op(ret_left, ret_right);
  }

  inline auto fold_right(int x, int y) const { // [x,y)
    value_type ret_left = Monoid::id();
    value_type ret_right = Monoid::id();
    
    int l = x + hsize, r = y + hsize;
    while(l < r){
      if(r & 1) ret_right = Monoid::op(ret_right, data_right[--r]);
      if(l & 1) ret_left = Monoid::op(data_right[l++], ret_left);
      l >>= 1, r >>= 1;
    }
    
    return Monoid::op(ret_right, ret_left);
  }

  inline void update(int i, const value_type &x){
    i += hsize;
    data_left[i] = data_right[i] = x;
    while(i > 1){
      i >>= 1;
      data_left[i] = Monoid::op(data_left[i << 1 | 0], data_left[i << 1 | 1]);
      data_right[i] = Monoid::op(data_right[i << 1 | 1], data_right[i << 1 | 0]);
    }
  }

  template <typename T>
  inline void init_with_vector(const std::vector<T> &val){
    data_left.assign(size, Monoid::id());
    data_right.assign(size, Monoid::id());
    
    for(int i = 0; i < (int)val.size(); ++i){
      data_left[hsize + i] = val[i];
      data_right[hsize + i] = val[i];
    }
    for(int i = hsize-1; i >= 1; --i){
      data_left[i] = Monoid::op(data_left[i << 1 | 0], data_left[i << 1 | 1]);
      data_right[i] = Monoid::op(data_right[i << 1 | 1], data_right[i << 1 | 0]);
    }
  }

  template <typename T>
  inline void init(const T &val){
    init_with_vector(std::vector<value_type>(hsize, val));
  }  
};
#line 3 "Mylib/AlgebraicStructure/Monoid/affine_monoid.cpp"

/**
 * @see https://atcoder.jp/contests/arc008/submissions/7996520
 * @see https://judge.yosupo.jp/submission/2048
 */

template <typename T>
struct AffineMonoid{
  using value_type = std::pair<T, T>;
  constexpr inline static value_type id(){return std::make_pair(1, 0);}
  constexpr inline static value_type op(const value_type &a, const value_type &b){return std::make_pair(a.first * b.first, a.first * b.second + a.second);}
};
#line 2 "Mylib/AlgebraicStructure/Monoid/dual_monoid.cpp"

template <typename Monoid>
struct DualMonoid{
  using value_type = typename Monoid::value_type;
  constexpr inline static value_type id(){return Monoid::id();}
  constexpr inline static value_type op(const value_type &a, const value_type &b){return Monoid::op(b, a);}
};
#line 12 "test/yosupo-judge/vertex_set_path_composite/main.test.cpp"

using mint = ModInt<998244353>;
using M = DualMonoid<AffineMonoid<mint>>;

int main(){
  int N, Q; scanf("%d%d", &N, &Q);

  Tree<int> tree(N);

  std::vector<std::pair<mint,mint>> f(N);

  for(int i = 0; i < N; ++i){
    int64_t a, b; scanf("%lld%lld", &a, &b);
    f[i] = std::make_pair(a, b);
  }

  for(int i = 0; i < N-1; ++i){
    int u, v; scanf("%d%d", &u, &v);
    add_undirected(tree, u, v, 1);
  }
  
  HLDecomposition<int> hld(tree, 0);

  SegmentTreeBothFoldable<M> seg(N);
  
  for(int i = 0; i < N; ++i){
    seg.update(hld.get_id(i), f[i]);
  }

  while(Q--){
    int type; scanf("%d", &type);

    if(type == 0){
      int64_t p, c, d; scanf("%lld%lld%lld", &p, &c, &d);

      seg.update(hld.get_id(p), std::make_pair(c, d));
    }else{
      int64_t u, v, x; scanf("%lld%lld%lld", &u, &v, &x);

      auto left = M::id(), right = M::id();

      hld.path_query_vertex(u, v,
                            [&](int l, int r){
                              left = M::op(left, seg.fold_right(l, r));
                            },
                            [&](int l, int r){
                              right = M::op(seg.fold_left(l, r), right);
                            });
      
      auto a = M::op(left, right);

      mint ans = a.first * x + a.second;
      printf("%lld\n", ans.val);
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

