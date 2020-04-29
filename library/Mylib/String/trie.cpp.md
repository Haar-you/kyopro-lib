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


# :warning: Trie木

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#d75653ebf9facf6e669959c8c0d9cbcf">Mylib/String</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/String/trie.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-29 22:35:52+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <string>
#include <vector>

/**
 * @title Trie木
 * @docs trie.md
 */
template <typename T>
class Trie{
  constexpr static int CHAR_MAX = 128;
  int table[CHAR_MAX];
  int N;
  
  struct node{
    T val;
    std::vector<node*> ch;
    
    node(int N): val(0), ch(N){}
  };

public:
  Trie(const std::string &s): N(s.size()){
    for(int i = 0; i < CHAR_MAX; ++i) table[i] = -1;
    for(int i = 0; i < (int)s.size(); ++i){
      table[(int)s[i]] = i;
    }
  }

  node *root = nullptr;
  
  node* insert(node *t, const std::string &s, const T &val, int i = 0){
    if(!t) t = new node(N);

    if(i >= (int)s.size()){
      t->val = val;
      return t;
    }

    int c = table[(int)s[i]];
    t->ch[c] = insert(t->ch[c], s, val, i+1);

    return t;
  }
  
  void insert(const std::string &s, const T &val){
    root = insert(root, s, val, 0);
  }

  node* find(node *t, char c){
    if(!t) return t;
    return t->ch[table[(int)c]];
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/String/trie.cpp"
#include <string>
#include <vector>

/**
 * @title Trie木
 * @docs trie.md
 */
template <typename T>
class Trie{
  constexpr static int CHAR_MAX = 128;
  int table[CHAR_MAX];
  int N;
  
  struct node{
    T val;
    std::vector<node*> ch;
    
    node(int N): val(0), ch(N){}
  };

public:
  Trie(const std::string &s): N(s.size()){
    for(int i = 0; i < CHAR_MAX; ++i) table[i] = -1;
    for(int i = 0; i < (int)s.size(); ++i){
      table[(int)s[i]] = i;
    }
  }

  node *root = nullptr;
  
  node* insert(node *t, const std::string &s, const T &val, int i = 0){
    if(!t) t = new node(N);

    if(i >= (int)s.size()){
      t->val = val;
      return t;
    }

    int c = table[(int)s[i]];
    t->ch[c] = insert(t->ch[c], s, val, i+1);

    return t;
  }
  
  void insert(const std::string &s, const T &val){
    root = insert(root, s, val, 0);
  }

  node* find(node *t, char c){
    if(!t) return t;
    return t->ch[table[(int)c]];
  }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

