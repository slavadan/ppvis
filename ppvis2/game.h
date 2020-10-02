#pragma once
#include <iostream>
#include <string>
#include <vector>

class UserInterface
{
public:
	virtual void MainMenu() = 0;
};

class GameField;

class ConsoleUI : public UserInterface
{
public:
	void MainMenu() override;
	void DisplayField(GameField& field);
};

class Player
{
private:
	std::string player_name = "Player";
	char symbol = 'x';

public:
	void set_playername(std::string player_name);
	std::string get_palyername();


	void make_move(int a, int b, GameField& game);
	char get_symbol();
	void set_symbol(char symbol);
};


class GameField
{
private:
	std::vector<std::string> game_field =
	{
		{"   "},
		{"   "},
		{"   "}
	};

	bool check_sqare(int a, int b);

public:
	void fill_sqare(int a, int b, Player* player);
	//void check_winner();

	friend void ConsoleUI::DisplayField(GameField& field);
	friend void Player::make_move(int a, int b, GameField& game);
};
