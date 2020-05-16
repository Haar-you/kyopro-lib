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


# :heavy_check_mark: test/aoj/2842/main.fenwick_tree.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#64e19fd3e4193a1559ce21d32ec43623">test/aoj/2842</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/2842/main.fenwick_tree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-16 06:15:04+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/AlgebraicStructure/Group/sum.cpp.html">Mylib/AlgebraicStructure/Group/sum.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/DataStructure/FenwickTree/fenwick_tree_2d.cpp.html">FenwickTree (2D)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842"

#include <iostream>
#include <queue>
#include <tuple>

#include "Mylib/AlgebraicStructure/Group/sum.cpp"
#include "Mylib/DataStructure/FenwickTree/fenwick_tree_2d.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int H,W,T,Q; std::cin >> H >> W >> T >> Q;

  FenwickTree2D<SumGroup<int>> seg1(H, W), seg2(H, W);

  std::queue<std::tuple<int,int,int>> q;
  
  while(Q--){
    int t,c; std::cin >> t >> c;
    
    while(q.size()){
      auto &a = q.front();
      
      if(t >= std::get<2>(a) + T){
        int x = std::get<0>(a), y = std::get<1>(a);
        
        seg1.update(x, y, 1);
        seg2.update(x, y, -1);
        
        q.pop();
      }else{
        break;
      }
    }
      
    if(c == 0){
      int h,w; std::cin >> h >> w;
      --h, --w;
      
      seg2.update(h, w, 1);
      q.emplace(h, w, t);
    }else if(c == 1){
      int h,w; std::cin >> h >> w;
      --h, --w;
      
      if(seg1.at(h, w) == 1) seg1.update(h, w, -1);
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
#line 1 "test/aoj/2842/main.fenwick_tree.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842"

#include <iostream>
#include <queue>
#include <tuple>

#line 2 "Mylib/AlgebraicStructure/Group/sum.cpp"

/**
 * @docs sum.md
 */
template <typename T>
struct SumGroup{
  using value_type = T;

  static value_type id(){return 0;}
  static value_type op(const value_type &a, const value_type &b){return a + b;}
  static value_type inv(const value_type &a){return -a;}
};
#line 2 "Mylib/DataStructure/FenwickTree/fenwick_tree_2d.cpp"
#include <vector>

/**
 * @title FenwickTree (2D)
 * @docs fenwick_tree_2d.md
 */
template <typename AbelianGroup>
class FenwickTree2D{
  using value_type = typename AbelianGroup::value_type;
      
  int w, h;
  std::vector<std::vector<value_type>> data;
      
public:
  FenwickTree2D(int width, int height){
    w = width;
    h = height;
    data = std::vector<std::vector<value_type>>(w+1, std::vector<value_type>(h+1));
  }

private:
  inline value_type get_w(int i, int y) const {
    value_type ret = AbelianGroup::id();
    i += 1;
    while(i > 0){
      ret = AbelianGroup::op(ret, data[i][y]);
      i -= i & (-i);
    }
    return ret;
  }
  
  inline value_type get_w(int l, int r, int y) const {
    return AbelianGroup::op(get_w(r-1, y), AbelianGroup::inv(get_w(l-1, y)));
  }

  inline value_type get(int x1, int x2, int y) const {
    value_type ret = AbelianGroup::id();
    y += 1;
    while(y > 0){
      ret = AbelianGroup::op(ret, get_w(x1, x2, y));
      y -= y & (-y);
    }
    return ret;
  }
  
public:
  value_type get(int x1, int y1, int x2, int y2) const { // [(x1,y1),(x2,y2))
    return AbelianGroup::op(get(x1, x2, y2-1), AbelianGroup::inv(get(x1, x2, y1-1)));
  }
     
  value_type at(int x, int y) const {
    return get(x, y, x+1, y+1);
  }
     
  void update(int x, int y, const value_type &val){
    x += 1;
    y += 1;

    for(int i = x; i <= w; i += i & (-i)){
      for(int j = y; j <= h; j += j & (-j)){
        data[i][j] = AbelianGroup::op(data[i][j], val);
      }
    }
  }
};
#line 9 "test/aoj/2842/main.fenwick_tree.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int H,W,T,Q; std::cin >> H >> W >> T >> Q;

  FenwickTree2D<SumGroup<int>> seg1(H, W), seg2(H, W);

  std::queue<std::tuple<int,int,int>> q;
  
  while(Q--){
    int t,c; std::cin >> t >> c;
    
    while(q.size()){
      auto &a = q.front();
      
      if(t >= std::get<2>(a) + T){
        int x = std::get<0>(a), y = std::get<1>(a);
        
        seg1.update(x, y, 1);
        seg2.update(x, y, -1);
        
        q.pop();
      }else{
        break;
      }
    }
      
    if(c == 0){
      int h,w; std::cin >> h >> w;
      --h, --w;
      
      seg2.update(h, w, 1);
      q.emplace(h, w, t);
    }else if(c == 1){
      int h,w; std::cin >> h >> w;
      --h, --w;
      
      if(seg1.at(h, w) == 1) seg1.update(h, w, -1);
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

