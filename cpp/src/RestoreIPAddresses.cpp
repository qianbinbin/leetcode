#include "RestoreIPAddresses.h"

using namespace lcpp;

static std::string join(const std::vector<std::string> &Strings, char Ch) {
  std::string Result;
  for (const auto &Str : Strings)
    Result += Str + Ch;
  Result.pop_back();
  return Result;
}

static void restore(std::string &S, std::string::size_type I,
                    std::vector<std::string> &Path,
                    std::vector<std::string> &Result) {
  const auto &Size = S.size();
  if (Path.size() == 4 || I == Size) {
    if (Path.size() == 4 && I == Size)
      Result.push_back(join(Path, '.'));
    return;
  }
  Path.emplace_back(std::string(S, I, 1));
  restore(S, I + 1, Path, Result);
  Path.pop_back();
  if (S[I] == '0')
    return;
  if (I + 1 < Size) {
    Path.emplace_back(std::string(S, I, 2));
    restore(S, I + 2, Path, Result);
    Path.pop_back();
  }
  if (I + 2 < Size) {
    auto S1 = std::string(S, I, 3);
    if (std::stoi(S1) > 255)
      return;
    Path.emplace_back(std::move(S1));
    restore(S, I + 3, Path, Result);
    Path.pop_back();
  }
}

std::vector<std::string> Solution93_1::restoreIpAddresses(std::string s) {
  std::vector<std::string> Result;
  std::vector<std::string> Path;
  restore(s, 0, Path, Result);
  return Result;
}

static bool isValidIPSegment(const std::string &Str) {
  const auto &Size = Str.size();
  if (Size == 0 || Size > 3)
    return false;
  if (Str[0] == '0')
    return Size == 1;
  return std::stoi(Str) < 256;
}

std::vector<std::string> Solution93_2::restoreIpAddresses(std::string s) {
  const auto &Size = s.size();
  std::vector<std::string> Result;
  for (std::string::size_type I1 = 1, E1 = std::min(I1 + 3, Size - 2); I1 < E1;
       ++I1) {
    for (auto I2 = I1 + 1, E2 = std::min(I1 + 4, Size - 1); I2 < E2; ++I2) {
      for (auto I3 = I2 + 1, E3 = std::min(I2 + 4, Size); I3 < E3; ++I3) {
        auto S1 = std::string(s, 0, I1), S2 = std::string(s, I1, I2 - I1),
             S3 = std::string(s, I2, I3 - I2),
             S4 = std::string(s, I3, Size - I3);
        if (isValidIPSegment(S1) && isValidIPSegment(S2) &&
            isValidIPSegment(S3) && isValidIPSegment(S4)) {
          Result.push_back(S1.append(".")
                               .append(S2)
                               .append(".")
                               .append(S3)
                               .append(".")
                               .append(S4));
        }
      }
    }
  }
  return Result;
}
