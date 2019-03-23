#include "LRUCache.h"

using namespace lcpp;

int LRUCache::get(int key) {
  const auto MIt = Map.find(key);
  if (MIt == Map.end())
    return -1;
  if (MIt->second.second != List.cbegin()) {
    List.erase(MIt->second.second);
    List.push_front(key);
    MIt->second.second = List.cbegin();
  }
  return MIt->second.first;
}

void LRUCache::put(int key, int value) {
  const auto MIt = Map.find(key);
  if (MIt != Map.end()) {
    MIt->second.first = value;
    if (MIt->second.second != List.cbegin()) {
      List.erase(MIt->second.second);
      List.push_front(key);
      MIt->second.second = List.cbegin();
    }
    return;
  }
  List.push_front(key);
  Map.insert({key, Value(value, List.cbegin())});
  if (Map.size() > Capacity) {
    Map.erase(List.back());
    List.pop_back();
  }
}
