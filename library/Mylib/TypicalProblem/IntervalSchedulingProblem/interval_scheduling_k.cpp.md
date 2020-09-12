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


# :x: Interval scheduling problem (Allow no more than k intervals to overlap)

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a1062884f064c2b3be412505b6627108">Mylib/TypicalProblem/IntervalSchedulingProblem</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/TypicalProblem/IntervalSchedulingProblem/interval_scheduling_k.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 17:46:14+09:00




## Operations

- `interval_scheduling_k(l[N], r[N], k)`
	- `N`個の半開区間`[l[i], r[i])`を、ある点で最大`k`個までの重複を許して選ぶときに、選べる個数を最大化する方法を返す。
	- Time complexity $O(N \log N)$

## Requirements

## Notes

## Problems

- [yukicoder No.580 旅館の予約計画](https://yukicoder.me/problems/no/580)
- [Codeforces Round #595 (Div. 3) D2. Too Many Segments (hard version)](https://codeforces.com/contest/1249/problem/D2)

## References

- [http://buyoh.hateblo.jp/entry/2017/10/25/160236](http://buyoh.hateblo.jp/entry/2017/10/25/160236)


## Verified with

* :x: <a href="../../../../verify/test/yukicoder/580/main.test.cpp.html">test/yukicoder/580/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
#include <utility>
#include <numeric>

/**
 * @title Interval scheduling problem (Allow no more than k intervals to overlap)
 * @docs interval_scheduling_k.md
 */
namespace haar_lib {
  auto interval_scheduling_k(std::vector<int> l, std::vector<int> r, int k){
    const int N = l.size();

    std::vector<int> ord(N);
    std::iota(ord.begin(), ord.end(), 0);
    std::sort(ord.begin(), ord.end(), [&](int i, int j){return r[i] < r[j];});

    std::multiset<int> a;
    std::vector<std::pair<int, int>> ret;

    for(int i : ord){
      auto it = a.upper_bound(l[i]);

      if(it != a.begin()){
        it = std::prev(it);
        a.erase(it);
      }

      if((int)a.size() < k){
        a.insert(r[i]);
        ret.emplace_back(l[i], r[i]);
      }
    }

    return ret;
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/TypicalProblem/IntervalSchedulingProblem/interval_scheduling_k.cpp"
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
#include <utility>
#include <numeric>

/**
 * @title Interval scheduling problem (Allow no more than k intervals to overlap)
 * @docs interval_scheduling_k.md
 */
namespace haar_lib {
  auto interval_scheduling_k(std::vector<int> l, std::vector<int> r, int k){
    const int N = l.size();

    std::vector<int> ord(N);
    std::iota(ord.begin(), ord.end(), 0);
    std::sort(ord.begin(), ord.end(), [&](int i, int j){return r[i] < r[j];});

    std::multiset<int> a;
    std::vector<std::pair<int, int>> ret;

    for(int i : ord){
      auto it = a.upper_bound(l[i]);

      if(it != a.begin()){
        it = std::prev(it);
        a.erase(it);
      }

      if((int)a.size() < k){
        a.insert(r[i]);
        ret.emplace_back(l[i], r[i]);
      }
    }

    return ret;
  }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

