#ifndef WIN_CONDITION_HPP
#define WIN_CONDITION_HPP
#include "hand_values.hpp"

enum Win
{
	Win = 2,
	Lost = 1,
	Draw = 0
};

int win_condition(int player_result, int enemy_result, Player player, Enemy enemy)
{
	if (player_result==Win and enemy_result==Win)
	{
		Card Player_1 = player.give_card(1);
		Card Player_2 = player.give_card(2);
		Card Enemy_1 = player.give_card(1);
		Card Enemy_2 = player.give_card(2);
		if(Player_1.value_draw(Player_1,Player_2,Enemy_1,Enemy_2)==2)
		{
			std::cout << "Both players had the same hand but you had the highest card.\n";
			return Win;
		}
		else if (Player_1.value_draw(Player_1, Player_2, Enemy_1, Enemy_2) == 1)
		{
			std::cout << "Both players had the same hand but the enemy had the highest card.\n";
			return Lost;
		}
		else {
			std::cout << "It's a draw.\n";
			return Draw;
		}
	}
	else if (player_result==Win)
	{
		std::cout << "It's a win for the player.\n";
		return Win;
	}
	else if (enemy_result==Win)
	{
		std::cout << "It's a win for the enemy.\n";
		return Lost;
	}
	else
	{
		return Draw;
	}
}

#endif