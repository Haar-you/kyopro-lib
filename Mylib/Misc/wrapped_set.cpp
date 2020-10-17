#pragma once
#include <set>
#include <functional>

template <typename T, typename Compare = std::less<T>>
class wrapped_set : public std::set<T, Compare> {
  using super = std::set<T, Compare>;

public:
  const T& max() const {
    assert(not super::empty());
    return *super::rbegin();
  }

  const T& min() const {
    assert(not super::empty());
    return *super::begin();
  }
};
