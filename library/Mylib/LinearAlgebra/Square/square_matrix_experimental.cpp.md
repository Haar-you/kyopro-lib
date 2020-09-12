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


# :warning: Mylib/LinearAlgebra/Square/square_matrix_experimental.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#b58b3fdb1287502881e9117a37552614">Mylib/LinearAlgebra/Square</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/LinearAlgebra/Square/square_matrix_experimental.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 18:36:08+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <utility>

/**
 */
namespace haar_lib::experimental {
  template <typename T, int *N>
  struct square_matrix {
    using value_type = T;

    std::vector<std::vector<T>> matrix;

    square_matrix(): matrix(*N, std::vector<T>(*N)){}
    square_matrix(const T &val): matrix(*N, std::vector<T>(*N, val)){}
    square_matrix(const std::vector<std::vector<T>> &matrix): matrix(matrix){}

    bool operator==(const square_matrix &val) const {return matrix == val.matrix;}
    bool operator!=(const square_matrix &val) const {return !(*this == val);}

    auto& operator=(const square_matrix &val){
      this->matrix = val.matrix;
      return *this;
    }

    auto& operator+=(const square_matrix &val){
      for(int i = 0; i < (*N); ++i) for(int j = 0; j < (*N); ++j) matrix[i][j] = matrix[i][j] + val[i][j];
      return *this;
    }

    auto& operator-=(const square_matrix &val){
      for(int i = 0; i < (*N); ++i) for(int j = 0; j < (*N); ++j) matrix[i][j] = matrix[i][j] - val[i][j];
      return *this;
    }

    auto& operator*=(const square_matrix &val){
      std::vector<std::vector<T>> temp(*N, std::vector<T>(*N));
      for(int i = 0; i < (*N); ++i) for(int j = 0; j < (*N); ++j) for(int k = 0; k < (*N); ++k) temp[i][j] = temp[i][j] + matrix[i][k] * val[k][j];
      std::swap(matrix, temp);
      return *this;
    }

    const auto& operator[](size_t i) const {return matrix[i];}
    auto& operator[](size_t i){return matrix[i];}
    int size() const {return (*N);}

    static auto make_unit(){
      square_matrix ret;
      for(int i = 0; i < (*N); ++i) ret[i][i] = 1;
      return ret;
    }

    friend auto operator+(const square_matrix &a, const square_matrix &b){auto ret = a; ret += b; return ret;}
    friend auto operator-(const square_matrix &a, const square_matrix &b){auto ret = a; ret -= b; return ret;}
    friend auto operator*(const square_matrix &a, const square_matrix &b){auto ret = a; ret *= b; return ret;}
  };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/LinearAlgebra/Square/square_matrix_experimental.cpp"
#include <vector>
#include <utility>

/**
 */
namespace haar_lib::experimental {
  template <typename T, int *N>
  struct square_matrix {
    using value_type = T;

    std::vector<std::vector<T>> matrix;

    square_matrix(): matrix(*N, std::vector<T>(*N)){}
    square_matrix(const T &val): matrix(*N, std::vector<T>(*N, val)){}
    square_matrix(const std::vector<std::vector<T>> &matrix): matrix(matrix){}

    bool operator==(const square_matrix &val) const {return matrix == val.matrix;}
    bool operator!=(const square_matrix &val) const {return !(*this == val);}

    auto& operator=(const square_matrix &val){
      this->matrix = val.matrix;
      return *this;
    }

    auto& operator+=(const square_matrix &val){
      for(int i = 0; i < (*N); ++i) for(int j = 0; j < (*N); ++j) matrix[i][j] = matrix[i][j] + val[i][j];
      return *this;
    }

    auto& operator-=(const square_matrix &val){
      for(int i = 0; i < (*N); ++i) for(int j = 0; j < (*N); ++j) matrix[i][j] = matrix[i][j] - val[i][j];
      return *this;
    }

    auto& operator*=(const square_matrix &val){
      std::vector<std::vector<T>> temp(*N, std::vector<T>(*N));
      for(int i = 0; i < (*N); ++i) for(int j = 0; j < (*N); ++j) for(int k = 0; k < (*N); ++k) temp[i][j] = temp[i][j] + matrix[i][k] * val[k][j];
      std::swap(matrix, temp);
      return *this;
    }

    const auto& operator[](size_t i) const {return matrix[i];}
    auto& operator[](size_t i){return matrix[i];}
    int size() const {return (*N);}

    static auto make_unit(){
      square_matrix ret;
      for(int i = 0; i < (*N); ++i) ret[i][i] = 1;
      return ret;
    }

    friend auto operator+(const square_matrix &a, const square_matrix &b){auto ret = a; ret += b; return ret;}
    friend auto operator-(const square_matrix &a, const square_matrix &b){auto ret = a; ret -= b; return ret;}
    friend auto operator*(const square_matrix &a, const square_matrix &b){auto ret = a; ret *= b; return ret;}
  };
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

