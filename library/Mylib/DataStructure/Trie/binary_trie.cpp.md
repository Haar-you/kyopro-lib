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


# :warning: Binary trie

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#aacfe2e228752c2f7bc46438cb1a6bd5">Mylib/DataStructure/Trie</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/Trie/binary_trie.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Operations

## Requirements

## Notes

## Problems

- [第5回 ドワンゴからの挑戦状 本選 B - XOR Spread](https://beta.atcoder.jp/contests/dwacon5th-final-open/tasks/dwacon5th_final_b)

## References

- [https://kazuma8128.hatenablog.com/entry/2018/05/06/022654](https://kazuma8128.hatenablog.com/entry/2018/05/06/022654)


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>

/**
 * @title Binary trie
 * @docs binary_trie.md
 */
template <typename T, unsigned int B> class BinaryTrie{
protected:
  struct node{
    int count;
    node *ch[2];
    node(): count(0){
      ch[0] = ch[1] = nullptr;
    }
  };

  node *root = nullptr;

protected:
  int count(node *t) const {return t ? t->count : 0;}

public:
  int size() const {return root ? root->count : 0;}
  bool empty() const {return !root;}

protected:
  void to_list(node *t, const T val, std::vector<T> &ret) const {
    if(!t) return;
    if(!t->ch[0] && !t->ch[1]) ret.push_back(val);

    if(t->ch[0]) to_list(t->ch[0], val<<1, ret);
    if(t->ch[1]) to_list(t->ch[1], (val<<1)|1, ret);
  }

public:
  std::vector<T> to_list() const {
    std::vector<T> ret;
    to_list(root, 0, ret);
    return ret;
  }

protected:
  node* insert(node *t, const T &val, unsigned int depth = 1){
    if(!t) t = new node();
    ++(t->count);

    if(depth > B) return t;

    int b = (val >> (B-depth)) & 1;
    t->ch[b] = insert(t->ch[b], val, depth+1);
    return t;
  }
  
public:
  void insert(const T &val){
    root = insert(root, val);
  }
  
protected:
  node* erase(node *t, const T &val, unsigned int depth = 1){
    if(!t) return t;

    --(t->count);
    if(t->count == 0) return nullptr;
    if(depth > B) return t;

    int b = (val >> (B-depth)) & 1;
    t->ch[b] = erase(t->ch[b], val, depth+1);
    return t;
  }
  
public:
  void erase(const T &val){
    root = erase(root, val);
  }

protected:
  T min_element(node *t, const T &diff, unsigned int depth = 1) const {
    if(depth > B) return 0;
    int b = (diff >> (B-depth)) & 1;
    b ^= !t->ch[b];
    return min_element(t->ch[b], diff, depth+1) | (b << (B-depth));
  }
  
public:
  T min_element(const T &diff = 0) const {
    return min_element(root, diff);
  }

protected:
  T max_element(node *t, const T &diff, unsigned int depth = 1) const {
    if(depth > B) return 0;
    int b = !((diff >> (B-depth)) & 1);
    b ^= !t->ch[b];
    return max_element(t->ch[b], diff, depth+1) | (b << (B-depth));
  }
  
public:
  T max_element(const T &diff = 0) const {
    return max_element(root, diff);
  }

protected:
  T at(node *t, int index, unsigned int depth = 1) const {
    if(depth > B) return 0;

    int c = count(t->ch[0]);
    if(t->ch[0] && index < c) return at(t->ch[0], index, depth+1);
    else return at(t->ch[1], index-c, depth+1) | ((T)1 << (B-depth));
  }

public:
  T at(int index) const {
    return at(root, index);
  }

  T operator[](int index) const {
    return at(index);
  }


protected:
  int lower_bound(node *t, const T &val, unsigned int depth = 1) const {
    if(!t) return 0;

    int b = (val >> (B-depth)) & 1;

    return (b ? count(t->ch[0]) : 0) + lower_bound(t->ch[b], val, depth+1);
  }

public:
  int lower_bound(const T &val) const {
    return lower_bound(root, val);
  }

  int upper_bound(const T &val) const{
    return lower_bound(root, val+1);
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DataStructure/Trie/binary_trie.cpp"
#include <vector>

/**
 * @title Binary trie
 * @docs binary_trie.md
 */
template <typename T, unsigned int B> class BinaryTrie{
protected:
  struct node{
    int count;
    node *ch[2];
    node(): count(0){
      ch[0] = ch[1] = nullptr;
    }
  };

  node *root = nullptr;

protected:
  int count(node *t) const {return t ? t->count : 0;}

public:
  int size() const {return root ? root->count : 0;}
  bool empty() const {return !root;}

protected:
  void to_list(node *t, const T val, std::vector<T> &ret) const {
    if(!t) return;
    if(!t->ch[0] && !t->ch[1]) ret.push_back(val);

    if(t->ch[0]) to_list(t->ch[0], val<<1, ret);
    if(t->ch[1]) to_list(t->ch[1], (val<<1)|1, ret);
  }

public:
  std::vector<T> to_list() const {
    std::vector<T> ret;
    to_list(root, 0, ret);
    return ret;
  }

protected:
  node* insert(node *t, const T &val, unsigned int depth = 1){
    if(!t) t = new node();
    ++(t->count);

    if(depth > B) return t;

    int b = (val >> (B-depth)) & 1;
    t->ch[b] = insert(t->ch[b], val, depth+1);
    return t;
  }
  
public:
  void insert(const T &val){
    root = insert(root, val);
  }
  
protected:
  node* erase(node *t, const T &val, unsigned int depth = 1){
    if(!t) return t;

    --(t->count);
    if(t->count == 0) return nullptr;
    if(depth > B) return t;

    int b = (val >> (B-depth)) & 1;
    t->ch[b] = erase(t->ch[b], val, depth+1);
    return t;
  }
  
public:
  void erase(const T &val){
    root = erase(root, val);
  }

protected:
  T min_element(node *t, const T &diff, unsigned int depth = 1) const {
    if(depth > B) return 0;
    int b = (diff >> (B-depth)) & 1;
    b ^= !t->ch[b];
    return min_element(t->ch[b], diff, depth+1) | (b << (B-depth));
  }
  
public:
  T min_element(const T &diff = 0) const {
    return min_element(root, diff);
  }

protected:
  T max_element(node *t, const T &diff, unsigned int depth = 1) const {
    if(depth > B) return 0;
    int b = !((diff >> (B-depth)) & 1);
    b ^= !t->ch[b];
    return max_element(t->ch[b], diff, depth+1) | (b << (B-depth));
  }
  
public:
  T max_element(const T &diff = 0) const {
    return max_element(root, diff);
  }

protected:
  T at(node *t, int index, unsigned int depth = 1) const {
    if(depth > B) return 0;

    int c = count(t->ch[0]);
    if(t->ch[0] && index < c) return at(t->ch[0], index, depth+1);
    else return at(t->ch[1], index-c, depth+1) | ((T)1 << (B-depth));
  }

public:
  T at(int index) const {
    return at(root, index);
  }

  T operator[](int index) const {
    return at(index);
  }


protected:
  int lower_bound(node *t, const T &val, unsigned int depth = 1) const {
    if(!t) return 0;

    int b = (val >> (B-depth)) & 1;

    return (b ? count(t->ch[0]) : 0) + lower_bound(t->ch[b], val, depth+1);
  }

public:
  int lower_bound(const T &val) const {
    return lower_bound(root, val);
  }

  int upper_bound(const T &val) const{
    return lower_bound(root, val+1);
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

