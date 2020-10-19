#include <bapi.h>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <map>
#include "..\src\middle\token.h"

#define TEST	// Set this TEST to RELASE to unload the system from testing mode.

#ifdef TEST
#include "..\data\testing\test_data.h"

// Local Declarations
bool checkNetObj(std::string username, std::string NET);

// Local Definitions
bool checkNetObj(std::string username, std::string NET) {	// COMPLETE
	// Stupidly slow. I know
	if (NET == "NET100") {
		unsigned short objects = sizeof(NET100_obj)/sizeof(NET100_obj[0]);
		for (int i = 0; i < objects; i++)
			if (NET100_obj[i] == username)
				return true;
	}
	else if (NET == "NET200") {
		for (int i = 0; i < NET200_obj->size(); i++)
			if (NET200_obj[i] == username)
				return true;
	}
	else if (NET == "NET300") {
		unsigned short objects = sizeof(NET300_obj) / sizeof(NET300_obj[0]);
		for (int i = 0; i < objects; i++)
			if (NET300_obj[i] == username)
				return true;
	}
	else if (NET == "NET400") {
		unsigned short objects = sizeof(NET400_obj) / sizeof(NET400_obj[0]);
		for (int i = 0; i < objects; i++)
			if (NET400_obj[i] == username)
				return true;
	}
	else if (NET == "NET500") {
		unsigned short objects = sizeof(NET500_obj) / sizeof(NET500_obj[0]);
		for (int i = 0; i < objects; i++)
			if (NET500_obj[i] == username)
				return true;
	}
	else if (NET == "NET600") {
		unsigned short objects = sizeof(NET600_obj) / sizeof(NET600_obj[0]);
		for (int i = 0; i < objects; i++)
			if (NET600_obj[i] == username)
				return true;
	}
	else if (NET == "NET700") {
		unsigned short objects = sizeof(NET700_obj) / sizeof(NET700_obj[0]);
		for (int i = 0; i < objects; i++)
			if (NET700_obj[i] == username)
				return true;
	}
	else if (NET == "NET800") {
		unsigned short objects = sizeof(NET800_obj) / sizeof(NET800_obj[0]);
		for (int i = 0; i < objects; i++)
			if (NET800_obj[i] == username)
				return true;
	}
	else if (NET == "NET900") {
		unsigned short objects = sizeof(NET900_obj) / sizeof(NET900_obj[0]);
		for (int i = 0; i < objects; i++)
			if (NET900_obj[i] == username)
				return true;
	}
	else if (NET == "NET110") {
		unsigned short objects = sizeof(NET110_obj) / sizeof(NET110_obj[0]);
		for (int i = 0; i < objects; i++)
			if (NET110_obj[i] == username)
				return true;
	}
	else return false;
}

// BAPI::USER

bool BAPI::USER::is_present(
	std::string access_code,
	std::string NET,
	std::string username,
	short usertype
){
	//COMPLETE
	// Returning Convention: 

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

	if (token.checkAccess(access_code)) {
		switch (usertype)
		{
		case 1: {	// Invoked if the user key is ADMIN
			return (checkNetObj(username, NET));
		}
			  break;
		case 2: {	// Invoked if the user key is SUPPORT
			// INCOMPLETE
		}
			  break;
		case 3: {	// Invoked if the user key is MODERATOR
			// INCOMPLETE
		}
			  break;
		case 4: {	// Invoked if the user key is STUDENT
			return (checkNetObj(username, NET));
		}
			  break;
		case 5: {	// Invoked if the user key is EMPLOYEE
		}
			  break;
		default:
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
	// Returning Convention: 

	if (token.checkAccess(access_code)) {
		if (checkNetObj(username, NET) && salt == "0000")
			return token.giveSession();
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
	// COMPLETE
	// Returning Convention: 


	if (token.checkAccess(access_code) && token.checkSession(session_code)) {
		(Joker_DB.at(NET)).insert(BID, user_data);
		return true;
	}
	return false;
}

std::string BAPI::USER::get_all(
	std::string access_code,
	std::string session_code,
	std::string NET,
	std::string BID_request_by,
	short usertype
) {
	//COMPLETE

	/* Return Convention
	string get::attr::users() : "#BLK_ADM, count, 0:(BIDxxxxxxxxxx,Name,AID), 1:(BIDxxxxxxxxxx,Name,AID), ... n:(BIDxxxxxxxxxx,Name,AID)"
		* "#BLK_STU, count, 0:(BIDxxxxxxxxxx,Name,SID), 1:(BIDxxxxxxxxxx,Name,SID), ... n:(BIDxxxxxxxxxx,Name,SID)"
		* "#BLK_EMP, count, 0:(BIDxxxxxxxxxx,Name,EID), 1:(BIDxxxxxxxxxx,Name,EID), ... n:(BIDxxxxxxxxxx,Name,EID)"
		* "#BLK_SUP, count, 0:(BIDxxxxxxxxxx,Name,SUP), 1:(BIDxxxxxxxxxx,Name,SUP), ... n:(BIDxxxxxxxxxx,Name,SUP)"
		* "#BLK_MOD, count, 0:(BIDxxxxxxxxxx,Name,MOD), 1:(BIDxxxxxxxxxx,Name,MOD), ... n:(BIDxxxxxxxxxx,Name,MOD)"
		* "#BLK_GUE, count, 0:(BGIDxxxxxxxxxx,Name,Duration), 1:(BGIDxxxxxxxxxx,Name,Duration), ... n:(BGIDxxxxxxxxxx,Name,Duration)"
	*/


	std::string prefix[] = { "#BLK_ADM, ","#BLK_STU, ","#BLK_EMP, ","#BLK_SUP, ","#BLK_MOD, ","#BLK_GUE, " };
	std::string pass_data = "NULL";

	if (token.checkAccess(access_code) && token.checkSession(session_code) && (userTypes.at(BID_request_by) == 'A'))
	{
		if (NET == "NET100") {
			switch (usertype)
			{
			case 1: {
				pass_data = "";
				for (int i = 0; i < 6; i++)	// Loops for 6 times because only 6 admins are present.
					pass_data = pass_data + NET100_obj[i] + ", ";
				return prefix[0] + pass_data;
			}
				  break;
			case 2: {
				pass_data = "";
				for (int i = 5; i < NET100_obj->size(); i++)	// Skips first 6 admins and logs in the rest.
					pass_data = pass_data + NET100_obj[i] + ", ";
				return prefix[1] + pass_data;
			}
				  break;
			case 3:
			case 4:
			case 5:
			case 6:
			default:
				break;
			}
		}
		else if (NET == "NET200") {
			switch (usertype)
			{
			case 1: {
				pass_data = "";
				for (int i = 0; i < 6; i++)	// Loops for 6 times because only 6 admins are present.
					pass_data = pass_data + NET200_obj[i] + ", ";
				return prefix[0] + pass_data;
			}
				  break;
			case 2: {
				pass_data = "";
				for (int i = 5; i < NET200_obj->size(); i++)	// Skips first 6 admins and logs in the rest.
					pass_data = pass_data + NET200_obj[i] + ", ";
				return prefix[1] + pass_data;
			}
				  break;
			case 3:
			case 4:
			case 5:
			case 6:
			default:
				break;
			}
		}
		else if (NET == "NET300") {
			switch (usertype)
			{
			case 1: {
				pass_data = "";
				for (int i = 0; i < 6; i++)	// Loops for 6 times because only 6 admins are present.
					pass_data = pass_data + NET300_obj[i] + ", ";
				return prefix[0] + pass_data;
			}
				  break;
			case 2: {
				pass_data = "";
				for (int i = 5; i < NET500_obj->size(); i++)	// Skips first 6 admins and logs in the rest.
					pass_data = pass_data + NET300_obj[i] + ", ";
				return prefix[1] + pass_data;
			}
				  break;
			case 3:
			case 4:
			case 5:
			case 6:
			default:
				break;
			}
		}
		else if (NET == "NET400") {
			switch (usertype)
			{
			case 1: {
				pass_data = "";
				for (int i = 0; i < 6; i++)	// Loops for 6 times because only 6 admins are present.
					pass_data = pass_data + NET400_obj[i] + ", ";
				return prefix[0] + pass_data;
			}
				  break;
			case 2: {
				pass_data = "";
				for (int i = 5; i < NET400_obj->size(); i++)	// Skips first 6 admins and logs in the rest.
					pass_data = pass_data + NET400_obj[i] + ", ";
				return prefix[1] + pass_data;
			}
				  break;
			case 3:
			case 4:
			case 5:
			case 6:
			default:
				break;
			}
		}
		else if (NET == "NET500") {
			switch (usertype)
			{
			case 1: {
				pass_data = "";
				for (int i = 0; i < 6; i++)	// Loops for 6 times because only 6 admins are present.
					pass_data = pass_data + NET500_obj[i] + ", ";
				return prefix[0] + pass_data;
			}
				  break;
			case 2: {
				pass_data = "";
				//unsigned object_count = sizeof(NET500_obj) / sizeof(NET500_obj[0]);
				for (int i = 5; i < NET500_obj->size(); i++)	// Skips first 6 admins and logs in the rest.
					pass_data = pass_data + NET500_obj[i] + ", ";
				return prefix[1] + pass_data;
			}
				  break;
			case 3:
			case 4:
			case 5:
			case 6:
			default:
				break;
			}
		}
		else if (NET == "NET600") {
			switch (usertype)
			{
			case 1: {
				pass_data = "";
				for (int i = 0; i < 6; i++)	// Loops for 6 times because only 6 admins are present.
					pass_data = pass_data + NET600_obj[i] + ", ";
				return prefix[0] + pass_data;
			}
				  break;
			case 2: {
				pass_data = "";
				unsigned object_count = sizeof(NET600_obj) / sizeof(NET600_obj[0]);
				for (int i = 5; i < NET600_obj->size(); i++)	// Skips first 6 admins and logs in the rest.
					pass_data = pass_data + NET600_obj[i] + ", ";
				return prefix[1] + pass_data;
			}
				  break;
			case 3:
			case 4:
			case 5:
			case 6:
			default:
				break;
			}
		}
		else if (NET == "NET700") {
			switch (usertype)
			{
			case 1: {
				pass_data = "";
				for (int i = 0; i < 6; i++)	// Loops for 6 times because only 6 admins are present.
					pass_data = pass_data + NET700_obj[i] + ", ";
				return prefix[0] + pass_data;
			}
				  break;
			case 2: {
				pass_data = "";
				unsigned object_count = sizeof(NET700_obj) / sizeof(NET700_obj[0]);
				for (int i = 5; i < NET700_obj->size(); i++)	// Skips first 6 admins and logs in the rest.
					pass_data = pass_data + NET700_obj[i] + ", ";
				return prefix[1] + pass_data;
			}
				  break;
			case 3:
			case 4:
			case 5:
			case 6:
			default:
				break;
			}
		}
		else if (NET == "NET800") {
			switch (usertype)
			{
			case 1: {
				pass_data = "";
				for (int i = 0; i < 6; i++)	// Loops for 6 times because only 6 admins are present.
					pass_data = pass_data + NET800_obj[i] + ", ";
				return prefix[0] + pass_data;
			}
				  break;
			case 2: {
				pass_data = "";
				unsigned object_count = sizeof(NET800_obj) / sizeof(NET800_obj[0]);
				for (int i = 5; i < NET800_obj->size(); i++)	// Skips first 6 admins and logs in the rest.
					pass_data = pass_data + NET800_obj[i] + ", ";
				return prefix[1] + pass_data;
			}
				  break;
			case 3:
			case 4:
			case 5:
			case 6:
			default:
				break;
			}
		}
		else if (NET == "NET900") {
			switch (usertype)
			{
			case 1: {
				pass_data = "";
				for (int i = 0; i < 6; i++)	// Loops for 6 times because only 6 admins are present.
					pass_data = pass_data + NET900_obj[i] + ", ";
				return prefix[0] + pass_data;
			}
				  break;
			case 2: {
				pass_data = "";
				unsigned object_count = sizeof(NET900_obj) / sizeof(NET900_obj[0]);
				for (int i = 5; i < NET900_obj->size(); i++)	// Skips first 6 admins and logs in the rest.
					pass_data = pass_data + NET900_obj[i] + ", ";
				return prefix[1] + pass_data;
			}
				  break;
			case 3:
			case 4:
			case 5:
			case 6:
			default:
				break;
			}
		}
		else if (NET == "NET110") {
			switch (usertype)
			{
			case 1: {
				pass_data = "";
				for (int i = 0; i < 6; i++)	// Loops for 6 times because only 6 admins are present.
					pass_data = pass_data + NET110_obj[i] + ", ";
				return prefix[0] + pass_data;
			}
				  break;
			case 2: {
				pass_data = "";
				unsigned object_count = sizeof(NET110_obj) / sizeof(NET110_obj[0]);
				for (int i = 5; i < NET110_obj->size(); i++)	// Skips first 6 admins and logs in the rest.
					pass_data = pass_data + NET110_obj[i] + ", ";
				return prefix[1] + pass_data;
			}
				  break;
			case 3:
			case 4:
			case 5:
			case 6:
			default:
				break;
			}
		}
	}
	return pass_data;
}

std::string BAPI::USER::get(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET,
	std::string BID
) {
	//COMPLETE

	/* Return Convention
	"	"#USR_ATTR_ADM, BID:'BIDxxxxxxxxxx', AID:'xxxxxxxxxx', NET:'NETxxxxxxxxxx', OWN:'0 or 1', NAME:'xxxxxxxxxx', GUARDIAN:'xxxxxxxxxx', DOB:'00/MON/0000', ACT_STAT:'0 or 1', PH1:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', PH2:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', EM1:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', EM2:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', ADD1:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), AREA:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ADD2==ADD1:'0', ADD2:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), LOC:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ONLINE:'0 or 1', ACC_STAT:'xxxxxxxxxx'"
	*	"#USR_ATTR_STU, BID:'BIDxxxxxxxxxx', SID:'xxxxxxxxxx', NET:'NETxxxxxxxxxx', PEN:'0 or 1', NAME:'xxxxxxxxxx', GUARDIAN:'xxxxxxxxxx', DOB:'00/MON/0000', ACT_STAT:'0 or 1', PH1:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', PH2:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', EM1:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', EM2:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', ADD1:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), AREA:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ADD2==ADD1:'0', ADD2:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), LOC:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ONLINE:'0 or 1', ACC_STAT:'xxxxxxxxxx', DEPT:'xxxxxxxxxx', LOGCOUNT:'xxxxxxxxx'"
	*	"#USR_ATTR_EMP, BID:'BIDxxxxxxxxxx', EID:'xxxxxxxxxx', NET:'NETxxxxxxxxxx', OWN:'0 or 1', NAME:'xxxxxxxxxx', GUARDIAN:'xxxxxxxxxx', SPOUSE:'xxxxxxxxxx', DOB:'00/MON/0000', ACT_STAT:'0 or 1', PH1:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', PH2:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', EM1:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', EM2:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', ADD1:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), AREA:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ADD2==ADD1:'1', ADD2:'NULL', ONLINE:'0 or 1', ACC_STAT:'xxxxxxxxxx', DEPT:'xxxxxxxxxx', LOGCOUNT:'xxxxxxxxx'"
	*/

	std::string prefix[] = { "#USR_ATTR_ADM, ","#USR_ATTR_STU, ","#USR_ATTR_EMP, ","#USR_ATTR_SUP, ","#USR_ATTR_MOD, ","#USR_ATTR_GUE, " };
	std::string pass_data = "NULL";

	if (token.checkAccess(access_code) && token.checkSession(session_code) && (userTypes.at(BID_requested_by) == 'A') || (userTypes.at(BID_requested_by) == 'U'))
	{
		if (NET == "NET100") {
			// Not implementing check method for authenticating type of BID_requested_by
			// Not implementing checking user type method right now.
			return prefix[0] + (Joker_DB.at(NET)).at(BID);
		}
		else if (NET == "NET200") {
			// Not implementing check method for authenticating type of BID_requested_by
			std::map <std::string, std::string> data_container;
			data_container = Joker_DB.at(NET);
			pass_data = data_container.at(BID);
			return prefix[1] + pass_data;		// Not implementing checking user type method right now.
		}
		else if (NET == "NET300") {
			// Not implementing check method for authenticating type of BID_requested_by
			std::map <std::string, std::string> data_container;
			data_container = Joker_DB.at(NET);
			pass_data = data_container.at(BID);
			return prefix[0] + pass_data;		// Not implementing checking user type method right now.
		}
		else if (NET == "NET400") {
			// Not implementing check method for authenticating type of BID_requested_by
			std::map <std::string, std::string> data_container;
			data_container = Joker_DB.at(NET);
			pass_data = data_container.at(BID);
			return prefix[1] + pass_data;		// Not implementing checking user type method right now.
		}
		else if (NET == "NET500") {
			// Not implementing check method for authenticating type of BID_requested_by
			std::map <std::string, std::string> data_container;
			data_container = Joker_DB.at(NET);
			pass_data = data_container.at(BID);
			return prefix[0] + pass_data;		// Not implementing checking user type method right now.
		}
		else if (NET == "NET600") {
			// Not implementing check method for authenticating type of BID_requested_by
			std::map <std::string, std::string> data_container;
			data_container = Joker_DB.at(NET);
			pass_data = data_container.at(BID);
			return prefix[0] + pass_data;		// Not implementing checking user type method right now.
		}
		else if (NET == "NET700") {
			// Not implementing check method for authenticating type of BID_requested_by
			std::map <std::string, std::string> data_container;
			data_container = Joker_DB.at(NET);
			pass_data = data_container.at(BID);
			return prefix[0] + pass_data;		// Not implementing checking user type method right now.
		}
		else if (NET == "NET800") {
			// Not implementing check method for authenticating type of BID_requested_by
			std::map <std::string, std::string> data_container;
			data_container = Joker_DB.at(NET);
			pass_data = data_container.at(BID);
			return prefix[0] + pass_data;		// Not implementing checking user type method right now.
		}
		else if (NET == "NET900") {
			// Not implementing check method for authenticating type of BID_requested_by
			std::map <std::string, std::string> data_container;
			data_container = Joker_DB.at(NET);
			pass_data = data_container.at(BID);
			return prefix[0] + pass_data;		// Not implementing checking user type method right now.
		}
		else if (NET == "NET110") {
			// Not implementing check method for authenticating type of BID_requested_by
			std::map <std::string, std::string> data_container;
			data_container = Joker_DB.at(NET);
			pass_data = data_container.at(BID);
			return prefix[0] + pass_data;		// Not implementing checking user type method right now.
		}
		else return pass_data;
	}
	return "ERROR CODE: M100 - Unauthorized access. Bad Access or Session Key";
}

std::string BAPI::USER::update_all(
	std::string access_code,
	std::string session_code,
	std::string BID_requested_by,
	std::string NET,
	std::string multiple_user_data,
	short action
) {	
	// INCOMPLETE. //Consider removal.
	// Return Convention:

	if (token.checkAccess(access_code) && token.checkSession(session_code) && (userTypes.at(BID_requested_by) == 'A')) {
		return "something";
	}
	else return "something";
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
	if (token.checkAccess(access_code) && token.checkSession(session_code) && ((userTypes.at(BID_requested_by) == 'A') || (userTypes.at(BID_requested_by) == 'U'))) {
		(Joker_DB.at(NET)).at(BID) = user_data;
		return "something";
	}
	else return "something";
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

	if (token.checkAccess(access_code) && token.checkSession(session_code) && (userTypes.at(BID_requested_by) == 'A')) {
		for (int i = 0; i < 10; i++) {
			std::string BID_add = token.giveSession();
			(Joker_DB.at(NET)).insert(make_pair(BID_add, multiple_user_data));
		}
		return "something";
	}
	else return "something";
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

	if (token.checkAccess(access_code) && token.checkSession(session_code) && (userTypes.at(BID_requested_by) == 'A')) {
		std::string BID_add = token.giveSession();	// Currently using a random seed, would be later replaced with a BID generator.
		(Joker_DB.at(NET)).insert(make_pair(BID_add, user_data)); // In implementation, make a BID_add generator.
		return "something";
	}
	else return "something";
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

	if (token.checkAccess(access_code) && token.checkSession(session_code) && (userTypes.at(BID_requested_by) == 'A')) {
		(Joker_DB.at(NET)).erase((Joker_DB.at(NET)).find(BID_to_remove));

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

		return "something";
	}
	else return "something";
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
		if (NET == "NET100" || NET == "NET200" || NET == "NET300" || NET == "NET400" || NET == "NET500" || NET == "NET600" || NET == "NET700" || NET == "NET800" || NET == "NET900" || NET == "NET110")
			return true;
	}
	else return false;
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