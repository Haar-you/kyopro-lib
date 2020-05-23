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


# :x: 森の分解

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a41ea9974466d4f509bcbf59f2ee921e">Mylib/Graph/TreeUtils</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/TreeUtils/forest.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-17 13:16:12+09:00




## Depends on

* :question: <a href="../graph_template.cpp.html">グラフ用テンプレート</a>


## Verified with

* :x: <a href="../../../../verify/test/yukicoder/922/main.test.cpp.html">test/yukicoder/922/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <algorithm>
#include <utility>
#include "Mylib/Graph/graph_template.cpp"

/**
 * @title 森の分解
 * @docs forest.md
 */
template <typename T>
struct Forest{
  std::vector<Tree<T>> trees;
  std::vector<int> tree_id;
  std::vector<int> vertex_id;
  std::vector<std::vector<int>> rid;

  Forest(const Graph<T> &g){
    const int N = g.size();

    tree_id.resize(N);
    vertex_id.resize(N);

    std::vector<bool> check(N);

    auto dfs =
      [&](auto &dfs, int cur, std::vector<int> &vertices, std::vector<Edge<T>> &edges) -> void{
        check[cur] = true;
        vertices.push_back(cur);

        for(auto &e : g[cur]){
          edges.push_back(e);

          if(not check[e.to]){
            dfs(dfs, e.to, vertices, edges);
          }
        }
      };

    for(int i = 0; i < N; ++i){
      if(not check[i]){
        std::vector<int> vertices;
        std::vector<Edge<T>> edges;
        dfs(dfs, i, vertices, edges);
        
        const int m = vertices.size(); 
        const int k = trees.size();

        rid.push_back(std::vector<int>(m));

        for(int i = 0; i < (int)vertices.size(); ++i){
          tree_id[vertices[i]] = k;
          vertex_id[vertices[i]] = i;
          rid[k][i] = vertices[i];
        }

        trees.push_back(Tree<T>(m));

        for(auto &e : edges){
          trees[k][vertex_id[e.from]].emplace_back(vertex_id[e.from], vertex_id[e.to], e.cost);
        }
      }
    }
  }
  
  bool in_same_tree(int i, int j) const {
    return tree_id[i] == tree_id[j];
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/TreeUtils/forest.cpp"
#include <vector>
#include <algorithm>
#include <utility>
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
#line 6 "Mylib/Graph/TreeUtils/forest.cpp"

/**
 * @title 森の分解
 * @docs forest.md
 */
template <typename T>
struct Forest{
  std::vector<Tree<T>> trees;
  std::vector<int> tree_id;
  std::vector<int> vertex_id;
  std::vector<std::vector<int>> rid;

  Forest(const Graph<T> &g){
    const int N = g.size();

    tree_id.resize(N);
    vertex_id.resize(N);

    std::vector<bool> check(N);

    auto dfs =
      [&](auto &dfs, int cur, std::vector<int> &vertices, std::vector<Edge<T>> &edges) -> void{
        check[cur] = true;
        vertices.push_back(cur);

        for(auto &e : g[cur]){
          edges.push_back(e);

          if(not check[e.to]){
            dfs(dfs, e.to, vertices, edges);
          }
        }
      };

    for(int i = 0; i < N; ++i){
      if(not check[i]){
        std::vector<int> vertices;
        std::vector<Edge<T>> edges;
        dfs(dfs, i, vertices, edges);
        
        const int m = vertices.size(); 
        const int k = trees.size();

        rid.push_back(std::vector<int>(m));

        for(int i = 0; i < (int)vertices.size(); ++i){
          tree_id[vertices[i]] = k;
          vertex_id[vertices[i]] = i;
          rid[k][i] = vertices[i];
        }

        trees.push_back(Tree<T>(m));

        for(auto &e : edges){
          trees[k][vertex_id[e.from]].emplace_back(vertex_id[e.from], vertex_id[e.to], e.cost);
        }
      }
    }
  }
  
  bool in_same_tree(int i, int j) const {
    return tree_id[i] == tree_id[j];
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

