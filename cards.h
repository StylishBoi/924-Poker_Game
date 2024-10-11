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
	void ToString();
	int return_value();

	//winning algorithms
	Card high_value(Card card_1, Card card_2);
	bool pair_verification(Card card_1, Card card_2);
	bool three_way_verification(Card card_1, Card card_2, Card card_3);
	bool flush(Card card_1, Card card_2, Card card_3, Card card_4, Card card_5);
	bool straight(Card card_1, Card card_2, Card card_3, Card card_4, Card card_5);
	bool four_way_verification(Card card_1, Card card_2, Card card_3, Card card_4);
	bool straight_flush(Card card_1, Card card_2, Card card_3, Card card_4, Card card_5);
	bool royal_flush(Card card_1, Card card_2, Card card_3, Card card_4, Card card_5);
};

#endif
