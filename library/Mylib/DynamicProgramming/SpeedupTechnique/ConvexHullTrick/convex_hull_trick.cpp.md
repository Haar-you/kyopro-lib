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
<script type="text/javascript" src="../../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../../assets/css/copy-button.css" />


# :warning: Convex Hull Trick

<a href="../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../index.html#7e10cb4eef4fe46e217959a10aea6a72">Mylib/DynamicProgramming/SpeedupTechnique/ConvexHullTrick</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DynamicProgramming/SpeedupTechnique/ConvexHullTrick/convex_hull_trick.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-03 01:42:28+09:00


* see: <a href="https://atcoder.jp/contests/dp/tasks/dp_z (Minクエリ)">https://atcoder.jp/contests/dp/tasks/dp_z (Minクエリ)</a>
* see: <a href="https://codeforces.com/contest/939/problem/E (Maxクエリ)">https://codeforces.com/contest/939/problem/E (Maxクエリ)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <deque>
#include <utility>
#include <functional>

/**
 * @title Convex Hull Trick
 * @see https://atcoder.jp/contests/dp/tasks/dp_z (Minクエリ)
 * @see https://codeforces.com/contest/939/problem/E (Maxクエリ)
 * @note Comparator = greater<T> : 傾き => 単調減少, クエリ座標 => 単調増加, クエリ => Min
 * @note Comparator = less<T> : 傾き => 単調増加, クエリ座標 => 単調増加, クエリ => Max
 */
template <typename T, typename Comparator = std::greater<T>>
class ConvexHullTrick{
  std::deque<std::pair<T,T>> lines;
  bool is_needless(const std::pair<T,T> &a, const std::pair<T,T> &b, const std::pair<T,T> &c){
    return (a.second-b.second)*(a.first-c.first) >= (a.second-c.second)*(a.first-b.first);
  }
  
  T apply(const std::pair<T,T> &f, const T &x){
    return f.first*x + f.second;
  }

  Comparator comp = Comparator();

public:
  ConvexHullTrick(){}
  
  void add(const T &a, const T &b){
    if(!lines.empty()){
      std::pair<T,T> l = lines.back();
      
      if(l.first == a){
        if(not comp(l.second, b)) return;
        lines.pop_back();
      }
    }
    while(lines.size() >= 2 and is_needless(std::make_pair(a,b), lines.back(), *(lines.end()-2))){
      lines.pop_back();
    }
    lines.push_back(std::make_pair(a,b));
  }

  T query(const T &x){
    while(lines.size() >= 2 and comp(apply(lines[0],x), apply(lines[1],x))){
      lines.pop_front();
    }
    return apply(lines[0],x);
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DynamicProgramming/SpeedupTechnique/ConvexHullTrick/convex_hull_trick.cpp"
#include <deque>
#include <utility>
#include <functional>

/**
 * @title Convex Hull Trick
 * @see https://atcoder.jp/contests/dp/tasks/dp_z (Minクエリ)
 * @see https://codeforces.com/contest/939/problem/E (Maxクエリ)
 * @note Comparator = greater<T> : 傾き => 単調減少, クエリ座標 => 単調増加, クエリ => Min
 * @note Comparator = less<T> : 傾き => 単調増加, クエリ座標 => 単調増加, クエリ => Max
 */
template <typename T, typename Comparator = std::greater<T>>
class ConvexHullTrick{
  std::deque<std::pair<T,T>> lines;
  bool is_needless(const std::pair<T,T> &a, const std::pair<T,T> &b, const std::pair<T,T> &c){
    return (a.second-b.second)*(a.first-c.first) >= (a.second-c.second)*(a.first-b.first);
  }
  
  T apply(const std::pair<T,T> &f, const T &x){
    return f.first*x + f.second;
  }

  Comparator comp = Comparator();

public:
  ConvexHullTrick(){}
  
  void add(const T &a, const T &b){
    if(!lines.empty()){
      std::pair<T,T> l = lines.back();
      
      if(l.first == a){
        if(not comp(l.second, b)) return;
        lines.pop_back();
      }
    }
    while(lines.size() >= 2 and is_needless(std::make_pair(a,b), lines.back(), *(lines.end()-2))){
      lines.pop_back();
    }
    lines.push_back(std::make_pair(a,b));
  }

  T query(const T &x){
    while(lines.size() >= 2 and comp(apply(lines[0],x), apply(lines[1],x))){
      lines.pop_front();
    }
    return apply(lines[0],x);
  }
};

```
{% endraw %}

<a href="../../../../../index.html">Back to top page</a>

