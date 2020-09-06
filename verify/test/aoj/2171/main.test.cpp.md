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


# :x: test/aoj/2171/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#4195ec8e967880acfa32ac4f42872403">test/aoj/2171</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/2171/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 09:10:27+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2171">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2171</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Graph/ShortestPath/warshall_floyd_for_matrix_graph.cpp.html">Warshall-Floyd algorithm (For adjacency matrix graph)</a>
* :x: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>
* :x: <a href="../../../../library/Mylib/LinearAlgebra/SimultaneousLinearEquations/float_simultaneous_linear_equations.cpp.html">Simultaneous linear equations (Floating point number)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2171"
#define ERROR 1e-8

#include <iostream>
#include <vector>
#include <iomanip>
#include "Mylib/Graph/ShortestPath/warshall_floyd_for_matrix_graph.cpp"
#include "Mylib/LinearAlgebra/SimultaneousLinearEquations/float_simultaneous_linear_equations.cpp"
#include "Mylib/IO/input_vector.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n, s, t;
  while(std::cin >> n >> s >> t, n){
    --s, --t;

    auto q = input_vector<int>(n);
    auto g = input_vector<int>(n, n);

    auto dist = warshall_floyd_for_matrix<int, 0>(g);

    if(not dist[s][t]){
      std::cout << "impossible" << std::endl;
      continue;
    }

    std::vector<std::vector<double>> a(n, std::vector<double>(n));
    std::vector<double> b(n);

    for(int i = 0; i < n; ++i){
      if(i == t){
        a[i][i] = 1;
        b[i] = 0;
        continue;
      }

      if(q[i]){
        int d = *dist[i][t];

        int k = 0;
        for(int j = 0; j < n; ++j){
          if(g[i][j] > 0 and g[i][j] + *dist[j][t] == d){
            ++k;
          }
        }

        for(int j = 0; j < n; ++j){
          if(g[i][j] > 0 and g[i][j] + *dist[j][t] == d){
            a[i][j] = -1;
            b[i] += g[i][j];
          }
        }

        a[i][i] += k;
      }else{
        int k = 0;
        for(int j = 0; j < n; ++j){
          if(g[i][j] > 0){
            ++k;
          }
        }

        for(int j = 0; j < n; ++j){
          if(g[i][j] > 0){
            a[i][j] = -1;
            b[i] += g[i][j];
          }
        }

        a[i][i] += k;
      }
    }

    auto res = float_simultaneous_linear_equations(a, b, ERROR);

    double ans = (*res).solution[s];
    std::cout << std::setprecision(12) << std::fixed << ans << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/2171/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2171"
#define ERROR 1e-8

#include <iostream>
#include <vector>
#include <iomanip>
#line 3 "Mylib/Graph/ShortestPath/warshall_floyd_for_matrix_graph.cpp"
#include <optional>

/**
 * @title Warshall-Floyd algorithm (For adjacency matrix graph)
 * @docs warshall_floyd_for_matrix_graph.md
 */
namespace warshall_floyd_for_matrix_impl {
  template <typename T>
  struct Result {
    std::vector<std::vector<std::optional<T>>> dist;
    bool has_negative_cycle;
    const auto& operator[](int i) const {return dist[i];}
  };
}

template <typename T, T INVALID>
auto warshall_floyd_for_matrix(const std::vector<std::vector<T>> &g){
  const int n = g.size();
  auto dist = std::vector(n, std::vector<std::optional<T>>(n));

  for(int i = 0; i < n; ++i) dist[i][i] = 0;

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      if(g[i][j] != INVALID){
        dist[i][j] = g[i][j];
      }
    }
  }

  for(int k = 0; k < n; ++k){
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
        if(dist[i][k] and dist[k][j]){
          if(not dist[i][j]){
            dist[i][j] = *dist[i][k] + *dist[k][j];
          }else{
            dist[i][j] = std::min(*dist[i][j], *dist[i][k] + *dist[k][j]);
          }
        }
      }
    }
  }

  bool has_negative_cycle = false;
  for(int i = 0; i < n; ++i) if(*dist[i][i] < 0) has_negative_cycle = true;

  return warshall_floyd_for_matrix_impl::Result<T>{dist, has_negative_cycle};
}
#line 4 "Mylib/LinearAlgebra/SimultaneousLinearEquations/float_simultaneous_linear_equations.cpp"
#include <utility>

/**
 * @title Simultaneous linear equations (Floating point number)
 * @docs float_simultaneous_linear_equations.md
 */
namespace float_simultaneous_linear_equations_impl {
  template <typename T>
  struct Result {
    int rank, dim;
    std::vector<T> solution;
  };
}

template <typename T>
auto float_simultaneous_linear_equations(std::vector<std::vector<T>> a, std::vector<T> b, T eps){
  using Result = float_simultaneous_linear_equations_impl::Result<T>;
  std::optional<Result> ret;

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

  const int dim = m - rank;

  std::vector<T> solution(m);
  for(int i = 0; i < rank; ++i) solution[i] = b[i];

  ret = Result({rank, dim, solution});
  return ret;
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
#line 10 "test/aoj/2171/main.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n, s, t;
  while(std::cin >> n >> s >> t, n){
    --s, --t;

    auto q = input_vector<int>(n);
    auto g = input_vector<int>(n, n);

    auto dist = warshall_floyd_for_matrix<int, 0>(g);

    if(not dist[s][t]){
      std::cout << "impossible" << std::endl;
      continue;
    }

    std::vector<std::vector<double>> a(n, std::vector<double>(n));
    std::vector<double> b(n);

    for(int i = 0; i < n; ++i){
      if(i == t){
        a[i][i] = 1;
        b[i] = 0;
        continue;
      }

      if(q[i]){
        int d = *dist[i][t];

        int k = 0;
        for(int j = 0; j < n; ++j){
          if(g[i][j] > 0 and g[i][j] + *dist[j][t] == d){
            ++k;
          }
        }

        for(int j = 0; j < n; ++j){
          if(g[i][j] > 0 and g[i][j] + *dist[j][t] == d){
            a[i][j] = -1;
            b[i] += g[i][j];
          }
        }

        a[i][i] += k;
      }else{
        int k = 0;
        for(int j = 0; j < n; ++j){
          if(g[i][j] > 0){
            ++k;
          }
        }

        for(int j = 0; j < n; ++j){
          if(g[i][j] > 0){
            a[i][j] = -1;
            b[i] += g[i][j];
          }
        }

        a[i][i] += k;
      }
    }

    auto res = float_simultaneous_linear_equations(a, b, ERROR);

    double ans = (*res).solution[s];
    std::cout << std::setprecision(12) << std::fixed << ans << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

