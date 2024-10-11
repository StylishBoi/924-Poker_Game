#ifndef HANDS_VALUES_HPP
#define HANDS_VALUES_HPP
#include "player.h"
#include "dealer.h"
#include "win_condition.hpp"

int high_value(Player player, Enemy enemy) {
	int player_result=Lost;
	int enemy_result = Lost;
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
		player_result = Draw;
	}
	else if (highest_player.return_value() < highest_local.return_value())
	{
		std::cout << "The enemy has the higher card.\n";
		player_result = Lost;
	}
	else
	{
		std::cout << "The player has the higher card.\n";
		player_result = Win;
	}
	player_result = win_condition(player_result, enemy_result, player, enemy);
	return player_result;
}

int pair(Player player, Dealer dealer, Enemy enemy)
{
	int player_result = Lost;

	Card local_1(player.give_card(1));
	Card local_2(player.give_card(2));
	if (local_1.pair_verification(local_1, local_2)==true)
	{
		std::cout << "The player has one pair.\n";
		player_result = Win;
	}

	for (int idx = 1; idx < 6; ++idx)
	{
		Card dealer_card = dealer.give_card(idx);
		if(dealer_card.pair_verification(dealer_card, local_1)==true)
		{
			std::cout << "The player has one pair.\n";
			player_result = Win;
		}
		else if (dealer_card.pair_verification(dealer_card, local_2) == true)
		{
			std::cout << "The player has one pair.\n";
			player_result = Win;
		}
	}

	int enemy_result = Lost;
	Card enemy_1(enemy.give_card(1));
	Card enemy_2(enemy.give_card(2));
	if (enemy_1.pair_verification(enemy_1, enemy_2) == true)
	{
		std::cout << "The enemy has one pair.\n";
		enemy_result = Win;
	}

	for (int idx = 1; idx < 6; ++idx)
	{
		Card dealer_card = dealer.give_card(idx);
		if (dealer_card.pair_verification(dealer_card, enemy_1) == true)
		{
			std::cout << "The enemy has one pair.\n";
			enemy_result = Win;
		}
		else if (dealer_card.pair_verification(dealer_card, enemy_2) == true)
		{
			std::cout << "The enemy has one pair.\n";
			enemy_result = Win;
		}
	}
	player_result = win_condition(player_result, enemy_result, player, enemy);
	return player_result;
}

int two_pairs(Player player, Dealer dealer, Enemy enemy)
{

	int player_result = Lost;
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
				std::cout << "The player has two pairs.\n";
				player_result = Win;
			}
			else if (dealer_card.pair_verification(dealer_card, other_dealer) == true && dealer_card.pair_verification(dealer_card, local_1) == true)
			{
				std::cout << "The player has two pairs.\n";
				player_result = Win;
			}
			else if (dealer_card.pair_verification(dealer_card, local_1) == true && dealer_card.pair_verification(other_dealer, local_2) == true)
			{
				std::cout << "The player has two pairs.\n";
				player_result = Win;
			}
			else if (dealer_card.pair_verification(dealer_card, local_2) == true && dealer_card.pair_verification(other_dealer, local_1) == true)
			{
				std::cout << "The player has two pairs.\n";
				player_result = Win;
			}
			else if (dealer_card.pair_verification(local_1, local_2) == true && dealer_card.pair_verification(other_dealer, dealer_card) == true)
			{
				std::cout << "The player has two pairs.\n";
				player_result = Win;
			}
		}
	}

	Card enemy_1(enemy.give_card(1));
	Card enemy_2(enemy.give_card(2));

	int enemy_result = Lost;

	for (int idx = 1; idx < 6; ++idx)
	{
		Card dealer_card = dealer.give_card(idx);
		for (int wdx = idx + 1; wdx <6; ++wdx)
		{
			Card other_dealer = dealer.give_card((wdx));
			if (dealer_card.pair_verification(dealer_card, other_dealer) == true && dealer_card.pair_verification(dealer_card, enemy_2) == true)
			{
				std::cout << "The enemy has two pairs.\n";
				enemy_result = Win;
			}
			else if (dealer_card.pair_verification(dealer_card, other_dealer) == true && dealer_card.pair_verification(dealer_card, enemy_1) == true)
			{
				std::cout << "The enemy has two pairs.\n";
				enemy_result = Win;
			}
			else if (dealer_card.pair_verification(dealer_card, enemy_1) == true && dealer_card.pair_verification(other_dealer, enemy_2) == true)
			{
				std::cout << "The enemy has two pairs.\n";
				enemy_result = Win;
			}
			else if (dealer_card.pair_verification(dealer_card, enemy_2) == true && dealer_card.pair_verification(other_dealer, enemy_1) == true)
			{
				std::cout << "The enemy has two pairs.\n";
				enemy_result = Win;
			}
			else if (dealer_card.pair_verification(enemy_1, enemy_2) == true && dealer_card.pair_verification(other_dealer, dealer_card) == true)
			{
				std::cout << "The enemy has two pairs.\n";
				enemy_result = Win;
			}
		}
	}
	player_result = win_condition(player_result, enemy_result, player, enemy);
	return player_result;
}

int three_of_a_kind(Player player, Dealer dealer, Enemy enemy)
{
	int player_result = Lost;
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
				std::cout << "The player has three of a kind.\n";
				player_result = Win;
			}
			else if (local_1.three_way_verification(local_1, dealer_card, other_dealer) == true)
			{
				std::cout << "The player has three of a kind.\n";
				player_result = Win;
			}
			else if (local_2.three_way_verification(local_2, dealer_card, other_dealer) == true)
			{
				std::cout << "The player has three of a kind.\n";
				player_result = Win;
			}
		}
	}

	Card enemy_1(enemy.give_card(1));
	Card enemy_2(enemy.give_card(2));

	int enemy_result = Lost;

	for (int idx = 1; idx < 6; ++idx)
	{
		Card dealer_card = dealer.give_card(idx);
		if (enemy_1.three_way_verification(enemy_1, enemy_2, dealer_card) == true)
		{
			std::cout << "The enemy has three of a kind.\n";
			enemy_result = Win;
		}
		for (int wdx = idx + 1; wdx < 6; ++wdx)
		{
			Card other_dealer = dealer.give_card((wdx));
			
			if (enemy_1.three_way_verification(enemy_1, dealer_card, other_dealer) == true)
			{
				std::cout << "The enemy has three of a kind.\n";
				enemy_result = Win;
			}
			else if (enemy_2.three_way_verification(enemy_2, dealer_card, other_dealer) == true)
			{
				std::cout << "The enemy has three of a kind.\n";
				enemy_result = Win;
			}
		}
	}
	player_result = win_condition(player_result, enemy_result, player, enemy);
	return player_result;
}

int straight(Player player, Dealer dealer, Enemy enemy)
{
	Card local_1(player.give_card(1));
	Card local_2(player.give_card(2));
	int player_result = Lost;

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
						std::cout << "The player has a straight.\n";
						player_result = Win;
					}
					else if (local_1.straight(local_2, dealer_card1, dealer_card2, dealer_card3, dealer_card4) == true)
					{
						std::cout << "The player has a straight.\n";
						player_result = Win;
					}
					else if (local_1.straight(local_1, local_2, dealer_card1, dealer_card2, dealer_card3) == true)
					{
						std::cout << "The player has a straight.\n";
						player_result = Win;
					}
					else if (local_1.straight(local_1, local_2, dealer_card1, dealer_card2, dealer_card4) == true)
					{
						std::cout << "The player has a straight.\n";
						player_result = Win;
					}
				};
			};
		};
	};

	Card enemy_1(enemy.give_card(1));
	Card enemy_2(enemy.give_card(2));
	int enemy_result = Lost;

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
						std::cout << "The enemy has a straight.\n";
						enemy_result = Win;
					}
					else if (enemy_1.straight(enemy_2, dealer_card1, dealer_card2, dealer_card3, dealer_card4) == true)
					{
						std::cout << "The enemy has a straight.\n";
						enemy_result = Win;
					}
					else if (enemy_1.straight(enemy_1, enemy_2, dealer_card1, dealer_card2, dealer_card3) == true)
					{
						std::cout << "The enemy has a straight.\n";
						enemy_result = Win;
					}
					else if (enemy_1.straight(enemy_1, enemy_2, dealer_card1, dealer_card2, dealer_card4) == true)
					{
						std::cout << "The enemy has a straight.\n";
						enemy_result = Win;
					}
				};
			};
		};
	};
	player_result = win_condition(player_result, enemy_result, player, enemy);
	return player_result;
}

int flush(Player player, Dealer dealer, Enemy enemy)
{
	Card local_1(player.give_card(1));
	Card local_2(player.give_card(2));
	int player_result = Lost;

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
						std::cout << "The player has a flush.\n";
						player_result = Win;
					}
					else if (local_1.flush(local_2, dealer_card1, dealer_card2, dealer_card3, dealer_card4) == true)
					{
						std::cout << "The player has a flush.\n";
						player_result = Win;
					}
					else if (local_1.flush(local_1, local_2, dealer_card1, dealer_card2, dealer_card3) == true)
					{
						std::cout << "The player has a flush.\n";
						player_result = Win;
					}
					else if (local_1.flush(local_1, local_2, dealer_card1, dealer_card2, dealer_card4) == true)
					{
						std::cout << "The player has a flush.\n";
						player_result = Win;
					}
				};
			};
		};
	};

	Card enemy_1(enemy.give_card(1));
	Card enemy_2(enemy.give_card(2));
	int enemy_result = Lost;

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
						std::cout << "The enemy has a flush.\n";
						enemy_result = Win;
					}
					else if (enemy_1.flush(enemy_2, dealer_card1, dealer_card2, dealer_card3, dealer_card4) == true)
					{
						std::cout << "The enemy has a flush.\n";
						enemy_result = Win;
					}
					else if (enemy_1.flush(enemy_1, enemy_2, dealer_card1, dealer_card2, dealer_card3) == true)
					{
						std::cout << "The enemy has a flush.\n";
						enemy_result = Win;
					}
					else if (enemy_1.flush(enemy_1, enemy_2, dealer_card1, dealer_card2, dealer_card4) == true)
					{
						std::cout << "The enemy has a flush.\n";
						enemy_result = Win;
					}
				};
			};
		};
	};
	player_result = win_condition(player_result, enemy_result, player, enemy);
	return player_result;
}

int full_house(Player player, Dealer dealer, Enemy enemy)
{
	Card local_1(player.give_card(1));
	Card local_2(player.give_card(2));
	int player_result = Lost;

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

					if ((local_1.pair_verification(local_1, dealer_card1) == true) && (local_2.three_way_verification(local_2, dealer_card2, dealer_card3) == true))
					{
						std::cout << "The player has a full house.\n";
						player_result = Win;
					}
					else if ((local_1.pair_verification(local_1, dealer_card2) == true) && (local_2.three_way_verification(local_2, dealer_card3, dealer_card4) == true))
					{
						std::cout << "The player has a full house.\n";
						player_result = Win;
					}
					else if ((local_1.pair_verification(local_1, dealer_card3) == true) && (local_2.three_way_verification(local_2, dealer_card1, dealer_card2) == true))
					{
						std::cout << "The player has a full house.\n";
						player_result = Win;
					}
					else if ((local_2.pair_verification(local_2, dealer_card1) == true) && (local_1.three_way_verification(local_1, dealer_card2, dealer_card3) == true))
					{
						std::cout << "The player has a full house.\n";
						player_result = Win;
					}
					else if ((local_1.pair_verification(local_1, local_2) == true) && (dealer_card1.three_way_verification(dealer_card1, dealer_card2, dealer_card3) == true))
					{
						std::cout << "The player has a full house.\n";
						player_result = Win;
					}
					else if ((local_1.pair_verification(dealer_card1,dealer_card2) == true) && (local_1.three_way_verification(local_1, local_2, dealer_card3) == true))
					{
						std::cout << "The player has a full house.\n";
						player_result = Win;
					}
					else if ((local_1.pair_verification(dealer_card2, dealer_card3) == true) && (local_1.three_way_verification(local_1, local_2, dealer_card4) == true))
					{
						std::cout << "The player has a full house.\n";
						player_result = Win;
					}
				};
			};
		};
	};

	Card enemy_1(enemy.give_card(1));
	Card enemy_2(enemy.give_card(2));
	int enemy_result = Lost;

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

					if ((enemy_1.pair_verification(enemy_1, dealer_card1) == true) && (enemy_2.three_way_verification(enemy_2, dealer_card2, dealer_card3) == true))
					{
						std::cout << "The enemy has a full house.\n";
						enemy_result = Win;
					}
					else if ((enemy_1.pair_verification(enemy_1, dealer_card2) == true) && (enemy_2.three_way_verification(enemy_2, dealer_card3, dealer_card4) == true))
					{
						std::cout << "The enemy has a full house.\n";
						enemy_result = Win;
					}
					else if ((enemy_2.pair_verification(enemy_2, dealer_card1) == true) && (enemy_1.three_way_verification(enemy_1, dealer_card2, dealer_card3) == true))
					{
						std::cout << "The enemy has a full house.\n";
						enemy_result = Win;
					}
					else if ((enemy_1.pair_verification(enemy_1, enemy_2) == true) && (dealer_card1.three_way_verification(dealer_card1, dealer_card2, dealer_card3) == true))
					{
						std::cout << "The enemy has a full house.\n";
						enemy_result = Win;
					}
					else if ((enemy_1.pair_verification(dealer_card1, dealer_card2) == true) && (enemy_1.three_way_verification(enemy_1, enemy_2, dealer_card3) == true))
					{
						std::cout << "The enemy has a full house.\n";
						enemy_result = Win;
					}
					else if ((enemy_1.pair_verification(dealer_card2, dealer_card3) == true) && (enemy_1.three_way_verification(enemy_1, enemy_2, dealer_card4) == true))
					{
						std::cout << "The enemy has a full house.\n";
						enemy_result = Win;
					}
				};
			};
		};
	};
	player_result = win_condition(player_result, enemy_result, player, enemy);
	return player_result;
}

int four_of_a_kind(Player player, Dealer dealer, Enemy enemy)
{
	Card local_1(player.give_card(1));
	Card local_2(player.give_card(2));
	int player_result = Lost;

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
					std::cout << "The player has four of a kind.\n";
					player_result = Win;
				}
				else if (local_1.four_way_verification(local_2, dealer_card1, dealer_card2, dealer_card3) == true)
				{
					std::cout << "The player has four of a kind.\n";
					player_result = Win;
				}
				else if (local_1.four_way_verification(local_1, local_2, dealer_card1, dealer_card2) == true)
				{
					std::cout << "The player has four of a kind.\n";
					player_result = Win;
				}
				else if (local_1.four_way_verification(local_1, local_2, dealer_card1, dealer_card3) == true)
				{
					std::cout << "The player has four of a kind.\n";
					player_result = Win;
				}
			};
		};
	};

	Card enemy_1(enemy.give_card(1));
	Card enemy_2(enemy.give_card(2));
	int enemy_result = Lost;

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
					std::cout << "The enemy has four of a kind.\n";
					enemy_result = Win;
				}
				else if (enemy_1.four_way_verification(enemy_2, dealer_card1, dealer_card2, dealer_card3) == true)
				{
					std::cout << "The enemy has four of a kind.\n";
					enemy_result = Win;
				}
				else if (enemy_1.four_way_verification(enemy_1, enemy_2, dealer_card1, dealer_card2) == true)
				{
					std::cout << "The enemy has four of a kind.\n";
					enemy_result = Win;
				}
				else if (enemy_1.four_way_verification(enemy_1, enemy_2, dealer_card1, dealer_card3) == true)
				{
					std::cout << "The enemy has four of a kind.\n";
					enemy_result = Win;
				}
			};
		};
	};
	player_result = win_condition(player_result, enemy_result, player, enemy);
	return player_result;
}

int straight_flush	(Player player, Dealer dealer, Enemy enemy)
{
	Card local_1(player.give_card(1));
	Card local_2(player.give_card(2));
	int player_result = Lost;

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
						std::cout << "The player has a straight flush.\n";
						player_result = Win;
					}
					else if (local_1.straight_flush(local_2, dealer_card1, dealer_card2, dealer_card3, dealer_card4) == true)
					{
						std::cout << "The player has a straight flush.\n";
						player_result = Win;
					}
					else if (local_1.straight_flush(local_1, local_2, dealer_card1, dealer_card2, dealer_card3) == true)
					{
						std::cout << "The player has a straight flush.\n";
						player_result = Win;
					}
					else if (local_1.straight_flush(local_1, local_2, dealer_card1, dealer_card2, dealer_card4) == true)
					{
						std::cout << "The player has a straight flush.\n";
						player_result = Win;
					}
				};
			};
		};
	};

	Card enemy_1(enemy.give_card(1));
	Card enemy_2(enemy.give_card(2));
	int enemy_result = Lost;

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
						std::cout << "The enemy has a straight flush.\n";
						enemy_result = Win;
					}
					else if (enemy_1.straight_flush(enemy_2, dealer_card1, dealer_card2, dealer_card3, dealer_card4) == true)
					{
						std::cout << "The enemy has a straight flush.\n";
						enemy_result = Win;
					}
					else if (enemy_1.straight_flush(enemy_1, enemy_2, dealer_card1, dealer_card2, dealer_card3) == true)
					{
						std::cout << "The enemy has a straight flush.\n";
						enemy_result = Win;
					}
					else if (enemy_1.straight_flush(enemy_1, enemy_2, dealer_card1, dealer_card2, dealer_card4) == true)
					{
						std::cout << "The enemy has a straight flush.\n";
						enemy_result = Win;
					}
				};
			};
		};
	};
	player_result = win_condition(player_result, enemy_result, player, enemy);
	return player_result;
}

int royal_flush(Player player, Dealer dealer, Enemy enemy)
{
	Card local_1(player.give_card(1));
	Card local_2(player.give_card(2));
	int player_result = Lost;

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
						std::cout << "The player has a royal flush.\n";
						player_result = Win;
					}
					else if (local_1.royal_flush(local_2, dealer_card1, dealer_card2, dealer_card3, dealer_card4) == true)
					{
						std::cout << "The player has a royal flush.\n";
						player_result = Win;
					}
					else if (local_1.royal_flush(local_1, local_2, dealer_card1, dealer_card2, dealer_card3) == true)
					{
						std::cout << "The player has a royal flush.\n";
						player_result = Win;
					}
					else if (local_1.royal_flush(local_1, local_2, dealer_card1, dealer_card2, dealer_card4) == true)
					{
						std::cout << "The player has a royal flush.\n";
						player_result = Win;
					}
				};
			};
		};
	};

	Card enemy_1(enemy.give_card(1));
	Card enemy_2(enemy.give_card(2));
	int enemy_result = Lost;

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
						std::cout << "The enemy has a royal flush.\n";
						enemy_result = Win;
					}
					else if (enemy_1.royal_flush(enemy_2, dealer_card1, dealer_card2, dealer_card3, dealer_card4) == true)
					{
						std::cout << "The enemy has a royal flush.\n";
						enemy_result = Win;
					}
					else if (enemy_1.royal_flush(enemy_1, enemy_2, dealer_card1, dealer_card2, dealer_card3) == true)
					{
						std::cout << "The enemy has a royal flush.\n";
						enemy_result = Win;
					}
					else if (enemy_1.royal_flush(enemy_1, enemy_2, dealer_card1, dealer_card2, dealer_card4) == true)
					{
						std::cout << "The enemy has a royal flush.\n";
						enemy_result = Win;
					}
				};
			};
		};
	};
	player_result = win_condition(player_result, enemy_result, player, enemy);
	return player_result;
}
#endif