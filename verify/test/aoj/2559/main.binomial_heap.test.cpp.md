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
    - Last commit date: 2020-09-09 02:56:29+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2559">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2559</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/DataStructure/Heap/binomial_heap.cpp.html">Binomial heap</a>
* :question: <a href="../../../../library/Mylib/Graph/MinimumSpanningTree/prim.cpp.html">Prim algorithm</a>
* :question: <a href="../../../../library/Mylib/Graph/Template/graph.cpp.html">Basic graph</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Misc/merge_technique.cpp.html">Mylib/Misc/merge_technique.cpp</a>
* :question: <a href="../../../../library/Mylib/Utils/fix_point.cpp.html">Fixed point combinator</a>


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
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/MinimumSpanningTree/prim.cpp"
#include "Mylib/Utils/fix_point.cpp"
#include "Mylib/DataStructure/Heap/binomial_heap.cpp"
#include "Mylib/Misc/merge_technique.cpp"

namespace hl = haar_lib;

int main(){
  int n, m; std::cin >> n >> m;

  hl::graph<int64_t> g(n);
  g.read<1, false>(m);

  std::map<std::pair<int, int>, int> index;
  for(auto &a : g){
    for(auto &e : a) index[{e.from, e.to}] = e.index;
  }

  auto res = hl::prim(g);

  std::vector<int64_t> ans(m, -1);

  if((int)res.size() == n - 1){
    int64_t s = 0;
    hl::tree<int64_t> tree(n);

    for(auto &e : res){
      s += e.cost;
      tree[e.from].push_back(e);
    }

    ans.assign(m, s);

    std::vector<hl::binomial_heap<std::tuple<int64_t, int, int>, std::greater<>>> heaps(n);

    std::vector<std::set<int>> sub(n);

    hl::make_fix_point(
      [&](auto &&f, int cur, int par, int64_t cost) -> void {
        for(auto &e : g[cur]){
          heaps[cur].push({e.cost, e.from, e.to});
        }

        sub[cur].insert(cur);

        for(auto &e : tree[cur]){
          if(e.to == par) continue;
          f(e.to, cur, e.cost);

          heaps[cur].meld(heaps[e.to]);
          hl::merge_technique(sub[cur], sub[cur], sub[e.to]);
        }

        if(par != -1){
          while(not heaps[cur].empty()){
            auto [c, i, j] = heaps[cur].top();
            if((sub[cur].find(i) != sub[cur].end() and sub[cur].find(j) != sub[cur].end()) or
               (i == cur and j == par) or (i == par and j == cur)){
              heaps[cur].pop();
            }else{
              break;
            }
          }

          if(not heaps[cur].empty()){
            ans[index[{cur, par}]] = s - cost + std::get<0>(heaps[cur].top());
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
#line 4 "Mylib/Graph/Template/graph.cpp"

/**
 * @title Basic graph
 * @docs graph.md
 */
namespace haar_lib {
  template <typename T>
  struct edge {
    int from, to;
    T cost;
    int index = -1;
    edge(){}
    edge(int from, int to, T cost): from(from), to(to), cost(cost){}
    edge(int from, int to, T cost, int index): from(from), to(to), cost(cost), index(index){}
  };

  template <typename T>
  struct graph {
    using weight_type = T;
    using edge_type = edge<T>;

    std::vector<std::vector<edge<T>>> data;

    auto& operator[](size_t i){return data[i];}
    const auto& operator[](size_t i) const {return data[i];}

    auto begin() const {return data.begin();}
    auto end() const {return data.end();}

    graph(){}
    graph(int N): data(N){}

    bool empty() const {return data.empty();}
    int size() const {return data.size();}

    void add_edge(int i, int j, T w, int index = -1){
      data[i].emplace_back(i, j, w, index);
    }

    void add_undirected(int i, int j, T w, int index = -1){
      add_edge(i, j, w, index);
      add_edge(j, i, w, index);
    }

    template <size_t I, bool DIRECTED = true, bool WEIGHTED = true>
    void read(int M){
      for(int i = 0; i < M; ++i){
        int u, v; std::cin >> u >> v;
        u -= I;
        v -= I;
        T w = 1;
        if(WEIGHTED) std::cin >> w;
        if(DIRECTED) add_edge(u, v, w, i);
        else add_undirected(u, v, w, i);
      }
    }
  };

  template <typename T>
  using tree = graph<T>;
}
#line 3 "Mylib/Graph/MinimumSpanningTree/prim.cpp"
#include <queue>
#line 5 "Mylib/Graph/MinimumSpanningTree/prim.cpp"

/**
 * @title Prim algorithm
 * @docs prim.md
 */
namespace haar_lib {
  template <typename T>
  std::vector<edge<T>> prim(const graph<T> &graph){
    const int n = graph.size();
    std::vector<bool> visit(n, false);
    std::vector<edge<T>> ret;

    auto cmp = [](const auto &a, const auto &b){return a.cost > b.cost;};
    std::priority_queue<edge<T>, std::vector<edge<T>>, decltype(cmp)> pq(cmp);

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
}
#line 2 "Mylib/Utils/fix_point.cpp"
#include <utility>

/**
 * @title Fixed point combinator
 * @docs fix_point.md
 */
namespace haar_lib {
  template <typename F>
  struct fix_point : F {
    explicit constexpr fix_point(F &&f) noexcept : F(std::forward<F>(f)){}

    template <typename ... Args>
    constexpr auto operator()(Args &&... args) const {
      return F::operator()(*this, std::forward<Args>(args) ...);
    }
  };

  template <typename F>
  inline constexpr auto make_fix_point(F &&f){
    return fix_point<F>(std::forward<F>(f));
  }

  template <typename F>
  inline constexpr auto make_fix_point(F &f){
    return fix_point<F>(std::forward<F>(f));
  }
}
#line 3 "Mylib/DataStructure/Heap/binomial_heap.cpp"
#include <array>
#include <functional>
#include <cassert>

/**
 * @title Binomial heap
 * @docs binomial_heap.md
 */
namespace haar_lib {
  template <typename T, typename Compare = std::less<T>>
  class binomial_heap {
    struct node {
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
    binomial_heap(){
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

    void meld(binomial_heap &rhs){
      heap_size += rhs.heap_size;
      meld(rhs.roots);
      rhs.roots.fill(nullptr);
    }
  };
}
#line 4 "Mylib/Misc/merge_technique.cpp"

/**
 * @docs merge_technique.md
 */
namespace haar_lib {
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
}
#line 13 "test/aoj/2559/main.binomial_heap.test.cpp"

namespace hl = haar_lib;

int main(){
  int n, m; std::cin >> n >> m;

  hl::graph<int64_t> g(n);
  g.read<1, false>(m);

  std::map<std::pair<int, int>, int> index;
  for(auto &a : g){
    for(auto &e : a) index[{e.from, e.to}] = e.index;
  }

  auto res = hl::prim(g);

  std::vector<int64_t> ans(m, -1);

  if((int)res.size() == n - 1){
    int64_t s = 0;
    hl::tree<int64_t> tree(n);

    for(auto &e : res){
      s += e.cost;
      tree[e.from].push_back(e);
    }

    ans.assign(m, s);

    std::vector<hl::binomial_heap<std::tuple<int64_t, int, int>, std::greater<>>> heaps(n);

    std::vector<std::set<int>> sub(n);

    hl::make_fix_point(
      [&](auto &&f, int cur, int par, int64_t cost) -> void {
        for(auto &e : g[cur]){
          heaps[cur].push({e.cost, e.from, e.to});
        }

        sub[cur].insert(cur);

        for(auto &e : tree[cur]){
          if(e.to == par) continue;
          f(e.to, cur, e.cost);

          heaps[cur].meld(heaps[e.to]);
          hl::merge_technique(sub[cur], sub[cur], sub[e.to]);
        }

        if(par != -1){
          while(not heaps[cur].empty()){
            auto [c, i, j] = heaps[cur].top();
            if((sub[cur].find(i) != sub[cur].end() and sub[cur].find(j) != sub[cur].end()) or
               (i == cur and j == par) or (i == par and j == cur)){
              heaps[cur].pop();
            }else{
              break;
            }
          }

          if(not heaps[cur].empty()){
            ans[index[{cur, par}]] = s - cost + std::get<0>(heaps[cur].top());
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

