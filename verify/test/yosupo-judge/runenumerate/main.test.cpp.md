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


# :heavy_check_mark: test/yosupo-judge/runenumerate/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#94d41de64c18e59302675c02311cb549">test/yosupo-judge/runenumerate</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/runenumerate/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-15 00:08:57+09:00


* see: <a href="https://judge.yosupo.jp/problem/runenumerate">https://judge.yosupo.jp/problem/runenumerate</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/String/run_enumerate.cpp.html">run enumerate</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/String/z_algorithm.cpp.html">Z-algorithm</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/runenumerate"

#include <iostream>
#include <string>
#include "Mylib/String/run_enumerate.cpp"


int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  std::string s; std::cin >> s;

  auto ans = RunEnumerate(s).result;

  std::cout << ans.size() << "\n";
  
  for(auto &[t, l, r] : ans){
    std::cout << t << " " << l << " " << r << "\n";
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/runenumerate/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/runenumerate"

#include <iostream>
#include <string>
#line 3 "Mylib/String/run_enumerate.cpp"
#include <tuple>
#include <map>
#include <utility>
#include <algorithm>
#line 2 "Mylib/String/z_algorithm.cpp"
#include <vector>
#line 4 "Mylib/String/z_algorithm.cpp"

/**
 * @title Z-algorithm
 */
template <typename Container, typename T = typename Container::value_type>
std::vector<int> z_algorithm(const Container &s){
  const int n = s.size();
  std::vector<int> ret(n, 0);
  int j = 0;

  for(int i = 1; i < n; ++i){
    if(i+ret[i-j] < j+ret[j]){
      ret[i] = ret[i-j];
    }else{
      int k = std::max<int>(0, j+ret[j]-i);
      while(i+k < n and s[k] == s[i+k]) ++k;
      ret[i] = k;
      j = i;
    }
  }

  ret[0] = n;

  return ret;
}
#line 8 "Mylib/String/run_enumerate.cpp"

/**
 * @title run enumerate
 * @see http://pazzle1230.hatenablog.com/entry/2019/11/27/234632
 */
struct RunEnumerate{
  std::vector<std::tuple<int,int,int>> result;

private:
  auto aux(const std::string &first, const std::string &second){
    std::vector<std::tuple<int,int,int>> ret;

    const int N = first.size(), M = second.size();
  
    auto a = z_algorithm(std::string(first.rbegin(), first.rend()));

    std::string t = second + '\0' + first + second;
    auto b = z_algorithm(t);

    for(int i = 1; i < N; ++i){
      int l1 = a[i];
      int l2 = b[second.size() + first.size() - i + 1];

      if(l1 + i == N or l2 == M or i > l1 + l2) continue;

      int l = N - i - l1, r = N + l2;
      int t = i;
      ret.emplace_back(t, l, r);
    }

    return ret;
  }

  void run(std::string s, int left = 0){
    if(s.size() == 1) return;

    const int N = s.size();
    const int m = N / 2;
    const std::string first = s.substr(0, m), second = s.substr(m);
  
    {
      auto res = aux(first, second);

      for(auto &[t, l, r] : res){
        result.emplace_back(t, left + l, left + r);
      }
    }

    {
      auto res = aux(std::string(second.rbegin(), second.rend()), std::string(first.rbegin(), first.rend()));

      for(auto &[t, l, r] : res){
        result.emplace_back(t, left + N - r, left + N - l);
      }
    }

    run(first, left);
    run(second, left + first.size());
  }

  void sub(std::string s){
    const int N = s.size();
    
    {
      auto a = z_algorithm(s);

      for(int i = 1; i < N; ++i){
        if(i <= a[i]){
          result.emplace_back(i, 0, i + a[i]);
        }
      }
    }
    
    {
      auto a = z_algorithm(std::string(s.rbegin(), s.rend()));

      for(int i = 1; i < N; ++i){
        if(i <= a[i]){
          result.emplace_back(i, N - i - a[i], N);
        }
      }
    }
  }

public:
  RunEnumerate(const std::string &s){
    run(s);
    sub(s);

    std::map<std::pair<int,int>, int> m;

    for(auto &[t,l,r] : result){
      auto p = std::make_pair(l, r);

      if(m.find(p) != m.end()){
        m[p] = std::min(m[p], t);
      }else{
        m[p] = t;
      }
    }

    result.clear();

    for(auto &[p, t] : m){
      result.emplace_back(t, p.first, p.second);
    }

    std::sort(result.begin(), result.end());
  }
};
#line 6 "test/yosupo-judge/runenumerate/main.test.cpp"


int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  std::string s; std::cin >> s;

  auto ans = RunEnumerate(s).result;

  std::cout << ans.size() << "\n";
  
  for(auto &[t, l, r] : ans){
    std::cout << t << " " << l << " " << r << "\n";
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
