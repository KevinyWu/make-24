//
// Created by Kevin Wu on 1/11/22.
//
#include "deck.h"
#include "parser.h"
#include "solver.h"


// Checks if user input is valid
std::string valid_input(std::vector<int> hand) {
    std::string s;
    getline(std::cin, s);
    if (!parser::valid_string(s, hand)) {
        valid_input(hand);
    }
    return s;
}


// Takes user expression
float input(std::vector<int> hand) {
    std::cout << "Enter expression: ";
    std::string s = valid_input(hand);
    float r = parser::evaluate(s);
    return r;
}


// User decision to play again or not
std::string play_again() {
    std::string s;
    getline(std::cin, s);
    for (int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}


int main() {
    std::cout << "Welcome to the classic card game 24!\n"
                 "You are given four cards from a standard 52-card deck\n"
                 "Use the operations +, -, *, /, and () to make 24.\n"
                 "If you would like to quit the game at any time, press CTRL + C\n"
                 "Note: Ace = 1, Jack = 11, Queen = 12, King = 13.\n\n";
    deck d;
    std::vector<int> hand = d.draw4(d);
    bool new_draw = false;
    while (true) {
        // Draw again if previous round was won
        if (new_draw) {
            hand = d.draw4(d);
        }

        // Takes user input
        float r = input(hand);

        // Checks if result is valid
        std::cout << "Result: " << r << "\n";
        if (abs(24.0 - r) < 0.0001) {
            std::cout << "Good job! Play Again? (y/n): ";
            bool again = false;
            while(1) {
                std::string s = play_again();
                if (s == "y" || s == "yes") {
                    again = true;
                    break;
                }
                else if (s == "n" || s == "no") {
                    break;
                }
                else {
                    std::cout << "Please enter a valid response: ";
                    continue;
                }
            }
            if (!again) {
                break;
            }
            else {
                new_draw = true;
                continue;
            }
        }
        else {
            std::cout << "Try again." << "\n";
            new_draw = false;
        }
    }
    return 0;
}