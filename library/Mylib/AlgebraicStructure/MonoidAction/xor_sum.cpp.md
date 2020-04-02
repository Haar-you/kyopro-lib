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


# :warning: Mylib/AlgebraicStructure/MonoidAction/xor_sum.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#7bd9a37defae28fe1746a7ffe2a62491">Mylib/AlgebraicStructure/MonoidAction</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/AlgebraicStructure/MonoidAction/xor_sum.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-31 07:44:02+09:00




## Depends on

* :warning: <a href="../Monoid/parallel_monoid.cpp.html">Mylib/AlgebraicStructure/Monoid/parallel_monoid.cpp</a>
* :question: <a href="../Monoid/sum_monoid.cpp.html">Mylib/AlgebraicStructure/Monoid/sum_monoid.cpp</a>
* :warning: <a href="../Monoid/xor_monoid.cpp.html">Mylib/AlgebraicStructure/Monoid/xor_monoid.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "Mylib/AlgebraicStructure/Monoid/parallel_monoid.cpp"
#include "Mylib/AlgebraicStructure/Monoid/sum_monoid.cpp"
#include "Mylib/AlgebraicStructure/Monoid/xor_monoid.cpp"

template <typename U, int B>
struct XorSum{
  using monoid_get = ParallelMonoid<SumMonoid<int>, B>;
  using monoid_update = XorMonoid<U>;
  using value_type_get = typename monoid_get::value_type;
  using value_type_update = typename monoid_update::value_type;

  inline static value_type_get op(const value_type_get &a, const value_type_update &b, int len){
    auto ret = a;
    for(int i = 0; i < B; ++i) if((b >> i) & 1) ret[i] = len - ret[i];
    return ret;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/AlgebraicStructure/Monoid/parallel_monoid.cpp"
#include <array>

// BEGIN

template <typename Monoid, int B>
struct ParallelMonoid{
  using value_type = std::array<typename Monoid::value_type, B>;

  inline static value_type id(){
    value_type ret;
    ret.fill(Monoid::id());
    return ret;
  }

  inline static value_type op(const value_type &a, const value_type &b){
    value_type ret;
    for(int i = 0; i < B; ++i) ret[i] = Monoid::op(a[i], b[i]);
    return ret;
  }
};
#line 2 "Mylib/AlgebraicStructure/Monoid/sum_monoid.cpp"

template <typename T>
struct SumMonoid{
  using value_type = T;
  constexpr inline static value_type id(){return 0;}
  constexpr inline static value_type op(const value_type &a, const value_type &b){return a + b;}
};
#line 2 "Mylib/AlgebraicStructure/Monoid/xor_monoid.cpp"

template <typename T>
struct XorMonoid{
  using value_type = T;
  constexpr inline static value_type id(){return 0;}
  constexpr inline static value_type op(const value_type &a, const value_type &b){return a ^ b;}
};
#line 5 "Mylib/AlgebraicStructure/MonoidAction/xor_sum.cpp"

template <typename U, int B>
struct XorSum{
  using monoid_get = ParallelMonoid<SumMonoid<int>, B>;
  using monoid_update = XorMonoid<U>;
  using value_type_get = typename monoid_get::value_type;
  using value_type_update = typename monoid_update::value_type;

  inline static value_type_get op(const value_type_get &a, const value_type_update &b, int len){
    auto ret = a;
    for(int i = 0; i < B; ++i) if((b >> i) & 1) ret[i] = len - ret[i];
    return ret;
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

