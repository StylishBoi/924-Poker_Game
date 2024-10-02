#include <iostream>

class Dealer
{
private:
	Card dealer_1;
	Card dealer_2;
	Card dealer_3;
	Card dealer_4;
	Card dealer_5;

public:
	Dealer(Card c_1, Card c_2, Card c_3, Card c_4, Card c_5) :
	dealer_1(c_1),
	dealer_2(c_2),
	dealer_3(c_1),
	dealer_4(c_2),
	dealer_5(c_1){};
};