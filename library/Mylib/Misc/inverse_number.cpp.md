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


# :x: 転倒数

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#3aaad417c82174440088b5eea559262a">Mylib/Misc</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Misc/inverse_number.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




## Verified with

* :x: <a href="../../../verify/test/aoj/ALDS1_5_D/main.test.cpp.html">test/aoj/ALDS1_5_D/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>

/**
 * @title 転倒数
 * @docs inverse_number.md
 */
namespace inverse_number{
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Misc/inverse_number.cpp"
#include <vector>

/**
 * @title 転倒数
 * @docs inverse_number.md
 */
namespace inverse_number{
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

