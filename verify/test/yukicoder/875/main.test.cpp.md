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


# :heavy_check_mark: test/yukicoder/875/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#85bd684f532fe6c6e7e3dd42beff3eb5">test/yukicoder/875</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yukicoder/875/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-06 20:40:01+09:00


* see: <a href="https://yukicoder.me/problems/no/875">https://yukicoder.me/problems/no/875</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/min_monoid.cpp.html">Mylib/AlgebraicStructure/Monoid/min_monoid.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/with_index.cpp.html">Mylib/AlgebraicStructure/Monoid/with_index.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/DataStructure/SegmentTree/Static/Normal/segment_tree.cpp.html">セグメント木</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/875"

#include <iostream>
#include <vector>
#include <utility>

#include "Mylib/DataStructure/SegmentTree/Static/Normal/segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/min_monoid.cpp"
#include "Mylib/AlgebraicStructure/Monoid/with_index.cpp"

using Mon = WithIndex<MinMonoid<int>, MinMonoid<int>>;

int main(){
  int N, Q; scanf("%d %d", &N, &Q);

  SegmentTree<Mon> seg(N);

  std::vector<Mon::value_type> a(N);
  for(int i = 0; i < N; ++i){
    int x; scanf("%d", &x);
    a[i] = std::make_pair(x, i);
  }

  seg.init_with_vector(a);

  for(int i = 0; i < Q; ++i){
    int type; scanf("%d", &type);
    
    switch(type){
    case 1: {
      int l, r; scanf("%d %d", &l, &r);
      --l, --r;

      auto x = seg[l].first;
      auto y = seg[r].first;

      seg.update(l, std::make_pair(y, l));
      seg.update(r, std::make_pair(x, r));

      break;
    }
    case 2: {
      int l, r; scanf("%d %d", &l, &r);
      --l, --r;

      printf("%d\n", seg.get(l, r+1).second + 1);

      break;
    }
    }
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yukicoder/875/main.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/875"

#include <iostream>
#include <vector>
#include <utility>

#line 3 "Mylib/DataStructure/SegmentTree/Static/Normal/segment_tree.cpp"

/**
 * @title セグメント木
 */
template <typename Monoid>
class SegmentTree{
  using value_type = typename Monoid::value_type;
  
  int depth, size, hsize;
  std::vector<value_type> data;

public:
  SegmentTree(){}
  SegmentTree(int n):
    depth(n > 1 ? 32-__builtin_clz(n-1) + 1 : 1),
    size(1 << depth), hsize(size / 2),
    data(size, Monoid::id())
  {}

  inline auto operator[](int i) const {return at(i);}
  inline auto at(int i) const {return data[hsize + i];}
  
  inline auto get(int x, int y) const { // [x,y)
    value_type ret_left = Monoid::id();
    value_type ret_right = Monoid::id();
    
    int l = x + hsize, r = y + hsize;
    while(l < r){
      if(r & 1) ret_right = Monoid::op(data[--r], ret_right);
      if(l & 1) ret_left = Monoid::op(ret_left, data[l++]);
      l >>= 1, r >>= 1;
    }
    
    return Monoid::op(ret_left, ret_right);
  }

  inline void update(int i, const value_type &x){
    i += hsize;
    data[i] = x;
    while(i > 1) i >>= 1, data[i] = Monoid::op(data[i << 1 | 0], data[i << 1 | 1]);
  }

  template <typename T>
  inline void init_with_vector(const std::vector<T> &val){
    data.assign(size, Monoid::id());
    for(int i = 0; i < (int)val.size(); ++i) data[hsize + i] = val[i];
    for(int i = hsize-1; i >= 1; --i) data[i] = Monoid::op(data[i << 1 | 0], data[i << 1 | 1]);
  }

  template <typename T>
  inline void init(const T &val){
    init_with_vector(std::vector<value_type>(hsize, val));
  }  
};
#line 2 "Mylib/AlgebraicStructure/Monoid/min_monoid.cpp"
#include <algorithm>

template <typename T>
struct MinMonoid{
  using value_type = T;
  constexpr inline static value_type id(){return std::numeric_limits<T>::max();}
  constexpr inline static value_type op(const value_type &a, const value_type &b){return std::min(a, b);}
};
#line 3 "Mylib/AlgebraicStructure/Monoid/with_index.cpp"

template <typename Monoid, typename Index>
struct WithIndex{
  using value_type = std::pair<typename Monoid::value_type, typename Index::value_type>;

  constexpr inline static value_type id(){
    return {Monoid::id(), Index::id()};
  }

  constexpr inline static value_type op(const value_type &a, const value_type &b){
    if(a.first == b.first) return {a.first, Index::op(a.second, b.second)};
    if(Monoid::op(a.first, b.first) == a.first) return a;
    else return b;
  }
};
#line 10 "test/yukicoder/875/main.test.cpp"

using Mon = WithIndex<MinMonoid<int>, MinMonoid<int>>;

int main(){
  int N, Q; scanf("%d %d", &N, &Q);

  SegmentTree<Mon> seg(N);

  std::vector<Mon::value_type> a(N);
  for(int i = 0; i < N; ++i){
    int x; scanf("%d", &x);
    a[i] = std::make_pair(x, i);
  }

  seg.init_with_vector(a);

  for(int i = 0; i < Q; ++i){
    int type; scanf("%d", &type);
    
    switch(type){
    case 1: {
      int l, r; scanf("%d %d", &l, &r);
      --l, --r;

      auto x = seg[l].first;
      auto y = seg[r].first;

      seg.update(l, std::make_pair(y, l));
      seg.update(r, std::make_pair(x, r));

      break;
    }
    case 2: {
      int l, r; scanf("%d %d", &l, &r);
      --l, --r;

      printf("%d\n", seg.get(l, r+1).second + 1);

      break;
    }
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

