#ifndef DECK_H
#define DECK_H
#include "cards.h"
#include "enum_setup.hpp"
#include "vector"

class Deck
{
private:
	Card arrCards[52];

public:

	Deck() {
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
				arrCards[total_cards] = temporary_object;
				total_cards += 1;
			}
		}
	}

	void view_deck()
	{
		for (int w = 0; w < 52; ++w)
		{
			arrCards[w].ToString();
		}
	}
};

#endif