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


# :heavy_check_mark: test/aoj/1308/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#91fd4443c2280843651bf249ceada703">test/aoj/1308</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/1308/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1308">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1308</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/LinearAlgebra/SimultaneousLinearEquations/binary_simultaneous_linear_equations.cpp.html">Simultaneous linear equations (Mod2)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1308"

#include <iostream>
#include <vector>
#include <bitset>
#include "Mylib/LinearAlgebra/SimultaneousLinearEquations/binary_simultaneous_linear_equations.cpp"
#include "Mylib/IO/input_vector.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int m,n,d;
  while(std::cin >> m >> n >> d, m){
    auto s = input_vector<int>(n, m);
    
    auto a = std::vector(n*m, std::bitset<25*25>());
    std::vector<bool> b(n*m);

    std::vector<std::vector<int>> p(n, std::vector<int>(m));
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < m; ++j){
        p[i][j] = j+i*m;
      }
    }

    for(int i = 0; i < n; ++i){
      for(int j = 0; j < m; ++j){
        b[p[i][j]] = s[i][j];
      }
    }

    for(int i = 0; i < n; ++i){
      for(int j = 0; j < m; ++j){
        a[p[i][j]][p[i][j]] = 1;

        for(int x = 0; x < n; ++x){
          for(int y = 0; y < m; ++y){
            if(abs(i-x) + abs(j-y) == d){
              a[p[x][y]][p[i][j]] = 1;
            }
          }
        }
      }
    }

    std::cout << (bool)(binary_simultaneous_linear_equations::solve(a,b)) << std::endl;
  }
  
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/1308/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1308"

#include <iostream>
#include <vector>
#include <bitset>
#line 3 "Mylib/LinearAlgebra/SimultaneousLinearEquations/binary_simultaneous_linear_equations.cpp"
#include <optional>
#include <utility>
#line 6 "Mylib/LinearAlgebra/SimultaneousLinearEquations/binary_simultaneous_linear_equations.cpp"

/**
 * @title Simultaneous linear equations (Mod2)
 * @docs binary_simultaneous_linear_equations.md
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
#line 8 "test/aoj/1308/main.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int m,n,d;
  while(std::cin >> m >> n >> d, m){
    auto s = input_vector<int>(n, m);
    
    auto a = std::vector(n*m, std::bitset<25*25>());
    std::vector<bool> b(n*m);

    std::vector<std::vector<int>> p(n, std::vector<int>(m));
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < m; ++j){
        p[i][j] = j+i*m;
      }
    }

    for(int i = 0; i < n; ++i){
      for(int j = 0; j < m; ++j){
        b[p[i][j]] = s[i][j];
      }
    }

    for(int i = 0; i < n; ++i){
      for(int j = 0; j < m; ++j){
        a[p[i][j]][p[i][j]] = 1;

        for(int x = 0; x < n; ++x){
          for(int y = 0; y < m; ++y){
            if(abs(i-x) + abs(j-y) == d){
              a[p[x][y]][p[i][j]] = 1;
            }
          }
        }
      }
    }

    std::cout << (bool)(binary_simultaneous_linear_equations::solve(a,b)) << std::endl;
  }
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

