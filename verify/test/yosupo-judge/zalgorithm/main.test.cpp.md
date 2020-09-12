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


# :x: test/yosupo-judge/zalgorithm/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#cee42202ab0cff35bec3ed1b69090c0e">test/yosupo-judge/zalgorithm</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/zalgorithm/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 17:46:14+09:00


* see: <a href="https://judge.yosupo.jp/problem/zalgorithm">https://judge.yosupo.jp/problem/zalgorithm</a>


## Depends on

* :question: <a href="../../../../library/Mylib/IO/join.cpp.html">Mylib/IO/join.cpp</a>
* :x: <a href="../../../../library/Mylib/String/z_algorithm.cpp.html">Z-algorithm</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include <iostream>
#include <string>
#include "Mylib/String/z_algorithm.cpp"
#include "Mylib/IO/join.cpp"

namespace hl = haar_lib;

int main(){
  std::string s; std::cin >> s;

  auto ans = hl::z_algorithm(s);
  std::cout << hl::join(ans.begin(), ans.end()) << "\n";

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/zalgorithm/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include <iostream>
#include <string>
#line 2 "Mylib/String/z_algorithm.cpp"
#include <vector>
#include <algorithm>

/**
 * @title Z-algorithm
 * @docs z_algorithm
 */
namespace haar_lib {
  template <typename Container>
  std::vector<int> z_algorithm(const Container &s){
    const int n = s.size();
    std::vector<int> ret(n, 0);
    int j = 0;

    for(int i = 1; i < n; ++i){
      if(i + ret[i - j] < j + ret[j]){
        ret[i] = ret[i - j];
      }else{
        int k = std::max<int>(0, j + ret[j] - i);
        while(i + k < n and s[k] == s[i + k]) ++k;
        ret[i] = k;
        j = i;
      }
    }

    ret[0] = n;

    return ret;
  }
}
#line 3 "Mylib/IO/join.cpp"
#include <sstream>
#line 5 "Mylib/IO/join.cpp"

/**
 * @docs join.md
 */
namespace haar_lib {
  template <typename Iter>
  std::string join(Iter first, Iter last, std::string delim = " "){
    std::stringstream s;

    for(auto it = first; it != last; ++it){
      if(it != first) s << delim;
      s << *it;
    }

    return s.str();
  }
}
#line 7 "test/yosupo-judge/zalgorithm/main.test.cpp"

namespace hl = haar_lib;

int main(){
  std::string s; std::cin >> s;

  auto ans = hl::z_algorithm(s);
  std::cout << hl::join(ans.begin(), ans.end()) << "\n";

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

