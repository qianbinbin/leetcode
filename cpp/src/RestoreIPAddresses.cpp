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
