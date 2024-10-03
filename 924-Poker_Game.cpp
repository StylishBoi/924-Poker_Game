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

	int total_cards = 0;
	enum Suit temporary_suit;
	enum Value temporary_value;

	Card deck[53];

	for (int i = 0; i < 13; ++i)
	{
		for (int x = 0; x < 4; ++x)
		{
			temporary_suit = fix_suit(x);
			temporary_value = fix_value(i);
			deck[total_cards].create(temporary_suit, temporary_value);
			total_cards += 1;
		}
	}

	for (int w = 0; w < 52; ++w)
	{
		deck[w].card_display();
	}
}
