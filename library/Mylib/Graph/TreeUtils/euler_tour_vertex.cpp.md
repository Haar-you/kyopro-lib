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


# :heavy_check_mark: 頂点Euler tour

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a41ea9974466d4f509bcbf59f2ee921e">Mylib/Graph/TreeUtils</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/TreeUtils/euler_tour_vertex.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 18:35:49+09:00




## Depends on

* :heavy_check_mark: <a href="../graph_template.cpp.html">グラフ用テンプレート</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/yosupo-judge/vertex_add_subtree_sum/main.euler_tour.test.cpp.html">test/yosupo-judge/vertex_add_subtree_sum/main.euler_tour.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include "Mylib/Graph/graph_template.cpp"

/**
 * @title 頂点Euler tour
 */
template <typename T> class EulerTourVertex{
  int pos = 0;
  std::vector<int> begin, end;

  void dfs(int cur, int par, const Tree<T> &tree){
    begin[cur] = pos++;
	
    for(auto &e : tree[cur]){
      if(e.to == par) continue;
      dfs(e.to, cur, tree);
    }

    end[cur] = pos;
  }

public:
  EulerTourVertex(const Tree<T> &tree, int root): begin(tree.size()), end(tree.size()){
    dfs(root, -1, tree);
  }

  template <typename F> // F = std::function<void(int,int)>
  void subtree_query(int i, const F &f){
    f(begin[i], end[i]);
  }

  template <typename F> // F = std::function<void(int)>
  void point_query(int i, const F &f){
    f(begin[i]);
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/TreeUtils/euler_tour_vertex.cpp"
#include <vector>
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
#line 4 "Mylib/Graph/TreeUtils/euler_tour_vertex.cpp"

/**
 * @title 頂点Euler tour
 */
template <typename T> class EulerTourVertex{
  int pos = 0;
  std::vector<int> begin, end;

  void dfs(int cur, int par, const Tree<T> &tree){
    begin[cur] = pos++;
	
    for(auto &e : tree[cur]){
      if(e.to == par) continue;
      dfs(e.to, cur, tree);
    }

    end[cur] = pos;
  }

public:
  EulerTourVertex(const Tree<T> &tree, int root): begin(tree.size()), end(tree.size()){
    dfs(root, -1, tree);
  }

  template <typename F> // F = std::function<void(int,int)>
  void subtree_query(int i, const F &f){
    f(begin[i], end[i]);
  }

  template <typename F> // F = std::function<void(int)>
  void point_query(int i, const F &f){
    f(begin[i]);
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

