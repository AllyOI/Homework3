#ifndef DECK_H
#define DECK_H

#include <list>
#include <vector>

class Deck {
public:
    Deck();
    int drawCard();
    void returnCards(const std::vector<int>& wonCards);
    int cardsLeft() const;
    void addCard(int card);

private:
    std::list<int> cards;
};

#endif
