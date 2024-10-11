#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
	Card first_hand;
	Card second_hand;

public:
	Player(Card c_1, Card c_2);
	void player_display();
	Card give_card(int idx);
};

class Enemy
{
private:
	Card first_hand;
	Card second_hand;

public:
	Enemy(Card c_1, Card c_2);
	void player_display();
	Card give_card(int idx);
};

#endif