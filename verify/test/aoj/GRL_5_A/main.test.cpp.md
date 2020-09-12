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


# :x: test/aoj/GRL_5_A/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a624c615c8a90227d4c31dd34d7dfde1">test/aoj/GRL_5_A</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_5_A/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A</a>


## Depends on

* :question: <a href="../../../../library/Mylib/Graph/Template/graph.cpp.html">Basic graph</a>
* :x: <a href="../../../../library/Mylib/Graph/TreeUtils/tree_diameter.cpp.html">Tree diameter</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A"

#include <iostream>
#include <tuple>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/TreeUtils/tree_diameter.cpp"

namespace hl = haar_lib;

int main(){
  int n; std::cin >> n;

  hl::tree<int> tree(n);
  tree.read<0, false>(n - 1);

  int ans = hl::tree_diameter(tree).first;
  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_5_A/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A"

#include <iostream>
#include <tuple>
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
#line 3 "Mylib/Graph/TreeUtils/tree_diameter.cpp"
#include <utility>
#include <stack>
#include <algorithm>
#line 7 "Mylib/Graph/TreeUtils/tree_diameter.cpp"

/**
 * @title Tree diameter
 * @docs tree_diameter.md
 */
namespace haar_lib {
  template <typename T>
  std::pair<T, std::vector<int>> tree_diameter(const tree<T> &tr){
    const int N = tr.size();

    std::vector<bool> check(N);
    std::vector<T> dp(N);
    std::stack<int> st;

    st.push(0);
    while(st.size()){
      int i = st.top(); st.pop();

      check[i] = true;

      for(const auto &e : tr[i]){
        if(not check[e.to]){
          dp[e.to] = dp[i] + e.cost;
          st.push(e.to);
        }
      }
    }

    const int u = std::max_element(dp.begin(), dp.end()) - dp.begin();

    dp.assign(N, 0);
    check.assign(N, false);

    std::vector<int> prev(N);

    st.push(u);
    while(st.size()){
      int i = st.top(); st.pop();

      check[i] = true;

      for(const auto &e : tr[i]){
        if(not check[e.to]){
          dp[e.to] = dp[i] + e.cost;
          st.push(e.to);
          prev[e.to] = i;
        }
      }
    }

    const int v = std::max_element(dp.begin(), dp.end()) - dp.begin();

    std::vector<int> ret;

    int cur = v;
    while(1){
      ret.push_back(cur);
      if(cur == u) break;
      cur = prev[cur];
    }

    return std::make_pair(dp[v], ret);
  }
}
#line 7 "test/aoj/GRL_5_A/main.test.cpp"

namespace hl = haar_lib;

int main(){
  int n; std::cin >> n;

  hl::tree<int> tree(n);
  tree.read<0, false>(n - 1);

  int ans = hl::tree_diameter(tree).first;
  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
