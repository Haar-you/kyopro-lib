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


# :x: Inversion number

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#ebf5673f586fe469e71716464f05c5ea">Mylib/Algorithm/InversionNumber</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Algorithm/InversionNumber/inversion_number.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 17:46:14+09:00




## Verified with

* :x: <a href="../../../../verify/test/aoj/ALDS1_5_D/main.test.cpp.html">test/aoj/ALDS1_5_D/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <cstdint>

/**
 * @title Inversion number
 * @docs inversion_number.md
 */
namespace haar_lib {
  namespace inversion_number_impl {
    template <typename T, typename Compare>
    int64_t rec(std::vector<T> &a, const Compare &compare){
      const int n = a.size();
      if(n <= 1) return 0;

      int64_t ret = 0;

      std::vector<T> b(a.begin(), a.begin() + n / 2);
      std::vector<T> c(a.begin() + n / 2, a.end());

      ret += rec(b, compare);
      ret += rec(c, compare);

      int ai = 0, bi = 0, ci = 0;

      while(ai < n){
        if(bi < (int)b.size() and (ci == (int)c.size() or not compare(b[bi], c[ci]))){
          a[ai] = b[bi];
          ++bi;
        }else{
          ret += n / 2 - bi;
          a[ai] = c[ci];
          ++ci;
        }
        ++ai;
      }

      return ret;
    }
  }

  template <typename T, typename Compare>
  int64_t inversion_number(std::vector<T> a, const Compare &compare){
    return inversion_number_impl::rec(a, compare);
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Algorithm/InversionNumber/inversion_number.cpp"
#include <vector>
#include <cstdint>

/**
 * @title Inversion number
 * @docs inversion_number.md
 */
namespace haar_lib {
  namespace inversion_number_impl {
    template <typename T, typename Compare>
    int64_t rec(std::vector<T> &a, const Compare &compare){
      const int n = a.size();
      if(n <= 1) return 0;

      int64_t ret = 0;

      std::vector<T> b(a.begin(), a.begin() + n / 2);
      std::vector<T> c(a.begin() + n / 2, a.end());

      ret += rec(b, compare);
      ret += rec(c, compare);

      int ai = 0, bi = 0, ci = 0;

      while(ai < n){
        if(bi < (int)b.size() and (ci == (int)c.size() or not compare(b[bi], c[ci]))){
          a[ai] = b[bi];
          ++bi;
        }else{
          ret += n / 2 - bi;
          a[ai] = c[ci];
          ++ci;
        }
        ++ai;
      }

      return ret;
    }
  }

  template <typename T, typename Compare>
  int64_t inversion_number(std::vector<T> a, const Compare &compare){
    return inversion_number_impl::rec(a, compare);
  }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

