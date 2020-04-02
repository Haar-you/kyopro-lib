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


# :heavy_check_mark: test/aoj/3132/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#5df7098d8629f5dad4d475167fe60fb9">test/aoj/3132</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/3132/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 13:17:39+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3132">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3132</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/product_monoid.cpp.html">Mylib/AlgebraicStructure/Monoid/product_monoid.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/DataStructure/SegmentTree/Static/Normal/segment_tree.cpp.html">Mylib/DataStructure/SegmentTree/Static/Normal/segment_tree.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3132"
#define ERROR 1e-7

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "Mylib/AlgebraicStructure/Monoid/product_monoid.cpp"
#include "Mylib/DataStructure/SegmentTree/Static/Normal/segment_tree.cpp"


int main(){
  int N; std::cin >> N;
  
  auto seg = SegmentTree<ProductMonoid<double>>(N);
  
  std::vector<int> T(N), A(N);
  for(int i = 0; i < N; ++i) std::cin >> T[i] >> A[i];
  
  for(int i = 0; i < N; ++i){
    seg.update(i, 0.1 * (10 - A[i]));
  }

  int Q; std::cin >> Q;

  while(Q--){
    int L, R; std::cin >> L >> R;

    int l = std::lower_bound(T.begin(), T.end(), L) - T.begin();
    int r = std::lower_bound(T.begin(), T.end(), R) - T.begin();
    
    auto ans = seg.get(l, r) * 1e9;
    
    std::cout << std::fixed << std::setprecision(12) << ans << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/3132/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3132"
#define ERROR 1e-7

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#line 2 "Mylib/AlgebraicStructure/Monoid/product_monoid.cpp"

template <typename T>
struct ProductMonoid{
  using value_type = T;
  constexpr inline static value_type id(){return 1;}
  constexpr inline static value_type op(const value_type &a, const value_type &b){return a * b;}
};
#line 3 "Mylib/DataStructure/SegmentTree/Static/Normal/segment_tree.cpp"

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
#line 10 "test/aoj/3132/main.test.cpp"


int main(){
  int N; std::cin >> N;
  
  auto seg = SegmentTree<ProductMonoid<double>>(N);
  
  std::vector<int> T(N), A(N);
  for(int i = 0; i < N; ++i) std::cin >> T[i] >> A[i];
  
  for(int i = 0; i < N; ++i){
    seg.update(i, 0.1 * (10 - A[i]));
  }

  int Q; std::cin >> Q;

  while(Q--){
    int L, R; std::cin >> L >> R;

    int l = std::lower_bound(T.begin(), T.end(), L) - T.begin();
    int r = std::lower_bound(T.begin(), T.end(), R) - T.begin();
    
    auto ans = seg.get(l, r) * 1e9;
    
    std::cout << std::fixed << std::setprecision(12) << ans << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

