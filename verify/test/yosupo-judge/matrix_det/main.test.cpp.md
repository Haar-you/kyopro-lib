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
    - Last commit date: 2020-04-03 01:42:28+09:00


* see: <a href="https://judge.yosupo.jp/problem/matrix_det">https://judge.yosupo.jp/problem/matrix_det</a>


## Depends on

* :x: <a href="../../../../library/Mylib/LinearAlgebra/Square/determinant.cpp.html">行列式 (01)</a>
* :question: <a href="../../../../library/Mylib/LinearAlgebra/Square/square_matrix.cpp.html">正方行列</a>
* :question: <a href="../../../../library/Mylib/Number/Mint/mint.cpp.html">modint</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/LinearAlgebra/Square/square_matrix.cpp"
#include "Mylib/LinearAlgebra/Square/determinant.cpp"

using mint = ModInt<998244353>;
using Mat = SquareMatrix<mint>;

int main(){
  int N; scanf("%d", &N);

  Mat m(N);

  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      int x; scanf("%d", &x);
      m[i][j] = x;
    }
  }

  auto ans = determinant(m);

  printf("%lld\n", ans.val);

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/matrix_det/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#line 2 "Mylib/Number/Mint/mint.cpp"
#include <iostream>
#include <utility>

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
#line 2 "Mylib/LinearAlgebra/Square/square_matrix.cpp"
#include <vector>
#line 4 "Mylib/LinearAlgebra/Square/square_matrix.cpp"

/**
 * @title 正方行列
 */
template <typename T> struct SquareMatrix{
  using value_type = T;
  
  int N;
  std::vector<std::vector<T>> matrix;
  
  SquareMatrix(): N(0){}
  SquareMatrix(int N): N(N), matrix(N, std::vector<T>(N)){}
  SquareMatrix(int N, const T &val): N(N), matrix(N, std::vector<T>(N, val)){}
  SquareMatrix(const std::vector<std::vector<T>> &matrix): N(matrix.size()), matrix(matrix){}

  bool operator==(const SquareMatrix<T> &val) const {return matrix == val.matrix;}
  bool operator!=(const SquareMatrix<T> &val) const {return !(*this == val);}
  
  auto& operator=(const SquareMatrix &val){
    this->N = val.N;
    this->matrix = val.matrix;
    return *this;
  }
  
  auto& operator+=(const SquareMatrix &val){
    for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) matrix[i][j] = matrix[i][j] + val[i][j];
    return *this;
  }
  
  auto& operator-=(const SquareMatrix &val){
    for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) matrix[i][j] = matrix[i][j] - val[i][j];
    return *this;
  }

  auto& operator*=(const SquareMatrix &val){
    std::vector<std::vector<T>> temp(N, std::vector<T>(N));
    for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) for(int k = 0; k < N; ++k) temp[i][j] = temp[i][j] + matrix[i][k] * val[k][j];
    std::swap(matrix, temp);
    return *this;
  }

  inline const auto& operator[](size_t i) const {return matrix[i];}
  inline auto& operator[](size_t i){return matrix[i];}
  inline int size() const {return N;}
  
  static auto make_unit(int N){
    SquareMatrix ret(N);
    for(int i = 0; i < N; ++i) ret[i][i] = 1;
    return ret;
  }

  friend auto operator+(const SquareMatrix &a, const SquareMatrix &b){auto ret = a; ret += b; return ret;}
  friend auto operator-(const SquareMatrix &a, const SquareMatrix &b){auto ret = a; ret -= b; return ret;}
  friend auto operator*(const SquareMatrix &a, const SquareMatrix &b){auto ret = a; ret *= b; return ret;}
};
#line 2 "Mylib/LinearAlgebra/Square/determinant.cpp"

/**
 * @title 行列式
 */
template <typename M, typename T = typename M::value_type>
T determinant(M m){
  const int N = m.size();
  
  int s = 0;
  for(int i = 0; i < N; ++i){
    if(m[i][i] == 0){
      for(int j = i+1; j < N; ++j){
        if(m[j][i] != 0){
          m[i].swap(m[j]);
          (s += 1) %= 2;
          break;
        }
        if(j == N-1) return 0;
      }
    }
    
    for(int j = i+1; j < N; ++j){
      T t = m[j][i] / m[i][i];
      for(int k = 0; k < N; ++k) m[j][k] -= m[i][k] * t;
    }
  }
  
  T ret = s ? -1 : 1;
  for(int i = 0; i < N; ++i) ret *= m[i][i];
  return ret;
}
#line 6 "test/yosupo-judge/matrix_det/main.test.cpp"

using mint = ModInt<998244353>;
using Mat = SquareMatrix<mint>;

int main(){
  int N; scanf("%d", &N);

  Mat m(N);

  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      int x; scanf("%d", &x);
      m[i][j] = x;
    }
  }

  auto ans = determinant(m);

  printf("%lld\n", ans.val);

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

