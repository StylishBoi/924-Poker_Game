enum Suit
{
	Clubs,
	Hearts,
	Spades,
	Squares
};

enum Value
{
	Two = 2,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Joker,
	Queen,
	King,
	Ace,
};

enum Suit random_suit()
{
	int test_1 = rand() % 4;
	switch (test_1)
	{
	case 0:
		return Clubs;
	case 1:
		return Hearts;
	case 2:
		return Spades;
	case 3:
		return Squares;
	}
}

enum Value random_value()
{
	int test_1 = rand() % 14;
	switch (test_1)
	{
	case 0:
		return Two;
	case 1:
		return Three;
	case 2:
		return Four;
	case 3:
		return Five;
	case 4:
		return Six;
	case 5:
		return Seven;
	case 6:
		return Eight;
	case 7:
		return Nine;
	case 8:
		return Ten;
	case 9:
		return Joker;
	case 10:
		return Queen;
	case 11:
		return King;
	case 12:
		return Ace;
	}
}