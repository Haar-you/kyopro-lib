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


# :x: Dinic algorithm

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#ecd047c70c23d80351a9f133b49a4638">Mylib/Graph/Flow</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/Flow/dinic.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Verified with

* :x: <a href="../../../../verify/test/aoj/GRL_6_A/main.dinic.test.cpp.html">test/aoj/GRL_6_A/main.dinic.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

/**
 * @title Dinic algorithm
 * @docs dinic.md
 */
namespace haar_lib {
  template <typename T>
  class dinic {
  private:
    int size;
    std::vector<std::vector<T>> cap;
    std::vector<int> level;

    bool build_level(int s, int t){
      std::fill(level.begin(), level.end(), 0);
      level[s] = 1;
      std::queue<int> q;
      q.push(s);
      while(not q.empty()){
        int cur = q.front(); q.pop();
        for(int i = 0; i < size; ++i)
          if(level[i] == 0 and cap[cur][i] > 0){
            level[i] = level[cur] + 1;
            q.push(i);
          }
      }
      return level[t] != 0;
    }

    void dfs(std::vector<int> &path, T &flow, int t){
      if(path.empty()) return;
      int cur = path.back();
      if(cur == t){
        T f = std::numeric_limits<T>::max();
        for(int i = 1; i < (int)path.size(); ++i) f = std::min(f, cap[path[i - 1]][path[i]]);
        for(int i = 1; i < (int)path.size(); ++i){
          cap[path[i - 1]][path[i]] -= f;
          cap[path[i]][path[i - 1]] += f;
        }
        flow += f;
      }else{
        for(int i = 0; i < size; ++i){
          if(cap[cur][i] > 0 and level[i] > level[cur]){
            path.push_back(i);
            dfs(path, flow, t);
            path.pop_back();
          }
        }
      }
    }

  public:
    dinic(const std::vector<std::vector<std::pair<int, T>>> &g):
      size(g.size()), cap(size, std::vector<T>(size)), level(size){
      for(int i = 0; i < size; ++i){
        for(auto &[j, c] : g[i]){
          add_edge(i, j, c);
        }
      }
    }
    dinic(int size): size(size), cap(size, std::vector<T>(size)), level(size){}
    dinic(){}

    void add_edge(int from, int to, const T &c){
      cap[from][to] += c;
    }

    T solve(int s, int t){
      T f = 0;
      while(build_level(s, t)){
        T a = 0;
        std::vector<int> path = {s};
        dfs(path, a, t);
        f += a;
      }
      return f;
    }
  };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/Flow/dinic.cpp"
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

/**
 * @title Dinic algorithm
 * @docs dinic.md
 */
namespace haar_lib {
  template <typename T>
  class dinic {
  private:
    int size;
    std::vector<std::vector<T>> cap;
    std::vector<int> level;

    bool build_level(int s, int t){
      std::fill(level.begin(), level.end(), 0);
      level[s] = 1;
      std::queue<int> q;
      q.push(s);
      while(not q.empty()){
        int cur = q.front(); q.pop();
        for(int i = 0; i < size; ++i)
          if(level[i] == 0 and cap[cur][i] > 0){
            level[i] = level[cur] + 1;
            q.push(i);
          }
      }
      return level[t] != 0;
    }

    void dfs(std::vector<int> &path, T &flow, int t){
      if(path.empty()) return;
      int cur = path.back();
      if(cur == t){
        T f = std::numeric_limits<T>::max();
        for(int i = 1; i < (int)path.size(); ++i) f = std::min(f, cap[path[i - 1]][path[i]]);
        for(int i = 1; i < (int)path.size(); ++i){
          cap[path[i - 1]][path[i]] -= f;
          cap[path[i]][path[i - 1]] += f;
        }
        flow += f;
      }else{
        for(int i = 0; i < size; ++i){
          if(cap[cur][i] > 0 and level[i] > level[cur]){
            path.push_back(i);
            dfs(path, flow, t);
            path.pop_back();
          }
        }
      }
    }

  public:
    dinic(const std::vector<std::vector<std::pair<int, T>>> &g):
      size(g.size()), cap(size, std::vector<T>(size)), level(size){
      for(int i = 0; i < size; ++i){
        for(auto &[j, c] : g[i]){
          add_edge(i, j, c);
        }
      }
    }
    dinic(int size): size(size), cap(size, std::vector<T>(size)), level(size){}
    dinic(){}

    void add_edge(int from, int to, const T &c){
      cap[from][to] += c;
    }

    T solve(int s, int t){
      T f = 0;
      while(build_level(s, t)){
        T a = 0;
        std::vector<int> path = {s};
        dfs(path, a, t);
        f += a;
      }
      return f;
    }
  };
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
