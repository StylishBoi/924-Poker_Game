#ifndef GAME_SETUP_HPP
#define GAME_SETUP_HPP
#include "player.h"
#include "dealer.h"

Player player_cards(std::vector<Card> available_cards) {
//setup player cards
	bool verification_loop = true;
	while (verification_loop = true) {
		int temporary_number1 = rand() % 52;
		int temporary_number2 = rand() % 52;
		if (temporary_number1 == temporary_number2)
		{
			std::cout << "They're the same.\n";
		}
		else
		{
			Player temporary_cards(available_cards[temporary_number1], available_cards[temporary_number2]);
			std::cout << "It worked.\n";
			return temporary_cards;
		}
	}
}

Dealer dealer_cards(std::vector<Card> available_cards) {
	//setup player cards
	bool verification_loop = true;
	int temporary_number1 = rand() % 52;
	int temporary_number2 = rand() % 52;
	int temporary_number3 = rand() % 52;
	int temporary_number4 = rand() % 52;
	int temporary_number5 = rand() % 52;
	while (verification_loop = true) {
		int temporary_number1 = rand() % 52;
		int temporary_number2 = rand() % 52;
		int temporary_number3 = rand() % 52;
		int temporary_number4 = rand() % 52;
		int temporary_number5 = rand() % 52;
		if (temporary_number1 != temporary_number2!=temporary_number3!=temporary_number4!=temporary_number5)
		{
			std::cout << "It worked.\n";
			break;
		}
		else
		{
			std::cout << "They're the same.\n";
		}
	}

	Dealer temporary_cards(available_cards[temporary_number1], available_cards[temporary_number2], available_cards[temporary_number3], available_cards[temporary_number4], available_cards[temporary_number5]);
	return temporary_cards;
}
#endif
