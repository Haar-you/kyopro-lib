#pragma once
#include <vector>
#include <string>
#include <string_view>

namespace haar_lib {
  class knuth_morris_pratt {
    int M_;
    std::string pattern_;
    std::vector<int> table_;

  public:
    knuth_morris_pratt(){}
    knuth_morris_pratt(std::string p): M_(p.size()), pattern_(p), table_(M_ + 1){
      table_[0] = -1;
      table_[1] = 0;

      pattern_.push_back('\0');

      for(int i = 2, j = 0; i <= M_;){
        if(pattern_[i - 1] == pattern_[j]){
          table_[i] = j + 1;
          ++i;
          ++j;
        }else if(j > 0){
          j = table_[j];
        }else{
          table_[i] = 0;
          ++i;
        }
      }
    }

    std::vector<int> match(const std::string_view &s) const {
      std::vector<int> ret;
      const int N = s.size();

      for(int m = 0, i = 0; m + i < N;){
        if(pattern_[i] == s[m + i]){
          ++i;
          if(i == M_){
            ret.push_back(m);
            m += i - table_[i];
            if(i > 0) i = table_[i];
          }
        }else{
          m += i - table_[i];
          if(i > 0) i = table_[i];
        }
      }

      return ret;
    }
  };
}
