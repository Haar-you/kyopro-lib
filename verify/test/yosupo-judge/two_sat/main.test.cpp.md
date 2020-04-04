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


# :heavy_check_mark: test/yosupo-judge/two_sat/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#e93cc7e7edd1deb522641737d913fca6">test/yosupo-judge/two_sat</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/two_sat/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 18:35:49+09:00


* see: <a href="https://judge.yosupo.jp/problem/two_sat">https://judge.yosupo.jp/problem/two_sat</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/GraphUtils/strongly_connected_components.cpp.html">強連結成分分解</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/TopologicalSort/topological_sort.cpp.html">トポロジカルソート</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/graph_template.cpp.html">グラフ用テンプレート</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/two_sat.cpp.html">2-SAT</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#include <iostream>
#include <string>
#include <vector>
#include "Mylib/Graph/two_sat.cpp"

int main(){
  std::string p, cnf;
  int N,M;
  std::cin >> p >> cnf >> N >> M;

  TwoSat sat(N);

  for(int i = 0; i < M; ++i){
    int a,b,c; std::cin >> a >> b >> c;
    sat.add_or(a,b);
  }

  if(auto res = sat.solve(); res){
    std::cout << "s SATISFIABLE" << std::endl;
    std::vector<int> ans(N);

    for(int i = 0; i < N; ++i) ans[i] = (*res)[i] ? i+1 : -(i+1);

    std::cout << "v ";
    for(auto x : ans) std::cout << x << " ";
    std::cout << 0 << std::endl;
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
 * @title グラフ用テンプレート
 */
template <typename Cost = int> class Edge{
public:
  int from,to;
  Cost cost;
  Edge() {}
  Edge(int to, Cost cost): to(to), cost(cost){}
  Edge(int from, int to, Cost cost): from(from), to(to), cost(cost){}

  Edge rev() const {return Edge(to,from,cost);}
  
  friend std::ostream& operator<<(std::ostream &os, const Edge &e){
    os << "(FROM: " << e.from << "," << "TO: " << e.to << "," << "COST: " << e.cost << ")";
    return os;
  }
};

template <typename T> using Graph = std::vector<std::vector<Edge<T>>>;
template <typename T> using Tree = std::vector<std::vector<Edge<T>>>;

template <typename C, typename T> void add_edge(C &g, int from, int to, T w){
  g[from].emplace_back(from, to, w);
}

template <typename C, typename T> void add_undirected(C &g, int a, int b, T w){
  add_edge(g, a, b, w);
  add_edge(g, b, a, w);
}
#line 3 "Mylib/Graph/GraphUtils/strongly_connected_components.cpp"
#include <algorithm>
#line 5 "Mylib/Graph/GraphUtils/strongly_connected_components.cpp"

/**
 * @title 強連結成分分解
 */
template <typename T>
struct SCC{
  std::vector<int> result;
  int scc_size;
  
private:
  std::vector<bool> visit;
  std::vector<int> check;
  
  void dfs(int cur, const Graph<T> &graph){
    visit[cur] = true;
    for(auto &e : graph[cur]){
      if(not visit[e.to]) dfs(e.to,graph);
    }
    check.push_back(cur);
  }

  void rdfs(int cur, int i, const Graph<T> &rgraph){
    result[cur] = i;
    for(auto &e : rgraph[cur]){
      if(result[e.to] == -1) rdfs(e.to,i,rgraph);
    }
  }

public:
  SCC(const Graph<T> &graph){
    const int n = graph.size();
    result.assign(n, -1);
    visit.assign(n, false);
    
    for(int i = 0; i < n; ++i) if(!visit[i]) dfs(i,graph);
    std::reverse(check.begin(), check.end());
    
    Graph<T> rgraph(n);
    for(int i = 0; i < n; ++i) for(auto &e : graph[i]) rgraph[e.to].push_back(e.rev());

    int i = 0;
    for(auto c : check) if(result[c] == -1) {rdfs(c,i,rgraph); ++i;}
    scc_size = i;
  }

  inline const int operator[](int i) const {return result[i];}
};
#line 3 "Mylib/Graph/TopologicalSort/topological_sort.cpp"
#include <optional>
#include <queue>
#line 6 "Mylib/Graph/TopologicalSort/topological_sort.cpp"

/**
 * @title トポロジカルソート
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
  for(int i = n-1; i >= 0; --i){
    if(indeg[i] == 0) q.push(i);
  }

  std::vector<int> ret;
  while(!q.empty()){
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
 * @see https://yukicoder.me/problems/no/274 https://yukicoder.me/submissions/340917/source
 * @see https://yukicoder.me/problems/no/470 https://yukicoder.me/submissions/383028/source
 * @see https://atcoder.jp/contests/arc069/submissions/8830581
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
    auto scc = SCC<int>(g);

    for(int i = 0; i < n; ++i){
      if(scc[i] == scc[i+n]) return std::nullopt;
    }
    
    int m = scc.scc_size;

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
#line 7 "test/yosupo-judge/two_sat/main.test.cpp"

int main(){
  std::string p, cnf;
  int N,M;
  std::cin >> p >> cnf >> N >> M;

  TwoSat sat(N);

  for(int i = 0; i < M; ++i){
    int a,b,c; std::cin >> a >> b >> c;
    sat.add_or(a,b);
  }

  if(auto res = sat.solve(); res){
    std::cout << "s SATISFIABLE" << std::endl;
    std::vector<int> ans(N);

    for(int i = 0; i < N; ++i) ans[i] = (*res)[i] ? i+1 : -(i+1);

    std::cout << "v ";
    for(auto x : ans) std::cout << x << " ";
    std::cout << 0 << std::endl;
  }else{
    std::cout << "s UNSATISFIABLE" << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

