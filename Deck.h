#ifndef DECK_H
#define DECK_H

#include <list>

class Deck {
public:
    Deck();

    void addCard(int card);
    int drawCard();
    void returnCards(const std::list<int>& wonCards);
    int cardsLeft() const;

private:
    std::list<int> cards;
};

#endif

