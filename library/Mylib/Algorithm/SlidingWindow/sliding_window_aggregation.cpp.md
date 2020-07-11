---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../assets/css/copy-button.css" />


# :x: Sliding window aggregation

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#1d0203f9a0b34121f2fb0bb17b094d0f">Mylib/Algorithm/SlidingWindow</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Algorithm/SlidingWindow/sliding_window_aggregation.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-11 14:07:48+09:00




## Operations

## Requirements

## Notes

## Problems

## References

- [https://scrapbox.io/data-structures/Sliding_Window_Aggregation](https://scrapbox.io/data-structures/Sliding_Window_Aggregation)


## Verified with

* :x: <a href="../../../../verify/test/yosupo-judge/queue_operate_all_composite/main.test.cpp.html">test/yosupo-judge/queue_operate_all_composite/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
  Semigroup S;
  
  std::stack<value_type> front_stack, back_stack;
  std::vector<value_type> front_sum, back_sum;

  std::optional<value_type> f(std::optional<value_type> a, std::optional<value_type> b) const {
    if(a){
      if(b) return {S.op(*a, *b)};
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
  SlidingWindowAggregation(){}
  
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Algorithm/SlidingWindow/sliding_window_aggregation.cpp"
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
  Semigroup S;
  
  std::stack<value_type> front_stack, back_stack;
  std::vector<value_type> front_sum, back_sum;

  std::optional<value_type> f(std::optional<value_type> a, std::optional<value_type> b) const {
    if(a){
      if(b) return {S.op(*a, *b)};
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
  SlidingWindowAggregation(){}
  
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

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

