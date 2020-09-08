#pragma once
#include <iostream>

/**
 * @title Dice
 * @docs dice.md
 */
namespace haar_lib {
  struct Dice {
    int top, bottom, front, back, right, left;

    Dice(): top(), bottom(), front(), back(), right(), left(){}
    Dice(int top, int bottom, int front, int back, int right, int left):
      top(top), bottom(bottom), front(front), back(back), right(right), left(left){}

    Dice rot_left() const {
      return Dice(right, left, front, back, bottom, top);
    }

    Dice rot_right() const {
      return Dice(left, right, front, back, top, bottom);
    }

    Dice rot_front() const {
      return Dice(back, front, top, bottom, right, left);
    }

    Dice rot_back() const {
      return Dice(front, back, bottom, top, right, left);
    }

    Dice rot_clockwise() const {
      return Dice(top, bottom, right, left, back, front);
    }

    Dice rot_counterclockwise() const {
      return Dice(top, bottom, left, right, front, back);
    }

    friend std::ostream& operator<<(std::ostream &s, const Dice &a){
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
}
