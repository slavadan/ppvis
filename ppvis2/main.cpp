#include <iostream>
#include "game.h"

void DisplayGUI(UserInterface* GUI)
{
	GUI->MainMenu();
}

int main()
{
	UserInterface* Console = new ConsoleUI();
	DisplayGUI(Console);
	delete Console;

	return 0;
}