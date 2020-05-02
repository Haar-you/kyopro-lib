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


# :warning: Mylib/Graph/TreeUtils/forest.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a41ea9974466d4f509bcbf59f2ee921e">Mylib/Graph/TreeUtils</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/TreeUtils/forest.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




## Depends on

* :question: <a href="../../DataStructure/UnionFind/unionfind.cpp.html">UnionFind</a>
* :question: <a href="../graph_template.cpp.html">グラフ用テンプレート</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <algorithm>
#include <utility>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/DataStructure/UnionFind/unionfind.cpp"

/**
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
    UnionFind uf(N);

    for(auto &v : g){
      for(auto &e : v){
        uf.merge(e.from, e.to);
      }
    }
    
    const int tree_num = uf.count_group();
    
    trees.resize(tree_num);

    tree_id.resize(N);
    vertex_id.resize(N);

    rid.resize(tree_num);

    std::vector<int> temp;
    for(int i = 0; i < N; ++i) temp.push_back(uf.get_root(i));
    std::sort(temp.begin(), temp.end());
    temp.erase(std::unique(temp.begin(), temp.end()), temp.end());

    for(int i = 0; i < N; ++i){
      tree_id[i] = std::lower_bound(temp.begin(), temp.end(), uf.get_root(i)) - temp.begin();
      vertex_id[i] = rid[tree_id[i]].size();
      rid[tree_id[i]].push_back(i);
    }

    for(int i = 0; i < tree_num; ++i){
      trees[i].resize(uf.get_size(temp[i]));
    }
    
    for(auto &v : g){
      for(auto &e : v){
        add_edge(trees[tree_id[e.from]], vertex_id[e.from], vertex_id[e.to], e.cost);
      }
    }
  }
  
  std::pair<int, int> forests_id(int i) const {
    return std::make_pair(tree_id[i], vertex_id[i]);
  }

  int original_id(int i, int j) const {
    return rid[i][j];
  }

  bool in_same_tree(int i, int j) const {
    return tree_id[i] == tree_id[j];
  }

  int get_tree_num() const {
    return trees.size();
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
#line 3 "Mylib/DataStructure/UnionFind/unionfind.cpp"
#include <numeric>

/**
 * @title UnionFind
 * @docs unionfind.md
 */
class UnionFind{
  std::vector<int> parent, depth, size;
  int count;

public:
  UnionFind(int n): parent(n), depth(n,1), size(n,1), count(n){
    std::iota(parent.begin(), parent.end(), 0);
  }
  
  inline int get_root(int i){
    if(parent[i] == i) return i;
    else return parent[i] = get_root(parent[i]);
  }
  
  inline bool is_same(int i, int j){return get_root(i) == get_root(j);}

  inline int merge(int i, int j){
    int ri = get_root(i), rj = get_root(j);
    if(ri == rj) return ri;
    else{
      --count;
      if(depth[ri] < depth[rj]){
        parent[ri] = rj;
        size[rj] += size[ri];
        return rj;
      }else{
        parent[rj] = ri;
        size[ri] += size[rj];
        if(depth[ri] == depth[rj]) ++depth[ri];
        return ri;
      }
    }
  }

  inline int get_size(int i){return size[get_root(i)];}

  inline int count_group(){return count;}
};
#line 7 "Mylib/Graph/TreeUtils/forest.cpp"

/**
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
    UnionFind uf(N);

    for(auto &v : g){
      for(auto &e : v){
        uf.merge(e.from, e.to);
      }
    }
    
    const int tree_num = uf.count_group();
    
    trees.resize(tree_num);

    tree_id.resize(N);
    vertex_id.resize(N);

    rid.resize(tree_num);

    std::vector<int> temp;
    for(int i = 0; i < N; ++i) temp.push_back(uf.get_root(i));
    std::sort(temp.begin(), temp.end());
    temp.erase(std::unique(temp.begin(), temp.end()), temp.end());

    for(int i = 0; i < N; ++i){
      tree_id[i] = std::lower_bound(temp.begin(), temp.end(), uf.get_root(i)) - temp.begin();
      vertex_id[i] = rid[tree_id[i]].size();
      rid[tree_id[i]].push_back(i);
    }

    for(int i = 0; i < tree_num; ++i){
      trees[i].resize(uf.get_size(temp[i]));
    }
    
    for(auto &v : g){
      for(auto &e : v){
        add_edge(trees[tree_id[e.from]], vertex_id[e.from], vertex_id[e.to], e.cost);
      }
    }
  }
  
  std::pair<int, int> forests_id(int i) const {
    return std::make_pair(tree_id[i], vertex_id[i]);
  }

  int original_id(int i, int j) const {
    return rid[i][j];
  }

  bool in_same_tree(int i, int j) const {
    return tree_id[i] == tree_id[j];
  }

  int get_tree_num() const {
    return trees.size();
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

