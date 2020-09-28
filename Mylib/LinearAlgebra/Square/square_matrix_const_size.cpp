#pragma once
#include <array>
#include <initializer_list>
#include <utility>
#include <iostream>

namespace haar_lib {
  template <typename T, int N>
  class vector_const {
  public:
    using value_type = T;

  private:
    std::array<T, N> data_;

  public:
    vector_const(){data_.fill(0);}
    vector_const(T value){data_.fill(value);}
    vector_const(std::initializer_list<T> list){
      int i = 0;
      for(auto it = list.begin(); it != list.end(); ++it) data_[i++] = *it;
    }
    vector_const(const vector_const &that): data_(that.data_){}

    bool operator==(const vector_const &that){return data_ == that.data_;}
    bool operator!=(const vector_const &that){return !(*this == that);}

    auto& operator=(const vector_const &that){
      data_ = that.data_;
      return *this;
    }

    auto& operator+=(const vector_const &that){
      for(int i = 0; i < N; ++i) data_[i] += that.data_[i];
      return *this;
    }

    auto& operator-=(const vector_const &that){
      for(int i = 0; i < N; ++i) data_[i] -= that.data_[i];
      return *this;
    }

    friend auto dot(const vector_const &a, const vector_const &b){
      T ret = 0;
      for(int i = 0; i < N; ++i) ret += a.data_[i] * b.data_[i];
      return ret;
    }

    auto operator+(const vector_const &that) const {
      return vector_const(*this) += that;
    }

    auto operator-(const vector_const &that) const {
      return vector_const(*this) -= that;
    }

    auto& operator[](int i){return data_[i];}
    const auto& operator[](int i) const {return data_[i];}
    auto begin() const {return data_.begin();}
    auto end() const {return data_.end();}

    int size() const {return N;}

    friend std::ostream& operator<<(std::ostream &s, const vector_const &a){
      s << "{";
      for(auto it = a.data_.begin(); it != a.data_.end(); ++it){
        if(it != a.data_.begin()) s << ",";
        s << *it;
      }
      s << "}";
      return s;
    }
  };


  template <typename T, int N>
  class square_matrix_const {
  public:
    using value_type = T;
    using vector_type = vector_const<T, N>;

  private:
    std::array<vector_type, N> data_;

  public:
    square_matrix_const(){
      for(int i = 0; i < N; ++i) data_[i] = vector_type();
    }
    square_matrix_const(const T &val){
      for(int i = 0; i < N; ++i) data_[i] = vector_type(val);
    }
    square_matrix_const(std::initializer_list<std::initializer_list<T>> list){
      int i = 0;
      for(auto it = list.begin(); it != list.end(); ++it){
        data_[i++] = vector_type(*it);
      }
    }
    square_matrix_const(const square_matrix_const &that): data_(that.data_){}

    bool operator==(const square_matrix_const &that) const {return data_ == that.data_;}
    bool operator!=(const square_matrix_const &that) const {return !(*this == that);}

    auto& operator=(const square_matrix_const &that){
      data_ = that.data_;
      return *this;
    }

    auto& operator+=(const square_matrix_const &that){
      for(int i = 0; i < N; ++i) data_[i] += that.data_[i];
      return *this;
    }

    auto& operator-=(const square_matrix_const &that){
      for(int i = 0; i < N; ++i) data_[i] -= that.data_[i];
      return *this;
    }

    auto& operator*=(const square_matrix_const &that){
      square_matrix_const ret;
      for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
          for(int k = 0; k < N; ++k)
            ret[i][j] += data_[i][k] * that.data_[k][j];
      return *this = ret;
    }

    const auto& operator[](int i) const {return data_[i];}
    auto& operator[](int i){return data_[i];}
    int size() const {return N;}

    static auto unit(){
      square_matrix_const ret;
      for(int i = 0; i < N; ++i) ret[i][i] = 1;
      return ret;
    }

    auto operator+(const square_matrix_const &that) const {
      return square_matrix_const(*this) += that;
    }
    auto operator-(const square_matrix_const &that) const {
      return square_matrix_const(*this) -= that;
    }
    auto operator*(const square_matrix_const &that) const {
      return square_matrix_const(*this) *= that;
    }

    auto pow(uint64_t p) const {
      auto ret = unit();
      auto a = *this;

      while(p > 0){
        if(p & 1) ret *= a;
        a *= a;
        p >>= 1;
      }

      return ret;
    }

    auto operator*(const vector_type &that) const {
      vector_type ret;
      for(int i = 0; i < N; ++i) ret[i] = dot(data_[i], that);
      return ret;
    }
  };
}
