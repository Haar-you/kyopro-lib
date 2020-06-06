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


# :heavy_check_mark: test/aoj/2370/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#149f439fdc492bcb6afb80a048374854">test/aoj/2370</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/2370/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2370">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2370</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/BipartiteGraph/check_bipartite_graph.cpp.html">Check bipartite graph</a>
* :question: <a href="../../../../library/Mylib/Graph/graph_template.cpp.html">Graph template</a>
* :question: <a href="../../../../library/Mylib/IO/input_graph.cpp.html">Mylib/IO/input_graph.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/TypicalProblem/SubsetSumProblem/subset_sum_limited.cpp.html">Subset sum problem (With quantity limitations)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2370"

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/BipartiteGraph/check_bipartite_graph.cpp"
#include "Mylib/TypicalProblem/SubsetSumProblem/subset_sum_limited.cpp"
#include "Mylib/IO/input_graph.cpp"

int main(){
  int V, E; std::cin >> V >> E;
  
  auto g = convert_to_graph<int, false>(V, input_edges<int, 1, false>(E));

  auto res = check_bipartite_graph(g);
  
  if(std::all_of(res.begin(), res.end(), [](const auto &a){return (bool)a;})){
    int k = 0;

    std::map<int, int> c;

    for(auto &x : res){
      int a = (*x).first.size();
      int b = (*x).second.size();

      k += std::min(a, b);
      
      c[std::abs(a-b)] += 1;
    }

    std::vector<int> a, m;
    for(auto &p : c){
      a.push_back(p.first);
      m.push_back(p.second);
    }

    auto r = subset_sum_limited(c.size(), V, a, m);

    int64_t ans = 0;

    for(int i = 0; i <= V; ++i){
      if(r[i]){
        int64_t a = k + i;
        ans = std::max(ans, a * (V - a));
      }
    }

    ans -= E;
    std::cout << ans << "\n";
  }else{
    std::cout << -1 << "\n";
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/2370/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2370"

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#line 4 "Mylib/Graph/graph_template.cpp"

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
#line 3 "Mylib/Graph/BipartiteGraph/check_bipartite_graph.cpp"
#include <optional>
#include <stack>
#include <utility>
#line 7 "Mylib/Graph/BipartiteGraph/check_bipartite_graph.cpp"

/**
 * @title Check bipartite graph
 * @docs check_bipartite_graph.md
 */
template <typename T>
auto check_bipartite_graph(const Graph<T> &g){
  std::vector<std::optional<std::pair<std::vector<int>, std::vector<int>>>> ret;

  const int N = g.size();

  std::vector<int> check(N, -1);
  std::vector<bool> visit(N);

  for(int i = 0; i < N; ++i){
    if(visit[i]) continue;

    std::vector<int> a, b;
      
    bool res =
      [&](){
        std::stack<int> st;
 
        st.push(i);
        check[i] = 0;
        a.push_back(i);

        while(not st.empty()){
          auto cur = st.top(); st.pop();
          if(visit[cur]) continue;
          visit[cur] = true;
 
          for(auto &e : g[cur]){
            if(check[e.to] == check[cur]) return false;
 
            if(check[e.to] == -1){
              if(check[cur] == 0){
                check[e.to] = 1;
                b.push_back(e.to);
              }else{
                check[e.to] = 0;
                a.push_back(e.to);
              }
          
              st.push(e.to);
            }
          }
        }

        return true;
      }();

    if(res){
      ret.push_back({{a, b}});
    }else{
      ret.push_back(std::nullopt);
    }
  }

  return ret;
}
#line 3 "Mylib/TypicalProblem/SubsetSumProblem/subset_sum_limited.cpp"

/**
 * @title Subset sum problem (With quantity limitations)
 * @docs subset_sum_limited.md
 */
auto subset_sum_limited(int N, int K, const std::vector<int> &a, const std::vector<int> &m){
  std::vector<int> dp(K+1, -1);

  dp[0] = 0;
  for(int i = 0; i < N; ++i){
    for(int j = 0; j <= K; ++j){
      if(dp[j] >= 0){
        dp[j] = m[i];
      }else if(j < a[i] or dp[j-a[i]] <= 0){
        dp[j] = -1;
      }else{
        dp[j] = dp[j-a[i]] - 1;
      }
    }
  }

  for(int i = 0; i <= K; ++i) dp[i] = dp[i] >= 0;

  return dp;
}
#line 4 "Mylib/IO/input_graph.cpp"

/**
 * @docs input_graph.md
 */
template <typename T, size_t I, bool WEIGHTED>
std::vector<Edge<T>> input_edges(int M){
  std::vector<Edge<T>> ret;
  
  for(int i = 0; i < M; ++i){
    int s, t; std::cin >> s >> t;
    s -= I;
    t -= I;
    T w = 1; if(WEIGHTED) std::cin >> w;
    ret.emplace_back(s, t, w);
  }
  
  return ret;  
}

template <typename T, bool DIRECTED>
Graph<T> convert_to_graph(int N, const std::vector<Edge<T>> &edges){
  Graph<T> g(N);

  for(const auto &e : edges){
    add_edge(g, e.from, e.to, e.cost);
    if(not DIRECTED) add_edge(g, e.to, e.from, e.cost);
  }
  
  return g;
}
#line 12 "test/aoj/2370/main.test.cpp"

int main(){
  int V, E; std::cin >> V >> E;
  
  auto g = convert_to_graph<int, false>(V, input_edges<int, 1, false>(E));

  auto res = check_bipartite_graph(g);
  
  if(std::all_of(res.begin(), res.end(), [](const auto &a){return (bool)a;})){
    int k = 0;

    std::map<int, int> c;

    for(auto &x : res){
      int a = (*x).first.size();
      int b = (*x).second.size();

      k += std::min(a, b);
      
      c[std::abs(a-b)] += 1;
    }

    std::vector<int> a, m;
    for(auto &p : c){
      a.push_back(p.first);
      m.push_back(p.second);
    }

    auto r = subset_sum_limited(c.size(), V, a, m);

    int64_t ans = 0;

    for(int i = 0; i <= V; ++i){
      if(r[i]){
        int64_t a = k + i;
        ans = std::max(ans, a * (V - a));
      }
    }

    ans -= E;
    std::cout << ans << "\n";
  }else{
    std::cout << -1 << "\n";
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

