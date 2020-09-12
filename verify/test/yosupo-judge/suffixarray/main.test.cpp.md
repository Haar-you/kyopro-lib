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


# :x: test/yosupo-judge/suffixarray/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#1a3b4838010325a1a7a9bbb6eb794296">test/yosupo-judge/suffixarray</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/suffixarray/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 05:03:27+09:00


* see: <a href="https://judge.yosupo.jp/problem/suffixarray">https://judge.yosupo.jp/problem/suffixarray</a>


## Depends on

* :question: <a href="../../../../library/Mylib/IO/join.cpp.html">Mylib/IO/join.cpp</a>
* :x: <a href="../../../../library/Mylib/String/suffix_array.cpp.html">Suffix array</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include <iostream>
#include <string>
#include "Mylib/String/suffix_array.cpp"
#include "Mylib/IO/join.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  std::string S; std::cin >> S;
  hl::suffix_array sa(S);

  std::cout << hl::join(sa.begin() + 1, sa.end()) << "\n";

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
#line 3 "Mylib/String/suffix_array.cpp"
#include <vector>
#include <algorithm>
#include <deque>

/**
 * @title Suffix array
 * @docs suffix_array.md
 */
namespace haar_lib {
  template <typename Container>
  struct suffix_array {
    Container s;
    int N;
    std::vector<int> data;

    suffix_array(Container s_): s(s_), N(s.size()), data(N){
      if(N == 1){
        data = {1, 0};
        return;
      }

      s.resize(N + 1);

      std::string LS(N + 1, 'S');
      for(int i = N; --i >= 0;){
        if(s[i] < s[i + 1]) LS[i] = 'S';
        else if(s[i] > s[i + 1]) LS[i] = 'L';
        else LS[i] = LS[i + 1];
      }

      const int bucket_count = *std::max_element(s.begin(), s.end());
      std::vector<int> bucket_size(bucket_count + 1);
      for(auto x : s) bucket_size[x] += 1;

      auto induced_sort =
        [&](std::vector<int> LMS){
          std::vector<int> bucket(N + 1, -1);
          std::vector<bool> is_lms(N + 1);

          std::vector<std::deque<int>> empty(bucket_count + 1);

          for(int i = 0, k = 0; i <= bucket_count; ++i){
            for(int j = 0; j < bucket_size[i]; ++j){
              empty[i].push_back(k);
              ++k;
            }
          }

          std::reverse(LMS.begin(), LMS.end());
          for(auto x : LMS){
            int i = empty[s[x]].back(); empty[s[x]].pop_back();

            bucket[i] = x;
            is_lms[i] = true;
          }

          for(int i = 0; i <= N; ++i){
            if(bucket[i] >= 1 and LS[bucket[i] - 1] == 'L'){
              auto x = s[bucket[i] - 1];
              int j = empty[x].front(); empty[x].pop_front();
              bucket[j] = bucket[i] - 1;
            }
          }

          for(int i = 0; i <= N; ++i){
            if(is_lms[i]){
              bucket[i] = -1;
            }
          }

          for(int i = 0, k = 0; i <= bucket_count; ++i){
            empty[i].clear();

            for(int j = 0; j < bucket_size[i]; ++j){
              empty[i].push_back(k);
              ++k;
            }
          }

          for(int i = N; i >= 0; --i){
            if(bucket[i] >= 1 and LS[bucket[i] - 1] == 'S'){
              auto x = s[bucket[i] - 1];
              int j = empty[x].back(); empty[x].pop_back();
              bucket[j] = bucket[i] - 1;
            }
          }

          bucket[0] = N;
          return bucket;
        };

      std::vector<int> LMS;
      for(int i = 1; i <= N; ++i){
        if(LS[i] == 'S' and LS[i - 1] == 'L'){
          LMS.push_back(i);
        }
      }

      std::vector<int> LMS_bucket_length(N + 1, 1);
      for(int i = 0; i < (int)LMS.size() - 1; ++i){
        LMS_bucket_length[LMS[i]] = LMS[i + 1] - LMS[i] + 1;
      }

      auto bucket = induced_sort(LMS);

      std::vector<int> LMS_substr_sorted;
      for(int i : bucket){
        if(i > 0 and LS[i - 1] == 'L' and LS[i] == 'S'){
          LMS_substr_sorted.push_back(i);
        }
      }

      std::vector<int> rank(N + 1);
      rank[LMS_substr_sorted[0]] = 1;

      for(int i = 1, k = 1; i < (int)LMS_substr_sorted.size(); ++i){
        const int x = LMS_substr_sorted[i - 1], y = LMS_substr_sorted[i];

        bool eq = true;
        if(LMS_bucket_length[x] != LMS_bucket_length[y]) eq = false;
        else{
          for(int j = 0; j < LMS_bucket_length[x]; ++j){
            if(s[x + j] != s[y + j]) eq = false;
          }
        }

        if(not eq) ++k;
        rank[y] = k;
      }

      std::vector<int> t;
      for(int i = 0; i <= N; ++i){
        if(rank[i] != 0) t.push_back(rank[i]);
      }

      auto sa = suffix_array<std::vector<int>>(t).data;

      std::vector<int> LMS_sorted;
      for(int i = 1; i < (int)sa.size(); ++i){
        LMS_sorted.push_back(LMS[sa[i]]);
      }

      data = induced_sort(LMS_sorted);
    }

    int operator[](size_t i) const {return data[i];}
    auto begin() const {return data.begin();}
    auto end() const {return data.end();}
    size_t size() const {return data.size();}

    int lower_bound(const Container &s_) const {
      auto check =
        [&](int x){
          for(int i = 0; i < (int)s_.size(); ++i){
            if(data[x] + i >= (int)s.size()) return false;
            if(s_[i] < s[data[x] + i]) return true;
            if(s_[i] > s[data[x] + i]) return false;
          }
          return true;
        };

      int lb = -1, ub = size();
      while(std::abs(lb - ub) > 1){
        int mid = (lb + ub) / 2;
        if(check(mid)) ub = mid;
        else lb = mid;
      }

      return ub;
    }

    int upper_bound(const Container &s_) const {
      Container t(s_);

      ++t.back();
      int ret = lower_bound(t);

      return ret;
    }
  };
}
#line 3 "Mylib/IO/join.cpp"
#include <sstream>
#line 5 "Mylib/IO/join.cpp"

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
#line 7 "test/yosupo-judge/suffixarray/main.test.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  std::string S; std::cin >> S;
  hl::suffix_array sa(S);

  std::cout << hl::join(sa.begin() + 1, sa.end()) << "\n";

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

