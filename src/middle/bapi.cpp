#include <bapi.h>
#include <string>
//Authentication tokens, I hope these aren't accessible anywhere.
const std::string authentication_key = "Cmh3gdcQx&XZVbDQFQgcoen>9&kXUQ69u*(m7D#LWqx&uh6%CQ=4hb$LG";

//USER/CHECK FUNCTIONS
bool bapi::user::check::checkUser(std::string token, char key, std::string username) {
	//Function to check presence of account.
	if (token == authentication_key) { //Proceed normally
		return true;
	}
	else
		return false;
}

bool bapi::user::check::login(std::string token, char key, std::string username, std::string password) {
	//INCOMPLETE
	return false;
}

bool bapi::user::check::logut(std::string token, std::string bid) {
	//INCOMPLETE
	return false;
}

//USER/GET/ATTRIBUTES Functions
std::string bapi::user::get::attributes::getUsers(std::string token, char usertype) {
	//INCOMPLETE
	return "0";
}

std::string bapi::user::get::attributes::getUser(std::string token, std::string BID_requestBy, std::string BID_requestOn) {
	//INCOMPLETE
	return "0";
}

std::string bapi::user::get::attributes::getUser(std::string token, std::string bid) {
	//INCOMPLETE
	return "0";
}

//USER/UPDATE/ATTRIBUTES Functions
bool bapi::user::update::attributes::updateUsers(std::string token, std::string bid, char action) {	//Consider removal.
	//INCOMPLETE
	return false;
}

bool bapi::user::update::attributes::updateUser(std::string token, std::string bid, JSON user) {
	//INCOMPLETE
	return false;
}

//USER/POST/ATTRIBUTES Functions
bool bapi::user::post::attributes::postUsers(std::string token, std::string BID_requestBy, char action, JSON* users) {	//Consider removal
	//INCOMPLETE
	return false;
}

bool bapi::user::post::attributes::postUser(std::string token, std::string BID_requestBy, char action, JSON user) {
	//INCOMPLETE
	return false;
}

//USER/POP/ATTRIBUTES Functions
bool bapi::user::pop::attributes::popUser(std::string token, std::string BID_requestBy, std::string BID_requestOn, char action) {
	//INCOMPLETE
	return false;
}