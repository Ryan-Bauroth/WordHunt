//
// Created by Ryan Bauroth on 5/5/25.
//

#ifndef BUCKETSOLVER_H
#define BUCKETSOLVER_H
#include <unordered_map>
#include <vector>
#include <string>


class BucketSolver {
public:
    BucketSolver();
    std::vector<std::string> solveGrid(std::vector<std::vector<char>> grid);
    static const int size = 4;

private:
    std::unordered_map<char, std::vector<std::string>> buckets;
    const std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";



};



#endif //BUCKETSOLVER_H
