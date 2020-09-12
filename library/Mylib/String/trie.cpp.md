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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: Trie

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#d75653ebf9facf6e669959c8c0d9cbcf">Mylib/String</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/String/trie.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Operations

## Requirements

## Notes

## Problems

- [C - たんごたくさん](https://atcoder.jp/contests/tenka1-2016-final-open/tasks/tenka1_2016_final_c)
- [Codeforces Round #542 (Div. 1) C. Morse Code](https://codeforces.com/contest/1129/problem/C)
- [dna - DNAの合成 (DNA Synthesizer)](https://atcoder.jp/contests/joisc2010/tasks/joisc2010_dna)
- [E - 宝くじ](https://atcoder.jp/contests/utpc2014/tasks/utpc2014_e)

## References



## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <string>
#include <vector>
#include <map>

/**
 * @title Trie
 * @docs trie.md
 */
namespace haar_lib {
  template <typename T>
  struct trie_node {
    std::map<char, trie_node*> children;
    T val;

  public:
    trie_node(){}
    trie_node(T val): val(val){}

    const T& value() const {return val;}
    T& value(){return val;}

    trie_node* insert(char c, const T &v){
      if(children.find(c) != children.end()){
        children[c]->val = v;
      }else{
        children[c] = new trie_node<T>(v);
      }

      return children[c];
    }

    template <typename Iter>
    trie_node* insert(Iter first, Iter last, const T &v){
      if(first == last){
        val = v;
        return this;
      }else{
        const auto c = *first;
        if(children.find(c) == children.end()){
          children[c] = new trie_node(T());
        }

        return children[c]->insert(first + 1, last, v);
      }
    }

    trie_node* find(char c){
      if(children.find(c) != children.end()) return children[c];
      else return nullptr;
    }
  };

  template <typename T>
  struct trie {
    using node = trie_node<T>;

    node *root;

    trie(){
      root = new node(T());
    }

    template <typename Iter>
    node* insert(Iter first, Iter last, const T &v){
      return root->insert(first, last, v);
    }
  };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/String/trie.cpp"
#include <string>
#include <vector>
#include <map>

/**
 * @title Trie
 * @docs trie.md
 */
namespace haar_lib {
  template <typename T>
  struct trie_node {
    std::map<char, trie_node*> children;
    T val;

  public:
    trie_node(){}
    trie_node(T val): val(val){}

    const T& value() const {return val;}
    T& value(){return val;}

    trie_node* insert(char c, const T &v){
      if(children.find(c) != children.end()){
        children[c]->val = v;
      }else{
        children[c] = new trie_node<T>(v);
      }

      return children[c];
    }

    template <typename Iter>
    trie_node* insert(Iter first, Iter last, const T &v){
      if(first == last){
        val = v;
        return this;
      }else{
        const auto c = *first;
        if(children.find(c) == children.end()){
          children[c] = new trie_node(T());
        }

        return children[c]->insert(first + 1, last, v);
      }
    }

    trie_node* find(char c){
      if(children.find(c) != children.end()) return children[c];
      else return nullptr;
    }
  };

  template <typename T>
  struct trie {
    using node = trie_node<T>;

    node *root;

    trie(){
      root = new node(T());
    }

    template <typename Iter>
    node* insert(Iter first, Iter last, const T &v){
      return root->insert(first, last, v);
    }
  };
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

