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


# :heavy_check_mark: test/aoj/2842/main.segment_tree.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#64e19fd3e4193a1559ce21d32ec43623">test/aoj/2842</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/2842/main.segment_tree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-11 14:07:48+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842</a>


## Depends on

* :question: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/sum.cpp.html">Mylib/AlgebraicStructure/Monoid/sum.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/DataStructure/SegmentTree/segment_tree_2d.cpp.html">Segment tree (2D)</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842"

#include <iostream>
#include <queue>
#include <tuple>

#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"
#include "Mylib/DataStructure/SegmentTree/segment_tree_2d.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int H,W,T,Q; std::cin >> H >> W >> T >> Q;

  SegmentTree2D<SumMonoid<int>> seg1(H, W), seg2(H, W);

  std::queue<std::tuple<int,int,int>> q;
  
  for(auto [t, c] : input_tuples<int, int>(Q)){
    while(q.size()){
      auto &a = q.front();
      
      if(t >= std::get<2>(a) + T){
        int x = std::get<0>(a), y = std::get<1>(a);
        
        seg1.update(x, y, seg1.at(x, y) + 1);
        seg2.update(x, y, seg2.at(x, y) - 1);
        
        q.pop();
      }else{
        break;
      }
    }
      
    if(c == 0){
      int h,w; std::cin >> h >> w;
      --h, --w;
      
      seg2.update(h, w, seg2.at(h, w) + 1);
      q.emplace(h, w, t);
    }else if(c == 1){
      int h,w; std::cin >> h >> w;
      --h, --w;
      
      if(seg1.at(h, w) == 1) seg1.update(h, w, seg1.at(h, w) - 1);
    }else{
      int h1,w1,h2,w2; std::cin >> h1 >> w1 >> h2 >> w2;
      --h1, --w1;
      
      std::cout << seg1.get(h1, w1, h2, w2) << " " << seg2.get(h1, w1, h2, w2) << std::endl;
    }
  }
  
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/2842/main.segment_tree.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842"

#include <iostream>
#include <queue>
#include <tuple>

#line 2 "Mylib/AlgebraicStructure/Monoid/sum.cpp"

/**
 * @docs sum.md
 */
template <typename T>
struct SumMonoid{
  using value_type = T;
  value_type id() const {return 0;}
  value_type op(value_type a, value_type b) const {return a + b;}
};
#line 2 "Mylib/DataStructure/SegmentTree/segment_tree_2d.cpp"
#include <vector>

/**
 * @title Segment tree (2D)
 * @docs segment_tree_2d.md
 */
template <typename Monoid>
class SegmentTree2D{
  using value_type = typename Monoid::value_type;
  Monoid M;
  
  int w, h;
  std::vector<std::vector<value_type>> data;

  value_type get_w(int l, int r, int y) const {
    l += w / 2;
    r += w / 2;

    value_type ret = M.id();

    while(l < r){
      if(r & 1) ret = M.op(ret, data[--r][y]);
      if(l & 1) ret = M.op(ret, data[l++][y]);
      l >>= 1, r >>= 1;
    }
    
    return ret;
  }
      
public:
  SegmentTree2D(int width, int height){
    w = 1;
    while(w < width) w *= 2;
    w = w*2;
    
    h = 1;
    while(h < height) h *= 2;
    h = h*2;
        
    data = std::vector<std::vector<value_type>>(w, std::vector<value_type>(h));
  }
     
  value_type get(int x1, int y1, int x2, int y2) const { // [(x1,y1),(x2,y2))
    int l = y1 + h / 2;
    int r = y2 + h / 2;

    value_type ret = M.id();

    while(l < r){
      if(r & 1) ret = M.op(ret, get_w(x1, x2, --r));
      if(l & 1) ret = M.op(ret, get_w(x1, x2, l++));
      l >>= 1, r >>= 1;
    }

    return ret;
  }
  
  value_type at(int x, int y) const {
    return data[w / 2 + x][h / 2 + y];
  }
     
  void update(int x, int y, const value_type &val){
    const int i = x + w / 2;
    const int j = y + h / 2;
    
    data[i][j] = val;
     
    for(int X = i >> 1, Y = j; X > 0; X >>= 1){
      data[X][Y] = M.op(data[X << 1 | 0][Y], data[X << 1 | 1][Y]);
    }
        
    for(int Y = j >> 1; Y > 0; Y >>= 1){
      for(int X = i; X > 0; X >>= 1){
        data[X][Y] = M.op(data[X][Y << 1 | 0], data[X][Y << 1 | 1]);
      }
    }
  }
};
#line 5 "Mylib/IO/input_tuples.cpp"
#include <utility>
#include <initializer_list>
#line 6 "Mylib/IO/input_tuple.cpp"

/**
 * @docs input_tuple.md
 */
template <typename T, size_t ... I>
static void input_tuple_helper(std::istream &s, T &val, std::index_sequence<I...>){
  (void)std::initializer_list<int>{(void(s >> std::get<I>(val)), 0)...};
}

template <typename T, typename U>
std::istream& operator>>(std::istream &s, std::pair<T, U> &value){
  s >> value.first >> value.second;
  return s;
}

template <typename ... Args>
std::istream& operator>>(std::istream &s, std::tuple<Args...> &value){
  input_tuple_helper(s, value, std::make_index_sequence<sizeof...(Args)>());
  return s;
}
#line 8 "Mylib/IO/input_tuples.cpp"

/**
 * @docs input_tuples.md
 */
template <typename ... Args>
class InputTuples{
  struct iter{
    using value_type = std::tuple<Args ...>;
    value_type value;
    bool fetched = false;
    int N, c = 0;

    value_type operator*(){
      if(not fetched){
        std::cin >> value;
      }
      return value;
    }

    void operator++(){
      ++c;
      fetched = false;
    }

    bool operator!=(iter &) const {
      return c < N;
    }

    iter(int N): N(N){}
  };

  int N;

public:
  InputTuples(int N): N(N){}

  iter begin() const {return iter(N);}
  iter end() const {return iter(N);}
};

template <typename ... Args>
auto input_tuples(int N){
  return InputTuples<Args ...>(N);
}
#line 10 "test/aoj/2842/main.segment_tree.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int H,W,T,Q; std::cin >> H >> W >> T >> Q;

  SegmentTree2D<SumMonoid<int>> seg1(H, W), seg2(H, W);

  std::queue<std::tuple<int,int,int>> q;
  
  for(auto [t, c] : input_tuples<int, int>(Q)){
    while(q.size()){
      auto &a = q.front();
      
      if(t >= std::get<2>(a) + T){
        int x = std::get<0>(a), y = std::get<1>(a);
        
        seg1.update(x, y, seg1.at(x, y) + 1);
        seg2.update(x, y, seg2.at(x, y) - 1);
        
        q.pop();
      }else{
        break;
      }
    }
      
    if(c == 0){
      int h,w; std::cin >> h >> w;
      --h, --w;
      
      seg2.update(h, w, seg2.at(h, w) + 1);
      q.emplace(h, w, t);
    }else if(c == 1){
      int h,w; std::cin >> h >> w;
      --h, --w;
      
      if(seg1.at(h, w) == 1) seg1.update(h, w, seg1.at(h, w) - 1);
    }else{
      int h1,w1,h2,w2; std::cin >> h1 >> w1 >> h2 >> w2;
      --h1, --w1;
      
      std::cout << seg1.get(h1, w1, h2, w2) << " " << seg2.get(h1, w1, h2, w2) << std::endl;
    }
  }
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

