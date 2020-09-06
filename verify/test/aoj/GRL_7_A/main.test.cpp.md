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


# :x: test/aoj/GRL_7_A/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#806a528feab938cddc13c96a5d63d020">test/aoj/GRL_7_A</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_7_A/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 09:10:27+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Graph/Flow/ford_fulkerson.cpp.html">Ford-Fulkerson algorithm</a>
* :x: <a href="../../../../library/Mylib/Graph/Matching/bipartite_matching.cpp.html">Maximum bipartite matching</a>
* :x: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :x: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A"

#include <iostream>
#include "Mylib/Graph/Matching/bipartite_matching.cpp"
#include "Mylib/Graph/Flow/ford_fulkerson.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  int X, Y, E; std::cin >> X >> Y >> E;

  BipartiteMatching<FordFulkerson<int>> b(X, Y);

  for(auto [x, y] : input_tuples<int, int>(E)){
    b.add_edge(x, y);
  }

  int ans = b.solve();

  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_7_A/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A"

#include <iostream>
#line 2 "Mylib/Graph/Matching/bipartite_matching.cpp"
#include <vector>
#include <utility>
#include <climits>
#include <cassert>

/**
 * @title Maximum bipartite matching
 * @docs bipartite_matching.md
 */
template <typename MaxFlow>
class BipartiteMatching {
  int L, R, s, t;
  MaxFlow f;

public:
  BipartiteMatching(int L, int R): L(L), R(R), s(L + R), t(s + 1), f(L + R + 2){
    for(int i = 0; i < L; ++i) f.add_edge(s, i, 1);
    for(int i = 0; i < R; ++i) f.add_edge(L + i, t, 1);
  }

  void add_edge(int i, int j){
    assert(0 <= i and i < L and 0 <= j and j < R);
    f.add_edge(i, L + j, 1);
  }

  int solve(){
    return f.solve(s, t);
  }

  auto get_matching(){
    auto g = f.get_graph();
    std::vector<std::pair<int, int>> ret;

    for(int i = 0; i < (int)g.size() - 2; ++i){
      for(const auto &e : g[i]){
        if((not e.is_rev) and e.cap == 0 and e.to != t) ret.emplace_back(i, e.to - L);
      }
    }

    return ret;
  }
};
#line 3 "Mylib/Graph/Flow/ford_fulkerson.cpp"
#include <algorithm>

/**
 * @title Ford-Fulkerson algorithm
 * @docs ford_fulkerson.md
 */
template <typename T>
class FordFulkerson {
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
  FordFulkerson(const std::vector<std::vector<std::pair<int, T>>> &g):
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
#line 4 "Mylib/IO/input_tuples.cpp"
#include <tuple>
#line 6 "Mylib/IO/input_tuples.cpp"
#include <initializer_list>
#line 6 "Mylib/IO/input_tuple.cpp"

/**
 * @docs input_tuple.md
 */
template <typename T, size_t ... I>
static void input_tuple_helper(std::istream &s, T &val, std::index_sequence<I ...>){
  (void)std::initializer_list<int>{(void(s >> std::get<I>(val)), 0) ...};
}

template <typename T, typename U>
std::istream& operator>>(std::istream &s, std::pair<T, U> &value){
  s >> value.first >> value.second;
  return s;
}

template <typename ... Args>
std::istream& operator>>(std::istream &s, std::tuple<Args ...> &value){
  input_tuple_helper(s, value, std::make_index_sequence<sizeof ... (Args)>());
  return s;
}
#line 8 "Mylib/IO/input_tuples.cpp"

/**
 * @docs input_tuples.md
 */
template <typename ... Args>
class InputTuples {
  struct iter {
    using value_type = std::tuple<Args ...>;
    value_type value;
    bool fetched = false;
    int N, c = 0;

    value_type operator*(){
      if(not fetched){
        std::cin >> value;
      }
      return value;
    }

    void operator++(){
      ++c;
      fetched = false;
    }

    bool operator!=(iter &) const {
      return c < N;
    }

    iter(int N): N(N){}
  };

  int N;

public:
  InputTuples(int N): N(N){}

  iter begin() const {return iter(N);}
  iter end() const {return iter(N);}
};

template <typename ... Args>
auto input_tuples(int N){
  return InputTuples<Args ...>(N);
}
#line 7 "test/aoj/GRL_7_A/main.test.cpp"

int main(){
  int X, Y, E; std::cin >> X >> Y >> E;

  BipartiteMatching<FordFulkerson<int>> b(X, Y);

  for(auto [x, y] : input_tuples<int, int>(E)){
    b.add_edge(x, y);
  }

  int ans = b.solve();

  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

