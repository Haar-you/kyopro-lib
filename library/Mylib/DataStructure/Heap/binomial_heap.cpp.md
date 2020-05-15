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


# :heavy_check_mark: BinomialHeap

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#f151d59e79c7ff7f731ff52cf9b782e4">Mylib/DataStructure/Heap</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/Heap/binomial_heap.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-14 01:02:10+09:00




## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/2559/main.binomial_heap.test.cpp.html">test/aoj/2559/main.binomial_heap.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <array>
#include <functional>
#include <cassert>

/**
 * @title BinomialHeap
 * @docs binomial_heap.md
 */
template <typename T, typename Compare = std::less<T>>
class BinomialHeap{
  struct node{
    T value;
    std::vector<node*> children;

    node(T value): value(value){}
  };

  constexpr static int MAX = 31;
  
  std::array<node*, MAX> roots;
  Compare compare;
  int top_index = -1;
  int heap_size = 0;

  node* merge(node *a, node *b){
    if(compare(a->value, b->value)) std::swap(a, b);
    a->children.push_back(b);
    return a;
  }

  void meld(std::array<node*, MAX> y){
    node *s = nullptr;

    for(int i = 0; i < MAX; ++i){
      node *a = nullptr;

      if(s and y[i]){
        a = merge(s, y[i]);
        s = nullptr;
      }else if(y[i]){
        std::swap(s, y[i]);
      }

      if(a){
        std::swap(s, a);
      }else{
        if(s and roots[i]){
          s = merge(s, roots[i]);
          roots[i] = nullptr;
        }else if(s){
          roots[i] = s;
          s = nullptr;
        }
      }
    }
    
    top_index = -1;
    for(int i = 0; i < MAX; ++i){
      if(roots[i]){
        if(top_index == -1){
          top_index = i;
        }else if(compare(roots[top_index]->value, roots[i]->value)){
          top_index = i;
        }
      }
    }
  }

public:
  BinomialHeap(){
    roots.fill(nullptr);
    compare = Compare();
  }

  int size() const {
    return heap_size;
  }

  bool empty() const {
    return heap_size == 0;
  }
  
  void push(const T &value){
    heap_size += 1;
    node *t = new node(value);

    for(int i = 0; i < MAX; ++i){
      if(roots[i]){
        t = merge(t, roots[i]);
        roots[i] = nullptr;
      }else{
        if(top_index == -1 or not roots[top_index] or compare(roots[top_index]->value, t->value)){
          top_index = i;
        }
        
        roots[i] = t;
        break;
      }
    }
  }

  const T& top() const {
    assert(top_index >= 0);
    return roots[top_index]->value;
  }

  void pop(){
    assert(top_index >= 0);
    heap_size -= 1;

    node *t = roots[top_index];
    roots[top_index] = nullptr;
    
    std::array<node*, MAX> c;
    c.fill(nullptr);
    std::copy(t->children.begin(), t->children.end(), c.begin());
    delete t;
    
    meld(c);
  }

  void meld(BinomialHeap &rhs){
    heap_size += rhs.heap_size;
    meld(rhs.roots);
    rhs.roots.fill(nullptr);
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DataStructure/Heap/binomial_heap.cpp"
#include <vector>
#include <array>
#include <functional>
#include <cassert>

/**
 * @title BinomialHeap
 * @docs binomial_heap.md
 */
template <typename T, typename Compare = std::less<T>>
class BinomialHeap{
  struct node{
    T value;
    std::vector<node*> children;

    node(T value): value(value){}
  };

  constexpr static int MAX = 31;
  
  std::array<node*, MAX> roots;
  Compare compare;
  int top_index = -1;
  int heap_size = 0;

  node* merge(node *a, node *b){
    if(compare(a->value, b->value)) std::swap(a, b);
    a->children.push_back(b);
    return a;
  }

  void meld(std::array<node*, MAX> y){
    node *s = nullptr;

    for(int i = 0; i < MAX; ++i){
      node *a = nullptr;

      if(s and y[i]){
        a = merge(s, y[i]);
        s = nullptr;
      }else if(y[i]){
        std::swap(s, y[i]);
      }

      if(a){
        std::swap(s, a);
      }else{
        if(s and roots[i]){
          s = merge(s, roots[i]);
          roots[i] = nullptr;
        }else if(s){
          roots[i] = s;
          s = nullptr;
        }
      }
    }
    
    top_index = -1;
    for(int i = 0; i < MAX; ++i){
      if(roots[i]){
        if(top_index == -1){
          top_index = i;
        }else if(compare(roots[top_index]->value, roots[i]->value)){
          top_index = i;
        }
      }
    }
  }

public:
  BinomialHeap(){
    roots.fill(nullptr);
    compare = Compare();
  }

  int size() const {
    return heap_size;
  }

  bool empty() const {
    return heap_size == 0;
  }
  
  void push(const T &value){
    heap_size += 1;
    node *t = new node(value);

    for(int i = 0; i < MAX; ++i){
      if(roots[i]){
        t = merge(t, roots[i]);
        roots[i] = nullptr;
      }else{
        if(top_index == -1 or not roots[top_index] or compare(roots[top_index]->value, t->value)){
          top_index = i;
        }
        
        roots[i] = t;
        break;
      }
    }
  }

  const T& top() const {
    assert(top_index >= 0);
    return roots[top_index]->value;
  }

  void pop(){
    assert(top_index >= 0);
    heap_size -= 1;

    node *t = roots[top_index];
    roots[top_index] = nullptr;
    
    std::array<node*, MAX> c;
    c.fill(nullptr);
    std::copy(t->children.begin(), t->children.end(), c.begin());
    delete t;
    
    meld(c);
  }

  void meld(BinomialHeap &rhs){
    heap_size += rhs.heap_size;
    meld(rhs.roots);
    rhs.roots.fill(nullptr);
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

