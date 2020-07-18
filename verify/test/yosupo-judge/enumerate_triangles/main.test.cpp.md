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


# :heavy_check_mark: test/yosupo-judge/enumerate_triangles/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#e25b567185ad9d2c82bdf5444236f5c2">test/yosupo-judge/enumerate_triangles</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/enumerate_triangles/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-08 12:08:32+09:00


* see: <a href="https://judge.yosupo.jp/problem/enumerate_triangles">https://judge.yosupo.jp/problem/enumerate_triangles</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/enumerate_triangles.cpp.html">Enumerate triangles</a>
* :question: <a href="../../../../library/Mylib/Graph/graph_template.cpp.html">Graph template</a>
* :question: <a href="../../../../library/Mylib/IO/input_graph.cpp.html">Mylib/IO/input_graph.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>
* :question: <a href="../../../../library/Mylib/Number/Mint/mint.cpp.html">Modint</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_triangles"

#include <iostream>

#include "Mylib/IO/input_graph.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/Graph/enumerate_triangles.cpp"
#include "Mylib/Number/Mint/mint.cpp"

using mint = ModInt<998244353>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, M; std::cin >> N >> M;
  auto x = input_vector<mint>(N);
  auto g = convert_to_graph<int, false>(N, input_edges<int, 0, false>(M));

  auto res = enumerate_triangles(g);
  mint ans = 0;
  for(auto [i, j, k] : res) ans += x[i] * x[j] * x[k];

  std::cout << ans << "\n";
  
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/enumerate_triangles/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_triangles"

#include <iostream>

#line 2 "Mylib/Graph/graph_template.cpp"
#include <vector>
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
#line 4 "Mylib/IO/input_graph.cpp"

/**
 * @docs input_graph.md
 */
template <typename T, size_t I, bool WEIGHTED>
std::vector<Edge<T>> input_edges(int M){
  std::vector<Edge<T>> ret;
  
  for(int i = 0; i < M; ++i){
    int s, t; std::cin >> s >> t;
    s -= I;
    t -= I;
    T w = 1; if(WEIGHTED) std::cin >> w;
    ret.emplace_back(s, t, w);
  }
  
  return ret;  
}

template <typename T, bool DIRECTED>
Graph<T> convert_to_graph(int N, const std::vector<Edge<T>> &edges){
  Graph<T> g(N);

  for(const auto &e : edges){
    add_edge(g, e.from, e.to, e.cost);
    if(not DIRECTED) add_edge(g, e.to, e.from, e.cost);
  }
  
  return g;
}
#line 4 "Mylib/IO/input_vector.cpp"

/**
 * @docs input_vector.md
 */
template <typename T>
std::vector<T> input_vector(int N){
  std::vector<T> ret(N);
  for(int i = 0; i < N; ++i) std::cin >> ret[i];
  return ret;
}

template <typename T>
std::vector<std::vector<T>> input_vector(int N, int M){
  std::vector<std::vector<T>> ret(N);
  for(int i = 0; i < N; ++i) ret[i] = input_vector<T>(M);
  return ret;
}
#line 3 "Mylib/Graph/enumerate_triangles.cpp"
#include <tuple>
#include <unordered_set>
#line 6 "Mylib/Graph/enumerate_triangles.cpp"

/**
 * @title Enumerate triangles
 * @docs enumerate_triangles.md
 */
template <typename T>
std::vector<std::tuple<int,int,int>> enumerate_triangles(Graph<T> g){
  const int N = g.size();
  std::vector<std::tuple<int,int,int>> ret;

  std::vector<std::unordered_set<int>> adjacent(N);

  for(int i = 0; i < N; ++i){
    for(auto &e : g[i]){
      if(g[e.from].size() < g[e.to].size()){
        adjacent[e.from].insert(e.to);
      }else if(g[e.from].size() == g[e.to].size()){
        if(e.from < e.to){
          adjacent[e.from].insert(e.to);
        }
      }
    }
  }

  for(int i = 0; i < N; ++i){
    for(int j : adjacent[i]){
      for(int k : adjacent[j]){
        if(adjacent[i].find(k) != adjacent[i].end()){
          ret.emplace_back(i, j, k);
        }
      }
    }
  }

  return ret;
}
#line 3 "Mylib/Number/Mint/mint.cpp"
#include <utility>

/**
 * @title Modint
 * @docs mint.md
 */
template <uint32_t M> class ModInt{
public:
  constexpr static uint32_t MOD = M;
  uint64_t val;
  
  constexpr ModInt(): val(0){}
  constexpr ModInt(int64_t n){
    if(n >= M) val = n % M;
    else if(n < 0) val = n % M + M;
    else val = n;
  }
  
  constexpr auto operator+(const ModInt &a) const {return ModInt(val + a.val);}
  constexpr auto operator-(const ModInt &a) const {return ModInt(val - a.val);}
  constexpr auto operator*(const ModInt &a) const {return ModInt(val * a.val);}
  constexpr auto operator/(const ModInt &a) const {return ModInt(val * a.inv().val);}
  
  constexpr auto& operator=(const ModInt &a){val = a.val; return *this;}
  constexpr auto& operator+=(const ModInt &a){if((val += a.val) >= M) val -= M; return *this;}
  constexpr auto& operator-=(const ModInt &a){if(val < a.val) val += M; val -= a.val; return *this;}
  constexpr auto& operator*=(const ModInt &a){(val *= a.val) %= M; return *this;}
  constexpr auto& operator/=(const ModInt &a){(val *= a.inv().val) %= M; return *this;}
 
  constexpr bool operator==(const ModInt &a) const {return val == a.val;}
  constexpr bool operator!=(const ModInt &a) const {return val != a.val;}
 
  constexpr auto& operator++(){*this += 1; return *this;}
  constexpr auto& operator--(){*this -= 1; return *this;}
 
  constexpr auto operator++(int){auto t = *this; *this += 1; return t;}
  constexpr auto operator--(int){auto t = *this; *this -= 1; return t;}
 
  constexpr static ModInt power(int64_t n, int64_t p){
    if(p < 0) return power(n, -p).inv();
    
    int64_t ret = 1, e = n % M;
    for(; p; (e *= e) %= M, p >>= 1) if(p & 1) (ret *= e) %= M;
    return ret;
  }
 
  constexpr static ModInt inv(int64_t a){
    int64_t b = M, u = 1, v = 0;
    
    while(b){
      int64_t t = a / b;
      a -= t * b; std::swap(a,b);
      u -= t * v; std::swap(u,v);
    }
 
    u %= M;
    if(u < 0) u += M;
    
    return u;
  }
 
  constexpr static auto frac(int64_t a, int64_t b){return ModInt(a) / ModInt(b);}
  
  constexpr auto power(int64_t p) const {return power(val, p);}
  constexpr auto inv() const {return inv(val);}
 
  friend constexpr auto operator-(const ModInt &a){return ModInt(-a.val);}
 
  friend constexpr auto operator+(int64_t a, const ModInt &b){return ModInt(a) + b;}
  friend constexpr auto operator-(int64_t a, const ModInt &b){return ModInt(a) - b;}
  friend constexpr auto operator*(int64_t a, const ModInt &b){return ModInt(a) * b;}
  friend constexpr auto operator/(int64_t a, const ModInt &b){return ModInt(a) / b;}
 
  friend std::istream& operator>>(std::istream &s, ModInt<M> &a){s >> a.val; return s;}
  friend std::ostream& operator<<(std::ostream &s, const ModInt<M> &a){s << a.val; return s;}

  template <int N>
  static auto div(){
    static auto value = inv(N);
    return value;
  }

  explicit operator int32_t() const noexcept {return val;}
  explicit operator int64_t() const noexcept {return val;}
};
#line 9 "test/yosupo-judge/enumerate_triangles/main.test.cpp"

using mint = ModInt<998244353>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, M; std::cin >> N >> M;
  auto x = input_vector<mint>(N);
  auto g = convert_to_graph<int, false>(N, input_edges<int, 0, false>(M));

  auto res = enumerate_triangles(g);
  mint ans = 0;
  for(auto [i, j, k] : res) ans += x[i] * x[j] * x[k];

  std::cout << ans << "\n";
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

