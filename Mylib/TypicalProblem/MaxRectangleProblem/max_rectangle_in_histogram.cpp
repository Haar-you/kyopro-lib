#pragma once
#include <vector>
#include <stack>
#include <utility>

/**
 * @title Largest rectangle in histogram
 * @docs max_rectangle_in_histogram.md
 */
namespace haar_lib {
  template <typename T>
  T max_rectangle_in_histogram(const std::vector<T> &h){
    std::stack<std::pair<T, int>> st;
    T ret = 0;

    for(size_t i = 0; i < h.size(); ++i){
      if(st.empty()){
        st.emplace(h[i], i);
      }else if(st.top().first < h[i]){
        st.emplace(h[i], i);
      }else if(st.top().first > h[i]){
        int j = i;
        while(not st.empty() and st.top().first > h[i]){
          ret = std::max(ret, st.top().first * ((T)i - st.top().second));
          j = st.top().second;
          st.pop();
        }
        st.emplace(h[i], j);
      }
    }

    while(not st.empty()){
      ret = std::max(ret, st.top().first * ((T)h.size() - st.top().second));
      st.pop();
    }

    return ret;
  }
}
