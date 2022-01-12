//
// Created by Kevin Wu on 1/11/22.
//
#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <algorithm>
#include <stack>


// Parses input string using shunting-yard algorithm
class parser
{
public:
    static float evaluate(std::string); // Returns value of expression after evaluation
private:
    static int precedence(char); // Find precedence of operators
    static float apply_op(float, float, char); // Perform arithmetic operations
    static bool valid_char(char c); // Checks if a character is valid
    static bool valid_string(const std::string&); // Checks if a string is valid
};


#endif //PARSER_H
