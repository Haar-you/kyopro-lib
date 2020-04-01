#pragma once
#include <vector>
#include <utility>

template <typename Semiring> struct SquareMatrix{
  using value_type = typename Semiring::value_type;
  
  size_t N;
  std::vector<std::vector<value_type>> matrix;
  
  SquareMatrix(): N(0){}
  SquareMatrix(int N): N(N), matrix(N, std::vector<value_type>(N, Semiring::id_add())){}

  bool operator==(const SquareMatrix &val) const {return matrix == val.matrix;}
  bool operator!=(const SquareMatrix &val) const {return !(*this == val);}

  auto& operator=(const SquareMatrix &val){
    N = val.N;
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
    std::vector<std::vector<value_type>> temp(N, std::vector<value_type>(N));
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
  
  static auto make_unit(size_t N){
    SquareMatrix<Semiring> ret(N);
    for(size_t i = 0; i < N; ++i) ret[i][i] = Semiring::id_mul();
    return ret;
  }

  friend auto operator+(const SquareMatrix &a, const SquareMatrix &b){auto ret = a; ret += b; return ret;}
  friend auto operator*(const SquareMatrix &a, const SquareMatrix &b){auto ret = a; ret *= b; return ret;}

  friend auto power(SquareMatrix a, uint64_t p){
    const int N = a.size();

    if(p == 0) return make_unit(N);
    if(p == 1) return a;
  
    auto temp = power(a, p/2);
    auto ret = temp * temp;

    if(p & 1) ret *= a;
 
    return ret;
  }
};
