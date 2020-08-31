#pragma once
#include <iostream>
#include <variant>

/**
 * @title Dihedral group
 * @docs dihedral.md
 */
template <typename Tag>
struct DihedralGroup {
  struct R {
    int value = 0;
    friend std::ostream& operator<<(std::ostream &s, const R &a){
      s << "R(" << a.value << ")";
      return s;
    }
  };
  
  struct S {
    int value = 0;
    friend std::ostream& operator<<(std::ostream &s, const S &a){
      s << "S(" << a.value << ")";
      return s;
    }
  };

  static int K;
  
  using value_type = std::variant<R, S>;

  value_type operator()() const {
    return R{0};
  }

  value_type operator()(const value_type &a, const value_type &b) const {
    if(std::holds_alternative<R>(a)){
      if(std::holds_alternative<R>(b)){
        return R{(std::get<R>(a).value + std::get<R>(b).value) % K};
      }else{
        return S{(std::get<S>(b).value - std::get<R>(a).value + K) % K};
      }
    }else{
      if(std::holds_alternative<R>(b)){
        return S{(std::get<S>(a).value + std::get<R>(b).value) % K};
      }else{
        return R{(std::get<S>(b).value - std::get<S>(a).value + K) % K};
      }
    }
  }

  value_type inv(const value_type &a) const {
    if(std::holds_alternative<R>(a)){
      const int i = std::get<R>(a).value;
      return R{i == 0 ? 0 : K - i};
    }else{
      return a;
    }
  }
};

template <typename Tag> int DihedralGroup<Tag>::K;
