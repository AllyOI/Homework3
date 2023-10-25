#include "Deck.h"

Deck::Deck() {
    // Initialize a standard deck of cards (52 cards)
    for (int suit = 0; suit < 4; ++suit) {
        for (int rank = 2; rank <= 14; ++rank) {
            cards.push_back(rank);
        }
    }
}

int Deck::drawCard() {
    int card = cards.front();
    cards.pop_front();
    return card;
}

void Deck::returnCards(const std::vector<int>& wonCards) {
    for (int card : wonCards) {
        cards.push_back(card);
    }
}

int Deck::cardsLeft() const {
    return cards.size();
}

void Deck::addCard(int card) {
    cards.push_back(card);
}
