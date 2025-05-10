//
// Created by Ryan Bauroth on 5/6/25.
//

#include "Trie.h"

#include <functional>

/**
 * Constructor for Trie
 */
Trie::Trie() {
    root = new TrieNode();
}

/**
 * Gets root of Trie
 * @return TrieNode root
 */
TrieNode *Trie::getRoot() {
    return root;
}

/**
 * Inserts a new word into the Trie
 * Follows existing path if it exists, then creates new path when needed
 * @param word word to insert
 */
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

/**
 * Calculates memory usage of Trie
 * @param trie
 * @return size_t
 */
size_t Trie::calculateTrieMemoryUsage(Trie* trie) {
    size_t totalMemory = 0;

    std::function<void(TrieNode*)> traverseNodes = [&](TrieNode* node) {
        if (!node) return;

        totalMemory += node->getMemoryUsage();

        for (auto& child : node->children) {
            traverseNodes(child.second);
        }
    };

    traverseNodes(trie->getRoot());
    return totalMemory;
}



