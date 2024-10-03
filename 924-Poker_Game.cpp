#include <iostream>
#include <vector>
#include "enum_setup.hpp"
#include "cards.h"
#include "player.h"
#include "game_setup.hpp"
#include "cards_setup.hpp"

//recipient.erase(recipient.begin() + 0); UTILISER POUR SUPPRIMER UNE CARTE DU TAS

int main()
{
	srand(time(0));
	Card temporary_object;
	std::vector<Card> deck= { 52, temporary_object };
	deck=creation(deck);

	//Variables for cards creations
	for (int w = 0; w < deck.size(); ++w)
	{
		deck[w].card_display();
	}

	Player temporary_deck2 = player_cards(deck);
	temporary_deck2.player_display();
	Dealer temporary_deck3 = dealer_cards(deck);
}
