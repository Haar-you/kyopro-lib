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


# :heavy_check_mark: 強連結成分分解

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#0520734517f09caa086d1aa01fa4b9e4">Mylib/Graph/GraphUtils</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/GraphUtils/strongly_connected_components.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




## Depends on

* :question: <a href="../graph_template.cpp.html">グラフ用テンプレート</a>


## Required by

* :heavy_check_mark: <a href="../two_sat.cpp.html">2-SAT</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/GRL_3_C/main.test.cpp.html">test/aoj/GRL_3_C/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/yosupo-judge/scc/main.test.cpp.html">test/yosupo-judge/scc/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/yosupo-judge/two_sat/main.test.cpp.html">test/yosupo-judge/two_sat/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <algorithm>
#include "Mylib/Graph/graph_template.cpp"

/**
 * @title 強連結成分分解
 * @docs strongly_connected_components.md
 */
template <typename T>
struct SCC{
  std::vector<int> result;
  int scc_size;
  
private:
  std::vector<bool> visit;
  std::vector<int> check;
  
  void dfs(int cur, const Graph<T> &graph){
    visit[cur] = true;
    for(auto &e : graph[cur]){
      if(not visit[e.to]) dfs(e.to,graph);
    }
    check.push_back(cur);
  }

  void rdfs(int cur, int i, const Graph<T> &rgraph){
    result[cur] = i;
    for(auto &e : rgraph[cur]){
      if(result[e.to] == -1) rdfs(e.to,i,rgraph);
    }
  }

public:
  SCC(const Graph<T> &graph){
    const int n = graph.size();
    result.assign(n, -1);
    visit.assign(n, false);
    
    for(int i = 0; i < n; ++i) if(!visit[i]) dfs(i,graph);
    std::reverse(check.begin(), check.end());
    
    Graph<T> rgraph(n);
    for(int i = 0; i < n; ++i) for(auto &e : graph[i]) rgraph[e.to].emplace_back(e.to, e.from, e.cost);

    int i = 0;
    for(auto c : check) if(result[c] == -1) {rdfs(c,i,rgraph); ++i;}
    scc_size = i;
  }

  inline const int operator[](int i) const {return result[i];}
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/GraphUtils/strongly_connected_components.cpp"
#include <vector>
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
#line 5 "Mylib/Graph/GraphUtils/strongly_connected_components.cpp"

/**
 * @title 強連結成分分解
 * @docs strongly_connected_components.md
 */
template <typename T>
struct SCC{
  std::vector<int> result;
  int scc_size;
  
private:
  std::vector<bool> visit;
  std::vector<int> check;
  
  void dfs(int cur, const Graph<T> &graph){
    visit[cur] = true;
    for(auto &e : graph[cur]){
      if(not visit[e.to]) dfs(e.to,graph);
    }
    check.push_back(cur);
  }

  void rdfs(int cur, int i, const Graph<T> &rgraph){
    result[cur] = i;
    for(auto &e : rgraph[cur]){
      if(result[e.to] == -1) rdfs(e.to,i,rgraph);
    }
  }

public:
  SCC(const Graph<T> &graph){
    const int n = graph.size();
    result.assign(n, -1);
    visit.assign(n, false);
    
    for(int i = 0; i < n; ++i) if(!visit[i]) dfs(i,graph);
    std::reverse(check.begin(), check.end());
    
    Graph<T> rgraph(n);
    for(int i = 0; i < n; ++i) for(auto &e : graph[i]) rgraph[e.to].emplace_back(e.to, e.from, e.cost);

    int i = 0;
    for(auto c : check) if(result[c] == -1) {rdfs(c,i,rgraph); ++i;}
    scc_size = i;
  }

  inline const int operator[](int i) const {return result[i];}
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
