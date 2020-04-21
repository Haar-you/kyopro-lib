#pragma once

#include <string>
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
