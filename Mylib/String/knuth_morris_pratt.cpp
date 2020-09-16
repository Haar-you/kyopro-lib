#pragma once
#include <vector>
#include <string>
#include <string_view>

namespace haar_lib {
  struct knuth_morris_pratt {
    int M;
    std::string pattern;
    std::vector<int> table;

    knuth_morris_pratt(std::string p): M(p.size()), pattern(p), table(M + 1){
      table[0] = -1;
      table[1] = 0;

      pattern.push_back('\0');

      for(int i = 2, j = 0; i <= M;){
        if(pattern[i - 1] == pattern[j]){
          table[i] = j + 1;
          ++i;
          ++j;
        }else if(j > 0){
          j = table[j];
        }else{
          table[i] = 0;
          ++i;
        }
      }
    }

    std::vector<int> match(const std::string_view &s) const {
      std::vector<int> ret;
      const int N = s.size();

      for(int m = 0, i = 0; m + i < N;){
        if(pattern[i] == s[m + i]){
          ++i;
          if(i == M){
            ret.push_back(m);
            m += i - table[i];
            if(i > 0) i = table[i];
          }
        }else{
          m += i - table[i];
          if(i > 0) i = table[i];
        }
      }

      return ret;
    }
  };
}
