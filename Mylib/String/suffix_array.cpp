#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <deque>

/**
 * @title Suffix array
 * @docs suffix_array.md
 */
namespace haar_lib {
  template <typename Container>
  struct SuffixArray {
    Container s;
    int N;
    std::vector<int> data;

    SuffixArray(Container s_): s(s_), N(s.size()), data(N){
      if(N == 1){
        data = {1, 0};
        return;
      }

      s.resize(N + 1);

      std::string LS(N + 1, 'S');
      for(int i = N; --i >= 0;){
        if(s[i] < s[i + 1]) LS[i] = 'S';
        else if(s[i] > s[i + 1]) LS[i] = 'L';
        else LS[i] = LS[i + 1];
      }

      const int bucket_count = *std::max_element(s.begin(), s.end());
      std::vector<int> bucket_size(bucket_count + 1);
      for(auto x : s) bucket_size[x] += 1;

      auto induced_sort =
        [&](std::vector<int> LMS){
          std::vector<int> bucket(N + 1, -1);
          std::vector<bool> is_lms(N + 1);

          std::vector<std::deque<int>> empty(bucket_count + 1);

          for(int i = 0, k = 0; i <= bucket_count; ++i){
            for(int j = 0; j < bucket_size[i]; ++j){
              empty[i].push_back(k);
              ++k;
            }
          }

          std::reverse(LMS.begin(), LMS.end());
          for(auto x : LMS){
            int i = empty[s[x]].back(); empty[s[x]].pop_back();

            bucket[i] = x;
            is_lms[i] = true;
          }

          for(int i = 0; i <= N; ++i){
            if(bucket[i] >= 1 and LS[bucket[i] - 1] == 'L'){
              auto x = s[bucket[i] - 1];
              int j = empty[x].front(); empty[x].pop_front();
              bucket[j] = bucket[i] - 1;
            }
          }

          for(int i = 0; i <= N; ++i){
            if(is_lms[i]){
              bucket[i] = -1;
            }
          }

          for(int i = 0, k = 0; i <= bucket_count; ++i){
            empty[i].clear();

            for(int j = 0; j < bucket_size[i]; ++j){
              empty[i].push_back(k);
              ++k;
            }
          }

          for(int i = N; i >= 0; --i){
            if(bucket[i] >= 1 and LS[bucket[i] - 1] == 'S'){
              auto x = s[bucket[i] - 1];
              int j = empty[x].back(); empty[x].pop_back();
              bucket[j] = bucket[i] - 1;
            }
          }

          bucket[0] = N;
          return bucket;
        };

      std::vector<int> LMS;
      for(int i = 1; i <= N; ++i){
        if(LS[i] == 'S' and LS[i - 1] == 'L'){
          LMS.push_back(i);
        }
      }

      std::vector<int> LMS_bucket_length(N + 1, 1);
      for(int i = 0; i < (int)LMS.size() - 1; ++i){
        LMS_bucket_length[LMS[i]] = LMS[i + 1] - LMS[i] + 1;
      }

      auto bucket = induced_sort(LMS);

      std::vector<int> LMS_substr_sorted;
      for(int i : bucket){
        if(i > 0 and LS[i - 1] == 'L' and LS[i] == 'S'){
          LMS_substr_sorted.push_back(i);
        }
      }

      std::vector<int> rank(N + 1);
      rank[LMS_substr_sorted[0]] = 1;

      for(int i = 1, k = 1; i < (int)LMS_substr_sorted.size(); ++i){
        const int x = LMS_substr_sorted[i - 1], y = LMS_substr_sorted[i];

        bool eq = true;
        if(LMS_bucket_length[x] != LMS_bucket_length[y]) eq = false;
        else{
          for(int j = 0; j < LMS_bucket_length[x]; ++j){
            if(s[x + j] != s[y + j]) eq = false;
          }
        }

        if(not eq) ++k;
        rank[y] = k;
      }

      std::vector<int> t;
      for(int i = 0; i <= N; ++i){
        if(rank[i] != 0) t.push_back(rank[i]);
      }

      auto sa = SuffixArray<std::vector<int>>(t).data;

      std::vector<int> LMS_sorted;
      for(int i = 1; i < (int)sa.size(); ++i){
        LMS_sorted.push_back(LMS[sa[i]]);
      }

      data = induced_sort(LMS_sorted);
    }

    int operator[](size_t i) const {return data[i];}
    auto begin() const {return data.begin();}
    auto end() const {return data.end();}
    size_t size() const {return data.size();}

    int lower_bound(const Container &s_) const {
      auto check =
        [&](int x){
          for(int i = 0; i < (int)s_.size(); ++i){
            if(data[x] + i >= (int)s.size()) return false;
            if(s_[i] < s[data[x] + i]) return true;
            if(s_[i] > s[data[x] + i]) return false;
          }
          return true;
        };

      int lb = -1, ub = size();
      while(abs(lb - ub) > 1){
        int mid = (lb + ub) / 2;
        if(check(mid)) ub = mid;
        else lb = mid;
      }

      return ub;
    }

    int upper_bound(const Container &s_) const {
      Container t(s_);

      ++t.back();
      int ret = lower_bound(t);

      return ret;
    }
  };
}
