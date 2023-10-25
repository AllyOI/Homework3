#include "Player.h"
#include <iostream>

//will be where you can initialize your test cases
Player human;
Player computer;

int main() {
	int round = 1;
	bool cont = true;
	while (cont && !(human.getDeckLength() == 0 && human.getSPLength() == 0) && !(computer.getDeckLength() == 0 && computer.getSPLength() == 0)) {
		std::cout << "*\n* Round " << round << ":\n*\n";
		//draw cards
		int hCard = human.drawDeck();
		int cCard = computer.drawDeck();

		//Make the choice
		std::cout << "You peek at the card you drew... you drew a " << hCard << ".\n";
		int choose = 0;
		if (human.getSPLength() == 0) {
			std::cout << "Nothing in side pile... must push to side pile!\n";
			choose = 1;
		}
		else if (human.getSPLength() == 5) {
			std::cout << "Side pile full... must pull from side pile.\n";
			choose = 2;
		}
		while (choose != 1 && choose != 2) {
			std::cout << "Press...\n\t1: Push to side pile and draw new\n\t2: Pull from side pile.\n";
			std::cin >> choose;
		}

		//human play
		int hXtra = 0;
		if (choose == 1) {
			//push to side pile and draw new card to use.
			human.addSP(hCard);
			hCard = human.drawDeck();
		}
		else {
			//pull from side pile and use newly drawn card with it
			hXtra = human.drawSP();
		}

		//computer play
		int cXtra = 0;
		if (computer.getSPLength() == 0) {
			choose = 1;
		}
		else if (computer.getSPLength() == 5) {
			choose = 2;
		}
		else if (cCard <= 6) {
			choose = 2;
		}
		else {
			choose = 1;
		}

		if (choose == 1) {
			computer.addSP(cCard);
			cCard = computer.drawDeck();
		}
		else {
			cXtra = computer.drawSP();
		}

		//determine winnage

		std::cout << "You play " << hCard;
		if (hXtra != 0) {
			std::cout << " and " << hXtra;
		}
		std::cout << "...\n";
		
		std::cout << "Computer plays " << cCard;
		if (cXtra != 0) {
			std::cout << " and " << cXtra;
		}
		std::cout << "...\n";

		if (hCard + hXtra > cCard + cXtra) {
			std::cout << "You win!\n"
			//player wins
			human.addScore(hCard + hXtra);
			human.addToDeck(hCard);
			if (hXtra != 0) {
				human.addToDeck(hXtra);
			}
		}
		else {
			std::cout << "You lost...\n";
			//computer wins
			computer.addScore(cCard + cXtra);
			computer.addToDeck(cCard);
			if (cXtra != 0) {
				computer.addToDeck(cXtra);
			}
		}
		std::cout <<"Round "<< round<< "results:\n\tYour score:\t" << human.getScore()<<"\n\tComputer score:\t"<<computer.getScore() << "\n";
		round++;
		char c;
		do
		{
			std::cout << "Continue? (y/n)\n";
			std::cin >> c;
		} while (c != 'y' && c != 'n');
		cont = c == 'y';
	}

	if (human.getDeckLength() == 0 && human.getSPLength() == 0) {
		std::cout << "You ran out of cards... you lose!\n";
	}
	else if (computer.getDeckLength() == 0 && computer.getSPLength() == 0) {
		std::cout << "Computer ran out of cards... you win!\n";
	}
}