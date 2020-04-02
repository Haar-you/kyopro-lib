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


# :x: Mylib/Algorithm/SlidingWindow/sliding_window_aggregation.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#1d0203f9a0b34121f2fb0bb17b094d0f">Mylib/Algorithm/SlidingWindow</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Algorithm/SlidingWindow/sliding_window_aggregation.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-31 11:59:58+09:00




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

template <typename T, typename F>
class SlidingWindowAggregation{
  std::stack<T> front_stack, back_stack;
  std::vector<T> front_sum, back_sum;

  const F f;
  
public:
  SlidingWindowAggregation(const F &f): f(f){}
  
  std::optional<T> fold() const {
    if(front_sum.empty()){
      if(back_sum.empty()) return std::nullopt;
      return {back_sum.back()};
    }else{
      if(back_sum.empty()) return {front_sum.back()};
      return {f(front_sum.back(), back_sum.back())};
    }
  }

  void push(const T &value){
    back_stack.push(value);

    if(back_sum.empty()){
      back_sum.push_back(value);
    }else{
      const auto t = f(back_sum.back(), value);
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
          const auto t = f(value, front_sum.back());
          front_sum.push_back(t);
        }
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

template <typename T, typename F>
class SlidingWindowAggregation{
  std::stack<T> front_stack, back_stack;
  std::vector<T> front_sum, back_sum;

  const F f;
  
public:
  SlidingWindowAggregation(const F &f): f(f){}
  
  std::optional<T> fold() const {
    if(front_sum.empty()){
      if(back_sum.empty()) return std::nullopt;
      return {back_sum.back()};
    }else{
      if(back_sum.empty()) return {front_sum.back()};
      return {f(front_sum.back(), back_sum.back())};
    }
  }

  void push(const T &value){
    back_stack.push(value);

    if(back_sum.empty()){
      back_sum.push_back(value);
    }else{
      const auto t = f(back_sum.back(), value);
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
          const auto t = f(value, front_sum.back());
          front_sum.push_back(t);
        }
      }
    }

    front_stack.pop();
    front_sum.pop_back();
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

