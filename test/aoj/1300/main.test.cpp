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
