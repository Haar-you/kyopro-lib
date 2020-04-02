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


# :warning: Mylib/LinearAlgebra/Square/square_matrix_const_size.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#b58b3fdb1287502881e9117a37552614">Mylib/LinearAlgebra/Square</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/LinearAlgebra/Square/square_matrix_const_size.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 04:55:54+09:00


* see: <a href="https://atcoder.jp/contests/abc129/submissions/7098355">https://atcoder.jp/contests/abc129/submissions/7098355</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <array>
#include <initializer_list>
#include <utility>

/**
 * @see https://atcoder.jp/contests/abc129/submissions/7098355
 */
template <typename T, int N> struct SquareMatrixConst{
  using value_type = T;
  
  std::array<std::array<T,N>,N> matrix;

  SquareMatrixConst(){
    for(size_t i = 0; i < N; ++i) for(size_t j = 0; j < N; ++j) matrix[i][j] = 0;
  }
  SquareMatrixConst(const T &val){
    for(size_t i = 0; i < N; ++i) matrix[i].fill(val);
  }
  SquareMatrixConst(std::initializer_list<std::initializer_list<T>> list){
    int i = 0;
    for(auto it1 = list.begin(); it1 != list.end(); ++it1, ++i){
      int j = 0;
      for(auto it2 = it1->begin(); it2 != it1->end(); ++it2, ++j){
        matrix[i][j] = *it2;
      }
    }
  }

  bool operator==(const SquareMatrixConst &val) const {return matrix == val.matrix;}
  bool operator!=(const SquareMatrixConst &val) const {return !(*this == val);}

  auto& operator=(const SquareMatrixConst &val){
    this->matrix = val.matrix;
    return *this;
  }

  auto& operator+=(const SquareMatrixConst &val){
    for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) matrix[i][j] = matrix[i][j] + val[i][j];
    return *this;
  }

  auto& operator-=(const SquareMatrixConst &val){
    for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) matrix[i][j] = matrix[i][j] - val[i][j];
    return *this;
  }

  auto& operator*=(const SquareMatrixConst &val){
    std::array<std::array<T,N>,N> temp = {};
    for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) for(int k = 0; k < N; ++k) temp[i][j] = temp[i][j] + matrix[i][k] * val[k][j];
    std::swap(matrix, temp);
    return *this;
  }

  inline const auto& operator[](size_t i) const {return matrix[i];}
  inline auto& operator[](size_t i){return matrix[i];}
  inline int size() const {return N;}
  
  static auto make_unit(int = 0){
    SquareMatrixConst ret;
    for(size_t i = 0; i < N; ++i) ret[i][i] = 1;
    return ret;
  }

  friend auto operator+(const SquareMatrixConst &a, const SquareMatrixConst &b){auto ret = a; ret += b; return ret;}
  friend auto operator-(const SquareMatrixConst &a, const SquareMatrixConst &b){auto ret = a; ret -= b; return ret;}
  friend auto operator*(const SquareMatrixConst &a, const SquareMatrixConst &b){auto ret = a; ret *= b; return ret;}
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/LinearAlgebra/Square/square_matrix_const_size.cpp"
#include <array>
#include <initializer_list>
#include <utility>

/**
 * @see https://atcoder.jp/contests/abc129/submissions/7098355
 */
template <typename T, int N> struct SquareMatrixConst{
  using value_type = T;
  
  std::array<std::array<T,N>,N> matrix;

  SquareMatrixConst(){
    for(size_t i = 0; i < N; ++i) for(size_t j = 0; j < N; ++j) matrix[i][j] = 0;
  }
  SquareMatrixConst(const T &val){
    for(size_t i = 0; i < N; ++i) matrix[i].fill(val);
  }
  SquareMatrixConst(std::initializer_list<std::initializer_list<T>> list){
    int i = 0;
    for(auto it1 = list.begin(); it1 != list.end(); ++it1, ++i){
      int j = 0;
      for(auto it2 = it1->begin(); it2 != it1->end(); ++it2, ++j){
        matrix[i][j] = *it2;
      }
    }
  }

  bool operator==(const SquareMatrixConst &val) const {return matrix == val.matrix;}
  bool operator!=(const SquareMatrixConst &val) const {return !(*this == val);}

  auto& operator=(const SquareMatrixConst &val){
    this->matrix = val.matrix;
    return *this;
  }

  auto& operator+=(const SquareMatrixConst &val){
    for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) matrix[i][j] = matrix[i][j] + val[i][j];
    return *this;
  }

  auto& operator-=(const SquareMatrixConst &val){
    for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) matrix[i][j] = matrix[i][j] - val[i][j];
    return *this;
  }

  auto& operator*=(const SquareMatrixConst &val){
    std::array<std::array<T,N>,N> temp = {};
    for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) for(int k = 0; k < N; ++k) temp[i][j] = temp[i][j] + matrix[i][k] * val[k][j];
    std::swap(matrix, temp);
    return *this;
  }

  inline const auto& operator[](size_t i) const {return matrix[i];}
  inline auto& operator[](size_t i){return matrix[i];}
  inline int size() const {return N;}
  
  static auto make_unit(int = 0){
    SquareMatrixConst ret;
    for(size_t i = 0; i < N; ++i) ret[i][i] = 1;
    return ret;
  }

  friend auto operator+(const SquareMatrixConst &a, const SquareMatrixConst &b){auto ret = a; ret += b; return ret;}
  friend auto operator-(const SquareMatrixConst &a, const SquareMatrixConst &b){auto ret = a; ret -= b; return ret;}
  friend auto operator*(const SquareMatrixConst &a, const SquareMatrixConst &b){auto ret = a; ret *= b; return ret;}
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

