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


# :x: test/yukicoder/306/main.ternary.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#94d4e5c879e40488003ae32a119b6352">test/yukicoder/306</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yukicoder/306/main.ternary.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00


* see: <a href="https://yukicoder.me/problems/no/306">https://yukicoder.me/problems/no/306</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Algorithm/Search/ternary_search_downwards.cpp.html">Ternary search (Convex downwards)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/306"
#define ERROR 1e-6

#include <iostream>
#include <iomanip>
#include <cmath>
#include "Mylib/Algorithm/Search/ternary_search_downwards.cpp"


int main(){
  int xa, xb, ya, yb; std::cin >> xa >> ya >> xb >> yb;
  
  auto f =
    [&](long double p){
      return std::hypot(xa, ya-p) + std::hypot(xb, yb-p);
    };

  auto ans = ternary_search_downwards<long double>(-1000, 1000, f);
  
  std::cout << std::fixed << std::setprecision(12) << ans << std::endl;
  
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yukicoder/306/main.ternary.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/306"
#define ERROR 1e-6

#include <iostream>
#include <iomanip>
#include <cmath>
#line 2 "Mylib/Algorithm/Search/ternary_search_downwards.cpp"
#include <functional>

/**
 * @title Ternary search (Convex downwards)
 * @docs ternary_search_downwards.md
 */
template <typename T = double, typename Func = std::function<T(T)>>
T ternary_search_downwards(T lb, T ub, const Func &f, int LOOP_COUNT = 100){
  T t1,t2;
  
  while(LOOP_COUNT--){
    t1 = lb + (ub-lb) / 3;
    t2 = lb + (ub-lb) / 3 * 2;
    
    if(f(t1) < f(t2)){
      ub = t2;
    }else{
      lb = t1;
    }
  }
 
  return lb;
}
#line 8 "test/yukicoder/306/main.ternary.test.cpp"


int main(){
  int xa, xb, ya, yb; std::cin >> xa >> ya >> xb >> yb;
  
  auto f =
    [&](long double p){
      return std::hypot(xa, ya-p) + std::hypot(xb, yb-p);
    };

  auto ans = ternary_search_downwards<long double>(-1000, 1000, f);
  
  std::cout << std::fixed << std::setprecision(12) << ans << std::endl;
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

