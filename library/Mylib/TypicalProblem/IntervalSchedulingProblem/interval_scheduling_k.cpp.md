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


# :warning: Mylib/TypicalProblem/IntervalSchedulingProblem/interval_scheduling_k.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a1062884f064c2b3be412505b6627108">Mylib/TypicalProblem/IntervalSchedulingProblem</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/TypicalProblem/IntervalSchedulingProblem/interval_scheduling_k.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 08:41:26+09:00




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

std::vector<std::pair<int,int>> interval_scheduling_k(std::vector<std::pair<int,int>> s, int k){
  std::sort(s.begin(), s.end(), [](const auto &a, const auto &b){
                             return a.second == b.second ? a.first < b.first : a.second < b.second;
                           });

  std::multiset<int> a;
  std::vector<std::pair<int,int>> ret;

  for(auto &p : s){
    auto it = a.lower_bound(p.first);

    if(it != a.begin()){
      it = std::prev(it);
      a.erase(it);
    }

    if((int)a.size() < k){
      a.insert(p.second);
      ret.emplace_back(p);
    }
  }
  
  return ret;
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

std::vector<std::pair<int,int>> interval_scheduling_k(std::vector<std::pair<int,int>> s, int k){
  std::sort(s.begin(), s.end(), [](const auto &a, const auto &b){
                             return a.second == b.second ? a.first < b.first : a.second < b.second;
                           });

  std::multiset<int> a;
  std::vector<std::pair<int,int>> ret;

  for(auto &p : s){
    auto it = a.lower_bound(p.first);

    if(it != a.begin()){
      it = std::prev(it);
      a.erase(it);
    }

    if((int)a.size() < k){
      a.insert(p.second);
      ret.emplace_back(p);
    }
  }
  
  return ret;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

