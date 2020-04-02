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


# :warning: Mylib/LinearAlgebra/Square/square_matrix_const_size_semiring.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#b58b3fdb1287502881e9117a37552614">Mylib/LinearAlgebra/Square</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/LinearAlgebra/Square/square_matrix_const_size_semiring.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 04:55:54+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <array>
#include <initializer_list>
#include <utility>

template <typename Semiring, int N> struct SquareMatrix{
  using value_type = typename Semiring::value_type;
  
  std::array<std::array<value_type, N>, N> matrix;
  
  SquareMatrix(){}
  SquareMatrix(std::initializer_list<std::initializer_list<value_type>> list){
    int i = 0;
    for(auto it1 = list.begin(); it1 != list.end(); ++it1, ++i){
      int j = 0;
      for(auto it2 = it1->begin(); it2 != it1->end(); ++it2, ++j){
        matrix[i][j] = *it2;
      }
    }
  }

  bool operator==(const SquareMatrix &val) const {return matrix == val.matrix;}
  bool operator!=(const SquareMatrix &val) const {return !(*this == val);}

  auto& operator=(const SquareMatrix &val){
    matrix = val.matrix;
    return *this;
  }

  auto& operator+=(const SquareMatrix &val){
    for(size_t i = 0; i < N; ++i){
      for(size_t j = 0; j < N; ++j){
        matrix[i][j] = Semiring::add(matrix[i][j], val[i][j]);
      }
    }
    return *this;
  }

  auto& operator*=(const SquareMatrix &val){
    std::array<std::array<value_type, N>, N> temp;
    for(size_t i = 0; i < N; ++i){
      for(size_t j = 0; j < N; ++j){
        for(size_t k = 0; k < N; ++k){
          temp[i][j] = Semiring::add(temp[i][j], Semiring::mul(matrix[i][k], val[k][j]));
        }
      }
    }
    std::swap(matrix, temp);
    return *this;
  }

  inline const auto& operator[](size_t i) const {return matrix[i];}
  inline auto& operator[](size_t i){return matrix[i];}
  inline int size() const {return N;}
  
  static auto make_unit(){
    SquareMatrix<Semiring, N> ret;
    for(size_t i = 0; i < N; ++i) ret[i][i] = Semiring::id_mul();
    return ret;
  }

  friend auto operator+(const SquareMatrix &a, const SquareMatrix &b){auto ret = a; ret += b; return ret;}
  friend auto operator*(const SquareMatrix &a, const SquareMatrix &b){auto ret = a; ret *= b; return ret;}

  friend auto power(SquareMatrix a, uint64_t p){
    if(p == 0) return make_unit();
    if(p == 1) return a;
  
    auto temp = power(a, p/2);
    auto ret = temp * temp;

    if(p & 1) ret *= a;
 
    return ret;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/LinearAlgebra/Square/square_matrix_const_size_semiring.cpp"
#include <array>
#include <initializer_list>
#include <utility>

template <typename Semiring, int N> struct SquareMatrix{
  using value_type = typename Semiring::value_type;
  
  std::array<std::array<value_type, N>, N> matrix;
  
  SquareMatrix(){}
  SquareMatrix(std::initializer_list<std::initializer_list<value_type>> list){
    int i = 0;
    for(auto it1 = list.begin(); it1 != list.end(); ++it1, ++i){
      int j = 0;
      for(auto it2 = it1->begin(); it2 != it1->end(); ++it2, ++j){
        matrix[i][j] = *it2;
      }
    }
  }

  bool operator==(const SquareMatrix &val) const {return matrix == val.matrix;}
  bool operator!=(const SquareMatrix &val) const {return !(*this == val);}

  auto& operator=(const SquareMatrix &val){
    matrix = val.matrix;
    return *this;
  }

  auto& operator+=(const SquareMatrix &val){
    for(size_t i = 0; i < N; ++i){
      for(size_t j = 0; j < N; ++j){
        matrix[i][j] = Semiring::add(matrix[i][j], val[i][j]);
      }
    }
    return *this;
  }

  auto& operator*=(const SquareMatrix &val){
    std::array<std::array<value_type, N>, N> temp;
    for(size_t i = 0; i < N; ++i){
      for(size_t j = 0; j < N; ++j){
        for(size_t k = 0; k < N; ++k){
          temp[i][j] = Semiring::add(temp[i][j], Semiring::mul(matrix[i][k], val[k][j]));
        }
      }
    }
    std::swap(matrix, temp);
    return *this;
  }

  inline const auto& operator[](size_t i) const {return matrix[i];}
  inline auto& operator[](size_t i){return matrix[i];}
  inline int size() const {return N;}
  
  static auto make_unit(){
    SquareMatrix<Semiring, N> ret;
    for(size_t i = 0; i < N; ++i) ret[i][i] = Semiring::id_mul();
    return ret;
  }

  friend auto operator+(const SquareMatrix &a, const SquareMatrix &b){auto ret = a; ret += b; return ret;}
  friend auto operator*(const SquareMatrix &a, const SquareMatrix &b){auto ret = a; ret *= b; return ret;}

  friend auto power(SquareMatrix a, uint64_t p){
    if(p == 0) return make_unit();
    if(p == 1) return a;
  
    auto temp = power(a, p/2);
    auto ret = temp * temp;

    if(p & 1) ret *= a;
 
    return ret;
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

