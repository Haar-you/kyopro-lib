#pragma once
#include <vector>
#include <utility>

/**
 * @title Square matrix
 * @docs square_matrix.md
 */
template <typename T, class Tag> struct SquareMatrix{
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

template <typename T, class Tag> int SquareMatrix<T,Tag>::N;
