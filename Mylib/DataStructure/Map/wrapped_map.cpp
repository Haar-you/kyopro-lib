#pragma once
#include <map>
#include <functional>
#include <algorithm>

namespace haar_lib {
  template <typename Key, typename Value, typename Compare = std::less<Key>>
  class wrapped_map : public std::map<Key, Value, Compare> {
    using super = std::map<Key, Value, Compare>;

  public:
    const auto& max_key() const {
      assert(not super::empty());
      return *super::rbegin();
    }

    const auto& min_key() const {
      assert(not super::empty());
      return *super::begin();
    }

    bool contains_key(const Key &x) const {
      return super::find(x) != super::end();
    }

    const auto& max_value() const {
      assert(not super::empty());
      return *std::max_element(
        super::begin(), super::end(),
        [](const auto &a, const auto &b){return a.second < b.second;}
      );
    }

    const auto& min_value() const {
      assert(not super::empty());
      return *std::min_element(
        super::begin(), super::end(),
        [](const auto &a, const auto &b){return a.second < b.second;}
      );
    }

    template <typename Predicate>
    void erase_if(Predicate pred){
      for(auto it = super::begin(); it != super::end();){
        if(pred(it->first, it->second)) it = super::erase(it);
        else ++it;
      }
    }
  };
}
