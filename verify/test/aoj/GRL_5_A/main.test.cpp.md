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


# :heavy_check_mark: test/aoj/GRL_5_A/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a624c615c8a90227d4c31dd34d7dfde1">test/aoj/GRL_5_A</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_5_A/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/TreeUtils/tree_utils.cpp.html">TreeUtils</a>
* :question: <a href="../../../../library/Mylib/Graph/graph_template.cpp.html">グラフ用テンプレート</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A"

#include <iostream>
#include <tuple>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/TreeUtils/tree_utils.cpp"

int main(){
  int n; std::cin >> n;
  Tree<int> tree(n);

  for(int i = 0; i < n-1; ++i){
    int s, t, w; std::cin >> s >> t >> w;
    add_undirected(tree, s, t, w);
  }

  int ans;
  std::tie(std::ignore, std::ignore, ans) = TreeUtils<int>::diameter(tree);
  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_5_A/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A"

#include <iostream>
#include <tuple>
#line 2 "Mylib/Graph/graph_template.cpp"
#include <vector>
#line 4 "Mylib/Graph/graph_template.cpp"

/**
 * @title グラフ用テンプレート
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
#line 3 "Mylib/Graph/TreeUtils/tree_utils.cpp"
#include <utility>
#include <stack>
#line 6 "Mylib/Graph/TreeUtils/tree_utils.cpp"
#include <algorithm>
#line 8 "Mylib/Graph/TreeUtils/tree_utils.cpp"

/**
 * @title TreeUtils
 * @docs tree_utils.md
 */
template <typename T> class TreeUtils{
public:
  static std::pair<int,T> farthest(const Tree<T> &tree, int cur, int par = -1){
    auto d = std::make_pair(cur, 0);
    for(auto &e : tree[cur]){
      if(e.to == par) continue;
      auto t = farthest(tree, e.to, cur);
      t.second += e.cost;
      if(t.second > d.second) d = t;
    }
    return d;
  }

  static std::vector<T> distance(const Tree<T> &tree, int root){
    int n = tree.size();
    std::vector<T> ret(n);
    std::vector<bool> visited(n);
    
    std::stack<int> st;
    st.push(root);
    ret[root] = 0;
    
    while(not st.empty()){
      int cur = st.top(); st.pop();
      visited[cur] = true;
      
      for(auto &e : tree[cur]){
        if(not visited[e.to]){
          ret[e.to] = ret[cur] + e.cost;
          st.push(e.to);
        }
      }
    }
    
    return ret;
  }
  
  static std::tuple<int, int, T> diameter(const Tree<T> &tree){
    auto a = farthest(tree, 0);
    auto b = farthest(tree, a.first);
    return std::make_tuple(a.first, b.first, b.second);
  }

  static std::vector<T> height(const Tree<T> &tree){
    auto a = farthest(tree, 0);
    auto b = farthest(tree, a.first);

    int n = tree.size();

    auto d1 = distance(tree, a.first);
    auto d2 = distance(tree, b.first);

    std::vector<T> h(n);
    for(int i = 0; i < n; ++i) h[i] = std::max(d1[i], d2[i]);
    
    return h;
  }
};
#line 7 "test/aoj/GRL_5_A/main.test.cpp"

int main(){
  int n; std::cin >> n;
  Tree<int> tree(n);

  for(int i = 0; i < n-1; ++i){
    int s, t, w; std::cin >> s >> t >> w;
    add_undirected(tree, s, t, w);
  }

  int ans;
  std::tie(std::ignore, std::ignore, ans) = TreeUtils<int>::diameter(tree);
  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
