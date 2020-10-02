#include "game.h"

void ConsoleUI::MainMenu()
{
	bool start = true;
	Player player, player1;
	GameField game;
	int coord_A, coord_B, choose;

	int hod = 1;

	player1.set_symbol('o');
	player1.set_playername("Player23");

	while (start)
	{
		DisplayField(game);
		
		if (!(hod % 2))
		{

			if (game.find_winner(player))
			{
				std::cout << "winner: " << player.get_palyername() << std::endl;
				system("pause");
				system("cls");

			}
			else
			{
				std::cout << "Hod: " << player1.get_palyername() << std::endl;
				std::cin >> coord_A >> coord_B;
				player1.make_move(coord_A - 1, coord_B - 1, game);
				system("cls");
				--hod;
			}

		}
		else
		{

			if (game.find_winner(player1))
			{
				std::cout << "winner: " << player1.get_palyername() << std::endl;
				system("pause");
				system("cls");

			}
			else
			{
				std::cout << "Hod: " << player.get_palyername() << std::endl;
				std::cin >> coord_A >> coord_B;
				player.make_move(coord_A - 1, coord_B - 1, game);
				system("cls");
				++hod;
			}


		}

	}
}

void ConsoleUI::DisplayField(GameField & field)
{
	for (int a = 0; a < field.game_field.size(); a++)
	{
		std::cout << "_________" << std::endl;
		for (int m = 0; m < field.game_field[a].size(); m++)
			std::cout << field.game_field[a][m] << " |";
		std::cout << std::endl;
	}
}

void Player::set_playername(std::string player_name)
{
	this->player_name = player_name;
}

std::string Player::get_palyername()
{
	return player_name;
}

void Player::make_move(int a, int b, GameField & game)
{
	if (game.check_sqare(a, b))
		game.fill_sqare(a, b, this);
	else
		return;
}

char Player::get_symbol()
{
	return symbol;
}

void Player::set_symbol(char symbol)
{
	this->symbol = symbol;
}

bool GameField::check_sqare(int a, int b)
{
	if (game_field[a][b] == ' ')
		return true;
	else
		return false;
}

int GameField::horizontal_check(Player& player)
{
	int count = 0;
	char win_symbol = player.get_symbol();

	for (int i = 0; i < game_field.size(); i++)
	{
		for (int a = 0; a < game_field[i].size(); a++)
		{
			if (game_field[i][a] == win_symbol)
			{
				count++;
			}
			else
				break;
		}
		count = 0;
	}

	return count;
}

int GameField::vertical_check(Player & player)
{
	int count = 0;
	char win_symbol = player.get_symbol();

	for (int i = 0; i < game_field.size(); i++)
	{
		for (int a = 0; a < game_field[i].size(); a++)
		{
			if (game_field[a][i] == win_symbol)
			{
				count++;
			}
			else
				break;
		}
		count = 0;
	}

	return count;
}

int GameField::diag_check(Player & player)
{
	char win_symbol = player.get_symbol();
	if (game_field[0][0] == win_symbol && game_field[1][1] == win_symbol && game_field[2][2] == win_symbol)
		return 3;
	else if (game_field[0][2] == win_symbol && game_field[1][1] == win_symbol && game_field[2][0] == win_symbol)
		return 3;
	else
		return 0;
}

void GameField::fill_sqare(int a, int b, Player* player)
{
	game_field[a][b] = player->get_symbol();
}

bool GameField::find_winner(Player& player)
{
	//std::cout << count << std::endl;
	//system("pause");
	//system("cls");

	if (horizontal_check(player) == 3 || vertical_check(player) == 3 || diag_check(player) == 3)
		return true;
	else
		return false;
}
