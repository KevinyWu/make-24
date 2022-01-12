//
// Created by Kevin Wu on 1/11/22.
//
#include "card.h"


// Initialize a card to default values
card::card() {
    rank = 1;
    suit = spade;
}


// Initialize a card to given values
card::card(suits sv, int rv) {
    rank = rv;
    suit = sv;
}


// Output a card
void print_card(card c) {
    switch(c.rank) {
        case  1: std::cout << "Ace"; break;
        case 11: std::cout << "Jack"; break;
        case 12: std::cout << "Queen"; break;
        case 13: std::cout << "King"; break;
        default: std::cout << c.rank; break;
    }
    switch(c.suit) {
        case diamond: std::cout << " of Diamonds"; break;
        case spade: std::cout << " of Spades"; break;
        case heart: std::cout << " of Hearts"; break;
        case club: std::cout << " of Clubs"; break;
    }
}