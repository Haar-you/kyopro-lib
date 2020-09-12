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


# :x: test/yosupo-judge/matrix_det/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#f56272346ebd60cefe0da1df8f0209d6">test/yosupo-judge/matrix_det</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/matrix_det/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00


* see: <a href="https://judge.yosupo.jp/problem/matrix_det">https://judge.yosupo.jp/problem/matrix_det</a>


## Depends on

* :question: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>
* :x: <a href="../../../../library/Mylib/LinearAlgebra/Square/determinant.cpp.html">Determinant</a>
* :question: <a href="../../../../library/Mylib/LinearAlgebra/Square/square_matrix.cpp.html">Square matrix</a>
* :x: <a href="../../../../library/Mylib/Number/Mint/mint.cpp.html">Modint</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include <iostream>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/LinearAlgebra/Square/square_matrix.cpp"
#include "Mylib/LinearAlgebra/Square/determinant.cpp"
#include "Mylib/IO/input_vector.cpp"

namespace hl = haar_lib;

using mint = hl::modint<998244353>;

struct tag {};
using Mat = hl::square_matrix<mint, tag>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N; std::cin >> N;

  Mat::init(N);

  Mat m(hl::input_vector<mint>(N, N));

  std::cout << hl::determinant(m) << "\n";

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/matrix_det/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include <iostream>
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
#line 2 "Mylib/LinearAlgebra/Square/square_matrix.cpp"
#include <vector>
#line 4 "Mylib/LinearAlgebra/Square/square_matrix.cpp"

/**
 * @title Square matrix
 * @docs square_matrix.md
 */
namespace haar_lib {
  template <typename T, class Tag>
  struct square_matrix {
    using value_type = T;

    static int N;
    static void init(int n){N = n;}
    std::vector<std::vector<T>> matrix;

    square_matrix(): matrix(N, std::vector<T>(N)){}
    square_matrix(const T &val): matrix(N, std::vector<T>(N, val)){}
    square_matrix(const std::vector<std::vector<T>> &matrix): matrix(matrix){}

    bool operator==(const square_matrix &val) const {return matrix == val.matrix;}
    bool operator!=(const square_matrix &val) const {return !(*this == val);}

    auto& operator=(const square_matrix &val){
      this->matrix = val.matrix;
      return *this;
    }

    auto& operator+=(const square_matrix &val){
      for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) matrix[i][j] = matrix[i][j] + val[i][j];
      return *this;
    }

    auto& operator-=(const square_matrix &val){
      for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) matrix[i][j] = matrix[i][j] - val[i][j];
      return *this;
    }

    auto& operator*=(const square_matrix &val){
      std::vector<std::vector<T>> temp(N, std::vector<T>(N));
      for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) for(int k = 0; k < N; ++k) temp[i][j] = temp[i][j] + matrix[i][k] * val[k][j];
      std::swap(matrix, temp);
      return *this;
    }

    const auto& operator[](size_t i) const {return matrix[i];}
    auto& operator[](size_t i){return matrix[i];}
    int size() const {return N;}

    static auto make_unit(){
      square_matrix ret;
      for(int i = 0; i < N; ++i) ret[i][i] = 1;
      return ret;
    }

    friend auto operator+(const square_matrix &a, const square_matrix &b){auto ret = a; ret += b; return ret;}
    friend auto operator-(const square_matrix &a, const square_matrix &b){auto ret = a; ret -= b; return ret;}
    friend auto operator*(const square_matrix &a, const square_matrix &b){auto ret = a; ret *= b; return ret;}
  };

  template <typename T, class Tag> int square_matrix<T, Tag>::N;
}
#line 2 "Mylib/LinearAlgebra/Square/determinant.cpp"

/**
 * @title Determinant
 * @docs determinant.md
 */
namespace haar_lib {
  template <typename M, typename T = typename M::value_type>
  T determinant(M m){
    const int N = m.size();

    int s = 0;
    for(int i = 0; i < N; ++i){
      if(m[i][i] == 0){
        for(int j = i + 1; j < N; ++j){
          if(m[j][i] != 0){
            m[i].swap(m[j]);
            (s += 1) %= 2;
            break;
          }
          if(j == N - 1) return 0;
        }
      }

      for(int j = i + 1; j < N; ++j){
        T t = m[j][i] / m[i][i];
        for(int k = 0; k < N; ++k) m[j][k] -= m[i][k] * t;
      }
    }

    T ret = s ? -1 : 1;
    for(int i = 0; i < N; ++i) ret *= m[i][i];
    return ret;
  }
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
#line 8 "test/yosupo-judge/matrix_det/main.test.cpp"

namespace hl = haar_lib;

using mint = hl::modint<998244353>;

struct tag {};
using Mat = hl::square_matrix<mint, tag>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N; std::cin >> N;

  Mat::init(N);

  Mat m(hl::input_vector<mint>(N, N));

  std::cout << hl::determinant(m) << "\n";

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

