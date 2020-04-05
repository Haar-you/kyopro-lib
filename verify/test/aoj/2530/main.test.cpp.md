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


# :heavy_check_mark: test/aoj/2530/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#9c9a92db287cfe91b89f042067749877">test/aoj/2530</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/2530/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-05 15:40:57+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2530">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2530</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/LinearAlgebra/SimultaneousLinearEquations/binary_simultaneous_linear_equations.cpp.html">Mod2体上の連立線形方程式</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Number/Mod/mod_power.cpp.html">mod累乗</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2530"

#include <iostream>
#include <vector>
#include <bitset>
#include "Mylib/Number/Mod/mod_power.cpp"
#include "Mylib/LinearAlgebra/SimultaneousLinearEquations/binary_simultaneous_linear_equations.cpp"
 
constexpr int64_t mod = 1000000009;
 
using B = std::bitset<2500>;
 
int main(){
  int R, C; std::cin >> R >> C;
 
  std::vector<std::vector<int>> f(R, std::vector<int>(C));
  for(int i = 0; i < R; ++i){
    for(int j = 0; j < C; ++j){
      std::cin >> f[i][j];
    }
  }
 
  std::vector<std::vector<int>> index(R, std::vector<int>(C));
  {
    int c = 0;
    for(int i = 0; i < R; ++i){
      for(int j = 0; j < C; ++j){
        index[i][j] = c;
        ++c;
      }
    }
  }
  
  std::vector<B> a(R*C);
  std::vector<bool> b(R*C);
 
  for(int i = 0; i < R; ++i){
    for(int j = 0; j < C; ++j){
      b[index[i][j]] = f[i][j];
 
      for(int p = 0; p < R; ++p){
        for(int q = 0; q < C; ++q){
          if(abs(i-p) == abs(j-q) or i == p or j == q){
            a[index[p][q]][index[i][j]] = true;
          }
        }
      }
    }
  }
 
  auto res = binary_simultaneous_linear_equations::solve(a, b);
 
  int64_t ans = 0;
  if(res){
    ans = power(2, R*C-(*res).rank, mod);
  }
 
  std::cout << ans << std::endl;
 
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/2530/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2530"

#include <iostream>
#include <vector>
#include <bitset>
#line 2 "Mylib/Number/Mod/mod_power.cpp"

/**
 * @title mod累乗
 */
int64_t power(int64_t n, int64_t p, int64_t m){
  int64_t ret = 1;
  while(p > 0){
    if(p & 1) (ret *= n) %= m;
    (n *= n) %= m;
    p >>= 1;
  }
  return ret;
}
#line 3 "Mylib/LinearAlgebra/SimultaneousLinearEquations/binary_simultaneous_linear_equations.cpp"
#include <optional>
#include <utility>
#line 6 "Mylib/LinearAlgebra/SimultaneousLinearEquations/binary_simultaneous_linear_equations.cpp"

/**
 * @title Mod2体上の連立線形方程式
 * @see http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1308
 */
namespace binary_simultaneous_linear_equations{
  template <size_t N>
  struct Result{
    int rank, dim;
    std::vector<bool> solution;
  };

  template <size_t N>
  auto solve(std::vector<std::bitset<N>> a, std::vector<bool> b){
    std::optional<Result<N>> ret;
  
    const int n = a.size(), m = N;
    int rank = 0;
    
    for(int j = 0; j < m; ++j){
      int pivot = -1;
      for(int i = rank; i < n; ++i){
        if(a[i][j]){
          pivot = i;
          break;
        }
      }

      if(pivot == -1) continue;
      std::swap(a[pivot], a[rank]);
      swap(b[pivot], b[rank]);
    
      for(int i = 0; i < n; ++i){
        if(i != rank and a[i][j]){
          a[i] ^= a[rank];
          b[i] = b[i] ^ b[rank];
        }
      }
    
      ++rank;
    }
  
    for(int i = rank; i < n; ++i){
      if(b[i]){
        return ret;
      }
    }
  
    int dim = m - rank;

    std::vector<bool> solution(m);
    for(int i = 0; i < rank; ++i) solution[i] = b[i];

    ret = Result<N>({rank, dim, solution});
  
    return ret;
  }
}
#line 8 "test/aoj/2530/main.test.cpp"
 
constexpr int64_t mod = 1000000009;
 
using B = std::bitset<2500>;
 
int main(){
  int R, C; std::cin >> R >> C;
 
  std::vector<std::vector<int>> f(R, std::vector<int>(C));
  for(int i = 0; i < R; ++i){
    for(int j = 0; j < C; ++j){
      std::cin >> f[i][j];
    }
  }
 
  std::vector<std::vector<int>> index(R, std::vector<int>(C));
  {
    int c = 0;
    for(int i = 0; i < R; ++i){
      for(int j = 0; j < C; ++j){
        index[i][j] = c;
        ++c;
      }
    }
  }
  
  std::vector<B> a(R*C);
  std::vector<bool> b(R*C);
 
  for(int i = 0; i < R; ++i){
    for(int j = 0; j < C; ++j){
      b[index[i][j]] = f[i][j];
 
      for(int p = 0; p < R; ++p){
        for(int q = 0; q < C; ++q){
          if(abs(i-p) == abs(j-q) or i == p or j == q){
            a[index[p][q]][index[i][j]] = true;
          }
        }
      }
    }
  }
 
  auto res = binary_simultaneous_linear_equations::solve(a, b);
 
  int64_t ans = 0;
  if(res){
    ans = power(2, R*C-(*res).rank, mod);
  }
 
  std::cout << ans << std::endl;
 
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

