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


# :x: test/yosupo-judge/staticrmq/main.sparse_table.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#5680c9d4a5622c4318d3dde130a2c657">test/yosupo-judge/staticrmq</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/staticrmq/main.sparse_table.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-12 08:15:26+09:00


* see: <a href="https://judge.yosupo.jp/problem/staticrmq">https://judge.yosupo.jp/problem/staticrmq</a>


## Depends on

* :question: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/min.cpp.html">Mylib/AlgebraicStructure/Monoid/min.cpp</a>
* :x: <a href="../../../../library/Mylib/DataStructure/SparseTable/sparse_table.cpp.html">Sparse table</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <iostream>
#include <vector>

#include "Mylib/DataStructure/SparseTable/sparse_table.cpp"
#include "Mylib/AlgebraicStructure/Monoid/min.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, Q; std::cin >> N >> Q;

  std::vector<int> a(N);
  for(int i = 0; i < N; ++i) std::cin >> a[i];

  SparseTable<MinMonoid<int>> s(a);

  while(Q--){
    int l, r; std::cin >> l >> r;

    std::cout << s.get(l, r) << "\n";
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/staticrmq/main.sparse_table.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <iostream>
#include <vector>

#line 3 "Mylib/DataStructure/SparseTable/sparse_table.cpp"
#include <utility>
#include <algorithm>

/**
 * @title Sparse table
 * @docs sparse_table.md
 */
template <typename Semilattice>
class SparseTable{
  using value_type = typename Semilattice::value_type;
  
  std::vector<std::vector<value_type>> a;
  std::vector<int> log_table;
  
public:
  SparseTable(const std::vector<value_type> &v){
    int n = v.size();
    int logn = 0;
    while((1 << logn) <= n) ++logn;
    
    a.assign(n, std::vector<value_type>(logn));
    for(int i = 0; i < n; ++i) a[i][0] = v[i];
    for(int j = 1; j < logn; ++j){
      for(int i = 0; i < n; ++i){
        a[i][j] = Semilattice::op(a[i][j-1], a[std::min<int>(n-1, i+(1<<(j-1)))][j-1]);
      }
    }

    log_table.assign(n+1, 0);
    for(int i = 2; i < n+1; ++i) log_table[i] = log_table[i>>1] + 1;
  }
  
  inline value_type get(int s, int t) const { // [s,t)
    int k = log_table[t-s];
    return Semilattice::op(a[s][k], a[t-(1<<k)][k]);
  }

  inline value_type get(std::vector<std::pair<int,int>> st) const {
    value_type ret;
    bool t = true;

    for(const auto &p : st){
      if(p.first < p.second){
        if(t){
          ret = get(p.first, p.second);
          t = false;
        }else{
          ret = Semilattice::op(ret, get(p.first, p.second));
        }
      }
    }

    return ret;
  }
};
#line 3 "Mylib/AlgebraicStructure/Monoid/min.cpp"

/**
 * @docs min.md
 */
template <typename T>
struct MinMonoid{
  using value_type = T;
  constexpr inline static value_type id(){return std::numeric_limits<T>::max();}
  constexpr inline static value_type op(const value_type &a, const value_type &b){return std::min(a, b);}
};
#line 8 "test/yosupo-judge/staticrmq/main.sparse_table.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, Q; std::cin >> N >> Q;

  std::vector<int> a(N);
  for(int i = 0; i < N; ++i) std::cin >> a[i];

  SparseTable<MinMonoid<int>> s(a);

  while(Q--){
    int l, r; std::cin >> l >> r;

    std::cout << s.get(l, r) << "\n";
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

