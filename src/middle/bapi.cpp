#include <bapi.h>
#include <string>
#include <stdlib.h>
#include <ctime>

//Local variables
/*-----------------------------------------------------------------------------------------------*/
const std::string salt[] = {
	"bjF^W4Rtht","6+VsquQ94v","Bsa!4UV@dm","L@Ke#gH9Ns","AMEvRv^6SP","#ZyVyfj7LQ","Q%3yBQn9DV",
	"2umn+=FSb3","7V!M-hn#89","&SC^J*v4?j","4BAeeN8-Qa","&SFWSMwH6P","rPe5Vp%nyw","yHjC-vT5Fp",
	"8*Hy2qx8+g","s_r%9mGC29","fh4x+A_A4D","WkZ-$_h!9t","r8=VLnUU+A","snCvaN*8+n","C$_uHugm9P",
	"eRjjf3$3M%","tRg7T_^5rW","w3+P9NeNxp","rWtRfY@W5C","j?4v*J)MsC","ZNB47fnsdf","HCs2*5#$^_"
};
const unsigned short salts = sizeof(salt) / sizeof(salt[0]);  // Calculates length of salt[]

//Local declarations
bool checkAuth(std::string token);
bool checkNetwork(std::string NET);
std::string giveSalt();
bool checkSalt(std::string);

//USER/CHECK FUNCTIONS
/*-----------------------------------------------------------------------------------------------*/
bool bapi::user::chk::checkUser(std::string token, short key, std::string username, std::string net) {
	//INCOMPLETE
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

std::string bapi::user::chk::authLogin(std::string token, short key, std::string username, std::string password) {
	//INCOMPLETE
	//return "-1";
	return giveSalt();
}

bool bapi::user::chk::logout(std::string token, std::string bid, JSON data) {
	//INCOMPLETE
	return false;
}


//USER/GET/ATTRIBUTES Functions
/*-----------------------------------------------------------------------------------------------*/
std::string bapi::user::get::atr::getUsers(std::string token, std::string session_code, char usertype) {
	//INCOMPLETE
	return "0";
}

std::string bapi::user::get::atr::getUser(std::string token, std::string session_code, std::string BID_requestBy, std::string BID_requestOn) {
	//INCOMPLETE
	return "0";
}

std::string bapi::user::get::atr::getUser(std::string token, std::string session_code, std::string bid) {
	//INCOMPLETE
	if (checkAuth(token) && checkSalt(session_code))
		return "0";
	else return "-1";
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
bool checkAuth(std::string token) { // COMPLETE
	const std::string authentication_key = "Cmh3gdcQx&XZVbDQFQgcoen>9&kXUQ69u*(m7D#LWqx&uh6%CQ=4hb$LG";
	if (token == authentication_key)
		return true;
	return false;
}

bool checkNetwork(std::string NET) { // INCOMPLETE
	return false;
}

std::string giveSalt() { // COMPLETE
	srand((unsigned)time(0));
	return salt[(rand() % salts) + 1];
}

bool checkSalt(std::string code) { // COMPLETE
	for (int i = 0; i < salts; ++i){
		if (salt[i] == code) {
			return true;
		}
	}
	return false;
}