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


# :heavy_check_mark: test/aoj/ALDS1_15_C/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#dfb9b4b04978b5abf401139b8f15bff5">test/aoj/ALDS1_15_C</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/ALDS1_15_C/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 08:41:26+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_15_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_15_C</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/TypicalProblem/IntervalSchedulingProblem/interval_scheduling.cpp.html">区間スケジューリング問題</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_15_C"

#include <iostream>
#include <vector>
#include "Mylib/TypicalProblem/IntervalSchedulingProblem/interval_scheduling.cpp"

int main(){
  int n; std::cin >> n;
  
  std::vector<int> left(n), right(n);
  for(int i = 0; i < n; ++i){
    int s,t; std::cin >> s >> t;
    left[i] = s;
    right[i] = t+1;
  }
  
  auto ans = interval_scheduling(left, right);
  
  std::cout << ans.size() << std::endl;
  
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/ALDS1_15_C/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_15_C"

#include <iostream>
#include <vector>
#line 3 "Mylib/TypicalProblem/IntervalSchedulingProblem/interval_scheduling.cpp"
#include <numeric>
#include <algorithm>
#include <limits>
#include <utility>

/**
 * @title 区間スケジューリング問題
 * @see https://atcoder.jp/contests/kupc2015/submissions/6604297
 * @see https://codeforces.com/contest/528/submission/57933292
 * @attention time complexity O(N log N)
 */
template <typename T>
std::vector<std::pair<T,T>> interval_scheduling(const std::vector<T> &left, const std::vector<T> &right){ // 区間は[a,b]
  const int N = left.size();
  std::vector<std::pair<T,T>> ret;
  std::vector<int> ord(N);
  std::iota(ord.begin(), ord.end(), 0);
  std::sort(ord.begin(), ord.end(), [&](int i, int j){return right[i] < right[j];});

  auto b = std::numeric_limits<T>::lowest();

  for(int i : ord){
    if(left[i] >= b){
      ret.emplace_back(left[i], right[i]);
      b = right[i];
    }
  }
  
  return ret;
}
#line 6 "test/aoj/ALDS1_15_C/main.test.cpp"

int main(){
  int n; std::cin >> n;
  
  std::vector<int> left(n), right(n);
  for(int i = 0; i < n; ++i){
    int s,t; std::cin >> s >> t;
    left[i] = s;
    right[i] = t+1;
  }
  
  auto ans = interval_scheduling(left, right);
  
  std::cout << ans.size() << std::endl;
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

