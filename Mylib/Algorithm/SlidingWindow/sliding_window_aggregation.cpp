#pragma once
#include <vector>
#include <stack>
#include <optional>

/**
 * @title Sliding window aggregation
 * @docs sliding_window_aggregation.md
 */
template <typename Semigroup>
class SlidingWindowAggregation{
  using value_type = typename Semigroup::value_type;
  
  std::stack<value_type> front_stack, back_stack;
  std::vector<value_type> front_sum, back_sum;
  
public:
  SlidingWindowAggregation(){}
  
  std::optional<value_type> fold() const {
    if(front_sum.empty()){
      if(back_sum.empty()) return std::nullopt;
      return {back_sum.back()};
    }else{
      if(back_sum.empty()) return {front_sum.back()};
      return {Semigroup::op(front_sum.back(), back_sum.back())};
    }
  }

  void push(const value_type &value){
    back_stack.push(value);

    if(back_sum.empty()){
      back_sum.push_back(value);
    }else{
      const auto t = Semigroup::op(back_sum.back(), value);
      back_sum.push_back(t);
    }
  }

  void pop(){
    if(front_stack.empty()){
      back_sum.clear();

      while(not back_stack.empty()){
        const auto value = back_stack.top(); back_stack.pop();
        front_stack.push(value);

        if(front_sum.empty()){
          front_sum.push_back(value);
        }else{
          const auto t = Semigroup::op(value, front_sum.back());
          front_sum.push_back(t);
        }
      }
    }

    front_stack.pop();
    front_sum.pop_back();
  }
};
