#include <bapi.h>
#include <string>
#include <stdlib.h>
#include <ctime>
#include "..\src\middle\token.h"

//Local variables
/*-----------------------------------------------------------------------------------------------*/
Token token;

//Local declarations
/*-----------------------------------------------------------------------------------------------*/
bool checkNetwork(std::string NET);

//USER/CHECK FUNCTIONS
/*-----------------------------------------------------------------------------------------------*/
bool bapi::user::chk::user(std::string access_code, short key, std::string username, std::string net) {
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
	if (token.checkAccess(access_code)) {
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

std::string bapi::user::chk::authLogin(std::string access_code, short key, std::string username, std::string password) {
	//INCOMPLETE
	//return "-1";
	return token.giveSession();
}

bool bapi::user::chk::logout(std::string access_code, std::string session_code, std::string bid, std::string data) {
	//INCOMPLETE
	return false;
}


//USER/GET/ATTRIBUTES Functions
/*-----------------------------------------------------------------------------------------------*/
std::string bapi::user::get::attr::users(std::string access_code, std::string session_code, short usertype) {
	//INCOMPLETE
	std::string prefix[] = {"#BLK_ADM","#BLK_STU","#BLK_EMP","#BLK_SUP","#BLK_MOD","#BLK_GUE"};
	return prefix[0] + "0";
}

std::string bapi::user::get::attr::user(std::string access_code, std::string session_code, std::string BID_requestedBy, std::string BID_requested) {
	//INCOMPLETE
	std::string prefix[] = {"#USR_ATTR_ADM","#USR_ATTR_STU","#USR_ATTR_EMP","#USR_ATTR_SUP","#USR_ATTR_MOD","#USR_ATTR_GUE"};
	return prefix[0] + "0";
}

std::string bapi::user::get::attr::user(std::string access_code, std::string session_code, std::string bid) {
	//INCOMPLETE
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return "0";
	else return "-1";
}


//USER/UPDATE/ATTRIBUTES Functions
/*-----------------------------------------------------------------------------------------------*/
bool bapi::user::up::attr::users(std::string access_code, std::string session_code, std::string bid, short action) {	//Consider removal.
	//INCOMPLETE
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::user::up::attr::user(std::string access_code, std::string session_code, std::string bid, std::string data) {
	//INCOMPLETE
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}


//USER/POST/ATTRIBUTES Functions
/*-----------------------------------------------------------------------------------------------*/
bool bapi::user::post::attr::users(std::string access_code, std::string session_code, std::string BID_requestBy, short action, std::string data) {	//Consider removal
	//INCOMPLETE
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::user::post::attr::user(std::string access_code, std::string session_code, std::string BID_requestBy, short action, std::string data) {
	//INCOMPLETE
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}


//USER/POP/ATTRIBUTES Functions
/*-----------------------------------------------------------------------------------------------*/
bool bapi::user::pop::attr::user(std::string access_code, std::string session_code, std::string BID_requestBy, std::string BID_requestOn, short action) {
	//INCOMPLETE
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

//NETWORK/CHECK Functions
/*-----------------------------------------------------------------------------------------------*/
bool bapi::net::chk::net(std::string access_code, std::string NET){ //INCOMPLETE
	if (token.checkAccess(access_code))
		return false;
	else return true;
}

bool bapi::net::chk::user(std::string access_code, short key, std::string NET, std::string BID) { //INCOMPLETE
	if (token.checkAccess(access_code))
		return false;
	else return true;
}

bool bapi::net::chk::owner(std::string access_code, std::string NET, std::string BID){ //INCOMPLETE
	if (token.checkAccess(access_code))
		return false;
	else return true;
}

bool bapi::net::chk::active(std::string access_code, std::string NET){ //INCOMPLETE
	if (token.checkAccess(access_code))
		return false;
	else return true;
}

//NETWORK/GET Functions
/*-----------------------------------------------------------------------------------------------*/
std::string bapi::net::get::net(std::string access_code, std::string session_code, std::string NET, std::string BID){ //INCOMPLETE
	std::string prefix = "#NET";
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::stats(std::string access_code, std::string session_code, std::string NET, std::string BID){ //INCOMPLETE
	std::string prefix = "#NET_STAT";
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::admins(std::string access_code, std::string session_code, std::string NET, std::string BID){ // INCOMPLETE
	std::string prefix = "#NET_ADMS";
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::owner(std::string access_code, std::string session_code, std::string NET, std::string BID){ // INCOMPLETE
	std::string prefix = "#NET_OWN";
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::stands(std::string access_code, std::string session_code, std::string NET, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_STDS";
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::stand(std::string access_code, std::string session_code, std::string NET, std::string STD, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_STD";
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::standStats(std::string access_code, std::string session_code, std::string NET, std::string STD, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_STD_STAT";
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::nearestStand(std::string access_code, std::string session_code, std::string NET, std::string LOC, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_NEAR_STD";
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

int bapi::net::get::standDistance(std::string access_code, std::string session_code, std::string NET, std::string STD1, std::string STD2, std::string BID) { // INCOMPLETE
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return 100;
	else return 100;
}

std::string bapi::net::get::cycles(std::string access_code, std::string session_code, std::string NET, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_CYCS";
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::cycle(std::string access_code, std::string session_code, std::string NET, std::string CYC) { // INCOMPLETE
	std::string prefix = "#NET_CYC";
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::freeCycles(std::string access_code, std::string session_code, std::string NET, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_FREE_CYC";
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::locks(std::string access_code, std::string session_code, std::string NET, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_LCKS";
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::lock(std::string access_code, std::string session_code, std::string NET, std::string LCK, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_LCK";
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::allTXN(std::string access_code, std::string session_code, std::string NET, std::string BID_requester){
	std::string prefix = "#NET_TXNS";
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::userTXN(std::string access_code, std::string session_code, std::string NET, std::string BID_requester, std::string BID_requested){
	std::string prefix = "#NET_USR_TXN";
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::stdTXN(std::string access_code, std::string session_code, std::string NET, std::string STD, std::string BID_requester){
	std::string prefix = "#NET_STD_TXN";
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::cycTXN(std::string access_code, std::string session_code, std::string NET, std::string CYC, std::string BID_requester){
	std::string prefix = "#NET_CYC_TXN";
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::TXN(std::string access_code, std::string session_code, std::string NET, std::string BID_requester, std::string TXN){
	std::string prefix = "#NET_TXN";
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

//NETWORK/UP Functions
/*-----------------------------------------------------------------------------------------------*/
bool bapi::net::up::net(std::string access_code, std::string session_code, std::string NET, std::string BID, short action, std::string data) { // INCOMPLETE
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::up::stands(std::string access_code, std::string session_code, std::string NET, std::string BID, short action, std::string data) { // INCOMPLETE
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::up::stand(std::string access_code, std::string session_code, std::string NET, std::string BID, short action, std::string STD, std::string data) { // INCOMPLETE
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::up::cycles(std::string access_code, std::string session_code, std::string NET, std::string BID, short action, std::string data) { // INCOMPLETE
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::up::cycle(std::string access_code, std::string session_code, std::string NET, std::string BID, short action, std::string CYC, std::string data) { // INCOMPLETE
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::up::locks(std::string access_code, std::string session_code, std::string NET, std::string BID, short action, std::string data) { // INCOMPLETE
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::up::lock(std::string access_code, std::string session_code, std::string NET, std::string BID, short action, std::string LCK, std::string data) { // INCOMPLETE
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

//NETWORK/POST Functions
/*-----------------------------------------------------------------------------------------------*/
bool bapi::net::post::net(std::string access_code, std::string session_code, std::string BID, std::string data) { //INCOMPLETE
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::post::stand(std::string access_code, std::string session_code, std::string BID, std::string NET, std::string data){ //INCOMPLETE
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::post::cycle(std::string access_code, std::string session_code, std::string BID, std::string NET, std::string data) { //INCOMPLETE
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::post::lock(std::string access_code, std::string session_code, std::string BID, std::string NET, std::string STD, std::string data) { //INCOMPLETE
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

//NETWORK/POP Functions
/*-----------------------------------------------------------------------------------------------*/
bool bapi::net::pop::net(std::string access_code, std::string session_code, std::string BID, std::string NET) { // INCOMPLETE
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::pop::stand(std::string access_code, std::string session_code, std::string BID, std::string NET, std::string STD) { // INCOMPLETE
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::pop::cycle(std::string access_code, std::string session_code, std::string BID, std::string NET, std::string CYC) { // INCOMPLETE
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::pop::lock(std::string access_code, std::string session_code, std::string BID, std::string NET, std::string STD, std::string LCK) { // INCOMPLETE
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

//-----------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------

//Local Definitions

bool checkNetwork(std::string NET) { // INCOMPLETE
	return false;
}