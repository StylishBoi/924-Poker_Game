#ifndef POKER_GAME
#define POKER_GAME
#include "deck.h"
#include "cards_setup.hpp"
#include "hand_values.hpp"
#include "poker_game.hpp"

int main()
{
	//setting up cards
	Deck deck;
	Player player = player_cards(deck);
	Enemy enemy = enemy_cards(deck);
	Dealer dealer = dealer_cards(deck);
	int player_money = 100;
	int menu_choice;

	std::cout << "WELCOME TO POKER \n\n";

	while(true)
	{
		std::cout<<"-*- Main Menu -*-\n\n1 - Play\n2 - Rules\n3 - Leave\n\n";
		std::cin >> menu_choice;
		switch(menu_choice)
		{
		case 1:
			std::cout << "\n - * - * - * - * - * - * - * - * - * - * - \n\n";
			player_money=Poker_Match(player_money, player, dealer, enemy);
			break;
		case 2:
			std::cout << "\nIn this game, you will play poker.\nYou will follow the basic poker rules with a money system.\nYou will face ONE opponent and need to have the better hand than him.\nIf you go bankrupt, you lose.\n\n";
			break;
		case 3:
			std::cout << "Goodbye !";
			return 0;
		default:
			std::cout << "\nWrong input, please try again.\n\n";
		}
		if (player_money==0)
		{
			std::cout << "You have went bankrupt :[\n\nGame Over";
			return 0;
		}
	}
}
#endif
