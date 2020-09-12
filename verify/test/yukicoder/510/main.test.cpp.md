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


# :x: test/yukicoder/510/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#79c44d69f4476256a05dd1926185d029">test/yukicoder/510</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yukicoder/510/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-12 11:23:53+09:00


* see: <a href="https://yukicoder.me/problems/no/510">https://yukicoder.me/problems/no/510</a>


## Depends on

* :x: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/dual.cpp.html">Dual monoid</a>
* :x: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/product_matrix.cpp.html">Product matrix monoid</a>
* :question: <a href="../../../../library/Mylib/DataStructure/SegmentTree/segment_tree.cpp.html">Segment tree</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>
* :x: <a href="../../../../library/Mylib/LinearAlgebra/Square/square_matrix_const_size.cpp.html">Square matrix (Const size)</a>
* :x: <a href="../../../../library/Mylib/Number/Mint/mint.cpp.html">Modint</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/510"

#include <iostream>
#include <vector>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/LinearAlgebra/Square/square_matrix_const_size.cpp"
#include "Mylib/DataStructure/SegmentTree/segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/product_matrix.cpp"
#include "Mylib/AlgebraicStructure/Monoid/dual.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

using mint = hl::modint<1000000007>;
using Mat = hl::square_matrix_const<mint, 4>;
using Monoid = hl::dual_monoid<hl::product_matrix_monoid<Mat>>;

auto f(mint x, mint y){
  Mat ret = {
             {1, 0, x, 0},
             {0, y, 0, 1},
             {0, 2 * y, y * y, 1},
             {0, 0, 0, 1}
  };
  return ret;
}

int main(){
  int n, q; std::cin >> n >> q;

  hl::segment_tree<Monoid> seg(n);
  std::vector<mint> x(n), y(n);

  for(int i = 0; i < n; ++i){
    seg.update(i, f(x[i], y[i]));
  }

  for(auto [c, i] : hl::input_tuples<char, int>(q)){
    if(c == 'x'){
      int v; std::cin >> v;
      x[i] = v;

      seg.update(i, f(x[i], y[i]));
    }else if(c == 'y'){
      int v; std::cin >> v;
      y[i] = v;

      seg.update(i, f(x[i], y[i]));
    }else{
      auto m = seg.get(0, i);
      auto ans = m[0][0] + m[0][1] + m[0][2] + m[0][3];
      std::cout << ans << "\n";
    }
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yukicoder/510/main.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/510"

#include <iostream>
#include <vector>
#line 3 "Mylib/Number/Mint/mint.cpp"
#include <utility>

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
#line 2 "Mylib/LinearAlgebra/Square/square_matrix_const_size.cpp"
#include <array>
#include <initializer_list>
#line 5 "Mylib/LinearAlgebra/Square/square_matrix_const_size.cpp"

/**
 * @title Square matrix (Const size)
 * @docs square_matrix_const_size.md
 */
namespace haar_lib {
  template <typename T, int N>
  struct square_matrix_const {
    using value_type = T;

    std::array<std::array<T, N>, N> matrix;

    square_matrix_const(){
      for(size_t i = 0; i < N; ++i) for(size_t j = 0; j < N; ++j) matrix[i][j] = 0;
    }
    square_matrix_const(const T &val){
      for(size_t i = 0; i < N; ++i) matrix[i].fill(val);
    }
    square_matrix_const(std::initializer_list<std::initializer_list<T>> list){
      int i = 0;
      for(auto it1 = list.begin(); it1 != list.end(); ++it1, ++i){
        int j = 0;
        for(auto it2 = it1->begin(); it2 != it1->end(); ++it2, ++j){
          matrix[i][j] = *it2;
        }
      }
    }

    bool operator==(const square_matrix_const &val) const {return matrix == val.matrix;}
    bool operator!=(const square_matrix_const &val) const {return !(*this == val);}

    auto& operator=(const square_matrix_const &val){
      this->matrix = val.matrix;
      return *this;
    }

    auto& operator+=(const square_matrix_const &val){
      for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) matrix[i][j] = matrix[i][j] + val[i][j];
      return *this;
    }

    auto& operator-=(const square_matrix_const &val){
      for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) matrix[i][j] = matrix[i][j] - val[i][j];
      return *this;
    }

    auto& operator*=(const square_matrix_const &val){
      std::array<std::array<T, N>, N> temp = {};
      for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) for(int k = 0; k < N; ++k) temp[i][j] = temp[i][j] + matrix[i][k] * val[k][j];
      std::swap(matrix, temp);
      return *this;
    }

    const auto& operator[](size_t i) const {return matrix[i];}
    auto& operator[](size_t i){return matrix[i];}
    int size() const {return N;}

    static auto make_unit(){
      square_matrix_const ret;
      for(size_t i = 0; i < N; ++i) ret[i][i] = 1;
      return ret;
    }

    friend auto operator+(const square_matrix_const &a, const square_matrix_const &b){auto ret = a; ret += b; return ret;}
    friend auto operator-(const square_matrix_const &a, const square_matrix_const &b){auto ret = a; ret -= b; return ret;}
    friend auto operator*(const square_matrix_const &a, const square_matrix_const &b){auto ret = a; ret *= b; return ret;}
  };
}
#line 3 "Mylib/DataStructure/SegmentTree/segment_tree.cpp"
#include <algorithm>
#include <functional>

/**
 * @title Segment tree
 * @docs segment_tree.md
 */
namespace haar_lib {
  template <typename Monoid>
  class segment_tree {
    using value_type = typename Monoid::value_type;
    const static Monoid M;

    int depth, size, hsize;
    std::vector<value_type> data;

  public:
    segment_tree(){}
    segment_tree(int n):
      depth(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),
      size(1 << depth), hsize(size / 2),
      data(size, M())
    {}

    auto operator[](int i) const {return data[hsize + i];}

    auto get(int x, int y) const {
      value_type ret_left = M();
      value_type ret_right = M();

      int l = x + hsize, r = y + hsize;
      while(l < r){
        if(r & 1) ret_right = M(data[--r], ret_right);
        if(l & 1) ret_left = M(ret_left, data[l++]);
        l >>= 1, r >>= 1;
      }

      return M(ret_left, ret_right);
    }

    void update(int i, const value_type &x){
      i += hsize;
      data[i] = x;
      while(i > 1) i >>= 1, data[i] = M(data[i << 1 | 0], data[i << 1 | 1]);
    }

    template <typename T>
    void init_with_vector(const std::vector<T> &val){
      data.assign(size, M());
      for(int i = 0; i < (int)val.size(); ++i) data[hsize + i] = val[i];
      for(int i = hsize - 1; i >= 1; --i) data[i] = M(data[i << 1 | 0], data[i << 1 | 1]);
    }

    template <typename T>
    void init(const T &val){
      init_with_vector(std::vector<value_type>(hsize, val));
    }

  private:
    template <bool Lower, typename F>
    int bound(const int l, const int r, value_type x, F f) const {
      std::vector<int> pl, pr;
      int L = l + hsize;
      int R = r + hsize;
      while(L < R){
        if(R & 1) pr.push_back(--R);
        if(L & 1) pl.push_back(L++);
        L >>= 1, R >>= 1;
      }

      std::reverse(pr.begin(), pr.end());
      pl.insert(pl.end(), pr.begin(), pr.end());

      value_type a = M();

      for(int i : pl){
        auto b = M(a, data[i]);

        if((Lower and not f(b, x)) or (not Lower and f(x, b))){
          while(i < hsize){
            if(auto c = M(a, data[i << 1 | 0]); (Lower and not f(c, x)) or (not Lower and f(x, c))){
              i = i << 1 | 0;
            }else{
              a = c;
              i = i << 1 | 1;
            }
          }

          return i - hsize;
        }

        a = b;
      }

      return r;
    }

  public:
    template <typename F = std::less<value_type>>
    int lower_bound(int l, int r, value_type x, F f = F()) const {
      return bound<true>(l, r, x, f);
    }

    template <typename F = std::less<value_type>>
    int upper_bound(int l, int r, value_type x, F f = F()) const {
      return bound<false>(l, r, x, f);
    }
  };
}
#line 2 "Mylib/AlgebraicStructure/Monoid/product_matrix.cpp"

/**
 * @title Product matrix monoid
 * @docs product_matrix.md
 */
namespace haar_lib {
  template <typename T>
  struct product_matrix_monoid {
    using value_type = T;
    value_type operator()() const {return T::make_unit();}
    value_type operator()(const value_type &a, const value_type &b) const {return a * b;}
  };
}
#line 2 "Mylib/AlgebraicStructure/Monoid/dual.cpp"

/**
 * @title Dual monoid
 * @docs dual.md
 */
namespace haar_lib {
  template <typename Monoid>
  struct dual_monoid {
    using value_type = typename Monoid::value_type;
    const static Monoid M;
    value_type operator()() const {return M();}
    value_type operator()(const value_type &a, const value_type &b) const {return M(b, a);}
  };
}
#line 4 "Mylib/IO/input_tuples.cpp"
#include <tuple>
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
#line 11 "test/yukicoder/510/main.test.cpp"

namespace hl = haar_lib;

using mint = hl::modint<1000000007>;
using Mat = hl::square_matrix_const<mint, 4>;
using Monoid = hl::dual_monoid<hl::product_matrix_monoid<Mat>>;

auto f(mint x, mint y){
  Mat ret = {
             {1, 0, x, 0},
             {0, y, 0, 1},
             {0, 2 * y, y * y, 1},
             {0, 0, 0, 1}
  };
  return ret;
}

int main(){
  int n, q; std::cin >> n >> q;

  hl::segment_tree<Monoid> seg(n);
  std::vector<mint> x(n), y(n);

  for(int i = 0; i < n; ++i){
    seg.update(i, f(x[i], y[i]));
  }

  for(auto [c, i] : hl::input_tuples<char, int>(q)){
    if(c == 'x'){
      int v; std::cin >> v;
      x[i] = v;

      seg.update(i, f(x[i], y[i]));
    }else if(c == 'y'){
      int v; std::cin >> v;
      y[i] = v;

      seg.update(i, f(x[i], y[i]));
    }else{
      auto m = seg.get(0, i);
      auto ans = m[0][0] + m[0][1] + m[0][2] + m[0][3];
      std::cout << ans << "\n";
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

