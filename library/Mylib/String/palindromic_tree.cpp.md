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


# :warning: 回文木

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#d75653ebf9facf6e669959c8c0d9cbcf">Mylib/String</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/String/palindromic_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-03 01:42:28+09:00


* see: <a href="https://www.spoj.com/problems/LPS/ (最長回文部分列)">https://www.spoj.com/problems/LPS/ (最長回文部分列)</a>
* see: <a href="https://www.spoj.com/problems/NUMOFPAL/ (回文部分列の個数)">https://www.spoj.com/problems/NUMOFPAL/ (回文部分列の個数)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <map>
#include <string>
#include <algorithm>

/**
 * @title 回文木
 * @see https://www.spoj.com/problems/LPS/ (最長回文部分列)
 * @see https://www.spoj.com/problems/NUMOFPAL/ (回文部分列の個数)
 */
class PalindromicTree{
  struct node{
    int length;
    int count;
    std::map<char, node*> children;
    node *suffix_link;
    std::vector<node*> reverse_suffix_links;
  };
  
  node *even_root, *odd_root;
  int size_ = 2;

public:
  PalindromicTree(const std::string &s){
    even_root = new node();
    even_root->length = 0;

    odd_root = new node();
    odd_root->length = -1;

    even_root->suffix_link = odd_root;
    odd_root->reverse_suffix_links.emplace_back(even_root);
    
    node *cur = odd_root;

    const int N = s.size();
    
    for(int i = 0; i < N; ++i){
      node *t = cur;

      while(1){
        if(i - t->length - 1 >= 0 and s[i] == s[i - t->length - 1]){
          if(t->children.find(s[i]) == t->children.end()){
            node *a = new node();
            a->length = t->length + 2;
            a->count = 1;
            t->children[s[i]] = a;
            ++size_;
          }else{
            t->children[s[i]]->count += 1;
          }
          break;
        }else{
          t = t->suffix_link;
        }
      }

      node *next = t->children[s[i]];

      if(!next->suffix_link){
        if(next->length == 1){
          next->suffix_link = even_root;
          even_root->reverse_suffix_links.emplace_back(next);
        }else{
          node *p = cur;

          while(1){
            if(p != t){
              if(i - p->length - 1 >= 0 and s[i] == s[i - p->length - 1]){
                next->suffix_link = p->children[s[i]];
                p->children[s[i]]->reverse_suffix_links.emplace_back(next);
                break;
              }else{
                p = p->suffix_link;
              }
            }else{
              p = p->suffix_link;
            }
          }
        }
      }

      cur = next;
    }
  }

  int size() const {
    return size_;
  }

private:
  int longest_(node *t) const {
    int ret = t->length;
    for(auto &p : t->children) ret = std::max(ret, longest_(p.second));
    return ret;
  }

public:
  int longest() const {
    int ret = std::max(longest_(odd_root), longest_(even_root));
    return ret;
  }

private:
  int count_sub_palindromes_(node *t, int &c) const {
    int ret = t->count;

    for(auto &s : t->reverse_suffix_links){
      ret += count_sub_palindromes_(s, c);
    }

    if(t != odd_root and t != even_root) c += ret;

    return ret;
  }

public:
  int count_sub_palindromes() const {
    int ret = 0;
    count_sub_palindromes_(odd_root, ret);
    return ret;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/String/palindromic_tree.cpp"
#include <vector>
#include <map>
#include <string>
#include <algorithm>

/**
 * @title 回文木
 * @see https://www.spoj.com/problems/LPS/ (最長回文部分列)
 * @see https://www.spoj.com/problems/NUMOFPAL/ (回文部分列の個数)
 */
class PalindromicTree{
  struct node{
    int length;
    int count;
    std::map<char, node*> children;
    node *suffix_link;
    std::vector<node*> reverse_suffix_links;
  };
  
  node *even_root, *odd_root;
  int size_ = 2;

public:
  PalindromicTree(const std::string &s){
    even_root = new node();
    even_root->length = 0;

    odd_root = new node();
    odd_root->length = -1;

    even_root->suffix_link = odd_root;
    odd_root->reverse_suffix_links.emplace_back(even_root);
    
    node *cur = odd_root;

    const int N = s.size();
    
    for(int i = 0; i < N; ++i){
      node *t = cur;

      while(1){
        if(i - t->length - 1 >= 0 and s[i] == s[i - t->length - 1]){
          if(t->children.find(s[i]) == t->children.end()){
            node *a = new node();
            a->length = t->length + 2;
            a->count = 1;
            t->children[s[i]] = a;
            ++size_;
          }else{
            t->children[s[i]]->count += 1;
          }
          break;
        }else{
          t = t->suffix_link;
        }
      }

      node *next = t->children[s[i]];

      if(!next->suffix_link){
        if(next->length == 1){
          next->suffix_link = even_root;
          even_root->reverse_suffix_links.emplace_back(next);
        }else{
          node *p = cur;

          while(1){
            if(p != t){
              if(i - p->length - 1 >= 0 and s[i] == s[i - p->length - 1]){
                next->suffix_link = p->children[s[i]];
                p->children[s[i]]->reverse_suffix_links.emplace_back(next);
                break;
              }else{
                p = p->suffix_link;
              }
            }else{
              p = p->suffix_link;
            }
          }
        }
      }

      cur = next;
    }
  }

  int size() const {
    return size_;
  }

private:
  int longest_(node *t) const {
    int ret = t->length;
    for(auto &p : t->children) ret = std::max(ret, longest_(p.second));
    return ret;
  }

public:
  int longest() const {
    int ret = std::max(longest_(odd_root), longest_(even_root));
    return ret;
  }

private:
  int count_sub_palindromes_(node *t, int &c) const {
    int ret = t->count;

    for(auto &s : t->reverse_suffix_links){
      ret += count_sub_palindromes_(s, c);
    }

    if(t != odd_root and t != even_root) c += ret;

    return ret;
  }

public:
  int count_sub_palindromes() const {
    int ret = 0;
    count_sub_palindromes_(odd_root, ret);
    return ret;
  }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

