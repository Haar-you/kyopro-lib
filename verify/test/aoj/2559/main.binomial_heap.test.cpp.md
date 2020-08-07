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


# :heavy_check_mark: test/aoj/2559/main.binomial_heap.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#470f11b8b249244fcbedd0bf3d66e316">test/aoj/2559</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/2559/main.binomial_heap.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-07 18:06:08+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2559">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2559</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/DataStructure/Heap/binomial_heap.cpp.html">Binomial heap</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/MinimumSpanningTree/prim.cpp.html">Prim algorithm</a>
* :question: <a href="../../../../library/Mylib/Graph/graph_template.cpp.html">Graph template</a>
* :question: <a href="../../../../library/Mylib/IO/input_graph.cpp.html">Mylib/IO/input_graph.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Misc/merge_technique.cpp.html">Mylib/Misc/merge_technique.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Utils/fix_point.cpp.html">Fixed point combinator</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2559"

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <tuple>

#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/MinimumSpanningTree/prim.cpp"
#include "Mylib/Utils/fix_point.cpp"
#include "Mylib/DataStructure/Heap/binomial_heap.cpp"
#include "Mylib/Misc/merge_technique.cpp"
#include "Mylib/IO/input_graph.cpp"

int main(){
  int n, m; std::cin >> n >> m;

  auto edges = input_edges<int64_t, 1, true>(m);
  auto g = convert_to_graph<int64_t, false>(n, edges);

  std::map<std::pair<int,int>, int> index;
  for(int i = 0; i < m; ++i){
    const auto &e = edges[i];
    index[{e.from, e.to}] = index[{e.to, e.from}] = i;
  }

  auto res = prim(g);

  std::vector<int64_t> ans(m, -1);

  if((int)res.size() == n-1){
    int64_t s = 0;
    Tree<int64_t> tree(n);

    for(auto &e : res){
      s += e.cost;
      tree[e.from].push_back(e);
    }

    ans.assign(m, s);

    std::vector<
      BinomialHeap<std::tuple<int64_t, int, int>, std::greater<std::tuple<int64_t, int, int>>>
      > sh(n);
    
    std::vector<std::set<int>> sub(n);

    make_fix_point(
      [&](auto &&f, int cur, int par, int64_t cost) -> void{
        for(auto &e : g[cur]){
          sh[cur].push({e.cost, e.from, e.to});
        }

        sub[cur].insert(cur);

        for(auto &e : tree[cur]){
          if(e.to == par) continue;
          f(e.to, cur, e.cost);

          sh[cur].meld(sh[e.to]);
          merge_technique(sub[cur], sub[cur], sub[e.to]);
        }

        if(par != -1){
          while(not sh[cur].empty()){
            auto [c, i, j] = sh[cur].top();
            if((sub[cur].find(i) != sub[cur].end() and sub[cur].find(j) != sub[cur].end()) or
               (i == cur and j == par) or (i == par and j == cur)){
              sh[cur].pop();
            }else{
              break;
            }
          }

          if(not sh[cur].empty()){
            ans[index[{cur, par}]] = s - cost + std::get<0>(sh[cur].top());
          }else{
            ans[index[{cur, par}]] = -1;
          }
        }
      }
    )(0, -1, 0);
  }

  for(auto x : ans){
    std::cout << x << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/2559/main.binomial_heap.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2559"

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <tuple>

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
#line 3 "Mylib/Graph/MinimumSpanningTree/prim.cpp"
#include <queue>
#line 5 "Mylib/Graph/MinimumSpanningTree/prim.cpp"

/**
 * @title Prim algorithm
 * @docs prim.md
 */
template <typename T>
std::vector<Edge<T>> prim(const Graph<T> &graph){
  int n = graph.size();
  std::vector<bool> visit(n, false);
  std::vector<Edge<T>> ret;

  auto cmp = [](const auto &a, const auto &b){return a.cost > b.cost;};
  std::priority_queue<Edge<T>, std::vector<Edge<T>>, decltype(cmp)> pq(cmp);
  
  visit[0] = true;
  for(auto &e : graph[0]) pq.push(e);

  while(not pq.empty()){
    auto t = pq.top(); pq.pop();

    if(visit[t.from] == visit[t.to]) continue;

    int i = visit[t.from] ? t.to : t.from;
    for(auto &e : graph[i]){
      pq.push(e);
    }

    visit[i] = true;
    ret.push_back(t);
  }

  return ret;
}
#line 2 "Mylib/Utils/fix_point.cpp"
#include <utility>

/**
 * @title Fixed point combinator
 * @docs fix_point.md
 */
template <typename F>
struct FixPoint : F{
  explicit constexpr FixPoint(F &&f) noexcept : F(std::forward<F>(f)){}

  template <typename... Args>
  constexpr auto operator()(Args &&... args) const {
    return F::operator()(*this, std::forward<Args>(args)...);
  }
};

template <typename F>
inline constexpr auto make_fix_point(F &&f){
  return FixPoint<F>(std::forward<F>(f));
}

template <typename F>
inline constexpr auto make_fix_point(F &f){
  return FixPoint<F>(std::forward<F>(f));
}
#line 3 "Mylib/DataStructure/Heap/binomial_heap.cpp"
#include <array>
#include <functional>
#include <cassert>

/**
 * @title Binomial heap
 * @docs binomial_heap.md
 */
template <typename T, typename Compare = std::less<T>>
class BinomialHeap{
  struct node{
    T value;
    std::vector<node*> children;
    node(T value): value(value){}
  };

  constexpr static int MAX = 31;
  
  std::array<node*, MAX> roots;
  Compare compare;
  int top_index = -1;
  int heap_size = 0;

  node* merge(node *a, node *b){
    if(compare(a->value, b->value)) std::swap(a, b);
    a->children.push_back(b);
    return a;
  }

  template <typename Container>
  void meld(Container c){
    node *s = nullptr;

    for(int i = 0; i < MAX; ++i){
      std::vector<node*> temp;
      if(s){temp.push_back(s); s = nullptr;}
      if(roots[i]){temp.push_back(roots[i]); roots[i] = nullptr;}
      if(i < (int)c.size() and c[i]){temp.push_back(c[i]); c[i] = nullptr;}

      switch(temp.size()){
      case 1: roots[i] = temp[0]; break;
      case 2: s = merge(temp[0], temp[1]); break;
      case 3: roots[i] = temp[0]; s = merge(temp[1], temp[2]); break;
      }
    }
    
    top_index = -1;
    for(int i = 0; i < MAX; ++i){
      if(roots[i]){
        if(top_index == -1 or compare(roots[top_index]->value, roots[i]->value)){
          top_index = i;
        }
      }
    }
  }

public:
  BinomialHeap(){
    roots.fill(nullptr);
    compare = Compare();
  }

  int size() const {
    return heap_size;
  }

  bool empty() const {
    return heap_size == 0;
  }
  
  void push(const T &value){
    heap_size += 1;
    node *t = new node(value);

    meld(std::vector<node*>({t}));
  }

  const T& top() const {
    return roots[top_index]->value;
  }

  void pop(){
    heap_size -= 1;
    
    node *t = roots[top_index];
    roots[top_index] = nullptr;
    meld(t->children);

    delete t;
  }

  void meld(BinomialHeap &rhs){
    heap_size += rhs.heap_size;
    meld(rhs.roots);
    rhs.roots.fill(nullptr);
  }
};
#line 4 "Mylib/Misc/merge_technique.cpp"

/**
 * @docs merge_technique.md
 */
template <typename T>
void merge_technique(std::set<T> &res, std::set<T> &a, std::set<T> &b){
  if(a.size() > b.size()){
    a.insert(b.begin(), b.end());
    std::swap(res, a);
  }else{
    b.insert(a.begin(), a.end());
    std::swap(res, b);
  }
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
#line 15 "test/aoj/2559/main.binomial_heap.test.cpp"

int main(){
  int n, m; std::cin >> n >> m;

  auto edges = input_edges<int64_t, 1, true>(m);
  auto g = convert_to_graph<int64_t, false>(n, edges);

  std::map<std::pair<int,int>, int> index;
  for(int i = 0; i < m; ++i){
    const auto &e = edges[i];
    index[{e.from, e.to}] = index[{e.to, e.from}] = i;
  }

  auto res = prim(g);

  std::vector<int64_t> ans(m, -1);

  if((int)res.size() == n-1){
    int64_t s = 0;
    Tree<int64_t> tree(n);

    for(auto &e : res){
      s += e.cost;
      tree[e.from].push_back(e);
    }

    ans.assign(m, s);

    std::vector<
      BinomialHeap<std::tuple<int64_t, int, int>, std::greater<std::tuple<int64_t, int, int>>>
      > sh(n);
    
    std::vector<std::set<int>> sub(n);

    make_fix_point(
      [&](auto &&f, int cur, int par, int64_t cost) -> void{
        for(auto &e : g[cur]){
          sh[cur].push({e.cost, e.from, e.to});
        }

        sub[cur].insert(cur);

        for(auto &e : tree[cur]){
          if(e.to == par) continue;
          f(e.to, cur, e.cost);

          sh[cur].meld(sh[e.to]);
          merge_technique(sub[cur], sub[cur], sub[e.to]);
        }

        if(par != -1){
          while(not sh[cur].empty()){
            auto [c, i, j] = sh[cur].top();
            if((sub[cur].find(i) != sub[cur].end() and sub[cur].find(j) != sub[cur].end()) or
               (i == cur and j == par) or (i == par and j == cur)){
              sh[cur].pop();
            }else{
              break;
            }
          }

          if(not sh[cur].empty()){
            ans[index[{cur, par}]] = s - cost + std::get<0>(sh[cur].top());
          }else{
            ans[index[{cur, par}]] = -1;
          }
        }
      }
    )(0, -1, 0);
  }

  for(auto x : ans){
    std::cout << x << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

