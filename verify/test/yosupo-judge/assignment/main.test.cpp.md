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


# :heavy_check_mark: test/yosupo-judge/assignment/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#7db45eeebe50ebaff0e32d268a51d554">test/yosupo-judge/assignment</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/assignment/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 18:35:49+09:00


* see: <a href="https://judge.yosupo.jp/problem/assignment">https://judge.yosupo.jp/problem/assignment</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/Flow/minimum_cost_flow.cpp.html">最小費用流</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/Matching/weighted_bipartite_matching.cpp.html">重み付き二部マッチング</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/assignment"

#include <iostream>
#include <vector>
#include "Mylib/Graph/Matching/weighted_bipartite_matching.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N; std::cin >> N;
  WeightedBipartiteMatching<int64_t> m(N, N);

  auto a = std::vector(N, std::vector<int64_t>(N));
  
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      std::cin >> a[i][j];
      m.add_edge(i, j, a[i][j]);
    }
  }
  
  auto ans = m.solve(N);
  std::cout << ans << std::endl;

  auto match = m.get_matching_edges();

  std::vector<int> p(N);
  for(auto &[i,j,c] : match){
    p[i] = j;
  }

  for(int i = 0; i < N; ++i){
    std::cout << p[i] << " ";
  }
  std::cout << "\n";
  
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/assignment/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/assignment"

#include <iostream>
#include <vector>
#line 3 "Mylib/Graph/Matching/weighted_bipartite_matching.cpp"
#include <tuple>
#line 3 "Mylib/Graph/Flow/minimum_cost_flow.cpp"
#include <queue>
#include <utility>
#include <functional>
#include <algorithm>
#line 8 "Mylib/Graph/Flow/minimum_cost_flow.cpp"

/**
 * @title 最小費用流
 */
template <typename T, typename U> class MinimumCostFlow{
public:
  struct edge{
    int from, to;
    T cap;
    U cost;
    int rev;
    bool is_rev;
    edge(int from, int to, T cap, U cost, int rev, bool is_rev):
      from(from), to(to), cap(cap), cost(cost), rev(rev), is_rev(is_rev){}
  };

private:
  int size;
  std::vector<std::vector<edge>> g;

public:
  MinimumCostFlow(int size): size(size), g(size){}

  void add_edge(int from, int to, T cap, U cost){
    g[from].emplace_back(from, to, cap, cost, g[to].size(), false);
    g[to].emplace_back(to, from, 0, -cost, g[from].size()-1, true);
  }

  T solve(int src, int dst, const T &f, U &ret){
    ret = 0;
    T flow = f;
    std::vector<U> h(size,0), cost(size);
    std::vector<bool> is_inf(size, true);
    std::vector<int> prev_node(size), prev_edge(size);
    std::priority_queue<std::pair<U,int>, std::vector<std::pair<U,int>>, std::greater<std::pair<U,int>>> pq;
    
    while(flow > 0){
      std::fill(is_inf.begin(), is_inf.end(), true);

      // src -> dst の最小コスト経路を探索する。 (dijkstra algorithm)
      cost[src] = 0;
      pq.emplace(0, src);
      is_inf[src] = false;

      while(!pq.empty()){
        U c;
        int v;
        std::tie(c,v) = pq.top(); pq.pop();

        if(cost[v] < c) continue;
	
        for(int i = 0; i < (int)g[v].size(); ++i){
          edge &e = g[v][i];
          int w = e.to;
          T cap = e.cap;
          U cst = e.cost;
          if(cap > 0){
            if(is_inf[w] or cost[w] + h[w] > cost[v] + h[v] + cst){
              is_inf[w] = false;
              cost[w] = cost[v] + cst + h[v] - h[w];
              prev_node[w] = v;
              prev_edge[w] = i;
              pq.emplace(cost[w], w);
            }
          }
        }
      }

      if(is_inf[dst]) return f-flow; // dstへ到達不可能
      
      for(int i = 0; i < size; ++i) h[i] += cost[i];

      // src -> dst の最小コスト経路へ流せる量(df)を決定する。
      T df = flow;
      for(int cur = dst; cur != src; cur = prev_node[cur]){
        df = std::min(df, g[prev_node[cur]][prev_edge[cur]].cap);
      }

      flow -= df;
      ret += df * h[dst];

      // capの更新
      for(int cur = dst; cur != src; cur = prev_node[cur]){
        edge &e = g[prev_node[cur]][prev_edge[cur]];
        e.cap -= df;
        g[cur][e.rev].cap += df;	
      }
    }

    return f;
  }

  const std::vector<std::vector<edge>>& get_graph(){
    return g;
  }
};
#line 5 "Mylib/Graph/Matching/weighted_bipartite_matching.cpp"

/**
 * @title 重み付き二部マッチング
 * @see http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2429
 */
template <typename T>
class WeightedBipartiteMatching{
public:
  const int left, right, s, t;
  MinimumCostFlow<int,T> f;
 
  WeightedBipartiteMatching(int left, int right):
    left(left), right(right), s(left+right), t(s+1), f(left+right+2)
  {
    for(int i = 0; i < left; ++i) f.add_edge(s, i, 1, 0);
    for(int i = 0; i < right; ++i) f.add_edge(left+i, t, 1, 0);
  }
 
  void add_edge(int from, int to, T cost){
    f.add_edge(from, left+to, 1, cost);
  }
 
  T solve(int flow){
    T ret;
    f.solve(s, t, flow, ret);
    return ret;
  }
 
  std::vector<std::tuple<int,int,T>> get_matching_edges(){
    auto g = f.get_graph();
    std::vector<std::tuple<int,int,T>> ret;
 
    for(int i = 0; i < left; ++i){
      for(auto &e : g[i]){
        if(not e.is_rev and e.to != t and e.cap == 0) ret.emplace_back(i, e.to-left, e.cost);
      }
    }
 
    return ret;
  }
};
#line 6 "test/yosupo-judge/assignment/main.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N; std::cin >> N;
  WeightedBipartiteMatching<int64_t> m(N, N);

  auto a = std::vector(N, std::vector<int64_t>(N));
  
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      std::cin >> a[i][j];
      m.add_edge(i, j, a[i][j]);
    }
  }
  
  auto ans = m.solve(N);
  std::cout << ans << std::endl;

  auto match = m.get_matching_edges();

  std::vector<int> p(N);
  for(auto &[i,j,c] : match){
    p[i] = j;
  }

  for(int i = 0; i < N; ++i){
    std::cout << p[i] << " ";
  }
  std::cout << "\n";
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

