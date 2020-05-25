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


# :heavy_check_mark: 木の直径

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a41ea9974466d4f509bcbf59f2ee921e">Mylib/Graph/TreeUtils</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/TreeUtils/tree_diameter.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-19 10:56:49+09:00




## Depends on

* :heavy_check_mark: <a href="../graph_template.cpp.html">グラフ用テンプレート</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/GRL_5_A/main.test.cpp.html">test/aoj/GRL_5_A/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/yosupo-judge/tree_diameter/main.test.cpp.html">test/yosupo-judge/tree_diameter/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <utility>
#include <stack>
#include <algorithm>
#include "Mylib/Graph/graph_template.cpp"

/**
 * @title 木の直径
 * @docs tree_diameter.md
 */
template <typename T>
std::pair<T, std::vector<int>> tree_diameter(const Tree<T> &tree){
  const int N = tree.size();

  std::vector<bool> check(N);
  std::vector<T> dp(N);
  std::stack<int> st;

  st.push(0);
  while(st.size()){
    int i = st.top(); st.pop();

    check[i] = true;

    for(const auto &e : tree[i]){
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

    for(const auto &e : tree[i]){
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/TreeUtils/tree_diameter.cpp"
#include <vector>
#include <utility>
#include <stack>
#include <algorithm>
#line 3 "Mylib/Graph/graph_template.cpp"
#include <iostream>

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
#line 7 "Mylib/Graph/TreeUtils/tree_diameter.cpp"

/**
 * @title 木の直径
 * @docs tree_diameter.md
 */
template <typename T>
std::pair<T, std::vector<int>> tree_diameter(const Tree<T> &tree){
  const int N = tree.size();

  std::vector<bool> check(N);
  std::vector<T> dp(N);
  std::stack<int> st;

  st.push(0);
  while(st.size()){
    int i = st.top(); st.pop();

    check[i] = true;

    for(const auto &e : tree[i]){
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

    for(const auto &e : tree[i]){
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

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

