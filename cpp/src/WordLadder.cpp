#include "WordLadder.h"
#include <unordered_set>

using namespace lcpp;

int Solution127_1::ladderLength(std::string beginWord, std::string endWord,
                                std::vector<std::string> &wordList) {
  std::unordered_set<std::string> WordSet(wordList.begin(), wordList.end());
  if (!WordSet.erase(endWord))
    return 0;
  WordSet.erase(beginWord);

  int Depth = 1;
  std::unordered_set<std::string> Set1{beginWord}, Set2{endWord}, Tmp;
  while (!Set1.empty() && !Set2.empty()) {
    ++Depth;
    if (Set1.size() > Set2.size())
      std::swap(Set1, Set2);
    const auto &S2E = Set2.end();
    for (const auto &Word : Set1) {
      auto Guess = Word;
      for (auto &Ch : Guess) {
        const auto Origin = Ch;
        for (char C = 'a'; C <= 'z'; ++C) {
          if (C == Origin)
            continue;
          Ch = C;
          if (Set2.find(Guess) != S2E)
            return Depth;
          if (WordSet.erase(Guess))
            Tmp.insert(Guess);
        }
        Ch = Origin;
      }
    }
    Set1.clear();
    std::swap(Set1, Tmp);
  }
  return 0;
}
