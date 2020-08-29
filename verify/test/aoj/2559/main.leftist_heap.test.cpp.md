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


# :heavy_check_mark: test/aoj/2559/main.leftist_heap.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#470f11b8b249244fcbedd0bf3d66e316">test/aoj/2559</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/2559/main.leftist_heap.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-28 18:23:32+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2559">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2559</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/DataStructure/Heap/leftist_heap.cpp.html">Leftist heap</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/MinimumSpanningTree/prim.cpp.html">Prim algorithm</a>
* :question: <a href="../../../../library/Mylib/Graph/Template/graph.cpp.html">Basic graph</a>
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

#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/MinimumSpanningTree/prim.cpp"
#include "Mylib/Utils/fix_point.cpp"
#include "Mylib/DataStructure/Heap/leftist_heap.cpp"
#include "Mylib/Misc/merge_technique.cpp"

int main(){
  int n, m; std::cin >> n >> m;

  Graph<int64_t> g(n);
  g.read<1, false>(m);
  
  std::map<std::pair<int,int>, int> index;
  for(auto &a : g){
    for(auto &e : a) index[{e.from, e.to}] = e.index;
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
      LeftistHeap<std::tuple<int64_t, int, int>, std::greater<std::tuple<int64_t, int, int>>>
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
#line 1 "test/aoj/2559/main.leftist_heap.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2559"

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <tuple>

#line 3 "Mylib/Graph/Template/graph.cpp"

/**
 * @title Basic graph
 * @docs graph.md
 */
template <typename T>
struct Edge{
  int from, to;
  T cost;
  int index = -1;
  Edge(){}
  Edge(int from, int to, T cost): from(from), to(to), cost(cost){}
  Edge(int from, int to, T cost, int index): from(from), to(to), cost(cost), index(index){}
};

template <typename T>
struct Graph{
  using weight_type = T;
  using edge_type = Edge<T>;
  
  std::vector<std::vector<Edge<T>>> data;

  auto& operator[](size_t i){return data[i];}
  const auto& operator[](size_t i) const {return data[i];}
  
  auto begin() const {return data.begin();}
  auto end() const {return data.end();}

  Graph(){}
  Graph(int N): data(N){}

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
using Tree = Graph<T>;
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
#line 2 "Mylib/DataStructure/Heap/leftist_heap.cpp"
#include <functional>
#line 4 "Mylib/DataStructure/Heap/leftist_heap.cpp"

/**
 * @title Leftist heap
 * @docs leftist_heap.md
 */
template <typename T, class Compare = std::less<T>>
class LeftistHeap{
  struct node{
    T val;
    node *left, *right;
    int s, size;
    node(const T &val): val(val), left(nullptr), right(nullptr), s(0), size(1){}
  };

  node *root;
  Compare compare;

public:
  LeftistHeap(): root(nullptr), compare(Compare()){}
  LeftistHeap(const Compare &compare): root(nullptr), compare(compare){}

protected:
  node* meld(node *a, node *b){
    if(!a) return b;
    if(!b) return a;

    if(compare(a->val, b->val)) std::swap(a, b);

    a->right = meld(a->right, b);
    if(!a->left or a->left->s < a->right->s) std::swap(a->left, a->right);

    a->s = (a->right ? a->right->s : 0) + 1;
    a->size = 1 + (a->left ? a->left->size : 0) + (a->right ? a->right->size : 0);
    return a;
  }

public:
  void meld(LeftistHeap &heap){root = meld(root, heap.root); heap.root = nullptr;}  
  void push(const T &val){root = meld(root, new node(val));}
  const T& top() const {return root->val;}
  void pop(){node *temp = root; root = meld(root->left, root->right); delete temp;}
  bool empty() const {return root == nullptr;}
  size_t size() const {return root ? root->size : 0;}
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
#line 14 "test/aoj/2559/main.leftist_heap.test.cpp"

int main(){
  int n, m; std::cin >> n >> m;

  Graph<int64_t> g(n);
  g.read<1, false>(m);
  
  std::map<std::pair<int,int>, int> index;
  for(auto &a : g){
    for(auto &e : a) index[{e.from, e.to}] = e.index;
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
      LeftistHeap<std::tuple<int64_t, int, int>, std::greater<std::tuple<int64_t, int, int>>>
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

