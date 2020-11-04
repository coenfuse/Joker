#include <iostream>
#include "graphics.h"
void bivfx::welcome(){	//COMPLETE
	std::cout << "==============================================================================================" << std::endl;
	std::cout << "\n##      ##      ## ########## ##         #######     ####        ##      ##     ##########";
	std::cout << "\n ##    ####    ##  ##         ##        ##         ##    ##     ####    ####    ##";
	std::cout << "\n  ##  ##  ##  ##   ######     ##       ##         ##      ##   ##  ##  ##  ##   ######";
	std::cout << "\n   ####    ####    ##         ##        ##         ##    ##   ##    ####    ##  ##";
	std::cout << "\n    ##      ##     ########## ########   #######     ####    ##      ##      ## ##########" << std::endl;
	std::cout << "\n";
	std::cout << "==============================================================================================";
	std::cout << "\n                                         To JOKER";
	std::cout << "\n                       A working protoype for Bi collection of systems" << std::endl;
	std::cout << "==============================================================================================" << std::endl;
}

void bivfx::menu() {	//COMPLETE
	std::cout << "\n\n";
	std::cout << "\t\t\t+-------------------  MENU  -------------------+" << std::endl;
	std::cout << "\t\t\t|                                              |" << std::endl;
	std::cout << "\t\t\t|-------------  1. Login into Bi  -------------|" << std::endl;
	std::cout << "\t\t\t|                                              |" << std::endl;
	std::cout << "\t\t\t|------------  2. Sign In into Bi  ------------|" << std::endl;
	std::cout << "\t\t\t|                                              |" << std::endl;
	std::cout << "\t\t\t|----------  3. Contact Bi dev team  ----------|" << std::endl;
	std::cout << "\t\t\t|                                              |" << std::endl;
	std::cout << "\t\t\t|----------------  4. Exit Bi  ----------------|" << std::endl;
	std::cout << "\t\t\t|                                              |" << std::endl;
	std::cout << "\t\t\t+----------------------------------------------+" << std::endl;
	std::cout << "\n";
	std::cout << "\t\t\t     Press any number from 1 to 4 to proceed" << std::endl;
}

void bivfx::close(){	//COMPLETE
	//Inspired by Grand Theft Auto Vice City exit splash screen
	std::cout << "\n\n**********************************************************************************************" << std::endl;
	std::cout << "Before you go we would like to thank You for using Joker." << std::endl;
	std::cout << "\nJoker is a small prototype for Bi system of softwares whose primary focus is robust cycle re-";
	std::cout << "\nntal mechanisms that aims to provide many other relevant information than just stale network's";
	std::cout << "\n statistics. While Joker is just an experimental escape for planning alpha level features for ";
	std::cout << "\nBi. Bi is developing out to provide vast array of functionalities that will make it easy to d-";
	std::cout << "\neploy on network of any scale." << std::endl;
	std::cout << "It is developed as a minor project by Sarthak Sharma and Saalim Ali. Any feedback would be highly appreciated.";
	std::cout << "\nMore information about this project can be found on its Github page at : github.com/coenboi/Joker"<<std::endl;
	std::cout << "\nPress Enter/Return to exit.";
	std::cout << "\n**********************************************************************************************\n\n" << std::endl;
	std::cin.get();
}
void bivfx::loginMenu() { //COMPLETE
	std::cout << "\n" << std::endl;
	std::cout << "\t\t\t+----------------  LOGIN MENU  ----------------+" << std::endl;
	std::cout << "\t\t\t|                                              |" << std::endl;
	std::cout << "\t\t\t|-----  Press 1 to Login as Administrator  ----|" << std::endl;
	std::cout << "\t\t\t|                                              |" << std::endl;
	std::cout << "\t\t\t|---------------  <COMING SOON>  --------------|" << std::endl;
	std::cout << "\t\t\t|                                              |" << std::endl;
	std::cout << "\t\t\t|---------------  <COMING SOON>  --------------|" << std::endl;
	std::cout << "\t\t\t|                                              |" << std::endl;
	std::cout << "\t\t\t|--------  Press 4 to Login as Student  -------|" << std::endl;
	std::cout << "\t\t\t|                                              |" << std::endl;
	std::cout << "\t\t\t|---------------  <COMING SOON>  --------------|" << std::endl;
	std::cout << "\t\t\t|                                              |" << std::endl;
	std::cout << "\t\t\t|---------------  <COMING SOON>  --------------|" << std::endl;
	std::cout << "\t\t\t|                                              |" << std::endl;
	std::cout << "\t\t\t|------------  Press 0 to go back  ------------|" << std::endl;
	std::cout << "\t\t\t|                                              |" << std::endl;
	std::cout << "\t\t\t+----------------------------------------------+" << std::endl;
	std::cout << "\n";
	std::cout << "\t\t\t\t\tWaiting for Input..." << std::endl;
}