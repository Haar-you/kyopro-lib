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


# :heavy_check_mark: test/yukicoder/306/main.golden.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#94d4e5c879e40488003ae32a119b6352">test/yukicoder/306</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yukicoder/306/main.golden.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00


* see: <a href="https://yukicoder.me/problems/no/306">https://yukicoder.me/problems/no/306</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Algorithm/Search/golden_section_search_downwards.cpp.html">下に凸の黄金分割探索</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/306"
#define ERROR 1e-6

#include <iostream>
#include <iomanip>
#include <cmath>
#include "Mylib/Algorithm/Search/golden_section_search_downwards.cpp"


int main(){
  int xa, xb, ya, yb; std::cin >> xa >> ya >> xb >> yb;
  
  auto f =
    [&](long double p){
      return std::hypot(xa, ya-p) + std::hypot(xb, yb-p);
    };

  auto ans = golden_section_search_downwards<long double>(-1000, 1000, f);
  
  std::cout << std::fixed << std::setprecision(12) << ans << std::endl;
  
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yukicoder/306/main.golden.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/306"
#define ERROR 1e-6

#include <iostream>
#include <iomanip>
#include <cmath>
#line 2 "Mylib/Algorithm/Search/golden_section_search_downwards.cpp"
#include <functional>
#line 4 "Mylib/Algorithm/Search/golden_section_search_downwards.cpp"

/**
 * @title 下に凸の黄金分割探索
 * @docs golden_section_search_downwards.md
 */
template <typename T = double, typename Func = std::function<T(T)>>
T golden_section_search_downwards(T lb, T ub, const Func &f, int LOOP_COUNT = 100){
  static const T phi = (1.0 + std::sqrt(5)) / 2;
  
  T t1, t2;

  while(LOOP_COUNT--){
    t1 = (lb * phi + ub) / (phi + 1.0);
    t2 = (lb + ub * phi) / (phi + 1.0);

    if(f(t1) < f(t2)){
      ub = t2;
    }else{
      lb = t1;
    }
  }

  return lb;
}
#line 8 "test/yukicoder/306/main.golden.test.cpp"


int main(){
  int xa, xb, ya, yb; std::cin >> xa >> ya >> xb >> yb;
  
  auto f =
    [&](long double p){
      return std::hypot(xa, ya-p) + std::hypot(xb, yb-p);
    };

  auto ans = golden_section_search_downwards<long double>(-1000, 1000, f);
  
  std::cout << std::fixed << std::setprecision(12) << ans << std::endl;
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

