//
// Created by Ryan Bauroth on 5/6/25.
//

#ifndef TRIESOLVER_H
#define TRIESOLVER_H
#include <string>
#include <vector>

#include "Trie.h"


class TrieSolver {
public:
    TrieSolver();
    std::vector<std::string> solveGrid(std::vector<std::vector<char>> grid);
    static const int size = 4;

private:
    Trie trie;
};



#endif //TRIESOLVER_H
