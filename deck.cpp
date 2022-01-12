//
// Created by Kevin Wu on 1/11/22.
//
#include "card.h"
#include "deck.h"


// Construct a 52 card deck
deck::deck() {
    top_card = 0;
    for (int i = 1; i <= 13; ++i) {
        card c1(diamond, i);
        card c2(spade, i);
        card c3(heart, i);
        card c4(club, i);
        cards[top_card++] = c1;
        cards[top_card++] = c2;
        cards[top_card++] = c3;
        cards[top_card++] = c4;
    }
}


// Shuffles the deck
void deck::shuffle_deck() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards, cards + 52, g);
}


// Checks if deck is empty
bool deck::is_empty() const {
    return top_card <= 0;
}


// Draws from top of deck
card deck::draw() {
    if (is_empty()) {
        std::cout << "Empty deck!";
        exit(-1);
    }
    return cards[--top_card];
}


// Draws n cards from deck without replacement
void deck::print_draw(int n) {
    if (n < 0 || n > 52) {
        std::cout << "Invalid number of cards!";
        exit(-1);
    }
    for (int i = 0; i < n; i++) {
        card c = draw();
        print_card(c);
        if (i != n - 1) {std::cout << ", ";}
        else {std::cout << "\n";}
    }
    shuffle_deck();
    top_card = 52;
}