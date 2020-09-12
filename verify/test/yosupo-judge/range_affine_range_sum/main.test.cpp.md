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
    - Last commit date: 2020-09-09 02:56:29+09:00


* see: <a href="https://judge.yosupo.jp/problem/range_affine_range_sum">https://judge.yosupo.jp/problem/range_affine_range_sum</a>


## Depends on

* :x: <a href="../../../../library/Mylib/AlgebraicStructure/MonoidAction/affine_sum.cpp.html">Range affine / Range sum</a>
* :question: <a href="../../../../library/Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp.html">Lazy segment tree</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>
* :x: <a href="../../../../library/Mylib/Number/Mint/mint.cpp.html">Modint</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include <iostream>
#include <vector>
#include "Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp"
#include "Mylib/AlgebraicStructure/MonoidAction/affine_sum.cpp"
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

using mint = hl::modint<998244353>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;

  auto seg = hl::lazy_segment_tree<hl::affine_sum<mint, mint>>(N);
  auto a = hl::input_vector<mint>(N);
  seg.init_with_vector(a);

  for(auto [t, l, r] : hl::input_tuples<int, int, int>(Q)){
    if(t == 0){
      int b, c; std::cin >> b >> c;
      seg.update(l, r, std::make_pair(b, c));
    }else{
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
#line 3 "Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp"

/**
 * @title Lazy segment tree
 * @docs lazy_segment_tree.md
 */
namespace haar_lib {
  template <typename Monoid>
  class lazy_segment_tree {
    using value_type_get = typename Monoid::value_type_get;
    using value_type_update = typename Monoid::value_type_update;
    const static Monoid M;

    const int depth, size, hsize;
    std::vector<value_type_get> data;
    std::vector<value_type_update> lazy;

    void propagate(int i){
      if(lazy[i] == M.id_update()) return;
      if(i < hsize){
        lazy[i << 1 | 0] = M.op_update(lazy[i], lazy[i << 1 | 0]);
        lazy[i << 1 | 1] = M.op_update(lazy[i], lazy[i << 1 | 1]);
      }
      int len = hsize >> (31 - __builtin_clz(i));
      data[i] = M.op(data[i], lazy[i], len);
      lazy[i] = M.id_update();
    }

    value_type_get update_aux(int i, int l, int r, int s, int t, const value_type_update &x){
      propagate(i);
      if(r <= s || t <= l) return data[i];
      else if(s <= l && r <= t){
        lazy[i] = M.op_update(x, lazy[i]);
        propagate(i);
        return data[i];
      }
      else return data[i] = M.op_get(update_aux(i << 1 | 0, l, (l + r) / 2, s, t, x), update_aux(i << 1 | 1, (l + r) / 2, r, s, t, x));
    }

    value_type_get get_aux(int i, int l, int r, int x, int y){
      propagate(i);
      if(r <= x || y <= l) return M.id_get();
      else if(x <= l && r <= y) return data[i];
      else return M.op_get(get_aux(i << 1 | 0, l, (l + r) / 2, x, y), get_aux(i << 1 | 1, (l + r) / 2, r, x, y));
    }

  public:
    lazy_segment_tree(){}
    lazy_segment_tree(int n):
      depth(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),
      size(1 << depth),
      hsize(size / 2),
      data(size, M.id_get()),
      lazy(size, M.id_update())
    {}

    void update(int l, int r, const value_type_update &x){update_aux(1, 0, hsize, l, r, x);}
    void update_at(int i, const value_type_update &x){update(i, i + 1, x);}
    value_type_get get(int l, int r){return get_aux(1, 0, hsize, l, r);}
    value_type_get operator[](int i){return get(i, i + 1);}

    template <typename T>
    void init(const T &val){
      init_with_vector(std::vector<T>(hsize, val));
    }

    template <typename T>
    void init_with_vector(const std::vector<T> &val){
      data.assign(size, M.id_get());
      lazy.assign(size, M.id_update());
      for(int i = 0; i < (int)val.size(); ++i) data[hsize + i] = val[i];
      for(int i = hsize - 1; i > 0; --i) data[i] = M.op_get(data[i << 1 | 0], data[i << 1 | 1]);
    }
  };
}
#line 2 "Mylib/AlgebraicStructure/MonoidAction/affine_sum.cpp"
#include <utility>

/**
 * @title Range affine / Range sum
 * @docs affine_sum.md
 */
namespace haar_lib {
  template <typename T, typename U>
  struct affine_sum {
    using value_type_get = T;
    using value_type_update = std::pair<U, U>;

    value_type_get id_get() const {return 0;}
    value_type_update id_update() const {return {1, 0};}

    value_type_get op_get(value_type_get a, value_type_get b) const {return a + b;}
    value_type_update op_update(value_type_update a, value_type_update b) const {return {a.first * b.first, a.first * b.second + a.second};}

    value_type_get op(value_type_get a, value_type_update b, int len) const {
      return b.first * a + b.second * len;
    }
  };
}
#line 4 "Mylib/Number/Mint/mint.cpp"

/**
 * @title Modint
 * @docs mint.md
 */
namespace haar_lib {
  template <int32_t M>
  class modint {
  public:
    constexpr static int32_t MOD = M;
    uint32_t val;

    constexpr modint(): val(0){}
    constexpr modint(int64_t n){
      if(n >= M) val = n % M;
      else if(n < 0) val = n % M + M;
      else val = n;
    }

    constexpr auto& operator=(const modint &a){val = a.val; return *this;}
    constexpr auto& operator+=(const modint &a){
      if(val + a.val >= M) val = (uint64_t)val + a.val - M;
      else val += a.val;
      return *this;
    }
    constexpr auto& operator-=(const modint &a){
      if(val < a.val) val += M;
      val -= a.val;
      return *this;
    }
    constexpr auto& operator*=(const modint &a){
      val = (uint64_t)val * a.val % M;
      return *this;
    }
    constexpr auto& operator/=(const modint &a){
      val = (uint64_t)val * a.inv().val % M;
      return *this;
    }

    constexpr auto operator+(const modint &a) const {return modint(*this) += a;}
    constexpr auto operator-(const modint &a) const {return modint(*this) -= a;}
    constexpr auto operator*(const modint &a) const {return modint(*this) *= a;}
    constexpr auto operator/(const modint &a) const {return modint(*this) /= a;}

    constexpr bool operator==(const modint &a) const {return val == a.val;}
    constexpr bool operator!=(const modint &a) const {return val != a.val;}

    constexpr auto& operator++(){*this += 1; return *this;}
    constexpr auto& operator--(){*this -= 1; return *this;}

    constexpr auto operator++(int){auto t = *this; *this += 1; return t;}
    constexpr auto operator--(int){auto t = *this; *this -= 1; return t;}

    constexpr static modint power(int64_t n, int64_t p){
      if(p < 0) return power(n, -p).inv();

      int64_t ret = 1, e = n % M;
      for(; p; (e *= e) %= M, p >>= 1) if(p & 1) (ret *= e) %= M;
      return ret;
    }

    constexpr static modint inv(int64_t a){
      int64_t b = M, u = 1, v = 0;

      while(b){
        int64_t t = a / b;
        a -= t * b; std::swap(a, b);
        u -= t * v; std::swap(u, v);
      }

      u %= M;
      if(u < 0) u += M;

      return u;
    }

    constexpr static auto frac(int64_t a, int64_t b){return modint(a) / modint(b);}

    constexpr auto power(int64_t p) const {return power(val, p);}
    constexpr auto inv() const {return inv(val);}

    friend constexpr auto operator-(const modint &a){return modint(M - a.val);}

    friend constexpr auto operator+(int64_t a, const modint &b){return modint(a) + b;}
    friend constexpr auto operator-(int64_t a, const modint &b){return modint(a) - b;}
    friend constexpr auto operator*(int64_t a, const modint &b){return modint(a) * b;}
    friend constexpr auto operator/(int64_t a, const modint &b){return modint(a) / b;}

    friend std::istream& operator>>(std::istream &s, modint<M> &a){s >> a.val; return s;}
    friend std::ostream& operator<<(std::ostream &s, const modint<M> &a){s << a.val; return s;}

    template <int N>
    static auto div(){
      static auto value = inv(N);
      return value;
    }

    explicit operator int32_t() const noexcept {return val;}
    explicit operator int64_t() const noexcept {return val;}
  };
}
#line 4 "Mylib/IO/input_vector.cpp"

/**
 * @docs input_vector.md
 */
namespace haar_lib {
  template <typename T>
  std::vector<T> input_vector(int N){
    std::vector<T> ret(N);
    for(int i = 0; i < N; ++i) std::cin >> ret[i];
    return ret;
  }

  template <typename T>
  std::vector<std::vector<T>> input_vector(int N, int M){
    std::vector<std::vector<T>> ret(N);
    for(int i = 0; i < N; ++i) ret[i] = input_vector<T>(M);
    return ret;
  }
}
#line 4 "Mylib/IO/input_tuples.cpp"
#include <tuple>
#line 6 "Mylib/IO/input_tuples.cpp"
#include <initializer_list>
#line 6 "Mylib/IO/input_tuple.cpp"

/**
 * @docs input_tuple.md
 */
namespace haar_lib {
  template <typename T, size_t ... I>
  static void input_tuple_helper(std::istream &s, T &val, std::index_sequence<I ...>){
    (void)std::initializer_list<int>{(void(s >> std::get<I>(val)), 0) ...};
  }

  template <typename T, typename U>
  std::istream& operator>>(std::istream &s, std::pair<T, U> &value){
    s >> value.first >> value.second;
    return s;
  }

  template <typename ... Args>
  std::istream& operator>>(std::istream &s, std::tuple<Args ...> &value){
    input_tuple_helper(s, value, std::make_index_sequence<sizeof ... (Args)>());
    return s;
  }
}
#line 8 "Mylib/IO/input_tuples.cpp"

/**
 * @docs input_tuples.md
 */
namespace haar_lib {
  template <typename ... Args>
  class InputTuples {
    struct iter {
      using value_type = std::tuple<Args ...>;
      value_type value;
      bool fetched = false;
      int N, c = 0;

      value_type operator*(){
        if(not fetched){
          std::cin >> value;
        }
        return value;
      }

      void operator++(){
        ++c;
        fetched = false;
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
}
#line 10 "test/yosupo-judge/range_affine_range_sum/main.test.cpp"

namespace hl = haar_lib;

using mint = hl::modint<998244353>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;

  auto seg = hl::lazy_segment_tree<hl::affine_sum<mint, mint>>(N);
  auto a = hl::input_vector<mint>(N);
  seg.init_with_vector(a);

  for(auto [t, l, r] : hl::input_tuples<int, int, int>(Q)){
    if(t == 0){
      int b, c; std::cin >> b >> c;
      seg.update(l, r, std::make_pair(b, c));
    }else{
      std::cout << seg.get(l, r) << "\n";
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

