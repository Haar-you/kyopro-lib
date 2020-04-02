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


# :heavy_check_mark: test/aoj/GRL_3_A/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#aef3de7eebed1830b43d31dc4a561484">test/aoj/GRL_3_A</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_3_A/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-01 05:19:32+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A&lang=ja">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A&lang=ja</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/GraphUtils/articulation_points.cpp.html">Mylib/Graph/GraphUtils/articulation_points.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/graph_template.cpp.html">Mylib/Graph/graph_template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A&lang=ja"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/GraphUtils/articulation_points.cpp"

int main(){
  int V, E; std::cin >> V >> E;

  Graph<int> g(V);
  for(int i = 0; i < E; ++i){
    int s, t; std::cin >> s >> t;
    add_undirected(g, s, t, 1);
  }

  auto ans = articulation_points(g);
  sort(ans.begin(), ans.end());
  
  for(auto x : ans) std::cout << x << std::endl;

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_3_A/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A&lang=ja"

#include <iostream>
#line 2 "Mylib/Graph/graph_template.cpp"
#include <vector>
#line 4 "Mylib/Graph/graph_template.cpp"

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
#line 3 "Mylib/Graph/GraphUtils/articulation_points.cpp"
#include <algorithm>
#line 5 "Mylib/Graph/GraphUtils/articulation_points.cpp"

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
#line 6 "test/aoj/GRL_3_A/main.test.cpp"

int main(){
  int V, E; std::cin >> V >> E;

  Graph<int> g(V);
  for(int i = 0; i < E; ++i){
    int s, t; std::cin >> s >> t;
    add_undirected(g, s, t, 1);
  }

  auto ans = articulation_points(g);
  sort(ans.begin(), ans.end());
  
  for(auto x : ans) std::cout << x << std::endl;

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

