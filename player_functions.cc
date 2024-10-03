#ifndef PLAYER_FUNCTIONS_CC
#define PLAYER_FUNCTIONS_CC
#include "cards.h"
#include "player.h"

Player::Player(Card c_1, Card c_2) : first_hand(c_1), second_hand(c_2) {};

void Player::player_display()
{
	first_hand.card_display();
	second_hand.card_display();
};
#endif
