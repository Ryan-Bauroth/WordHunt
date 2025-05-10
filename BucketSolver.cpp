//
// Created by Ryan Bauroth on 5/5/25.
//

#include "BucketSolver.h"
#include <fstream>
#include <iostream>
#include <set>

/**
 * Checks if a certain index is within board
 * @param x_index int
 * @param y_index int
 * @return if index is valid
 */
bool checkIndex(int x_index, int y_index) {
    return x_index >= 0 && x_index < BucketSolver::size &&
           y_index >= 0 && y_index < BucketSolver::size;
}

/**
 * Finds all locations where a certain letter exists around a spot on the grid
 * @param starting_index current index on grid
 * @param letter letter to search for
 * @param grid grid of letters
 * @return all found locations of a given letter, empty if none
 */
std::vector<std::vector<int>> findLetter(std::vector<int> starting_index, char letter, std::vector<std::vector<char>> grid) {
    std::vector<std::vector<int>> offsets = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};
    std::vector<std::vector<int>> result;

    // Ensure the index is within bounds and match the letter
    for (std::vector<int> offset : offsets) {
        int x_index = starting_index[0] + offset[0];
        int y_index = starting_index[1] + offset[1];
        if (checkIndex(x_index, y_index) && grid[x_index][y_index] == letter) {
            result.push_back({x_index, y_index});
        }
    }

    return result;
}

/**
 * Depth first search recursive function to find words
 * @param word word searched for
 * @param index # of letters into current word
 * @param x index of grid
 * @param y int of grid
 * @param grid grid of letters
 * @param visited grid of visited locations
 * @param path current path
 * @return true if word exists
 */
bool dfs(const std::string& word, int index, int x, int y,
         const std::vector<std::vector<char>>& grid,
         std::vector<std::vector<bool>>& visited,
         std::vector<std::vector<int>>& path) {

    if (index == word.size()) return true;

    std::vector<std::vector<int>> neighbors = findLetter({x, y}, word[index], grid);
    for (auto& pos : neighbors) {
        int nx = pos[0], ny = pos[1];

        // Skip if the cell is already visited
        if (!visited[nx][ny]) {
            visited[nx][ny] = true;
            path.push_back({nx, ny});

            // Recursively try to match the next character in the word
            if (dfs(word, index + 1, nx, ny, grid, visited, path))
                return true;

            path.pop_back(); // backtrack
            visited[nx][ny] = false;
        }
    }
    return false;
}

/**
 * Solves the grid for all possible solutions
 * @param grid grid of letters
 * @return all possible solutions
 */
std::vector<std::string> BucketSolver::solveGrid(std::vector<std::vector<char>> grid) {
    std::set<std::string> found_words_set;
    int rows = grid.size(), cols = grid[0].size();

    for (int x = 0; x < rows; x++) {
        for (int y = 0; y < cols; y++) {
            for (const std::string& word : buckets.at(grid[x][y])) {
                std::vector<std::vector<int>> path = {{x, y}};
                std::vector visited(rows, std::vector(cols, false));
                visited[x][y] = true;
                if (dfs(word, 1, x, y, grid, visited, path)) {
                    found_words_set.insert(word); // insert only if not already present
                }
            }
        }
    }

    std::vector<std::string> found_words(found_words_set.begin(), found_words_set.end());
    return found_words;
}

/**
 * Constructor for Bucket Solver
 * Sorts valid word list into buckets
 * Check size of Bucket after initialization
 */
BucketSolver::BucketSolver() {
    std::ifstream file("filtered_words.txt");

    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    for (char c : alphabet) {
        buckets.insert({c, {}});
    }

    std::string line;
    while (std::getline(file, line)) {
        buckets.at(line[0]).push_back(line);
    }

    size_t total = 0;

    for (const auto& [key, vec] : buckets) {
        total += sizeof(key);

        total += sizeof(vec);
        total += vec.capacity() * sizeof(std::string);

        for (const auto& word : vec) {
            total += sizeof(word);
            total += word.capacity();
        }
    }

    std::cout << "Bucket of size " << total / 1024 << " KB";

    file.close();
}


