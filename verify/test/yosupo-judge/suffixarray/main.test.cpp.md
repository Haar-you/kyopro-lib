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


# :heavy_check_mark: test/yosupo-judge/suffixarray/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#1a3b4838010325a1a7a9bbb6eb794296">test/yosupo-judge/suffixarray</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/suffixarray/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-03 01:42:28+09:00


* see: <a href="https://judge.yosupo.jp/problem/suffixarray">https://judge.yosupo.jp/problem/suffixarray</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/String/suffix_array.cpp.html">接尾辞配列</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include <iostream>
#include <string>
#include "Mylib/String/suffix_array.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  std::string S;

  while(std::cin >> S){
    SuffixArray<std::string> sa(S);

    for(auto x : sa.suffix_array){
      std::cout << x << " ";
    }
    std::cout << "\n";
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/suffixarray/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include <iostream>
#include <string>
#line 2 "Mylib/String/suffix_array.cpp"
#include <vector>
#include <tuple>

/**
 * @title 接尾辞配列
 * @see https://yukicoder.me/submissions/347188
 */
template <typename T> class SuffixArray{
public:
  const T str;
  const int n;
  std::vector<int> suffix_array;
  
  const int ALPHABET = 256;
  
  SuffixArray(const T &s): str(s), n(s.size()), suffix_array(n){
    std::vector<int> temp(n);
    for(int i = 0; i < n; ++i) temp[i] = s[i];

    {
      std::vector<int> table(ALPHABET);
      for(auto c : s) table[c] = 1;
      for(int i = 1; i < ALPHABET; ++i) table[i] += table[i-1];

      for(int i = 0; i < n; ++i){
        temp[i] = table[s[i]]; 
      }
    }

    for(int l = 1; l < n; l *= 2){
      std::vector<std::tuple<int,int,int>> m(n);
      for(int i = 0; i < n; ++i){
        m[i] = std::make_tuple(temp[i], i+l >= n ? 0 : temp[i + l], i);
      }
      
      {
        std::vector<std::vector<std::tuple<int,int,int>>> table(n+1);

        for(int i = 0; i < n; ++i){
          table[std::get<1>(m[i])].push_back(m[i]);
        }

        m.clear();

        for(int i = 0; i <= n; ++i){
          for(auto &t : table[i]){
            m.push_back(t);
          }
        }
      }
      
      {
        std::vector<std::vector<std::tuple<int,int,int>>> table(n+1);

        for(int i = 0; i < n; ++i){
          table[std::get<0>(m[i])].push_back(m[i]);
        }

        m.clear();

        for(int i = 0; i <= n; ++i){
          for(auto &t : table[i]){
            m.push_back(t);
          }
        }
      }
      
      int h = 1;
      for(int i = 0; i < n; ++i){
        if(i > 0 and (std::get<0>(m[i-1]) != std::get<0>(m[i]) or std::get<1>(m[i-1]) != std::get<1>(m[i]))){
          ++h;
        }
        
        temp[std::get<2>(m[i])] = h;
      }
    }
    
    for(int i = 0; i < n; ++i) suffix_array[temp[i]-1] = i;
  }

  int operator[](int i) const {return suffix_array[i];}

  bool starts_with(const T &s, int k) const {
    if(s.size() <= str.size() - k){
      for(int i = 0; i < (int)s.size(); ++i){
        if(s[i] != str[k+i]) return false;
      }
      return true;
    }
    return false;
  }

  int lower_bound(const T &s) const {
    auto check =
      [&](int x){
        for(int i = 0; i < (int)s.size(); ++i){
          if(suffix_array[x]+i >= (int)str.size()) return false;
          if(s[i] < str[suffix_array[x]+i]) return true;
          if(s[i] > str[suffix_array[x]+i]) return false;
        }
        return true;
      };

    int lb = -1, ub = n;
    while(abs(lb-ub) > 1){
      int mid = (lb+ub)/2;

      if(check(mid)){
        ub = mid;
      }else{
        lb = mid;
      }
    }
    
    return ub;
  }

  int upper_bound(const T &s) const {
    T t(s);

    t.back()++;
    int ret = lower_bound(t);
    t.back()--;
    return ret;
  }
};
#line 6 "test/yosupo-judge/suffixarray/main.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  std::string S;

  while(std::cin >> S){
    SuffixArray<std::string> sa(S);

    for(auto x : sa.suffix_array){
      std::cout << x << " ";
    }
    std::cout << "\n";
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

