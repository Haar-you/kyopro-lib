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


# :x: Kitamasa algorithm

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#826136648af25fa7c5e97a1b794f9784">Mylib/DynamicProgramming/SpeedupTechnique</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DynamicProgramming/SpeedupTechnique/kitamasa_algorithm.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Operations

## Requirements

## Notes

## Problems

- [yukicoder No.214 素数サイコロと合成数サイコロ (3-Medium)](https://yukicoder.me/problems/no/214)
- [yukicoder No.658 テトラナッチ数列 Hard](https://yukicoder.me/problems/no/658)
- [TDPC T - フィボナッチ](https://atcoder.jp/contests/tdpc/tasks/tdpc_fibonacci)

## References
 
- [https://misawa.github.io/others/fast_kitamasa_method.html](https://misawa.github.io/others/fast_kitamasa_method.html)
- [https://smijake3.hatenablog.com/entry/2017/01/02/024712](https://smijake3.hatenablog.com/entry/2017/01/02/024712)
- [http://sugarknri.hatenablog.com/entry/2017/11/18/233936](http://sugarknri.hatenablog.com/entry/2017/11/18/233936)
- [https://yosupo.hatenablog.com/entry/2015/03/27/025132](https://yosupo.hatenablog.com/entry/2015/03/27/025132)



## Verified with

* :x: <a href="../../../../verify/test/yukicoder/658/main.test.cpp.html">test/yukicoder/658/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>

/**
 * @title Kitamasa algorithm
 * @docs kitamasa_algorithm.md
 */
template <typename T> struct KitamasaAlgorithm{
  int size;
  std::vector<T> initial_values, coeff;

  KitamasaAlgorithm(int size, const std::vector<T> &initial_values, const std::vector<T> &coeff):
    size(size), initial_values(initial_values), coeff(coeff){}

  inline std::vector<T> inc(const std::vector<T> &a) const {
    std::vector<T> ret(size);

    for(int i = 0; i < size; ++i) ret[i] += a[size-1] * coeff[i];
    for(int i = 1; i < size; ++i) ret[i] += a[i-1]; 

    return ret;
  }
  
  inline std::vector<T> dbl(const std::vector<T> &a) const {
    std::vector<T> ret(size), b(a);
    
    for(int j = 0; j < size; ++j){
      for(int i = 0; i < size; ++i){
        ret[i] += a[j] * b[i];
      }

      b = inc(b);
    }
    
    return ret;
  }
  
  inline T calc(const std::vector<T> &v) const {
    T ret = 0;
    for(int i = 0; i < size; ++i) ret += v[i] * initial_values[i];
    return ret;
  }

  inline std::vector<T> get(int64_t index) const {
    std::vector<T> ret(size);
    ret[0] = 1;

    bool check = false;
    for(int i = 63; i >= 0; --i){
      if(check) ret = dbl(ret);

      if(index & (1LL << i)){
        ret = inc(ret);
        check = true;
      }
    }
    
    return ret;
  }

  inline T operator[](int64_t index) const {
    if(index < size) return initial_values[index];
    return calc(get(index));
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DynamicProgramming/SpeedupTechnique/kitamasa_algorithm.cpp"
#include <vector>

/**
 * @title Kitamasa algorithm
 * @docs kitamasa_algorithm.md
 */
template <typename T> struct KitamasaAlgorithm{
  int size;
  std::vector<T> initial_values, coeff;

  KitamasaAlgorithm(int size, const std::vector<T> &initial_values, const std::vector<T> &coeff):
    size(size), initial_values(initial_values), coeff(coeff){}

  inline std::vector<T> inc(const std::vector<T> &a) const {
    std::vector<T> ret(size);

    for(int i = 0; i < size; ++i) ret[i] += a[size-1] * coeff[i];
    for(int i = 1; i < size; ++i) ret[i] += a[i-1]; 

    return ret;
  }
  
  inline std::vector<T> dbl(const std::vector<T> &a) const {
    std::vector<T> ret(size), b(a);
    
    for(int j = 0; j < size; ++j){
      for(int i = 0; i < size; ++i){
        ret[i] += a[j] * b[i];
      }

      b = inc(b);
    }
    
    return ret;
  }
  
  inline T calc(const std::vector<T> &v) const {
    T ret = 0;
    for(int i = 0; i < size; ++i) ret += v[i] * initial_values[i];
    return ret;
  }

  inline std::vector<T> get(int64_t index) const {
    std::vector<T> ret(size);
    ret[0] = 1;

    bool check = false;
    for(int i = 63; i >= 0; --i){
      if(check) ret = dbl(ret);

      if(index & (1LL << i)){
        ret = inc(ret);
        check = true;
      }
    }
    
    return ret;
  }

  inline T operator[](int64_t index) const {
    if(index < size) return initial_values[index];
    return calc(get(index));
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

