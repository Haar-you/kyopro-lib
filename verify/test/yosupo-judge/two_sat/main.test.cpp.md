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


# :x: test/yosupo-judge/two_sat/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#e93cc7e7edd1deb522641737d913fca6">test/yosupo-judge/two_sat</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/two_sat/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-08 22:35:50+09:00


* see: <a href="https://judge.yosupo.jp/problem/two_sat">https://judge.yosupo.jp/problem/two_sat</a>


## Depends on

* :question: <a href="../../../../library/Mylib/Graph/GraphUtils/strongly_connected_components.cpp.html">Strongly connected components</a>
* :question: <a href="../../../../library/Mylib/Graph/TopologicalSort/topological_sort.cpp.html">Topological sort</a>
* :question: <a href="../../../../library/Mylib/Graph/graph_template.cpp.html">Graph template</a>
* :x: <a href="../../../../library/Mylib/Graph/two_sat.cpp.html">2-SAT</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/join.cpp.html">Mylib/IO/join.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#include <iostream>
#include <string>
#include <vector>
#include "Mylib/Graph/two_sat.cpp"
#include "Mylib/IO/join.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  std::string p, cnf;
  int N,M;
  std::cin >> p >> cnf >> N >> M;

  TwoSat sat(N);

  for(auto [a, b, c] : input_tuples<int, int, int>(M)){
    sat.add_or(a, b);
  }

  if(auto res = sat.solve(); res){
    std::vector<int> ans(N);
    for(int i = 0; i < N; ++i) ans[i] = (*res)[i] ? i+1 : -(i+1);

    std::cout
      << "s SATISFIABLE" << std::endl
      << "v " << join(ans.begin(), ans.end()) << " " << 0 << std::endl;
  }else{
    std::cout << "s UNSATISFIABLE" << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/two_sat/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#include <iostream>
#include <string>
#include <vector>
#line 3 "Mylib/Graph/two_sat.cpp"
#include <optional>
#include <cassert>
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
#line 3 "Mylib/Graph/GraphUtils/strongly_connected_components.cpp"
#include <algorithm>
#line 5 "Mylib/Graph/GraphUtils/strongly_connected_components.cpp"

/**
 * @title Strongly connected components
 * @docs strongly_connected_components.md
 */
template <typename T>
auto strongly_connected_components(const Graph<T> &g){
  const int n = g.size();

  std::vector<bool> visit(n);
  std::vector<int> check(n);
  std::vector<int> result(n, -1);

  auto dfs =
    [&](auto &f, int cur) -> void {
      visit[cur] = true;
      for(const auto &e : g[cur]){
        if(not visit[e.to]) f(f, e.to);
      }
      check.push_back(cur);
    };

  for(int i = 0; i < n; ++i) if(not visit[i]) dfs(dfs, i);

  std::reverse(check.begin(), check.end());

  Graph<T> rg(n);

  auto rdfs =
    [&](auto &f, int cur, int i) -> void {
      result[cur] = i;
      for(const auto &e : rg[cur]){
        if(result[e.to] == -1) f(f, e.to, i);
      }
    };

  for(int i = 0; i < n; ++i) for(const auto &e : g[i]) rg[e.to].emplace_back(e.to, e.from, e.cost);

  int i = 0;
  for(auto c : check) if(result[c] == -1) rdfs(rdfs, c, i), ++i;

  
  return std::make_pair(result, i);
}
#line 3 "Mylib/Graph/TopologicalSort/topological_sort.cpp"
#include <optional>
#include <queue>
#line 6 "Mylib/Graph/TopologicalSort/topological_sort.cpp"

/**
 * @title Topological sort
 * @docs topological_sort.md
 */
template <typename T>
std::optional<std::vector<int>> topological_sort(const Graph<T> &g){
  const int n = g.size();
  std::vector<int> indeg(n);
  
  for(int i = 0; i < n; ++i){
    for(auto &e : g[i]){
      ++indeg[e.to];
    }
  }

  std::queue<int> q;
  for(int i = 0; i < n; ++i){
    if(indeg[i] == 0) q.push(i);
  }

  std::vector<int> ret;
  while(not q.empty()){
    int cur = q.front(); q.pop();
    ret.push_back(cur);
    for(auto &e : g[cur]){
      --indeg[e.to];
      if(indeg[e.to] == 0){
        q.push(e.to);
      }
    }
  }

  if((int)ret.size() == n){
    return {ret};
  }else{
    return std::nullopt;
  }
}
#line 8 "Mylib/Graph/two_sat.cpp"

/**
 * @title 2-SAT
 * @docs two_sat.md
 */
class TwoSat{
  const int n;
  Graph<int> g;

  int f(int i){
    assert(i != 0);
    assert(abs(i) <= n);
    if(i > 0) return i-1;
    else return abs(i)-1 + n;
  }

public:
  TwoSat(int n): n(n), g(2*n){}

  /**
   * @note a→bを導入する
   */
  void add_if(int a, int b){
    add_edge(g, f(a), f(b), 1);
  }

  /**
   * @note a∨bを導入する
   * @note a ∨ b <=> (!a => b) ∧ (!b => a)
   */
  void add_or(int a, int b){
    add_if(-a, b);
    add_if(-b, a);
  }

  /**
   * @note ¬(a∧b)を導入する
   * @note !(A ∧ B) <=> (!A ∨ !B)
   */
  void not_coexist(int a, int b){
    add_or(-a, -b);
  }
  
public:
  std::optional<std::vector<bool>> solve() const {
    auto [scc, m] = strongly_connected_components<int>(g);

    for(int i = 0; i < n; ++i){
      if(scc[i] == scc[i+n]) return {};
    }
    
    Graph<int> g2(m);

    for(int i = 0; i < 2*n; ++i){
      for(auto &e : g[i]){
        if(scc[e.from] != scc[e.to]){
          add_edge(g2, scc[e.from], scc[e.to], 1);
        }
      }
    }

    auto ts = *topological_sort(g2);

    std::vector<int> r(m);
    for(int i = 0; i < m; ++i) r[ts[i]] = i;

    std::vector<bool> ret(n);
    for(int i = 0; i < n; ++i) ret[i] = r[scc[i]] > r[scc[i+n]];

    return {ret};
  }
};
#line 3 "Mylib/IO/join.cpp"
#include <sstream>
#line 5 "Mylib/IO/join.cpp"

/**
 * @docs join.md
 */
template <typename ITER>
std::string join(ITER first, ITER last, std::string delim = " "){
  std::stringstream s;

  for(auto it = first; it != last; ++it){
    if(it != first) s << delim;
    s << *it;
  }

  return s.str();
}
#line 4 "Mylib/IO/input_tuples.cpp"
#include <tuple>
#include <utility>
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
#line 9 "test/yosupo-judge/two_sat/main.test.cpp"

int main(){
  std::string p, cnf;
  int N,M;
  std::cin >> p >> cnf >> N >> M;

  TwoSat sat(N);

  for(auto [a, b, c] : input_tuples<int, int, int>(M)){
    sat.add_or(a, b);
  }

  if(auto res = sat.solve(); res){
    std::vector<int> ans(N);
    for(int i = 0; i < N; ++i) ans[i] = (*res)[i] ? i+1 : -(i+1);

    std::cout
      << "s SATISFIABLE" << std::endl
      << "v " << join(ans.begin(), ans.end()) << " " << 0 << std::endl;
  }else{
    std::cout << "s UNSATISFIABLE" << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

