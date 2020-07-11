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


# :heavy_check_mark: test/yosupo-judge/two_edge_connected_components/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#caa543e8ce2b504963292c36b66ba2d6">test/yosupo-judge/two_edge_connected_components</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/two_edge_connected_components/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00


* see: <a href="https://judge.yosupo.jp/problem/two_edge_connected_components">https://judge.yosupo.jp/problem/two_edge_connected_components</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/GraphUtils/two_edge_connected_components.cpp.html">Two edge connected components</a>
* :question: <a href="../../../../library/Mylib/Graph/graph_template.cpp.html">Graph template</a>
* :question: <a href="../../../../library/Mylib/IO/input_graph.cpp.html">Mylib/IO/input_graph.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/join.cpp.html">Mylib/IO/join.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/GraphUtils/two_edge_connected_components.cpp"
#include "Mylib/IO/input_graph.cpp"
#include "Mylib/IO/join.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, M; std::cin >> N >> M;

  auto g = convert_to_graph<int, false>(N, input_edges<int, 0, false>(M));

  auto res = two_edge_connected_components(g);

  std::cout << res.size() << std::endl;
  for(auto &v : res){
    std::cout << v.size() << " " << join(v.begin(), v.end()) << "\n";
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/two_edge_connected_components/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

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
#line 3 "Mylib/Graph/GraphUtils/two_edge_connected_components.cpp"
#include <stack>
#line 5 "Mylib/Graph/GraphUtils/two_edge_connected_components.cpp"

/**
 * @title Two edge connected components
 * @docs two_edge_connected_components.md
 */
template <typename T>
auto two_edge_connected_components(const Graph<T> &graph){
  const int n = graph.size();

  std::vector<std::vector<int>> ret;
  std::vector<int> low(n, -1), order(n, -1);
  std::stack<int> st;

  int v = 0;
  auto dfs =
    [&](auto &dfs, int cur, int par) -> int {
      if(order[cur] != -1) return order[cur];
      order[cur] = v;
      int temp = v++;
      st.push(cur);      

      int count = 0;

      for(const auto &e : graph[cur]){
        if(e.to == par){
          ++count;
          if(count == 1) continue;
        }
        
        int t = dfs(dfs, e.to, cur);
        temp = std::min(temp, t);

        if(low[e.to] > order[cur]){ // e is a bridge
          std::vector<int> cc;
          while(true){
            int c = st.top();
            cc.emplace_back(c);
            st.pop();
            if(c == e.to) break;
          }
          ret.emplace_back(cc);
        }
      }

      return low[cur] = temp;
    };

  for(int i = 0; i < n; ++i){
    if(order[i] == -1){
      dfs(dfs, i, -1);
      if(not st.empty()){
        std::vector<int> cc;
        while(not st.empty()) cc.emplace_back(st.top()), st.pop();
        ret.emplace_back(cc);
      }
    }
  }

  return ret;
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
#line 8 "test/yosupo-judge/two_edge_connected_components/main.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, M; std::cin >> N >> M;

  auto g = convert_to_graph<int, false>(N, input_edges<int, 0, false>(M));

  auto res = two_edge_connected_components(g);

  std::cout << res.size() << std::endl;
  for(auto &v : res){
    std::cout << v.size() << " " << join(v.begin(), v.end()) << "\n";
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

