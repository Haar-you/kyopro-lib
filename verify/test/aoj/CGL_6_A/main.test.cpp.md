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


# :x: test/aoj/CGL_6_A/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#ccdbf2fe951f3a82ecc561ea87264ae1">test/aoj/CGL_6_A</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/CGL_6_A/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_6_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_6_A</a>


## Depends on

* :question: <a href="../../../../library/Mylib/Geometry/Float/geometry_template.cpp.html">Geometry template</a>
* :x: <a href="../../../../library/Mylib/Geometry/Float/manhattan_segments_intersections.cpp.html">Manhattan segments intersections</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_6_A"

#include <iostream>
#include <vector>
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/manhattan_segments_intersections.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n; std::cin >> n;
  std::vector<hl::segment<int>> s(n);
  for(int i = 0; i < n; ++i){
    std::cin >> s[i].from >> s[i].to;
  }

  auto ans = hl::manhattan_segments_intersections(s);
  std::cout << ans << "\n";

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/CGL_6_A/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_6_A"

#include <iostream>
#include <vector>
#line 3 "Mylib/Geometry/Float/geometry_template.cpp"
#include <cmath>
#line 5 "Mylib/Geometry/Float/geometry_template.cpp"

/**
 * @title Geometry template
 * @docs geometry_template.md
 */
namespace haar_lib {
  template <typename T>
  struct vec {
    T x, y;
    vec(){}
    vec(T x, T y): x(x), y(y){}

    friend auto operator+(const vec &a, const vec &b){return vec(a.x + b.x, a.y + b.y);}
    friend auto operator-(const vec &a, const vec &b){return vec(a.x - b.x, a.y - b.y);}
    friend auto operator-(const vec &a){return vec(-a.x, -a.y);}

    friend bool operator==(const vec &a, const vec &b){return a.x == b.x and a.y == b.y;}
    friend bool operator!=(const vec &a, const vec &b){return !(a == b);}
    friend bool operator<(const vec &a, const vec &b){return a.x < b.x or (a.x == b.x and a.y < b.y);}

    friend std::istream& operator>>(std::istream &s, vec &a){
      s >> a.x >> a.y; return s;
    }
  };

  template <typename T, typename U> auto operator*(const vec<T> &a, const U &k){return vec<T>(a.x * k, a.y * k);}
  template <typename T, typename U> auto operator*(const U &k, const vec<T> &a){return vec<T>(a.x * k, a.y * k);}
  template <typename T, typename U> auto operator/(const vec<T> &a, const U &k){return vec<T>(a.x / k, a.y / k);}

  template <typename T> using point = vec<T>;

  template <typename T> T abs(const vec<T> &a){return sqrt(a.x * a.x + a.y * a.y);}
  template <typename T> T abs_sq(const vec<T> &a){return a.x * a.x + a.y * a.y;}

  template <typename T> T dot(const vec<T> &a, const vec<T> &b){return a.x * b.x + a.y * b.y;}
  template <typename T> T cross(const vec<T> &a, const vec<T> &b){return a.x * b.y - a.y * b.x;}

  template <typename T> auto unit(const vec<T> &a){return a / abs(a);}
  template <typename T> auto normal(const vec<T> &p){return vec<T>(-p.y, p.x);}

  template <typename T> auto polar(const T &r, const T &ang){return vec<T>(r * cos(ang), r * sin(ang));}

  template <typename T> T angle(const vec<T> &a, const vec<T> &b){return atan2(b.y - a.y, b.x - a.x);}
  template <typename T> T phase(const vec<T> &a){return atan2(a.y, a.x);}

  template <typename T>
  T angle_diff(const vec<T> &a, const vec<T> &b){
    T r = phase(b) - phase(a);

    if(r < -M_PI) return r + 2 * M_PI;
    else if(r > M_PI) return r - 2 * M_PI;
    return r;
  }


  template <typename T> struct line {
    point<T> from, to;
    line(): from(), to(){}
    line(const point<T> &from, const point<T> &to): from(from), to(to){}
  };

  template <typename T> using segment = line<T>;


  template <typename T> auto unit(const line<T> &a){return unit(a.to - a.from);}
  template <typename T> auto normal(const line<T> &a){return normal(a.to - a.from);}

  template <typename T> auto diff(const segment<T> &a){return a.to - a.from;}

  template <typename T> T abs(const segment<T> &a){return abs(diff(a));}

  template <typename T> T dot(const line<T> &a, const line<T> &b){return dot(diff(a), diff(b));}
  template <typename T> T cross(const line<T> &a, const line<T> &b){return cross(diff(a), diff(b));}


  template <typename T> using polygon = std::vector<point<T>>;

  template <typename T> struct circle {
    point<T> center;
    T radius;
    circle(): center(), radius(0){}
    circle(const point<T> &center, T radius): center(center), radius(radius){}
  };

  template <typename T>
  std::ostream& operator<<(std::ostream &s, const vec<T> &a){
    s << "(" << a.x << ", " << a.y << ")";
    return s;
  }

  template <typename T>
  std::ostream& operator<<(std::ostream &s, const line<T> &a){
    s << "(" << a.from << " -> " << a.to << ")";
    return s;
  }

  template <typename T>
  std::ostream& operator<<(std::ostream &s, const circle<T> &a){
    s << "("
      << "center: " << a.center << ", "
      << "radius: " << a.radius << ")";
    return s;
  }
}
#line 3 "Mylib/Geometry/Float/manhattan_segments_intersections.cpp"
#include <algorithm>
#include <utility>
#include <tuple>
#include <climits>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#line 10 "Mylib/Geometry/Float/manhattan_segments_intersections.cpp"

/**
 * @title Manhattan segments intersections
 * @docs manhattan_segments_intersections.md
 */
namespace haar_lib {
  template <typename T>
  int manhattan_segments_intersections(std::vector<segment<T>> segs){
    std::vector<segment<T>> hs;
    std::vector<std::tuple<point<T>, bool, int>> vs;
    int count = 0;

    for(auto s : segs){
      if(s.from.y == s.to.y){
        hs.push_back(s);
      }else{
        vs.emplace_back(s.from, s.from.y < s.to.y, count);
        vs.emplace_back(s.to, s.from.y > s.to.y, count);
        ++count;
      }
    }

    std::sort(hs.rbegin(), hs.rend(), [](const auto &a, const auto &b){return a.from.y < b.from.y;});
    std::sort(vs.rbegin(), vs.rend(), [](const auto &a, const auto &b){return std::get<0>(a).y < std::get<0>(b).y;});

    __gnu_pbds::tree<
      std::pair<T, int>,
      __gnu_pbds::null_type,
      std::less<std::pair<T, int>>,
      __gnu_pbds::rb_tree_tag,
      __gnu_pbds::tree_order_statistics_node_update
      > set;
    int64_t ans = 0;

    while(true){
      if(hs.empty() or vs.empty()) break;

      T ymin = std::min(hs.back().from.y, std::get<0>(vs.back()).y);

      std::vector<segment<T>> rs;
      std::vector<std::tuple<point<T>, bool, int>> ps;

      while(not hs.empty() and hs.back().from.y == ymin){
        rs.push_back(hs.back());
        hs.pop_back();
      }

      while(not vs.empty() and std::get<0>(vs.back()).y == ymin){
        ps.push_back(vs.back());
        vs.pop_back();
      }

      for(auto [a, b, c] : ps){
        if(b) set.insert(std::make_pair(a.x, c));
      }

      for(auto [a, b] : rs){
        auto [x1, x2] = std::minmax(a.x, b.x);

        auto ix1 = set.order_of_key(std::make_pair(x1, 0));
        auto ix2 = set.order_of_key(std::make_pair(x2, INT_MAX));

        ans += ix2 - ix1;
      }

      for(auto [a, b, c] : ps){
        if(not b) set.erase(std::make_pair(a.x, c));
      }
    }

    return ans;
  }
}
#line 7 "test/aoj/CGL_6_A/main.test.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n; std::cin >> n;
  std::vector<hl::segment<int>> s(n);
  for(int i = 0; i < n; ++i){
    std::cin >> s[i].from >> s[i].to;
  }

  auto ans = hl::manhattan_segments_intersections(s);
  std::cout << ans << "\n";

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

