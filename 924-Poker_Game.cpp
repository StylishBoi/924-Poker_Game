// 924-Poker_Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "enum_setup.hpp"

class Card
{
public:
	enum Suit suit;
	enum Value value;

	Card(enum Suit s_, enum Value v_) : suit(s_), value(v_) {};

	void check_suit()
	{
		switch(suit)
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
	void check_value()
	{
		switch(value)
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
};

int main()
{
	srand(time(0));
	enum Suit value_1 = random_suit();
	enum Value value_2 = random_value();
	Card card_1(value_1,value_2);
	card_1.check_suit();
	card_1.check_value();
}
