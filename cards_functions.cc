#ifndef CARDS_FUNCTIONS
#define CARDS_FUNCTIONS

#include <iostream>
#include "cards.h"
#include <vector>

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
int Card::return_value()
{
	return value;
}

Card Card::high_value(Card card_1, Card card_2)
{
	if (card_1.value>card_2.value)
	{
		return card_1;
	}
	else if (card_1.value < card_2.value)
	{
		return card_2;
	}
	else
	{
		return card_2;
	}
}
int Card::value_draw(Card card_1, Card card_2, Card enemy_1, Card enemy_2)
{
	if ((card_1.value > enemy_1.value) && (card_1.value > enemy_2.value))
	{
		return 2;
	}
	else if ((card_2.value > enemy_1.value) && (card_2.value > enemy_2.value))
	{
		return 2;
	}
	else if ((card_2.value < enemy_1.value) && (card_1.value < enemy_1.value))
	{
		return 1;
	}
	else if ((card_2.value < enemy_2.value) && (card_1.value < enemy_2.value))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool Card::pair_verification(Card card_1,Card card_2)
{
	if (card_1.value==card_2.value)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Card::three_way_verification(Card card_1, Card card_2,Card card_3)
{
	if ((card_1.value == card_2.value) and (card_2.value == card_3.value) and (card_1.value==card_3.value))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Card::flush(Card card_1, Card card_2, Card card_3, Card card_4, Card card_5)
{
	if ((card_1.suit==card_2.suit) && (card_2.suit==card_3.suit) && (card_3.suit==card_4.suit) && (card_4.suit==card_5.suit))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Card::straight(Card card_1, Card card_2, Card card_3, Card card_4, Card card_5)
{
	std::vector<int> straight;
	straight = {card_1.value, card_2.value, card_3.value, card_4.value, card_5.value};

	for (int i = 0; i < straight.size(); i++)
	{
		for (int j = 1; j < straight.size(); j++) {
			if (straight[i] > straight[j])
			{
				int temp = straight[i];
				straight[i] = straight[j];
				straight[j] = temp;
			}
		}
	}

	if ((straight[1]+1==straight[2]) && (straight[2] + 1 == straight[3]) && (straight[3] + 1 == straight[4]) && (straight[4] + 1 == straight[5])){
		return true;
	}
	else{
		return false;
	}
}
bool Card::four_way_verification(Card card_1, Card card_2, Card card_3, Card card_4)
{
	if ((card_1.value == card_2.value) && (card_2.value == card_3.value) && (card_3.value == card_4.value))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Card::straight_flush(Card card_1, Card card_2, Card card_3, Card card_4, Card card_5)
{
	std::vector<int> straight;
	straight = { card_1.value, card_2.value, card_3.value, card_4.value, card_5.value };

	for (int i = 0; i < straight.size(); i++)
	{
		for (int j = 1; j < straight.size(); j++) {
			if (straight[i] > straight[j])
			{
				int temp = straight[i];
				straight[i] = straight[j];
				straight[j] = temp;
			}
		}
	}

	if ((straight[1] + 1 == straight[2]) && (straight[2] + 1 == straight[3]) && (straight[3] + 1 == straight[4]) && (straight[4] + 1 == straight[5])) {
		if ((card_1.suit == card_2.suit) && (card_2.suit == card_3.suit) && (card_3.suit == card_4.suit) && (card_4.suit == card_5.suit))
		{
			return true;
		}
	}
	else {
		return false;
	}
}
bool Card::royal_flush(Card card_1, Card card_2, Card card_3, Card card_4, Card card_5)
{
	std::vector<int> straight;
	straight = { card_1.value, card_2.value, card_3.value, card_4.value, card_5.value };

	for (int i = 0; i < straight.size(); i++)
	{
		for (int j = i + 1; j < straight.size(); j++) {
			if (straight[i] > straight[j])
			{
				int temp = straight[i];
				straight[i] = straight[j];
				straight[j] = temp;
			}
		}
	}

	if ((straight[1] == 10) && (straight[2] == 11) && (straight[3] == 12) && (straight[4] == 13) && (straight[5] == 14)) {
		if ((card_1.suit == card_2.suit) && (card_2.suit == card_3.suit) && (card_3.suit == card_4.suit) && (card_4.suit == card_5.suit))
		{
			return true;
		}
	}
	else {
		return false;
	}
}

#endif 