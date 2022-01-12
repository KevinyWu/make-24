//
// Created by Kevin Wu on 1/11/22.
//
#ifndef DECK_H
#define DECK_H
#include "card.h"
#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>


// 52 card deck (no jokers)
class deck
{
public:
    deck(); // Initialize a 52 card deck
    void shuffle_deck(); // Shuffles the deck
    bool is_empty() const; // Checks if deck is empty
    card draw(); // Draws from top of deck
    std::vector<int> print_draw(int); // Draws n cards from deck without replacement and stores in vector
protected:
    card cards[52]; // Holds a deck
    int top_card; // Index one greater than last card
};


#endif //DECK_H
