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


# :x: test/yukicoder/580/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#cd972d63fbc2cdaa6f2e20f02bf8d13c">test/yukicoder/580</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yukicoder/580/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 17:46:14+09:00


* see: <a href="https://yukicoder.me/problems/no/580">https://yukicoder.me/problems/no/580</a>


## Depends on

* :x: <a href="../../../../library/Mylib/TypicalProblem/IntervalSchedulingProblem/interval_scheduling_k.cpp.html">Interval scheduling problem (Allow no more than k intervals to overlap)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/580"

#include <iostream>
#include <vector>
#include "Mylib/TypicalProblem/IntervalSchedulingProblem/interval_scheduling_k.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n, m; std::cin >> n >> m;

  std::vector<int> l(m), r(m);

  for(int i = 0; i < m; ++i){
    int d; std::cin >> d;
    int h1, m1; std::cin >> h1; std::cin.ignore(); std::cin >> m1;

    int o; std::cin >> o;
    int h2, m2; std::cin >> h2; std::cin.ignore(); std::cin >> m2;

    l[i] = d * 24 * 60 + h1 * 60 + m1;
    r[i] = o * 24 * 60 + h2 * 60 + m2 + 1;
  }

  auto res = hl::interval_scheduling_k(l, r, n);
  std::cout << res.size() << "\n";

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yukicoder/580/main.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/580"

#include <iostream>
#include <vector>
#line 3 "Mylib/TypicalProblem/IntervalSchedulingProblem/interval_scheduling_k.cpp"
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
#line 6 "test/yukicoder/580/main.test.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n, m; std::cin >> n >> m;

  std::vector<int> l(m), r(m);

  for(int i = 0; i < m; ++i){
    int d; std::cin >> d;
    int h1, m1; std::cin >> h1; std::cin.ignore(); std::cin >> m1;

    int o; std::cin >> o;
    int h2, m2; std::cin >> h2; std::cin.ignore(); std::cin >> m2;

    l[i] = d * 24 * 60 + h1 * 60 + m1;
    r[i] = o * 24 * 60 + h2 * 60 + m2 + 1;
  }

  auto res = hl::interval_scheduling_k(l, r, n);
  std::cout << res.size() << "\n";

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

