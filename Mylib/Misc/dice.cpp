#pragma once
#include <iostream>

namespace haar_lib {
  struct dice {
    int top, bottom, front, back, right, left;

    dice() : top(), bottom(), front(), back(), right(), left() {}
    dice(int top, int bottom, int front, int back, int right, int left) : top(top), bottom(bottom), front(front), back(back), right(right), left(left) {}

    dice rot_left() const {
      return dice(right, left, front, back, bottom, top);
    }

    dice rot_right() const {
      return dice(left, right, front, back, top, bottom);
    }

    dice rot_front() const {
      return dice(back, front, top, bottom, right, left);
    }

    dice rot_back() const {
      return dice(front, back, bottom, top, right, left);
    }

    dice rot_clockwise() const {
      return dice(top, bottom, right, left, back, front);
    }

    dice rot_counterclockwise() const {
      return dice(top, bottom, left, right, front, back);
    }

    friend std::ostream &operator<<(std::ostream &s, const dice &a) {
      s << "("
        << a.top << ", "
        << a.bottom << ", "
        << a.front << ", "
        << a.back << ", "
        << a.right << ", "
        << a.left << ")";
      return s;
    }
  };
}  // namespace haar_lib
