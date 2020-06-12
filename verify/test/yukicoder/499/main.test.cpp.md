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


# :x: test/yukicoder/499/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#6d875ae29365ab59bb073a9f5998cd26">test/yukicoder/499</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yukicoder/499/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00


* see: <a href="https://yukicoder.me/problems/no/499">https://yukicoder.me/problems/no/499</a>


## Depends on

* :question: <a href="../../../../library/Mylib/IO/join.cpp.html">Mylib/IO/join.cpp</a>
* :x: <a href="../../../../library/Mylib/Misc/convert_base.cpp.html">Convert base</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/499"

#include <iostream>
#include <algorithm>
#include "Mylib/Misc/convert_base.cpp"
#include "Mylib/IO/join.cpp"

int main(){
  int N; std::cin >> N;

  auto res = convert_base_to(N, 7);

  std::cout << join(res.begin(), res.end(), "") << "\n";
  
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yukicoder/499/main.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/499"

#include <iostream>
#include <algorithm>
#line 2 "Mylib/Misc/convert_base.cpp"
#include <vector>
#line 4 "Mylib/Misc/convert_base.cpp"

/**
 * @title Convert base
 * @docs convert_base.md
 */
std::vector<int64_t> convert_base_to(int64_t val, int64_t base){
  if(val == 0) return {0};

  int b = std::abs(base);

  std::vector<int64_t> ret;
  while(val != 0){
    int r = val % b;
    if(r < 0) r += b;
    val = (val - r) / base;
    ret.push_back(r);
  }

  std::reverse(ret.begin(), ret.end());
  
  return ret;
}

int64_t convert_base_from(const std::vector<int64_t> &val, int64_t base){
  int64_t ret = 0;
  for(auto it = val.begin(); it != val.end(); ++it){
    (ret *= base) += *it;
  }

  return ret;
}
#line 3 "Mylib/IO/join.cpp"
#include <sstream>
#include <string>

/**
 * @docs join.md
 */
template <typename ITER>
std::string join(ITER first, ITER last, std::string delim = " "){
  std::stringstream s;

  for(auto it = first; it != last; ++it){
    if(it != first) s << delim;
    s << *it;
  }

  return s.str();
}
#line 7 "test/yukicoder/499/main.test.cpp"

int main(){
  int N; std::cin >> N;

  auto res = convert_base_to(N, 7);

  std::cout << join(res.begin(), res.end(), "") << "\n";
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
