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


# :x: test/aoj/ALDS1_9_C/main.binary.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#4cec009c25052c746a2a7a5b033e9889">test/aoj/ALDS1_9_C</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/ALDS1_9_C/main.binary.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C</a>


## Depends on

* :x: <a href="../../../../library/Mylib/DataStructure/Heap/binary_heap.cpp.html">Binary heap</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C"

#include <iostream>
#include <string>
#include "Mylib/DataStructure/Heap/binary_heap.cpp"

namespace hl = haar_lib;

int main(){
  hl::binary_heap<int> heap;
  std::string s;

  while(1){
    std::cin >> s;

    if(s == "insert"){
      int k; std::cin >> k;
      heap.push(k);
    }else if(s == "extract"){
      std::cout << heap.top() << "\n";
      heap.pop();
    }else{
      break;
    }
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/ALDS1_9_C/main.binary.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C"

#include <iostream>
#include <string>
#line 2 "Mylib/DataStructure/Heap/binary_heap.cpp"
#include <vector>
#include <functional>
#include <utility>

/**
 * @title Binary heap
 * @docs binary_heap.md
 */
namespace haar_lib {
  template <typename T, typename Compare = std::less<T>>
  class binary_heap {
    std::vector<T> data;

    int left(int i) const {return i * 2 + 1;}
    int right(int i) const {return i * 2 + 2;}
    int parent(int i) const {return (i - 1) >> 1;}

    Compare compare;

  public:
    binary_heap(): compare(Compare()){}
    binary_heap(size_t capacity): compare(Compare()){data.reserve(capacity);}

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
}
#line 6 "test/aoj/ALDS1_9_C/main.binary.test.cpp"

namespace hl = haar_lib;

int main(){
  hl::binary_heap<int> heap;
  std::string s;

  while(1){
    std::cin >> s;

    if(s == "insert"){
      int k; std::cin >> k;
      heap.push(k);
    }else if(s == "extract"){
      std::cout << heap.top() << "\n";
      heap.pop();
    }else{
      break;
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

