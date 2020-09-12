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


# :heavy_check_mark: Simultaneous linear equations (Mod2)

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#0f2e8b5b008805076abcf42bbba8c8c1">Mylib/LinearAlgebra/SimultaneousLinearEquations</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/LinearAlgebra/SimultaneousLinearEquations/binary_simultaneous_linear_equations.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/1308/main.test.cpp.html">test/aoj/1308/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/2530/main.test.cpp.html">test/aoj/2530/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <optional>
#include <utility>
#include <bitset>

/**
 * @title Simultaneous linear equations (Mod2)
 * @docs binary_simultaneous_linear_equations.md
 */
namespace haar_lib {
  namespace binary_simultaneous_linear_equations_impl {
    template <size_t N>
    struct result {
      int rank, dim;
      std::vector<bool> solution;
    };
  }

  template <size_t N>
  auto binary_simultaneous_linear_equations(std::vector<std::bitset<N>> a, std::vector<bool> b){
    using result = binary_simultaneous_linear_equations_impl::result<N>;
    std::optional<result> ret;

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

    const int dim = m - rank;

    std::vector<bool> solution(m);
    for(int i = 0; i < rank; ++i) solution[i] = b[i];

    ret = result({rank, dim, solution});
    return ret;
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/LinearAlgebra/SimultaneousLinearEquations/binary_simultaneous_linear_equations.cpp"
#include <vector>
#include <optional>
#include <utility>
#include <bitset>

/**
 * @title Simultaneous linear equations (Mod2)
 * @docs binary_simultaneous_linear_equations.md
 */
namespace haar_lib {
  namespace binary_simultaneous_linear_equations_impl {
    template <size_t N>
    struct result {
      int rank, dim;
      std::vector<bool> solution;
    };
  }

  template <size_t N>
  auto binary_simultaneous_linear_equations(std::vector<std::bitset<N>> a, std::vector<bool> b){
    using result = binary_simultaneous_linear_equations_impl::result<N>;
    std::optional<result> ret;

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

    const int dim = m - rank;

    std::vector<bool> solution(m);
    for(int i = 0; i < rank; ++i) solution[i] = b[i];

    ret = result({rank, dim, solution});
    return ret;
  }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

