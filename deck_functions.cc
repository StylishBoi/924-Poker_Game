#ifndef FUNCTIONS_DECK_CC
#define FUNCTIONS_DECK_CC
#include "deck.h"
#include "enum_setup.h"

Deck::Deck() {
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

Card Deck::get_card(int number)
{
	return arrCards[number];
}

/*Card Deck::erase_card(int index)
{
	arrCards.erase(arrCards.begin() + index);

}*/

void Deck::view_deck()
{
	for (int w = 0; w < 52; ++w)
	{
		arrCards[w].ToString();
	}
}

#endif