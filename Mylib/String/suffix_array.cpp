#pragma once
#include <vector>
#include <tuple>

/**
 * @title Suffix array
 * @docs suffix_array.md
 */
template <typename T> class SuffixArray{
public:
  const T str;
  const int n;
  std::vector<int> suffix_array;
  
  const int ALPHABET = 256;
  
  SuffixArray(const T &s): str(s), n(s.size()), suffix_array(n){
    std::vector<int> temp(n);
    for(int i = 0; i < n; ++i) temp[i] = s[i];

    {
      std::vector<int> table(ALPHABET);
      for(auto c : s) table[c] = 1;
      for(int i = 1; i < ALPHABET; ++i) table[i] += table[i-1];

      for(int i = 0; i < n; ++i){
        temp[i] = table[s[i]]; 
      }
    }

    for(int l = 1; l < n; l *= 2){
      std::vector<std::tuple<int,int,int>> m(n);
      for(int i = 0; i < n; ++i){
        m[i] = std::make_tuple(temp[i], i+l >= n ? 0 : temp[i + l], i);
      }
      
      {
        std::vector<std::vector<std::tuple<int,int,int>>> table(n+1);

        for(int i = 0; i < n; ++i){
          table[std::get<1>(m[i])].push_back(m[i]);
        }

        m.clear();

        for(int i = 0; i <= n; ++i){
          for(auto &t : table[i]){
            m.push_back(t);
          }
        }
      }
      
      {
        std::vector<std::vector<std::tuple<int,int,int>>> table(n+1);

        for(int i = 0; i < n; ++i){
          table[std::get<0>(m[i])].push_back(m[i]);
        }

        m.clear();

        for(int i = 0; i <= n; ++i){
          for(auto &t : table[i]){
            m.push_back(t);
          }
        }
      }
      
      int h = 1;
      for(int i = 0; i < n; ++i){
        if(i > 0 and (std::get<0>(m[i-1]) != std::get<0>(m[i]) or std::get<1>(m[i-1]) != std::get<1>(m[i]))){
          ++h;
        }
        
        temp[std::get<2>(m[i])] = h;
      }
    }
    
    for(int i = 0; i < n; ++i) suffix_array[temp[i]-1] = i;
  }

  int operator[](int i) const {return suffix_array[i];}

  bool starts_with(const T &s, int k) const {
    if(s.size() <= str.size() - k){
      for(int i = 0; i < (int)s.size(); ++i){
        if(s[i] != str[k+i]) return false;
      }
      return true;
    }
    return false;
  }

  int lower_bound(const T &s) const {
    auto check =
      [&](int x){
        for(int i = 0; i < (int)s.size(); ++i){
          if(suffix_array[x]+i >= (int)str.size()) return false;
          if(s[i] < str[suffix_array[x]+i]) return true;
          if(s[i] > str[suffix_array[x]+i]) return false;
        }
        return true;
      };

    int lb = -1, ub = n;
    while(abs(lb-ub) > 1){
      int mid = (lb+ub)/2;

      if(check(mid)){
        ub = mid;
      }else{
        lb = mid;
      }
    }
    
    return ub;
  }

  int upper_bound(const T &s) const {
    T t(s);

    t.back()++;
    int ret = lower_bound(t);
    t.back()--;
    return ret;
  }
};
