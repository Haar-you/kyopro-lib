#pragma once
#include <iostream>
#include <string>

namespace haar_lib {
  template <typename T, unsigned int D>
  T get_decimal(){
    T ret = 0;
    bool minus = false;

    std::string s; std::cin >> s;

    auto it = s.begin();

    while(it != s.end() and std::isspace(*it)){
      it += 1;
    }

    if(it != s.end() and *it == '-'){
      minus = true;
      it += 1;
    }

    while(it != s.end() and std::isdigit(*it)){
      ret = ret * 10 + (int)(*it - '0');
      it += 1;
    }

    int r = 0;
    if(it != s.end() and *it == '.'){
      it += 1;

      while(r < (int)D and it != s.end() and std::isdigit(*it)){
        ret = ret * 10 + (int)(*it - '0');
        it += 1;
        r += 1;
      }
    }

    for(int i = 0; i < (int)D - r; ++i){
      ret = ret * 10;
    }

    if(minus) ret = -ret;

    return ret;
  }
}
