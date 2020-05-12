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


# :x: test/yukicoder/776/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a8c189a9cd3b51f204ab4e40b62c7dab">test/yukicoder/776</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yukicoder/776/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-12 08:15:26+09:00


* see: <a href="https://yukicoder.me/problems/no/776">https://yukicoder.me/problems/no/776</a>


## Depends on

* :x: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/max_partial_sum.cpp.html">Mylib/AlgebraicStructure/Monoid/max_partial_sum.cpp</a>
* :question: <a href="../../../../library/Mylib/DataStructure/SegmentTree/Static/Normal/segment_tree.cpp.html">SegmentTree</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/776"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

#include "Mylib/AlgebraicStructure/Monoid/max_partial_sum.cpp"
#include "Mylib/DataStructure/SegmentTree/Static/Normal/segment_tree.cpp"

using Mon = MaxPartialSumMonoid<int64_t>;

int main(){
  int N,Q; scanf("%d%d", &N, &Q);

  SegmentTree<Mon> seg(N);

  std::vector<int64_t> a(N);

  for(int i = 0; i < N; ++i){
    scanf("%lld", &a[i]);
    seg.update(i, Mon::MaxPartialSum::make(a[i]));
  }

  for(int i = 0; i < Q; ++i){
    std::string type; std::cin >> type;

    if(type == "set"){
      int i, x; scanf("%d%d", &i, &x);
      --i;
      seg.update(i, Mon::MaxPartialSum::make(x));
      a[i] = x;
    }else{
      int l1, l2, r1, r2; scanf("%d%d%d%d", &l1, &l2, &r1, &r2);
      --l1, --l2, --r1, --r2;

      r1 = std::max(l1,r1);
      l2 = std::min(l2,r2);
        
      int64_t ans = LLONG_MIN;
        
      auto f = [&](int L1, int L2, int R1, int R2){
                 auto ret =
                   seg.get(L1, L2+1).value_or(Mon::MaxPartialSum::make(0)).right_max +
                   seg.get(L2+1, R1).value_or(Mon::MaxPartialSum::make(0)).sum +
                   seg.get(R1, R2+1).value_or(Mon::MaxPartialSum::make(0)).left_max;

                 if(L2 == R1) ret -= a[L2];
                   
                 return ret;
               };

      if(l2 <= r1){
        ans = f(l1, l2, r1, r2);
      }else{
        ans = std::max(ans, f(l1, r1, r1, r2));
        ans = std::max(ans, f(l1, l2, l2, r2));
        ans = std::max(ans, seg.get(r1, l2+1)->partial_max);
      }

      printf("%lld\n", ans);
    }
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yukicoder/776/main.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/776"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

#line 2 "Mylib/AlgebraicStructure/Monoid/max_partial_sum.cpp"
#include <optional>
#line 4 "Mylib/AlgebraicStructure/Monoid/max_partial_sum.cpp"

/**
 * @docs max_partial_sum.md
 */
template <typename T>
struct MaxPartialSumMonoid{
  struct MaxPartialSum{
    T sum, left_max, right_max, partial_max;
    static auto make(T x){return MaxPartialSum({x, x, x, x});}
  };
  
  using value_type = std::optional<MaxPartialSum>;
  
  constexpr inline static value_type id(){
    return std::nullopt;
  }
  
  constexpr inline static value_type op(const value_type &a, const value_type &b){
    if(not a) return b;
    if(not b) return a;

    return {
            {
             a->sum + b->sum,
             std::max(a->left_max, a->sum + std::max(b->left_max, b->sum)),
             std::max(b->right_max, b->sum + std::max(a->right_max, a->sum)),
             std::max({a->partial_max, b->partial_max, a->right_max + b->left_max})
            }
    };
  }
};
#line 3 "Mylib/DataStructure/SegmentTree/Static/Normal/segment_tree.cpp"

/**
 * @title SegmentTree
 * @docs segment_tree.md
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
#line 11 "test/yukicoder/776/main.test.cpp"

using Mon = MaxPartialSumMonoid<int64_t>;

int main(){
  int N,Q; scanf("%d%d", &N, &Q);

  SegmentTree<Mon> seg(N);

  std::vector<int64_t> a(N);

  for(int i = 0; i < N; ++i){
    scanf("%lld", &a[i]);
    seg.update(i, Mon::MaxPartialSum::make(a[i]));
  }

  for(int i = 0; i < Q; ++i){
    std::string type; std::cin >> type;

    if(type == "set"){
      int i, x; scanf("%d%d", &i, &x);
      --i;
      seg.update(i, Mon::MaxPartialSum::make(x));
      a[i] = x;
    }else{
      int l1, l2, r1, r2; scanf("%d%d%d%d", &l1, &l2, &r1, &r2);
      --l1, --l2, --r1, --r2;

      r1 = std::max(l1,r1);
      l2 = std::min(l2,r2);
        
      int64_t ans = LLONG_MIN;
        
      auto f = [&](int L1, int L2, int R1, int R2){
                 auto ret =
                   seg.get(L1, L2+1).value_or(Mon::MaxPartialSum::make(0)).right_max +
                   seg.get(L2+1, R1).value_or(Mon::MaxPartialSum::make(0)).sum +
                   seg.get(R1, R2+1).value_or(Mon::MaxPartialSum::make(0)).left_max;

                 if(L2 == R1) ret -= a[L2];
                   
                 return ret;
               };

      if(l2 <= r1){
        ans = f(l1, l2, r1, r2);
      }else{
        ans = std::max(ans, f(l1, r1, r1, r2));
        ans = std::max(ans, f(l1, l2, l2, r2));
        ans = std::max(ans, seg.get(r1, l2+1)->partial_max);
      }

      printf("%lld\n", ans);
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

