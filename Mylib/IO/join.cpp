#pragma once
#include <iostream>
#include <sstream>
#include <string>

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
