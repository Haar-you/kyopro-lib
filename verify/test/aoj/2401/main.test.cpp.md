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


# :heavy_check_mark: test/aoj/2401/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#1d3efd405c3cf87c1a3243dd8aba3849">test/aoj/2401</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/2401/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2401">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2401</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Parser/parser.cpp.html">Parsing</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2401"

#include <iostream>
#include <string>
#include "Mylib/Parser/parser.cpp"

namespace hl = haar_lib;

struct parser : hl::parser {
  parser(const std::string &s): hl::parser(s){}

  bool constant(){
    bool ret = check('T');
    ignore();
    return ret;
  }

  bool negate(){
    ignore('-');
    return !expression();
  }

  std::string get_op(){
    if(check_and_ignore('*')) return "*";
    if(check_and_ignore('+')) return "+";
    ignore("->"); return "->";
  }

  bool term(){
    ignore('(');
    bool left = expression();
    auto op = get_op();
    bool right = expression();
    ignore(')');

    if(op == "*") return left && right;
    else if(op == "+") return left || right;
    else return !left || right;
  }

  bool expression(){
    if(check('(')) return term();
    if(check('-')) return negate();
    return constant();
  }

  bool run(){
    bool left = expression();
    ignore('=');
    bool right = expression();
    return left == right;
  }
};

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  std::string s;
  while(std::cin >> s){
    if(s == "#") break;

    bool ans = true;

    for(int i = 0; i < 1 << 11; ++i){
      std::string t(s);

      for(auto &ch : t){
        if(ch >= 'a' and ch <= 'k'){
          ch = i & (1 << (ch-'a')) ? 'T' : 'F';
        }
      }

      ans = ans and parser(t).run();
    }

    std::cout << (ans ? "YES" : "NO") << "\n";
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/2401/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2401"

#include <iostream>
#include <string>
#line 3 "Mylib/Parser/parser.cpp"
#include <cassert>

/**
 * @title Parsing
 * @docs parser.md
 */
namespace haar_lib {
  struct parser {
    using state = std::string::const_iterator;

    state cur, first, last;

    parser(){}
    parser(const std::string &s): cur(s.cbegin()), first(s.cbegin()), last(s.cend()){}

    char peek() const {return *cur;}

    bool check(char c) const {
      return *cur == c;
    }

    bool check(const std::string &s) const {
      state temp = cur;
      for(auto c : s){
        if(c != *temp) return false;
        ++temp;
      }
      return true;
    }

    void ignore(char c){
      assert(*cur == c);
      ++cur;
    }

    void ignore(){
      ++cur;
    }

    void ignore(const std::string &s){
      for(auto c : s){
        assert(*cur == c);
        ++cur;
      }
    }

    template <class Checker>
    void ignore_if(const Checker &f){
      assert(f(*cur));
      ++cur;
    }

    bool check_and_ignore(char c){
      if(*cur != c) return false;
      ++cur;
      return true;
    }

    bool end() const {return cur == last;}
    bool digit() const {return isdigit(*cur);}
    bool alpha() const {return isalpha(*cur);}
    bool lower() const {return islower(*cur);}
    bool upper() const {return isupper(*cur);}

    char get_char(){
      return *(cur++);
    }

    int get_digit(){
      return (int)(*(cur++) - '0');
    }

    template <typename Checker>
    auto get_string(const Checker &f){
      std::string ret;
      while(f(peek())){
        ret += peek();
        ignore();
      }
      return ret;
    }

    auto get_string_alpha(){
      std::string ret;
      while(isalpha(*cur)){
        ret += *cur;
        ++cur;
      }
      return ret;
    }

    auto get_string_alnum(){
      std::string ret;
      while(isalnum(*cur)){
        ret += *cur;
        ++cur;
      }
      return ret;
    }

    template <typename T>
    T get_number(){
      T ret = get_digit();
      while(digit()){
        (ret *= 10) += (T)(get_digit());
      }
      return ret;
    }
  };
}
#line 6 "test/aoj/2401/main.test.cpp"

namespace hl = haar_lib;

struct parser : hl::parser {
  parser(const std::string &s): hl::parser(s){}

  bool constant(){
    bool ret = check('T');
    ignore();
    return ret;
  }

  bool negate(){
    ignore('-');
    return !expression();
  }

  std::string get_op(){
    if(check_and_ignore('*')) return "*";
    if(check_and_ignore('+')) return "+";
    ignore("->"); return "->";
  }

  bool term(){
    ignore('(');
    bool left = expression();
    auto op = get_op();
    bool right = expression();
    ignore(')');

    if(op == "*") return left && right;
    else if(op == "+") return left || right;
    else return !left || right;
  }

  bool expression(){
    if(check('(')) return term();
    if(check('-')) return negate();
    return constant();
  }

  bool run(){
    bool left = expression();
    ignore('=');
    bool right = expression();
    return left == right;
  }
};

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  std::string s;
  while(std::cin >> s){
    if(s == "#") break;

    bool ans = true;

    for(int i = 0; i < 1 << 11; ++i){
      std::string t(s);

      for(auto &ch : t){
        if(ch >= 'a' and ch <= 'k'){
          ch = i & (1 << (ch-'a')) ? 'T' : 'F';
        }
      }

      ans = ans and parser(t).run();
    }

    std::cout << (ans ? "YES" : "NO") << "\n";
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

