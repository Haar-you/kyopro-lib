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
    - Last commit date: 2020-04-20 09:17:56+09:00


* see: <a href="https://judge.yosupo.jp/problem/two_edge_connected_components">https://judge.yosupo.jp/problem/two_edge_connected_components</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/GraphUtils/two_edge_connected_components.cpp.html">二重辺連結成分分解</a>
* :question: <a href="../../../../library/Mylib/Graph/graph_template.cpp.html">グラフ用テンプレート</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/GraphUtils/two_edge_connected_components.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, M; std::cin >> N >> M;

  Graph<int> g(N);
  for(int i = 0; i < M; ++i){
    int a, b; std::cin >> a >> b;
    add_undirected(g, a, b, 1);
  }

  auto res = two_edge_connected_components(g);

  std::cout << res.size() << std::endl;
  for(auto &v : res){
    std::cout << v.size();
    for(auto x : v) std::cout << " " << x;
    std::cout << std::endl;
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
 * @title グラフ用テンプレート
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
 * @title 二重辺連結成分分解
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

#line 6 "test/yosupo-judge/two_edge_connected_components/main.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, M; std::cin >> N >> M;

  Graph<int> g(N);
  for(int i = 0; i < M; ++i){
    int a, b; std::cin >> a >> b;
    add_undirected(g, a, b, 1);
  }

  auto res = two_edge_connected_components(g);

  std::cout << res.size() << std::endl;
  for(auto &v : res){
    std::cout << v.size();
    for(auto x : v) std::cout << " " << x;
    std::cout << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

