//
// Created by Kevin Wu on 1/11/22.
//
#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <algorithm>
#include <stack>
#include <ctype.h>
#include <string>
#include <vector>


// Parses input string using shunting-yard algorithm
class parser
{
public:
    static float evaluate(std::string); // Returns value of expression after evaluation
    static bool valid_string(const std::string&, std::vector<int>); // Checks if a string is valid
private:
    static int precedence(char); // Find precedence of operators
    static float apply_op(float, float, char); // Perform arithmetic operations
};


#endif //PARSER_H
