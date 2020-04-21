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
    - Last commit date: 2020-04-22 05:49:57+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1300">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1300</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/LinearAlgebra/GaussianElimination/gaussian_elimination.cpp.html">掃き出し法</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Number/Rational/rational.cpp.html">有理数クラス</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Parser/parser.cpp.html">構文解析</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/String/split.cpp.html">文字列のsplit関数</a>


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

using result = std::map<std::string, int>;

struct parser : Parser{
  parser(const std::string &s): Parser(s){}

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
    auto a = split(s, "->");
    auto b = split(a[0], "+");
    auto c = split(a[1], "+");

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

    std::vector<std::vector<Rational>> mat(atoms.size(), std::vector<Rational>(ress.size()));
    for(int i = 0; i < (int)ress.size(); ++i){
      for(auto &[k, v] : ress[i]){
        mat[atoms[k]][i] = v;
      }
    }

    gaussian_elimination(mat);
    
    const int n = ress.size();
    std::vector<Rational> ans(n);

    ans[n-1] = 1;

    for(int i = (int)atoms.size()-1; i >= 0; --i){
      if(mat[i].back() == 0) continue;

      int k = 0;
      Rational coef;
      Rational cons;

      for(int j = 0; j < n; ++j){
        if(ans[j] == 0){
          k = j;
          coef = mat[i][j];
        }else{
          cons += mat[i][j] * ans[j];
        }
      }

      ans[k] = -cons/coef;
    }

    int64_t l = 1;
    for(int i = 0; i < n; ++i) l = std::lcm(l, ans[i].deno);

    for(int i = 0; i < n; ++i) ans[i] *= l;

    for(int i = 0; i < (int)ans.size(); ++i){
      if(i) std::cout << " ";
      std::cout << ans[i];
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
#line 1 "test/aoj/1300/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1300"

#include <iostream>
#include <map>
#include <string>
#include <vector>

#line 2 "Mylib/Parser/parser.cpp"

#line 4 "Mylib/Parser/parser.cpp"
#include <cassert>

/**
 * @title 構文解析
 */
struct Parser{
  using state = std::string::const_iterator;
  
  state cur, first, last;

  Parser(){}
  Parser(const std::string &s): cur(s.cbegin()), first(s.cbegin()), last(s.cend()){}
  
  inline char peek() const {return *cur;}
  
  inline bool check(char c) const {
    return *cur == c;
  }
  
  inline bool check(const std::string &s) const {
    state temp = cur;
    for(auto c : s){
      if(c != *temp) return false;
      ++temp;
    }
    return true;
  }
  
  inline void ignore(char c){
    assert(*cur == c);
    ++cur;
  }
  
  inline void ignore(){
    ++cur;
  }
  
  inline void ignore(const std::string &s){
    for(auto c : s){
      assert(*cur == c);
      ++cur;
    }
  }
  
  template <class Checker>
  inline void ignore_if(const Checker &f){
    assert(f(*cur));
    ++cur;
  }

  inline bool check_and_ignore(char c){
    if(*cur != c) return false;
    ++cur;
    return true;
  }

  inline bool end() const {return cur == last;}
  inline bool digit() const {return isdigit(*cur);}
  inline bool alpha() const {return isalpha(*cur);}
  inline bool lower() const {return islower(*cur);}
  inline bool upper() const {return isupper(*cur);}
    
  inline char get_char(){
    return *(cur++);
  }
  
  inline int get_digit(){
    return (int)(*(cur++)-'0');
  }
  
  template <typename Checker>
  inline auto get_string(const Checker &f){
    std::string ret;
    while(f(peek())){
      ret += peek();
      ignore();
    }
    return ret;
  }
  
  inline auto get_string_alpha(){
    std::string ret;
    while(isalpha(*cur)){
      ret += *cur;
      ++cur;
    }
    return ret;
  }
  
  inline auto get_string_alnum(){
    std::string ret;
    while(isalnum(*cur)){
      ret += *cur;
      ++cur;
    }
    return ret;
  }
  
  template <typename T>
  inline T get_number(){
    T ret = get_digit();
    while(digit()){
      (ret *= 10) += (T)(get_digit());
    }
    return ret;
  }
};
#line 2 "Mylib/Number/Rational/rational.cpp"
#include <numeric>
#line 4 "Mylib/Number/Rational/rational.cpp"

/**
 * @title 有理数クラス
 */
class Rational{
public:
  int64_t nume, deno;
  Rational(): nume(0), deno(1){}
  Rational(int64_t num): nume(num), deno(1){} 
  Rational(int64_t num, int64_t den){
    int64_t g = std::gcd(num,den);
    nume = num/g;
    deno = den/g;
    if(deno < 0){
      nume = -nume;
      deno = -deno;
    }
  }
  Rational& operator+=(const Rational &a);
  Rational& operator-=(const Rational &a);
  Rational& operator*=(const Rational &a);
  Rational& operator/=(const Rational &a);
};

std::ostream& operator<<(std::ostream &os, const Rational &r){
  if(r.deno == 1){
    os << r.nume;
  }else{
    os << r.nume << "/" << r.deno;
  }
  
  return os;
}

Rational operator-(const Rational &a){return Rational(-a.nume, a.deno);}

Rational operator+(const Rational &a, const Rational &b){int64_t l = std::lcm(a.deno,b.deno); return Rational(l/a.deno*a.nume + l/b.deno*b.nume, l);}
Rational operator-(const Rational &a, const Rational &b){int64_t l = std::lcm(a.deno,b.deno); return Rational(l/a.deno*a.nume - l/b.deno*b.nume, l);}
Rational operator*(const Rational &a, const Rational &b){return Rational(a.nume*b.nume, a.deno*b.deno);}
Rational operator/(const Rational &a, const Rational &b){return Rational(a.nume*b.deno, a.deno*b.nume);}

bool operator==(const Rational &a, const Rational &b){return a.nume == b.nume && a.deno == b.deno;}
bool operator!=(const Rational &a, const Rational &b){return !(a==b);}
bool operator<(const Rational &a, const Rational &b){return a.nume*b.deno < b.nume*a.deno;}
bool operator<=(const Rational &a, const Rational &b){return a.nume*b.deno <= b.nume*a.deno;}
bool operator>(const Rational &a, const Rational &b){return !(a<=b);}
bool operator>=(const Rational &a, const Rational &b){return !(a<b);}

double to_double(const Rational &a){return (double)a.nume/a.deno;}

Rational& Rational::operator+=(const Rational &a){*this = *this+a; return *this;}
Rational& Rational::operator-=(const Rational &a){*this = *this-a; return *this;}
Rational& Rational::operator*=(const Rational &a){*this = *this*a; return *this;}
Rational& Rational::operator/=(const Rational &a){*this = *this/a; return *this;}

Rational abs(const Rational &a){return Rational(abs(a.nume), abs(a.deno));}
#line 3 "Mylib/LinearAlgebra/GaussianElimination/gaussian_elimination.cpp"
#include <utility>

/**
 * @title 掃き出し法
 */
template <typename T> int gaussian_elimination(std::vector<std::vector<T>> &a){
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
#line 4 "Mylib/String/split.cpp"

/**
 * @title 文字列のsplit関数
 */
auto split(const std::string &s, const std::string &delim){
  std::vector<std::string> ret;

  size_t i = 0;
  while(1){
    size_t j = s.find(delim, i);
    if(j == std::string::npos) break;

    ret.push_back(s.substr(i,j-i));

    i = j + delim.size();
  }

  ret.push_back(s.substr(i,s.size()-i));

  return ret;
}
#line 12 "test/aoj/1300/main.test.cpp"

using result = std::map<std::string, int>;

struct parser : Parser{
  parser(const std::string &s): Parser(s){}

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
    auto a = split(s, "->");
    auto b = split(a[0], "+");
    auto c = split(a[1], "+");

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

    std::vector<std::vector<Rational>> mat(atoms.size(), std::vector<Rational>(ress.size()));
    for(int i = 0; i < (int)ress.size(); ++i){
      for(auto &[k, v] : ress[i]){
        mat[atoms[k]][i] = v;
      }
    }

    gaussian_elimination(mat);
    
    const int n = ress.size();
    std::vector<Rational> ans(n);

    ans[n-1] = 1;

    for(int i = (int)atoms.size()-1; i >= 0; --i){
      if(mat[i].back() == 0) continue;

      int k = 0;
      Rational coef;
      Rational cons;

      for(int j = 0; j < n; ++j){
        if(ans[j] == 0){
          k = j;
          coef = mat[i][j];
        }else{
          cons += mat[i][j] * ans[j];
        }
      }

      ans[k] = -cons/coef;
    }

    int64_t l = 1;
    for(int i = 0; i < n; ++i) l = std::lcm(l, ans[i].deno);

    for(int i = 0; i < n; ++i) ans[i] *= l;

    for(int i = 0; i < (int)ans.size(); ++i){
      if(i) std::cout << " ";
      std::cout << ans[i];
    }
    std::cout << "\n";
  }
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

