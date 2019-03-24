#ifndef LEETCODECPP_INTERVAL_H
#define LEETCODECPP_INTERVAL_H

namespace lcpp {

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

inline bool operator==(const Interval &I1, const Interval &I2) {
  return I1.start == I2.start && I1.end == I2.end;
}

}

#endif //LEETCODECPP_INTERVAL_H
