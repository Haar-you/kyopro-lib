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


# :heavy_check_mark: 重み付きunionfind

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#3ff74e8366c88d06b530f361450b1117">Mylib/DataStructure/UnionFind</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/UnionFind/weighted_unionfind.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-03 01:42:28+09:00


* see: <a href="https://atcoder.jp/contests/abc087/submissions/6544778">https://atcoder.jp/contests/abc087/submissions/6544778</a>
* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330</a>
* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/DSL_1_B/main.test.cpp.html">test/aoj/DSL_1_B/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <numeric>

/**
 * @title 重み付きunionfind
 * @see https://atcoder.jp/contests/abc087/submissions/6544778
 * @see http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330
 * @see http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
 */

template <typename T> class WeightedUnionFind{
  std::vector<int> parent, depth, size;
  std::vector<T> weight;
  int count;

public:
  WeightedUnionFind(int n): parent(n), depth(n,1), size(n,1), weight(n,0){
    std::iota(parent.begin(), parent.end(),0);
  }
  
  int get_root(int i){
    if(parent[i] == i) return i;
    else {
      int p = get_root(parent[i]);
      weight[i] += weight[parent[i]];
      return parent[i] = p;
    }
  }

  T get_weight(int i){get_root(i); return weight[i];} 
  bool is_same(int i, int j){return get_root(i) == get_root(j);}
  T diff(int i, int j){return get_weight(i)-get_weight(j);}
  
  int merge(int i, int j, T w){
    int ri = get_root(i), rj = get_root(j);
    if(ri == rj) return ri;
    else{
      if(depth[ri] < depth[rj]){
        parent[ri] = rj; size[rj] += size[ri]; weight[ri] = w - weight[i] + weight[j];
        return rj;
      }else{
        parent[rj] = ri; size[ri] += size[rj]; weight[rj] = -w + weight[i] - weight[j];
        if(depth[ri] == depth[rj]) ++depth[ri];
        return ri;
      }
    }
  }
  
  int get_size(int i){return size[get_root(i)];}
  int count_group(){return count;}
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DataStructure/UnionFind/weighted_unionfind.cpp"
#include <vector>
#include <numeric>

/**
 * @title 重み付きunionfind
 * @see https://atcoder.jp/contests/abc087/submissions/6544778
 * @see http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330
 * @see http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
 */

template <typename T> class WeightedUnionFind{
  std::vector<int> parent, depth, size;
  std::vector<T> weight;
  int count;

public:
  WeightedUnionFind(int n): parent(n), depth(n,1), size(n,1), weight(n,0){
    std::iota(parent.begin(), parent.end(),0);
  }
  
  int get_root(int i){
    if(parent[i] == i) return i;
    else {
      int p = get_root(parent[i]);
      weight[i] += weight[parent[i]];
      return parent[i] = p;
    }
  }

  T get_weight(int i){get_root(i); return weight[i];} 
  bool is_same(int i, int j){return get_root(i) == get_root(j);}
  T diff(int i, int j){return get_weight(i)-get_weight(j);}
  
  int merge(int i, int j, T w){
    int ri = get_root(i), rj = get_root(j);
    if(ri == rj) return ri;
    else{
      if(depth[ri] < depth[rj]){
        parent[ri] = rj; size[rj] += size[ri]; weight[ri] = w - weight[i] + weight[j];
        return rj;
      }else{
        parent[rj] = ri; size[ri] += size[rj]; weight[rj] = -w + weight[i] - weight[j];
        if(depth[ri] == depth[rj]) ++depth[ri];
        return ri;
      }
    }
  }
  
  int get_size(int i){return size[get_root(i)];}
  int count_group(){return count;}
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

