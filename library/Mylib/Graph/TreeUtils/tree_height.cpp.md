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


# :x: Tree height

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a41ea9974466d4f509bcbf59f2ee921e">Mylib/Graph/TreeUtils</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/TreeUtils/tree_height.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Depends on

* :x: <a href="tree_distance.cpp.html">Tree distance</a>
* :question: <a href="../graph_template.cpp.html">Graph template</a>


## Verified with

* :x: <a href="../../../../verify/test/aoj/GRL_5_B/main.test.cpp.html">test/aoj/GRL_5_B/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <algorithm>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/TreeUtils/tree_distance.cpp"

/**
 * @title Tree height
 * @docs tree_height.md
 */
template <typename T>
std::vector<T> tree_height(const Tree<T> &tree){
  const int n = tree.size();

  auto d = tree_distance(tree, 0);
  int a = std::max_element(d.begin(), d.end()) - d.begin();
  auto d1 = tree_distance(tree, a);
  int b = std::max_element(d1.begin(), d1.end()) - d1.begin();
  auto d2 = tree_distance(tree, b);

  std::vector<T> h(n);
  for(int i = 0; i < n; ++i) h[i] = std::max(d1[i], d2[i]);
    
  return h;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/TreeUtils/tree_height.cpp"
#include <vector>
#include <algorithm>
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
#line 3 "Mylib/Graph/TreeUtils/tree_distance.cpp"
#include <stack>
#line 5 "Mylib/Graph/TreeUtils/tree_distance.cpp"

/**
 * @title Tree distance
 * @docs tree_distance.md
 */
template <typename T>
std::vector<T> tree_distance(const Tree<T> &tree, int root){
  const int n = tree.size();
  std::vector<T> ret(n);
  std::vector<bool> visited(n);
    
  std::stack<int> st;
  st.push(root);
  ret[root] = 0;
    
  while(not st.empty()){
    int cur = st.top(); st.pop();
    visited[cur] = true;
      
    for(auto &e : tree[cur]){
      if(not visited[e.to]){
        ret[e.to] = ret[cur] + e.cost;
        st.push(e.to);
      }
    }
  }
    
  return ret;
}
#line 6 "Mylib/Graph/TreeUtils/tree_height.cpp"

/**
 * @title Tree height
 * @docs tree_height.md
 */
template <typename T>
std::vector<T> tree_height(const Tree<T> &tree){
  const int n = tree.size();

  auto d = tree_distance(tree, 0);
  int a = std::max_element(d.begin(), d.end()) - d.begin();
  auto d1 = tree_distance(tree, a);
  int b = std::max_element(d1.begin(), d1.end()) - d1.begin();
  auto d2 = tree_distance(tree, b);

  std::vector<T> h(n);
  for(int i = 0; i < n; ++i) h[i] = std::max(d1[i], d2[i]);
    
  return h;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

