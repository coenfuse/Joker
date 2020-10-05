//Consider creating separate files for each of these functions
#include <iostream>
#include <graphics.h>
#include <modules.h>

void bimdl::login() {
	unsigned short input;
	bivfx::loginMenu();
	std::cin >> input;
	switch (input){
	case 1: {
		std::cout << "\t\t\t       Please enter your Username and Password" << std::endl;
		std::cout << "\t\t\t       Username: ";
		std::string username;
		std::cin >> username;
		std::cout << "\t\t\t       Password: ";
		std::string salt;
		std::cin >> salt;
		std::cout << "Username: " << username << ", Password: " << salt << std::endl;
	}
		break;
	case 2: std::cout << "This functionality is in development. Check back later." << std::endl;
		break;
	case 3: std::cout << "This functionality is in development. Check back later." << std::endl;
		break;
	case 4: {
		std::cout << "\t\t\t Please enter your Enrollment Number or College ID" << std::endl;
	}
		break;
	case 5: std::cout << "This functionality is in development. Check back later." << std::endl;
		break;
	case 6: std::cout << "This functionality is in development. Check back later." << std::endl;
		break;
	case 0:
		break;
	default: std::cout << "Incorrect input. Program will terminate" << std::endl;
		break;
	}
}

void bimdl::create() {

}

void bimdl::contact() {

}
