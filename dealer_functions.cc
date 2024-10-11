#ifndef PLAYER_FUNCTIONS_CC
#define PLAYER_FUNCTIONS_CC
#include "dealer.h"


	Dealer::Dealer(Card c_1, Card c_2, Card c_3, Card c_4, Card c_5) :
		dealer_1(c_1),
		dealer_2(c_2),
		dealer_3(c_3),
		dealer_4(c_4),
		dealer_5(c_5) {};

void Dealer::dealer_display()
{
	dealer_1.ToString();
	dealer_2.ToString();
	dealer_3.ToString();
	dealer_4.ToString();
	dealer_5.ToString();
};

Card Dealer::give_card(int idx)
{
	switch (idx)
	{
	case 1:
		return dealer_1;
	case 2:
		return dealer_2;
	case 3:
		return dealer_3;
	case 4:
		return dealer_4;
	case 5:
		return dealer_5;
	}
}
#endif