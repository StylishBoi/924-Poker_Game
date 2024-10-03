#ifndef CARDS_H
#define CARDS_H

class Card
{
private:
	enum Suit suit;
	enum Value value;

public:
	void create(enum Suit s_, enum Value v_);
	void check_suit();
	void check_value();
	void card_display();

	//winning algorithms
	void pair_verification(Card card_1, Card card_2);
};

#endif
