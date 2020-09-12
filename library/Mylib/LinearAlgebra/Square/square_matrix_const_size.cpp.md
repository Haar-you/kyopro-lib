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


# :x: Square matrix (Const size)

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#b58b3fdb1287502881e9117a37552614">Mylib/LinearAlgebra/Square</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/LinearAlgebra/Square/square_matrix_const_size.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Verified with

* :x: <a href="../../../../verify/test/yukicoder/510/main.test.cpp.html">test/yukicoder/510/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <array>
#include <initializer_list>
#include <utility>

/**
 * @title Square matrix (Const size)
 * @docs square_matrix_const_size.md
 */
namespace haar_lib {
  template <typename T, int N>
  struct square_matrix_const {
    using value_type = T;

    std::array<std::array<T, N>, N> matrix;

    square_matrix_const(){
      for(size_t i = 0; i < N; ++i) for(size_t j = 0; j < N; ++j) matrix[i][j] = 0;
    }
    square_matrix_const(const T &val){
      for(size_t i = 0; i < N; ++i) matrix[i].fill(val);
    }
    square_matrix_const(std::initializer_list<std::initializer_list<T>> list){
      int i = 0;
      for(auto it1 = list.begin(); it1 != list.end(); ++it1, ++i){
        int j = 0;
        for(auto it2 = it1->begin(); it2 != it1->end(); ++it2, ++j){
          matrix[i][j] = *it2;
        }
      }
    }

    bool operator==(const square_matrix_const &val) const {return matrix == val.matrix;}
    bool operator!=(const square_matrix_const &val) const {return !(*this == val);}

    auto& operator=(const square_matrix_const &val){
      this->matrix = val.matrix;
      return *this;
    }

    auto& operator+=(const square_matrix_const &val){
      for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) matrix[i][j] = matrix[i][j] + val[i][j];
      return *this;
    }

    auto& operator-=(const square_matrix_const &val){
      for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) matrix[i][j] = matrix[i][j] - val[i][j];
      return *this;
    }

    auto& operator*=(const square_matrix_const &val){
      std::array<std::array<T, N>, N> temp = {};
      for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) for(int k = 0; k < N; ++k) temp[i][j] = temp[i][j] + matrix[i][k] * val[k][j];
      std::swap(matrix, temp);
      return *this;
    }

    const auto& operator[](size_t i) const {return matrix[i];}
    auto& operator[](size_t i){return matrix[i];}
    int size() const {return N;}

    static auto make_unit(){
      square_matrix_const ret;
      for(size_t i = 0; i < N; ++i) ret[i][i] = 1;
      return ret;
    }

    friend auto operator+(const square_matrix_const &a, const square_matrix_const &b){auto ret = a; ret += b; return ret;}
    friend auto operator-(const square_matrix_const &a, const square_matrix_const &b){auto ret = a; ret -= b; return ret;}
    friend auto operator*(const square_matrix_const &a, const square_matrix_const &b){auto ret = a; ret *= b; return ret;}
  };
}

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
 * @title Square matrix (Const size)
 * @docs square_matrix_const_size.md
 */
namespace haar_lib {
  template <typename T, int N>
  struct square_matrix_const {
    using value_type = T;

    std::array<std::array<T, N>, N> matrix;

    square_matrix_const(){
      for(size_t i = 0; i < N; ++i) for(size_t j = 0; j < N; ++j) matrix[i][j] = 0;
    }
    square_matrix_const(const T &val){
      for(size_t i = 0; i < N; ++i) matrix[i].fill(val);
    }
    square_matrix_const(std::initializer_list<std::initializer_list<T>> list){
      int i = 0;
      for(auto it1 = list.begin(); it1 != list.end(); ++it1, ++i){
        int j = 0;
        for(auto it2 = it1->begin(); it2 != it1->end(); ++it2, ++j){
          matrix[i][j] = *it2;
        }
      }
    }

    bool operator==(const square_matrix_const &val) const {return matrix == val.matrix;}
    bool operator!=(const square_matrix_const &val) const {return !(*this == val);}

    auto& operator=(const square_matrix_const &val){
      this->matrix = val.matrix;
      return *this;
    }

    auto& operator+=(const square_matrix_const &val){
      for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) matrix[i][j] = matrix[i][j] + val[i][j];
      return *this;
    }

    auto& operator-=(const square_matrix_const &val){
      for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) matrix[i][j] = matrix[i][j] - val[i][j];
      return *this;
    }

    auto& operator*=(const square_matrix_const &val){
      std::array<std::array<T, N>, N> temp = {};
      for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) for(int k = 0; k < N; ++k) temp[i][j] = temp[i][j] + matrix[i][k] * val[k][j];
      std::swap(matrix, temp);
      return *this;
    }

    const auto& operator[](size_t i) const {return matrix[i];}
    auto& operator[](size_t i){return matrix[i];}
    int size() const {return N;}

    static auto make_unit(){
      square_matrix_const ret;
      for(size_t i = 0; i < N; ++i) ret[i][i] = 1;
      return ret;
    }

    friend auto operator+(const square_matrix_const &a, const square_matrix_const &b){auto ret = a; ret += b; return ret;}
    friend auto operator-(const square_matrix_const &a, const square_matrix_const &b){auto ret = a; ret -= b; return ret;}
    friend auto operator*(const square_matrix_const &a, const square_matrix_const &b){auto ret = a; ret *= b; return ret;}
  };
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
