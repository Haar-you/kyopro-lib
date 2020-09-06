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


# :x: Square matrix

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#b58b3fdb1287502881e9117a37552614">Mylib/LinearAlgebra/Square</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/LinearAlgebra/Square/square_matrix.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-02 21:08:27+09:00




## Verified with

* :x: <a href="../../../../verify/test/aoj/1327/main.test.cpp.html">test/aoj/1327/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/matrix_det/main.test.cpp.html">test/yosupo-judge/matrix_det/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yukicoder/194/main.test.cpp.html">test/yukicoder/194/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <utility>

/**
 * @title Square matrix
 * @docs square_matrix.md
 */
template <typename T, class Tag>
struct SquareMatrix {
  using value_type = T;

  static int N;
  static void init(int n){N = n;}
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

  const auto& operator[](size_t i) const {return matrix[i];}
  auto& operator[](size_t i){return matrix[i];}
  int size() const {return N;}

  static auto make_unit(){
    SquareMatrix ret;
    for(int i = 0; i < N; ++i) ret[i][i] = 1;
    return ret;
  }

  friend auto operator+(const SquareMatrix &a, const SquareMatrix &b){auto ret = a; ret += b; return ret;}
  friend auto operator-(const SquareMatrix &a, const SquareMatrix &b){auto ret = a; ret -= b; return ret;}
  friend auto operator*(const SquareMatrix &a, const SquareMatrix &b){auto ret = a; ret *= b; return ret;}
};

template <typename T, class Tag> int SquareMatrix<T, Tag>::N;

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/LinearAlgebra/Square/square_matrix.cpp"
#include <vector>
#include <utility>

/**
 * @title Square matrix
 * @docs square_matrix.md
 */
template <typename T, class Tag>
struct SquareMatrix {
  using value_type = T;

  static int N;
  static void init(int n){N = n;}
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

  const auto& operator[](size_t i) const {return matrix[i];}
  auto& operator[](size_t i){return matrix[i];}
  int size() const {return N;}

  static auto make_unit(){
    SquareMatrix ret;
    for(int i = 0; i < N; ++i) ret[i][i] = 1;
    return ret;
  }

  friend auto operator+(const SquareMatrix &a, const SquareMatrix &b){auto ret = a; ret += b; return ret;}
  friend auto operator-(const SquareMatrix &a, const SquareMatrix &b){auto ret = a; ret -= b; return ret;}
  friend auto operator*(const SquareMatrix &a, const SquareMatrix &b){auto ret = a; ret *= b; return ret;}
};

template <typename T, class Tag> int SquareMatrix<T, Tag>::N;

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

