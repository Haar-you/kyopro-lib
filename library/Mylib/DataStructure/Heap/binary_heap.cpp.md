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


# :warning: BinaryHeap

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#f151d59e79c7ff7f731ff52cf9b782e4">Mylib/DataStructure/Heap</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/Heap/binary_heap.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-05 16:49:32+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <functional>
#include <utility>

/**
 * @title BinaryHeap
 * @docs binary_heap.md
 */
template <typename T, typename Compare = std::less<T>>
struct BinaryHeap{
  std::vector<T> data;

  BinaryHeap(){}
  BinaryHeap(size_t capacity){data.reserve(capacity);}

  void push(T value){
    data.emplace_back(value);

    int i = data.size();

    while(i > 1){
      int p = i >> 1;
      if(Compare()(data[p-1], data[i-1])){
        std::swap(data[i-1], data[p-1]);
        i = p;
      }else{
        break;
      }
    }
  }

  T top() const {
    return data.front();
  }

  void pop(){
    data.front() = data.back();
    data.pop_back();

    int i = 1;

    while(1){
      int left = i << 1 | 0;
      int right = i << 1 | 1;

      if((int)data.size() < left){
        break;
      }else if((int)data.size() < right){
        if(Compare()(data[i-1], data[left-1])){
          std::swap(data[left-1], data[i-1]);
          i = left;
        }else{
          break;
        }
      }else{
        if(Compare()(data[left-1], data[i-1]) and Compare()(data[right-1], data[i-1])){
          break;
        }else{
          if(Compare()(data[right-1], data[left-1])){
            std::swap(data[left-1], data[i-1]);
            i = left;
          }else{
            std::swap(data[right-1], data[i-1]);
            i = right;
          }
        }
      }
    }
  }

  bool empty() const {
    return data.empty();
  }

  size_t size() const {
    return data.size();
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DataStructure/Heap/binary_heap.cpp"
#include <vector>
#include <functional>
#include <utility>

/**
 * @title BinaryHeap
 * @docs binary_heap.md
 */
template <typename T, typename Compare = std::less<T>>
struct BinaryHeap{
  std::vector<T> data;

  BinaryHeap(){}
  BinaryHeap(size_t capacity){data.reserve(capacity);}

  void push(T value){
    data.emplace_back(value);

    int i = data.size();

    while(i > 1){
      int p = i >> 1;
      if(Compare()(data[p-1], data[i-1])){
        std::swap(data[i-1], data[p-1]);
        i = p;
      }else{
        break;
      }
    }
  }

  T top() const {
    return data.front();
  }

  void pop(){
    data.front() = data.back();
    data.pop_back();

    int i = 1;

    while(1){
      int left = i << 1 | 0;
      int right = i << 1 | 1;

      if((int)data.size() < left){
        break;
      }else if((int)data.size() < right){
        if(Compare()(data[i-1], data[left-1])){
          std::swap(data[left-1], data[i-1]);
          i = left;
        }else{
          break;
        }
      }else{
        if(Compare()(data[left-1], data[i-1]) and Compare()(data[right-1], data[i-1])){
          break;
        }else{
          if(Compare()(data[right-1], data[left-1])){
            std::swap(data[left-1], data[i-1]);
            i = left;
          }else{
            std::swap(data[right-1], data[i-1]);
            i = right;
          }
        }
      }
    }
  }

  bool empty() const {
    return data.empty();
  }

  size_t size() const {
    return data.size();
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

