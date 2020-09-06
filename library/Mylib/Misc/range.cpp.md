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


# :warning: Mylib/Misc/range.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#3aaad417c82174440088b5eea559262a">Mylib/Misc</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Misc/range.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-02 21:08:27+09:00




## Operations

一つの閉区間を管理する。

- `is_null()`
  - 区間が空であるかを判定する。
- `contains(a)`
  - 区間に点`a`が含まれるかを判定する。

- `intersect(a, b)`
  - 区間`a`と`b`の共通部分を得る。
- `left_expand(a, x)`
  - 区間`a`の左端を`x`だけ伸縮したものを返す。
- `right_expand(a, x)`
  - 区間`a`の右端を`x`だけ伸縮したものを返す。

## Requirements

## Notes

## Problems

## References


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <optional>
#include <utility>
#include <iostream>
#include <algorithm>

/**
 * @docs range.md
 */
template <typename T>
struct Range {
  std::optional<std::pair<std::optional<T>, std::optional<T>>> value;

  Range(){}
  Range(std::optional<T> l, std::optional<T> r): value(std::make_pair(l, r)){}

  friend std::ostream& operator<<(std::ostream &s, const Range<T> &a){
    s << "[";
    if(a.value){
      if((a.value)->first) s << *((a.value)->first);
      else s << "-∞ ";
      s << ",";
      if((a.value)->second) s << *((a.value)->second);
      else s << "∞ ";
    }
    s << "]";
    return s;
  }

  bool is_null() const {
    return not value;
  }

  bool contains(T v) const {
    if(not value) return false;
    if(value->first and v < *(value->first)) return false;
    if(value->second and v > *(value->second)) return false;

    return true;
  }
};

template <typename T>
auto intersect(Range<T> a, Range<T> b){
  if(not a.value or not b.value) return Range<T>();
  std::optional<T> l, r;

  if((a.value)->first){
    l = *((a.value)->first);
  }

  if((b.value)->first){
    if(l) l = std::max(*l, *((b.value)->first));
    else l = *((b.value)->first);
  }

  if((a.value)->second){
    r = *((a.value)->second);
  }

  if((b.value)->second){
    if(r) r = std::min(*r, *((b.value)->second));
    else r = *((b.value)->second);
  }

  if(l and r){
    if(*l > *r){
      return Range<T>();
    }
  }

  return Range<T>(l, r);
}

template <typename T>
auto left_expand(Range<T> a, T x){
  if(a.value and (a.value)->first){
    *((a.value)->first) += x;
    if((a.value)->second and *((a.value)->first) > *((a.value)->second)){
      return Range<T>();
    }
  }

  return a;
}

template <typename T>
auto right_expand(Range<T> a, T x){
  if(a.value and (a.value)->second){
    *((a.value)->second) += x;
    if((a.value)->first and *((a.value)->first) > *((a.value)->second)){
      return Range<T>();
    }
  }

  return a;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Misc/range.cpp"
#include <optional>
#include <utility>
#include <iostream>
#include <algorithm>

/**
 * @docs range.md
 */
template <typename T>
struct Range {
  std::optional<std::pair<std::optional<T>, std::optional<T>>> value;

  Range(){}
  Range(std::optional<T> l, std::optional<T> r): value(std::make_pair(l, r)){}

  friend std::ostream& operator<<(std::ostream &s, const Range<T> &a){
    s << "[";
    if(a.value){
      if((a.value)->first) s << *((a.value)->first);
      else s << "-∞ ";
      s << ",";
      if((a.value)->second) s << *((a.value)->second);
      else s << "∞ ";
    }
    s << "]";
    return s;
  }

  bool is_null() const {
    return not value;
  }

  bool contains(T v) const {
    if(not value) return false;
    if(value->first and v < *(value->first)) return false;
    if(value->second and v > *(value->second)) return false;

    return true;
  }
};

template <typename T>
auto intersect(Range<T> a, Range<T> b){
  if(not a.value or not b.value) return Range<T>();
  std::optional<T> l, r;

  if((a.value)->first){
    l = *((a.value)->first);
  }

  if((b.value)->first){
    if(l) l = std::max(*l, *((b.value)->first));
    else l = *((b.value)->first);
  }

  if((a.value)->second){
    r = *((a.value)->second);
  }

  if((b.value)->second){
    if(r) r = std::min(*r, *((b.value)->second));
    else r = *((b.value)->second);
  }

  if(l and r){
    if(*l > *r){
      return Range<T>();
    }
  }

  return Range<T>(l, r);
}

template <typename T>
auto left_expand(Range<T> a, T x){
  if(a.value and (a.value)->first){
    *((a.value)->first) += x;
    if((a.value)->second and *((a.value)->first) > *((a.value)->second)){
      return Range<T>();
    }
  }

  return a;
}

template <typename T>
auto right_expand(Range<T> a, T x){
  if(a.value and (a.value)->second){
    *((a.value)->second) += x;
    if((a.value)->first and *((a.value)->first) > *((a.value)->second)){
      return Range<T>();
    }
  }

  return a;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

