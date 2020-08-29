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


# :question: Rerooting DP

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a41ea9974466d4f509bcbf59f2ee921e">Mylib/Graph/TreeUtils</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/TreeUtils/rerooting.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-28 18:23:32+09:00




## Operations

## Requirements

## Notes

## Problems

- [EDPC V - Subtree](https://atcoder.jp/contests/dp/tasks/dp_v)
- [Codeforces Round #627 (Div. 3) F. Maximum White Subtree](https://codeforces.com/contest/1324/problem/F)
- [ABC 160 F - Distributing Integers](https://atcoder.jp/contests/abc160/tasks/abc160_f)
- [ARC 028 C - 高橋王国の分割統治 ](https://atcoder.jp/contests/arc028/tasks/arc028_3)
- [s8pc #4 D - Driving on a Tree](https://atcoder.jp/contests/s8pc-4/tasks/s8pc_4_d)

## References
- [https://null-mn.hatenablog.com/entry/2020/04/14/124151](https://null-mn.hatenablog.com/entry/2020/04/14/124151)
- [https://qiita.com/keymoon/items/2a52f1b0fb7ef67fb89e](https://qiita.com/keymoon/items/2a52f1b0fb7ef67fb89e)
- [https://kuretchi.github.io/blog/entries/rerooting/](https://kuretchi.github.io/blog/entries/rerooting/)


## Depends on

* :question: <a href="../Template/graph.cpp.html">Basic graph</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/1595/main.test.cpp.html">test/aoj/1595/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yukicoder/922/main.test.cpp.html">test/yukicoder/922/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Rerooting DP
 * @docs rerooting.md
 */

template <typename T, typename U, typename Merge, typename EdgeF, typename VertexF>
struct Rerooting{
  int N;
  Tree<T> tree;
  U id;
  Merge merge;
  EdgeF f;
  VertexF g;
  
  std::vector<std::vector<U>> dp;
  std::vector<U> result;
  
  Rerooting(Tree<T> tree, U id, Merge merge, EdgeF f, VertexF g):
    N(tree.size()), tree(tree), id(id), merge(merge), f(f), g(g), dp(N), result(N, id)
  {
    for(int i = 0; i < N; ++i) dp[i].assign((int)tree[i].size(), id);
    rec1(0);
    rec2(0, -1, id);
    for(int i = 0; i < N; ++i){
      for(int j = 0; j < (int)tree[i].size(); ++j){
        result[i] = merge(result[i], f(dp[i][j], tree[i][j]));
      }
      
      result[i] = g(result[i], i);
    }
  }

  U rec1(int cur, int par = -1){
    U acc = id;
    
    for(int i = 0; i < (int)tree[cur].size(); ++i){
      auto &e = tree[cur][i];
      if(e.to == par) continue;
      dp[cur][i] = rec1(e.to, cur);
      acc = merge(acc, f(dp[cur][i], e));
    }

    return g(acc, cur);
  }

  void rec2(int cur, int par, U value){
    const int l = tree[cur].size();

    for(int i = 0; i < l; ++i){
      if(tree[cur][i].to == par){
        dp[cur][i] = value;
      }
    }

    std::vector<U> left(l+1, id), right(l+1, id);

    for(int i = 0; i < l-1; ++i){
      const auto &e = tree[cur][i];
      left[i+1] = merge(left[i], f(dp[cur][i], e));
    }

    for(int i = l-1; i >= 1; --i){
      const auto &e = tree[cur][i];
      right[i-1] = merge(right[i], f(dp[cur][i], e));
    }

    for(int i = 0; i < l; ++i){
      const auto &e = tree[cur][i];
      if(e.to == par) continue;

      rec2(e.to, cur, g(merge(left[i], right[i]), cur));
    }
  }
};

template <typename T, typename U, typename Merge, typename EdgeF, typename VertexF>
auto make_rerooting(const Tree<U> &tree, T id, Merge merge, EdgeF f, VertexF g){
  return Rerooting<U,T,Merge,EdgeF,VertexF>(tree, id, merge, f, g);
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/TreeUtils/rerooting.cpp"
#include <vector>
#line 3 "Mylib/Graph/Template/graph.cpp"

/**
 * @title Basic graph
 * @docs graph.md
 */
template <typename T>
struct Edge{
  int from, to;
  T cost;
  int index = -1;
  Edge(){}
  Edge(int from, int to, T cost): from(from), to(to), cost(cost){}
  Edge(int from, int to, T cost, int index): from(from), to(to), cost(cost), index(index){}
};

template <typename T>
struct Graph{
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

template <typename T, typename U, typename Merge, typename EdgeF, typename VertexF>
struct Rerooting{
  int N;
  Tree<T> tree;
  U id;
  Merge merge;
  EdgeF f;
  VertexF g;
  
  std::vector<std::vector<U>> dp;
  std::vector<U> result;
  
  Rerooting(Tree<T> tree, U id, Merge merge, EdgeF f, VertexF g):
    N(tree.size()), tree(tree), id(id), merge(merge), f(f), g(g), dp(N), result(N, id)
  {
    for(int i = 0; i < N; ++i) dp[i].assign((int)tree[i].size(), id);
    rec1(0);
    rec2(0, -1, id);
    for(int i = 0; i < N; ++i){
      for(int j = 0; j < (int)tree[i].size(); ++j){
        result[i] = merge(result[i], f(dp[i][j], tree[i][j]));
      }
      
      result[i] = g(result[i], i);
    }
  }

  U rec1(int cur, int par = -1){
    U acc = id;
    
    for(int i = 0; i < (int)tree[cur].size(); ++i){
      auto &e = tree[cur][i];
      if(e.to == par) continue;
      dp[cur][i] = rec1(e.to, cur);
      acc = merge(acc, f(dp[cur][i], e));
    }

    return g(acc, cur);
  }

  void rec2(int cur, int par, U value){
    const int l = tree[cur].size();

    for(int i = 0; i < l; ++i){
      if(tree[cur][i].to == par){
        dp[cur][i] = value;
      }
    }

    std::vector<U> left(l+1, id), right(l+1, id);

    for(int i = 0; i < l-1; ++i){
      const auto &e = tree[cur][i];
      left[i+1] = merge(left[i], f(dp[cur][i], e));
    }

    for(int i = l-1; i >= 1; --i){
      const auto &e = tree[cur][i];
      right[i-1] = merge(right[i], f(dp[cur][i], e));
    }

    for(int i = 0; i < l; ++i){
      const auto &e = tree[cur][i];
      if(e.to == par) continue;

      rec2(e.to, cur, g(merge(left[i], right[i]), cur));
    }
  }
};

template <typename T, typename U, typename Merge, typename EdgeF, typename VertexF>
auto make_rerooting(const Tree<U> &tree, T id, Merge merge, EdgeF f, VertexF g){
  return Rerooting<U,T,Merge,EdgeF,VertexF>(tree, id, merge, f, g);
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

