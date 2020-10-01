#pragma once
#include <iostream>
#include <string>
#include <vector>

class UserInterface
{
public:
	virtual void MainMenu() = 0;
};

class ConsoleUI : public UserInterface
{
public:
	void MainMenu() override;
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
public:

};