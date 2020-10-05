/*
	Name: Joker (Bi Alpha)
	Author: Sarthak Sharma
	Created: 25-09-2020, 17:48
	Updated: 04-10-2020, 13:12
	Description: This is the entry point for our program. Contains a menu designed on switch for basic frontend.
*/
#include <iostream>
#include <modules.h>
#include <graphics.h>

int main() {
	unsigned short input;
	bivfx::welcome();
	bivfx::menu();
	std::cin >> input;
	switch (input)
	{
	case 1: bimdl::login();	// Present in Module source file
		break;
	case 2: bimdl::create();	// Present in Module source file
		break;
	case 3: bimdl::contact();	// Present in Module source file
		break;
	case 4: bivfx::close();		// Present in Graphic source file
		break;
	default: std::cout << "Incorrect input. Program will terminate" << std::endl;
		break;
	}
	//std::cin.get(); //Makes program to wait for us pressing enter before exiting.
}