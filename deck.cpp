//
// Created by Kevin Wu on 1/11/22.
//
#include "card.h"
#include "deck.h"
#include "solver.h"


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
        std::cerr << "Empty deck!";
    }
    return cards[--top_card];
}


// Draws n cards from deck without replacement
std::vector<card> deck::draw_n(int n) {
    if (n < 0 || n > 52) {
        std::cerr << "Invalid number of cards!";
    }
    std::vector<card> hand;
    for (int i = 0; i < n; i++) {
        card c = draw();
        hand.push_back(c);
    }
    shuffle_deck();
    top_card = 52;
    return hand;
}


// Extracts numerical value from a hand
std::vector<int> deck::get_hand_values(std::vector<card> hand) {
    std::vector<int> rtn;
    for (int i = 0; i < hand.size(); i++) {
        rtn.push_back(hand[i].rank);
    }
    return rtn;
}


// Print a hand
void deck::print_hand(std::vector<card> hand) {
    for (int i = 0; i < hand.size(); i++) {
        print_card(hand[i]);
        if (i != hand.size() - 1) {std::cout << ", ";}
        else {std::cout << "\n";}
    }
}


// Draws a hand of 4 valid cards and prints them
std::vector<int> deck::draw4(deck d) {
    d.shuffle_deck();
    std::vector<card> card_hand;
    std::vector<int> hand;
    do {
        card_hand = d.draw_n(4);
        hand = d.get_hand_values(card_hand);
    }
    while (!solver::solve(hand));
    d.print_hand(card_hand);
    return hand;
}