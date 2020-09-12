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


# :x: test/aoj/DPL_1_E/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#ff011c241521fe723b9ada74a9467695">test/aoj/DPL_1_E</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DPL_1_E/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 17:46:14+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E</a>


## Depends on

* :x: <a href="../../../../library/Mylib/String/levenshtein_distance.cpp.html">Levenshtein distance / Edit distance</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E"

#include <iostream>
#include <string>
#include "Mylib/String/levenshtein_distance.cpp"

namespace hl = haar_lib;

int main(){
  std::string s1, s2; std::cin >> s1 >> s2;

  auto ans = hl::levenshtein_distance(s1, s2);

  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DPL_1_E/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E"

#include <iostream>
#include <string>
#line 2 "Mylib/String/levenshtein_distance.cpp"
#include <vector>
#include <algorithm>

/**
 * @title Levenshtein distance / Edit distance
 * @docs levenshtein_distance.md
 */
namespace haar_lib {
  template <typename Container, typename T = typename Container::value_type>
  int levenshtein_distance(const Container &a, const Container &b){
    const int n = a.size(), m = b.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

    for(int i = 0; i <= n; ++i) dp[i][0] = i;
    for(int i = 0; i <= m; ++i) dp[0][i] = i;

    for(int i = 0; i < n; ++i){
      for(int j = 0; j < m; ++j){
        dp[i + 1][j + 1] = std::min(dp[i][j + 1] + 1, dp[i + 1][j] + 1);

        if(a[i] == b[j]){
          dp[i + 1][j + 1] = std::min(dp[i + 1][j + 1], dp[i][j]);
        }else{
          dp[i + 1][j + 1] = std::min(dp[i + 1][j + 1], dp[i][j] + 1);
        }
      }
    }
    return dp[n][m];
  }
}
#line 6 "test/aoj/DPL_1_E/main.test.cpp"

namespace hl = haar_lib;

int main(){
  std::string s1, s2; std::cin >> s1 >> s2;

  auto ans = hl::levenshtein_distance(s1, s2);

  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
