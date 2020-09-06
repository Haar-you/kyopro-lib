#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2401"

#include <iostream>
#include <string>
#include "Mylib/Parser/parser.cpp"

struct parser : Parser {
  parser(const std::string &s): Parser(s){}

  bool constant(){
    bool ret = check('T');
    ignore();
    return ret;
  }

  bool negate(){
    ignore('-');
    return !expression();
  }

  std::string get_op(){
    if(check_and_ignore('*')) return "*";
    if(check_and_ignore('+')) return "+";
    ignore("->"); return "->";
  }

  bool term(){
    ignore('(');
    bool left = expression();
    auto op = get_op();
    bool right = expression();
    ignore(')');

    if(op == "*") return left && right;
    else if(op == "+") return left || right;
    else return !left || right;
  }

  bool expression(){
    if(check('(')) return term();
    if(check('-')) return negate();
    return constant();
  }

  bool run(){
    bool left = expression();
    ignore('=');
    bool right = expression();
    return left == right;
  }
};

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  std::string s;
  while(std::cin >> s){
    if(s == "#") break;

    bool ans = true;

    for(int i = 0; i < 1 << 11; ++i){
      std::string t(s);

      for(auto &ch : t){
        if(ch >= 'a' and ch <= 'k'){
          ch = i & (1 << (ch-'a')) ? 'T' : 'F';
        }
      }

      ans = ans and parser(t).run();
    }

    std::cout << (ans ? "YES" : "NO") << "\n";
  }

  return 0;
}
