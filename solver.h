//
// Created by Kevin Wu on 1/11/22.
//
#ifndef SOLVER_H
#define SOLVER_H
#include <vector>


// Solver for Classic mode
class solver {
public:
    static bool solve(std::vector<int>); // Checks if four cards can make 24 using +, -, *, /, ()
private:
    static bool valid(std::vector<int>); // Checks if 4 numbers are valid
    static bool valid(float, float, float); // Checks if 3 numbers are valid
    static bool valid(float, float); // Checks if 2 numbers are valid
};

#endif //SOLVER_H
