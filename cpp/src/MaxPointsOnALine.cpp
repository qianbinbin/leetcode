#include "MaxPointsOnALine.h"
#include <cstdint>
#include <limits>
#include <unordered_map>

using namespace lcpp;

struct Slope {
  const int DeltaX;
  const int DeltaY;
  const std::size_t Hash;

  Slope(const Point &P1, const Point &P2) :
      DeltaX(P1.x - P2.x), DeltaY(P1.y - P2.y),
      Hash(hash(DeltaX, DeltaY)) {
  }

  inline std::size_t hash(int Dx, int Dy) {
    double K;
    if (Dx == 0)
      K = std::numeric_limits<double>::infinity();
    else if (Dy == 0)
      K = 0.0;
    else
      K = static_cast<double>(DeltaY) / DeltaX;
    return std::hash<double>()(K);
  }
};

inline bool operator==(const Slope &S1, const Slope &S2) {
  return (int64_t) S1.DeltaX * S2.DeltaY == (int64_t) S1.DeltaY * S2.DeltaX;
}

namespace std {

template<> struct hash<Slope> {
  std::size_t operator()(const Slope &S) const {
    return S.Hash;
  }
};

}

inline bool operator==(const Point &P1, const Point P2) {
  return P1.x == P2.x && P1.y == P2.y;
}

int Solution149_1::maxPoints(std::vector<Point> &points) {
  int MaxCount = 0, SameLinePoint, SamePoint;
  std::unordered_map<Slope, int> Map;
  for (auto I = points.cbegin(), E = points.cend(); I != E; ++I) {
    SameLinePoint = 0;
    SamePoint = 0;
    for (auto J = I + 1; J != E; ++J) {
      if (*J == *I)
        ++SamePoint;
      else
        SameLinePoint = std::max(SameLinePoint, ++Map[Slope(*I, *J)]);
    }
    Map.clear();
    MaxCount = std::max(MaxCount, 1 + SamePoint + SameLinePoint);
  }
  return MaxCount;
}
