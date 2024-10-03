#ifndef CARDS_SETUP_HPP
#define CARDS_SETUP_HPP
#include "cards.h"

std::vector<Card> creation(std::vector<Card> deck) {
	int total_cards = 0;
	Card temporary_object;
	enum Suit temporary_suit;
	enum Value temporary_value;

	for (int i = 0; i < 13; ++i)
	{
		for (int x = 0; x < 4; ++x)
		{
			temporary_suit = fix_suit(x);
			temporary_value = fix_value(i);
			temporary_object.create(temporary_suit, temporary_value);
			deck[total_cards] = temporary_object;
			total_cards += 1;
		}
	}
	
	return deck;
}
#endif
