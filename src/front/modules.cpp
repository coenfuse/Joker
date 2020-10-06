#include <iostream>
#include <graphics.h>
#include <modules.h>
#include <bisystem.h>
#include <bapi.h>
#include <time.h>
#include <JSON.h>

//Local variables
/*--------------------------------------------------------------------------------------------------------*/
short admin = 1;
//short SUP = 2;
//short MOD = 3;
short student = 4;
//short EMP = 5;

//Local declarations
/*--------------------------------------------------------------------------------------------------------*/

void loginAttempt(unsigned short attempt);
short dashboard(JSON, short);

//Core definitions
/*--------------------------------------------------------------------------------------------------------*/
void bimdl::login() {
	unsigned short input;
	bivfx::loginMenu();
	std::cin >> input;
	switch (input){
	case 1: {
		loginAttempt(4);
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

//Local Definitions
/*--------------------------------------------------------------------------------------------------------*/
void loginAttempt(unsigned short attempt) {	//COMPLETE
	std::system("cls");
	if (attempt >= 0 && attempt < 5) {
		std::cout << "\t\t\t\t\t    Attempts remaining: 0" << attempt + 1 << std::endl;
		std::cout << "\n\t\t\t       Please enter your Network ID (e.g: BINET12345)" << std::endl;
		std::cout << "\t\t\t       Network ID: ";
		std::string net;
		std::cin >> net;
		std::cout << "\t\t\t       Please enter your Username and Password" << std::endl;
		std::cout << "\t\t\t       Username: ";
		std::string username;
		std::cin >> username;
		if (bapi::user::chk::checkUser(access_token, admin, username, net)) {
			std::cout << "\t\t\t       Password: ";
			std::string salt;
			std::cin >> salt;
			if (bapi::user::chk::cred(access_token, admin, username, salt)) {
				JSON atr = JSON(bapi::user::get::atr::getUser(access_token, username), 1);

				short log;
				log = dashboard(atr, admin);
			}
		}
		std::cout << "User not found in the given network. Retry? [Y/N]" << std::endl;
		char choice = '0';
		std::cin >> choice;
		if (choice == 'Y' || choice == 'y')
			loginAttempt(--attempt);
		else bivfx::close();
		exit(0);
	}
	std::cout << "Too many incorrect inputs. System will now terminate." << std::endl;
}

short dashboard(JSON atr, short type) { //INCOMPLETE
	time_t session_start = time(NULL); //Log session starting time
	time_t session_end = time(NULL); //Log session ending time
	time_t session_dur = difftime(session_start, session_end); //Find session duration
	return 1;
}