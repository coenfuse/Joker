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
bool bapi::user::chk::user(std::string token, short key, std::string username, std::string net) {
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

bool bapi::user::chk::logout(std::string token, std::string session_code, std::string bid, std::string data) {
	//INCOMPLETE
	return false;
}


//USER/GET/ATTRIBUTES Functions
/*-----------------------------------------------------------------------------------------------*/
std::string bapi::user::get::attr::users(std::string token, std::string session_code, short usertype) {
	//INCOMPLETE
	std::string prefix[] = {"#BLK_ADM","#BLK_STU","#BLK_EMP","#BLK_SUP","#BLK_MOD","#BLK_GUE"};
	return prefix[0] + "0";
}

std::string bapi::user::get::attr::user(std::string token, std::string session_code, std::string BID_requestedBy, std::string BID_requested) {
	//INCOMPLETE
	std::string prefix[] = {"#USR_ATTR_ADM","#USR_ATTR_STU","#USR_ATTR_EMP","#USR_ATTR_SUP","#USR_ATTR_MOD","#USR_ATTR_GUE"};
	return prefix[0] + "0";
}

std::string bapi::user::get::attr::user(std::string token, std::string session_code, std::string bid) {
	//INCOMPLETE
	if (checkAuth(token) && checkSalt(session_code))
		return "0";
	else return "-1";
}


//USER/UPDATE/ATTRIBUTES Functions
/*-----------------------------------------------------------------------------------------------*/
bool bapi::user::up::attr::users(std::string token, std::string session_code, std::string bid, short action) {	//Consider removal.
	//INCOMPLETE
	return false;
}

bool bapi::user::up::attr::user(std::string token, std::string session_code, std::string bid, std::string data) {
	//INCOMPLETE
	return false;
}


//USER/POST/ATTRIBUTES Functions
/*-----------------------------------------------------------------------------------------------*/
bool bapi::user::post::attr::users(std::string token, std::string session_code, std::string BID_requestBy, short action, std::string data) {	//Consider removal
	//INCOMPLETE
	return false;
}

bool bapi::user::post::attr::user(std::string token, std::string session_code, std::string BID_requestBy, short action, std::string data) {
	//INCOMPLETE
	return false;
}


//USER/POP/ATTRIBUTES Functions
/*-----------------------------------------------------------------------------------------------*/
bool bapi::user::pop::attr::user(std::string token, std::string session_code, std::string BID_requestBy, std::string BID_requestOn, short action) {
	//INCOMPLETE
	return false;
}

//NETWORK/CHECK Functions
/*-----------------------------------------------------------------------------------------------*/
bool bapi::net::chk::net(std::string token, std::string NET){ //INCOMPLETE
	return true;
}

bool bapi::net::chk::user(std::string token, short key, std::string NET, std::string BID) { //INCOMPLETE
	return true;
}

bool bapi::net::chk::owner(std::string token, std::string NET, std::string BID){ //INCOMPLETE
	return true;
}

bool bapi::net::chk::active(std::string token, std::string NET){ //INCOMPLETE
	return true;
}

//NETWORK/GET Functions
/*-----------------------------------------------------------------------------------------------*/
std::string bapi::net::get::net(std::string token, std::string session_code, std::string NET, std::string BID){ //INCOMPLETE
	std::string prefix = "#NET";
	return prefix + "0";
}

std::string bapi::net::get::stats(std::string token, std::string session_code, std::string NET, std::string BID){ //INCOMPLETE
	std::string prefix = "#NET_STAT";
	return prefix + "0";
}

std::string bapi::net::get::admins(std::string token, std::string session_code, std::string NET, std::string BID){ // INCOMPLETE
	std::string prefix = "#NET_ADMS";
	return prefix + "0";
}

std::string bapi::net::get::owner(std::string token, std::string session_code, std::string NET, std::string BID){ // INCOMPLETE
	std::string prefix = "#NET_OWN";
	return prefix + "0";
}

std::string bapi::net::get::stands(std::string token, std::string session_code, std::string NET, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_STDS";
	return prefix + "0";
}

std::string bapi::net::get::stand(std::string token, std::string session_code, std::string NET, std::string STD, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_STD";
	return prefix + "0";
}

std::string bapi::net::get::standStats(std::string token, std::string session_code, std::string NET, std::string STD, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_STD_STAT";
	return prefix + "0";
}

std::string bapi::net::get::nearestStand(std::string token, std::string session_code, std::string NET, std::string LOC, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_NEAR_STD";
	return prefix + "0";
}

int bapi::net::get::standDistance(std::string token, std::string session_code, std::string NET, std::string STD1, std::string STD2, std::string BID) { // INCOMPLETE
	return 100;
}

std::string bapi::net::get::cycles(std::string token, std::string session_code, std::string NET, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_CYCS";
	return prefix + "0";
}

std::string bapi::net::get::cycle(std::string token, std::string session_code, std::string NET, std::string CYC) { // INCOMPLETE
	std::string prefix = "#NET_CYC";
	return prefix + "0";
}

std::string bapi::net::get::freeCycles(std::string token, std::string session_code, std::string NET, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_FREE_CYC";
	return prefix + "0";
}

std::string bapi::net::get::locks(std::string token, std::string session_code, std::string NET, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_LCKS";
	return prefix + "0";
}

std::string bapi::net::get::lock(std::string token, std::string session_code, std::string NET, std::string LCK, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_LCK";
	return prefix + "0";
}

std::string bapi::net::get::allTXN(std::string token, std::string session_code, std::string NET, std::string BID_requester){
	std::string prefix = "#NET_TXNS";
	return prefix + "0";
}

std::string bapi::net::get::userTXN(std::string token, std::string session_code, std::string NET, std::string BID_requester, std::string BID_requested){
	std::string prefix = "#NET_USR_TXN";
	return prefix + "0";
}

std::string bapi::net::get::stdTXN(std::string token, std::string session_code, std::string NET, std::string STD, std::string BID_requester){
	std::string prefix = "#NET_STD_TXN";
	return prefix + "0";
}

std::string bapi::net::get::cycTXN(std::string token, std::string session_code, std::string NET, std::string CYC, std::string BID_requester){
	std::string prefix = "#NET_CYC_TXN";
	return prefix + "0";
}

std::string bapi::net::get::TXN(std::string token, std::string session_code, std::string NET, std::string BID_requester, std::string TXN){
	std::string prefix = "#NET_TXN";
	return prefix + "0";
}

//NETWORK/UP Functions
/*-----------------------------------------------------------------------------------------------*/
bool bapi::net::up::net(std::string token, std::string session_code, std::string NET, std::string BID, short action, std::string data) { // INCOMPLETE
	return true;
}

bool bapi::net::up::stands(std::string token, std::string session_code, std::string NET, std::string BID, short action, std::string data) { // INCOMPLETE
	return true;
}

bool bapi::net::up::stand(std::string token, std::string session_code, std::string NET, std::string BID, short action, std::string STD, std::string data) { // INCOMPLETE
	return true;
}

bool bapi::net::up::cycles(std::string token, std::string session_code, std::string NET, std::string BID, short action, std::string data) { // INCOMPLETE
	return true;
}

bool bapi::net::up::cycle(std::string token, std::string session_code, std::string NET, std::string BID, short action, std::string CYC, std::string data) { // INCOMPLETE
	return true;
}

bool bapi::net::up::locks(std::string token, std::string session_code, std::string NET, std::string BID, short action, std::string data) { // INCOMPLETE
	return true;
}

bool bapi::net::up::lock(std::string token, std::string session_code, std::string NET, std::string BID, short action, std::string LCK, std::string data) { // INCOMPLETE
	return true;
}

//NETWORK/POST Functions
/*-----------------------------------------------------------------------------------------------*/
bool bapi::net::post::net(std::string token, std::string session_code, std::string BID, std::string data) { //INCOMPLETE
	return true;
}

bool bapi::net::post::stand(std::string token, std::string session_code, std::string BID, std::string NET, std::string data){ //INCOMPLETE
	return true;
}

bool bapi::net::post::cycle(std::string token, std::string session_code, std::string BID, std::string NET, std::string data) { //INCOMPLETE
	return true;
}

bool bapi::net::post::lock(std::string token, std::string session_code, std::string BID, std::string NET, std::string STD, std::string data) { //INCOMPLETE
	return true;
}

//NETWORK/POP Functions
/*-----------------------------------------------------------------------------------------------*/
bool bapi::net::pop::net(std::string token, std::string session_code, std::string BID, std::string NET) { // INCOMPLETE
	return true;
}

bool bapi::net::pop::stand(std::string token, std::string session_code, std::string BID, std::string NET, std::string STD) { // INCOMPLETE
	return true;
}

bool bapi::net::pop::cycle(std::string token, std::string session_code, std::string BID, std::string NET, std::string CYC) { // INCOMPLETE
	return true;
}

bool bapi::net::pop::lock(std::string token, std::string session_code, std::string BID, std::string NET, std::string STD, std::string LCK) { // INCOMPLETE
	return true;
}

//-----------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------

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
