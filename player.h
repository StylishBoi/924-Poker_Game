#include <iostream>

class Player
{
private:
	Card first_hand;
	Card second_hand;

public:
	Player(Card c_1, Card c_2) : first_hand(c_1), second_hand(c_2) {};

	void player_display()
	{
		first_hand.card_display();
	};
};