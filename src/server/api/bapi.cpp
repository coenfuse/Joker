#include <bapi.h>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <map>
#include <algorithm>
#include "..\src\server\core\token.h"

#define TEST	// Set this TEST to RELASE to unload the system from testing mode.

#ifdef TEST

#include "..\data\testing\test_data.h"

// Local Declarations

bool does_user_exist(std::string username, std::string NET);
bool does_network_exist(std::string NET);
short user_type(std::string BID, std::string NET);

// Local Definitions

bool does_user_exist(std::string username, std::string NET){	
	
	std::vector<std::string> user_list = Joker_Users.at(NET);
	std::sort(user_list.begin(), user_list.end());

	return std::binary_search(user_list.begin(), user_list.end(), username);
}
bool does_network_exist(std::string NET) {
	
	std::vector<std::string> list_copy = network_list;
	std::sort(list_copy.begin(), list_copy.begin());

	return std::binary_search(list_copy.begin(), list_copy.end(), NET);
}
short user_type(std::string BID, std::string NET) {
	
	using namespace BAPI;

	std::string DATA = (Joker_DB.at(NET)).at(BID);
	if ( DATA.find("TYPE:'ADM'") != -1 )
		return ADM;
	else if ( DATA.find("TYPE:'SUP'") != -1 )
		return SUP;
	else if ( DATA.find("TYPE:'MOD'") != -1 )
		return MOD;
	else if ( DATA.find("TYPE:'STU'") != -1 )
		return STU;
	else if ( DATA.find("TYPE:'EMP'") != -1 )
		return EMP;
	else return GUE;
}

// BAPI::USER

bool BAPI::USER::is_present(
	std::string access_code,
	std::string NET,
	std::string username,
	short usertype
){
	//COMPLETE
	
	// Returning Convention: 0 or 1

	if (token.checkAccess(access_code)) {
		switch (usertype)
		{
		case ADM: {	// Invoked if the usertype is ADMIN
			return (does_user_exist(username, NET));
		}
			  break;
		case SUP: {	// Invoked if the usertype is SUPPORT
			// INCOMPLETE
		}
			  break;
		case MOD: {	// Invoked if the usertype is MODERATOR
			// INCOMPLETE
		}
			  break;
		case STU: {	// Invoked if the usertype is STUDENT
			return (does_user_exist(username, NET));
		}
			  break;
		case EMP: {	// Invoked if the usertype is EMPLOYEE
		}
			  break;
		case GUE: {	// Invoked if the usertype is GUEST
		}
				break;
		}
	}
	return false;
}

std::string BAPI::USER::authorize_login(
	std::string access_code,
	std::string NET,
	std::string username,
	std::string salt,
	short usertype
){
	// COMPLETE

	/*
	* Return Convention:
	* Return "-1" if ACCESS_CODE is invalid
	* Return "1" if NET doesn't exist
	* Return "2" if USERNAME doesn't exist inside a NET
	* Return "3" if SALT is incorrect
	* otherwise Return "SESSION_CODE: 'xxxxxxxxxx', BID: 'xxxxxx'"
	*/

	if (token.checkAccess(access_code)) {
		if (does_network_exist(NET)){
			if (does_user_exist(username, NET)) {
				if (salt == "0000") {

					std::string BID = (BID_pairs.at(NET)).at(username);
					std::map<std::string, std::string> TEMP = Joker_DB.at(NET);
					std::string USER_DATA = (Joker_DB.at(NET)).at(BID);
					std::string KEY = "ONLINE:'", STATUS = "T", substr1, substr2;
					size_t start = 0, end = USER_DATA.find(KEY) + KEY.length();
					
					substr1 = USER_DATA.substr(start, end);
					
					start = substr1.length() + STATUS.length();
					end = USER_DATA.length() - start;
					substr2 = USER_DATA.substr(start, end);

					USER_DATA = substr1 + STATUS + substr2;
					TEMP[BID] = USER_DATA;
					Joker_DB[NET] = TEMP;

					// THIS FUNCTION IS WORKING BUT THE CHAGES MADE BY IT AREN"T GETTING REFLECTED GLOBALLY.
					// MAYBE BECAUSE WE ARE NOT MAKING THE CORRECT USE OF POINTERS.

					return "SESSION_CODE: '" + token.giveSession() + "', BID: '" + BID + "'";
				}
				return "3";
			}
			return "2";
		}
		return "1";
	}
	return "-1";
}

bool BAPI::USER::logout(
	std::string access_code,
	std::string session_code,
	std::string BID,
	std::string NET,
	std::string user_data
) {
	// INCOMPLETE
	// Returning Convention: 

	if (token.checkAccess(access_code) && token.checkSession(session_code)) {
		//The following line causes error C2675 and C2100. Use pointers or a propietary data handler.
		//(Joker_DB.at(NET)).insert(BID, user_data);
		// The above line also has an invalid syntax. Instead
		(Joker_DB.at(NET))[NET] = (BID, user_data);
		
		// What the above line does is, it takes the Joker_DB map. Makes a copy of it in the scope function.
		// Adds new data to it (causing memory problems) and then just deletes it when function goes out of scope.
		// Without making changes to the original file.
		return true;
	}
	return false;
}

std::string BAPI::USER::get_all(
	std::string access_code,
	std::string session_code,
	std::string NET,
	std::string BID_requested_by,
	short usertype
) {
	//INCOMPLETE

	/*
	* Return Convention:
	* 
	* Return "-1" if ACCESS_CODE or SESSION_CODE is invalid.
	* Return "0" if NET doesn't exist
	* Return "1" if unauthorized access is done to this function (Currently, only ADMIN can access this)
	* otherwise if usertype is (1), ADMIN
	*				Return: "#BLK_ADM, count, 0:(BIDxxxxxxxxxx,Name,AID), 1:(BIDxxxxxxxxxx,Name,AID), ... n:(BIDxxxxxxxxxx,Name,AID)"
	* 
	*			if usertype is (2), SUPPORT
	*				Return: "#BLK_SUP, count, 0:(BIDxxxxxxxxxx,Name,SUP), 1:(BIDxxxxxxxxxx,Name,SUP), ... n:(BIDxxxxxxxxxx,Name,SUP)"
	* 
	*			if usertype is (3), MODERATOR
	*				Return: "#BLK_MOD, count, 0:(BIDxxxxxxxxxx,Name,MOD), 1:(BIDxxxxxxxxxx,Name,MOD), ... n:(BIDxxxxxxxxxx,Name,MOD)"
	* 
	*			if usertype is (4), STUDENT
	*				Return: "#BLK_STU, count, 0:(BIDxxxxxxxxxx,Name,SID), 1:(BIDxxxxxxxxxx,Name,SID), ... n:(BIDxxxxxxxxxx,Name,SID)"
	* 
	*			if usertype is (5), EMPLOYEE
	*				Return: "#BLK_EMP, count, 0:(BIDxxxxxxxxxx,Name,EID), 1:(BIDxxxxxxxxxx,Name,EID), ... n:(BIDxxxxxxxxxx,Name,EID)"
	* 
	*			if usertype is (6), GUEST
	*				Return: "#BLK_GUE, count, 0:(BGIDxxxxxxxxxx,Name,Duration), 1:(BGIDxxxxxxxxxx,Name,Duration), ... n:(BGIDxxxxxxxxxx,Name,Duration)"
	*/

	using namespace BAPI;

	const std::string prefix[] = { 
		"#BLK_ADM, ",
		"#BLK_SUP, ",
		"#BLK_MOD, ",
		"#BLK_STU, ",
		"#BLK_EMP, ",
		"#BLK_GUE, "
	};

	std::string pass_data = "NULL", BID, NAME, ID, TEMP;
	size_t start, end;
	std::map<std::string, std::string> network;

	if (token.checkAccess(access_code) && token.checkSession(session_code)) {
		if (does_network_exist(NET)) {
			if (user_type(BID_requested_by, NET) == ADM)
			{
				network = Joker_DB.at(NET);
				switch (usertype)
				{
				case ADM: {
					std::map<std::string, std::string>::iterator index = network.begin();
					int count = 0;
					for (; count < 6; ++count, ++index) {
						TEMP = index->second;

						start = TEMP.find("BID:'") + 5;
						end = TEMP.find("', AID:");
						BID = TEMP.substr(start, end - start);

						start = TEMP.find("NAME:'") + 6;
						end = TEMP.find("', GUARDIAN:");
						NAME = TEMP.substr(start, end - start);

						start = TEMP.find("AID:'") + 5;
						end = TEMP.find("', NET:");
						ID = TEMP.substr(start, end - start);

						pass_data = pass_data + std::to_string(count) + ":(" + BID + "," + NAME + "," + ID + "), ";
					}
					return prefix[usertype] + std::to_string(count) + pass_data.substr(0, pass_data.length() - 2);
				}
					  break;

				case SUP: {
					return prefix[usertype];
				}
					  break;

				case MOD: {
					return prefix[usertype];
				}
					  break;

				case STU: {
					std::map<std::string, std::string>::iterator index = network.find("BID007");	// This is hack
					int count = 0;
					for (count; index != network.end(); count++, ++index) {
						TEMP = index->second;

						start = TEMP.find("BID:'") + 5;
						end = TEMP.find("', SID:");
						BID = TEMP.substr(start, end - start);

						start = TEMP.find("NAME:'") + 6;
						end = TEMP.find("', GUARDIAN");
						NAME = TEMP.substr(start, end - start);

						start = TEMP.find("SID:'") + 5;
						end = TEMP.find("', NET:");
						ID = TEMP.substr(start, end - start);

						pass_data = pass_data + std::to_string(count) + ":(" + BID + "," + NAME + "," + ID + "), ";
					}
					return prefix[usertype] + std::to_string(count) + pass_data.substr(0, pass_data.length() - 2);
				} 
					  break;

				case EMP: {
					return prefix[usertype];
				}
					  break;

				case GUE: {
					return prefix[usertype];
				}
					  break;
				}
			}
			else return "1";
		}
		else return "0";
	}
	else return "-1";
}

std::string BAPI::USER::get(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET,
	std::string BID_requested
) {
	//INCOMPLETE

	/*
	* Return Convention:
	*
	* Return "-1" if ACCESS_CODE or SESSION_CODE is invalid.
	* Return "0" if NET doesn't exist
	* Return "1" if Access Hierarchy is violated. Heirarchy: ADM -> SUP -> MOD -> (STU <!> EMP <!> GUE)
	* otherwise if BID_requested is of type ADMIN
	*				Return: "#USR_ATTR_ADM, BID:'BIDxxxxxxxxxx', AID : 'xxxxxxxxxx', NET : 'NETxxxxxxxxxx', OWN : '0 or 1', NAME : 'xxxxxxxxxx', GUARDIAN : 'xxxxxxxxxx', GEN : 'F or M or O', DOB : '00/MON/0000', ACT_STAT : '0 or 1', PH1 : 'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', PH2 : 'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', EM1 : 'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', EM2 : 'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', ADD1 : 'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), AREA:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ADD2 == ADD1 : '0', ADD2 : 'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), LOC:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ONLINE : '0 or 1', ACC_STAT : 'xxxxxxxxxx'"
	*
	*			if BID_requested is of type SUPPORT
	*	to-do ->	Return: "#USR_ATTR_SUP, BID:'BIDxxxxxxxxxx', SUP:'xxxxxxxxxx', NET:'NETxxxxxxxxxx', OWN:'0 or 1', NAME:'xxxxxxxxxx', GUARDIAN:'xxxxxxxxxx', GEN : 'F or M or O', DOB:'00/MON/0000', ACT_STAT:'0 or 1', PH1:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', PH2:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', EM1:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', EM2:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', ADD1:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), AREA:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ADD2==ADD1:'1', ADD2:'NULL', ONLINE:'0 or 1', ACC_STAT:'xxxxxxxxxx'"
	*
	*			if BID_requested is of type MODERATOR
	*	to-do ->	Return: "#USR_ATTR_MOD, BID:'BIDxxxxxxxxxx', MOD:'xxxxxxxxxx', NET:'NETxxxxxxxxxx', OWN:'0 or 1', NAME:'xxxxxxxxxx', GUARDIAN:'xxxxxxxxxx', GEN : 'F or M or O', DOB:'00/MON/0000', ACT_STAT:'0 or 1', PH1:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', PH2:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', EM1:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', EM2:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', ADD1:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), AREA:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ADD2==ADD1:'1', ADD2:'NULL', ONLINE:'0 or 1', ACC_STAT:'xxxxxxxxxx'"
	*
	*			if BID_requested is of type STUDENT
	*				Return: "#USR_ATTR_STU, BID:'BIDxxxxxxxxxx', SID:'xxxxxxxxxx', NET:'NETxxxxxxxxxx', PEN:'0 or 1', NAME:'xxxxxxxxxx', GUARDIAN:'xxxxxxxxxx', GEN : 'F or M or O', DOB:'00/MON/0000', ACT_STAT:'0 or 1', PH1:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', PH2:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', EM1:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', EM2:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', ADD1:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), AREA:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ADD2==ADD1:'0', ADD2:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), LOC:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ONLINE:'0 or 1', ACC_STAT:'xxxxxxxxxx', DEPT:'xxxxxxxxxx', LOGCOUNT:'xxxxxxxxx'"
	*
	*			if BID_requested is of type EMPLOYEE
	*				Return: "#USR_ATTR_EMP, BID:'BIDxxxxxxxxxx', EID:'xxxxxxxxxx', NET:'NETxxxxxxxxxx', OWN:'0 or 1', NAME:'xxxxxxxxxx', GUARDIAN:'xxxxxxxxxx', GEN : 'F or M or O', SPOUSE:'xxxxxxxxxx', DOB:'00/MON/0000', ACT_STAT:'0 or 1', PH1:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', PH2:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', EM1:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', EM2:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', ADD1:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), AREA:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ADD2==ADD1:'1', ADD2:'NULL', ONLINE:'0 or 1', ACC_STAT:'xxxxxxxxxx', DEPT:'xxxxxxxxxx', LOGCOUNT:'xxxxxxxxx'"
	*
	*			if BID_requested is of type GUEST
	*	to-do ->	Return: "#USR_ATTR_GUE, GID:'BGIDxxxxxxxxxx', Name:'xxxxxxxxxx', START:'00:00,00/00/00', END:'00:00,00/MON/0000', DUR:'00:00:00', IP:'000:000:000'"
	*/

	using namespace BAPI;

	std::string prefix[] = { 
		"#USR_ATTR_ADM, ",
		"#USR_ATTR_SUP, ",
		"#USR_ATTR_MOD, ",
		"#USR_ATTR_STU, ",
		"#USR_ATTR_EMP, ",
		"#USR_ATTR_GUE, "
	};
	std::string pass_data = "NULL";

	if (token.checkAccess(access_code) && token.checkSession(session_code)){
		if (does_network_exist(NET)) {
			const short requester = user_type(BID_requested_by, NET);
			const short requested = user_type(BID_requested, NET);

			switch (requester)
			{
			case ADM: {
				pass_data = (Joker_DB.at(NET)).at(BID_requested);
				return prefix[requested] + pass_data;
			}
				  break;

			case SUP: {
				if (requested != ADM) {
					pass_data = (Joker_DB.at(NET)).at(BID_requested);
					return prefix[requested] + pass_data;
				}
				return "1";
			}
				  break;

			case MOD: {
				if (requested != ADM && requested != SUP) {
					return prefix[requested] + pass_data;
				}
				return "1";
			}
				  break;

			case STU: {
				if (requested == STU && BID_requested_by == BID_requested) {
					pass_data = (Joker_DB.at(NET)).at(BID_requested);
					return prefix[requested] + pass_data;
				}
				return "1";
			}
				  break;

			case EMP: {
				if (requested == EMP && BID_requested_by == BID_requested) {
					pass_data = (Joker_DB.at(NET)).at(BID_requested);
					return prefix[requested] + pass_data;
				}
				return "1";
			}
				  break;

			case GUE: {
				if (requested == STU && BID_requested_by == BID_requested) {
					pass_data = (Joker_DB.at(NET)).at(BID_requested);
					return prefix[requested] + pass_data;
				}
				return "1";
			}
				  break;
			}
		}
		return "0";
	}
	return "-1";
}

std::string BAPI::USER::update_all(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET,
	short action
) {	
	// COMPLETE. //Consider removal.
	/*
	* Return Convention:
	* Return "-1" if ACCESS_CODE or SESSION_CODE is invalid.
	* Return "0" on normal execution.
	* Return "1" if NET doesn't exist
	* Return "2" if Access Hierarchy is violated. Heirarchy: ADM -> SUP -> MOD -> (STU <!> EMP <!> GUE)
	* Return "3" if attribute key is not found in the database.
	* 
	* Actions:
	* ACTIVATE = 0
	* DEACTIVATE = 1
	* ENABLE = 2
	* DISABLE = 3
	* MONITOR = 4
	* BLOCK = 5
	*/ 
	
	using namespace BAPI::USER_ACT;

	if (token.checkAccess(access_code) && token.checkSession(session_code)) {
		if (does_network_exist(NET)) {
			const short requester = user_type(BID_requested_by, NET);
			if (user_type(BID_requested_by, NET) == ADM){
				switch (action)
				{
				case ACTIVATE: {
					const std::string REPLACE_FROM = "IS_ACTIVE:'", TO_INSERT = "T";

					std::map<std::string, std::string> USER_DATA = Joker_DB.at(NET);
					std::map<std::string, std::string>::iterator itr;
					std::string TEMP_DATA, NEW_DATA, FIRST_HALF, SECOND_HALF;
					for (itr = USER_DATA.begin() ; itr != USER_DATA.end() ; ++itr) {
						size_t start = 0, end = 0;
						
						TEMP_DATA = itr->second;
						if (TEMP_DATA.find(REPLACE_FROM) != -1)
						{
							end = TEMP_DATA.find(REPLACE_FROM) + REPLACE_FROM.length();
							FIRST_HALF = TEMP_DATA.substr(start, end);

							start = end + TO_INSERT.length();
							end = TEMP_DATA.length() - start;
							SECOND_HALF = TEMP_DATA.substr(start, end);

							NEW_DATA = FIRST_HALF + TO_INSERT + SECOND_HALF;
							USER_DATA[itr->first] = NEW_DATA;
						}
						else return "3";
					}
					Joker_DB[NET] = USER_DATA;
				}
						break;
				case DEACTIVATE: {
					const std::string REPLACE_FROM = "IS_ACTIVE:'", TO_INSERT = "F";

					std::map<std::string, std::string> USER_DATA = Joker_DB.at(NET);
					std::map<std::string, std::string>::iterator itr;
					std::string TEMP_DATA, NEW_DATA, FIRST_HALF, SECOND_HALF;
					for (itr = USER_DATA.begin(); itr != USER_DATA.end(); ++itr) {
						size_t start = 0, end = 0;

						TEMP_DATA = itr->second;
						if (TEMP_DATA.find(REPLACE_FROM) != -1)
						{
							end = TEMP_DATA.find(REPLACE_FROM) + REPLACE_FROM.length();
							FIRST_HALF = TEMP_DATA.substr(start, end);

							start = end + TO_INSERT.length();
							end = TEMP_DATA.length() - start;
							SECOND_HALF = TEMP_DATA.substr(start, end);

							NEW_DATA = FIRST_HALF + TO_INSERT + SECOND_HALF;
							USER_DATA[itr->first] = NEW_DATA;
						}
						else return "3";
					}
					Joker_DB[NET] = USER_DATA;
				}
						break;
				case ENABLE: {
					const std::string REPLACE_FROM = "ACCOUNT_STAT:'", TO_INSERT = "0";

					std::map<std::string, std::string> USER_DATA = Joker_DB.at(NET);
					std::map<std::string, std::string>::iterator itr;
					std::string TEMP_DATA, NEW_DATA, FIRST_HALF, SECOND_HALF;
					for (itr = USER_DATA.begin(); itr != USER_DATA.end(); ++itr) {
						size_t start = 0, end = 0;

						TEMP_DATA = itr->second;
						if (TEMP_DATA.find(REPLACE_FROM) != -1)
						{
							end = TEMP_DATA.find(REPLACE_FROM) + REPLACE_FROM.length();
							FIRST_HALF = TEMP_DATA.substr(start, end);

							start = end + TO_INSERT.length();
							end = TEMP_DATA.length() - start;
							SECOND_HALF = TEMP_DATA.substr(start, end);

							NEW_DATA = FIRST_HALF + TO_INSERT + SECOND_HALF;
							USER_DATA[itr->first] = NEW_DATA;
						}
						else return "3";
					}
					Joker_DB[NET] = USER_DATA;
				}
						break;
				case DISABLE: {
					const std::string REPLACE_FROM = "ACCOUNT_STAT:'", TO_INSERT = "1";

					std::map<std::string, std::string> USER_DATA = Joker_DB.at(NET);
					std::map<std::string, std::string>::iterator itr;
					std::string TEMP_DATA, NEW_DATA, FIRST_HALF, SECOND_HALF;
					for (itr = USER_DATA.begin(); itr != USER_DATA.end(); ++itr) {
						size_t start = 0, end = 0;

						TEMP_DATA = itr->second;
						if (TEMP_DATA.find(REPLACE_FROM) != -1)
						{
							end = TEMP_DATA.find(REPLACE_FROM) + REPLACE_FROM.length();
							FIRST_HALF = TEMP_DATA.substr(start, end);

							start = end + TO_INSERT.length();
							end = TEMP_DATA.length() - start;
							SECOND_HALF = TEMP_DATA.substr(start, end);

							NEW_DATA = FIRST_HALF + TO_INSERT + SECOND_HALF;
							USER_DATA[itr->first] = NEW_DATA;
						}
						else return "3";
					}
					Joker_DB[NET] = USER_DATA;
				}
						break;
				case MONITOR: {
					const std::string REPLACE_FROM = "ACCOUNT_STAT:'", TO_INSERT = "2";

					std::map<std::string, std::string> USER_DATA = Joker_DB.at(NET);
					std::map<std::string, std::string>::iterator itr;
					std::string TEMP_DATA, NEW_DATA, FIRST_HALF, SECOND_HALF;
					for (itr = USER_DATA.begin(); itr != USER_DATA.end(); ++itr) {
						size_t start = 0, end = 0;

						TEMP_DATA = itr->second;
						if (TEMP_DATA.find(REPLACE_FROM) != -1)
						{
							end = TEMP_DATA.find(REPLACE_FROM) + REPLACE_FROM.length();
							FIRST_HALF = TEMP_DATA.substr(start, end);

							start = end + TO_INSERT.length();
							end = TEMP_DATA.length() - start;
							SECOND_HALF = TEMP_DATA.substr(start, end);

							NEW_DATA = FIRST_HALF + TO_INSERT + SECOND_HALF;
							USER_DATA[itr->first] = NEW_DATA;
						}
						else return "3";
					}
					Joker_DB[NET] = USER_DATA;
				}
						break;
				case BLOCK: {
					const std::string REPLACE_FROM = "ACCOUNT_STAT:'", TO_INSERT = "3";

					std::map<std::string, std::string> USER_DATA = Joker_DB.at(NET);
					std::map<std::string, std::string>::iterator itr;
					std::string TEMP_DATA, NEW_DATA, FIRST_HALF, SECOND_HALF;
					for (itr = USER_DATA.begin(); itr != USER_DATA.end(); ++itr) {
						size_t start = 0, end = 0;

						TEMP_DATA = itr->second;
						if (TEMP_DATA.find(REPLACE_FROM) != -1)
						{
							end = TEMP_DATA.find(REPLACE_FROM) + REPLACE_FROM.length();
							FIRST_HALF = TEMP_DATA.substr(start, end);

							start = end + TO_INSERT.length();
							end = TEMP_DATA.length() - start;
							SECOND_HALF = TEMP_DATA.substr(start, end);

							NEW_DATA = FIRST_HALF + TO_INSERT + SECOND_HALF;
							USER_DATA[itr->first] = NEW_DATA;
						}
						else return "3";
					}
					Joker_DB[NET] = USER_DATA;
				}
							break;
				}
				return "0";
			}
			else return "2";
		}
		else return "1";
	}
	else return "-1";
}

std::string BAPI::USER::update(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET,
	std::string BID,
	std::string user_data
) {
	// INCOMPLETE
	// Return Convention:
	if (token.checkAccess(access_code) && token.checkSession(session_code)) {
		if (does_network_exist(NET)) {
			//...
		}
		return "0";
	}
	return "-1";
}

std::string update(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET,
	std::string BID_to_be_updated
) {
	// INCOMPLETE
	// Return Convention
	return "INCOMPLETE";
}

std::string BAPI::USER::add_multiple(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET,
	std::string multiple_user_data,
	short action
) {	
	// INCOMPLETE. Consider Removal
	// Return Convention:

	if (token.checkAccess(access_code) && token.checkSession(session_code)) {
		if (does_network_exist(NET)) {
			//...
		}
		return "0";
	}
	return "-1";
}

std::string BAPI::USER::add(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET,
	std::string user_data,
	short action
) {
	//INCOMPLETE
	//In release phase, a proprietary BID generator will be used instead of using Session token generator.
	//Required, forumlation of passing conventions in the front end that would govern how data is passed into 'data' variable.
	//Return Convention:

	if (token.checkAccess(access_code) && token.checkSession(session_code)) {
		if (does_network_exist(NET)) {
			//...
		}
		return "0";
	}
	return "-1";
}

std::string BAPI::USER::remove(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET,
	std::string BID_to_remove,
	short action
) {
	//INCOMPLETE
	//This function currently deleted a key,pair value from the system. In the release mode, it should just disable it from accessing it.
	//Consider doing by making a string,struct pair where status of the account is fetched by the ACT_STAT attribute of a particular struct object.
	// Return Convention:

	if (token.checkAccess(access_code) && token.checkSession(session_code)) {
		if (does_network_exist(NET)) {
			(Joker_DB.at(NET)).erase((Joker_DB.at(NET)).find(BID_to_remove));
		}
		return "0";
	}
	return "-1";

		// How does above line works?
		/* Read it from the right:
		* We use the following syntax, map.erase(iterator);
		* Map is obtained by Joker_DB.at(NET) in the left hand side.
		* Iterator is obtained by map.find(key_val) where map = Joker_DB.at(NET) and key_val = BID_to_remove;
		* Joker_DB.at(NET).find(BID_to_remove) returns an iterator.
		* This iterator points at key 'BID_to_remove' that is present in map given by Joker_DB.at(NET)
		* Erase function expects an iterator as its parameter and we got this by the right part of the code.
		* Now in left side, Joker_DB.at(NET) returns a map, we add an erase function to it with iterator we already caluclated.
		* Thus, ( Joker_DB.at(NET) ).erase( Joker_DB.at(NET).find(BID_to_remove) )
		*/
}

// BAPI::USER::MESSAGES
// BAPI::USER::NOTIFICATION
// BAPI::USER::TICKET
// BAPI::USER::FEEDBACK

// BAPI::NETWORK

bool BAPI::NETWORK::is_present(
	std::string access_code,
	std::string NET
) {
	// INCOMPLETE
	// Return Convention:

	if (token.checkAccess(access_code)) {
		for (net_list_itr = network_list.begin(); net_list_itr < network_list.end(); ++net_list_itr) {
			if (*net_list_itr == NET)
				return true;
		}
		return false;
	}
	return false;
}

bool BAPI::NETWORK::user_exist(
	std::string access_code,
	std::string NET,
	std::string BID_check,
	short usertype
) {
	// INCOMPLETE
	// Return Convetion:

	if (token.checkAccess(access_code))
		return true;
	else return false;
}

bool BAPI::NETWORK::is_owner(
	std::string access_code,
	std::string NET,
	std::string BID_check
) {
	// INCOMPLETE
	// Return Convention:

	if (token.checkAccess(access_code))
		return true;
	else return false;
}

bool BAPI::NETWORK::is_active(
	std::string access_code,
	std::string NET
) {
	// INCOMPLETE
	// Return Convention:

	if (token.checkAccess(access_code))
		return true;
	else return false;
}

std::string BAPI::NETWORK::get_all(
	std::string access_code
) {
	// INCOMPLETE
	// Return Convention:

	std::string prefix = "#NET";

	if (token.checkAccess(access_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string BAPI::NETWORK::get(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET
) {
	// INCOMPLETE
	// Return Convetion:

	std::string prefix = "#NET";

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string BAPI::NETWORK::get_stats(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET
) {
	// INCOMPLETE
	// Return Convention:

	std::string prefix = "#NET_STAT";

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string BAPI::NETWORK::get_admins(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET
) {
	// INCOMPLETE
	// Return Convention:

	std::string prefix = "#NET_ADMS";

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string BAPI::NETWORK::get_owner(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET
) {
	// INCOMPLETE
	// Return Convention:

	std::string prefix = "#NET_OWN";

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string BAPI::NETWORK::update(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET,
	std::string network_data,
	short action
) {
	// INCOMPLETE
	// Return Convention:

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return "something";
	else return "something";
}

std::string BAPI::NETWORK::add(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string network_data
) {
	// INCOMPELTE
	// Return Convention:

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return "something";
	else return "something";
}

std::string BAPI::NETWORK::remove(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET
) {
	// INCOMPLETE
	// Return Convention:

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return "something";
	else return "something";
}

// BAPI::NETWORK::STAND

bool BAPI::NETWORK::STAND::is_stand_present(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET,
	std::string STD
) {
	// INCOMPLETE
	// Return Convention:

	return true;
}

std::string BAPI::NETWORK::STAND::get_all(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET
) {
	// INCOMPELTE
	// Return Convention:

	std::string prefix = "#NET_STDS";

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string BAPI::NETWORK::STAND::get(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET,
	std::string STD
) {
	// INCOMPLETE
	// Return Convention

	std::string prefix = "#NET_STD";

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string BAPI::NETWORK::STAND::get_stats(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET,
	std::string STD
) {
	// INCOMPLETE
	// Return Convention:

	std::string prefix = "#NET_STD_STAT";

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string BAPI::NETWORK::STAND::get_nearest(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET,
	std::string location
) {
	// INCOMPLETE
	// Return Convention:

	std::string prefix = "#NET_NEAR_STD";

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

int BAPI::NETWORK::STAND::get_distance(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET,
	std::string STD1,
	std::string STD2
) { 
	// INCOMPLETE
	// Return Convention:

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return 100;
	else return 100;
}

std::string BAPI::NETWORK::STAND::get_vacant(
	std::string access_code,
	std::string session_code,
	std::string NET
) {
	// INCOMPLETE
	// Return Convention:

	return "something";
}

std::string BAPI::NETWORK::STAND::update_all(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET,
	std::string multiple_stand_data,
	short action
) {
	// INCOMPLETE. Consider Removal
	// Return Convention:

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return "something";
	else return "something";
}

std::string BAPI::NETWORK::STAND::update(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET,
	std::string STD,
	std::string stand_data,
	short action
) {
	// INCOMPELTE
	// Return Convention:

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return "something";
	else return "something";
}

std::string BAPI::NETWORK::STAND::add(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET,
	std::string stand_data
) {
	// INCOMPLETE.
	// Return Convention:

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return "something";
	else return "something";
}

std::string BAPI::NETWORK::STAND::remove(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET,
	std::string STD
) {
	// INCOMPLETE
	// Return Convention:

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return "something";
	else return "something";
}

// BAPI::NETWORK::CYCLE

bool BAPI::NETWORK::CYCLE::is_present(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET,
	std::string CYC
) {
	// INCOMPLETE
	// Return Convention:

	return true;
}

std::string BAPI::NETWORK::CYCLE::get_all(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET,
	std::string BID
) {
	// INCOMPLETE
	// Return Convention:

	std::string prefix = "#NET_CYCS";

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string BAPI::NETWORK::CYCLE::get(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET,
	std::string CYC
) {
	// INCOMPLETE
	// Return Convention:

	std::string prefix = "#NET_CYC";

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string BAPI::NETWORK::CYCLE::get_available(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET
) {
	// INCOMPLETE
	// Return Convention:

	std::string prefix = "#NET_FREE_CYC";

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string BAPI::NETWORK::CYCLE::update_all(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET,
	std::string multiple_cycle_data,
	short action
) {
	// INCOMPLETE. Consider Removal
	// Return Convention

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return "something";
	else return "something";
}

std::string BAPI::NETWORK::CYCLE::update(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET,
	std::string CYC,
	std::string cycle_data,
	short action
) {
	// INCOMPLETE
	// Return Convention:

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return "something";
	else return "something";
}

std::string BAPI::NETWORK::CYCLE::add(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET,
	std::string cycle_data
) {
	// INCOMPLETE.
	// Return Convention:

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return "something";
	else return "something";
}

std::string BAPI::NETWORK::CYCLE::remove(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET,
	std::string CYC
) {
	// INCOMPLETE
	// Return Convention:

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return "something";
	else return "something";
}

// BAPI::NETWORK::LOCK

std::string BAPI::NETWORK::LOCK::get_all(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET
) {
	// INCOMPLETE
	// Return Convention:

	std::string prefix = "#NET_LCKS";

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string BAPI::NETWORK::LOCK::get(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET,
	std::string LCK
) {
	// INCOMPLETE
	// Return Convention:

	std::string prefix = "#NET_LCK";

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string BAPI::NETWORK::LOCK::get_stats(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET,
	std::string LCK
) {
	// INCOMPLETE
	// Return Convention:

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return "something";
	else return "something";
}

std::string BAPI::NETWORK::LOCK::update_all(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET,
	std::string multiple_lock_data,
	short action
) {
	// INCOMPLETE
	// Return Convention:

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return "something";
	else return "something";
}

std::string BAPI::NETWORK::LOCK::update(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET,
	std::string LCK,
	std::string lock_data,
	short action
) {
	// INCOMPLETE
	// Return Convention:

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return "something";
	else return "something";
}

std::string BAPI::NETWORK::LOCK::add(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET,
	std::string STD,
	std::string lock_data
) {
	// INCOMPLETE
	// Return Convention:

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return "something";
	else return "something";
}

std::string BAPI::NETWORK::LOCK::remove(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET,
	std::string STD,
	std::string LCK
) {
	// INCOMPLETE
	// Return Convention:

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return "something";
	else return "something";
}

// BAPI::NETWORK::TXN

std::string BAPI::NETWORK::TXN::get_all_TXN(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET
) {
	// INCOMPLETE.
	// Return Convention:

	std::string prefix = "#NET_TXNS";

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string BAPI::NETWORK::TXN::get_user_TXN(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET,
	std::string BID_requested
) {
	// INCOMPLETE
	// Return Convention:

	std::string prefix = "#NET_USR_TXN";

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string BAPI::NETWORK::TXN::get_stand_TXN(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET,
	std::string STD
) {
	// INCOMPLETE
	// Return Convention:

	std::string prefix = "#NET_STD_TXN";

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string BAPI::NETWORK::TXN::get_cycle_TXN(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET,
	std::string CYC
) {
	// INCOMPLETE
	// Return Convention:

	std::string prefix = "#NET_CYC_TXN";

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string BAPI::NETWORK::TXN::get_TXN(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET,
	std::string TXN
) {
	// INCOMPLETE
	// Return Convention:

	std::string prefix = "#NET_TXN";

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

#endif // TEST


#ifdef RELEASE

// Local Variables
Token token;

// Local Definitions

// Local Definitions
bool checkNetObj(std::string USERNAME, std::string NET) {	// INCOMPLETE
	return false;
}

/*=================================================================================================================*/
//USER/CHECK FUNCTIONS
/*-----------------------------------------------------------------------------------------------*/
bool bapi::user::chk::user(std::string access_code, short key, std::string username, std::string net) {
	//INCOMPLETE
	/*Function to check presence of account inside a network.
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
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

		if (token.checkAccess(access_code)) {
			switch (key)
			{
			case 1: {
				if (checkNetObj(username, net))
					return true;
				return false;
			}
				  break;
			case 2: {
				// INCOMPLETE
			}
				  break;
			case 3:
				break;
			case 4: {
				if (checkNetObj(username, net))
					return true;
				return false;
			}
				  break;
			case 5:
				break;
			default:
				break;
			}
		}

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

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
		case 4: {
			if (checkNetwork(net)) {

			}
		}
			  break;
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
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	return token.giveSession();
}

bool bapi::user::chk::logout(std::string access_code, std::string session_code, std::string bid, std::string data) {
	//INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}
	return false;
}

//USER/GET/ATTRIBUTES Functions
/*-----------------------------------------------------------------------------------------------*/
std::string bapi::user::get::attr::users(std::string access_code, std::string session_code, short usertype) {
	//INCOMPLETE
	std::string prefix[] = { "#BLK_ADM","#BLK_STU","#BLK_EMP","#BLK_SUP","#BLK_MOD","#BLK_GUE" };
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	return prefix[0] + "0";
}

std::string bapi::user::get::attr::user(std::string access_code, std::string session_code, std::string BID_requestedBy, std::string BID_requested) {
	//INCOMPLETE
	std::string prefix[] = { "#USR_ATTR_ADM","#USR_ATTR_STU","#USR_ATTR_EMP","#USR_ATTR_SUP","#USR_ATTR_MOD","#USR_ATTR_GUE" };
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	return prefix[0] + "0";
}

std::string bapi::user::get::attr::user(std::string access_code, std::string session_code, std::string bid) {
	//INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return "0";
	else return "-1";
}

//USER/UPDATE/ATTRIBUTES Functions
/*-----------------------------------------------------------------------------------------------*/
bool bapi::user::up::attr::users(std::string access_code, std::string session_code, std::string bid, short action) {	//Consider removal.
	//INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::user::up::attr::user(std::string access_code, std::string session_code, std::string bid, std::string data) {
	//INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

//USER/POST/ATTRIBUTES Functions
/*-----------------------------------------------------------------------------------------------*/
bool bapi::user::post::attr::users(std::string access_code, std::string session_code, std::string BID_requestBy, short action, std::string data) {	//Consider removal
	//INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::user::post::attr::user(std::string access_code, std::string session_code, std::string BID_requestBy, short action, std::string data) {
	//INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

//USER/POP/ATTRIBUTES Functions
/*-----------------------------------------------------------------------------------------------*/
bool bapi::user::pop::attr::user(std::string access_code, std::string session_code, std::string BID_requestBy, std::string BID_requestOn, short action) {
	//INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}


/*=================================================================================================================*/
//NETWORK/CHECK Functions
/*-----------------------------------------------------------------------------------------------*/
bool bapi::net::chk::net(std::string access_code, std::string NET) { //INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code))
		return false;
	else return true;
}

bool bapi::net::chk::user(std::string access_code, short key, std::string NET, std::string BID) { //INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code))
		return false;
	else return true;
}

bool bapi::net::chk::owner(std::string access_code, std::string NET, std::string BID) { //INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code))
		return false;
	else return true;
}

bool bapi::net::chk::active(std::string access_code, std::string NET) { //INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code))
		return false;
	else return true;
}

//NETWORK/GET Functions
/*-----------------------------------------------------------------------------------------------*/
std::string bapi::net::get::net(std::string access_code, std::string session_code, std::string NET, std::string BID) { //INCOMPLETE
	std::string prefix = "#NET";
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::stats(std::string access_code, std::string session_code, std::string NET, std::string BID) { //INCOMPLETE
	std::string prefix = "#NET_STAT";
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::admins(std::string access_code, std::string session_code, std::string NET, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_ADMS";
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::owner(std::string access_code, std::string session_code, std::string NET, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_OWN";
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::stands(std::string access_code, std::string session_code, std::string NET, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_STDS";
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::stand(std::string access_code, std::string session_code, std::string NET, std::string STD, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_STD";
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::standStats(std::string access_code, std::string session_code, std::string NET, std::string STD, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_STD_STAT";
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::nearestStand(std::string access_code, std::string session_code, std::string NET, std::string LOC, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_NEAR_STD";
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

int bapi::net::get::standDistance(std::string access_code, std::string session_code, std::string NET, std::string STD1, std::string STD2, std::string BID) { // INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return 100;
	else return 100;
}

std::string bapi::net::get::cycles(std::string access_code, std::string session_code, std::string NET, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_CYCS";
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::cycle(std::string access_code, std::string session_code, std::string NET, std::string CYC) { // INCOMPLETE
	std::string prefix = "#NET_CYC";
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::freeCycles(std::string access_code, std::string session_code, std::string NET, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_FREE_CYC";
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::locks(std::string access_code, std::string session_code, std::string NET, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_LCKS";
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::lock(std::string access_code, std::string session_code, std::string NET, std::string LCK, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_LCK";
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::allTXN(std::string access_code, std::string session_code, std::string NET, std::string BID_requester) {
	std::string prefix = "#NET_TXNS";
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::userTXN(std::string access_code, std::string session_code, std::string NET, std::string BID_requester, std::string BID_requested) {
	std::string prefix = "#NET_USR_TXN";
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::stdTXN(std::string access_code, std::string session_code, std::string NET, std::string STD, std::string BID_requester) {
	std::string prefix = "#NET_STD_TXN";
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::cycTXN(std::string access_code, std::string session_code, std::string NET, std::string CYC, std::string BID_requester) {
	std::string prefix = "#NET_CYC_TXN";
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::TXN(std::string access_code, std::string session_code, std::string NET, std::string BID_requester, std::string TXN) {
	std::string prefix = "#NET_TXN";
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

//NETWORK/UP Functions
/*-----------------------------------------------------------------------------------------------*/
bool bapi::net::up::net(std::string access_code, std::string session_code, std::string NET, std::string BID, short action, std::string data) { // INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::up::stands(std::string access_code, std::string session_code, std::string NET, std::string BID, short action, std::string data) { // INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::up::stand(std::string access_code, std::string session_code, std::string NET, std::string BID, short action, std::string STD, std::string data) { // INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::up::cycles(std::string access_code, std::string session_code, std::string NET, std::string BID, short action, std::string data) { // INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::up::cycle(std::string access_code, std::string session_code, std::string NET, std::string BID, short action, std::string CYC, std::string data) { // INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::up::locks(std::string access_code, std::string session_code, std::string NET, std::string BID, short action, std::string data) { // INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::up::lock(std::string access_code, std::string session_code, std::string NET, std::string BID, short action, std::string LCK, std::string data) { // INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

//NETWORK/POST Functions
/*-----------------------------------------------------------------------------------------------*/
bool bapi::net::post::net(std::string access_code, std::string session_code, std::string BID, std::string data) { //INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::post::stand(std::string access_code, std::string session_code, std::string BID, std::string NET, std::string data) { //INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::post::cycle(std::string access_code, std::string session_code, std::string BID, std::string NET, std::string data) { //INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::post::lock(std::string access_code, std::string session_code, std::string BID, std::string NET, std::string STD, std::string data) { //INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

//NETWORK/POP Functions
/*-----------------------------------------------------------------------------------------------*/
bool bapi::net::pop::net(std::string access_code, std::string session_code, std::string BID, std::string NET) { // INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::pop::stand(std::string access_code, std::string session_code, std::string BID, std::string NET, std::string STD) { // INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::pop::cycle(std::string access_code, std::string session_code, std::string BID, std::string NET, std::string CYC) { // INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::pop::lock(std::string access_code, std::string session_code, std::string BID, std::string NET, std::string STD, std::string LCK) { // INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}


#endif // RELEASE


#ifdef LEGACY
/*===============================================================================================*/
bool TEST_MODE = true;		// Set this TEST_MODE to FALSE to unload the system from testing mode.
/*===============================================================================================*/

//Local variables
/*-----------------------------------------------------------------------------------------------*/
#ifdef TEST

Token token;

#endif // TEST

#ifdef RELEASE

Token token;

#endif // RELEASE


//Local declarations
/*-----------------------------------------------------------------------------------------------*/
#ifdef TEST

bool checkNetObj(std::string USERNAME, std::string NET);

#endif // TEST

#ifdef RELEASE

bool checkNetwork(std::string NET);

#endif // RELEASE



//USER/CHECK FUNCTIONS
/*-----------------------------------------------------------------------------------------------*/
bool bapi::user::chk::user(std::string access_code, short key, std::string username, std::string net) {
	//INCOMPLETE
	/*Function to check presence of account inside a network.
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
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

		if (token.checkAccess(access_code)) {
			switch (key)
			{
			case 1: {
				if (checkNetObj(username, net))
					return true;
				return false;
			}
				  break;
			case 2: {
				// INCOMPLETE
			}
				  break;
			case 3:
				break;
			case 4: {
				if (checkNetObj(username, net))
					return true;
				return false;
			}
				  break;
			case 5:
				break;
			default:
				break;
			}
		}

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

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
		case 4: {
			if (checkNetwork(net)) {

			}
		}
			  break;
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
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	return token.giveSession();
}

bool bapi::user::chk::logout(std::string access_code, std::string session_code, std::string bid, std::string data) {
	//INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}
	return false;
}


//USER/GET/ATTRIBUTES Functions
/*-----------------------------------------------------------------------------------------------*/
std::string bapi::user::get::attr::users(std::string access_code, std::string session_code, short usertype) {
	//INCOMPLETE
	std::string prefix[] = { "#BLK_ADM","#BLK_STU","#BLK_EMP","#BLK_SUP","#BLK_MOD","#BLK_GUE" };
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	return prefix[0] + "0";
}

std::string bapi::user::get::attr::user(std::string access_code, std::string session_code, std::string BID_requestedBy, std::string BID_requested) {
	//INCOMPLETE
	std::string prefix[] = { "#USR_ATTR_ADM","#USR_ATTR_STU","#USR_ATTR_EMP","#USR_ATTR_SUP","#USR_ATTR_MOD","#USR_ATTR_GUE" };
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	return prefix[0] + "0";
}

std::string bapi::user::get::attr::user(std::string access_code, std::string session_code, std::string bid) {
	//INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return "0";
	else return "-1";
}


//USER/UPDATE/ATTRIBUTES Functions
/*-----------------------------------------------------------------------------------------------*/
bool bapi::user::up::attr::users(std::string access_code, std::string session_code, std::string bid, short action) {	//Consider removal.
	//INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::user::up::attr::user(std::string access_code, std::string session_code, std::string bid, std::string data) {
	//INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}


//USER/POST/ATTRIBUTES Functions
/*-----------------------------------------------------------------------------------------------*/
bool bapi::user::post::attr::users(std::string access_code, std::string session_code, std::string BID_requestBy, short action, std::string data) {	//Consider removal
	//INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::user::post::attr::user(std::string access_code, std::string session_code, std::string BID_requestBy, short action, std::string data) {
	//INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}


//USER/POP/ATTRIBUTES Functions
/*-----------------------------------------------------------------------------------------------*/
bool bapi::user::pop::attr::user(std::string access_code, std::string session_code, std::string BID_requestBy, std::string BID_requestOn, short action) {
	//INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

//NETWORK/CHECK Functions
/*-----------------------------------------------------------------------------------------------*/
bool bapi::net::chk::net(std::string access_code, std::string NET) { //INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code))
		return false;
	else return true;
}

bool bapi::net::chk::user(std::string access_code, short key, std::string NET, std::string BID) { //INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code))
		return false;
	else return true;
}

bool bapi::net::chk::owner(std::string access_code, std::string NET, std::string BID) { //INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code))
		return false;
	else return true;
}

bool bapi::net::chk::active(std::string access_code, std::string NET) { //INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code))
		return false;
	else return true;
}

//NETWORK/GET Functions
/*-----------------------------------------------------------------------------------------------*/
std::string bapi::net::get::net(std::string access_code, std::string session_code, std::string NET, std::string BID) { //INCOMPLETE
	std::string prefix = "#NET";
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::stats(std::string access_code, std::string session_code, std::string NET, std::string BID) { //INCOMPLETE
	std::string prefix = "#NET_STAT";
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::admins(std::string access_code, std::string session_code, std::string NET, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_ADMS";
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::owner(std::string access_code, std::string session_code, std::string NET, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_OWN";
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::stands(std::string access_code, std::string session_code, std::string NET, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_STDS";
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::stand(std::string access_code, std::string session_code, std::string NET, std::string STD, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_STD";
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::standStats(std::string access_code, std::string session_code, std::string NET, std::string STD, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_STD_STAT";
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::nearestStand(std::string access_code, std::string session_code, std::string NET, std::string LOC, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_NEAR_STD";
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

int bapi::net::get::standDistance(std::string access_code, std::string session_code, std::string NET, std::string STD1, std::string STD2, std::string BID) { // INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return 100;
	else return 100;
}

std::string bapi::net::get::cycles(std::string access_code, std::string session_code, std::string NET, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_CYCS";
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::cycle(std::string access_code, std::string session_code, std::string NET, std::string CYC) { // INCOMPLETE
	std::string prefix = "#NET_CYC";
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::freeCycles(std::string access_code, std::string session_code, std::string NET, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_FREE_CYC";
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::locks(std::string access_code, std::string session_code, std::string NET, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_LCKS";
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::lock(std::string access_code, std::string session_code, std::string NET, std::string LCK, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_LCK";
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::allTXN(std::string access_code, std::string session_code, std::string NET, std::string BID_requester) {
	std::string prefix = "#NET_TXNS";
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::userTXN(std::string access_code, std::string session_code, std::string NET, std::string BID_requester, std::string BID_requested) {
	std::string prefix = "#NET_USR_TXN";
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::stdTXN(std::string access_code, std::string session_code, std::string NET, std::string STD, std::string BID_requester) {
	std::string prefix = "#NET_STD_TXN";
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::cycTXN(std::string access_code, std::string session_code, std::string NET, std::string CYC, std::string BID_requester) {
	std::string prefix = "#NET_CYC_TXN";
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::TXN(std::string access_code, std::string session_code, std::string NET, std::string BID_requester, std::string TXN) {
	std::string prefix = "#NET_TXN";
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

//NETWORK/UP Functions
/*-----------------------------------------------------------------------------------------------*/
bool bapi::net::up::net(std::string access_code, std::string session_code, std::string NET, std::string BID, short action, std::string data) { // INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::up::stands(std::string access_code, std::string session_code, std::string NET, std::string BID, short action, std::string data) { // INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::up::stand(std::string access_code, std::string session_code, std::string NET, std::string BID, short action, std::string STD, std::string data) { // INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::up::cycles(std::string access_code, std::string session_code, std::string NET, std::string BID, short action, std::string data) { // INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::up::cycle(std::string access_code, std::string session_code, std::string NET, std::string BID, short action, std::string CYC, std::string data) { // INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::up::locks(std::string access_code, std::string session_code, std::string NET, std::string BID, short action, std::string data) { // INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::up::lock(std::string access_code, std::string session_code, std::string NET, std::string BID, short action, std::string LCK, std::string data) { // INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

//NETWORK/POST Functions
/*-----------------------------------------------------------------------------------------------*/
bool bapi::net::post::net(std::string access_code, std::string session_code, std::string BID, std::string data) { //INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::post::stand(std::string access_code, std::string session_code, std::string BID, std::string NET, std::string data) { //INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::post::cycle(std::string access_code, std::string session_code, std::string BID, std::string NET, std::string data) { //INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::post::lock(std::string access_code, std::string session_code, std::string BID, std::string NET, std::string STD, std::string data) { //INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

//NETWORK/POP Functions
/*-----------------------------------------------------------------------------------------------*/
bool bapi::net::pop::net(std::string access_code, std::string session_code, std::string BID, std::string NET) { // INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::pop::stand(std::string access_code, std::string session_code, std::string BID, std::string NET, std::string STD) { // INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::pop::cycle(std::string access_code, std::string session_code, std::string BID, std::string NET, std::string CYC) { // INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::pop::lock(std::string access_code, std::string session_code, std::string BID, std::string NET, std::string STD, std::string LCK) { // INCOMPLETE
	if (TEST_MODE) { // Stub operation of this BAPI function is enclosed here.

	}
	else {	// Real operation of this BAPI function is enclosed here.
	}
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

//-----------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------

//Local Definitions

#ifdef TEST

bool checkNetObj(std::string USERNAME, std::string NET) {	// COMPLETE
	return true;
}

#endif // TEST

#ifdef RELEASE

bool checkNetwork(std::string NET) {	// INCOMPLETE
	return false;
}

#endif // RELEASE  
#endif // LEGACY