/*
	Name: Joker
	Author: Sarthak Sharma
	Date: 25-09-20 17:48
	Description: This is the entry point for our program. Contains a menu designed on switch for basic frontend.
*/
#include <iostream>
#include "../include/modules.h"
#include "../include/graphics.h"

int main(){
	welcomeGraphic();
	std::cout << "Select an option to proceed. Press number 1 to 4" << std::endl;
	std::cin.get(); //Makes program to wait for us pressing enter before exiting.
	//std::cin input;
}
