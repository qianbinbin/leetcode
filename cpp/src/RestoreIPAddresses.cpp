#include "RestoreIPAddresses.h"

using namespace lcpp;

static std::string join(const std::vector<std::string> &Strings, char Ch) {
  std::string Result;
  for (const auto &Str : Strings)
    Result += Str + Ch;
  Result.pop_back();
  return Result;
}

static void restore(std::string &S,
                    std::string::size_type I,
                    std::vector<std::string> &Path,
                    std::vector<std::string> &Result) {
  const auto &Size = S.size();
  if (Path.size() == 4 || I == Size) {
    if (Path.size() == 4 && I == Size)
      Result.push_back(join(Path, '.'));
    return;
  }
  if (S[I] == '0') {
    Path.emplace_back("0");
    restore(S, I + 1, Path, Result);
    Path.pop_back();
    return;
  }
  const auto E = std::min(I + 3, Size);
  for (auto J = I + 1; J <= E; ++J) {
    auto Segment = std::string(S, I, J - I);
    if (stoi(Segment) > 255)
      break;
    Path.emplace_back(std::move(Segment));
    restore(S, J, Path, Result);
    Path.pop_back();
  }
}

std::vector<std::string> Solution93_1::restoreIpAddresses(std::string s) {
  std::vector<std::string> Result;
  if (s.size() < 4 || s.size() > 12)
    return Result;
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
  for (const auto &Ch : Str) {
    if (!isdigit(Ch))
      return false;
  }
  return stoi(Str) < 256;
}

std::vector<std::string> Solution93_2::restoreIpAddresses(std::string s) {
  const auto &Size = s.size();
  std::vector<std::string> Result;
  if (Size < 4 || Size > 12)
    return Result;
  for (std::string::size_type I1 = 1, E1 = std::min(I1 + 3, Size - 2); I1 < E1;
       ++I1) {
    for (auto I2 = I1 + 1, E2 = std::min(I2 + 3, Size - 1); I2 < E2; ++I2) {
      for (auto I3 = I2 + 1, E3 = std::min(I3 + 3, Size); I3 < E3; ++I3) {
        auto S1 = std::string(s, 0, I1),
            S2 = std::string(s, I1, I2 - I1),
            S3 = std::string(s, I2, I3 - I2),
            S4 = std::string(s, I3, Size - I3);
        if (isValidIPSegment(S1) && isValidIPSegment(S2)
            && isValidIPSegment(S3) && isValidIPSegment(S4)) {
          S1 += '.';
          S1 += S2;
          S1 += '.';
          S1 += S3;
          S1 += '.';
          S1 += S4;
          Result.emplace_back(std::move(S1));
        }
      }
    }
  }
  return Result;
}
