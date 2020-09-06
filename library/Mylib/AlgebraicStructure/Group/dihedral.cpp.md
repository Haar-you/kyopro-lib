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


# :x: Dihedral group

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a11cf6f4bd6e76e33e4d7136e3eb98bc">Mylib/AlgebraicStructure/Group</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/AlgebraicStructure/Group/dihedral.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 09:10:27+09:00




## Operations

## Requirements

## Notes

## Problems

## References

- [https://en.wikipedia.org/wiki/Dihedral_group](https://en.wikipedia.org/wiki/Dihedral_group)


## Verified with

* :x: <a href="../../../../verify/test/aoj/0390/main.test.cpp.html">test/aoj/0390/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <iostream>
#include <variant>

/**
 * @title Dihedral group
 * @docs dihedral.md
 */
template <typename Tag>
struct DihedralGroup {
  struct R {
    int value = 0;
    friend std::ostream& operator<<(std::ostream &s, const R &a){
      s << "R(" << a.value << ")";
      return s;
    }
  };

  struct S {
    int value = 0;
    friend std::ostream& operator<<(std::ostream &s, const S &a){
      s << "S(" << a.value << ")";
      return s;
    }
  };

  static int K;

  using value_type = std::variant<R, S>;

  value_type operator()() const {
    return R({0});
  }

  value_type operator()(const value_type &a, const value_type &b) const {
    if(std::holds_alternative<R>(a)){
      if(std::holds_alternative<R>(b)){
        return R({(std::get<R>(a).value + std::get<R>(b).value) % K});
      }else{
        return S({(std::get<S>(b).value - std::get<R>(a).value + K) % K});
      }
    }else{
      if(std::holds_alternative<R>(b)){
        return S({(std::get<S>(a).value + std::get<R>(b).value) % K});
      }else{
        return R({(std::get<S>(b).value - std::get<S>(a).value + K) % K});
      }
    }
  }

  value_type inv(const value_type &a) const {
    if(std::holds_alternative<R>(a)){
      const int i = std::get<R>(a).value;
      return R({i == 0 ? 0 : K - i});
    }else{
      return a;
    }
  }
};

template <typename Tag> int DihedralGroup<Tag>::K;

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/AlgebraicStructure/Group/dihedral.cpp"
#include <iostream>
#include <variant>

/**
 * @title Dihedral group
 * @docs dihedral.md
 */
template <typename Tag>
struct DihedralGroup {
  struct R {
    int value = 0;
    friend std::ostream& operator<<(std::ostream &s, const R &a){
      s << "R(" << a.value << ")";
      return s;
    }
  };

  struct S {
    int value = 0;
    friend std::ostream& operator<<(std::ostream &s, const S &a){
      s << "S(" << a.value << ")";
      return s;
    }
  };

  static int K;

  using value_type = std::variant<R, S>;

  value_type operator()() const {
    return R({0});
  }

  value_type operator()(const value_type &a, const value_type &b) const {
    if(std::holds_alternative<R>(a)){
      if(std::holds_alternative<R>(b)){
        return R({(std::get<R>(a).value + std::get<R>(b).value) % K});
      }else{
        return S({(std::get<S>(b).value - std::get<R>(a).value + K) % K});
      }
    }else{
      if(std::holds_alternative<R>(b)){
        return S({(std::get<S>(a).value + std::get<R>(b).value) % K});
      }else{
        return R({(std::get<S>(b).value - std::get<S>(a).value + K) % K});
      }
    }
  }

  value_type inv(const value_type &a) const {
    if(std::holds_alternative<R>(a)){
      const int i = std::get<R>(a).value;
      return R({i == 0 ? 0 : K - i});
    }else{
      return a;
    }
  }
};

template <typename Tag> int DihedralGroup<Tag>::K;

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

