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


# :heavy_check_mark: 間接点列挙

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#0520734517f09caa086d1aa01fa4b9e4">Mylib/Graph/GraphUtils</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/GraphUtils/articulation_points.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




## Depends on

* :heavy_check_mark: <a href="../graph_template.cpp.html">グラフ用テンプレート</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/GRL_3_A/main.test.cpp.html">test/aoj/GRL_3_A/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <algorithm>
#include "Mylib/Graph/graph_template.cpp"

/**
 * @title 間接点列挙
 * @docs articulation_points.md
 */
template <typename T> std::vector<int> articulation_points(const Graph<T> &graph){
  int n = graph.size();
  std::vector<int> visit(n, -1), low(n, -1), ret;

  int v = 0;
  
  auto dfs =
    [&](auto &&dfs, int cur){
      if(visit[cur] != -1) return visit[cur];
      visit[cur] = v;

      int temp = v;
      std::vector<int> children;
      ++v;

      for(auto &e : graph[cur]){
        if(visit[e.to] == -1) children.push_back(e.to);
        int t = dfs(dfs, e.to);
        temp = std::min(temp, t);
      }

      low[cur] = temp;

      if((cur != 0 or children.size() >= 2) and std::any_of(children.begin(), children.end(), [&](int x){return low[x] >= visit[cur];})){
        ret.push_back(cur);
      }

      return low[cur];
    };

  
  for(int i = 0; i < n; ++i){
    if(visit[i] == -1){
      dfs(dfs, i);
    }
  }

  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/GraphUtils/articulation_points.cpp"
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
#line 5 "Mylib/Graph/GraphUtils/articulation_points.cpp"

/**
 * @title 間接点列挙
 * @docs articulation_points.md
 */
template <typename T> std::vector<int> articulation_points(const Graph<T> &graph){
  int n = graph.size();
  std::vector<int> visit(n, -1), low(n, -1), ret;

  int v = 0;
  
  auto dfs =
    [&](auto &&dfs, int cur){
      if(visit[cur] != -1) return visit[cur];
      visit[cur] = v;

      int temp = v;
      std::vector<int> children;
      ++v;

      for(auto &e : graph[cur]){
        if(visit[e.to] == -1) children.push_back(e.to);
        int t = dfs(dfs, e.to);
        temp = std::min(temp, t);
      }

      low[cur] = temp;

      if((cur != 0 or children.size() >= 2) and std::any_of(children.begin(), children.end(), [&](int x){return low[x] >= visit[cur];})){
        ret.push_back(cur);
      }

      return low[cur];
    };

  
  for(int i = 0; i < n; ++i){
    if(visit[i] == -1){
      dfs(dfs, i);
    }
  }

  return ret;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

