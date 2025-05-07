//
// Created by Ryan Bauroth on 5/6/25.
//

#include "TrieSolver.h"

#include <fstream>
#include <iostream>
#include <set>


void dfs(int x, int y, std::vector<std::vector<char>>& grid,
         std::vector<std::vector<bool>>& visited,
         TrieNode* node, std::string current_word,
         std::set<std::string>& found_words) {

    if (node->is_end) {
        found_words.insert(current_word);
    }

    visited[x][y] = true;

    static const std::vector<std::pair<int, int>> directions = {
        {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}
    };

    for (const auto& [dx, dy] : directions) {
        int nx = x + dx, ny = y + dy;
        if (nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size() && !visited[nx][ny]) {
            char next_char = std::toupper(grid[nx][ny]);
            if (node->children.count(next_char)) {
                dfs(nx, ny, grid, visited, node->children[next_char],
                    current_word + next_char, found_words);
            }
        }
    }

    visited[x][y] = false;
}


std::vector<std::string> TrieSolver::solveGrid(std::vector<std::vector<char> > grid) {
    std::set<std::string> found_words;
    int rows = grid.size(), cols = grid[0].size();
    std::vector visited(rows, std::vector(cols, false));
    TrieNode* root = trie.getRoot();

    for (int x = 0; x < rows; x++) {
        for (int y = 0; y < cols; y++) {
            char start_char = std::toupper(grid[x][y]);
            if (root->children.count(start_char)) {
                dfs(x, y, grid, visited, root->children[start_char],
                    std::string(1, start_char), found_words);
            }
        }
    }
    return std::vector(found_words.begin(), found_words.end());
}


TrieSolver::TrieSolver(): trie() {
    std::ifstream file("filtered_words.txt");

    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.size() > 2) {
            trie.insert(line);
        }
    }

    file.close();
}
