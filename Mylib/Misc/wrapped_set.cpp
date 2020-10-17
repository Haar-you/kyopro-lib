#pragma once
#include <set>
#include <functional>

namespace haar_lib {
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

    bool contains(const T &x) const {
      return super::find(x) != super::end();
    }

    template <typename Predicate>
    void erase_if(Predicate pred){
      for(auto it = super::begin(); it != super::end();){
        if(pred(*it)) it = super::erase(it);
        else ++it;
      }
    }
  };
}
