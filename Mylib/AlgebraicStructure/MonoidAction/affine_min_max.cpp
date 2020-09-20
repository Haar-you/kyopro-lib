#pragma once

namespace haar_lib {
  template <typename MonoidGet, typename MonoidUpdate>
  struct affine_min_max {
    using value_type_get = typename MonoidGet::value_type;
    using value_type_update = typename MonoidUpdate::value_type;

    value_type_get operator()(const value_type_get &a, const value_type_update &b, int) const {
      value_type_get ret;
      if(b.first >= 0){
        if(a.min) ret.min = b.first * (a.min.value()) + b.second;
        if(a.max) ret.max = b.first * (a.max.value()) + b.second;
      }else{
        if(a.min) ret.max = b.first * (a.min.value()) + b.second;
        if(a.max) ret.min = b.first * (a.max.value()) + b.second;
      }

      return ret;
    }
  };
}
