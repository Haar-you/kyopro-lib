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


# :x: test/yosupo-judge/tree_diameter/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#fc38206dcd10be708e58c9df7503cac7">test/yosupo-judge/tree_diameter</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/tree_diameter/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 11:15:59+09:00


* see: <a href="https://judge.yosupo.jp/problem/tree_diameter">https://judge.yosupo.jp/problem/tree_diameter</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Graph/Template/graph.cpp.html">Basic graph</a>
* :x: <a href="../../../../library/Mylib/Graph/TreeUtils/tree_diameter.cpp.html">Tree diameter</a>
* :x: <a href="../../../../library/Mylib/IO/join.cpp.html">Mylib/IO/join.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include <iostream>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/TreeUtils/tree_diameter.cpp"
#include "Mylib/IO/join.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N; std::cin >> N;

  Tree<int64_t> tree(N);
  tree.read<0, false>(N - 1);

  auto [cost, path] = tree_diameter(tree);

  std::cout
    << cost << " " << path.size() << "\n"
    << join(path.begin(), path.end()) << "\n";

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/tree_diameter/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include <iostream>
#line 2 "Mylib/Graph/Template/graph.cpp"
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
#line 3 "Mylib/Graph/TreeUtils/tree_diameter.cpp"
#include <utility>
#include <stack>
#include <algorithm>
#line 7 "Mylib/Graph/TreeUtils/tree_diameter.cpp"

/**
 * @title Tree diameter
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
#line 3 "Mylib/IO/join.cpp"
#include <sstream>
#include <string>

/**
 * @docs join.md
 */
template <typename ITER>
std::string join(ITER first, ITER last, std::string delim = " "){
  std::stringstream s;

  for(auto it = first; it != last; ++it){
    if(it != first) s << delim;
    s << *it;
  }

  return s.str();
}
#line 7 "test/yosupo-judge/tree_diameter/main.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N; std::cin >> N;

  Tree<int64_t> tree(N);
  tree.read<0, false>(N - 1);

  auto [cost, path] = tree_diameter(tree);

  std::cout
    << cost << " " << path.size() << "\n"
    << join(path.begin(), path.end()) << "\n";

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

