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


# :heavy_check_mark: test/aoj/1595/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#56f0b2628838f5e87f16daf710f380b1">test/aoj/1595</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/1595/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1595">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1595</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/TreeUtils/rerooting.cpp.html">全方位木dp</a>
* :question: <a href="../../../../library/Mylib/Graph/graph_template.cpp.html">グラフ用テンプレート</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1595"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/TreeUtils/rerooting.cpp"

int main(){
  int N; std::cin >> N;
  Tree<int> tree(N);

  for(int i = 0; i < N-1; ++i){
    int u, v; std::cin >> u >> v;
    --u, --v;
    add_undirected(tree, u, v, 1);
  }

  auto merge = [](const auto &a, const auto &b){return std::max(a, b);};
  auto f = [](const auto &a, const auto &){return a + 1;};
  auto g = [](const auto &a, int){return a;};

  auto r = make_rerooting<int>(tree, 0, merge, f, g);

  for(auto &x : r.result){
    std::cout << 2 * (N-1) - x << std::endl;
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
#line 2 "Mylib/Graph/graph_template.cpp"
#include <vector>
#line 4 "Mylib/Graph/graph_template.cpp"

/**
 * @title グラフ用テンプレート
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
#line 4 "Mylib/Graph/TreeUtils/rerooting.cpp"

/**
 * @title 全方位木dp
 * @docs rerooting.md
 */

template <typename T, typename U, typename Merge, typename EdgeF, typename VertexF>
struct Rerooting{
  int N;
  T tree;
  U id;
  Merge merge;
  EdgeF f;
  VertexF g;
  
  std::vector<std::vector<U>> dp;
  std::vector<U> result;
  
  Rerooting(T tree, U id, Merge merge, EdgeF f, VertexF g):
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

template <typename T, typename G, typename Merge, typename EdgeF, typename VertexF>
auto make_rerooting(const G &tree, T id, Merge merge, EdgeF f, VertexF g){
  return Rerooting<G,T,Merge,EdgeF,VertexF>(tree, id, merge, f, g);
}
#line 6 "test/aoj/1595/main.test.cpp"

int main(){
  int N; std::cin >> N;
  Tree<int> tree(N);

  for(int i = 0; i < N-1; ++i){
    int u, v; std::cin >> u >> v;
    --u, --v;
    add_undirected(tree, u, v, 1);
  }

  auto merge = [](const auto &a, const auto &b){return std::max(a, b);};
  auto f = [](const auto &a, const auto &){return a + 1;};
  auto g = [](const auto &a, int){return a;};

  auto r = make_rerooting<int>(tree, 0, merge, f, g);

  for(auto &x : r.result){
    std::cout << 2 * (N-1) - x << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

