//
// Created by Ryan Bauroth on 5/6/25.
//

#include "Trie.h"

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



