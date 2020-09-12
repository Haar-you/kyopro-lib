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


# :x: Ford-Fulkerson algorithm

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#ecd047c70c23d80351a9f133b49a4638">Mylib/Graph/Flow</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/Flow/ford_fulkerson.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Verified with

* :x: <a href="../../../../verify/test/aoj/2903/main.test.cpp.html">test/aoj/2903/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/3058/main.test.cpp.html">test/aoj/3058/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/GRL_6_A/main.ford_fulkerson.test.cpp.html">test/aoj/GRL_6_A/main.ford_fulkerson.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/GRL_7_A/main.test.cpp.html">test/aoj/GRL_7_A/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <algorithm>

/**
 * @title Ford-Fulkerson algorithm
 * @docs ford_fulkerson.md
 */
namespace haar_lib {
  template <typename T>
  class ford_fulkerson {
  public:
    struct edge {
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
    ford_fulkerson(const std::vector<std::vector<std::pair<int, T>>> &g):
      size(g.size()), graph(size), visit(size)
    {
      for(int i = 0; i < size; ++i){
        for(auto &[j, c] : g[i]){
          add_edge(i, j, c);
        }
      }
    }
    ford_fulkerson(int size): size(size), graph(size), visit(size){}

    void add_edge(int from, int to, const T &cap){
      graph[from].push_back((edge){to, (int)graph[to].size(), cap, false});
      graph[to].push_back((edge){from, (int)graph[from].size() - 1, 0, true});
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
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/Flow/ford_fulkerson.cpp"
#include <vector>
#include <algorithm>

/**
 * @title Ford-Fulkerson algorithm
 * @docs ford_fulkerson.md
 */
namespace haar_lib {
  template <typename T>
  class ford_fulkerson {
  public:
    struct edge {
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
    ford_fulkerson(const std::vector<std::vector<std::pair<int, T>>> &g):
      size(g.size()), graph(size), visit(size)
    {
      for(int i = 0; i < size; ++i){
        for(auto &[j, c] : g[i]){
          add_edge(i, j, c);
        }
      }
    }
    ford_fulkerson(int size): size(size), graph(size), visit(size){}

    void add_edge(int from, int to, const T &cap){
      graph[from].push_back((edge){to, (int)graph[to].size(), cap, false});
      graph[to].push_back((edge){from, (int)graph[from].size() - 1, 0, true});
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
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

