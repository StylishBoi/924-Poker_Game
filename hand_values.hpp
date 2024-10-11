#ifndef HANDS_VALUES_HPP
#define HANDS_VALUES_HPP
#include "player.h"
#include "dealer.h"

void high_value(Player player, Enemy enemy) {
	int highest_idx = 1;

	Card local_card(player.give_card(1));
	Card local_2(player.give_card(2));
	Card highest_local(local_card.high_value(local_card, local_2));
	Card highest_player = highest_local;


	for (int idx = 1; idx < 2;++idx)
	{
		local_card =enemy.give_card(idx);
		highest_local = highest_local.high_value(highest_local,local_card);
	}
	if (highest_player.return_value() == highest_local.return_value())
	{
		std::cout << "The highest value is the same.\n"
			;
	}
	else if (highest_player.return_value() < highest_local.return_value())
	{
		std::cout << "The enemy has the higher card.\n";
	}
	else
	{
		std::cout << "The player has the higher card.\n";
	}
}

void pair(Player player, Dealer dealer, Enemy enemy)
{
	bool player_pair = false;
	bool enemy_pair = false;

	dealer.dealer_display();
	Card local_1(player.give_card(1));
	Card local_2(player.give_card(2));
	if (local_1.pair_verification(local_1, local_2)==true)
	{
		std::cout << "The player has one pair with his own cards.\n";
		player_pair = true;
	}

	for (int idx = 1; idx < 6; ++idx)
	{
		Card dealer_card = dealer.give_card(idx);
		if(dealer_card.pair_verification(dealer_card, local_1)==true)
		{
			std::cout << "Player has one pair with the dealer cards.\n";
			player_pair = true;
		}
		else if (dealer_card.pair_verification(dealer_card, local_2) == true)
		{
			std::cout << "Player has one pair with the dealer cards.\n";
			player_pair = true;
		}
	}

	Card enemy_1(enemy.give_card(1));
	Card enemy_2(enemy.give_card(2));
	if (enemy_1.pair_verification(enemy_1, enemy_2) == true)
	{
		std::cout << "The enemy has one pair with his own cards.\n";
		enemy_pair = true;
	}

	for (int idx = 1; idx < 6; ++idx)
	{
		Card dealer_card = dealer.give_card(idx);
		if (dealer_card.pair_verification(dealer_card, enemy_1) == true)
		{
			std::cout << "Enemy has one pair with the dealer cards.\n";
			enemy_pair = true;
		}
		else if (dealer_card.pair_verification(dealer_card, enemy_2) == true)
		{
			std::cout << "Enemy has one pair with the dealer cards.\n";
			enemy_pair = true;
		}
	}

	if (enemy_pair == true && player_pair == true)
	{
		std::cout << "It's a tie.\n";
	}
	else if (enemy_pair == true)
	{
		std::cout << "The enemy wins.\n";
	}
	else if (player_pair==true)
	{
		std::cout << "The player wins.\n";
	}
	else
	{
		std::cout << "Nobody has a pair.\n";
	}
}

void two_pairs(Player player, Dealer dealer, Enemy enemy)
{
	Card local_1(player.give_card(1));
	Card local_2(player.give_card(2));

	for (int idx = 1; idx < 6; ++idx)
	{
		Card dealer_card = dealer.give_card(idx);
		for (int wdx=idx+1; wdx<6;++wdx)
		{
			Card other_dealer = dealer.give_card((wdx));
			if (dealer_card.pair_verification(dealer_card, other_dealer)==true && dealer_card.pair_verification(dealer_card, local_2) == true)
			{
				std::cout << "There are two pairs on the table.";
			}
			else if (dealer_card.pair_verification(dealer_card, other_dealer) == true && dealer_card.pair_verification(dealer_card, local_1) == true)
			{
				std::cout << "There are two pairs on the table.";
			}
			else if (dealer_card.pair_verification(dealer_card, local_1) == true && dealer_card.pair_verification(other_dealer, local_2) == true)
			{
				std::cout << "Player has two pairs with the dealer cards via his own cards.\n";
			}
			else if (dealer_card.pair_verification(dealer_card, local_2) == true && dealer_card.pair_verification(other_dealer, local_1) == true)
			{
				std::cout << "Player has two pairs with the dealer cards via his own cards.\n";
			}
			else if (dealer_card.pair_verification(local_1, local_2) == true && dealer_card.pair_verification(other_dealer, dealer_card) == true)
			{
				std::cout << "Player has two pairs with the dealer cards via his own cards.\n";
			}
		}
	}

	Card enemy_1(enemy.give_card(1));
	Card enemy_2(enemy.give_card(2));

	for (int idx = 1; idx < 6; ++idx)
	{
		Card dealer_card = dealer.give_card(idx);
		if (dealer_card.pair_verification(dealer_card, enemy_1) == true && dealer_card.pair_verification(dealer_card, enemy_2) == true)
		{
			std::cout << "Enemy has two pairs with the dealer cards via his own cards.\n";
		}
		for (int wdx = idx + 1; wdx <6; ++wdx)
		{
			Card other_dealer = dealer.give_card((wdx));
			if (dealer_card.pair_verification(dealer_card, other_dealer) == true && dealer_card.pair_verification(dealer_card, enemy_2) == true)
			{
				std::cout << "There are two pairs on the table.";
			}
			else if (dealer_card.pair_verification(dealer_card, other_dealer) == true && dealer_card.pair_verification(dealer_card, enemy_1) == true)
			{
				std::cout << "There are two pairs on the table.";
			}
			else if (dealer_card.pair_verification(dealer_card, enemy_1) == true && dealer_card.pair_verification(other_dealer, enemy_2) == true)
			{
				std::cout << "Enemy has two pairs with the dealer cards and his own cards.\n";
			}
			else if (dealer_card.pair_verification(dealer_card, enemy_2) == true && dealer_card.pair_verification(other_dealer, enemy_1) == true)
			{
				std::cout << "Enemy has two pairs with the dealer cards and his own cards.\n";
			}
			else if (dealer_card.pair_verification(enemy_1, enemy_2) == true && dealer_card.pair_verification(other_dealer, dealer_card) == true)
			{
				std::cout << "Enemy has two pairs with the dealer cards and his own cards.\n";
			}
		}
	}
}

void three_of_a_kind(Player player, Dealer dealer, Enemy enemy)
{
	Card local_1(player.give_card(1));
	Card local_2(player.give_card(2));

	for (int idx = 1; idx < 6; ++idx)
	{
		Card dealer_card = dealer.give_card(idx);
		for (int wdx = idx + 1; wdx < 6; ++wdx)
		{
			Card other_dealer = dealer.give_card((wdx));
			if (local_1.three_way_verification(local_1, local_2, dealer_card) == true)
			{
				std::cout << "There are three of a kind on the table for the player.";
			}
			else if (local_1.three_way_verification(local_1, dealer_card, other_dealer) == true)
			{
				std::cout << "There are three of a kind on the table for the player.";
			}
			else if (local_2.three_way_verification(local_2, dealer_card, other_dealer) == true)
			{
				std::cout << "There are three of a kind on the table for the player.";
			}
			else if (local_1.three_way_verification(local_1, local_2, other_dealer) == true)
			{
				std::cout << "There are three of a kind on the table for the player.";
			}
		}
	}

	Card enemy_1(enemy.give_card(1));
	Card enemy_2(enemy.give_card(2));

	for (int idx = 1; idx < 6; ++idx)
	{
		Card dealer_card = dealer.give_card(idx);
		for (int wdx = idx + 1; wdx < 6; ++wdx)
		{
			Card other_dealer = dealer.give_card((wdx));
			if (enemy_1.three_way_verification(enemy_1, enemy_2, dealer_card) == true)
			{
				std::cout << "There are three of a kind on the table for the enemy.";
			}
			else if (enemy_1.three_way_verification(enemy_1, dealer_card, other_dealer) == true)
			{
				std::cout << "There are three of a kind on the table for the enemy.";
			}
			else if (enemy_2.three_way_verification(enemy_2, dealer_card, other_dealer) == true)
			{
				std::cout << "There are three of a kind on the table for the enemy.";
			}
			else if (enemy_1.three_way_verification(enemy_1, enemy_2, other_dealer) == true)
			{
				std::cout << "There are three of a kind on the table for the enemy.";
			}
		}
	}
}

void flush(Player player, Dealer dealer, Enemy enemy)
{
	Card local_1(player.give_card(1));
	Card local_2(player.give_card(2));

	for (int a = 1; a < 6; ++a)
	{
		Card dealer_card1 = dealer.give_card(a);
		for (int b = a + 1; b < 6; ++b)
		{
			Card dealer_card2 = dealer.give_card(b);
			for (int c = b + 1; c < 6; ++c)
			{
				Card dealer_card3 = dealer.give_card(c);
				for (int d = c + 1; d < 6; ++d)
				{
					Card dealer_card4 = dealer.give_card(d);

					if (local_1.flush(local_1, dealer_card1, dealer_card2, dealer_card3, dealer_card4) == true)
					{
						std::cout << "The player has a flush.";
					}
					else if (local_1.flush(local_2, dealer_card1, dealer_card2, dealer_card3, dealer_card4) == true)
					{
						std::cout << "The player has a flush.";
					}
					else if (local_1.flush(local_1, local_2, dealer_card1, dealer_card2, dealer_card3) == true)
					{
						std::cout << "The player has a flush.";
					}
					else if (local_1.flush(local_1, local_2, dealer_card1, dealer_card2, dealer_card4) == true)
					{
						std::cout << "The player has a flush.";
					}
				};
			};
		};
	};

	Card enemy_1(enemy.give_card(1));
	Card enemy_2(enemy.give_card(2));

	for (int a = 1; a < 6; ++a)
	{
		Card dealer_card1 = dealer.give_card(a);
		for (int b = a + 1; b < 6; ++b)
		{
			Card dealer_card2 = dealer.give_card(b);
			for (int c = b + 1; c < 6; ++c)
			{
				Card dealer_card3 = dealer.give_card(c);
				for (int d = c + 1; d < 6; ++d)
				{
					Card dealer_card4 = dealer.give_card(d);

					if (enemy_1.flush(enemy_1, dealer_card1, dealer_card2, dealer_card3, dealer_card4) == true)
					{
						std::cout << "The player has a flush.";
					}
					else if (enemy_1.flush(enemy_2, dealer_card1, dealer_card2, dealer_card3, dealer_card4) == true)
					{
						std::cout << "The player has a flush.";
					}
					else if (enemy_1.flush(enemy_1, enemy_2, dealer_card1, dealer_card2, dealer_card3) == true)
					{
						std::cout << "The player has a flush.";
					}
					else if (enemy_1.flush(enemy_1, enemy_2, dealer_card1, dealer_card2, dealer_card4) == true)
					{
						std::cout << "The player has a flush.";
					}
				};
			};
		};
	};
}

void straight(Player player, Dealer dealer, Enemy enemy)
{
	Card local_1(player.give_card(1));
	Card local_2(player.give_card(2));

	for (int a = 1; a < 6; ++a)
	{
		Card dealer_card1 = dealer.give_card(a);
		for (int b = a + 1; b < 6; ++b)
		{
			Card dealer_card2 = dealer.give_card(b);
			for (int c = b + 1; c < 6; ++c)
			{
				Card dealer_card3 = dealer.give_card(c);
				for (int d = c + 1; d < 6; ++d)
				{
					Card dealer_card4 = dealer.give_card(d);

					if (local_1.straight(local_1, dealer_card1, dealer_card2, dealer_card3, dealer_card4) == true)
					{
						std::cout << "The player has a straight.";
					}
					else if (local_1.straight(local_2, dealer_card1, dealer_card2, dealer_card3, dealer_card4) == true)
					{
						std::cout << "The player has a straight.";
					}
					else if (local_1.straight(local_1, local_2, dealer_card1, dealer_card2, dealer_card3) == true)
					{
						std::cout << "The player has a straight.";
					}
					else if (local_1.straight(local_1, local_2, dealer_card1, dealer_card2, dealer_card4) == true)
					{
						std::cout << "The player has a straight.";
					}
				};
			};
		};
	};

	Card enemy_1(enemy.give_card(1));
	Card enemy_2(enemy.give_card(2));

	for (int a = 1; a < 6; ++a)
	{
		Card dealer_card1 = dealer.give_card(a);
		for (int b = a + 1; b < 6; ++b)
		{
			Card dealer_card2 = dealer.give_card(b);
			for (int c = b + 1; c < 6; ++c)
			{
				Card dealer_card3 = dealer.give_card(c);
				for (int d = c + 1; d < 6; ++d)
				{
					Card dealer_card4 = dealer.give_card(d);

					if (enemy_1.straight(enemy_1, dealer_card1, dealer_card2, dealer_card3, dealer_card4) == true)
					{
						std::cout << "The player has a straight.";
					}
					else if (enemy_1.straight(enemy_2, dealer_card1, dealer_card2, dealer_card3, dealer_card4) == true)
					{
						std::cout << "The player has a straight.";
					}
					else if (enemy_1.straight(enemy_1, enemy_2, dealer_card1, dealer_card2, dealer_card3) == true)
					{
						std::cout << "The player has a straight.";
					}
					else if (enemy_1.straight(enemy_1, enemy_2, dealer_card1, dealer_card2, dealer_card4) == true)
					{
						std::cout << "The player has a straight.";
					}
				};
			};
		};
	};
}

void four_of_a_kind(Player player, Dealer dealer, Enemy enemy)
{
	Card local_1(player.give_card(1));
	Card local_2(player.give_card(2));

	for (int a = 1; a < 6; ++a)
	{
		Card dealer_card1 = dealer.give_card(a);
		for (int b = a + 1; b < 6; ++b)
		{
			Card dealer_card2 = dealer.give_card(b);
			for (int c = b + 1; c < 6; ++c)
			{
				Card dealer_card3 = dealer.give_card(c);

				if (local_1.four_way_verification(local_1, dealer_card1, dealer_card2, dealer_card3) == true)
				{
					std::cout << "The player has four of a kind.";
				}
				else if (local_1.four_way_verification(local_2, dealer_card1, dealer_card2, dealer_card3) == true)
				{
					std::cout << "The player has four of a kind.";
				}
				else if (local_1.four_way_verification(local_1, local_2, dealer_card1, dealer_card2) == true)
				{
					std::cout << "The player has four of a kind.";
				}
				else if (local_1.four_way_verification(local_1, local_2, dealer_card1, dealer_card3) == true)
				{
					std::cout << "The player has four of a kind.";
				}
			};
		};
	};

	Card enemy_1(enemy.give_card(1));
	Card enemy_2(enemy.give_card(2));

	for (int a = 1; a < 6; ++a)
	{
		Card dealer_card1 = dealer.give_card(a);
		for (int b = a + 1; b < 6; ++b)
		{
			Card dealer_card2 = dealer.give_card(b);
			for (int c = b + 1; c < 6; ++c)
			{
				Card dealer_card3 = dealer.give_card(c);

				if (enemy_1.four_way_verification(enemy_1, dealer_card1, dealer_card2, dealer_card3) == true)
				{
					std::cout << "The enemy has four of a kind.";
				}
				else if (enemy_1.four_way_verification(enemy_2, dealer_card1, dealer_card2, dealer_card3) == true)
				{
					std::cout << "The enemy has four of a kind.";
				}
				else if (enemy_1.four_way_verification(enemy_1, enemy_2, dealer_card1, dealer_card2) == true)
				{
					std::cout << "The enemy has four of a kind.";
				}
				else if (enemy_1.four_way_verification(enemy_1, enemy_2, dealer_card1, dealer_card3) == true)
				{
					std::cout << "The enemy has four of a kind.";
				}
			};
		};
	};
}

void straight_flush	(Player player, Dealer dealer, Enemy enemy)
{
	Card local_1(player.give_card(1));
	Card local_2(player.give_card(2));

	for (int a = 1; a < 6; ++a)
	{
		Card dealer_card1 = dealer.give_card(a);
		for (int b = a + 1; b < 6; ++b)
		{
			Card dealer_card2 = dealer.give_card(b);
			for (int c = b + 1; c < 6; ++c)
			{
				Card dealer_card3 = dealer.give_card(c);
				for (int d = c + 1; d < 6; ++d)
				{
					Card dealer_card4 = dealer.give_card(d);

					if (local_1.straight_flush(local_1, dealer_card1, dealer_card2, dealer_card3, dealer_card4) == true)
					{
						std::cout << "The player has a straight flush.";
					}
					else if (local_1.straight_flush(local_2, dealer_card1, dealer_card2, dealer_card3, dealer_card4) == true)
					{
						std::cout << "The player has a straight flush.";
					}
					else if (local_1.straight_flush(local_1, local_2, dealer_card1, dealer_card2, dealer_card3) == true)
					{
						std::cout << "The player has a straight flush.";
					}
					else if (local_1.straight_flush(local_1, local_2, dealer_card1, dealer_card2, dealer_card4) == true)
					{
						std::cout << "The player has a straight flush.";
					}
				};
			};
		};
	};

	Card enemy_1(enemy.give_card(1));
	Card enemy_2(enemy.give_card(2));

	for (int a = 1; a < 6; ++a)
	{
		Card dealer_card1 = dealer.give_card(a);
		for (int b = a + 1; b < 6; ++b)
		{
			Card dealer_card2 = dealer.give_card(b);
			for (int c = b + 1; c < 6; ++c)
			{
				Card dealer_card3 = dealer.give_card(c);
				for (int d = c + 1; d < 6; ++d)
				{
					Card dealer_card4 = dealer.give_card(d);

					if (enemy_1.straight_flush(enemy_1, dealer_card1, dealer_card2, dealer_card3, dealer_card4) == true)
					{
						std::cout << "The player has a straight flush.";
					}
					else if (enemy_1.straight_flush(enemy_2, dealer_card1, dealer_card2, dealer_card3, dealer_card4) == true)
					{
						std::cout << "The player has a straight flush.";
					}
					else if (enemy_1.straight_flush(enemy_1, enemy_2, dealer_card1, dealer_card2, dealer_card3) == true)
					{
						std::cout << "The player has a straight flush.";
					}
					else if (enemy_1.straight_flush(enemy_1, enemy_2, dealer_card1, dealer_card2, dealer_card4) == true)
					{
						std::cout << "The player has a straight flush.";
					}
				};
			};
		};
	};
}

void royal_flush(Player player, Dealer dealer, Enemy enemy)
{
	Card local_1(player.give_card(1));
	Card local_2(player.give_card(2));

	for (int a = 1; a < 6; ++a)
	{
		Card dealer_card1 = dealer.give_card(a);
		for (int b = a + 1; b < 6; ++b)
		{
			Card dealer_card2 = dealer.give_card(b);
			for (int c = b + 1; c < 6; ++c)
			{
				Card dealer_card3 = dealer.give_card(c);
				for (int d = c + 1; d < 6; ++d)
				{
					Card dealer_card4 = dealer.give_card(d);

					if (local_1.royal_flush(local_1, dealer_card1, dealer_card2, dealer_card3, dealer_card4) == true)
					{
						std::cout << "The player has a royal flush.";
					}
					else if (local_1.royal_flush(local_2, dealer_card1, dealer_card2, dealer_card3, dealer_card4) == true)
					{
						std::cout << "The player has a royal flush.";
					}
					else if (local_1.royal_flush(local_1, local_2, dealer_card1, dealer_card2, dealer_card3) == true)
					{
						std::cout << "The player has a royal flush.";
					}
					else if (local_1.royal_flush(local_1, local_2, dealer_card1, dealer_card2, dealer_card4) == true)
					{
						std::cout << "The player has a royal flush.";
					}
				};
			};
		};
	};

	Card enemy_1(enemy.give_card(1));
	Card enemy_2(enemy.give_card(2));

	for (int a = 1; a < 6; ++a)
	{
		Card dealer_card1 = dealer.give_card(a);
		for (int b = a + 1; b < 6; ++b)
		{
			Card dealer_card2 = dealer.give_card(b);
			for (int c = b + 1; c < 6; ++c)
			{
				Card dealer_card3 = dealer.give_card(c);
				for (int d = c + 1; d < 6; ++d)
				{
					Card dealer_card4 = dealer.give_card(d);

					if (enemy_1.royal_flush(enemy_1, dealer_card1, dealer_card2, dealer_card3, dealer_card4) == true)
					{
						std::cout << "The player has a royal flush.";
					}
					else if (enemy_1.royal_flush(enemy_2, dealer_card1, dealer_card2, dealer_card3, dealer_card4) == true)
					{
						std::cout << "The player has a royal flush.";
					}
					else if (enemy_1.royal_flush(enemy_1, enemy_2, dealer_card1, dealer_card2, dealer_card3) == true)
					{
						std::cout << "The player has a royal flush.";
					}
					else if (enemy_1.royal_flush(enemy_1, enemy_2, dealer_card1, dealer_card2, dealer_card4) == true)
					{
						std::cout << "The player has a royal flush.";
					}
				};
			};
		};
	};
}
#endif