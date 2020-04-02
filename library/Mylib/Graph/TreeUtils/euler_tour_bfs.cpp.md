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


# :warning: Mylib/Graph/TreeUtils/euler_tour_bfs.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a41ea9974466d4f509bcbf59f2ee921e">Mylib/Graph/TreeUtils</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/TreeUtils/euler_tour_bfs.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-01 05:19:32+09:00


* see: <a href="https://yukicoder.me/submissions/390077">https://yukicoder.me/submissions/390077</a>


## Depends on

* :question: <a href="../graph_template.cpp.html">Mylib/Graph/graph_template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <queue>
#include "Mylib/Graph/graph_template.cpp"

/**
 * @see https://yukicoder.me/submissions/390077
 */
template <typename T> struct EulerTourBFS{
  Tree<T> tree;
  int N;
  std::vector<int> bfs_order;
  std::vector<int> parent;

  EulerTourBFS(const Tree<T> &tree, int root): tree(tree), N(tree.size()), bfs_order(N, -1), parent(N, -1){
    std::vector<bool> visited(N);
    std::queue<int> q;
    q.push(root);

    int i = 0;
    while(q.size()){
      int cur = q.front(); q.pop();

      if(visited[cur]) continue;
      visited[cur] = true;

      bfs_order[cur] = i;
      ++i;

      for(auto &e : tree[cur]){
        if(not visited[e.to]){
          q.push(e.to);
        }
      }
    }
    
    dfs_parent(root, -1);
  }

  void dfs_parent(int cur, int par){
    parent[cur] = par;
    
    for(auto it = tree[cur].begin(); it != tree[cur].end(); ++it){
      if(it->to == par){
        tree[cur].erase(it);
        break;
      }
    }
    
    for(auto &e : tree[cur]){
      if(e.to == par) continue;
      dfs_parent(e.to, cur);
    }
  }

public:
  inline int get_parent(int i) const {
    if(i == -1) return -1;
    return parent[i];
  }
  
  template <typename Func> inline void query_at(int i, const Func &f) const {
    if(i != -1){
      f(bfs_order[i], bfs_order[i]+1);
    }
  }

  template <typename Func> inline void query_children(int i, const Func &f) const {
    if(i != -1 and tree[i].size()){
      f(bfs_order[tree[i].front().to], bfs_order[tree[i].back().to]+1);
    }
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/TreeUtils/euler_tour_bfs.cpp"
#include <vector>
#include <queue>
#line 3 "Mylib/Graph/graph_template.cpp"
#include <iostream>

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
#line 5 "Mylib/Graph/TreeUtils/euler_tour_bfs.cpp"

/**
 * @see https://yukicoder.me/submissions/390077
 */
template <typename T> struct EulerTourBFS{
  Tree<T> tree;
  int N;
  std::vector<int> bfs_order;
  std::vector<int> parent;

  EulerTourBFS(const Tree<T> &tree, int root): tree(tree), N(tree.size()), bfs_order(N, -1), parent(N, -1){
    std::vector<bool> visited(N);
    std::queue<int> q;
    q.push(root);

    int i = 0;
    while(q.size()){
      int cur = q.front(); q.pop();

      if(visited[cur]) continue;
      visited[cur] = true;

      bfs_order[cur] = i;
      ++i;

      for(auto &e : tree[cur]){
        if(not visited[e.to]){
          q.push(e.to);
        }
      }
    }
    
    dfs_parent(root, -1);
  }

  void dfs_parent(int cur, int par){
    parent[cur] = par;
    
    for(auto it = tree[cur].begin(); it != tree[cur].end(); ++it){
      if(it->to == par){
        tree[cur].erase(it);
        break;
      }
    }
    
    for(auto &e : tree[cur]){
      if(e.to == par) continue;
      dfs_parent(e.to, cur);
    }
  }

public:
  inline int get_parent(int i) const {
    if(i == -1) return -1;
    return parent[i];
  }
  
  template <typename Func> inline void query_at(int i, const Func &f) const {
    if(i != -1){
      f(bfs_order[i], bfs_order[i]+1);
    }
  }

  template <typename Func> inline void query_children(int i, const Func &f) const {
    if(i != -1 and tree[i].size()){
      f(bfs_order[tree[i].front().to], bfs_order[tree[i].back().to]+1);
    }
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

