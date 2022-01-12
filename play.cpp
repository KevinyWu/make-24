//
// Created by Kevin Wu on 1/11/22.
//
#include "deck.h"
#include "parser.h"


int main() {
    std::cout << "Welcome to the classic card game 24!\n"
                 "Given four cards from a standard 52-card deck, use the operations +, -, *, /, and () to make 24.\n"
                 "Note: Ace = 1, Jack = 11, Queen = 12, King = 13.\n\n";
    deck d;
    std::string s;
    while (true) {
        d.shuffle_deck();
        d.print_draw(4);
        std::cout << "Enter expression:\n";
        std::cin >> s;
        float r = parser::evaluate(s);
        std::cout << "Result: " << r << "\n";
        if (r > 23.999 && r < 24.001)
            std::cout << "Good job!" << "\n";
        else
            std::cout << "Try again." << "\n";
        break;
    }
    return 0;
}

