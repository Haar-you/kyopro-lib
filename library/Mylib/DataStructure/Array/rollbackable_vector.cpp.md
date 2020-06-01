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


# :warning: Roll-backable vector

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#0d7e284bb2256ddef55e56b25bfaf3f1">Mylib/DataStructure/Array</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/Array/rollbackable_vector.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




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

/**
 * @title Roll-backable vector
 * @docs rollbackable_vector.md
 */
template <typename T>
class RollbackableVector{
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

  auto cbegin() const {return data.cbegin();}
  auto cend() const {return data.cend();}

  int size() const {return data.size();}
  bool empty() const {return data.empty();}

  const T& back() const {return data.back();}
  const T& front() const {return data.front();}
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DataStructure/Array/rollbackable_vector.cpp"
#include <vector>

/**
 * @title Roll-backable vector
 * @docs rollbackable_vector.md
 */
template <typename T>
class RollbackableVector{
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

  auto cbegin() const {return data.cbegin();}
  auto cend() const {return data.cend();}

  int size() const {return data.size();}
  bool empty() const {return data.empty();}

  const T& back() const {return data.back();}
  const T& front() const {return data.front();}
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

