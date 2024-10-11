#ifndef POKER_GAME_HPP
#define POKER_GAME_HPP

enum poker_choice
{
	Fold=1,
	Call=2,
	Raise=3,
};

int Poker_Hands(Player player, Dealer dealer, Enemy enemy)
{
	int win;
	win=royal_flush(player, dealer, enemy);
	switch (win)
	{
	case Win:
		return Win;
	case Lost:
		return Lost;
	}
	win = straight_flush(player, dealer, enemy);
	switch (win)
	{
	case Win:
		return Win;
	case Lost:
		return Lost;
	}
	win = four_of_a_kind(player, dealer, enemy);
	switch (win)
	{
	case Win:
		return Win;
	case Lost:
		return Lost;
	}
	win = full_house(player, dealer, enemy);
	switch (win)
	{
	case Win:
		return Win;
	case Lost:
		return Lost;
	}
	win = flush(player, dealer, enemy);
	switch (win)
	{
	case Win:
		return Win;
	case Lost:
		return Lost;
	}
	win = straight(player, dealer, enemy);
	switch (win)
	{
	case Win:
		return Win;
	case Lost:
		return Lost;
	}
	win = three_of_a_kind(player, dealer, enemy);
	switch (win)
	{
	case Win:
		return Win;
	case Lost:
		return Lost;
	}
	win = two_pairs(player, dealer, enemy);
	switch (win)
	{
	case Win:
		return Win;
	case Lost:
		return Lost;
	}
	win = pair(player, dealer, enemy);
	switch (win)
	{
	case Win:
		return Win;
	case Lost:
		return Lost;
	}
	win = high_value(player, enemy);
	switch (win)
	{
	case Win:
		return Win;
	case Lost:
		return Lost;
	}
}

int poker_hand()
{
	int answer;
	std::cout << "1 - Fold\n2 - Call\n3 - Raise\n\n";
	while (true)
	{
		std::cin >> answer;
		switch (answer)
		{
		case Fold:
			std::cout << "\nYou have folded.\n";
			std::cout << "As you have folded, you have lost your money.\n";
			std::cout << "\n - * - * - * - * - * - * - * - \n\n";
			return Fold;
		case Call:
			std::cout << "\nYou have decided to call.\nThe betting amount remains the same.\n";
			return Call;
		case Raise:
			std::cout << "\nYou have decided to raise.\n";
			return Raise;
		default:
			std::cout << "\nWrong input, please try again.\n\n";
			break;
		}
	}
}

int bet_money(int player_money, int betting_money)
{
	int player_choice;
	while (true) {
		std::cout << "How much are you going to bet ?\n";
		std::cin >> betting_money;
		if (betting_money > player_money)
		{
			std::cout << "You have bet higher than your own money, please bet again.\n";
		}
		else
		{
			std::cout << "\nThe betting amount has been set as " << betting_money << "\n\n";
			return betting_money;
		}
	}
}

int raise_money(int player_money, int betting_money)
{
	int player_choice;
	player_money = player_money - betting_money;
	betting_money = 0;
	std::cout << "This is the amount of money left you have : "<<player_money<<"\n";
	while (true) {
		std::cout << "How much are you going to raise ?\n";
		std::cin >> betting_money;
		if (betting_money > player_money)
		{
			std::cout << "You have bet higher than your own money, please bet again.\n";
		}
		else
		{
			std::cout << "The betting amount has raised by " << betting_money << "\n\n\n";
			return betting_money;
		}
	}
}

int Poker_Match(int player_money, Player player, Dealer dealer, Enemy enemy)
{
	//Phase 1
	int betting_money=0;
	int player_choice;
	std::cout << "Money : "<<player_money<<"\n\n";
	betting_money =bet_money(player_money, betting_money);


	std::cout << "\n - * - * - * - * - * - * - * - * - * - * - \n\n";

	std::cout << "- * - Phase 1 - * -\n\n";

	std::cout << "These are your cards : \n\n";
	player.player_display();

	player_choice=poker_hand();
	switch (player_choice)
	{
	case Fold:
		return player_money-betting_money;
	case Call:
		break;
	case Raise:
		std::cout << "How much do you want to raise the amount by ?\n";
		betting_money = betting_money + raise_money(player_money, betting_money);
		std::cout << "This means the total of the betting money is now : " << betting_money<<"\n";
		break;
	}

	std::cout << "\n - * - * - * - * - * - * - * - * - * - * - \n\n";
	//Phase 2

	std::cout << "- * - Phase 2 - * -\n\n";

	std::cout << "These are the dealer cards : \n\n";
	Card dealer_1(dealer.give_card(1));
	Card dealer_2 (dealer.give_card(2));
	Card dealer_3 (dealer.give_card(3));
	dealer_1.ToString();
	dealer_2.ToString();
	dealer_3.ToString();

	std::cout << "# # # # # \n\n";

	std::cout << "These are your cards : \n\n";
	player.player_display();

	player_choice = poker_hand();
	switch (player_choice)
	{
	case Fold:
		return player_money - betting_money;
	case Call:
		break;
	case Raise:
		std::cout << "How much do you want to raise the amount by ?\n";
		betting_money = betting_money + raise_money(player_money, betting_money);
		std::cout << "This means the total of the betting money is now : " << betting_money;
		break;
	}

	std::cout << "\n - * - * - * - * - * - * - * - \n\n";
	//Phase 3

	std::cout << "- * - Phase 3 - * -\n\n";

	std::cout << "These are the dealer cards : \n\n";
	Card dealer_4(dealer.give_card(4));
	dealer_1.ToString();
	dealer_2.ToString();
	dealer_3.ToString();
	dealer_4.ToString();

	std::cout << "# # # # # \n\n";

	std::cout << "These are your cards : \n\n";
	player.player_display();

	player_choice = poker_hand();
	switch (player_choice)
	{
	case Fold:
		return player_money - betting_money;
	case Call:
		break;
	case Raise:
		std::cout << "How much do you want to raise the amount by ?\n";
		betting_money = betting_money + raise_money(player_money, betting_money);
		std::cout << "This means the total of the betting money is now : " << betting_money;
		break;
	}

	std::cout << "\n - * - * - * - * - * - * - * - \n\n";
	//Phase 4

	std::cout << "- * - Phase 4 - * -\n\n";

	std::cout << "These are the dealer cards : \n\n";
	Card dealer_5(dealer.give_card(5));
	dealer_1.ToString();
	dealer_2.ToString();
	dealer_3.ToString();
	dealer_4.ToString();
	dealer_5.ToString();

	std::cout << "# # # # # \n\n";

	std::cout << "These are your cards : \n\n";
	player.player_display();

	player_choice = poker_hand();
	switch (player_choice)
	{
	case Fold:
		return player_money - betting_money;
	case Call:
		break;
	case Raise:
		std::cout << "How much do you want to raise the amount by ?\n";
		betting_money = betting_money + raise_money(player_money, betting_money);
		std::cout << "This means the total of the betting money is now : " << betting_money;
		break;
	}

	std::cout << "\n - * - * - * - * - * - * - * - \n\n";
	//Phase 5

	std::cout << "- * - Phase 5 - * -\n\n";

	std::cout << "These are the dealer cards : \n\n";
	dealer_1.ToString();
	dealer_2.ToString();
	dealer_3.ToString();
	dealer_4.ToString();
	dealer_5.ToString();

	std::cout << "# # # # # \n\n";

	std::cout << "These are your cards : \n\n";
	player.player_display();

	std::cout << "These are the enemy cards : \n\n";
	enemy.player_display();

	std::cout << "# # # # # \n\n";

	int result;
	result=Poker_Hands(player, dealer, enemy);
	if (result==Win)
	{
		std::cout << "You have won the match.\n";
		std::cout << "Money lost : " << player_money*2<<"\n";
		std::cout << "\n - * - * - * - * - * - * - * - \n\n";
		return player_money * 2;
	}
	else if(result==Lost)
	{
		std::cout << "You have lost the match.\n";
		std::cout << "Money lost : " << player_money - betting_money<<"\n";
		std::cout << "\n - * - * - * - * - * - * - * - \n\n";
		return player_money - betting_money;
	}
	else
	{
		std::cout << "It's a draw, you do not lose any money.\n";
	}
}
#endif
