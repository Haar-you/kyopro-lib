#pragma once
#include <vector>
#include <utility>

/**
 * @title 正方行列
 */
template <typename T> struct SquareMatrix{
  using value_type = T;
  
  int N;
  std::vector<std::vector<T>> matrix;
  
  SquareMatrix(): N(0){}
  SquareMatrix(int N): N(N), matrix(N, std::vector<T>(N)){}
  SquareMatrix(int N, const T &val): N(N), matrix(N, std::vector<T>(N, val)){}
  SquareMatrix(const std::vector<std::vector<T>> &matrix): N(matrix.size()), matrix(matrix){}

  bool operator==(const SquareMatrix<T> &val) const {return matrix == val.matrix;}
  bool operator!=(const SquareMatrix<T> &val) const {return !(*this == val);}
  
  auto& operator=(const SquareMatrix &val){
    this->N = val.N;
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

  inline const auto& operator[](size_t i) const {return matrix[i];}
  inline auto& operator[](size_t i){return matrix[i];}
  inline int size() const {return N;}
  
  static auto make_unit(int N){
    SquareMatrix ret(N);
    for(int i = 0; i < N; ++i) ret[i][i] = 1;
    return ret;
  }

  friend auto operator+(const SquareMatrix &a, const SquareMatrix &b){auto ret = a; ret += b; return ret;}
  friend auto operator-(const SquareMatrix &a, const SquareMatrix &b){auto ret = a; ret -= b; return ret;}
  friend auto operator*(const SquareMatrix &a, const SquareMatrix &b){auto ret = a; ret *= b; return ret;}
};
