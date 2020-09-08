#pragma once
#include <vector>
#include <stack>
#include <optional>

/**
 * @title Sliding window aggregation
 * @docs sliding_window_aggregation.md
 */
namespace haar_lib {
  template <typename Semigroup>
  class sliding_window_aggregation {
    using value_type = typename Semigroup::value_type;
    const static Semigroup S;

    std::stack<value_type> front_stack, back_stack;
    std::vector<value_type> front_sum, back_sum;

    std::optional<value_type> f(std::optional<value_type> a, std::optional<value_type> b) const {
      if(a){
        if(b) return {S(*a, *b)};
        else return {*a};
      }else{
        if(b) return {*b};
        else return {};
      }
    }

    std::optional<value_type> g(const std::vector<value_type> &a) const {
      return a.empty() ? std::nullopt : std::optional(a.back());
    }

  public:
    sliding_window_aggregation(){}

    std::optional<value_type> fold() const {
      return f(g(front_sum), g(back_sum));
    }

    void push(const value_type &value){
      back_stack.push(value);
      back_sum.push_back(f(g(back_sum), value).value());
    }

    void pop(){
      if(front_stack.empty()){
        back_sum.clear();

        while(not back_stack.empty()){
          const auto value = back_stack.top(); back_stack.pop();
          front_stack.push(value);
          front_sum.push_back(f(value, g(front_sum)).value());
        }
      }

      front_stack.pop();
      front_sum.pop_back();
    }
  };
}
