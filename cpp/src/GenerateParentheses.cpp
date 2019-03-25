#include "GenerateParentheses.h"

using namespace lcpp;

typedef std::string::size_type SizeType;

static void generate(SizeType N, SizeType StackSize,
                     std::string &Path, std::vector<std::string> &Result) {
  if (Path.size() == 2 * N) {
    if (StackSize == 0)
      Result.push_back(Path);
    return;
  }
  if (StackSize < N) {
    Path.push_back('(');
    generate(N, StackSize + 1, Path, Result);
    Path.pop_back();
  }
  if (StackSize > 0) {
    Path.push_back(')');
    generate(N, StackSize - 1, Path, Result);
    Path.pop_back();
  }
}

std::vector<std::string> Solution22_1::generateParenthesis(int n) {
  std::vector<std::string> Result;
  std::string Path;
  generate(static_cast<SizeType>(n), 0, Path, Result);
  return Result;
}
