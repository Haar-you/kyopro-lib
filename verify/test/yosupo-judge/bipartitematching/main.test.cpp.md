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


# :heavy_check_mark: test/yosupo-judge/bipartitematching/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#aaddfc42bd9348a0d8dc19d8cb0c6655">test/yosupo-judge/bipartitematching</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/bipartitematching/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-03 05:13:49+09:00


* see: <a href="https://judge.yosupo.jp/problem/bipartitematching">https://judge.yosupo.jp/problem/bipartitematching</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/Matching/hopcroft_karp.cpp.html">Hopcroft-Karp algorithm</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include <iostream>
#include "Mylib/Graph/Matching/hopcroft_karp.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  int L,R,M; std::cin >> L >> R >> M;
  HopcroftKarp hk(L,R);

  for(auto [a, b] : input_tuples<int, int>(M)){
    hk.add_edge(a, b);
  }
  
  hk.solve();

  auto ans = hk.get_matching();

  std::cout << ans.size() << "\n";
  for(auto &[i,j] : ans){
    std::cout << i << " " << j << "\n";
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/bipartitematching/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include <iostream>
#line 2 "Mylib/Graph/Matching/hopcroft_karp.cpp"
#include <vector>
#include <queue>
#include <utility>
#include <cassert>

/**
 * @title Hopcroft-Karp algorithm
 * @docs hopcroft_karp.md
 */
class HopcroftKarp{
  struct edge{
    int from, to;
    int rev;
    bool used;
  };

  int L, R, N;
  std::vector<std::vector<edge>> graph;
  std::vector<int> dist;
  
  bool bfs(){
    dist.assign(N, -1);
    std::queue<int> q;

    q.push(0);
    dist[0] = 0;

    while(not q.empty()){
      int i = q.front(); q.pop();
      
      for(auto &e : graph[i]){
        if(not e.used and dist[e.to] == -1){
          dist[e.to] = dist[i] + 1;
          q.push(e.to);
        }
      }
    }

    return dist[N-1] != -1;
  }

  bool dfs(int cur){
    if(cur == N-1) return true;

    for(auto &e : graph[cur]){
      if(not e.used and dist[cur] + 1 == dist[e.to]){
        if(dfs(e.to)){
          e.used = true;
          if(e.rev >= 0) graph[e.to][e.rev].used = false;
          return true;
        }
      }
    }

    return false;
  }

public:
  HopcroftKarp(int L, int R): L(L), R(R), N(L+R+2), graph(N), dist(N){
    for(int i = 0; i < L; ++i){
      graph[0].push_back((edge){0, i+1, -1, false});
    }

    for(int i = 0; i < R; ++i){
      graph[i+L+1].push_back((edge){i+L+1, N-1, -1, false});
    }
  }

  void add_edge(int i, int j){
    assert(0 <= i and i < L);
    assert(0 <= j and j < R);

    int x = i+1;
    int y = j+L+1;

    graph[x].push_back((edge){x, y, (int)graph[y].size(), false});
    graph[y].push_back((edge){y, x, (int)graph[x].size()-1, true});
  }


  int solve(){
    int ret = 0;
    
    while(bfs()){
      int flow = 0;
      for(int i = 0; i < L; ++i){
        auto &e = graph[0][i];
        if(not e.used and dfs(e.to)){
          e.used = true;
          ++flow;
        }
      }
      if(flow == 0) break;
      ret += flow;
    }

    return ret;
  }
  
  auto get_matching(){
    std::vector<std::pair<int,int>> ret;
    for(int i = 0; i < L; ++i){
      for(auto &e : graph[i+1]){
        if(e.used) ret.emplace_back(i, e.to - L - 1);
      }
    }
    return ret;
  }
};
#line 4 "Mylib/IO/input_tuples.cpp"
#include <tuple>
#line 6 "Mylib/IO/input_tuples.cpp"
#include <initializer_list>
#line 5 "Mylib/IO/input_tuple.cpp"
#include <initializer_list>

/**
 * @docs input_tuple.md
 */
template <typename T, size_t ... I>
static void input_tuple_helper(std::istream &s, T &val, std::index_sequence<I...>){
  (void)std::initializer_list<int>{(void(s >> std::get<I>(val)), 0)...};
}

template <typename T, typename U>
std::istream& operator>>(std::istream &s, std::pair<T, U> &value){
  s >> value.first >> value.second;
  return s;
}

template <typename ... Args>
std::istream& operator>>(std::istream &s, std::tuple<Args...> &value){
  input_tuple_helper(s, value, std::make_index_sequence<sizeof...(Args)>());
  return s;
}
#line 8 "Mylib/IO/input_tuples.cpp"

/**
 * @docs input_tuples.md
 */
template <typename ... Args>
class InputTuples{
  struct iter{
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
#line 6 "test/yosupo-judge/bipartitematching/main.test.cpp"

int main(){
  int L,R,M; std::cin >> L >> R >> M;
  HopcroftKarp hk(L,R);

  for(auto [a, b] : input_tuples<int, int>(M)){
    hk.add_edge(a, b);
  }
  
  hk.solve();

  auto ans = hk.get_matching();

  std::cout << ans.size() << "\n";
  for(auto &[i,j] : ans){
    std::cout << i << " " << j << "\n";
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

