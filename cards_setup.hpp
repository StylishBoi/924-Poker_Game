#ifndef CARDS_SETUP_HPP
#define CARDS_SETUP_HPP
#include <vector>

void creation() {
	std::vector<Card> deck;
	int total_cards = 0;
	enum Suit temporary_suit;
	enum Value temporary_value;

	for (int i = 0; i < 13; ++i)
	{
		for (int x = 0; x < 4; ++x)
		{
			total_cards += 1;
			temporary_suit = fix_suit(x);
			temporary_value = fix_value(i);
			deck.emplace_back(temporary_suit, temporary_value);
			std::cout << temporary_suit << temporary_value << "\n";
		}
	}
	std::cout << "Total is " << total_cards;
}

#endif
