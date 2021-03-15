#include "GenerateParentheses.h"

using namespace lcpp;

typedef std::string::size_type SizeType;

static void generate(SizeType N, SizeType StackSize, SizeType LeftCount,
                     std::string &Path, std::vector<std::string> &Result) {
  if (Path.size() == 2 * N) {
    Result.push_back(Path);
    return;
  }
  if (LeftCount < N) {
    Path.push_back('(');
    generate(N, StackSize + 1, LeftCount + 1, Path, Result);
    Path.pop_back();
  }
  if (StackSize != 0) {
    Path.push_back(')');
    generate(N, StackSize - 1, LeftCount, Path, Result);
    Path.pop_back();
  }
}

std::vector<std::string> Solution22_1::generateParenthesis(int n) {
  std::vector<std::string> Result;
  std::string Path;
  generate(n, 0, 0, Path, Result);
  return Result;
}
