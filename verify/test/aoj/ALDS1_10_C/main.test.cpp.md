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


# :heavy_check_mark: test/aoj/ALDS1_10_C/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#6691093001380fa1883257c26243406e">test/aoj/ALDS1_10_C</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/ALDS1_10_C/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-16 08:33:11+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/String/longest_common_subsequence.cpp.html">最長共通部分列</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C"

#include <iostream>
#include <string>
#include "Mylib/String/longest_common_subsequence.cpp"

int main(){
  int q; std::cin >> q;
  
  while(q--){
    std::string x, y; std::cin >> x >> y;
    
    auto ans = lcs(x, y);
    
    std::cout << ans << std::endl;
  }
  
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/ALDS1_10_C/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C"

#include <iostream>
#include <string>
#line 2 "Mylib/String/longest_common_subsequence.cpp"
#include <vector>
#include <algorithm>

/**
 * @title 最長共通部分列
 * @docs longest_common_subsequence.md
 */
template <typename Container, typename T = typename Container::value_type>
int lcs(const Container &a, const Container &b){
  const int n = a.size(), m = b.size();
  
  std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1, 0));
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      dp[i][j] = a[i-1] == b[j-1] ? dp[i-1][j-1] + 1 : std::max(dp[i-1][j], dp[i][j-1]);
    }
  }
    
  return dp[n][m];
}
#line 6 "test/aoj/ALDS1_10_C/main.test.cpp"

int main(){
  int q; std::cin >> q;
  
  while(q--){
    std::string x, y; std::cin >> x >> y;
    
    auto ans = lcs(x, y);
    
    std::cout << ans << std::endl;
  }
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

