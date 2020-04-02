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


# :warning: Mylib/Graph/GraphUtils/decompose_pseudotree.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#0520734517f09caa086d1aa01fa4b9e4">Mylib/Graph/GraphUtils</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/GraphUtils/decompose_pseudotree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-01 05:19:32+09:00




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

template <typename T>
struct PseudoTree{
  const int n;
  std::vector<bool> in_loop;
  std::vector<int> group;

  void dfs(int cur, int par, const Graph<T> &g){
    group[cur] = group[par];

    for(auto &e : g[cur]){
      if(e.to == par) continue;
      dfs(e.to, cur, g);
    }
  }
  
  PseudoTree(const Graph<T> &g): n(g.size()), in_loop(n, true), group(n){
    std::vector<int> indeg(n);
    std::vector<bool> visited(n);
    std::queue<int> q;

    for(int i = 0; i < n; ++i){
      for(auto &e : g[i]){
        ++indeg[e.to];
      }
    }

    for(int i = 0; i < n; ++i){
      if(indeg[i] == 1){
        q.push(i);
      }
    }

    while(not q.empty()){
      int cur = q.front(); q.pop();

      in_loop[cur] = false;

      if(visited[cur]) continue;
      visited[cur] = true;
      
      for(auto &e : g[cur]){
        if(not visited[e.to]){
          --indeg[e.to];
          if(indeg[e.to] == 1){
            q.push(e.to);
          }
        }
      }
    }

    for(int i = 0; i < n; ++i){
      if(in_loop[i]){
        for(auto &e : g[i]){
          if(not in_loop[e.to]){
            group[i] = i;
            dfs(e.to, i, g);
            break;
          }
        }
      }
    }
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/GraphUtils/decompose_pseudotree.cpp"
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
#line 5 "Mylib/Graph/GraphUtils/decompose_pseudotree.cpp"

template <typename T>
struct PseudoTree{
  const int n;
  std::vector<bool> in_loop;
  std::vector<int> group;

  void dfs(int cur, int par, const Graph<T> &g){
    group[cur] = group[par];

    for(auto &e : g[cur]){
      if(e.to == par) continue;
      dfs(e.to, cur, g);
    }
  }
  
  PseudoTree(const Graph<T> &g): n(g.size()), in_loop(n, true), group(n){
    std::vector<int> indeg(n);
    std::vector<bool> visited(n);
    std::queue<int> q;

    for(int i = 0; i < n; ++i){
      for(auto &e : g[i]){
        ++indeg[e.to];
      }
    }

    for(int i = 0; i < n; ++i){
      if(indeg[i] == 1){
        q.push(i);
      }
    }

    while(not q.empty()){
      int cur = q.front(); q.pop();

      in_loop[cur] = false;

      if(visited[cur]) continue;
      visited[cur] = true;
      
      for(auto &e : g[cur]){
        if(not visited[e.to]){
          --indeg[e.to];
          if(indeg[e.to] == 1){
            q.push(e.to);
          }
        }
      }
    }

    for(int i = 0; i < n; ++i){
      if(in_loop[i]){
        for(auto &e : g[i]){
          if(not in_loop[e.to]){
            group[i] = i;
            dfs(e.to, i, g);
            break;
          }
        }
      }
    }
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

