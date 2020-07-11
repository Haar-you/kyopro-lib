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


# :heavy_check_mark: test/aoj/ALDS1_5_D/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#9a3b4a53b7b2b8e6ef2197e51a686fad">test/aoj/ALDS1_5_D</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/ALDS1_5_D/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-04 06:04:41+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D</a>


## Depends on

* :question: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Misc/inversion_number.cpp.html">Inversion number</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D"

#include <iostream>
#include <vector>
#include <functional>
#include "Mylib/Misc/inversion_number.cpp"
#include "Mylib/IO/input_vector.cpp"

int main(){
  int n; std::cin >> n;

  auto a = input_vector<int>(n);
  
  auto ans = inversion_number::solve(a, std::greater<int>());
  std::cout << ans << std::endl;
  
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/ALDS1_5_D/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D"

#include <iostream>
#include <vector>
#include <functional>
#line 3 "Mylib/Misc/inversion_number.cpp"

/**
 * @title Inversion number
 * @docs inversion_number.md
 */
namespace inversion_number{
  template <typename T, typename Compare>
  int64_t rec(std::vector<T> &a, const Compare &compare){
    int n = a.size();
    if(n <= 1) return 0;
    
    int64_t ret = 0;
    
    std::vector<T> b(a.begin(), a.begin() + n/2);
    std::vector<T> c(a.begin() + n/2, a.end());
    
    ret += rec(b, compare);
    ret += rec(c, compare);
    
    int ai = 0, bi = 0, ci = 0;
    
    while(ai < n){
      if(bi < (int)b.size() and (ci == (int)c.size() or not compare(b[bi], c[ci]))){
        a[ai] = b[bi];
        ++bi;
      }else{
        ret += n/2 - bi;
        a[ai] = c[ci];
        ++ci;
      }
      ++ai;
    }
  
    return ret;
  }
    
  template <typename T, typename Compare>
  int64_t solve(std::vector<T> a, const Compare &compare){
    return rec(a, compare);
  }
}
#line 4 "Mylib/IO/input_vector.cpp"

/**
 * @docs input_vector.md
 */
template <typename T>
std::vector<T> input_vector(int N){
  std::vector<T> ret(N);
  for(int i = 0; i < N; ++i) std::cin >> ret[i];
  return ret;
}

template <typename T>
std::vector<std::vector<T>> input_vector(int N, int M){
  std::vector<std::vector<T>> ret(N);
  for(int i = 0; i < N; ++i) ret[i] = input_vector<T>(M);
  return ret;
}
#line 8 "test/aoj/ALDS1_5_D/main.test.cpp"

int main(){
  int n; std::cin >> n;

  auto a = input_vector<int>(n);
  
  auto ans = inversion_number::solve(a, std::greater<int>());
  std::cout << ans << std::endl;
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

