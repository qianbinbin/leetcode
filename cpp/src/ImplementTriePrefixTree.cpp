#include "ImplementTriePrefixTree.h"

using namespace lcpp;

void Trie::insert(std::string word) {
  auto *P = Root;
  for (const auto &Ch : word) {
    auto &N = P->Children[Ch - 'a'];
    if (N == nullptr)
      N = new TrieNode();
    P = N;
  }
  P->End = true;
}

bool Trie::search(std::string word) {
  auto *P = Root;
  for (const auto &Ch : word) {
    if ((P = P->Children[Ch - 'a']) == nullptr)
      return false;
  }
  return P->End;
}

bool Trie::startsWith(std::string prefix) {
  auto *P = Root;
  for (const auto &Ch : prefix) {
    if ((P = P->Children[Ch - 'a']) == nullptr)
      return false;
  }
  return true;
}
