#ifndef POKER_GAME
#define POKER_GAME
#include "deck.h"
#include "cards_setup.hpp"
#include "hand_values.hpp"

int main()
{
	//setting up cards
	Deck deck;
	Player player = player_cards(deck);
	Enemy enemy = enemy_cards(deck);
	Dealer dealer = dealer_cards(deck);

	player.player_display();
	enemy.player_display();

	high_value(player, enemy);
	pair(player, dealer, enemy);
	two_pairs(player, dealer, enemy);
	three_of_a_kind(player, dealer, enemy);
	flush(player, dealer, enemy);
	straight(player, dealer, enemy);
	four_of_a_kind(player, dealer, enemy);
	straight_flush(player, dealer, enemy);
	royal_flush(player, dealer, enemy);
}
#endif
