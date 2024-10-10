#ifndef POKER_GAME
#define POKER_GAME
#include "deck.h"
#include <iostream>
#include <vector>

int main()
{
	Deck deck;
	deck.view_deck();
	Card second_deck = deck.get_card(7);
	second_deck.ToString();

	std::vector<int> test;
	test.push_back(6);
	test.push_back(-17);
	test.push_back(12);
	test.erase(test.begin() + 1);
	std::cout << test[1];
}
#endif
