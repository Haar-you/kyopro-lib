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


# :heavy_check_mark: Parsing

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#3137e84ecea04d2bbca689ed3c72bc37">Mylib/Parser</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Parser/parser.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/1102/main.test.cpp.html">test/aoj/1102/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/1300/main.test.cpp.html">test/aoj/1300/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2401/main.test.cpp.html">test/aoj/2401/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include <string>
#include <cassert>

/**
 * @title Parsing
 * @docs parser.md
 */
struct Parser{
  using state = std::string::const_iterator;
  
  state cur, first, last;

  Parser(){}
  Parser(const std::string &s): cur(s.cbegin()), first(s.cbegin()), last(s.cend()){}
  
  inline char peek() const {return *cur;}
  
  inline bool check(char c) const {
    return *cur == c;
  }
  
  inline bool check(const std::string &s) const {
    state temp = cur;
    for(auto c : s){
      if(c != *temp) return false;
      ++temp;
    }
    return true;
  }
  
  inline void ignore(char c){
    assert(*cur == c);
    ++cur;
  }
  
  inline void ignore(){
    ++cur;
  }
  
  inline void ignore(const std::string &s){
    for(auto c : s){
      assert(*cur == c);
      ++cur;
    }
  }
  
  template <class Checker>
  inline void ignore_if(const Checker &f){
    assert(f(*cur));
    ++cur;
  }

  inline bool check_and_ignore(char c){
    if(*cur != c) return false;
    ++cur;
    return true;
  }

  inline bool end() const {return cur == last;}
  inline bool digit() const {return isdigit(*cur);}
  inline bool alpha() const {return isalpha(*cur);}
  inline bool lower() const {return islower(*cur);}
  inline bool upper() const {return isupper(*cur);}
    
  inline char get_char(){
    return *(cur++);
  }
  
  inline int get_digit(){
    return (int)(*(cur++)-'0');
  }
  
  template <typename Checker>
  inline auto get_string(const Checker &f){
    std::string ret;
    while(f(peek())){
      ret += peek();
      ignore();
    }
    return ret;
  }
  
  inline auto get_string_alpha(){
    std::string ret;
    while(isalpha(*cur)){
      ret += *cur;
      ++cur;
    }
    return ret;
  }
  
  inline auto get_string_alnum(){
    std::string ret;
    while(isalnum(*cur)){
      ret += *cur;
      ++cur;
    }
    return ret;
  }
  
  template <typename T>
  inline T get_number(){
    T ret = get_digit();
    while(digit()){
      (ret *= 10) += (T)(get_digit());
    }
    return ret;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Parser/parser.cpp"

#include <string>
#include <cassert>

/**
 * @title Parsing
 * @docs parser.md
 */
struct Parser{
  using state = std::string::const_iterator;
  
  state cur, first, last;

  Parser(){}
  Parser(const std::string &s): cur(s.cbegin()), first(s.cbegin()), last(s.cend()){}
  
  inline char peek() const {return *cur;}
  
  inline bool check(char c) const {
    return *cur == c;
  }
  
  inline bool check(const std::string &s) const {
    state temp = cur;
    for(auto c : s){
      if(c != *temp) return false;
      ++temp;
    }
    return true;
  }
  
  inline void ignore(char c){
    assert(*cur == c);
    ++cur;
  }
  
  inline void ignore(){
    ++cur;
  }
  
  inline void ignore(const std::string &s){
    for(auto c : s){
      assert(*cur == c);
      ++cur;
    }
  }
  
  template <class Checker>
  inline void ignore_if(const Checker &f){
    assert(f(*cur));
    ++cur;
  }

  inline bool check_and_ignore(char c){
    if(*cur != c) return false;
    ++cur;
    return true;
  }

  inline bool end() const {return cur == last;}
  inline bool digit() const {return isdigit(*cur);}
  inline bool alpha() const {return isalpha(*cur);}
  inline bool lower() const {return islower(*cur);}
  inline bool upper() const {return isupper(*cur);}
    
  inline char get_char(){
    return *(cur++);
  }
  
  inline int get_digit(){
    return (int)(*(cur++)-'0');
  }
  
  template <typename Checker>
  inline auto get_string(const Checker &f){
    std::string ret;
    while(f(peek())){
      ret += peek();
      ignore();
    }
    return ret;
  }
  
  inline auto get_string_alpha(){
    std::string ret;
    while(isalpha(*cur)){
      ret += *cur;
      ++cur;
    }
    return ret;
  }
  
  inline auto get_string_alnum(){
    std::string ret;
    while(isalnum(*cur)){
      ret += *cur;
      ++cur;
    }
    return ret;
  }
  
  template <typename T>
  inline T get_number(){
    T ret = get_digit();
    while(digit()){
      (ret *= 10) += (T)(get_digit());
    }
    return ret;
  }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

