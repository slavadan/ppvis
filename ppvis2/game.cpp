#include "game.h"

void ConsoleUI::MainMenu()
{
	bool start = true;
	Player player, player1;
	GameField game;
	int coord_A, coord_B;

	int hod = 1;

	player1.set_symbol('o');
	player1.set_playername("Player23");

	while (start)
	{
		DisplayField(game);
		
		if (!(hod % 2))
		{
			std::cout << "Hod: " << player1.get_palyername() << std::endl;
			std::cin >> coord_A >> coord_B;
			player1.make_move(coord_A - 1, coord_B - 1, game);
			system("cls");
			--hod;
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
	game.fill_sqare(a, b, this);	
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
	return true;
}

void GameField::fill_sqare(int a, int b, Player* player)
{
	game_field[a][b] = player->get_symbol();
}
