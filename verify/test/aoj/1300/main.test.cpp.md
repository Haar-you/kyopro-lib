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


# :heavy_check_mark: test/aoj/1300/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#453a4dbc3063ebc5e529de1cba20ccae">test/aoj/1300</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/1300/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1300">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1300</a>


## Depends on

* :question: <a href="../../../../library/Mylib/IO/join.cpp.html">Mylib/IO/join.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/LinearAlgebra/GaussianElimination/gaussian_elimination.cpp.html">Gaussian elimination</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Number/Rational/rational.cpp.html">Rational number</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Parser/parser.cpp.html">Parsing</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/String/split.cpp.html">split</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1300"

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "Mylib/Parser/parser.cpp"
#include "Mylib/Number/Rational/rational.cpp"
#include "Mylib/LinearAlgebra/GaussianElimination/gaussian_elimination.cpp"
#include "Mylib/String/split.cpp"
#include "Mylib/IO/join.cpp"

namespace hl = haar_lib;

using result = std::map<std::string, int>;

struct parser : hl::parser {
  parser(const std::string &s): hl::parser(s){}

  std::string atom(){
    std::string ret;
    ret += get_char();
    if(lower()) ret += get_char();

    return ret;
  }

  result factor(){
    result ret;
    if(check_and_ignore('(')){
      ret = expression();
      ignore(')');
    }else{
      ret[atom()] = 1;
    }

    if(digit()){
      int n = get_number<int>();

      for(auto &kv : ret){
        kv.second *= n;
      }
    }

    return ret;
  }

  result expression(){
    result ret = factor();

    while(1){
      if(digit() or alpha() or check('(')){
        result temp = factor();

        for(auto &[k, v] : temp){
          ret[k] += v;
        }
      }else{
        break;
      }
    }

    return ret;
  }

  result run(){
    return expression();
  }
};

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  std::string s;
  while(std::cin >> s){
    if(s == ".") break;

    s.pop_back(); // pop period
    auto a = hl::split(s, "->");
    auto b = hl::split(a[0], "+");
    auto c = hl::split(a[1], "+");

    std::map<std::string, int> atoms;

    std::vector<result> ress;
    for(auto &x : b){
      auto r = parser(x).run();
      for(auto &kv : r){
        atoms[kv.first] = 0;
      }
      ress.push_back(r);
    }
    for(auto &x : c){
      auto r = parser(x).run();
      for(auto &kv : r){
        atoms[kv.first] = 0;
        kv.second = -kv.second;
      }
      ress.push_back(r);
    }

    {
      int i = 0;
      for(auto &kv : atoms){
        kv.second = i++;
      }
    }

    std::vector<std::vector<hl::rational>> mat(atoms.size(), std::vector<hl::rational>(ress.size()));
    for(int i = 0; i < (int)ress.size(); ++i){
      for(auto &[k, v] : ress[i]){
        mat[atoms[k]][i] = v;
      }
    }

    hl::gaussian_elimination(mat);

    const int n = ress.size();
    std::vector<hl::rational> ans(n);

    ans[n - 1] = 1;

    for(int i = (int)atoms.size(); --i >= 0;){
      if(mat[i].back() == 0) continue;

      int k = 0;
      hl::rational coef;
      hl::rational cons;

      for(int j = 0; j < n; ++j){
        if(ans[j] == 0){
          k = j;
          coef = mat[i][j];
        }else{
          cons += mat[i][j] * ans[j];
        }
      }

      ans[k] = -cons / coef;
    }

    int64_t l = 1;
    for(int i = 0; i < n; ++i) l = std::lcm(l, ans[i].deno);

    for(int i = 0; i < n; ++i) ans[i] *= l;

    std::cout << hl::join(ans.begin(), ans.end()) << "\n";
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/1300/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1300"

#include <iostream>
#include <map>
#include <string>
#include <vector>
#line 3 "Mylib/Parser/parser.cpp"
#include <cassert>

/**
 * @title Parsing
 * @docs parser.md
 */
namespace haar_lib {
  struct parser {
    using state = std::string::const_iterator;

    state cur, first, last;

    parser(){}
    parser(const std::string &s): cur(s.cbegin()), first(s.cbegin()), last(s.cend()){}

    char peek() const {return *cur;}

    bool check(char c) const {
      return *cur == c;
    }

    bool check(const std::string &s) const {
      state temp = cur;
      for(auto c : s){
        if(c != *temp) return false;
        ++temp;
      }
      return true;
    }

    void ignore(char c){
      assert(*cur == c);
      ++cur;
    }

    void ignore(){
      ++cur;
    }

    void ignore(const std::string &s){
      for(auto c : s){
        assert(*cur == c);
        ++cur;
      }
    }

    template <class Checker>
    void ignore_if(const Checker &f){
      assert(f(*cur));
      ++cur;
    }

    bool check_and_ignore(char c){
      if(*cur != c) return false;
      ++cur;
      return true;
    }

    bool end() const {return cur == last;}
    bool digit() const {return isdigit(*cur);}
    bool alpha() const {return isalpha(*cur);}
    bool lower() const {return islower(*cur);}
    bool upper() const {return isupper(*cur);}

    char get_char(){
      return *(cur++);
    }

    int get_digit(){
      return (int)(*(cur++) - '0');
    }

    template <typename Checker>
    auto get_string(const Checker &f){
      std::string ret;
      while(f(peek())){
        ret += peek();
        ignore();
      }
      return ret;
    }

    auto get_string_alpha(){
      std::string ret;
      while(isalpha(*cur)){
        ret += *cur;
        ++cur;
      }
      return ret;
    }

    auto get_string_alnum(){
      std::string ret;
      while(isalnum(*cur)){
        ret += *cur;
        ++cur;
      }
      return ret;
    }

    template <typename T>
    T get_number(){
      T ret = get_digit();
      while(digit()){
        (ret *= 10) += (T)(get_digit());
      }
      return ret;
    }
  };
}
#line 2 "Mylib/Number/Rational/rational.cpp"
#include <numeric>
#line 4 "Mylib/Number/Rational/rational.cpp"
#include <cmath>

/**
 * @title Rational number
 * @docs rational.md
 */
namespace haar_lib {
  class rational {
  public:
    int64_t nume, deno;
    rational(): nume(0), deno(1){}
    rational(int64_t num): nume(num), deno(1){}
    rational(int64_t num, int64_t den){
      int64_t g = std::gcd(num, den);
      nume = num / g;
      deno = den / g;
      if(deno < 0){
        nume = -nume;
        deno = -deno;
      }
    }

    auto operator+(const rational &b){
      int64_t l = std::lcm((*this).deno, b.deno);
      return rational(l / (*this).deno * (*this).nume + l / b.deno * b.nume, l);
    }

    auto operator-(const rational &b){
      int64_t l = std::lcm((*this).deno, b.deno);
      return rational(l / (*this).deno * (*this).nume - l / b.deno * b.nume, l);
    }

    auto operator*(const rational &b){
      return rational((*this).nume * b.nume, (*this).deno * b.deno);
    }

    auto operator/(const rational &b){
      return rational((*this).nume * b.deno, (*this).deno * b.nume);
    }

    auto& operator+=(const rational &a){*this = *this + a; return *this;}
    auto& operator-=(const rational &a){*this = *this - a; return *this;}
    auto& operator*=(const rational &a){*this = *this * a; return *this;}
    auto& operator/=(const rational &a){*this = *this / a; return *this;}

    explicit operator double() const {return (double)nume / deno;}
    explicit operator long double() const {return (long double)nume / deno;}
  };

  std::ostream& operator<<(std::ostream &os, const rational &r){
    if(r.deno == 1) os << r.nume;
    else os << r.nume << "/" << r.deno;
    return os;
  }

  auto operator-(const rational &a){return rational(-a.nume, a.deno);}

  bool operator==(const rational &a, const rational &b){return a.nume == b.nume && a.deno == b.deno;}
  bool operator!=(const rational &a, const rational &b){return !(a == b);}
  bool operator<(const rational &a, const rational &b){return a.nume * b.deno < b.nume * a.deno;}
  bool operator<=(const rational &a, const rational &b){return a.nume * b.deno <= b.nume * a.deno;}
  bool operator>(const rational &a, const rational &b){return !(a <= b);}
  bool operator>=(const rational &a, const rational &b){return !(a < b);}

  auto abs(const rational &a){return rational(std::abs(a.nume), std::abs(a.deno));}
}
#line 3 "Mylib/LinearAlgebra/GaussianElimination/gaussian_elimination.cpp"
#include <utility>

/**
 * @title Gaussian elimination
 * @docs gaussian_elimination.md
 */
namespace haar_lib {
  template <typename T>
  int gaussian_elimination(std::vector<std::vector<T>> &a){
    const int h = a.size();
    const int w = a[0].size();
    int rank = 0;

    for(int j = 0; j < w; ++j){
      int pivot = -1;

      for(int i = rank; i < h; ++i){
        if(a[i][j] != 0){
          pivot = i;
          break;
        }
      }

      if(pivot == -1) continue;

      std::swap(a[pivot], a[rank]);

      auto d = a[rank][j];
      for(int k = 0; k < w; ++k) a[rank][k] /= d;

      for(int i = 0; i < h; ++i){
        if(i == rank or a[i][j] == 0) continue;
        auto d = a[i][j];
        for(int k = 0; k < w; ++k){
          a[i][k] -= a[rank][k] * d;
        }
      }

      ++rank;
    }

    return rank;
  }
}
#line 4 "Mylib/String/split.cpp"

/**
 * @title split
 * @docs split.md
 */
namespace haar_lib {
  auto split(const std::string &s, const std::string &delim){
    std::vector<std::string> ret;

    size_t i = 0;
    while(1){
      size_t j = s.find(delim, i);
      if(j == std::string::npos) break;

      ret.push_back(s.substr(i, j - i));

      i = j + delim.size();
    }

    ret.push_back(s.substr(i, s.size() - i));

    return ret;
  }
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
#line 12 "test/aoj/1300/main.test.cpp"

namespace hl = haar_lib;

using result = std::map<std::string, int>;

struct parser : hl::parser {
  parser(const std::string &s): hl::parser(s){}

  std::string atom(){
    std::string ret;
    ret += get_char();
    if(lower()) ret += get_char();

    return ret;
  }

  result factor(){
    result ret;
    if(check_and_ignore('(')){
      ret = expression();
      ignore(')');
    }else{
      ret[atom()] = 1;
    }

    if(digit()){
      int n = get_number<int>();

      for(auto &kv : ret){
        kv.second *= n;
      }
    }

    return ret;
  }

  result expression(){
    result ret = factor();

    while(1){
      if(digit() or alpha() or check('(')){
        result temp = factor();

        for(auto &[k, v] : temp){
          ret[k] += v;
        }
      }else{
        break;
      }
    }

    return ret;
  }

  result run(){
    return expression();
  }
};

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  std::string s;
  while(std::cin >> s){
    if(s == ".") break;

    s.pop_back(); // pop period
    auto a = hl::split(s, "->");
    auto b = hl::split(a[0], "+");
    auto c = hl::split(a[1], "+");

    std::map<std::string, int> atoms;

    std::vector<result> ress;
    for(auto &x : b){
      auto r = parser(x).run();
      for(auto &kv : r){
        atoms[kv.first] = 0;
      }
      ress.push_back(r);
    }
    for(auto &x : c){
      auto r = parser(x).run();
      for(auto &kv : r){
        atoms[kv.first] = 0;
        kv.second = -kv.second;
      }
      ress.push_back(r);
    }

    {
      int i = 0;
      for(auto &kv : atoms){
        kv.second = i++;
      }
    }

    std::vector<std::vector<hl::rational>> mat(atoms.size(), std::vector<hl::rational>(ress.size()));
    for(int i = 0; i < (int)ress.size(); ++i){
      for(auto &[k, v] : ress[i]){
        mat[atoms[k]][i] = v;
      }
    }

    hl::gaussian_elimination(mat);

    const int n = ress.size();
    std::vector<hl::rational> ans(n);

    ans[n - 1] = 1;

    for(int i = (int)atoms.size(); --i >= 0;){
      if(mat[i].back() == 0) continue;

      int k = 0;
      hl::rational coef;
      hl::rational cons;

      for(int j = 0; j < n; ++j){
        if(ans[j] == 0){
          k = j;
          coef = mat[i][j];
        }else{
          cons += mat[i][j] * ans[j];
        }
      }

      ans[k] = -cons / coef;
    }

    int64_t l = 1;
    for(int i = 0; i < n; ++i) l = std::lcm(l, ans[i].deno);

    for(int i = 0; i < n; ++i) ans[i] *= l;

    std::cout << hl::join(ans.begin(), ans.end()) << "\n";
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

