#ifndef DECK_H
#define DECK_H
#include "cards.h"
#include <vector>

class Deck
{
private:
	std::vector<Card> arrCards;

public:

	Deck();

	Card get_card(int Number);

	void erase_card(int index);

	void view_deck();

	int cards_left();

};

#endif