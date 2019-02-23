#include "SimplifyPath.h"
#include <sstream>
#include <vector>

using namespace lcpp;

std::string Solution71_1::simplifyPath(std::string path) {
  std::vector<std::string> Stack;
  std::istringstream Stream(path);
  std::string Str;
  while (std::getline(Stream, Str, '/')) {
    if (Str.empty() || Str == ".")
      continue;
    if (Str == "..") {
      if (!Stack.empty())
        Stack.pop_back();
    } else {
      Stack.push_back(Str);
    }
  }
  Str = "";
  for (const auto &S : Stack) {
    Str += "/" + S;
  }
  if (Str.empty())
    Str = "/";
  return Str;
}
