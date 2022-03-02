#include "WordLadderII.h"
#include <unordered_map>
#include <unordered_set>

using namespace lcpp;

typedef std::unordered_map<std::string, std::vector<std::string>> GraphType;

static void findLadders(GraphType &Graph, std::string &End,
                        std::vector<std::string> &Path,
                        std::vector<std::vector<std::string>> &Result) {
  if (Path.back() == End) {
    Result.push_back(Path);
    return;
  }
  if (Graph.find(Path.back()) == Graph.end())
    return;
  for (auto &Next : Graph[Path.back()]) {
    Path.push_back(Next);
    findLadders(Graph, End, Path, Result);
    Path.pop_back();
  }
}

std::vector<std::vector<std::string>>
Solution126_1::findLadders(std::string beginWord, std::string endWord,
                           std::vector<std::string> &wordList) {
  std::vector<std::vector<std::string>> Result;
  std::unordered_set<std::string> WordSet(wordList.begin(), wordList.end());
  if (!WordSet.erase(endWord))
    return Result;
  WordSet.erase(beginWord);

  GraphType Graph;
  std::unordered_set<std::string> Set1({beginWord}), Set2({endWord}), Next;
  bool Reverse = false, Found = false;
  while (!Found && !Set1.empty() && !Set2.empty()) {
    if (Set1.size() > Set2.size()) {
      std::swap(Set1, Set2);
      Reverse = !Reverse;
    }
    const auto &S2E = Set2.end(), &WSE = WordSet.end();
    for (auto &Word : Set1) {
      auto Guess = Word;
      for (auto &Ch : Guess) {
        const auto Origin = Ch;
        for (char C = 'a'; C <= 'z'; ++C) {
          if (C == Origin)
            continue;
          Ch = C;
          if (Set2.find(Guess) != S2E) {
            Found = true;
            Reverse ? Graph[Guess].push_back(Word)
                    : Graph[Word].push_back(Guess);
          } else if (!Found && WordSet.find(Guess) != WSE) {
            Next.insert(Guess);
            Reverse ? Graph[Guess].push_back(Word)
                    : Graph[Word].push_back(Guess);
          }
        }
        Ch = Origin;
      }
    }
    for (const auto &S : Next)
      WordSet.erase(S);
    Set1.clear();
    std::swap(Set1, Next);
  }
  if (!Found)
    return Result;
  std::vector<std::string> Path{beginWord};
  ::findLadders(Graph, endWord, Path, Result);
  return Result;
}
