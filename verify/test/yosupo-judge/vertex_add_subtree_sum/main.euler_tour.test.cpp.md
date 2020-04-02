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


# :x: test/yosupo-judge/vertex_add_subtree_sum/main.euler_tour.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#5182f60ed9f69992a8eee7b8b1003f24">test/yosupo-judge/vertex_add_subtree_sum</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/vertex_add_subtree_sum/main.euler_tour.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 18:35:49+09:00


* see: <a href="https://judge.yosupo.jp/problem/vertex_add_subtree_sum">https://judge.yosupo.jp/problem/vertex_add_subtree_sum</a>


## Depends on

* :question: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/sum_monoid.cpp.html">Mylib/AlgebraicStructure/Monoid/sum_monoid.cpp</a>
* :question: <a href="../../../../library/Mylib/DataStructure/SegmentTree/Static/Normal/segment_tree.cpp.html">セグメント木</a>
* :x: <a href="../../../../library/Mylib/Graph/TreeUtils/euler_tour_vertex.cpp.html">頂点Euler tour</a>
* :question: <a href="../../../../library/Mylib/Graph/graph_template.cpp.html">グラフ用テンプレート</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include <iostream>
#include <vector>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/TreeUtils/euler_tour_vertex.cpp"
#include "Mylib/DataStructure/SegmentTree/Static/Normal/segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/sum_monoid.cpp"

int main(){
  int N, Q; scanf("%d %d", &N, &Q);

  std::vector<int64_t> a(N);
  for(int i = 0; i < N; ++i) scanf("%lld", &a[i]);

  Tree<int> tree(N);
  for(int i = 1; i < N; ++i){
    int p; scanf("%d", &p);
    add_edge(tree, p, i, 1);
  }

  auto seg = SegmentTree<SumMonoid<int64_t>>(N);
  auto et = EulerTourVertex(tree, 0);

  for(int i = 0; i < N; ++i){
    et.point_query(i, [&](int j){seg.update(j, a[i]);});
  }

  while(Q--){
    int t; scanf("%d", &t);

    if(t == 0){
      int u, x; scanf("%d %d", &u, &x);

      et.point_query(u, [&](int j){seg.update(j, seg.at(j) + x);});
    }else{
      int u; scanf("%d", &u);

      int64_t ans = 0;
      et.subtree_query(u, [&](int l, int r){ans += seg.get(l, r);});

      printf("%lld\n", ans);
    }
  }
  
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/vertex_add_subtree_sum/main.euler_tour.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include <iostream>
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
#line 4 "Mylib/Graph/TreeUtils/euler_tour_vertex.cpp"

/**
 * @title 頂点Euler tour
 */
template <typename T> class EulerTourVertex{
  int pos = 0;
  std::vector<int> begin, end;

  void dfs(int cur, int par, const Tree<T> &tree){
    begin[cur] = pos++;
	
    for(auto &e : tree[cur]){
      if(e.to == par) continue;
      dfs(e.to, cur, tree);
    }

    end[cur] = pos;
  }

public:
  EulerTourVertex(const Tree<T> &tree, int root): begin(tree.size()), end(tree.size()){
    dfs(root, -1, tree);
  }

  template <typename F> // F = std::function<void(int,int)>
  void subtree_query(int i, const F &f){
    f(begin[i], end[i]);
  }

  template <typename F> // F = std::function<void(int)>
  void point_query(int i, const F &f){
    f(begin[i]);
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
#line 2 "Mylib/AlgebraicStructure/Monoid/sum_monoid.cpp"

template <typename T>
struct SumMonoid{
  using value_type = T;
  constexpr inline static value_type id(){return 0;}
  constexpr inline static value_type op(const value_type &a, const value_type &b){return a + b;}
};
#line 9 "test/yosupo-judge/vertex_add_subtree_sum/main.euler_tour.test.cpp"

int main(){
  int N, Q; scanf("%d %d", &N, &Q);

  std::vector<int64_t> a(N);
  for(int i = 0; i < N; ++i) scanf("%lld", &a[i]);

  Tree<int> tree(N);
  for(int i = 1; i < N; ++i){
    int p; scanf("%d", &p);
    add_edge(tree, p, i, 1);
  }

  auto seg = SegmentTree<SumMonoid<int64_t>>(N);
  auto et = EulerTourVertex(tree, 0);

  for(int i = 0; i < N; ++i){
    et.point_query(i, [&](int j){seg.update(j, a[i]);});
  }

  while(Q--){
    int t; scanf("%d", &t);

    if(t == 0){
      int u, x; scanf("%d %d", &u, &x);

      et.point_query(u, [&](int j){seg.update(j, seg.at(j) + x);});
    }else{
      int u; scanf("%d", &u);

      int64_t ans = 0;
      et.subtree_query(u, [&](int l, int r){ans += seg.get(l, r);});

      printf("%lld\n", ans);
    }
  }
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

