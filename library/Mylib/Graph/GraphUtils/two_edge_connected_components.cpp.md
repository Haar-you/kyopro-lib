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


# :heavy_check_mark: 二重辺連結成分分解

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#0520734517f09caa086d1aa01fa4b9e4">Mylib/Graph/GraphUtils</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/GraphUtils/two_edge_connected_components.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 18:35:49+09:00




## Depends on

* :heavy_check_mark: <a href="../graph_template.cpp.html">グラフ用テンプレート</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/yosupo-judge/two_edge_connected_components/main.test.cpp.html">test/yosupo-judge/two_edge_connected_components/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <stack>
#include "Mylib/Graph/graph_template.cpp"

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


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/GraphUtils/two_edge_connected_components.cpp"
#include <vector>
#include <stack>
#line 3 "Mylib/Graph/graph_template.cpp"
#include <iostream>

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

  Edge rev() const {return Edge(to,from,cost);}
  
  friend std::ostream& operator<<(std::ostream &os, const Edge &e){
    os << "(FROM: " << e.from << "," << "TO: " << e.to << "," << "COST: " << e.cost << ")";
    return os;
  }
};

template <typename T> using Graph = std::vector<std::vector<Edge<T>>>;
template <typename T> using Tree = std::vector<std::vector<Edge<T>>>;

template <typename C, typename T> void add_edge(C &g, int from, int to, T w){
  g[from].emplace_back(from, to, w);
}

template <typename C, typename T> void add_undirected(C &g, int a, int b, T w){
  add_edge(g, a, b, w);
  add_edge(g, b, a, w);
}
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


```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

