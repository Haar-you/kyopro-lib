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


# :question: Mylib/IO/join.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#7f8c074a28e3c2f263a02491ce2132dd">Mylib/IO</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/IO/join.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 17:46:14+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/1300/main.test.cpp.html">test/aoj/1300/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/1327/main.test.cpp.html">test/aoj/1327/main.test.cpp</a>
* :x: <a href="../../../verify/test/aoj/DSL_3_D/main.test.cpp.html">test/aoj/DSL_3_D/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/assignment/main.test.cpp.html">test/yosupo-judge/assignment/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/bernoulli_number/main.test.cpp.html">test/yosupo-judge/bernoulli_number/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/cartesian_tree/main.test.cpp.html">test/yosupo-judge/cartesian_tree/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/convolution_mod/main.test.cpp.html">test/yosupo-judge/convolution_mod/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/convolution_mod_1000000007/main.test.cpp.html">test/yosupo-judge/convolution_mod_1000000007/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/exp_of_formal_power_series/main.test.cpp.html">test/yosupo-judge/exp_of_formal_power_series/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/factorize/main.test.cpp.html">test/yosupo-judge/factorize/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/inv_of_formal_power_series/main.test.cpp.html">test/yosupo-judge/inv_of_formal_power_series/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/log_of_formal_power_series/main.test.cpp.html">test/yosupo-judge/log_of_formal_power_series/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/maximum_independent_set/main.test.cpp.html">test/yosupo-judge/maximum_independent_set/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/montmort_number_mod/main.test.cpp.html">test/yosupo-judge/montmort_number_mod/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/partition_function/main.fps.test.cpp.html">test/yosupo-judge/partition_function/main.fps.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/partition_function/main.test.cpp.html">test/yosupo-judge/partition_function/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/polynomial_taylor_shift/main.test.cpp.html">test/yosupo-judge/polynomial_taylor_shift/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/pow_of_formal_power_series/main.test.cpp.html">test/yosupo-judge/pow_of_formal_power_series/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/scc/main.test.cpp.html">test/yosupo-judge/scc/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/sharp_p_subset_sum/main.test.cpp.html">test/yosupo-judge/sharp_p_subset_sum/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/sqrt_of_formal_power_series/main.test.cpp.html">test/yosupo-judge/sqrt_of_formal_power_series/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/stirling_number_of_the_first_kind/main.test.cpp.html">test/yosupo-judge/stirling_number_of_the_first_kind/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/stirling_number_of_the_second_kind/main.test.cpp.html">test/yosupo-judge/stirling_number_of_the_second_kind/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/suffixarray/main.test.cpp.html">test/yosupo-judge/suffixarray/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/system_of_linear_equations/main.test.cpp.html">test/yosupo-judge/system_of_linear_equations/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/tree_diameter/main.test.cpp.html">test/yosupo-judge/tree_diameter/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/two_edge_connected_components/main.test.cpp.html">test/yosupo-judge/two_edge_connected_components/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/two_sat/main.test.cpp.html">test/yosupo-judge/two_sat/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/zalgorithm/main.test.cpp.html">test/yosupo-judge/zalgorithm/main.test.cpp</a>
* :x: <a href="../../../verify/test/yukicoder/499/main.test.cpp.html">test/yukicoder/499/main.test.cpp</a>
* :x: <a href="../../../verify/test/yukicoder/782/main.test.cpp.html">test/yukicoder/782/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <iostream>
#include <sstream>
#include <string>

/**
 * @docs join.md
 */
namespace haar_lib {
  template <typename Iter>
  std::string join(Iter first, Iter last, std::string delim = " "){
    std::stringstream s;

    for(auto it = first; it != last; ++it){
      if(it != first) s << delim;
      s << *it;
    }

    return s.str();
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/IO/join.cpp"
#include <iostream>
#include <sstream>
#include <string>

/**
 * @docs join.md
 */
namespace haar_lib {
  template <typename Iter>
  std::string join(Iter first, Iter last, std::string delim = " "){
    std::stringstream s;

    for(auto it = first; it != last; ++it){
      if(it != first) s << delim;
      s << *it;
    }

    return s.str();
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

