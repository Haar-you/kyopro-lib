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


# :x: test/yosupo-judge/range_affine_range_sum/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#7561f7b6847dbe0c0f95d39dd0066b92">test/yosupo-judge/range_affine_range_sum</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/range_affine_range_sum/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 16:54:34+09:00


* see: <a href="https://judge.yosupo.jp/problem/range_affine_range_sum">https://judge.yosupo.jp/problem/range_affine_range_sum</a>


## Depends on

* :x: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/affine_monoid.cpp.html">Mylib/AlgebraicStructure/Monoid/affine_monoid.cpp</a>
* :question: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/sum_monoid.cpp.html">Mylib/AlgebraicStructure/Monoid/sum_monoid.cpp</a>
* :x: <a href="../../../../library/Mylib/AlgebraicStructure/MonoidAction/affine_sum.cpp.html">Mylib/AlgebraicStructure/MonoidAction/affine_sum.cpp</a>
* :question: <a href="../../../../library/Mylib/DataStructure/SegmentTree/Static/Lazy/lazy_segment_tree.cpp.html">遅延セグメント木</a>
* :question: <a href="../../../../library/Mylib/Number/Mint/mint.cpp.html">modint</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include <iostream>
#include <vector>
#include "Mylib/DataStructure/SegmentTree/Static/Lazy/lazy_segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/affine_monoid.cpp"
#include "Mylib/AlgebraicStructure/Monoid/sum_monoid.cpp"
#include "Mylib/AlgebraicStructure/MonoidAction/affine_sum.cpp"
#include "Mylib/Number/Mint/mint.cpp"

using mint = ModInt<998244353>;


int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;

  auto seg = LazySegmentTree<AffineSum<mint,mint>>(N);

  std::vector<mint> a(N);
  for(int i = 0; i < N; ++i) std::cin >> a[i];
  
  seg.init_with_vector(a);

  while(Q--){
    int t; std::cin >> t;

    if(t == 0){
      int l, r, b, c; std::cin >> l >> r >> b >> c;

      seg.update(l, r, std::make_pair(b, c));
    }else{
      int l, r; std::cin >> l >> r;

      std::cout << seg.get(l, r) << "\n";
    }
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/range_affine_range_sum/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include <iostream>
#include <vector>
#line 3 "Mylib/DataStructure/SegmentTree/Static/Lazy/lazy_segment_tree.cpp"

/**
 * @title 遅延セグメント木
 */
template <typename Monoid>
class LazySegmentTree{
  using value_type_get = typename Monoid::value_type_get;
  using value_type_update = typename Monoid::value_type_update;
  using monoid_get = typename Monoid::monoid_get;
  using monoid_update = typename Monoid::monoid_update;
  
  const int depth, size, hsize;
  std::vector<value_type_get> data;
  std::vector<value_type_update> lazy;

  inline void propagate(int i){
    if(lazy[i] == monoid_update::id()) return;
    if(i < hsize){
      lazy[i << 1 | 0] = monoid_update::op(lazy[i], lazy[i << 1 | 0]);
      lazy[i << 1 | 1] = monoid_update::op(lazy[i], lazy[i << 1 | 1]);
    }
    int len = hsize >> (31 - __builtin_clz(i));
    data[i] = Monoid::op(data[i], lazy[i], len);
    lazy[i] = monoid_update::id();
  }

  inline value_type_get update_aux(int i, int l, int r, int s, int t, const value_type_update &x){
    propagate(i);
    if(r <= s || t <= l) return data[i];
    else if(s <= l && r <= t){
      lazy[i] = monoid_update::op(x, lazy[i]);
      propagate(i);
      return data[i];
    }
    else return data[i] = monoid_get::op(update_aux(i << 1 | 0, l, (l+r) / 2, s, t, x), update_aux(i << 1 | 1, (l+r) / 2, r, s, t, x));
  }
  
  inline value_type_get get_aux(int i, int l, int r, int x, int y){
    propagate(i);
    if(r <= x || y <= l) return monoid_get::id();
    else if(x <= l && r <= y) return data[i];
    else return monoid_get::op(get_aux(i << 1 | 0, l, (l+r) / 2, x, y), get_aux(i << 1 | 1, (l+r) / 2, r, x, y));
  }

public:
  LazySegmentTree(){}
  LazySegmentTree(int n):
    depth(n > 1 ? 32-__builtin_clz(n-1) + 1 : 1),
    size(1 << depth),
    hsize(size / 2),
    data(size, monoid_get::id()),
    lazy(size, monoid_update::id())
  {}

  inline void update(int l, int r, const value_type_update &x){update_aux(1, 0, hsize, l, r, x);}
  inline void update_at(int i, const value_type_update &x){update(i, i+1, x);}
  inline value_type_get get(int l, int r){return get_aux(1, 0, hsize, l, r);}
  inline value_type_get at(int i){return get(i, i+1);}

  template <typename T>
  inline void init(const T &val){
    init_with_vector(std::vector<T>(hsize, val));
  }

  template <typename T>
  inline void init_with_vector(const std::vector<T> &val){
    data.assign(size, monoid_get::id());
    lazy.assign(size, monoid_update::id());
    for(int i = 0; i < (int)val.size(); ++i) data[hsize + i] = val[i];
    for(int i = hsize-1; i > 0; --i) data[i] = monoid_get::op(data[i << 1 | 0], data[i << 1 | 1]);
  }
};
#line 2 "Mylib/AlgebraicStructure/Monoid/affine_monoid.cpp"
#include <utility>

/**
 * @see https://atcoder.jp/contests/arc008/submissions/7996520
 * @see https://judge.yosupo.jp/submission/2048
 */

template <typename T>
struct AffineMonoid{
  using value_type = std::pair<T, T>;
  constexpr inline static value_type id(){return std::make_pair(1, 0);}
  constexpr inline static value_type op(const value_type &a, const value_type &b){return std::make_pair(a.first * b.first, a.first * b.second + a.second);}
};
#line 2 "Mylib/AlgebraicStructure/Monoid/sum_monoid.cpp"

template <typename T>
struct SumMonoid{
  using value_type = T;
  constexpr inline static value_type id(){return 0;}
  constexpr inline static value_type op(const value_type &a, const value_type &b){return a + b;}
};
#line 4 "Mylib/AlgebraicStructure/MonoidAction/affine_sum.cpp"

template <typename T, typename U>
struct AffineSum{
  using monoid_get = SumMonoid<T>;
  using monoid_update = AffineMonoid<U>;
  using value_type_get = typename monoid_get::value_type;
  using value_type_update = typename monoid_update::value_type;

  constexpr inline static value_type_get op(const value_type_get &a, const value_type_update &b, int len){
    return b.first * a + b.second * len;
  }
};
#line 4 "Mylib/Number/Mint/mint.cpp"

/**
 * @title modint
 */
template <uint32_t M> class ModInt{
public:
  uint64_t val;
  
  constexpr ModInt(): val(0){}
  constexpr ModInt(int64_t n){
    if(n >= M) val = n % M;
    else if(n < 0) val = n % M + M;
    else val = n;
  }
  
  inline constexpr auto operator+(const ModInt &a) const {return ModInt(val + a.val);}
  inline constexpr auto operator-(const ModInt &a) const {return ModInt(val - a.val);}
  inline constexpr auto operator*(const ModInt &a) const {return ModInt(val * a.val);}
  inline constexpr auto operator/(const ModInt &a) const {return ModInt(val * a.inv().val);}
  
  inline constexpr auto& operator=(const ModInt &a){val = a.val; return *this;}
  inline constexpr auto& operator+=(const ModInt &a){if((val += a.val) >= M) val -= M; return *this;}
  inline constexpr auto& operator-=(const ModInt &a){if(val < a.val) val += M; val -= a.val; return *this;}
  inline constexpr auto& operator*=(const ModInt &a){(val *= a.val) %= M; return *this;}
  inline constexpr auto& operator/=(const ModInt &a){(val *= a.inv().val) %= M; return *this;}
 
  inline constexpr bool operator==(const ModInt &a) const {return val == a.val;}
  inline constexpr bool operator!=(const ModInt &a) const {return val != a.val;}
 
  inline constexpr auto& operator++(){*this += 1; return *this;}
  inline constexpr auto& operator--(){*this -= 1; return *this;}
 
  inline constexpr auto operator++(int){auto t = *this; *this += 1; return t;}
  inline constexpr auto operator--(int){auto t = *this; *this -= 1; return t;}
 
  inline constexpr static ModInt power(int64_t n, int64_t p){
    if(p < 0) return power(n, -p).inv();
    
    int64_t ret = 1, e = n;
    for(; p; (e *= e) %= M, p >>= 1) if(p & 1) (ret *= e) %= M;
    return ret;
  }
 
  inline constexpr static ModInt inv(int64_t a){
    int64_t b = M, u = 1, v = 0;
    
    while(b){
      int64_t t = a / b;
      a -= t * b; std::swap(a,b);
      u -= t * v; std::swap(u,v);
    }
 
    u %= M;
    if(u < 0) u += M;
    
    return u;
  }
 
  inline constexpr static auto frac(int64_t a, int64_t b){return ModInt(a) / ModInt(b);}
  
  inline constexpr auto power(int64_t p) const {return power(val, p);}
  inline constexpr auto inv() const {return inv(val);}
 
  friend inline constexpr auto operator-(const ModInt &a){return ModInt(-a.val);}
 
  friend inline constexpr auto operator+(int64_t a, const ModInt &b){return ModInt(a) + b;}
  friend inline constexpr auto operator-(int64_t a, const ModInt &b){return ModInt(a) - b;}
  friend inline constexpr auto operator*(int64_t a, const ModInt &b){return ModInt(a) * b;}
  friend inline constexpr auto operator/(int64_t a, const ModInt &b){return ModInt(a) / b;}
 
  friend std::istream& operator>>(std::istream &s, ModInt<M> &a){s >> a.val; return s;}
  friend std::ostream& operator<<(std::ostream &s, const ModInt<M> &a){s << a.val; return s;}

  template <int N>
  inline static auto div(){
    static auto value = inv(N);
    return value;
  }
};
#line 10 "test/yosupo-judge/range_affine_range_sum/main.test.cpp"

using mint = ModInt<998244353>;


int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;

  auto seg = LazySegmentTree<AffineSum<mint,mint>>(N);

  std::vector<mint> a(N);
  for(int i = 0; i < N; ++i) std::cin >> a[i];
  
  seg.init_with_vector(a);

  while(Q--){
    int t; std::cin >> t;

    if(t == 0){
      int l, r, b, c; std::cin >> l >> r >> b >> c;

      seg.update(l, r, std::make_pair(b, c));
    }else{
      int l, r; std::cin >> l >> r;

      std::cout << seg.get(l, r) << "\n";
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

