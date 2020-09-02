#pragma once
#include <vector>

/**
 * @title Rollbackable vector
 * @docs rollbackable_vector.md
 */
template <typename T>
class RollbackableVector {
  using value_type = T;

  std::vector<T> data;
  std::vector<std::vector<T>> stock;
  std::vector<int> history;

public:
  void push_back(const T &value){
    data.push_back(value);
    stock.push_back({value});
    history.push_back(-1);
  }

  void set(int i, const T &value){
    data[i] = value;
    stock[i].push_back(value);
    history.push_back(i);
  }

  void roll_back(){
    const int i = history.back(); history.pop_back();

    if(i == -1){
      data.pop_back();
      stock.pop_back();
    }else{
      stock[i].pop_back();
      data[i] = stock[i].back();
    }
  }

  const value_type& operator[](int i) const {return data[i];}

  auto cbegin() const {return data.cbegin();}
  auto cend() const {return data.cend();}

  int size() const {return data.size();}
  bool empty() const {return data.empty();}

  const T& back() const {return data.back();}
  const T& front() const {return data.front();}
};
