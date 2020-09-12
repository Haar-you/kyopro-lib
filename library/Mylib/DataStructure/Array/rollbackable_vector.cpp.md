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


# :warning: Rollbackable vector

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#0d7e284bb2256ddef55e56b25bfaf3f1">Mylib/DataStructure/Array</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/Array/rollbackable_vector.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Operations

## Requirements

## Notes

## Problems

- [ABC 165 F - LIS on Tree](https://atcoder.jp/contests/abc165/tasks/abc165_f)

## References



## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <variant>
#include <initializer_list>
#include <utility>
#include <iostream>

/**
 * @title Rollbackable vector
 * @docs rollbackable_vector.md
 */
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DataStructure/Array/rollbackable_vector.cpp"
#include <vector>
#include <variant>
#include <initializer_list>
#include <utility>
#include <iostream>

/**
 * @title Rollbackable vector
 * @docs rollbackable_vector.md
 */
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

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

