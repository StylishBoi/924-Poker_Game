#ifndef CARDS_FUNCTIONS
#define CARDS_FUNCTIONS

#include <iostream>
#include "cards.h"

void Card::create(enum Suit s_, enum Value v_)
{
	suit = s_;
	value = v_;
}
void Card::check_suit()
	{
		switch (suit)
		{
		case 0:
			std::cout << "Clubs\n";
			break;
		case 1:
			std::cout << "Hearts\n";
			break;
		case 2:
			std::cout << "Spades\n";
			break;
		case 3:
			std::cout << "Squares\n";
			break;
		}
	}
void Card::check_value()
	{
		switch (value)
		{
		case 2:
			std::cout << "Two";
			break;
		case 3:
			std::cout << "Three";
			break;
		case 4:
			std::cout << "Four";
			break;
		case 5:
			std::cout << "Five";
			break;
		case 6:
			std::cout << "Six";
			break;
		case 7:
			std::cout << "Seven";
			break;
		case 8:
			std::cout << "Eight";
			break;
		case 9:
			std::cout << "Nine";
			break;
		case 10:
			std::cout << "Ten";
			break;
		case 11:
			std::cout << "Joker";
			break;
		case 12:
			std::cout << "Queen";
			break;
		case 13:
			std::cout << "King";
			break;
		case 14:
			std::cout << "Ace";
			break;
		}
	}
void Card::ToString()
{
	check_value();
	std::cout << " of ";
	check_suit();
	std::cout << "\n";
}
void Card::pair_verification(Card card_1,Card card_2)
{
	if (card_1.value==card_2.value)
	{
		std::cout << "You have a pair !\n";
	}
	else
	{
		std::cout << "You do not have a pair :[\n";
	}
}

#endif 