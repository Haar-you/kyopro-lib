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


# :heavy_check_mark: Binomial heap

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#f151d59e79c7ff7f731ff52cf9b782e4">Mylib/DataStructure/Heap</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/Heap/binomial_heap.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




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
 * @title Binomial heap
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

  template <typename Container>
  void meld(Container c){
    node *s = nullptr;

    for(int i = 0; i < MAX; ++i){
      std::vector<node*> temp;
      if(s){temp.push_back(s); s = nullptr;}
      if(roots[i]){temp.push_back(roots[i]); roots[i] = nullptr;}
      if(i < (int)c.size() and c[i]){temp.push_back(c[i]); c[i] = nullptr;}

      switch(temp.size()){
      case 1: roots[i] = temp[0]; break;
      case 2: s = merge(temp[0], temp[1]); break;
      case 3: roots[i] = temp[0]; s = merge(temp[1], temp[2]); break;
      }
    }
    
    top_index = -1;
    for(int i = 0; i < MAX; ++i){
      if(roots[i]){
        if(top_index == -1 or compare(roots[top_index]->value, roots[i]->value)){
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

    meld(std::vector<node*>({t}));
  }

  const T& top() const {
    return roots[top_index]->value;
  }

  void pop(){
    heap_size -= 1;
    
    node *t = roots[top_index];
    roots[top_index] = nullptr;
    meld(t->children);

    delete t;
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
 * @title Binomial heap
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

  template <typename Container>
  void meld(Container c){
    node *s = nullptr;

    for(int i = 0; i < MAX; ++i){
      std::vector<node*> temp;
      if(s){temp.push_back(s); s = nullptr;}
      if(roots[i]){temp.push_back(roots[i]); roots[i] = nullptr;}
      if(i < (int)c.size() and c[i]){temp.push_back(c[i]); c[i] = nullptr;}

      switch(temp.size()){
      case 1: roots[i] = temp[0]; break;
      case 2: s = merge(temp[0], temp[1]); break;
      case 3: roots[i] = temp[0]; s = merge(temp[1], temp[2]); break;
      }
    }
    
    top_index = -1;
    for(int i = 0; i < MAX; ++i){
      if(roots[i]){
        if(top_index == -1 or compare(roots[top_index]->value, roots[i]->value)){
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

    meld(std::vector<node*>({t}));
  }

  const T& top() const {
    return roots[top_index]->value;
  }

  void pop(){
    heap_size -= 1;
    
    node *t = roots[top_index];
    roots[top_index] = nullptr;
    meld(t->children);

    delete t;
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

