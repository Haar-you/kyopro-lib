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


# :x: test/aoj/GRL_2_A/main.prim.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#81ed75a9aa7f4e6edc886499b1a67fa4">test/aoj/GRL_2_A</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_2_A/main.prim.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Graph/MinimumSpanningTree/prim.cpp.html">Prim法</a>
* :question: <a href="../../../../library/Mylib/Graph/graph_template.cpp.html">グラフ用テンプレート</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/MinimumSpanningTree/prim.cpp"

int main(){
  int V, E; std::cin >> V >> E;
  
  Graph<int64_t> g(V);
  for(int i = 0; i < E; ++i){
    int s, t, d; std::cin >> s >> t >> d;
    add_undirected(g, s, t, (int64_t)d);
  }

  auto res = prim(g);

  int64_t ans = 0;
  for(auto &e : res) ans += e.cost; 
  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_2_A/main.prim.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"

#include <iostream>
#line 2 "Mylib/Graph/graph_template.cpp"
#include <vector>
#line 4 "Mylib/Graph/graph_template.cpp"

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
#line 3 "Mylib/Graph/MinimumSpanningTree/prim.cpp"
#include <queue>
#line 5 "Mylib/Graph/MinimumSpanningTree/prim.cpp"

/**
 * @title Prim法
 * @docs prim.md
 */
template <typename T>
std::vector<Edge<T>> prim(const Graph<T> &graph){
  int n = graph.size();
  std::vector<bool> visit(n, false);
  std::vector<Edge<T>> ret;

  auto cmp = [](const auto &a, const auto &b){return a.cost > b.cost;};
  std::priority_queue<Edge<T>, std::vector<Edge<T>>, decltype(cmp)> pq(cmp);
  
  visit[0] = true;
  for(auto &e : graph[0]) pq.push(e);

  while(not pq.empty()){
    auto t = pq.top(); pq.pop();

    if(visit[t.from] == visit[t.to]) continue;

    int i = visit[t.from] ? t.to : t.from;
    for(auto &e : graph[i]){
      pq.push(e);
    }

    visit[i] = true;
    ret.push_back(t);
  }

  return ret;
}
#line 6 "test/aoj/GRL_2_A/main.prim.test.cpp"

int main(){
  int V, E; std::cin >> V >> E;
  
  Graph<int64_t> g(V);
  for(int i = 0; i < E; ++i){
    int s, t, d; std::cin >> s >> t >> d;
    add_undirected(g, s, t, (int64_t)d);
  }

  auto res = prim(g);

  int64_t ans = 0;
  for(auto &e : res) ans += e.cost; 
  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

