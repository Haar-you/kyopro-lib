#pragma once
#include <vector>
#include <stack>
#include <optional>

namespace haar_lib {
  template <typename Semigroup>
  class sliding_window_aggregation {
  public:
    using value_type = typename Semigroup::value_type;

  private:
    Semigroup S_;

    std::stack<value_type> front_stack_, back_stack_;
    std::vector<value_type> front_sum_, back_sum_;

    std::optional<value_type> f(std::optional<value_type> a, std::optional<value_type> b) const {
      if(a){
        if(b) return {S_(*a, *b)};
        else return {*a};
      }else{
        if(b) return {*b};
        else return std::nullopt;
      }
    }

    std::optional<value_type> g(const std::vector<value_type> &a) const {
      return a.empty() ? std::nullopt : std::optional(a.back());
    }

  public:
    sliding_window_aggregation(){}

    std::optional<value_type> fold() const {
      return f(g(front_sum_), g(back_sum_));
    }

    void push(const value_type &value){
      back_stack_.push(value);
      back_sum_.push_back(f(g(back_sum_), value).value());
    }

    void pop(){
      if(front_stack_.empty()){
        back_sum_.clear();

        while(not back_stack_.empty()){
          const auto value = back_stack_.top(); back_stack_.pop();
          front_stack_.push(value);
          front_sum_.push_back(f(value, g(front_sum_)).value());
        }
      }

      front_stack_.pop();
      front_sum_.pop_back();
    }
  };
}
