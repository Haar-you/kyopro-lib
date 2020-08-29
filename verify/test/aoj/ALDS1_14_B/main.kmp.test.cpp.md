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


# :heavy_check_mark: test/aoj/ALDS1_14_B/main.kmp.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#6ed7f5103dd44c87e247853bfe87329e">test/aoj/ALDS1_14_B</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/ALDS1_14_B/main.kmp.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-23 16:43:16+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/String/knuth_morris_pratt.cpp.html">Knuth-Morris-Pratt algorithm</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include <iostream>
#include <string>
#include "Mylib/String/knuth_morris_pratt.cpp"

int main(){
  std::string t, p; std::cin >> t >> p;

  auto res = KMP(p).match(t);
  for(auto i : res) std::cout << i << "\n";
  
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/ALDS1_14_B/main.kmp.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include <iostream>
#include <string>
#line 2 "Mylib/String/knuth_morris_pratt.cpp"
#include <vector>
#line 4 "Mylib/String/knuth_morris_pratt.cpp"

/**
 * @title Knuth-Morris-Pratt algorithm
 * @docs knuth_morris_pratt.md
 */
struct KMP{
  int M;
  std::string pattern;
  std::vector<int> table;

  KMP(std::string p): M(p.size()), pattern(p), table(M + 1){
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

  std::vector<int> match(std::string s) const {
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
#line 6 "test/aoj/ALDS1_14_B/main.kmp.test.cpp"

int main(){
  std::string t, p; std::cin >> t >> p;

  auto res = KMP(p).match(t);
  for(auto i : res) std::cout << i << "\n";
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

