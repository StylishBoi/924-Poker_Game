// 924-Poker_Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "enum_setup.hpp"
#include "cards.h"
#include "player.h"
#include "dealer.h"
#include "cards_setup.hpp"

int main()
{
	srand(time(0));
	Card card_1(random_suit(), random_value());
	Card card_2(random_suit(), random_value());

	creation();

	Player player_1(card_1, card_2);

	Card card_3(random_suit(), random_value());
	Card card_4(random_suit(), random_value());
	Card card_5(random_suit(), random_value());
	Card card_6(random_suit(), random_value());
	Card card_7(random_suit(), random_value());

	Dealer deal(card_3, card_4, card_5, card_6, card_7);
}
