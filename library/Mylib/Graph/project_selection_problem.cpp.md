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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: Project Selection Problem

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#791a56799ce3ef8e4fb5da8cbce3a9bf">Mylib/Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/project_selection_problem.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-05 13:51:54+09:00


* see: <a href="https://kimiyuki.net/blog/2017/12/05/minimum-cut-and-project-selection-problem/">https://kimiyuki.net/blog/2017/12/05/minimum-cut-and-project-selection-problem/</a>
* see: <a href="https://ei1333.github.io/luzhiled/snippets/memo/project-selection.html">https://ei1333.github.io/luzhiled/snippets/memo/project-selection.html</a>
* see: <a href="https://ferin-tech.hatenablog.com/entry/2019/10/28/%E7%87%83%E3%82%84%E3%81%99%E5%9F%8B%E3%82%81%E3%82%8B%E5%95%8F%E9%A1%8C">https://ferin-tech.hatenablog.com/entry/2019/10/28/%E7%87%83%E3%82%84%E3%81%99%E5%9F%8B%E3%82%81%E3%82%8B%E5%95%8F%E9%A1%8C</a>
* see: <a href="https://atcoder.jp/contests/arc085/submissions/8399754">https://atcoder.jp/contests/arc085/submissions/8399754</a>
* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3058">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3058</a>
* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2903">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2903</a>


## Depends on

* :heavy_check_mark: <a href="Flow/dinic.cpp.html">Dinic法</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <utility>
#include <cassert>
#include "Mylib/Graph/Flow/dinic.cpp"

/*
 * @title Project Selection Problem
 * @see https://kimiyuki.net/blog/2017/12/05/minimum-cut-and-project-selection-problem/
 * @see https://ei1333.github.io/luzhiled/snippets/memo/project-selection.html
 * @see https://ferin-tech.hatenablog.com/entry/2019/10/28/%E7%87%83%E3%82%84%E3%81%99%E5%9F%8B%E3%82%81%E3%82%8B%E5%95%8F%E9%A1%8C
 
 * @see https://atcoder.jp/contests/arc085/submissions/8399754
 * @see http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3058
 * @see http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2903
 */
template <typename T, T INF>
class ProjectSelectionProblem{
  int N, s, t;
  std::vector<std::vector<std::pair<int,T>>> graph;
  T default_gain;

public:
  ProjectSelectionProblem(int N): N(N), s(N), t(N+1), graph(N+2), default_gain(0){}

  void penalty_if_red(int i, T c){
    assert(c >= 0);
    graph[i].emplace_back(t, c);
  }

  void gain_if_red(int i, T c){
    assert(c >= 0);
    default_gain += c;
    penalty_if_blue(i, c);
  }
  
  void penalty_if_blue(int i, T c){
    assert(c >= 0);
    graph[s].emplace_back(i, c);
  }

  void gain_if_blue(int i, T c){
    assert(c >= 0);
    default_gain += c;
    penalty_if_red(i, c);
  }

  void penalty_if_red_blue(int i, int j, T c){
    assert(c >= 0);
    graph[i].emplace_back(j, c);
  }

  void penalty_if_different(int i, int j, T c){
    assert(c >= 0);
    graph[i].emplace_back(j, c);
    graph[j].emplace_back(i, c);
  }

  void must_be_red(int i){
    penalty_if_blue(i, INF);
  }

  void must_be_blue(int i){
    penalty_if_red(i, INF);
  }

  void if_red_then_must_be_red(int i, int j){
    penalty_if_red_blue(i, j, INF);
  }

  void gain_if_red_red(int i, int j, T c){
    assert(c >= 0);
    default_gain += c;
    int w = graph.size();
    graph.push_back({});

    graph[s].emplace_back(w, c);
    graph[w].emplace_back(i, INF);
    graph[w].emplace_back(j, INF);
  }

  void gain_if_blue_blue(int i, int j, T c){
    assert(c >= 0);
    default_gain += c;
    int w = graph.size();
    graph.push_back({});
    
    graph[w].emplace_back(t, c);
    graph[i].emplace_back(w, INF);
    graph[j].emplace_back(w, INF);
  }

  T solve(){
    Dinic<T,INF> flow(graph);
    return default_gain - flow.solve(s, t);
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/project_selection_problem.cpp"
#include <vector>
#include <utility>
#include <cassert>
#line 4 "Mylib/Graph/Flow/dinic.cpp"
#include <deque>
#include <algorithm>

/**
 * @title Dinic法
 */
template <typename T> class Dinic{
private:
  std::vector<std::vector<std::pair<int,T>>> graph;
  int size, s, t;
  std::vector<std::vector<T>> cap;
  std::vector<int> level;
  
  bool buildLevel(){
    std::fill(level.begin(), level.end(), 0);
    level[s] = 1;
    std::deque<int> deq = {s};
    while(not deq.empty()){
      int cur = deq.front(); deq.pop_front();
      for(int i = 0; i < size; ++i)
        if(level[i] == 0 and cap[cur][i] > 0){
          level[i] = level[cur] + 1;
          deq.push_back(i);
        }
    }
    return level[t] != 0;
  }
  void dfs(std::vector<int> &path, T &flow){
    if(path.empty()) return;
    int cur = path.back();
    if(cur == t){
      T f = std::numeric_limits<T>::max();
      for(int i = 1; i < (int)path.size(); ++i) f = std::min(f, cap[path[i-1]][path[i]]);
      for(int i = 1; i < (int)path.size(); ++i){
        cap[path[i-1]][path[i]] -= f;
        cap[path[i]][path[i-1]] += f;
      }
      flow += f;
    }else{
      for(int i = 0; i < size; ++i){
        if(cap[cur][i] > 0 and level[i] > level[cur]){
          path.push_back(i);
          dfs(path, flow);
          path.pop_back();
        }
      }
    }
  }
  
  T augment(){
    T f = 0;
    std::vector<int> path = {s};
    dfs(path, f);
    return f;
  }
  
  T loop(){
    T f = 0;
    while(buildLevel()) f += augment();
    return f;
  }
 
public:
  Dinic(std::vector<std::vector<std::pair<int,T>>> &_graph): graph(_graph), size(graph.size()) {}
  Dinic(int size): graph(size), size(size){}
  Dinic(){}
 
  void add_edge(int from, int to, const T &cap){
    graph[from].push_back({to, cap});
  }
  
  T solve(int _s, int _t){
    cap = std::vector<std::vector<T>>(size, std::vector<T>(size, 0));
    level = std::vector<int>(size, 0);
 
    for(int i = 0; i < size; ++i)
      for(auto &p : graph[i]){
        int j = p.first;
        T d = p.second;
        cap[i][j] += d;
      }
 
    s = _s;
    t = _t;
 
    return loop();
  }
};
#line 6 "Mylib/Graph/project_selection_problem.cpp"

/*
 * @title Project Selection Problem
 * @see https://kimiyuki.net/blog/2017/12/05/minimum-cut-and-project-selection-problem/
 * @see https://ei1333.github.io/luzhiled/snippets/memo/project-selection.html
 * @see https://ferin-tech.hatenablog.com/entry/2019/10/28/%E7%87%83%E3%82%84%E3%81%99%E5%9F%8B%E3%82%81%E3%82%8B%E5%95%8F%E9%A1%8C
 
 * @see https://atcoder.jp/contests/arc085/submissions/8399754
 * @see http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3058
 * @see http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2903
 */
template <typename T, T INF>
class ProjectSelectionProblem{
  int N, s, t;
  std::vector<std::vector<std::pair<int,T>>> graph;
  T default_gain;

public:
  ProjectSelectionProblem(int N): N(N), s(N), t(N+1), graph(N+2), default_gain(0){}

  void penalty_if_red(int i, T c){
    assert(c >= 0);
    graph[i].emplace_back(t, c);
  }

  void gain_if_red(int i, T c){
    assert(c >= 0);
    default_gain += c;
    penalty_if_blue(i, c);
  }
  
  void penalty_if_blue(int i, T c){
    assert(c >= 0);
    graph[s].emplace_back(i, c);
  }

  void gain_if_blue(int i, T c){
    assert(c >= 0);
    default_gain += c;
    penalty_if_red(i, c);
  }

  void penalty_if_red_blue(int i, int j, T c){
    assert(c >= 0);
    graph[i].emplace_back(j, c);
  }

  void penalty_if_different(int i, int j, T c){
    assert(c >= 0);
    graph[i].emplace_back(j, c);
    graph[j].emplace_back(i, c);
  }

  void must_be_red(int i){
    penalty_if_blue(i, INF);
  }

  void must_be_blue(int i){
    penalty_if_red(i, INF);
  }

  void if_red_then_must_be_red(int i, int j){
    penalty_if_red_blue(i, j, INF);
  }

  void gain_if_red_red(int i, int j, T c){
    assert(c >= 0);
    default_gain += c;
    int w = graph.size();
    graph.push_back({});

    graph[s].emplace_back(w, c);
    graph[w].emplace_back(i, INF);
    graph[w].emplace_back(j, INF);
  }

  void gain_if_blue_blue(int i, int j, T c){
    assert(c >= 0);
    default_gain += c;
    int w = graph.size();
    graph.push_back({});
    
    graph[w].emplace_back(t, c);
    graph[i].emplace_back(w, INF);
    graph[j].emplace_back(w, INF);
  }

  T solve(){
    Dinic<T,INF> flow(graph);
    return default_gain - flow.solve(s, t);
  }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

