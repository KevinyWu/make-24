//
// Created by Kevin Wu on 1/11/22.
//
#include "parser.h"


// Find precedence of operators
int parser::precedence(char op) {
    if (op == '+'||op == '-')
        return 1;
    if (op == '*'||op == '/')
        return 2;
    return 0;
}


// Perform arithmetic operations
float parser::apply_op(float a, float b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}


// Checks if a string is valid
bool parser::valid_string(const std::string& tokens, std::vector<int> hand) {
    std::vector<int> nums;
    std::vector<char> ops;

    // fills nums with numerical values and ops with other characters
    for (int i = 0; i < tokens.length(); i++) {
        if (isdigit(tokens[i])) {
            std::string n = "";
            while(isdigit(tokens[i])) {
                n += tokens[i++];
            }
            nums.push_back(std::stoi(n));
        }
        ops.push_back(tokens[i]);
    }
    // Check if all cards are used and no others
    std::sort(nums.begin(), nums.end());
    std::sort(hand.begin(), hand.end());
    if (nums != hand) {
        std::cerr << "Use all cards and no others! Please try again:\n";
        return false;
    }
    // Check if other characters are valid operations
    std::string valid = "+-*/() ";
    for(int i = 0; i < ops.size()-1; i++) {
        if (valid.find(ops[i]) == std::string::npos) {
            std::cerr << "Invalid mathematical expression! Please try again:\n";
            return false;
        }
    }
    return true;
}


// Returns value of expression after evaluation
float parser::evaluate(std::string tokens) {
    int i;
    // Stack to store values
    std::stack <float> values;
    // Stack to store operators
    std::stack <char> ops;

    for (i = 0; i < tokens.length(); i++) {
        // Current token is a whitespace, skip it
        if (tokens[i] == ' ') {
            continue;
        }
        // Current token is an opening brace, push it to 'ops'
        else if (tokens[i] == '(') {
            ops.push(tokens[i]);
        }
        // Current token is a number, push it to stack for numbers
        else if (isdigit(tokens[i])) {
            float val = 0;
            // May be more than one digit in number
            while (i < tokens.length() && isdigit(tokens[i])) {
                val = (val * 10) + (tokens[i] - '0');
                i++;
            }
            values.push(val);
            i--;
        }
        // Closing brace encountered, solve entire brace
        else if (tokens[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                float val2 = values.top();
                values.pop();
                float val1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(apply_op(val1, val2, op));
            }
            // Pop opening brace
            if (!ops.empty()) {
                ops.pop();
            }
        }
        // Current token is an operator
        else {
            // While top of 'ops' has same or greater precedence to current operator,
            // apply operator on top of 'ops' to top two elements in values stack
            while (!ops.empty() && precedence(ops.top()) >= precedence(tokens[i])) {
                float val2 = values.top();
                values.pop();
                float val1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(apply_op(val1, val2, op));
            }
            // Push current token to 'ops'
            ops.push(tokens[i]);
        }
    }

    // Apply remaining ops to remaining values
    while (!ops.empty()) {
        float val2 = values.top();
        values.pop();
        float val1 = values.top();
        values.pop();
        char op = ops.top();
        ops.pop();
        values.push(apply_op(val1, val2, op));
    }
    // Top of 'values' contains result, return it
    return values.top();
}