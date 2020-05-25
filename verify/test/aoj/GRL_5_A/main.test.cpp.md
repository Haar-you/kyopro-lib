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


# :heavy_check_mark: test/aoj/GRL_5_A/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a624c615c8a90227d4c31dd34d7dfde1">test/aoj/GRL_5_A</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_5_A/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-24 12:01:27+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/TreeUtils/tree_diameter.cpp.html">木の直径</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/graph_template.cpp.html">グラフ用テンプレート</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A"

#include <iostream>
#include <tuple>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/TreeUtils/tree_diameter.cpp"

int main(){
  int n; std::cin >> n;
  Tree<int> tree(n);

  for(int i = 0; i < n-1; ++i){
    int s, t, w; std::cin >> s >> t >> w;
    add_undirected(tree, s, t, w);
  }

  int ans;
  std::tie(ans, std::ignore) = tree_diameter(tree);
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
#line 3 "Mylib/Graph/TreeUtils/tree_diameter.cpp"
#include <utility>
#include <stack>
#include <algorithm>
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
#line 7 "test/aoj/GRL_5_A/main.test.cpp"

int main(){
  int n; std::cin >> n;
  Tree<int> tree(n);

  for(int i = 0; i < n-1; ++i){
    int s, t, w; std::cin >> s >> t >> w;
    add_undirected(tree, s, t, w);
  }

  int ans;
  std::tie(ans, std::ignore) = tree_diameter(tree);
  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

