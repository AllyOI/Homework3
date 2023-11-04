#pragma once
#include "Deck.h"
#include "SidePile.h"
class Player{
private:
    Deck deck;
    SidePile sidePile;
    int score;
    
public:
    Player();
    Player(bool);
    int drawDeck();
    int getDeckLength();
    int drawSP();
    void addToDeck(int);
    int getSPLength();
    void addSP(int);
    void addScore(int);
    int getScore();
    
    ~Player();
};

