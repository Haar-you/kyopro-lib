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


# :heavy_check_mark: test/aoj/GRL_3_C/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#f4ad592153fe633f58e350fdd102799a">test/aoj/GRL_3_C</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_3_C/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-20 09:17:56+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/GraphUtils/strongly_connected_components.cpp.html">強連結成分分解</a>
* :question: <a href="../../../../library/Mylib/Graph/graph_template.cpp.html">グラフ用テンプレート</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/GraphUtils/strongly_connected_components.cpp"

int main(){
  int V, E; std::cin >> V >> E;

  Graph<int> g(V);
  for(int i = 0; i < E; ++i){
    int s, t; std::cin >> s >> t;
    add_edge(g, s, t, 1);
  }

  auto scc = SCC(g);

  int q; std::cin >> q;

  for(int i = 0; i < q; ++i){
    int u, v; std::cin >> u >> v;

    std::cout << (scc[u] == scc[v]) << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_3_C/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C"

#include <iostream>
#line 2 "Mylib/Graph/graph_template.cpp"
#include <vector>
#line 4 "Mylib/Graph/graph_template.cpp"

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
#line 3 "Mylib/Graph/GraphUtils/strongly_connected_components.cpp"
#include <algorithm>
#line 5 "Mylib/Graph/GraphUtils/strongly_connected_components.cpp"

/**
 * @title 強連結成分分解
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
#line 6 "test/aoj/GRL_3_C/main.test.cpp"

int main(){
  int V, E; std::cin >> V >> E;

  Graph<int> g(V);
  for(int i = 0; i < E; ++i){
    int s, t; std::cin >> s >> t;
    add_edge(g, s, t, 1);
  }

  auto scc = SCC(g);

  int q; std::cin >> q;

  for(int i = 0; i < q; ++i){
    int u, v; std::cin >> u >> v;

    std::cout << (scc[u] == scc[v]) << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

