#include "deck.h"

Deck::Deck(bool standard) {
    if (standard) 
    {
        // Initialize a standard deck of cards (52 cards)
        for (int suit = 0; suit < 4; ++suit) {
            for (int rank = 2; rank <= 14; ++rank) {
                cards.push_back(rank);
            }
        }
    }
}

void Deck::addCard(int card) {
    cards.push_back(card);
}

int Deck::drawCard() {
    if (cards.empty()) {
        // Handle the case where the deck is empty
        return -1; // You can define your own error handling here
    }

    int card = cards.front();
    cards.pop_front();
    return card;
}

void Deck::returnCards(const std::list<int>& wonCards) {
    for (int card : wonCards) {
        cards.push_back(card);
    }
}

int Deck::cardsLeft() const {
    return cards.size();
}
