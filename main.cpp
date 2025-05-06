#include <fstream>
#include <iostream>

#include "BucketSolver.h"

int main() {
    BucketSolver solver;
    std::vector<std::vector<char>> grid;
    std::string row;
    for (int i = 0; i < 4; i++) {
        row = "";
        while (row.size() != 4) {
            std::cout << "Enter row " + std::to_string(i) + ": ";
            std::cin >> row;
            if (row.size() == 4) {
                std::vector<char> row_vector;
                for (char c : row) {
                    row_vector.push_back(std::toupper(c));
                }
                grid.push_back(row_vector);
            }
        }
    }

    std::cout << "Solving..." << std::endl;
    auto start_time = std::chrono::high_resolution_clock::now();

    std::vector<std::string> solutions = solver.solveGrid(grid);

    auto duration = duration_cast<std::chrono::milliseconds>( std::chrono::high_resolution_clock::now() - start_time);

    std::sort(solutions.begin(), solutions.end(), [](const std::string& a, const std::string& b) {
        return a.size() > b.size();
    });


    std::cout << std::endl;
    std::cout << "Found " << solutions.size() << " words!" << std::endl;
    std::cout << "Execution time: " << duration.count() << " milliseconds." << std::endl;

    std::ofstream output_file("solutions.txt");

    if (!output_file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    for (const auto& word : solutions) {
        output_file << word << std::endl;
    }

    output_file.close();

    return 0;
}
