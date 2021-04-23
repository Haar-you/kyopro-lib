#pragma once
#include <algorithm>
#include <deque>
#include <string>
#include <vector>

namespace haar_lib {
  template <typename Container>
  class suffix_array {
    Container s_;
    int N_;
    std::vector<int> data_;

  public:
    suffix_array() {}
    suffix_array(Container s) : s_(s), N_(s_.size()), data_(N_) {
      if (N_ == 1) {
        data_ = {1, 0};
        return;
      }

      s_.resize(N_ + 1);

      std::string LS(N_ + 1, 'S');
      for (int i = N_; --i >= 0;) {
        if (s_[i] < s_[i + 1])
          LS[i] = 'S';
        else if (s_[i] > s_[i + 1])
          LS[i] = 'L';
        else
          LS[i] = LS[i + 1];
      }

      const int bucket_count = *std::max_element(s_.begin(), s_.end());
      std::vector<int> bucket_size(bucket_count + 1);
      for (auto x : s_) bucket_size[x] += 1;

      auto induced_sort =
          [&](std::vector<int> LMS) {
            std::vector<int> bucket(N_ + 1, -1);
            std::vector<bool> is_lms(N_ + 1);

            std::vector<std::deque<int>> empty(bucket_count + 1);

            for (int i = 0, k = 0; i <= bucket_count; ++i) {
              for (int j = 0; j < bucket_size[i]; ++j) {
                empty[i].push_back(k);
                ++k;
              }
            }

            std::reverse(LMS.begin(), LMS.end());
            for (auto x : LMS) {
              int i = empty[s_[x]].back();
              empty[s_[x]].pop_back();

              bucket[i] = x;
              is_lms[i] = true;
            }

            for (int i = 0; i <= N_; ++i) {
              if (bucket[i] >= 1 and LS[bucket[i] - 1] == 'L') {
                auto x = s_[bucket[i] - 1];
                int j  = empty[x].front();
                empty[x].pop_front();
                bucket[j] = bucket[i] - 1;
              }
            }

            for (int i = 0; i <= N_; ++i) {
              if (is_lms[i]) {
                bucket[i] = -1;
              }
            }

            for (int i = 0, k = 0; i <= bucket_count; ++i) {
              empty[i].clear();

              for (int j = 0; j < bucket_size[i]; ++j) {
                empty[i].push_back(k);
                ++k;
              }
            }

            for (int i = N_; i >= 0; --i) {
              if (bucket[i] >= 1 and LS[bucket[i] - 1] == 'S') {
                auto x = s_[bucket[i] - 1];
                int j  = empty[x].back();
                empty[x].pop_back();
                bucket[j] = bucket[i] - 1;
              }
            }

            bucket[0] = N_;
            return bucket;
          };

      std::vector<int> LMS;
      for (int i = 1; i <= N_; ++i) {
        if (LS[i] == 'S' and LS[i - 1] == 'L') {
          LMS.push_back(i);
        }
      }

      std::vector<int> LMS_bucket_length(N_ + 1, 1);
      for (int i = 0; i < (int) LMS.size() - 1; ++i) {
        LMS_bucket_length[LMS[i]] = LMS[i + 1] - LMS[i] + 1;
      }

      auto bucket = induced_sort(LMS);

      std::vector<int> LMS_substr_sorted;
      for (int i : bucket) {
        if (i > 0 and LS[i - 1] == 'L' and LS[i] == 'S') {
          LMS_substr_sorted.push_back(i);
        }
      }

      std::vector<int> rank(N_ + 1);
      rank[LMS_substr_sorted[0]] = 1;

      for (int i = 1, k = 1; i < (int) LMS_substr_sorted.size(); ++i) {
        const int x = LMS_substr_sorted[i - 1], y = LMS_substr_sorted[i];

        bool eq = true;
        if (LMS_bucket_length[x] != LMS_bucket_length[y])
          eq = false;
        else {
          for (int j = 0; j < LMS_bucket_length[x]; ++j) {
            if (s_[x + j] != s_[y + j]) eq = false;
          }
        }

        if (not eq) ++k;
        rank[y] = k;
      }

      std::vector<int> t;
      for (int i = 0; i <= N_; ++i) {
        if (rank[i] != 0) t.push_back(rank[i]);
      }

      auto sa = suffix_array<std::vector<int>>(t);

      std::vector<int> LMS_sorted;
      for (int i = 1; i < (int) sa.size(); ++i) {
        LMS_sorted.push_back(LMS[sa[i]]);
      }

      data_ = induced_sort(LMS_sorted);
    }

    int operator[](size_t i) const { return data_[i]; }
    auto begin() const { return data_.begin(); }
    auto end() const { return data_.end(); }
    size_t size() const { return data_.size(); }
    const auto& data() const { return data_; }
    const auto& str() const { return s_; }

    int lower_bound(const Container& a) const {
      auto check =
          [&](int x) {
            for (int i = 0; i < (int) a.size(); ++i) {
              if (data_[x] + i >= (int) s_.size()) return false;
              if (a[i] < s_[data_[x] + i]) return true;
              if (a[i] > s_[data_[x] + i]) return false;
            }
            return true;
          };

      int lb = -1, ub = size();
      while (std::abs(lb - ub) > 1) {
        int mid = (lb + ub) / 2;
        if (check(mid))
          ub = mid;
        else
          lb = mid;
      }

      return ub;
    }

    int upper_bound(const Container& s) const {
      Container t(s);

      ++t.back();
      int ret = lower_bound(t);

      return ret;
    }
  };
}  // namespace haar_lib
