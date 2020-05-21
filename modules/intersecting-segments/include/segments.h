// Copyright 2020 Kukushkina Ksenia & Maximova Irina

#ifndef MODULES_INTERSECTING_SEGMENTS_INCLUDE_SEGMENTS_H_
#define MODULES_INTERSECTING_SEGMENTS_INCLUDE_SEGMENTS_H_

#include <utility>

class Segment {
  using pair = std::pair<double, double>;

 public:
  Segment(double _x1, double _y1, double _x2, double _y2);
  Segment(pair coord_1, pair coord_2);

  double area(double x, double y) const;
  bool isIntersect(const Segment& A) const;

 private:
  double x1;
  double y1;
  double x2;
  double y2;
};

#endif  // MODULES_INTERSECTING_SEGMENTS_INCLUDE_SEGMENTS_H_
