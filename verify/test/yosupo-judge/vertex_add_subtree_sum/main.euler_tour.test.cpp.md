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
    - Last commit date: 2020-07-11 14:07:48+09:00


* see: <a href="https://judge.yosupo.jp/problem/vertex_add_subtree_sum">https://judge.yosupo.jp/problem/vertex_add_subtree_sum</a>


## Depends on

* :question: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/sum.cpp.html">Mylib/AlgebraicStructure/Monoid/sum.cpp</a>
* :question: <a href="../../../../library/Mylib/DataStructure/SegmentTree/segment_tree.cpp.html">Segment tree</a>
* :x: <a href="../../../../library/Mylib/Graph/TreeUtils/euler_tour_vertex.cpp.html">Euler tour (Vertex)</a>
* :question: <a href="../../../../library/Mylib/Graph/graph_template.cpp.html">Graph template</a>
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
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/TreeUtils/euler_tour_vertex.cpp"
#include "Mylib/DataStructure/SegmentTree/segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, Q; std::cin >> N >> Q;

  auto a = input_vector<int64_t>(N);

  Tree<int> tree(N);
  for(int i = 1; i < N; ++i){
    int p; std::cin >> p;
    add_edge(tree, p, i, 1);
  }

  auto seg = SegmentTree<SumMonoid<int64_t>>(N);
  auto et = EulerTourVertex(tree, 0);

  for(int i = 0; i < N; ++i){
    et.point_query(
      i,
      [&](int j){
        seg.update(j, a[i]);
      }
    );
  }

  for(auto [t, u] : input_tuples<int, int>(Q)){
    if(t == 0){
      int x; std::cin >> x;

      et.point_query(
        u,
        [&](int j){
          seg.update(j, seg.at(j) + x);
        }
      );
    }else{
      int64_t ans = 0;
      et.subtree_query(
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
#line 1 "test/yosupo-judge/vertex_add_subtree_sum/main.euler_tour.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include <iostream>
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
#line 4 "Mylib/Graph/TreeUtils/euler_tour_vertex.cpp"

/**
 * @title Euler tour (Vertex)
 * @docs euler_tour_vertex.md
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
#line 2 "Mylib/AlgebraicStructure/Monoid/sum.cpp"

/**
 * @docs sum.md
 */
template <typename T>
struct SumMonoid{
  using value_type = T;
  value_type id() const {return 0;}
  value_type op(value_type a, value_type b) const {return a + b;}
};
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
#line 11 "test/yosupo-judge/vertex_add_subtree_sum/main.euler_tour.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, Q; std::cin >> N >> Q;

  auto a = input_vector<int64_t>(N);

  Tree<int> tree(N);
  for(int i = 1; i < N; ++i){
    int p; std::cin >> p;
    add_edge(tree, p, i, 1);
  }

  auto seg = SegmentTree<SumMonoid<int64_t>>(N);
  auto et = EulerTourVertex(tree, 0);

  for(int i = 0; i < N; ++i){
    et.point_query(
      i,
      [&](int j){
        seg.update(j, a[i]);
      }
    );
  }

  for(auto [t, u] : input_tuples<int, int>(Q)){
    if(t == 0){
      int x; std::cin >> x;

      et.point_query(
        u,
        [&](int j){
          seg.update(j, seg.at(j) + x);
        }
      );
    }else{
      int64_t ans = 0;
      et.subtree_query(
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

