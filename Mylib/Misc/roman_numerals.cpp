#pragma once
#include <string>

namespace haar_lib::misn {
  int roman_to_num(std::string s){
    int ret = 0;

    for(int i = 0; i < (int)s.size(); ++i){
      switch(s[i]){
      case 'I': {
        if(i + 1 < (int)s.size() and (s[i + 1] == 'V' or s[i + 1] == 'X')){
          ret -= 1;
        }else{
          ret += 1;
        }
        break;
      }

      case 'V': ret += 5; break;

      case 'X': {
        if(i + 1 < (int)s.size() and (s[i + 1] == 'L' or s[i + 1] == 'C')){
          ret -= 10;
        }else{
          ret += 10;
        }
        break;
      }

      case 'L': ret += 50; break;

      case 'C': {
        if(i + 1 < (int)s.size() and (s[i + 1] == 'D' or s[i + 1] == 'M')){
          ret -= 100;
        }else{
          ret += 100;
        }
        break;
      }

      case 'D': ret += 500; break;

      case 'M': ret += 1000; break;
      }
    }

    return ret;
  }

  std::string num_to_roman(int n){
    std::string ret = "";

    if(n >= 1000){
      int k = n / 1000;
      ret += std::string(k, 'M');
      n %= 1000;
    }

    if(n >= 100){
      int k = n / 100;
      if(k <= 3) ret += std::string(k, 'C');
      else if(k == 4) ret += "CD";
      else if(k <= 8) ret += "D" + std::string(k - 5, 'C');
      else ret += "CM";

      n %= 100;
    }

    if(n >= 10){
      int k = n / 10;
      if(k <= 3) ret += std::string(k, 'X');
      else if(k == 4) ret += "XL";
      else if(k <= 8) ret += "L" + std::string(k - 5, 'X');
      else ret += "XC";

      n %= 10;
    }

    int k = n;
    if(k <= 3) ret += std::string(k, 'I');
    else if(k == 4) ret += "IV";
    else if(k <= 8) ret += "V" + std::string(k - 5, 'I');
    else ret += "IX";

    return ret;
  }
}
