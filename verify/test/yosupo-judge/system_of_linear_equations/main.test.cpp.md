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


# :heavy_check_mark: test/yosupo-judge/system_of_linear_equations/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a26257034660248e359cc2c36c605bb6">test/yosupo-judge/system_of_linear_equations</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/system_of_linear_equations/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 04:55:54+09:00


* see: <a href="https://judge.yosupo.jp/problem/system_of_linear_equations">https://judge.yosupo.jp/problem/system_of_linear_equations</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/LinearAlgebra/SimultaneousLinearEquations/simultaneous_linear_equations.cpp.html">Mylib/LinearAlgebra/SimultaneousLinearEquations/simultaneous_linear_equations.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Number/Mint/mint.cpp.html">Mylib/Number/Mint/mint.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations"

#include <vector>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/LinearAlgebra/SimultaneousLinearEquations/simultaneous_linear_equations.cpp"


using mint = ModInt<998244353>;

int main(){
  int N, M; scanf("%d%d", &N, &M);

  std::vector<std::vector<mint>> A(N, std::vector<mint>(M));

  for(int i = 0; i < N; ++i){
    for(int j = 0; j < M; ++j){
      int x; scanf("%d", &x);
      A[i][j] = x;
    }
  }

  std::vector<mint> B(N);
  for(int i = 0; i < N; ++i){
    int x;
    scanf("%d", &x);
    B[i] = x;
  }

  auto res = simulaneous_linear_equations::solve(A, B);
  
  if(not res){
    printf("-1\n");
  }else{
    printf("%d\n", (*res).dim);

    for(int i = 0; i < M; ++i){
      printf("%lld ", (*res).solution[i].val);
    }
    puts("");
    
    for(auto &b : (*res).basis){
      for(auto &x : b){
        printf("%lld ", x.val);
      }
      puts("");
    }
  }
  
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/system_of_linear_equations/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations"

#include <vector>
#line 2 "Mylib/Number/Mint/mint.cpp"
#include <iostream>
#include <utility>

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
#line 3 "Mylib/LinearAlgebra/SimultaneousLinearEquations/simultaneous_linear_equations.cpp"
#include <optional>
#line 5 "Mylib/LinearAlgebra/SimultaneousLinearEquations/simultaneous_linear_equations.cpp"

namespace simulaneous_linear_equations{
  template <typename T>
  struct Result{
    int rank, dim;
    std::vector<T> solution;
    std::vector<std::vector<T>> basis;
  };

  template <typename T>
  auto solve(std::vector<std::vector<T>> a, std::vector<T> b){
    std::optional<Result<T>> ret;
    const int n = a.size();
    const int m = a[0].size();
  
    int rank = 0;

    for(int j = 0; j < m; ++j){
      int pivot = -1;
    
      for(int i = rank; i < n; ++i){
        if(a[i][j] != 0){
          pivot = i;
          break;
        }
      }

      if(pivot == -1) continue;

      std::swap(a[pivot], a[rank]);
      std::swap(b[pivot], b[rank]);

      auto d = a[rank][j];
      for(int k = 0; k < m; ++k) a[rank][k] /= d;
      b[rank] /= d;

      for(int i = 0; i < n; ++i){
        if(i == rank or a[i][j] == 0) continue;
        auto d = a[i][j];
        for(int k = 0; k < m; ++k) a[i][k] -= a[rank][k] * d;
        b[i] -= b[rank] * d;
      }

      ++rank;
    }

    for(int i = rank; i < n; ++i){
      if(b[i] != 0){
        return ret;
      }
    }
    
    int dim = m - rank;

    std::vector<std::vector<T>> basis(dim, std::vector<T>(m));
    std::vector<int> index;

    {
      int k = 0;
      for(int i = 0; i < rank; ++i){
        for(int j = k; j < m; ++j){
          if(a[i][j] == 1){
            k = j+1;
            break;
          }

          index.push_back(j);
        }
      }

      for(int j = k; j < m; ++j) index.push_back(j);
    }
    
    for(int i = 0, k = 0; i < rank; ++i){
      for(int j = k; j < m; ++j){
        if(a[i][j] == 1){
          for(int l = 0; l < dim; ++l) basis[l][j] = -a[i][index[l]];
          k = j + 1;
          break;
        }
      }
    }

    for(int i = 0; i < dim; ++i) basis[i][index[i]] = 1;

    std::vector<T> solution(m);
    for(int i = 0; i < rank; ++i) solution[i] = b[i];

    ret = Result<T>({rank, dim, solution, basis});

    return ret;
  }
}
#line 6 "test/yosupo-judge/system_of_linear_equations/main.test.cpp"


using mint = ModInt<998244353>;

int main(){
  int N, M; scanf("%d%d", &N, &M);

  std::vector<std::vector<mint>> A(N, std::vector<mint>(M));

  for(int i = 0; i < N; ++i){
    for(int j = 0; j < M; ++j){
      int x; scanf("%d", &x);
      A[i][j] = x;
    }
  }

  std::vector<mint> B(N);
  for(int i = 0; i < N; ++i){
    int x;
    scanf("%d", &x);
    B[i] = x;
  }

  auto res = simulaneous_linear_equations::solve(A, B);
  
  if(not res){
    printf("-1\n");
  }else{
    printf("%d\n", (*res).dim);

    for(int i = 0; i < M; ++i){
      printf("%lld ", (*res).solution[i].val);
    }
    puts("");
    
    for(auto &b : (*res).basis){
      for(auto &x : b){
        printf("%lld ", x.val);
      }
      puts("");
    }
  }
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

