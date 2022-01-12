//
// Created by Kevin Wu on 1/11/22.
//
#include "solver.h"


// Checks if four cards can make 24 using +, -, *, /, ()
bool solver::solve(std::vector<int> nums) {
    sort(nums.begin(), nums.end());
    do {
        if (valid(nums)) return true;
    }
    while (next_permutation(nums.begin(), nums.end()));
    return false;
}


// Checks if 4 numbers are valid
bool solver::valid(std::vector<int> nums) {
    float a = nums[0], b = nums[1], c = nums[2], d = nums[3];
    if (valid(a+b, c, d) || valid(a-b, c, d) || valid(a*b, c, d) || valid(a/b, c, d)) return true;
    if (valid(a, b+c, d) || valid(a, b-c, d) || valid(a, b*c, d) || valid(a, b/c, d)) return true;
    if (valid(a, b, c+d) || valid(a, b, c-d) || valid(a, b, c*d) || valid(a, b, c/d)) return true;
    return false;
}


// Checks if 3 numbers are valid
bool solver::valid(float a, float b, float c) {
    if (valid(a+b, c) || valid(a-b, c) || valid(a*b, c) || b&&valid(a/b, c)) return true;
    if (valid(a, b+c) || valid(a, b-c) || valid(a, b*c) || c&&valid(a, b/c)) return true;
    return false;
}


// Checks if 2 numbers are valid
bool solver::valid(float a, float b) {
    return (abs(a+b-24.0) < 0.0001 ||
            abs(a-b-24.0) < 0.0001 ||
            abs(a*b-24.0) < 0.0001 ||
            b&&abs(a/b-24.0) < 0.0001);
}
