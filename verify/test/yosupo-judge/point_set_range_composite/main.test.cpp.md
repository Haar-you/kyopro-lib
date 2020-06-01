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


# :x: test/yosupo-judge/point_set_range_composite/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#4d6b83f34c17c15b5343ef482a3d7447">test/yosupo-judge/point_set_range_composite</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/point_set_range_composite/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00


* see: <a href="https://judge.yosupo.jp/problem/point_set_range_composite">https://judge.yosupo.jp/problem/point_set_range_composite</a>


## Depends on

* :x: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/affine.cpp.html">Mylib/AlgebraicStructure/Monoid/affine.cpp</a>
* :x: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/dual.cpp.html">Mylib/AlgebraicStructure/Monoid/dual.cpp</a>
* :x: <a href="../../../../library/Mylib/DataStructure/SegmentTree/segment_tree.cpp.html">Segment tree</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>
* :x: <a href="../../../../library/Mylib/Number/Mint/mint.cpp.html">Modint</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include <iostream>
#include <utility>
#include "Mylib/DataStructure/SegmentTree/segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/affine.cpp"
#include "Mylib/AlgebraicStructure/Monoid/dual.cpp"
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/IO/input_tuples.cpp"

using mint = ModInt<998244353>;
using M = DualMonoid<AffineMonoid<mint>>;

int main(){
  int N, Q; std::cin >> N >> Q;

  auto seg = SegmentTree<M>(N);

  for(int i = 0; i < N; ++i){
    int a, b; std::cin >> a >> b;
    seg.update(i, {a, b});
  }

  for(auto [t] : input_tuples<int>(Q)){
    if(t == 0){
      int p, c, d; std::cin >> p >> c >> d;
      seg.update(p, {c, d});
    }else{
      int l, r, x; std::cin >> l >> r >> x;
      auto [a, b] = seg.get(l, r);
      std::cout << a * x + b << std::endl;
    }
  }
  
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/point_set_range_composite/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include <iostream>
#include <utility>
#line 2 "Mylib/DataStructure/SegmentTree/segment_tree.cpp"
#include <vector>

/**
 * @title Segment tree
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
#line 3 "Mylib/AlgebraicStructure/Monoid/affine.cpp"

/**
 * @docs affine.md
 */
template <typename T>
struct AffineMonoid{
  using value_type = std::pair<T, T>;
  constexpr inline static value_type id(){return std::make_pair(1, 0);}
  constexpr inline static value_type op(const value_type &a, const value_type &b){return std::make_pair(a.first * b.first, a.first * b.second + a.second);}
};
#line 2 "Mylib/AlgebraicStructure/Monoid/dual.cpp"

/**
 * @docs dual.md
 */
template <typename Monoid>
struct DualMonoid{
  using value_type = typename Monoid::value_type;
  constexpr inline static value_type id(){return Monoid::id();}
  constexpr inline static value_type op(const value_type &a, const value_type &b){return Monoid::op(b, a);}
};
#line 4 "Mylib/Number/Mint/mint.cpp"

/**
 * @title Modint
 * @docs mint.md
 */
template <uint32_t M> class ModInt{
public:
  constexpr static uint32_t MOD = M;
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
    
    int64_t ret = 1, e = n % M;
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

  explicit operator int32_t() const noexcept {return val;}
  explicit operator int64_t() const noexcept {return val;}
};
#line 4 "Mylib/IO/input_tuples.cpp"
#include <tuple>
#line 6 "Mylib/IO/input_tuples.cpp"
#include <initializer_list>

/**
 * @docs input_tuples.md
 */
template <typename ... Args>
class InputTuples{
  template <typename T, size_t ... I>
  static void input_tuple_helper(T &val, std::index_sequence<I...>){
    (void)std::initializer_list<int>{(void(std::cin >> std::get<I>(val)), 0)...};
  }
  
  struct iter{
    using value_type = std::tuple<Args ...>;
    value_type value;
    bool get = false;
    int N;
    int c = 0;

    value_type operator*(){
      if(get) return value;
      else{
        input_tuple_helper(value, std::make_index_sequence<sizeof...(Args)>());
        return value;
      }
    }

    void operator++(){
      ++c;
      get = false;
    }

    bool operator!=(iter &) const {
      return c < N;
    }

    iter(int N): N(N){}
  };

  int N;

public:
  InputTuples(int N): N(N){}

  iter begin() const {return iter(N);}
  iter end() const {return iter(N);}
};

template <typename ... Args>
auto input_tuples(int N){
  return InputTuples<Args ...>(N);
}
#line 10 "test/yosupo-judge/point_set_range_composite/main.test.cpp"

using mint = ModInt<998244353>;
using M = DualMonoid<AffineMonoid<mint>>;

int main(){
  int N, Q; std::cin >> N >> Q;

  auto seg = SegmentTree<M>(N);

  for(int i = 0; i < N; ++i){
    int a, b; std::cin >> a >> b;
    seg.update(i, {a, b});
  }

  for(auto [t] : input_tuples<int>(Q)){
    if(t == 0){
      int p, c, d; std::cin >> p >> c >> d;
      seg.update(p, {c, d});
    }else{
      int l, r, x; std::cin >> l >> r >> x;
      auto [a, b] = seg.get(l, r);
      std::cout << a * x + b << std::endl;
    }
  }
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

