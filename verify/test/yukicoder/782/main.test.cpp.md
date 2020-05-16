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


# :x: test/yukicoder/782/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#69b51e2d143bc3bccb43628882e5cf09">test/yukicoder/782</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yukicoder/782/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-16 14:34:01+09:00


* see: <a href="https://yukicoder.me/problems/no/782">https://yukicoder.me/problems/no/782</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Misc/convert_base.cpp.html">進数変換</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/782"

#include <iostream>
#include "Mylib/Misc/convert_base.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int T, B; std::cin >> T >> B;
  while(T--){
    int N; std::cin >> N;
    auto ans = convert_base_to(N, B);
    for(auto x : ans) std::cout << x;
    std::cout << "\n";
  }
  
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yukicoder/782/main.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/782"

#include <iostream>
#line 2 "Mylib/Misc/convert_base.cpp"
#include <vector>
#include <algorithm>

/**
 * @title 進数変換
 * @docs convert_base.md
 */
std::vector<int64_t> convert_base_to(int64_t val, int64_t base){
  if(val == 0) return {0};

  int b = std::abs(base);

  std::vector<int64_t> ret;
  while(val != 0){
    int r = val % b;
    if(r < 0) r += b;
    val = (val - r) / base;
    ret.push_back(r);
  }

  std::reverse(ret.begin(), ret.end());
  
  return ret;
}

int64_t convert_base_from(const std::vector<int64_t> &val, int64_t base){
  int64_t ret = 0;
  for(auto it = val.begin(); it != val.end(); ++it){
    (ret *= base) += *it;
  }

  return ret;
}
#line 5 "test/yukicoder/782/main.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int T, B; std::cin >> T >> B;
  while(T--){
    int N; std::cin >> N;
    auto ans = convert_base_to(N, B);
    for(auto x : ans) std::cout << x;
    std::cout << "\n";
  }
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

