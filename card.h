//
// Created by Kevin Wu on 1/11/22.
//
#ifndef CARD_H
#define CARD_H
#include <iostream>


// Possible suits
enum suits {diamond, club, heart, spade};


// 52 card deck (no jokers)
class card
{
public:
    card(); // Initialize a card with default values
    card(suits, int); // Initialize a card with given values
protected:
    int rank;
    suits suit;
    // Output a card
    friend void print_card(card c);
};


#endif //CARD_H
