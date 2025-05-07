//
// Created by Ryan Bauroth on 5/6/25.
//

#include "Trie.h"

Trie::Trie() {
    root = new TrieNode();
}

TrieNode *Trie::getRoot() {
    return root;
}

void Trie::insert(const std::string &word) {
    TrieNode *node = root;
    for (char c : word) {
        c = std::toupper(c);
        if (!node->children[c]) {
            node->children[c] = new TrieNode();
        }
        node = node->children[c];
    }
    node->is_end = true;
}



