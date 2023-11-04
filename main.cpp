#include "Player.h"
#include <iostream>
#include <array>

//where you can initialize your test cases
int pDeck[] = {1, 8, 9};
int pSP[] = { 9 };
int cDeck[] = {1, 2, 3};
int cSP[] = { 9 };

Player human(false);
Player computer(false);


int main() {
	for (int c : pDeck) {
		human.addToDeck(c);
	}
	for (int c : pSP) {
		human.addSP(c);
	}
	for (int c : cDeck) {
		computer.addToDeck(c);
	}
	for (int c : cSP) {
		computer.addSP(c);
	}
	int round = 1;
	bool cont = true;
	int style = 0;
	int rds = -1;
	while (style != 1 && style != 2) {
		std::cout << "Play until out of cards (1) or for some number of rounds (2)?\n";
		std::cin >> style;
	}
	if (style == 2) {
		while (rds <= 0) {
			std::cin.get();
			std::cout << "Enter number of rounds to play: \n";
			std::cin >> rds;
		}
	}
	while (cont && !(human.getDeckLength() == 0 && human.getSPLength() == 0) && !(computer.getDeckLength() == 0 && computer.getSPLength() == 0)) {
		std::cout << "*\n* Round " << round << ":\n*\n";
		//draw cards
		int hCard = human.drawDeck();
		int cCard = computer.drawDeck();

		//Make the choice
		std::cout << "You peek at the card you drew... you drew a " << hCard << ".\n";
		int choose = 0;
		std::cout << "Cards in deck: " << human.getDeckLength() << "\nCards in side pile: " << human.getSPLength() << "\n";
		if (human.getSPLength() == 0) {
			std::cout << "Nothing in side pile... must push to side pile!\n";
			choose = 1;
		}
		else if (human.getSPLength() == 5) {
			std::cout << "Side pile full... must pull from side pile.\n";
			choose = 2;
		}
		else if (human.getDeckLength() == 0) {
			std::cout << "Deck empty... must pull from side pile.\n";
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
			std::cout << "You win!\n";
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
		std::cout <<"Round "<< round<< " results:\n\tYour score:\t" << human.getScore()<<"\n\tComputer score:\t"<<computer.getScore() << "\n";

		if (round == rds) {
			std::cout << "Rounds complete... ";
			if (human.getScore() > computer.getScore()) {
				std::cout << "you win!\n";
			}
			else if (computer.getScore() > human.getScore()) {
				std::cout << "you lose...\n";
			}
			else {
				std::cout << "tie!\n";
			}
			cont = false;
		} else if (human.getDeckLength() + human.getSPLength() == 0) {
			std::cout << "You're out of cards... you lose!";
			cont = false;
		}
		else if (computer.getDeckLength() + computer.getSPLength() == 0) {
			std::cout << "Computer is out of cards... you win!";
			cont = false;
		} 
		else {
			char c = 'a';
			while (c != 'y' && c != 'n')
			{
				std::cout << "Continue? (y/n)\n";
				std::cin >> c;
			}
			cont = c == 'y';
		}
		round++;
	}
}