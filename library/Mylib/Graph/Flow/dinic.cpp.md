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


# :heavy_check_mark: Dinic法

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#ecd047c70c23d80351a9f133b49a4638">Mylib/Graph/Flow</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/Flow/dinic.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 18:35:49+09:00




## Required by

* :warning: <a href="../project_selection_problem.cpp.html">Project Selection Problem</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/GRL_6_A/main.dinic.test.cpp.html">test/aoj/GRL_6_A/main.dinic.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <utility>
#include <deque>
#include <algorithm>

/**
 * @title Dinic法
 */
template <typename T, T INF> class Dinic{
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
      T f = INF;
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/Flow/dinic.cpp"
#include <vector>
#include <utility>
#include <deque>
#include <algorithm>

/**
 * @title Dinic法
 */
template <typename T, T INF> class Dinic{
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
      T f = INF;
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

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

