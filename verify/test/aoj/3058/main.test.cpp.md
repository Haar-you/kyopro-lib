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


# :heavy_check_mark: test/aoj/3058/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#7e98db48dc3a2f2f4bf10921a7d3d1f5">test/aoj/3058</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/3058/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-29 20:22:17+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3058">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3058</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/Flow/ford_fulkerson.cpp.html">Ford-Fulkerson法</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/project_selection_problem.cpp.html">Project Selection Problem</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3058"

#include <iostream>
#include <vector>
#include <utility>
#include <string>

#include "Mylib/Graph/project_selection_problem.cpp"
#include "Mylib/Graph/Flow/ford_fulkerson.cpp"

int main(){
  int N, M; std::cin >> N >> M;
  std::string U; std::cin >> U;

  std::vector<int> A(N);
  for(int i = 0; i < N; ++i) std::cin >> A[i];

  ProjectSelectionProblem<int, FordFulkerson<int>> psp(N);
  // red: right, blue: left

  for(int i = 0; i < N; ++i){
    if(U[i] == 'R'){
      psp.penalty_if_blue(i, A[i]);
    }else{
      psp.penalty_if_red(i, A[i]);
    }
  }
  
  for(int i = 0; i < M; ++i){
    int s, t, b; std::cin >> s >> t >> b;
    --s, --t;
    if(s > t) std::swap(s, t);
    
    psp.penalty_if_red_blue(s, t, b);
  }

  auto ans = -psp.solve();
  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/3058/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3058"

#include <iostream>
#include <vector>
#include <utility>
#include <string>

#line 4 "Mylib/Graph/project_selection_problem.cpp"
#include <cassert>
#include <limits>

/*
 * @title Project Selection Problem
 * @docs project_selection_problem.md
 */
template <typename T, typename Flow>
class ProjectSelectionProblem{
  int N, s, t;
  std::vector<std::vector<std::pair<int,T>>> graph;
  T default_gain;

  constexpr static T INF = std::numeric_limits<T>::max();

public:
  ProjectSelectionProblem(int N): N(N), s(N), t(N+1), graph(N+2), default_gain(0){}

  void penalty_if_red(int i, T c){
    assert(c >= 0);
    assert(0 <= i and i < N);
    graph[i].emplace_back(t, c);
  }

  void gain_if_red(int i, T c){
    assert(c >= 0);
    assert(0 <= i and i < N);
    default_gain += c;
    penalty_if_blue(i, c);
  }
  
  void penalty_if_blue(int i, T c){
    assert(c >= 0);
    assert(0 <= i and i < N);
    graph[s].emplace_back(i, c);
  }

  void gain_if_blue(int i, T c){
    assert(c >= 0);
    assert(0 <= i and i < N);
    default_gain += c;
    penalty_if_red(i, c);
  }

  void penalty_if_red_blue(int i, int j, T c){
    assert(c >= 0);
    assert(0 <= i and i < N);
    assert(0 <= j and j < N);
    graph[i].emplace_back(j, c);
  }

  void penalty_if_different(int i, int j, T c){
    assert(c >= 0);
    assert(0 <= i and i < N);
    assert(0 <= j and j < N);
    graph[i].emplace_back(j, c);
    graph[j].emplace_back(i, c);
  }

  void must_be_red(int i){
    assert(0 <= i and i < N);
    penalty_if_blue(i, INF);
  }

  void must_be_blue(int i){
    assert(0 <= i and i < N);
    penalty_if_red(i, INF);
  }

  void if_red_then_must_be_red(int i, int j){
    assert(0 <= i and i < N);
    assert(0 <= j and j < N);
    penalty_if_red_blue(i, j, INF);
  }

  void gain_if_red_red(int i, int j, T c){
    assert(c >= 0);
    assert(0 <= i and i < N);
    assert(0 <= j and j < N);
    default_gain += c;
    int w = graph.size();
    graph.push_back({});

    graph[s].emplace_back(w, c);
    graph[w].emplace_back(i, INF);
    graph[w].emplace_back(j, INF);
  }

  void gain_if_blue_blue(int i, int j, T c){
    assert(c >= 0);
    assert(0 <= i and i < N);
    assert(0 <= j and j < N);
    default_gain += c;
    int w = graph.size();
    graph.push_back({});
    
    graph[w].emplace_back(t, c);
    graph[i].emplace_back(w, INF);
    graph[j].emplace_back(w, INF);
  }

  T solve(){
    Flow flow(graph);
    return default_gain - flow.solve(s, t);
  }
};
#line 3 "Mylib/Graph/Flow/ford_fulkerson.cpp"
#include <algorithm>

/**
 * @title Ford-Fulkerson法
 */
template <typename T> class FordFulkerson{
public:
  struct edge{
    int to, rev;
    T cap;
    bool is_rev;
  };
  
private:
  int size;

  std::vector<std::vector<edge>> graph;
  std::vector<bool> visit;
  
  T dfs(int from, int to, T flow){
    if(from == to) return flow;
    visit[from] = true;

    for(auto &e : graph[from]){
      if(!visit[e.to] and e.cap > 0){
        T d = dfs(e.to, to, std::min(flow, e.cap));
        if(d > 0){
          e.cap -= d;
          graph[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }
  
public:
  FordFulkerson(const std::vector<std::vector<std::pair<int,T>>> &g):
    size(g.size()), graph(size), visit(size)
  {
    for(int i = 0; i < size; ++i){
      for(auto &[j, c] : g[i]){
        add_edge(i, j, c);
      }
    }  
  }
  FordFulkerson(int size): size(size), graph(size), visit(size){}

  void add_edge(int from, int to, const T &cap){
    graph[from].push_back((edge){to, (int)graph[to].size(), cap, false});
    graph[to].push_back((edge){from, (int)graph[from].size()-1, 0, true});
  }

  void reset_flow(){
    for(auto &v : graph){
      for(auto &e : v){
        if(e.is_rev){
          graph[e.to][e.rev].cap += e.cap;
          e.cap = 0;
        }
      }
    }
  }

  T solve(int s, int t){
    T ret = 0;

    while(1){
      visit.assign(size, false);
      T flow = dfs(s, t, std::numeric_limits<T>::max());
      if(flow == 0) return ret;
      ret += flow;
    }
  }

  const std::vector<std::vector<edge>>& get_graph(){
    return graph;
  }
};
#line 10 "test/aoj/3058/main.test.cpp"

int main(){
  int N, M; std::cin >> N >> M;
  std::string U; std::cin >> U;

  std::vector<int> A(N);
  for(int i = 0; i < N; ++i) std::cin >> A[i];

  ProjectSelectionProblem<int, FordFulkerson<int>> psp(N);
  // red: right, blue: left

  for(int i = 0; i < N; ++i){
    if(U[i] == 'R'){
      psp.penalty_if_blue(i, A[i]);
    }else{
      psp.penalty_if_red(i, A[i]);
    }
  }
  
  for(int i = 0; i < M; ++i){
    int s, t, b; std::cin >> s >> t >> b;
    --s, --t;
    if(s > t) std::swap(s, t);
    
    psp.penalty_if_red_blue(s, t, b);
  }

  auto ans = -psp.solve();
  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

