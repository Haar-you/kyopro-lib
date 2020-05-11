#pragma once
#include "Mylib/Geometry/Float/geometry_template.cpp"

/**
 * @title 線分・点間の距離
 * @docs distance_segment_point.md
 */
template <typename T>
T distance_segment_point(const Segment<T> &l, const Point<T> &p){
  if(dot(diff(l), p - l.from) < 0) return abs(p - l.from);
  if(dot(-diff(l), p - l.to) < 0) return abs(p - l.to);
  return abs(cross(diff(l), p - l.from)) / abs(l);
}
