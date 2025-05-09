//
// Created by Ryan Bauroth on 5/6/25.
//

#ifndef TRIENODE_H
#define TRIENODE_H
#include <unordered_map>


class TrieNode {
public:
    TrieNode();
    bool is_end;
    std::unordered_map<char, TrieNode*> children;
    int pruned_paths = 0;
};



#endif //TRIENODE_H
