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


# :x: test/aoj/GRL_6_A/main.push_relabel.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#d22130300c64d313f1c5481cac7c3c1c">test/aoj/GRL_6_A</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_6_A/main.push_relabel.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 09:10:27+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Graph/Flow/push_relabel.cpp.html">Push-relabel</a>
* :x: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :x: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"

#include <iostream>
#include <climits>
#include "Mylib/Graph/Flow/push_relabel.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  int V, E; std::cin >> V >> E;

  PushRelabel<int> f(V);

  for(auto [s, t, c] : input_tuples<int, int, int>(E)){
    f.add_edge(s, t, c);
  }

  auto ans = f.solve(0, V - 1);
  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_6_A/main.push_relabel.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"

#include <iostream>
#include <climits>
#line 2 "Mylib/Graph/Flow/push_relabel.cpp"
#include <vector>
#include <queue>
#include <utility>
#include <limits>

/**
 * @title Push-relabel
 * @docs push_relabel.md
 */
template <typename T>
struct PushRelabel {
private:
  struct edge {
    int from, to;
    int rev;
    T cap;
    bool is_rev;
  };

  int N;
  std::vector<std::vector<edge>> g;
  std::vector<T> excess;
  std::vector<int> height;
  std::queue<int> next_active_vertex;
  constexpr static T inf = std::numeric_limits<T>::max();

  void init(int s, int t){
    excess[s] = inf;

    for(auto &e : g[s]){
      push(e, s, t);
    }

    {
      for(int i = 0; i < N; ++i){
        height[i] = N;
      }

      std::queue<int> q;
      std::vector<bool> check(N);
      q.push(t);
      height[t] = 0;

      while(not q.empty()){
        const int i = q.front(); q.pop();

        if(check[i]) continue;
        check[i] = true;

        for(auto &e : g[i]){
          if(not e.is_rev) continue;
          if(height[e.from] + 1 < height[e.to]){
            height[e.to] = height[e.from] + 1;
            q.push(e.to);
          }
        }
      }

      height[s] = N;
    }
  }

  bool is_pushable(const edge &e){
    if(excess[e.from] == 0) return false;
    if(height[e.from] != height[e.to] + 1) return false;
    if(e.cap == 0) return false;
    return true;
  }

  void push(edge &e, int, int){
    auto &r = g[e.to][e.rev];

    T flow = std::min(e.cap, excess[e.from]);

    e.cap -= flow;
    r.cap += flow;

    excess[e.from] -= flow;
    excess[e.to] += flow;

    if(excess[e.to] == flow) next_active_vertex.push(e.to);
  }

  void relabel(int i, int, int){
    int a = std::numeric_limits<int>::max() / 2;
    for(auto &e : g[i]){
      if(e.cap > 0) a = std::min(a, height[e.to]);
    }

    height[i] = a + 1;
  }

public:
  PushRelabel(){}
  PushRelabel(int N): N(N), g(N), excess(N), height(N){}
  PushRelabel(std::vector<std::vector<std::pair<int, T>>> g):
    N(g.size()), g(N), excess(N), height(N)
  {
    for(int i = 0; i < N; ++i){
      for(auto [j, c] : g[i]){
        add_edge(i, j, c);
      }
    }
  }


  void add_edge(int from, int to, T c){
    g[from].push_back({from, to, (int)g[to].size(), c, false});
    g[to].push_back({to, from, (int)g[from].size() - 1, 0, true});
  }

  T solve(int s, int t){
    init(s, t);

    while(true){
      int index = -1;

      while(not next_active_vertex.empty()){
        int i = next_active_vertex.front();
        if(i != s and i != t and excess[i] > 0){
          index = i;
          break;
        }
        next_active_vertex.pop();
      }

      if(index == -1) break;

      bool ok = false;
      for(auto &e : g[index]){
        if(is_pushable(e)){
          push(e, s, t);
          ok = true;
          break;
        }
      }

      if(not ok){
        relabel(index, s, t);
      }
    }

    return excess[t];
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
#line 7 "test/aoj/GRL_6_A/main.push_relabel.test.cpp"

int main(){
  int V, E; std::cin >> V >> E;

  PushRelabel<int> f(V);

  for(auto [s, t, c] : input_tuples<int, int, int>(E)){
    f.add_edge(s, t, c);
  }

  auto ans = f.solve(0, V - 1);
  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

