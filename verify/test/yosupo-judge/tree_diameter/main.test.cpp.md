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
    - Last commit date: 2020-06-02 05:58:35+09:00


* see: <a href="https://judge.yosupo.jp/problem/tree_diameter">https://judge.yosupo.jp/problem/tree_diameter</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Graph/TreeUtils/tree_diameter.cpp.html">Tree diameter</a>
* :question: <a href="../../../../library/Mylib/Graph/graph_template.cpp.html">Graph template</a>
* :question: <a href="../../../../library/Mylib/IO/input_graph.cpp.html">Mylib/IO/input_graph.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/join.cpp.html">Mylib/IO/join.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/TreeUtils/tree_diameter.cpp"
#include "Mylib/IO/input_graph.cpp"
#include "Mylib/IO/join.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N; std::cin >> N;

  auto tree = convert_to_graph<int64_t, false>(N, input_edges<int64_t, 0, true>(N-1));

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
#line 2 "Mylib/Graph/graph_template.cpp"
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
#line 4 "Mylib/IO/input_graph.cpp"

/**
 * @docs input_graph.md
 */
template <typename T, size_t I, bool WEIGHTED>
std::vector<Edge<T>> input_edges(int M){
  std::vector<Edge<T>> ret;
  
  for(int i = 0; i < M; ++i){
    int s, t; std::cin >> s >> t;
    s -= I;
    t -= I;
    T w = 1; if(WEIGHTED) std::cin >> w;
    ret.emplace_back(s, t, w);
  }
  
  return ret;  
}

template <typename T, bool DIRECTED>
Graph<T> convert_to_graph(int N, const std::vector<Edge<T>> &edges){
  Graph<T> g(N);

  for(const auto &e : edges){
    add_edge(g, e.from, e.to, e.cost);
    if(not DIRECTED) add_edge(g, e.to, e.from, e.cost);
  }
  
  return g;
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
#line 8 "test/yosupo-judge/tree_diameter/main.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N; std::cin >> N;

  auto tree = convert_to_graph<int64_t, false>(N, input_edges<int64_t, 0, true>(N-1));

  auto [cost, path] = tree_diameter(tree);

  std::cout
    << cost << " " << path.size() << "\n"
    << join(path.begin(), path.end()) << "\n";

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

