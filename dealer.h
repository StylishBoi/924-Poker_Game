#ifndef DEALER_H
#define DEALER_H
#include "cards.h"

class Dealer
{
private:
	Card dealer_1;
	Card dealer_2;
	Card dealer_3;
	Card dealer_4;
	Card dealer_5;

public:
	Dealer(Card c_1, Card c_2, Card c_3, Card c_4, Card c_5);

	void dealer_display();
	Card give_card(int idx);
};

#endif
