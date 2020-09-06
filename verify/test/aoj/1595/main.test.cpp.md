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


# :x: test/aoj/1595/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#56f0b2628838f5e87f16daf710f380b1">test/aoj/1595</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/1595/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 11:15:59+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1595">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1595</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Graph/Template/graph.cpp.html">Basic graph</a>
* :x: <a href="../../../../library/Mylib/Graph/TreeUtils/rerooting.cpp.html">Rerooting DP</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1595"

#include <iostream>
#include "Mylib/Graph/TreeUtils/rerooting.cpp"
#include "Mylib/Graph/Template/graph.cpp"

int main(){
  int N; std::cin >> N;

  Tree<int> tree(N);
  tree.read<1, false, false>(N - 1);

  auto r = rerooting<int>(
    tree,
    0,
    [](const auto &a, const auto &b){
      return std::max(a, b);
    },
    [](const auto &a, const auto &){
      return a + 1;
    },
    [](const auto &a, int){
      return a;
    }
  );

  for(auto &x : r){
    std::cout << 2 * (N - 1) - x << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/1595/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1595"

#include <iostream>
#line 2 "Mylib/Graph/TreeUtils/rerooting.cpp"
#include <vector>
#line 4 "Mylib/Graph/Template/graph.cpp"

/**
 * @title Basic graph
 * @docs graph.md
 */
template <typename T>
struct Edge {
  int from, to;
  T cost;
  int index = -1;
  Edge(){}
  Edge(int from, int to, T cost): from(from), to(to), cost(cost){}
  Edge(int from, int to, T cost, int index): from(from), to(to), cost(cost), index(index){}
};

template <typename T>
struct Graph {
  using weight_type = T;
  using edge_type = Edge<T>;

  std::vector<std::vector<Edge<T>>> data;

  auto& operator[](size_t i){return data[i];}
  const auto& operator[](size_t i) const {return data[i];}

  auto begin() const {return data.begin();}
  auto end() const {return data.end();}

  Graph(){}
  Graph(int N): data(N){}

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
using Tree = Graph<T>;
#line 4 "Mylib/Graph/TreeUtils/rerooting.cpp"

/**
 * @title Rerooting DP
 * @docs rerooting.md
 */
namespace rerooting_impl {
  template <typename T, typename U, typename Merge, typename EdgeF, typename VertexF>
  T rec1(
    Tree<U> &tree,
    T id,
    const Merge &merge,
    const EdgeF &f,
    const VertexF &g,
    std::vector<std::vector<T>> &dp,
    int cur,
    int par = -1
  ){
    T acc = id;

    for(int i = 0; i < (int)tree[cur].size(); ++i){
      auto &e = tree[cur][i];
      if(e.to == par) continue;
      dp[cur][i] = rec1(tree, id, merge, f, g, dp, e.to, cur);
      acc = merge(acc, f(dp[cur][i], e));
    }

    return g(acc, cur);
  }

  template <typename T, typename U, typename Merge, typename EdgeF, typename VertexF>
  void rec2(
    const Tree<U> &tree,
    T id,
    const Merge &merge,
    const EdgeF &f,
    const VertexF &g,
    std::vector<std::vector<T>> &dp,
    int cur,
    int par,
    T value
  ){
    const int l = tree[cur].size();

    for(int i = 0; i < l; ++i){
      if(tree[cur][i].to == par){
        dp[cur][i] = value;
      }
    }

    std::vector<T> left(l + 1, id), right(l + 1, id);

    for(int i = 0; i < l - 1; ++i){
      const auto &e = tree[cur][i];
      left[i + 1] = merge(left[i], f(dp[cur][i], e));
    }

    for(int i = l - 1; i >= 1; --i){
      const auto &e = tree[cur][i];
      right[i - 1] = merge(right[i], f(dp[cur][i], e));
    }

    for(int i = 0; i < l; ++i){
      const auto &e = tree[cur][i];
      if(e.to == par) continue;

      rec2(tree, id, merge, f, g, dp, e.to, cur, g(merge(left[i], right[i]), cur));
    }
  }
}

template <typename T, typename U, typename Merge, typename EdgeF, typename VertexF>
auto rerooting(Tree<U> tree, T id, Merge merge, EdgeF f, VertexF g){
  const int N = tree.size();
  std::vector<std::vector<T>> dp(N);
  std::vector<T> ret(N, id);

  for(int i = 0; i < N; ++i) dp[i].assign(tree[i].size(), id);
  rerooting_impl::rec1(tree, id, merge, f, g, dp, 0);
  rerooting_impl::rec2(tree, id, merge, f, g, dp, 0, -1, id);
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < (int)tree[i].size(); ++j){
      ret[i] = merge(ret[i], f(dp[i][j], tree[i][j]));
    }

    ret[i] = g(ret[i], i);
  }

  return ret;
}
#line 6 "test/aoj/1595/main.test.cpp"

int main(){
  int N; std::cin >> N;

  Tree<int> tree(N);
  tree.read<1, false, false>(N - 1);

  auto r = rerooting<int>(
    tree,
    0,
    [](const auto &a, const auto &b){
      return std::max(a, b);
    },
    [](const auto &a, const auto &){
      return a + 1;
    },
    [](const auto &a, int){
      return a;
    }
  );

  for(auto &x : r){
    std::cout << 2 * (N - 1) - x << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

