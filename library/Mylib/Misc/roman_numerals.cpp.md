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


# :warning: Roman numerals

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#3aaad417c82174440088b5eea559262a">Mylib/Misc</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Misc/roman_numerals.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 17:46:14+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <string>

/**
 * @title Roman numerals
 * @docs roman_numerals.md
 */
namespace haar_lib::misn {
  int roman_to_num(std::string s){
    int ret = 0;

    for(int i = 0; i < (int)s.size(); ++i){
      switch(s[i]){
      case 'I': {
        if(i + 1 < (int)s.size() and (s[i + 1] == 'V' or s[i + 1] == 'X')){
          ret -= 1;
        }else{
          ret += 1;
        }
        break;
      }

      case 'V': ret += 5; break;

      case 'X': {
        if(i + 1 < (int)s.size() and (s[i + 1] == 'L' or s[i + 1] == 'C')){
          ret -= 10;
        }else{
          ret += 10;
        }
        break;
      }

      case 'L': ret += 50; break;

      case 'C': {
        if(i + 1 < (int)s.size() and (s[i + 1] == 'D' or s[i + 1] == 'M')){
          ret -= 100;
        }else{
          ret += 100;
        }
        break;
      }

      case 'D': ret += 500; break;

      case 'M': ret += 1000; break;
      }
    }

    return ret;
  }

  std::string num_to_roman(int n){
    std::string ret = "";

    if(n >= 1000){
      int k = n / 1000;
      ret += std::string(k, 'M');
      n %= 1000;
    }

    if(n >= 100){
      int k = n / 100;
      if(k <= 3) ret += std::string(k, 'C');
      else if(k == 4) ret += "CD";
      else if(k <= 8) ret += "D" + std::string(k - 5, 'C');
      else ret += "CM";

      n %= 100;
    }

    if(n >= 10){
      int k = n / 10;
      if(k <= 3) ret += std::string(k, 'X');
      else if(k == 4) ret += "XL";
      else if(k <= 8) ret += "L" + std::string(k - 5, 'X');
      else ret += "XC";

      n %= 10;
    }

    int k = n;
    if(k <= 3) ret += std::string(k, 'I');
    else if(k == 4) ret += "IV";
    else if(k <= 8) ret += "V" + std::string(k - 5, 'I');
    else ret += "IX";

    return ret;
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Misc/roman_numerals.cpp"
#include <string>

/**
 * @title Roman numerals
 * @docs roman_numerals.md
 */
namespace haar_lib::misn {
  int roman_to_num(std::string s){
    int ret = 0;

    for(int i = 0; i < (int)s.size(); ++i){
      switch(s[i]){
      case 'I': {
        if(i + 1 < (int)s.size() and (s[i + 1] == 'V' or s[i + 1] == 'X')){
          ret -= 1;
        }else{
          ret += 1;
        }
        break;
      }

      case 'V': ret += 5; break;

      case 'X': {
        if(i + 1 < (int)s.size() and (s[i + 1] == 'L' or s[i + 1] == 'C')){
          ret -= 10;
        }else{
          ret += 10;
        }
        break;
      }

      case 'L': ret += 50; break;

      case 'C': {
        if(i + 1 < (int)s.size() and (s[i + 1] == 'D' or s[i + 1] == 'M')){
          ret -= 100;
        }else{
          ret += 100;
        }
        break;
      }

      case 'D': ret += 500; break;

      case 'M': ret += 1000; break;
      }
    }

    return ret;
  }

  std::string num_to_roman(int n){
    std::string ret = "";

    if(n >= 1000){
      int k = n / 1000;
      ret += std::string(k, 'M');
      n %= 1000;
    }

    if(n >= 100){
      int k = n / 100;
      if(k <= 3) ret += std::string(k, 'C');
      else if(k == 4) ret += "CD";
      else if(k <= 8) ret += "D" + std::string(k - 5, 'C');
      else ret += "CM";

      n %= 100;
    }

    if(n >= 10){
      int k = n / 10;
      if(k <= 3) ret += std::string(k, 'X');
      else if(k == 4) ret += "XL";
      else if(k <= 8) ret += "L" + std::string(k - 5, 'X');
      else ret += "XC";

      n %= 10;
    }

    int k = n;
    if(k <= 3) ret += std::string(k, 'I');
    else if(k == 4) ret += "IV";
    else if(k <= 8) ret += "V" + std::string(k - 5, 'I');
    else ret += "IX";

    return ret;
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

