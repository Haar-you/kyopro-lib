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


# :heavy_check_mark: test/yukicoder/194/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a69917d4d187b863fce67c7534f3be6a">test/yukicoder/194</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yukicoder/194/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-25 21:56:55+09:00


* see: <a href="https://yukicoder.me/problems/no/194">https://yukicoder.me/problems/no/194</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/LinearAlgebra/Square/inverse_matrix.cpp.html">逆行列</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/LinearAlgebra/Square/power.cpp.html">行列累乗</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/LinearAlgebra/Square/square_matrix.cpp.html">正方行列</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Number/Mint/mint.cpp.html">modint</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/194"


#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/LinearAlgebra/Square/square_matrix.cpp"
#include "Mylib/LinearAlgebra/Square/inverse_matrix.cpp"
#include "Mylib/LinearAlgebra/Square/power.cpp"

using mint = ModInt<1000000007>;
using M = SquareMatrix<mint>;

std::pair<mint,mint> solve1(int64_t N, int64_t K, std::vector<int> A){
  M m(N);

  for(int i = 0; i < N; ++i) m[0][i] = 1;
  for(int i = 0; i < N-1; ++i) m[i+1][i] = 1;

  std::reverse(A.begin(), A.end());

  mint f = 0;
  
  {
    auto m2 = power(m, K-N);
    for(int i = 0; i < N; ++i) f += m2[0][i] * A[i];
  }

  mint s = std::accumulate(A.begin(), A.end(), mint(0));
  
  {
    auto t = M::make_unit(N) - m;
    M c;
    inverse_matrix(t, c);

    auto temp = (M::make_unit(N) - power(m, K-N+1)) * c;
    temp -= M::make_unit(N);

    for(int i = 0; i < N; ++i) s += temp[0][i] * A[i];
  }

  return {f, s};
}

std::pair<mint,mint> solve2(int64_t N, int64_t K, std::vector<int> A){
  std::vector<mint> v(K);

  mint temp = 0;
  for(int i = 0; i < N; ++i){
    temp += A[i];
    v[i] = A[i];
  }

  for(int i = N; i < K; ++i){
    v[i] = temp;
    temp += v[i];
    temp -= v[i-N];
  }

  mint f = v.back();
  mint s = std::accumulate(v.begin(), v.end(), mint(0));
  
  return {f, s};
}




int main(){
  int64_t N, K; std::cin >> N >> K;

  std::vector<int> A(N);
  for(auto &x : A) std::cin >> x;

  auto [f, s] = K > 1000000 ? solve1(N, K, A) : solve2(N, K, A);
  std::cout << f << " " << s << "\n";

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yukicoder/194/main.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/194"


#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#line 3 "Mylib/Number/Mint/mint.cpp"
#include <utility>

/**
 * @title modint
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
#line 3 "Mylib/LinearAlgebra/Square/inverse_matrix.cpp"

/**
 * @title 逆行列
 */
template <typename M, typename T = typename M::value_type>
bool inverse_matrix(M m, M &ret){
  const int N = m.size();

  ret = M::make_unit(N);

  for(int i = 0; i < N; ++i){
    int p = i;
    for(int j = i; j < N; ++j){
      if(m[i][j] != 0){
        p = j;
        break;
      }
    }

    std::swap(m[i], m[p]);
    std::swap(ret[i], ret[p]);
    
    {
      T d = m[i][i];

      if(d == 0) return false;
    
      for(int j = 0; j < N; ++j){
        m[i][j] /= d;
        ret[i][j] /= d;
      }
    }
    
    for(int j = 0; j < N; ++j){
      if(i == j) continue;
      T d = m[j][i] / m[i][i];
      for(int k = 0; k < N; ++k){
        m[j][k] -= m[i][k] * d;
        ret[j][k] -= ret[i][k] * d;
      }
    }
  }

  return true;
}
#line 2 "Mylib/LinearAlgebra/Square/power.cpp"

/**
 * @title 行列累乗
 */
template <typename M, typename T = typename M::value_type>
M power(M a, uint64_t p){
  const int N = a.size();

  if(p == 0) return M::make_unit(N);
  if(p == 1) return a;

  M temp = power(a, p >> 1);
  auto ret = temp * temp;

  if(p & 1) ret *= a;  
  
  return ret;
}
#line 13 "test/yukicoder/194/main.test.cpp"

using mint = ModInt<1000000007>;
using M = SquareMatrix<mint>;

std::pair<mint,mint> solve1(int64_t N, int64_t K, std::vector<int> A){
  M m(N);

  for(int i = 0; i < N; ++i) m[0][i] = 1;
  for(int i = 0; i < N-1; ++i) m[i+1][i] = 1;

  std::reverse(A.begin(), A.end());

  mint f = 0;
  
  {
    auto m2 = power(m, K-N);
    for(int i = 0; i < N; ++i) f += m2[0][i] * A[i];
  }

  mint s = std::accumulate(A.begin(), A.end(), mint(0));
  
  {
    auto t = M::make_unit(N) - m;
    M c;
    inverse_matrix(t, c);

    auto temp = (M::make_unit(N) - power(m, K-N+1)) * c;
    temp -= M::make_unit(N);

    for(int i = 0; i < N; ++i) s += temp[0][i] * A[i];
  }

  return {f, s};
}

std::pair<mint,mint> solve2(int64_t N, int64_t K, std::vector<int> A){
  std::vector<mint> v(K);

  mint temp = 0;
  for(int i = 0; i < N; ++i){
    temp += A[i];
    v[i] = A[i];
  }

  for(int i = N; i < K; ++i){
    v[i] = temp;
    temp += v[i];
    temp -= v[i-N];
  }

  mint f = v.back();
  mint s = std::accumulate(v.begin(), v.end(), mint(0));
  
  return {f, s};
}




int main(){
  int64_t N, K; std::cin >> N >> K;

  std::vector<int> A(N);
  for(auto &x : A) std::cin >> x;

  auto [f, s] = K > 1000000 ? solve1(N, K, A) : solve2(N, K, A);
  std::cout << f << " " << s << "\n";

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
