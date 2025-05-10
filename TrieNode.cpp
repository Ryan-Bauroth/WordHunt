//
// Created by Ryan Bauroth on 5/6/25.
//

#include "TrieNode.h"

/**
 * Constructor for TrieNode
 */
TrieNode::TrieNode() {
    is_end = false;
}

/**
 * Calculates memory usage of TrieNode
 * @return size_t
 */
size_t TrieNode::getMemoryUsage() {
    size_t total = sizeof(TrieNode);
    total += children.size() * sizeof(std::pair<const char, TrieNode*>);
    return total;
}
