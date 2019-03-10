#include "AddBinary.h"

using namespace lcpp;

std::string Solution67_1::addBinary(std::string a, std::string b) {
  std::string Result(std::max(a.size(), b.size()) + 1, '\0');
  auto I = a.crbegin(), IE = a.crend(), J = b.crbegin(), JE = b.crend();
  auto It = Result.rbegin();
  int Value, Carry = 0;
  while (I != IE && J != JE) {
    Value = *I - '0' + *J - '0' + Carry;
    Carry = Value / 2;
    *It++ = static_cast<char>(Value % 2 + '0');
    ++I;
    ++J;
  }
  while (I != IE) {
    Value = *I - '0' + Carry;
    Carry = Value / 2;
    *It++ = static_cast<char>(Value % 2 + '0');
    ++I;
  }
  while (J != JE) {
    Value = *J - '0' + Carry;
    Carry = Value / 2;
    *It++ = static_cast<char>(Value % 2 + '0');
    ++J;
  }
  if (Carry > 0)
    *It++ = '1';
  Result.erase(Result.begin(), It.base());
  return Result;
}
