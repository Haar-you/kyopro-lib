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


# :heavy_check_mark: 連立線形方程式 (浮動小数点数)

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#0f2e8b5b008805076abcf42bbba8c8c1">Mylib/LinearAlgebra/SimultaneousLinearEquations</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/LinearAlgebra/SimultaneousLinearEquations/float_simultaneous_linear_equations.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/2171/main.test.cpp.html">test/aoj/2171/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <optional>
#include <utility>

/**
 * @title 連立線形方程式 (浮動小数点数)
 * @docs float_simultaneous_linear_equations.md
 */
namespace float_simultaneous_linear_equations{
  template <typename T>
  struct Result{
    int rank, dim;
    std::vector<T> solution;
  };

  template <typename T>
  auto solve(std::vector<std::vector<T>> a, std::vector<T> b, T eps){
    std::optional<Result<T>> ret;

    const int n = a.size(), m = a[0].size();
    int rank = 0;
  
    for(int j = 0; j < m; ++j){
      int pivot = -1;
    
      double M = eps;
      for(int i = rank; i < n; ++i){
        if(std::abs(a[i][j]) > M){
          M = std::abs(a[i][j]);
          pivot = i;
        }
      }
    
      if(pivot == -1) continue;
    
      std::swap(a[pivot], a[rank]);
      std::swap(b[pivot], b[rank]);
    
      {
        double d = a[rank][j];
        for(int k = 0; k < m; ++k) a[rank][k] /= d;
        b[rank] /= d;
      }

      for(int i = 0; i < n; ++i){
        if(i == rank or std::abs(a[i][j]) <= eps) continue;
        double d = a[i][j];
        for(int k = 0; k < m; ++k){
          a[i][k] -= a[rank][k] * d;
        }
        b[i] -= b[rank] * d;
      }
    
      ++rank;
    }
  
    for(int i = rank; i < n; ++i){
      if(std::abs(b[i]) > eps){
        return ret;
      }
    }

    int dim = m - rank;

    std::vector<T> solution(m);
    for(int i = 0; i < rank; ++i) solution[i] = b[i];

    ret = Result<T>({rank, dim, solution});
    return ret;
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/LinearAlgebra/SimultaneousLinearEquations/float_simultaneous_linear_equations.cpp"
#include <vector>
#include <optional>
#include <utility>

/**
 * @title 連立線形方程式 (浮動小数点数)
 * @docs float_simultaneous_linear_equations.md
 */
namespace float_simultaneous_linear_equations{
  template <typename T>
  struct Result{
    int rank, dim;
    std::vector<T> solution;
  };

  template <typename T>
  auto solve(std::vector<std::vector<T>> a, std::vector<T> b, T eps){
    std::optional<Result<T>> ret;

    const int n = a.size(), m = a[0].size();
    int rank = 0;
  
    for(int j = 0; j < m; ++j){
      int pivot = -1;
    
      double M = eps;
      for(int i = rank; i < n; ++i){
        if(std::abs(a[i][j]) > M){
          M = std::abs(a[i][j]);
          pivot = i;
        }
      }
    
      if(pivot == -1) continue;
    
      std::swap(a[pivot], a[rank]);
      std::swap(b[pivot], b[rank]);
    
      {
        double d = a[rank][j];
        for(int k = 0; k < m; ++k) a[rank][k] /= d;
        b[rank] /= d;
      }

      for(int i = 0; i < n; ++i){
        if(i == rank or std::abs(a[i][j]) <= eps) continue;
        double d = a[i][j];
        for(int k = 0; k < m; ++k){
          a[i][k] -= a[rank][k] * d;
        }
        b[i] -= b[rank] * d;
      }
    
      ++rank;
    }
  
    for(int i = rank; i < n; ++i){
      if(std::abs(b[i]) > eps){
        return ret;
      }
    }

    int dim = m - rank;

    std::vector<T> solution(m);
    for(int i = 0; i < rank; ++i) solution[i] = b[i];

    ret = Result<T>({rank, dim, solution});
    return ret;
  }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

