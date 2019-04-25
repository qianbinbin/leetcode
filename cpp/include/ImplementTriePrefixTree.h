// Implement a trie with insert, search, and startsWith methods.
//
// Example:
//
// Trie trie = new Trie();
//
// trie.insert("apple");
// trie.search("apple");   // returns true
// trie.search("app");     // returns false
// trie.startsWith("app"); // returns true
// trie.insert("app");
// trie.search("app");     // returns true
//
// Note:
//
// You may assume that all inputs are consist of lowercase letters a-z.
// All inputs are guaranteed to be non-empty strings.

#ifndef LEETCODECPP_IMPLEMENTTRIEPREFIXTREE_H
#define LEETCODECPP_IMPLEMENTTRIEPREFIXTREE_H

#include <array>
#include <string>

namespace lcpp {

class Trie {
public:
  /** Initialize your data structure here. */
  Trie() : Root(new TrieNode()) {}

  ~Trie() { deleteTrie(Root); }

  /** Inserts a word into the trie. */
  void insert(std::string word);

  /** Returns if the word is in the trie. */
  bool search(std::string word);

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(std::string prefix);

private:
  struct TrieNode {
    bool End{};
    std::array<struct TrieNode *, 26> Children{};
  };

  TrieNode *const Root;

  static void deleteTrie(TrieNode *T) {
    for (const auto &N : T->Children) {
      if (N != nullptr)
        deleteTrie(N);
    }
    delete T;
  }
};

} // namespace lcpp

#endif // LEETCODECPP_IMPLEMENTTRIEPREFIXTREE_H
