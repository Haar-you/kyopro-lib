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


# :x: test/yosupo-judge/unionfind/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#5aa16257c29c51dffa0b4e5427dcc272">test/yosupo-judge/unionfind</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/unionfind/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-03 01:42:28+09:00


* see: <a href="https://judge.yosupo.jp/problem/unionfind">https://judge.yosupo.jp/problem/unionfind</a>


## Depends on

* :question: <a href="../../../../library/Mylib/DataStructure/UnionFind/unionfind.cpp.html">unionfind</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <iostream>
#include "Mylib/DataStructure/UnionFind/unionfind.cpp"


int main(){
  int N, Q; std::cin >> N >> Q;

  UnionFind uf(N);

  while(Q--){
    int t; std::cin >> t;

    if(t == 0){
      int u, v; std::cin >> u >> v;
      uf.merge(u, v);
    }else{
      int u, v; std::cin >> u >> v;
      std::cout << uf.is_same(u, v) << std::endl;
    }
  }
  
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/unionfind/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <iostream>
#line 2 "Mylib/DataStructure/UnionFind/unionfind.cpp"
#include <vector>
#include <numeric>

/**
 * @title unionfind
 */
class UnionFind{
  std::vector<int> parent, depth, size;
  int count;

public:
  UnionFind(int n): parent(n), depth(n,1), size(n,1), count(n){
    std::iota(parent.begin(), parent.end(), 0);
  }
  
  inline int get_root(int i){
    if(parent[i] == i) return i;
    else return parent[i] = get_root(parent[i]);
  }
  
  inline bool is_same(int i, int j){return get_root(i) == get_root(j);}

  inline int merge(int i, int j){
    int ri = get_root(i), rj = get_root(j);
    if(ri == rj) return ri;
    else{
      --count;
      if(depth[ri] < depth[rj]){
        parent[ri] = rj;
        size[rj] += size[ri];
        return rj;
      }else{
        parent[rj] = ri;
        size[ri] += size[rj];
        if(depth[ri] == depth[rj]) ++depth[ri];
        return ri;
      }
    }
  }

  inline int get_size(int i){return size[get_root(i)];}

  inline int count_group(){return count;}
};
#line 5 "test/yosupo-judge/unionfind/main.test.cpp"


int main(){
  int N, Q; std::cin >> N >> Q;

  UnionFind uf(N);

  while(Q--){
    int t; std::cin >> t;

    if(t == 0){
      int u, v; std::cin >> u >> v;
      uf.merge(u, v);
    }else{
      int u, v; std::cin >> u >> v;
      std::cout << uf.is_same(u, v) << std::endl;
    }
  }
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

