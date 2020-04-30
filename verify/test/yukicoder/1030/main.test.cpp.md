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


# :heavy_check_mark: test/yukicoder/1030/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#fce7f5311a6094c5e355d46a4ec1ba92">test/yukicoder/1030</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yukicoder/1030/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-29 20:22:17+09:00


* see: <a href="https://yukicoder.me/problems/no/1030">https://yukicoder.me/problems/no/1030</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/max_monoid.cpp.html">Mylib/AlgebraicStructure/Monoid/max_monoid.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/maybe_monoid.cpp.html">Mylib/AlgebraicStructure/Monoid/maybe_monoid.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/DataStructure/SegmentTree/Static/Normal/segment_tree.cpp.html">セグメント木</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp.html">HL分解</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/graph_template.cpp.html">グラフ用テンプレート</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/1030"

#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp"
#include "Mylib/DataStructure/SegmentTree/Static/Normal/segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/max_monoid.cpp"
#include "Mylib/AlgebraicStructure/Monoid/maybe_monoid.cpp"

struct LCASemigroup{
  using value_type = int;
  static std::function<int(int,int)> op;
};

std::function<int(int,int)> LCASemigroup::op;


int main(){
  int N, K, Q; std::cin >> N >> K >> Q;
  std::vector<int> C(N);
  for(auto &x : C) std::cin >> x;
  
  std::vector<int> A(K);
  for(auto &x : A){
    std::cin >> x;
    --x;
  }

  Tree<int> tree(N);
  for(int i = 0; i < N-1; ++i){
    int e, f; std::cin >> e >> f;
    --e, --f;
    add_edge(tree, f, e, 1);
  }

  HLDecomposition<int> hld(tree, 0);
  LCASemigroup::op = [&](int a, int b) -> int{return hld.lca(a, b);};

  SegmentTree<MaxMonoid<int>> seg1(N);
  for(int i = 0; i < N; ++i){
    seg1.update(hld.get_id(i), C[i]);
  }

  SegmentTree<MaybeMonoid<LCASemigroup>> seg2(K);
  seg2.init_with_vector(A);

  while(Q--){
    int T; std::cin >> T;

    if(T == 1){
      int X, Y; std::cin >> X >> Y;
      --X; --Y;

      seg2.update(X, Y);
    }else{
      int L, R; std::cin >> L >> R;
      
      int lca = *seg2.get(L-1, R);
      int ans = 0;
      hld.path_query_vertex(0, lca,
                            [&](int l, int r){
                              ans = std::max(ans, seg1.get(l, r));
                            });
      
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
#line 1 "test/yukicoder/1030/main.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/1030"

#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

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
#line 3 "Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp"
#include <utility>
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
#line 3 "Mylib/DataStructure/SegmentTree/Static/Normal/segment_tree.cpp"

/**
 * @title セグメント木
 */
template <typename Monoid>
class SegmentTree{
  using value_type = typename Monoid::value_type;
  
  int depth, size, hsize;
  std::vector<value_type> data;

public:
  SegmentTree(){}
  SegmentTree(int n):
    depth(n > 1 ? 32-__builtin_clz(n-1) + 1 : 1),
    size(1 << depth), hsize(size / 2),
    data(size, Monoid::id())
  {}

  inline auto operator[](int i) const {return at(i);}
  inline auto at(int i) const {return data[hsize + i];}
  
  inline auto get(int x, int y) const { // [x,y)
    value_type ret_left = Monoid::id();
    value_type ret_right = Monoid::id();
    
    int l = x + hsize, r = y + hsize;
    while(l < r){
      if(r & 1) ret_right = Monoid::op(data[--r], ret_right);
      if(l & 1) ret_left = Monoid::op(ret_left, data[l++]);
      l >>= 1, r >>= 1;
    }
    
    return Monoid::op(ret_left, ret_right);
  }

  inline void update(int i, const value_type &x){
    i += hsize;
    data[i] = x;
    while(i > 1) i >>= 1, data[i] = Monoid::op(data[i << 1 | 0], data[i << 1 | 1]);
  }

  template <typename T>
  inline void init_with_vector(const std::vector<T> &val){
    data.assign(size, Monoid::id());
    for(int i = 0; i < (int)val.size(); ++i) data[hsize + i] = val[i];
    for(int i = hsize-1; i >= 1; --i) data[i] = Monoid::op(data[i << 1 | 0], data[i << 1 | 1]);
  }

  template <typename T>
  inline void init(const T &val){
    init_with_vector(std::vector<value_type>(hsize, val));
  }  
};
#line 3 "Mylib/AlgebraicStructure/Monoid/max_monoid.cpp"

template <typename T>
struct MaxMonoid{
  using value_type = T;
  constexpr inline static value_type id(){return std::numeric_limits<T>::lowest();}
  constexpr inline static value_type op(const value_type &a, const value_type &b){return std::max(a, b);}
};
#line 2 "Mylib/AlgebraicStructure/Monoid/maybe_monoid.cpp"
#include <optional>

template <typename Semigroup>
struct MaybeMonoid{
  using value_type = std::optional<typename Semigroup::value_type>;
  
  static value_type id(){return {};}
  static value_type op(const value_type &a, const value_type &b){
    if(not a) return b;
    if(not b) return a;
    return {Semigroup::op(*a, *b)};
  }
};
#line 13 "test/yukicoder/1030/main.test.cpp"

struct LCASemigroup{
  using value_type = int;
  static std::function<int(int,int)> op;
};

std::function<int(int,int)> LCASemigroup::op;


int main(){
  int N, K, Q; std::cin >> N >> K >> Q;
  std::vector<int> C(N);
  for(auto &x : C) std::cin >> x;
  
  std::vector<int> A(K);
  for(auto &x : A){
    std::cin >> x;
    --x;
  }

  Tree<int> tree(N);
  for(int i = 0; i < N-1; ++i){
    int e, f; std::cin >> e >> f;
    --e, --f;
    add_edge(tree, f, e, 1);
  }

  HLDecomposition<int> hld(tree, 0);
  LCASemigroup::op = [&](int a, int b) -> int{return hld.lca(a, b);};

  SegmentTree<MaxMonoid<int>> seg1(N);
  for(int i = 0; i < N; ++i){
    seg1.update(hld.get_id(i), C[i]);
  }

  SegmentTree<MaybeMonoid<LCASemigroup>> seg2(K);
  seg2.init_with_vector(A);

  while(Q--){
    int T; std::cin >> T;

    if(T == 1){
      int X, Y; std::cin >> X >> Y;
      --X; --Y;

      seg2.update(X, Y);
    }else{
      int L, R; std::cin >> L >> R;
      
      int lca = *seg2.get(L-1, R);
      int ans = 0;
      hld.path_query_vertex(0, lca,
                            [&](int l, int r){
                              ans = std::max(ans, seg1.get(l, r));
                            });
      
      std::cout << ans << "\n";
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
