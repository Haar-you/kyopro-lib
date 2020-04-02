#pragma once

/**
 * @title サイコロ
 */
struct Dice{
  int top, bottom, left, right, front, back;

  Dice(){}
  Dice(int top, int bottom, int left, int right, int front, int back):
    top(top), bottom(bottom), left(left), right(right), front(front), back(back){}

  Dice rot_left() const {
    return Dice(right, left, top, bottom, front, back);
  }

  Dice rot_right() const {
    return Dice(left, right, bottom, top, front, back);
  }

  Dice rot_front() const {
    return Dice(back, front, left, right, top, bottom);
  }
  
  Dice rot_back() const {
    return Dice(front, back, left, right, bottom, top);
  }
};
