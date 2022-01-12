//
// Created by Kevin Wu on 1/11/22.
//
#include "deck.h"
#include "parser.h"
#include "solver.h"


int main() {
    std::cout << "Welcome to the classic card game 24!\n"
                 "Given four cards from a standard 52-card deck, use the operations +, -, *, /, and () to make 24.\n"
                 "Note: Ace = 1, Jack = 11, Queen = 12, King = 13.\n\n";
    deck d;
    std::string s;
    while (true) {
        d.shuffle_deck();
        // Checks if hand is valid
        std::vector<int> hand = d.print_draw(4);
        if (!solver::solve(hand)) {
            continue;
        }
        // Takes user input
        std::cout << "Enter expression: ";
        std::cin >> s;
        float r = parser::evaluate(s);
        // Checks if result is valid
        std::cout << "Result: " << r << "\n";
        if (abs(24.0 - r) < 0.0001) {
            std::cout << "Good job!" << "\n";
        }
        else {
            std::cout << "Try again." << "\n";
        }
        break;
    }
    return 0;
}

