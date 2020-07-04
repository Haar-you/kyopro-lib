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


# :heavy_check_mark: Check bipartite graph

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#3b87eee7aef75da88610c966a8da844f">Mylib/Graph/BipartiteGraph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/BipartiteGraph/check_bipartite_graph.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Operations

## Requirements

## Notes

## Problems

- [Maximum-Cup 2018 C - 嘘つきな天使たち](https://atcoder.jp/contests/maximum-cup-2018/tasks/maximum_cup_2018_c)
- [ARC 099 E - Independence](https://atcoder.jp/contests/arc099/tasks/arc099_c)

## References



## Depends on

* :heavy_check_mark: <a href="../graph_template.cpp.html">Graph template</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/2370/main.test.cpp.html">test/aoj/2370/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <optional>
#include <stack>
#include <utility>
#include "Mylib/Graph/graph_template.cpp"

/**
 * @title Check bipartite graph
 * @docs check_bipartite_graph.md
 */
template <typename T>
auto check_bipartite_graph(const Graph<T> &g){
  std::vector<std::optional<std::pair<std::vector<int>, std::vector<int>>>> ret;

  const int N = g.size();

  std::vector<int> check(N, -1);
  std::vector<bool> visit(N);

  for(int i = 0; i < N; ++i){
    if(visit[i]) continue;

    std::vector<int> a, b;
      
    bool res =
      [&](){
        std::stack<int> st;
 
        st.push(i);
        check[i] = 0;
        a.push_back(i);

        while(not st.empty()){
          auto cur = st.top(); st.pop();
          if(visit[cur]) continue;
          visit[cur] = true;
 
          for(auto &e : g[cur]){
            if(check[e.to] == check[cur]) return false;
 
            if(check[e.to] == -1){
              if(check[cur] == 0){
                check[e.to] = 1;
                b.push_back(e.to);
              }else{
                check[e.to] = 0;
                a.push_back(e.to);
              }
          
              st.push(e.to);
            }
          }
        }

        return true;
      }();

    if(res){
      ret.push_back({{a, b}});
    }else{
      ret.push_back(std::nullopt);
    }
  }

  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/BipartiteGraph/check_bipartite_graph.cpp"
#include <vector>
#include <optional>
#include <stack>
#include <utility>
#line 3 "Mylib/Graph/graph_template.cpp"
#include <iostream>

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
#line 7 "Mylib/Graph/BipartiteGraph/check_bipartite_graph.cpp"

/**
 * @title Check bipartite graph
 * @docs check_bipartite_graph.md
 */
template <typename T>
auto check_bipartite_graph(const Graph<T> &g){
  std::vector<std::optional<std::pair<std::vector<int>, std::vector<int>>>> ret;

  const int N = g.size();

  std::vector<int> check(N, -1);
  std::vector<bool> visit(N);

  for(int i = 0; i < N; ++i){
    if(visit[i]) continue;

    std::vector<int> a, b;
      
    bool res =
      [&](){
        std::stack<int> st;
 
        st.push(i);
        check[i] = 0;
        a.push_back(i);

        while(not st.empty()){
          auto cur = st.top(); st.pop();
          if(visit[cur]) continue;
          visit[cur] = true;
 
          for(auto &e : g[cur]){
            if(check[e.to] == check[cur]) return false;
 
            if(check[e.to] == -1){
              if(check[cur] == 0){
                check[e.to] = 1;
                b.push_back(e.to);
              }else{
                check[e.to] = 0;
                a.push_back(e.to);
              }
          
              st.push(e.to);
            }
          }
        }

        return true;
      }();

    if(res){
      ret.push_back({{a, b}});
    }else{
      ret.push_back(std::nullopt);
    }
  }

  return ret;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

