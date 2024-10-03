#ifndef GAME_SETUP_HPP
#define GAME_SETUP_HPP
#include "player.h"
#include "dealer.h"
//FAIRE QUE LES FONCTIONS PEUVENT RETOURNER PLUSIEURS VALUERS !!!!!!!

Player player_cards(std::vector<Card> available_cards) {
	int temporary_number1 = rand() % available_cards.size();
	available_cards.erase(available_cards.begin() + temporary_number1);
	int temporary_number2 = rand() % available_cards.size();
	available_cards.erase(available_cards.begin() + temporary_number2);

	Player temporary_cards(available_cards[temporary_number1], available_cards[temporary_number2]);
	return temporary_cards;
}

Dealer dealer_cards(std::vector<Card> available_cards) {
	int temporary_number1 = rand() % available_cards.size();
	available_cards.erase(available_cards.begin() + temporary_number1);
	int temporary_number2 = rand() % available_cards.size();
	available_cards.erase(available_cards.begin() + temporary_number2);
	int temporary_number3 = rand() % available_cards.size();
	available_cards.erase(available_cards.begin() + temporary_number3);
	int temporary_number4 = rand() % available_cards.size();
	available_cards.erase(available_cards.begin() + temporary_number4);
	int temporary_number5 = rand() % available_cards.size();
	available_cards.erase(available_cards.begin() + temporary_number5);

	Dealer temporary_cards(available_cards[temporary_number1], available_cards[temporary_number2], available_cards[temporary_number3], available_cards[temporary_number4], available_cards[temporary_number5]);
	return temporary_cards;
}
#endif
