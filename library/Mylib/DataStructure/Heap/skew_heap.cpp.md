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


# :heavy_check_mark: Skew heap

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#f151d59e79c7ff7f731ff52cf9b782e4">Mylib/DataStructure/Heap</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/Heap/skew_heap.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/2559/main.skew_heap.test.cpp.html">test/aoj/2559/main.skew_heap.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <functional>
#include <utility>

/**
 * @title Skew heap
 * @docs skew_heap.md
 */
template <typename T, class Compare = std::less<T>>
class SkewHeap{
  struct node{
    T val;
    node *left, *right;
    int size;
    node(const T &val): val(val), left(nullptr), right(nullptr), size(1){}
  };

  node *root;
  Compare compare;

public:
  SkewHeap(): root(nullptr), compare(Compare()){}
  SkewHeap(const Compare &compare): root(nullptr), compare(compare){}

protected:
  node* meld(node *a, node *b){
    if(!a) return b;
    if(!b) return a;

    if(compare(a->val, b->val)) std::swap(a, b);

    a->size += b->size;
    a->right = meld(a->right, b);
    std::swap(a->left, a->right);

    return a;
  }

public:
  void meld(SkewHeap &heap){root = meld(root, heap.root); heap.root = nullptr;}
  void push(const T &val){root = meld(root, new node(val));}
  const T& top() const {return root->val;}
  void pop(){node *temp = root; root = meld(root->left, root->right); delete temp;}
  bool empty() const {return root == nullptr;}
  size_t size() const {return root ? root->size : 0;}
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DataStructure/Heap/skew_heap.cpp"
#include <functional>
#include <utility>

/**
 * @title Skew heap
 * @docs skew_heap.md
 */
template <typename T, class Compare = std::less<T>>
class SkewHeap{
  struct node{
    T val;
    node *left, *right;
    int size;
    node(const T &val): val(val), left(nullptr), right(nullptr), size(1){}
  };

  node *root;
  Compare compare;

public:
  SkewHeap(): root(nullptr), compare(Compare()){}
  SkewHeap(const Compare &compare): root(nullptr), compare(compare){}

protected:
  node* meld(node *a, node *b){
    if(!a) return b;
    if(!b) return a;

    if(compare(a->val, b->val)) std::swap(a, b);

    a->size += b->size;
    a->right = meld(a->right, b);
    std::swap(a->left, a->right);

    return a;
  }

public:
  void meld(SkewHeap &heap){root = meld(root, heap.root); heap.root = nullptr;}
  void push(const T &val){root = meld(root, new node(val));}
  const T& top() const {return root->val;}
  void pop(){node *temp = root; root = meld(root->left, root->right); delete temp;}
  bool empty() const {return root == nullptr;}
  size_t size() const {return root ? root->size : 0;}
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

