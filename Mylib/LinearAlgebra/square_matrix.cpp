#pragma once
#include <vector>
#include <utility>
#include <cstdint>
#include <iostream>

namespace haar_lib {
  template <typename T, int &N>
  class vector_dyn {
  public:
    using value_type = T;

  private:
    std::vector<T> data_;

  public:
    vector_dyn(): data_(N){}
    vector_dyn(T value): data_(N, value){}
    vector_dyn(std::initializer_list<T> list): data_(N){
      int i = 0;
      for(auto it = list.begin(); it != list.end(); ++it) data_[i++] = *it;
    }
    vector_dyn(const vector_dyn &that): data_(that.data_){}

    template <typename U>
    vector_dyn(const std::vector<U> &that): data_(that.begin(), that.end()){}

    bool operator==(const vector_dyn &that){return data_ == that.data_;}
    bool operator!=(const vector_dyn &that){return !(*this == that);}

    auto& operator=(const vector_dyn &that){
      data_ = that.data_;
      return *this;
    }

    auto& operator+=(const vector_dyn &that){
      for(int i = 0; i < N; ++i) data_[i] += that.data_[i];
      return *this;
    }

    auto& operator-=(const vector_dyn &that){
      for(int i = 0; i < N; ++i) data_[i] -= that.data_[i];
      return *this;
    }

    friend auto dot(const vector_dyn &a, const vector_dyn &b){
      T ret = 0;
      for(int i = 0; i < N; ++i) ret += a.data_[i] * b.data_[i];
      return ret;
    }

    auto operator+(const vector_dyn &that) const {
      return vector(*this) += that;
    }

    auto operator-(const vector_dyn &that) const {
      return vector(*this) -= that;
    }

    auto& operator[](int i){return data_[i];}
    const auto& operator[](int i) const {return data_[i];}
    auto begin() const {return data_.begin();}
    auto end() const {return data_.end();}

    int size() const {return N;}

    friend std::ostream& operator<<(std::ostream &s, const vector_dyn &a){
      s << "{";
      for(auto it = a.data_.begin(); it != a.data_.end(); ++it){
        if(it != a.data_.begin()) s << ",";
        s << *it;
      }
      s << "}";
      return s;
    }
  };


  template <typename T, int &N>
  class square_matrix_dyn {
  public:
    using value_type = T;
    using vector_type = vector_dyn<T, N>;

  private:
    std::vector<vector_type> data_;

  public:
    square_matrix_dyn(): data_(N, vector_type()){}
    square_matrix_dyn(const T &val): data_(N, vector_type(val)){}
    square_matrix_dyn(std::initializer_list<std::initializer_list<T>> list): data_(N){
      int i = 0;
      for(auto it = list.begin(); it != list.end(); ++it){
        data_[i++] = vector_type(*it);
      }
    }
    square_matrix_dyn(const square_matrix_dyn &that): data_(that.data_){}
    square_matrix_dyn(const std::vector<std::vector<T>> &that): data_(N){
      for(int i = 0; i < N; ++i) data_[i] = that[i];
    }

    bool operator==(const square_matrix_dyn &that) const {return data_ == that.data_;}
    bool operator!=(const square_matrix_dyn &that) const {return !(*this == that);}

    auto& operator=(const square_matrix_dyn &that){
      data_ = that.data_;
      return *this;
    }

    auto& operator+=(const square_matrix_dyn &that){
      for(int i = 0; i < N; ++i) data_[i] += that.data_[i];
      return *this;
    }

    auto& operator-=(const square_matrix_dyn &that){
      for(int i = 0; i < N; ++i) data_[i] -= that.data_[i];
      return *this;
    }

    auto& operator*=(const square_matrix_dyn &that){
      square_matrix_dyn ret;
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
      square_matrix_dyn ret;
      for(int i = 0; i < N; ++i) ret[i][i] = 1;
      return ret;
    }

    auto operator+(const square_matrix_dyn &that){
      return square_matrix_dyn(*this) += that;
    }
    auto operator-(const square_matrix_dyn &that){
      return square_matrix_dyn(*this) -= that;
    }
    auto operator*(const square_matrix_dyn &that){
      return square_matrix_dyn(*this) *= that;
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

    auto operator*(const vector_type &that){
      vector_type ret;
      for(int i = 0; i < N; ++i) ret[i] = dot(data_[i], that);
      return ret;
    }
  };
}
