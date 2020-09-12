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


# :x: Knuth-Morris-Pratt algorithm

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#d75653ebf9facf6e669959c8c0d9cbcf">Mylib/String</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/String/knuth_morris_pratt.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Operations

## Requirements

## Notes

## Problems

## References

- [https://ja.wikipedia.org/wiki/クヌース–モリス–プラット法](https://ja.wikipedia.org/wiki/%E3%82%AF%E3%83%8C%E3%83%BC%E3%82%B9%E2%80%93%E3%83%A2%E3%83%AA%E3%82%B9%E2%80%93%E3%83%97%E3%83%A9%E3%83%83%E3%83%88%E6%B3%95)


## Verified with

* :x: <a href="../../../verify/test/aoj/ALDS1_14_B/main.kmp.test.cpp.html">test/aoj/ALDS1_14_B/main.kmp.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <string>
#include <string_view>

/**
 * @title Knuth-Morris-Pratt algorithm
 * @docs knuth_morris_pratt.md
 */
namespace haar_lib {
  struct knuth_morris_pratt {
    int M;
    std::string pattern;
    std::vector<int> table;

    knuth_morris_pratt(std::string p): M(p.size()), pattern(p), table(M + 1){
      table[0] = -1;
      table[1] = 0;

      pattern.push_back('\0');

      for(int i = 2, j = 0; i <= M;){
        if(pattern[i - 1] == pattern[j]){
          table[i] = j + 1;
          ++i;
          ++j;
        }else if(j > 0){
          j = table[j];
        }else{
          table[i] = 0;
          ++i;
        }
      }
    }

    std::vector<int> match(const std::string_view &s) const {
      std::vector<int> ret;
      const int N = s.size();

      for(int m = 0, i = 0; m + i < N;){
        if(pattern[i] == s[m + i]){
          ++i;
          if(i == M){
            ret.push_back(m);
            m += i - table[i];
            if(i > 0) i = table[i];
          }
        }else{
          m += i - table[i];
          if(i > 0) i = table[i];
        }
      }

      return ret;
    }
  };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/String/knuth_morris_pratt.cpp"
#include <vector>
#include <string>
#include <string_view>

/**
 * @title Knuth-Morris-Pratt algorithm
 * @docs knuth_morris_pratt.md
 */
namespace haar_lib {
  struct knuth_morris_pratt {
    int M;
    std::string pattern;
    std::vector<int> table;

    knuth_morris_pratt(std::string p): M(p.size()), pattern(p), table(M + 1){
      table[0] = -1;
      table[1] = 0;

      pattern.push_back('\0');

      for(int i = 2, j = 0; i <= M;){
        if(pattern[i - 1] == pattern[j]){
          table[i] = j + 1;
          ++i;
          ++j;
        }else if(j > 0){
          j = table[j];
        }else{
          table[i] = 0;
          ++i;
        }
      }
    }

    std::vector<int> match(const std::string_view &s) const {
      std::vector<int> ret;
      const int N = s.size();

      for(int m = 0, i = 0; m + i < N;){
        if(pattern[i] == s[m + i]){
          ++i;
          if(i == M){
            ret.push_back(m);
            m += i - table[i];
            if(i > 0) i = table[i];
          }
        }else{
          m += i - table[i];
          if(i > 0) i = table[i];
        }
      }

      return ret;
    }
  };
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

