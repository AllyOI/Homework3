#include "Player.h"
#include "Deck.h"
#include "SidePile.h"
#include <iostream>
using namespace std;

Player::Player() {
    this->score = 0;
}

Player::Player(bool standard) {
    deck = Deck(standard);
}

Player::~Player() {
    
}

int Player::drawDeck() {
    return this->deck.drawCard();
}

int Player::getDeckLength() {
    //call deck length function on deck class
    return this->deck.cardsLeft();
}

int Player::drawSP() {
    /*cout << "This method needs to be implemented still." << endl;
    return -1;*/

    return this->sidePile.pop();
}

void Player::addToDeck(int card) {
    this->deck.addCard(card);
}

int Player::getSPLength() {
    return this->sidePile.getSPLength();
}

void Player::addSP(int card) {
    this->sidePile.push(card);
}

void Player::addScore(int score) {
    this->score += score;
}

int Player::getScore() {
    return this->score;
}


