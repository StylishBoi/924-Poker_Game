#include <type_traits>
#ifndef PLAYER_FUNCTIONS_CC
#define PLAYER_FUNCTIONS_CC
#include "cards.h"
#include "player.h"

Player::Player(Card c_1, Card c_2) : first_hand(c_1), second_hand(c_2) {};

void Player::player_display()
{
	first_hand.ToString();
	second_hand.ToString();
};

Card Player::give_card(int idx)
{
	switch(idx)
	{
	case 1:
		return first_hand;
	case 2:
		return second_hand;
	}
}

Enemy::Enemy(Card c_1, Card c_2) : first_hand(c_1), second_hand(c_2) {};

void Enemy::player_display()
{
	first_hand.ToString();
	second_hand.ToString();
};

Card Enemy::give_card(int idx)
{
	switch (idx)
	{
	case 1:
		return first_hand;
	case 2:
		return second_hand;
	}
}

#endif
