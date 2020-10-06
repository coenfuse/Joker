#include <bapi.h>
#include <string>

//Local declarations
bool checkAuth(std::string token);
bool checkNetwork(std::string NET);

//USER/CHECK FUNCTIONS
/*-----------------------------------------------------------------------------------------------*/
bool bapi::user::chk::checkUser(std::string token, short key, std::string username, std::string net) {	//INCOMPLETE
	/*Function to check presence of account.
	* 
	* Parameter 1 = Access Token of type 'std::string'
	* Parameter 2 = Function key of type 'short'
	*	- Key = 1, for Admin
	*	- Key = 2, for Support
	*   - Key = 3, for Moderator
	*	- Key = 4, for Student
	*	- Key = 5, for Employee
	* Parameter 3 = Username string of type 'std::string'. Correlates to AID
	* Parameter 4 = Network ID string of type 'std::string'. Correlates to NET
	* 
	*/
	if (checkAuth(token)) {
		switch (key)
		{
		case 1: {
			if (checkNetwork(net)) {

			}
		}
			  break;
		case 2:
		case 3:
		case 4:
		case 5:
		default:
			break;
		}
		return true;
	}
	else
		return false;
}

bool bapi::user::chk::cred(std::string token, char key, std::string username, std::string password) {
	//INCOMPLETE
	return false;
}

bool bapi::user::chk::logut(std::string token, std::string bid) {
	//INCOMPLETE
	return false;
}


//USER/GET/ATTRIBUTES Functions
/*-----------------------------------------------------------------------------------------------*/
std::string bapi::user::get::atr::getUsers(std::string token, char usertype) {
	//INCOMPLETE
	return "0";
}

std::string bapi::user::get::atr::getUser(std::string token, std::string BID_requestBy, std::string BID_requestOn) {
	//INCOMPLETE
	return "0";
}

std::string bapi::user::get::atr::getUser(std::string token, std::string bid) {
	//INCOMPLETE
	return "0";
}


//USER/UPDATE/ATTRIBUTES Functions
/*-----------------------------------------------------------------------------------------------*/
bool bapi::user::up::atr::updateUsers(std::string token, std::string bid, char action) {	//Consider removal.
	//INCOMPLETE
	return false;
}

bool bapi::user::up::atr::updateUser(std::string token, std::string bid, JSON user) {
	//INCOMPLETE
	return false;
}


//USER/POST/ATTRIBUTES Functions
/*-----------------------------------------------------------------------------------------------*/
bool bapi::user::post::atr::postUsers(std::string token, std::string BID_requestBy, char action, JSON* users) {	//Consider removal
	//INCOMPLETE
	return false;
}

bool bapi::user::post::atr::postUser(std::string token, std::string BID_requestBy, char action, JSON user) {
	//INCOMPLETE
	return false;
}


//USER/POP/ATTRIBUTES Functions
/*-----------------------------------------------------------------------------------------------*/
namespace userPop = bapi::user::pop::atr;
bool userPop::popUser(std::string token, std::string BID_requestBy, std::string BID_requestOn, char action) {
	//INCOMPLETE
	return false;
}

//NETWORK/CHECK Functions
/*-----------------------------------------------------------------------------------------------*/
bool bapi::net::chk::searchObj(std::string token, short key, std::string NET, std::string BID) { //INCOMPLETE
	return true;
}

//Local Definitions
bool checkAuth(std::string token) {
	const std::string authentication_key = "Cmh3gdcQx&XZVbDQFQgcoen>9&kXUQ69u*(m7D#LWqx&uh6%CQ=4hb$LG";
	if (token == authentication_key)
		return true;
	return false;
}

bool checkNetwork(std::string NET) { //INCOMPLETE
	return false;
}