#pragma once
#include <vector>
#include <variant>
#include <initializer_list>
#include <utility>
#include <iostream>

namespace haar_lib {
  template <typename T>
  class rollbackable_vector {
    using value_type = T;

    std::vector<T> data;

    using Update = std::pair<T, int>;
    struct PushBack {};
    using PopBack = T;

    std::vector<std::variant<Update, PushBack, PopBack>> history;

  public:
    rollbackable_vector(){}
    rollbackable_vector(size_t n): data(n){}
    rollbackable_vector(std::vector<T> a): data(a){}
    rollbackable_vector(std::initializer_list<T> a): data(a.begin(), a.end()){}

    void push_back(const T &value){
      history.push_back(PushBack());
      data.push_back(value);
    }

    void pop_back(){
      history.push_back(PopBack(data.back()));
      data.pop_back();
    }

    void set(int i, const T &value){
      history.push_back(Update(data[i], i));
      data[i] = value;
    }

    void roll_back(){
      if(std::holds_alternative<Update>(history.back())){
        auto [value, i] = std::get<Update>(history.back());
        data[i] = value;
      }else if(std::holds_alternative<PushBack>(history.back())){
        data.pop_back();
      }else if(std::holds_alternative<PopBack>(history.back())){
        auto value = std::get<PopBack>(history.back());
        data.push_back(value);
      }

      history.pop_back();
    }

    bool rollbackable() const {
      return not history.empty();
    }

    const value_type& operator[](int i) const {return data[i];}

    auto cbegin() const {return data.cbegin();}
    auto cend() const {return data.cend();}

    int size() const {return data.size();}
    bool empty() const {return data.empty();}

    const T& back() const {return data.back();}
    const T& front() const {return data.front();}

    friend std::ostream& operator<<(std::ostream &s, const rollbackable_vector &a){
      s << "{";
      for(auto it = a.cbegin(); it != a.cend(); ++it){
        if(it != a.cbegin()) s << ", ";
        s << *it;
      }
      s << "}";
      return s;
    }
  };
}
