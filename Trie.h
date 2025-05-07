//
// Created by Ryan Bauroth on 5/6/25.
//

#ifndef TRIE_H
#define TRIE_H
#include <string>
#include "TrieNode.h"


class Trie {
public:
    Trie();

    void insert(const std::string& word);

    TrieNode* getRoot();

private:
    TrieNode* root;
};



#endif //TRIE_H
