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


# :heavy_check_mark: test/aoj/1327/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#0bdfbad106799ccca05cbd57bfdddfd4">test/aoj/1327</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/1327/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1327">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1327</a>


## Depends on

* :question: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/join.cpp.html">Mylib/IO/join.cpp</a>
* :question: <a href="../../../../library/Mylib/LinearAlgebra/Square/power.cpp.html">Power of a matrix</a>
* :question: <a href="../../../../library/Mylib/LinearAlgebra/Square/square_matrix.cpp.html">Square matrix</a>
* :question: <a href="../../../../library/Mylib/Number/Mint/runtime_mint.cpp.html">Modint (Runtime mod)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1327"
     
#include <iostream>
#include <vector>
#include "Mylib/Number/Mint/runtime_mint.cpp"
#include "Mylib/LinearAlgebra/Square/square_matrix.cpp"
#include "Mylib/LinearAlgebra/Square/power.cpp"
#include "Mylib/IO/join.cpp"
#include "Mylib/IO/input_vector.cpp"

using mint = RuntimeModInt;

struct tag{};
using M = SquareMatrix<mint, tag>;
     
int main(){
  int n, m, a, b, c, t;
  while(std::cin >> n >> m >> a >> b >> c >> t, n){
    mint::M = m;
    M::N = n;

    auto s = input_vector<mint>(n);
     
    M mat;
     
    for(int i = 0; i < n; ++i){
      if(i-1 >= 0) mat[i][i-1] = a;
      mat[i][i] = b;
      if(i+1 < n) mat[i][i+1] = c;
    }
     
    mat = power(mat, t);
     
    std::vector<mint> ans(n);
     
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
        ans[i] += mat[i][j] * s[j];
      }
    }

    std::cout << join(ans.begin(), ans.end()) << "\n";
  }
     
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/1327/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1327"
     
#include <iostream>
#include <vector>
#line 3 "Mylib/Number/Mint/runtime_mint.cpp"
#include <utility>

/**
 * @title Modint (Runtime mod)
 * @docs runtime_mint.md
 */
class RuntimeModInt{
public:
  static uint32_t M;
  
  uint64_t val;
  RuntimeModInt(): val(0){}
  RuntimeModInt(int64_t n){
    if(n >= M) val = n % M;
    else if(n < 0) val = n % M + M;
    else val = n;
  }
  
  const auto operator+(const RuntimeModInt &a) const {return RuntimeModInt(val + a.val);}
  const auto operator-(const RuntimeModInt &a) const {return RuntimeModInt(val - a.val);}
  const auto operator*(const RuntimeModInt &a) const {return RuntimeModInt(val * a.val);}
  const auto operator/(const RuntimeModInt &a) const {return RuntimeModInt(val * a.inv().val);}
  
  const auto& operator=(const RuntimeModInt &a){val = a.val; return *this;}
  const auto& operator+=(const RuntimeModInt &a){if((val += a.val) >= M) val -= M; return *this;}
  const auto& operator-=(const RuntimeModInt &a){if(val < a.val) val += M; val -= a.val; return *this;}
  const auto& operator*=(const RuntimeModInt &a){(val *= a.val) %= M; return *this;}
  const auto& operator/=(const RuntimeModInt &a){(val *= a.inv().val) %= M; return *this;}

  const bool operator==(const RuntimeModInt &a) const {return val == a.val;}
  const bool operator!=(const RuntimeModInt &a) const {return val != a.val;}

  const static auto power(int64_t n, int64_t p){
    RuntimeModInt ret = 1, e = n;
    for(; p; e *= e, p >>= 1) if(p & 1) ret *= e;
    return ret;
  }

  const auto power(int64_t p) const {
    RuntimeModInt ret = 1, e = val;
    for(; p; e *= e, p >>= 1) if(p & 1) ret *= e;
    return ret;
  }
  
  const RuntimeModInt inv() const {
    int64_t a = val, b = M, u = 1, v = 0;

    while(b){
      int64_t t = a/b;
      a -= t*b; std::swap(a,b);
      u -= t*v; std::swap(u,v);
    }
    u %= M;
    if(u < 0) u += M;
    
    return u;
  }
};

auto operator-(const RuntimeModInt &a){return RuntimeModInt(-a.val);}

auto operator+(int64_t a, const RuntimeModInt &b){return RuntimeModInt(a) + b;}
auto operator-(int64_t a, const RuntimeModInt &b){return RuntimeModInt(a) - b;}
auto operator*(int64_t a, const RuntimeModInt &b){return RuntimeModInt(a) * b;}
auto operator/(int64_t a, const RuntimeModInt &b){return RuntimeModInt(a) / b;}

uint32_t RuntimeModInt::M;

std::istream& operator>>(std::istream &is, RuntimeModInt &a){is >> a.val; return is;}
std::ostream& operator<<(std::ostream &os, const RuntimeModInt &a){os << a.val; return os;}
#line 4 "Mylib/LinearAlgebra/Square/square_matrix.cpp"

/**
 * @title Square matrix
 * @docs square_matrix.md
 */
template <typename T, class Tag> struct SquareMatrix{
  using value_type = T;
  
  static int N;
  std::vector<std::vector<T>> matrix;
  
  SquareMatrix(): matrix(N, std::vector<T>(N)){}
  SquareMatrix(const T &val): matrix(N, std::vector<T>(N, val)){}
  SquareMatrix(const std::vector<std::vector<T>> &matrix): matrix(matrix){}

  bool operator==(const SquareMatrix &val) const {return matrix == val.matrix;}
  bool operator!=(const SquareMatrix &val) const {return !(*this == val);}
  
  auto& operator=(const SquareMatrix &val){
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
  
  static auto make_unit(){
    SquareMatrix ret;
    for(int i = 0; i < N; ++i) ret[i][i] = 1;
    return ret;
  }

  friend auto operator+(const SquareMatrix &a, const SquareMatrix &b){auto ret = a; ret += b; return ret;}
  friend auto operator-(const SquareMatrix &a, const SquareMatrix &b){auto ret = a; ret -= b; return ret;}
  friend auto operator*(const SquareMatrix &a, const SquareMatrix &b){auto ret = a; ret *= b; return ret;}
};

template <typename T, class Tag> int SquareMatrix<T,Tag>::N;
#line 2 "Mylib/LinearAlgebra/Square/power.cpp"

/**
 * @title Power of a matrix
 * @docs power.md
 */
template <typename M, typename T = typename M::value_type>
M power(M a, uint64_t p){
  if(p == 0) return M::make_unit();
  if(p == 1) return a;

  M temp = power(a, p >> 1);
  auto ret = temp * temp;

  if(p & 1) ret *= a;  
  
  return ret;
}
#line 3 "Mylib/IO/join.cpp"
#include <sstream>
#include <string>

/**
 * @docs join.md
 */
template <typename ITER>
std::string join(ITER first, ITER last, std::string delim = " "){
  std::stringstream s;

  for(auto it = first; it != last; ++it){
    if(it != first) s << delim;
    s << *it;
  }

  return s.str();
}
#line 4 "Mylib/IO/input_vector.cpp"

/**
 * @docs input_vector.md
 */
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
#line 10 "test/aoj/1327/main.test.cpp"

using mint = RuntimeModInt;

struct tag{};
using M = SquareMatrix<mint, tag>;
     
int main(){
  int n, m, a, b, c, t;
  while(std::cin >> n >> m >> a >> b >> c >> t, n){
    mint::M = m;
    M::N = n;

    auto s = input_vector<mint>(n);
     
    M mat;
     
    for(int i = 0; i < n; ++i){
      if(i-1 >= 0) mat[i][i-1] = a;
      mat[i][i] = b;
      if(i+1 < n) mat[i][i+1] = c;
    }
     
    mat = power(mat, t);
     
    std::vector<mint> ans(n);
     
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
        ans[i] += mat[i][j] * s[j];
      }
    }

    std::cout << join(ans.begin(), ans.end()) << "\n";
  }
     
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

