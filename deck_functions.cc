#ifndef FUNCTIONS_DECK_CC
#define FUNCTIONS_DECK_CC
#include "deck.h"
#include "enum_setup.h"
#include <vector>
#include <iostream>

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
			arrCards.push_back(temporary_object);
			total_cards += 1;
		}
	}
}

Card Deck::get_card(int number)
{
	return arrCards[number];
}

void Deck::erase_card(int index)
{
	std::vector<Card> local_vector;
	local_vector = arrCards;
	arrCards.erase(arrCards.begin() + index);

}

void Deck::view_deck()
{
	for (int w = 0; w < 52; ++w)
	{
		arrCards[w].ToString();
	}
}

int Deck::cards_left()
{
	return arrCards.size();
}


#endif