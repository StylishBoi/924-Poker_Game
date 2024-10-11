#ifndef CARDS_SETUP_HPP
#define CARDS_SETUP_HPP
#include <iostream>
#include "cards.h"
#include "player.h"
#include "deck.h"
#include "dealer.h"

Player player_cards(Deck &deck)
{
	srand(time(0));

	int card_chosen = rand() % deck.cards_left();
	Card local_card=deck.get_card(card_chosen);
	deck.erase_card(card_chosen);


	card_chosen = rand() % deck.cards_left();
	Card local_card_2 = deck.get_card(card_chosen);
	deck.erase_card(card_chosen);

	Player player(local_card, local_card_2);

	return player;
}

Enemy enemy_cards(Deck& deck)
{
	srand(time(0));

	int card_chosen = rand() % deck.cards_left();
	Card local_card = deck.get_card(card_chosen);
	deck.erase_card(card_chosen);


	card_chosen = rand() % deck.cards_left();
	Card local_card_2 = deck.get_card(card_chosen);
	deck.erase_card(card_chosen);

	Enemy enemy(local_card, local_card_2);

	return enemy;
}

Dealer dealer_cards(Deck& deck)
{
	srand(time(0));
	int card_chosen;

	card_chosen = rand() % deck.cards_left();
	Card local_card = deck.get_card(card_chosen);
	deck.erase_card(card_chosen);

	card_chosen = rand() % deck.cards_left();
	Card local_card_2 = deck.get_card(card_chosen);
	deck.erase_card(card_chosen);

	card_chosen = rand() % deck.cards_left();
	Card local_card_3 = deck.get_card(card_chosen);
	deck.erase_card(card_chosen);

	card_chosen = rand() % deck.cards_left();
	Card local_card_4 = deck.get_card(card_chosen);
	deck.erase_card(card_chosen);

	card_chosen = rand() % deck.cards_left();
	Card local_card_5 = deck.get_card(card_chosen);
	deck.erase_card(card_chosen);

	Dealer dealer(local_card, local_card_2, local_card_3, local_card_4, local_card_5);

	return dealer;
}
#endif
