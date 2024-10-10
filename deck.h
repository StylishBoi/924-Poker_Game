#ifndef DECK_H
#define DECK_H
#include "cards.h"

class Deck
{
private:
	Card arrCards[52];

public:

	Deck();

	Card get_card(int Number);

	Card erase_card(int index);

	void view_deck();

};

#endif