#include "MaxPointsOnALine.h"
#include <limits>
#include <unordered_map>

using namespace lcpp;

struct Slope {
  int const DeltaX;
  int const DeltaY;
  std::size_t const Hash;

  Slope(std::vector<int> const &P1, std::vector<int> const &P2)
      : DeltaX(P1[0] - P2[0]), DeltaY(P1[1] - P2[1]),
        Hash(hash(DeltaX, DeltaY)) {}

  inline std::size_t hash(int Dx, int Dy) const {
    double K;
    if (Dx == 0)
      K = std::numeric_limits<double>::infinity();
    else if (Dy == 0)
      K = 0;
    else
      K = static_cast<double>(DeltaY) / DeltaX;
    return std::hash<double>()(K);
  }
};

inline bool operator==(const Slope &S1, const Slope &S2) {
  return (int64_t)S1.DeltaX * S2.DeltaY == (int64_t)S1.DeltaY * S2.DeltaX;
}

namespace std {

template <> struct hash<Slope> {
  std::size_t operator()(const Slope &S) const { return S.Hash; }
};

} // namespace std

inline bool operator==(std::vector<int> const &P1, std::vector<int> const &P2) {
  return P1[0] == P2[0] && P1[1] == P2[1];
}

int Solution149_1::maxPoints(std::vector<std::vector<int>> &points) {
  int Result = 0, MaxCount, SamePoints;
  std::unordered_map<Slope, int> Map;
  for (auto I = points.begin(), E = points.end(); I != E; ++I) {
    MaxCount = 0;
    SamePoints = 0;
    for (auto J = I + 1; J != E; ++J) {
      if (*J == *I)
        ++SamePoints;
      else
        MaxCount = std::max(MaxCount, ++Map[Slope(*I, *J)]);
    }
    Map.clear();
    Result = std::max(Result, 1 + SamePoints + MaxCount);
  }
  return Result;
}
