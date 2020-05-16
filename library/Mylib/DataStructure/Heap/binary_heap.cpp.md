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


# :heavy_check_mark: BinaryHeap

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#f151d59e79c7ff7f731ff52cf9b782e4">Mylib/DataStructure/Heap</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/Heap/binary_heap.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-16 06:14:31+09:00




## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/ALDS1_9_C/main.binary.test.cpp.html">test/aoj/ALDS1_9_C/main.binary.test.cpp</a>


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
class BinaryHeap{
  std::vector<T> data;

  int left(int i) const {return i * 2 + 1;}
  int right(int i) const {return i * 2 + 2;}
  int parent(int i) const {return (i - 1) >> 1;}

  Compare compare;

public:
  BinaryHeap(): compare(Compare()){}
  BinaryHeap(size_t capacity): compare(Compare()){data.reserve(capacity);}

  void push(T value){
    data.emplace_back(value);

    int i = (int)data.size() - 1;

    while(i > 0){
      int p = parent(i);
      if(compare(data[i], data[p])) break;
      std::swap(data[i], data[p]);
      i = p;
    }
  }

  T top() const {
    return data.front();
  }

  void pop(){
    data.front() = data.back();
    data.pop_back();

    int i = 0;

    while(1){
      int l = left(i);
      int r = right(i);

      if((int)data.size() <= l) break;
      if((int)data.size() <= r){
        if(compare(data[l], data[i])) break;
        std::swap(data[l], data[i]);
        i = l;
      }else{
        if(compare(data[l], data[i]) and compare(data[r], data[i])) break;
        if(compare(data[r], data[l])){
          std::swap(data[l], data[i]);
          i = l;
        }else{
          std::swap(data[r], data[i]);
          i = r;
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
class BinaryHeap{
  std::vector<T> data;

  int left(int i) const {return i * 2 + 1;}
  int right(int i) const {return i * 2 + 2;}
  int parent(int i) const {return (i - 1) >> 1;}

  Compare compare;

public:
  BinaryHeap(): compare(Compare()){}
  BinaryHeap(size_t capacity): compare(Compare()){data.reserve(capacity);}

  void push(T value){
    data.emplace_back(value);

    int i = (int)data.size() - 1;

    while(i > 0){
      int p = parent(i);
      if(compare(data[i], data[p])) break;
      std::swap(data[i], data[p]);
      i = p;
    }
  }

  T top() const {
    return data.front();
  }

  void pop(){
    data.front() = data.back();
    data.pop_back();

    int i = 0;

    while(1){
      int l = left(i);
      int r = right(i);

      if((int)data.size() <= l) break;
      if((int)data.size() <= r){
        if(compare(data[l], data[i])) break;
        std::swap(data[l], data[i]);
        i = l;
      }else{
        if(compare(data[l], data[i]) and compare(data[r], data[i])) break;
        if(compare(data[r], data[l])){
          std::swap(data[l], data[i]);
          i = l;
        }else{
          std::swap(data[r], data[i]);
          i = r;
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

