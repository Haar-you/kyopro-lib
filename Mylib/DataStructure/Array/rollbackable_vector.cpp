#pragma once
#include <initializer_list>
#include <iostream>
#include <utility>
#include <variant>
#include <vector>

namespace haar_lib {
  template <typename T>
  class rollbackable_vector {
  public:
    using value_type = T;

  private:
    std::vector<T> data_;

    using Update = std::pair<T, int>;
    struct PushBack {};
    using PopBack = T;

    std::vector<std::variant<Update, PushBack, PopBack>> history_;

  public:
    rollbackable_vector() {}
    rollbackable_vector(size_t n) : data_(n) {}
    rollbackable_vector(std::vector<T> a) : data_(a) {}
    rollbackable_vector(std::initializer_list<T> a) : data_(a.begin(), a.end()) {}

    void push_back(const T& value) {
      history_.push_back(PushBack());
      data_.push_back(value);
    }

    void pop_back() {
      history_.push_back(PopBack(data_.back()));
      data_.pop_back();
    }

    void set(int i, const T& value) {
      history_.push_back(Update(data_[i], i));
      data_[i] = value;
    }

    void roll_back() {
      if (std::holds_alternative<Update>(history_.back())) {
        auto [value, i] = std::get<Update>(history_.back());
        data_[i]        = value;
      } else if (std::holds_alternative<PushBack>(history_.back())) {
        data_.pop_back();
      } else if (std::holds_alternative<PopBack>(history_.back())) {
        auto value = std::get<PopBack>(history_.back());
        data_.push_back(value);
      }

      history_.pop_back();
    }

    bool rollbackable() const {
      return not history_.empty();
    }

    const value_type& operator[](int i) const { return data_[i]; }

    auto cbegin() const { return data_.cbegin(); }
    auto cend() const { return data_.cend(); }

    int size() const { return data_.size(); }
    bool empty() const { return data_.empty(); }

    const T& back() const { return data_.back(); }
    const T& front() const { return data_.front(); }

    const auto& data() const { return data_; }
  };
}  // namespace haar_lib
