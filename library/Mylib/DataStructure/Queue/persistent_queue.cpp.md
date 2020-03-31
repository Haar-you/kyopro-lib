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


# :heavy_check_mark: Mylib/DataStructure/Queue/persistent_queue.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#6b1c73113eb1a95c1a861edccc8def0a">Mylib/DataStructure/Queue</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/Queue/persistent_queue.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-31 08:22:27+09:00




## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/yosupo-judge/persistent_queue/main.test.cpp.html">test/yosupo-judge/persistent_queue/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <array>

/**
 * @attention time complexity of push(value) and pop() : O(MAX_SIZE_2)
 */
template <typename T>
class PersistentQueue{
  constexpr static int MAX_SIZE_2 = 20; // size <= 2 ^ MAX_SIZE_2
  
  struct node{
    T value;
    std::array<node*, MAX_SIZE_2> ancestors;
    int depth = 0;
  };

  node *front_node = nullptr, *back_node = nullptr;

  PersistentQueue(node* front_node, node* back_node): front_node(front_node), back_node(back_node){}
  
  
public:
  PersistentQueue() {}
  PersistentQueue(const T &value){
    node *t = new node();
    t->value = value;
    back_node = front_node = t;
  }
  
  PersistentQueue push(const T &value){
    node *t = new node();

    t->value = value;
    
    t->ancestors[0] = back_node;
    for(int i = 1; i < MAX_SIZE_2; ++i){
      node *s = t->ancestors[i-1];
      if(s) t->ancestors[i] = s->ancestors[i-1];
      else break;
    }

    t->depth = back_node ? back_node->depth + 1 : 0;
    
    return PersistentQueue(front_node ? front_node : t, t);
  }

  PersistentQueue pop(){
    if(back_node->depth == front_node->depth){
      return PersistentQueue(nullptr, nullptr);
    }
    
    int d = back_node->depth - front_node->depth - 1;

    node *t = back_node;

    for(int i = MAX_SIZE_2 - 1; i >= 0; --i){
      if(d >= (1 << i)){
        d -= (1 << i);
        t = t->ancestors[i];
      }
      if(d == 0) break;
    }
    
    return PersistentQueue(t, back_node);
  }

  T front() const {
    return front_node->value;
  }

  T back() const {
    return back_node->value;
  }

  bool empty() const {
    return not front_node;
  }

  int size() const {
    return front_node ? 0 : back_node->depth - front_node->depth + 1;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DataStructure/Queue/persistent_queue.cpp"
#include <array>

/**
 * @attention time complexity of push(value) and pop() : O(MAX_SIZE_2)
 */
template <typename T>
class PersistentQueue{
  constexpr static int MAX_SIZE_2 = 20; // size <= 2 ^ MAX_SIZE_2
  
  struct node{
    T value;
    std::array<node*, MAX_SIZE_2> ancestors;
    int depth = 0;
  };

  node *front_node = nullptr, *back_node = nullptr;

  PersistentQueue(node* front_node, node* back_node): front_node(front_node), back_node(back_node){}
  
  
public:
  PersistentQueue() {}
  PersistentQueue(const T &value){
    node *t = new node();
    t->value = value;
    back_node = front_node = t;
  }
  
  PersistentQueue push(const T &value){
    node *t = new node();

    t->value = value;
    
    t->ancestors[0] = back_node;
    for(int i = 1; i < MAX_SIZE_2; ++i){
      node *s = t->ancestors[i-1];
      if(s) t->ancestors[i] = s->ancestors[i-1];
      else break;
    }

    t->depth = back_node ? back_node->depth + 1 : 0;
    
    return PersistentQueue(front_node ? front_node : t, t);
  }

  PersistentQueue pop(){
    if(back_node->depth == front_node->depth){
      return PersistentQueue(nullptr, nullptr);
    }
    
    int d = back_node->depth - front_node->depth - 1;

    node *t = back_node;

    for(int i = MAX_SIZE_2 - 1; i >= 0; --i){
      if(d >= (1 << i)){
        d -= (1 << i);
        t = t->ancestors[i];
      }
      if(d == 0) break;
    }
    
    return PersistentQueue(t, back_node);
  }

  T front() const {
    return front_node->value;
  }

  T back() const {
    return back_node->value;
  }

  bool empty() const {
    return not front_node;
  }

  int size() const {
    return front_node ? 0 : back_node->depth - front_node->depth + 1;
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

