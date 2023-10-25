#include "Player.h"
#include <iostream>

//will be where you can initialize your test cases
Player human;
Player computer;

int main() {
	//draw cards
	int hCard = human.drawDeck();
	int cCard = computer.drawDeck();
	
	//human play
	std::cout << "You peek at the card you drew... you drew a " << hCard << ". ";
	int choose = 0;
	do {
		std::cout << "Press...\n\t1: Push to side pile and draw new\n\t2: Pull from side pile.\n";
		std::cin >> choose;
	} while (choose != 1 && choose != 2);

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

	int cXtra = 0;
	//computer play


	//compare plays
	if (hCard + hXtra > cCard + cXtra) {
		//player wins
	}
	else {
		//computer wins
	}
}