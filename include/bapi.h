#ifndef BAPI_H
#define BAPI_H
#include <string>

// Returning conventions of these functions are mentioned at the end of this file.

namespace BAPI {

	// Type variables. NEVER CHANGE THEM!
	const short ADM = 0;	// Administrator
	const short SUP = 1;	// Support
	const short MOD = 2;	// Moderator
	const short STU = 3;	// Student
	const short EMP = 4;	// Employee
	const short GUE = 5;	// Guest

	// Action variables. NEVER CHANGE THEM!
	const short ACT1 = 1;
	const short ACT2 = 2;
	const short ACT3 = 3;
	const short ACT4 = 4;
	const short ACT5 = 5;

	namespace USER {

		// The following are basic authorization and verification functions

		bool is_present(
			std::string access_code,
			std::string NET,
			std::string username,
			short usertype
		);

		std::string authorize_login(
			std::string access_code,
			std::string NET,
			std::string username,
			std::string salt,
			short usertype
		);

		bool logout(
			std::string access_code,
			std::string session_code,
			std::string BID,
			std::string NET,
			std::string user_data
		);

		// The following are simple GET functions

		std::string get_all(
			std::string access_code,
			std::string session_code,
			std::string NET,
			std::string BID_requested_by,
			short usertype
		);

		std::string get(
			std::string access_code,
			std::string session_code,
			std::string BID_requested_by,
			std::string NET,
			std::string BID_requested
		);

		// The following are UPDATE functions

		std::string update_all(
			std::string access_code,
			std::string session_code,
			std::string BID_requested_by,
			std::string NET,
			std::string multiple_user_data,
			short action
		);	//Consider removal.
		
		std::string update(
			std::string access_code,
			std::string session_code,
			std::string BID_requested_by,
			std::string NET,
			std::string BID,
			std::string user_data
		);

		// The following are POST functions

		std::string add_multiple(
			std::string access_code,
			std::string session_code,
			std::string BID_requested_by,
			std::string NET,
			std::string multiple_user_data,
			short action
		);	//Consider removal

		std::string add(
			std::string access_code,
			std::string session_code,
			std::string BID_requested_by,
			std::string NET,
			std::string user_data,
			short action
		);

		// The following are POP functions

		std::string remove(
			std::string access_code,
			std::string session_code,
			std::string BID_requested_by,
			std::string NET,
			std::string BID_to_remove,
			short action
		);

		// The following are other nested functions for USER

		namespace MESSAGE {}
		namespace NOTIFICATION {}
		namespace TICKET {}
		namespace FEEDBACK {}
	}

	namespace NETWORK {

		// The following are basic CHECK functions

		bool is_present(
			std::string access_code,
			std::string NET
		);

		bool user_exist(
			std::string access_code,
			std::string NET,
			std::string BID_check,
			short usertype
		);

		bool is_owner(
			std::string access_code,
			std::string NET,
			std::string BID_check
		);

		bool is_active(
			std::string access_code,
			std::string NET
		);

		// The following are basic GET functions

		std::string get_all(
			std::string access_code
		);

		std::string get(
			std::string access_code,
			std::string session_code,
			std::string BID_requested_by,
			std::string NET
		);

		std::string get_stats(
			std::string access_code,
			std::string session_code,
			std::string BID_requested_by,
			std::string NET
		);

		std::string get_admins(
			std::string access_code,
			std::string session_code,
			std::string BID_requested_by,
			std::string NET
		);

		std::string get_owner(
			std::string access_code,
			std::string session_code,
			std::string BID_requested_by,
			std::string NET
		);

		// The following are basic UPDATE functions

		std::string update(
			std::string access_code,
			std::string session_code,
			std::string BID_requested_by,
			std::string NET,
			std::string network_data,
			short action
		);

		// The following are basic POST functions

		std::string add(
			std::string access_code,
			std::string session_code,
			std::string BID_requested_by,
			std::string network_data
		);

		// The following are basic POP functions

		std::string remove(
			std::string access_code,
			std::string session_code,
			std::string BID_requested_by,
			std::string NET
		);

		// The following are other nested functions for NETWORK

		namespace STAND {

			// The following are basic CHECK functions

			bool is_stand_present(
				std::string access_code,
				std::string session_code,
				std::string BID_requested_by,
				std::string NET,
				std::string STD
			);
			
			// The following are basic GET functions

			std::string get_all(
				std::string access_code,
				std::string session_code,
				std::string BID_requested_by,
				std::string NET
			);

			std::string get(
				std::string access_code,
				std::string session_code,
				std::string BID_requested_by,
				std::string NET,
				std::string STD
			);

			std::string get_stats(
				std::string access_code,
				std::string session_code,
				std::string BID_requested_by,
				std::string NET,
				std::string STD
			);

			std::string get_nearest(
				std::string access_code,
				std::string session_code,
				std::string BID_requested_by,
				std::string NET,
				std::string location
			);

			int get_distance(
				std::string access_code,
				std::string session_code,
				std::string BID_requested_by,
				std::string NET,
				std::string STD1,
				std::string STD2
			);

			std::string get_vacant(
				std::string access_code,
				std::string session_code,
				std::string NET
			);

			// The following are basic UPDATE functions

			std::string update_all(
				std::string access_code,
				std::string session_code,
				std::string BID_requested_by,
				std::string NET,
				std::string multiple_stand_data,
				short action
			);

			std::string update(
				std::string access_code,
				std::string session_code,
				std::string BID_requested_by,
				std::string NET,
				std::string STD,
				std::string stand_data,
				short action
			);

			// The following are basic POST functions

			std::string add(
				std::string access_code,
				std::string session_code,
				std::string BID_requested_by,
				std::string NET,
				std::string stand_data
			);

			// The following are basic POP functions

			std::string remove(
				std::string access_code,
				std::string session_code,
				std::string BID_requested_by,
				std::string NET,
				std::string STD
			);

		}

		namespace CYCLE {

			// The following are basic CHECK functions

			bool is_present(
				std::string access_code,
				std::string session_code,
				std::string BID_requested_by,
				std::string NET,
				std::string CYC
			);
			
			// The following are basic GET functions

			std::string get_all(
				std::string access_code,
				std::string session_code,
				std::string BID_requested_by,
				std::string NET,
				std::string BID
			);

			std::string get(
				std::string access_code,
				std::string session_code,
				std::string BID_requested_by,
				std::string NET,
				std::string CYC
			);

			std::string get_available(
				std::string access_code,
				std::string session_code,
				std::string BID_requested_by,
				std::string NET
			);

			// The following are basic UPDATE functions

			std::string update_all(
				std::string access_code,
				std::string session_code,
				std::string BID_requested_by,
				std::string NET,
				std::string multiple_cycle_data,
				short action
			);

			std::string update(
				std::string access_code,
				std::string session_code,
				std::string BID_requested_by,
				std::string NET,
				std::string CYC,
				std::string cycle_data,
				short action
			);

			// The following are basic POST functions

			std::string add(
				std::string access_code,
				std::string session_code,
				std::string BID_requested_by,
				std::string NET,
				std::string cycle_data
			);

			// The following are basic POP functions

			std::string remove(
				std::string access_code,
				std::string session_code,
				std::string BID_requested_by,
				std::string NET,
				std::string CYC
			);
		}

		namespace LOCK {

			// The following are basic GET functions

			std::string get_all(
				std::string access_code,
				std::string session_code,
				std::string BID_requested_by,
				std::string NET
			);

			std::string get(
				std::string access_code,
				std::string session_code,
				std::string BID_requested_by,
				std::string NET,
				std::string LCK
			);

			std::string get_stats(
				std::string access_code,
				std::string session_code,
				std::string BID_requested_by,
				std::string NET,
				std::string LCK
			);

			// The following are basic UPDATE functions

			std::string update_all(
				std::string access_code,
				std::string session_code,
				std::string BID_requested_by,
				std::string NET,
				std::string multiple_lock_data,
				short action
			);

			std::string update(
				std::string access_code,
				std::string session_code,
				std::string BID_requested_by,
				std::string NET,
				std::string LCK,
				std::string lock_data,
				short action
			);

			// The following are basic POST functions

			std::string add(
				std::string access_code,
				std::string session_code,
				std::string BID_requested_by,
				std::string NET,
				std::string STD,
				std::string lock_data
			);

			// The following are basic POP functions

			std::string remove(
				std::string access_code,
				std::string session_code,
				std::string BID_requested_by,
				std::string NET,
				std::string STD,
				std::string LCK
			);
		}

		namespace TXN {

			// The following are GET functions

			std::string get_all_TXN(
				std::string access_code,
				std::string session_code,
				std::string BID_requested_by,
				std::string NET
			);

			std::string get_user_TXN(
				std::string access_code,
				std::string session_code,
				std::string BID_requested_by,
				std::string NET,
				std::string BID_requested
			);

			std::string get_stand_TXN(
				std::string access_code,
				std::string session_code,
				std::string BID_requested_by,
				std::string NET,
				std::string STD
			);

			std::string get_cycle_TXN(
				std::string access_code,
				std::string session_code,
				std::string BID_requested_by,
				std::string NET,
				std::string CYC
			);

			std::string get_TXN(
				std::string access_code,
				std::string session_code,
				std::string BID_requested_by,
				std::string NET,
				std::string TXN
			);
		}

	}
}
#endif // BAPI_H

/*
* RETURNING CONVENTIONS:
*
* The following function come under namespace BAPI::USER::
*
* ::bool is_present(): 0 or 1
* ::string authorize_login():	SESSION_CODE: 'xxxxxxxxxx', BID:'xxxxxxxxxx'
* ::bool logout(): 0 or 1
* ::string get_all(): "#BLK_ADM, count, 0:(BIDxxxxxxxxxx,Name,AID), 1:(BIDxxxxxxxxxx,Name,AID), ... n:(BIDxxxxxxxxxx,Name,AID)"
*						    "#BLK_STU, count, 0:(BIDxxxxxxxxxx,Name,SID), 1:(BIDxxxxxxxxxx,Name,SID), ... n:(BIDxxxxxxxxxx,Name,SID)"
*						    "#BLK_EMP, count, 0:(BIDxxxxxxxxxx,Name,EID), 1:(BIDxxxxxxxxxx,Name,EID), ... n:(BIDxxxxxxxxxx,Name,EID)"
*						    "#BLK_SUP, count, 0:(BIDxxxxxxxxxx,Name,SUP), 1:(BIDxxxxxxxxxx,Name,SUP), ... n:(BIDxxxxxxxxxx,Name,SUP)"
*						    "#BLK_MOD, count, 0:(BIDxxxxxxxxxx,Name,MOD), 1:(BIDxxxxxxxxxx,Name,MOD), ... n:(BIDxxxxxxxxxx,Name,MOD)"
*						    "#BLK_GUE, count, 0:(BGIDxxxxxxxxxx,Name,Duration), 1:(BGIDxxxxxxxxxx,Name,Duration), ... n:(BGIDxxxxxxxxxx,Name,Duration)"
* ::string get(): "#USR_ATTR_ADM, BID:'BIDxxxxxxxxxx', AID : 'xxxxxxxxxx', NET : 'NETxxxxxxxxxx', OWN : '0 or 1', NAME : 'xxxxxxxxxx', GUARDIAN : 'xxxxxxxxxx', GEN : 'F or M or O', DOB : '00/MON/0000', ACT_STAT : '0 or 1', PH1 : 'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', PH2 : 'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', EM1 : 'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', EM2 : 'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', ADD1 : 'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), AREA:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ADD2 == ADD1 : '0', ADD2 : 'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), LOC:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ONLINE : '0 or 1', ACC_STAT : 'xxxxxxxxxx'"
*					   "#USR_ATTR_STU, BID:'BIDxxxxxxxxxx', SID:'xxxxxxxxxx', NET:'NETxxxxxxxxxx', PEN:'0 or 1', NAME:'xxxxxxxxxx', GUARDIAN:'xxxxxxxxxx', GEN : 'F or M or O', DOB:'00/MON/0000', ACT_STAT:'0 or 1', PH1:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', PH2:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', EM1:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', EM2:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', ADD1:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), AREA:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ADD2==ADD1:'0', ADD2:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), LOC:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ONLINE:'0 or 1', ACC_STAT:'xxxxxxxxxx', DEPT:'xxxxxxxxxx', LOGCOUNT:'xxxxxxxxx'"
*					   "#USR_ATTR_EMP, BID:'BIDxxxxxxxxxx', EID:'xxxxxxxxxx', NET:'NETxxxxxxxxxx', OWN:'0 or 1', NAME:'xxxxxxxxxx', GUARDIAN:'xxxxxxxxxx', GEN : 'F or M or O', SPOUSE:'xxxxxxxxxx', DOB:'00/MON/0000', ACT_STAT:'0 or 1', PH1:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', PH2:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', EM1:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', EM2:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', ADD1:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), AREA:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ADD2==ADD1:'1', ADD2:'NULL', ONLINE:'0 or 1', ACC_STAT:'xxxxxxxxxx', DEPT:'xxxxxxxxxx', LOGCOUNT:'xxxxxxxxx'"
*	//INCOMPLETE	   "#USR_ATTR_SUP, BID:'BIDxxxxxxxxxx', SUP:'xxxxxxxxxx', NET:'NETxxxxxxxxxx', OWN:'0 or 1', NAME:'xxxxxxxxxx', GUARDIAN:'xxxxxxxxxx', GEN : 'F or M or O', DOB:'00/MON/0000', ACT_STAT:'0 or 1', PH1:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', PH2:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', EM1:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', EM2:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', ADD1:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), AREA:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ADD2==ADD1:'1', ADD2:'NULL', ONLINE:'0 or 1', ACC_STAT:'xxxxxxxxxx'"
*	//INCOMPLETE	   "#USR_ATTR_MOD, BID:'BIDxxxxxxxxxx', MOD:'xxxxxxxxxx', NET:'NETxxxxxxxxxx', OWN:'0 or 1', NAME:'xxxxxxxxxx', GUARDIAN:'xxxxxxxxxx', GEN : 'F or M or O', DOB:'00/MON/0000', ACT_STAT:'0 or 1', PH1:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', PH2:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', EM1:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', EM2:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', ADD1:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), AREA:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ADD2==ADD1:'1', ADD2:'NULL', ONLINE:'0 or 1', ACC_STAT:'xxxxxxxxxx'"
*	//INCOMPLETE	   "#USR_ATTR_GUE, GID:'BGIDxxxxxxxxxx', Name:'xxxxxxxxxx', START:'00:00,00/00/00', END:'00:00,00/MON/0000', DUR:'00:00:00', IP:'000:000:000'"
* ::string update_all(): "RESPONSE CODE: Message, Remarks(if any)"
* ::string update(): "RESPONSE CODE: Message, Remarks(if any)"
* ::string add_multiple(): "RESPONSE CODE: Message, Remarks(if any)"
* ::string add(): "RESPONSE CODE: Message, AID/SID/EID/SUP/MOD, BID"
* ::string remove(): "RESPONSE CODE: Message, Remarks(if any)"
*
* BAPI::USER::MESSAGE::
* BAPI::USER::NOTIFICATION::
* BAPI::USER::TICKET::
* BAPI::USER::FEEDBACK::
*
* BAPI::NETWORK::
*
* ::bool is_present(): 0 or 1
* ::bool user_exist(): 0 or 1
* ::bool is_owner(): 0 or 1
* ::bool is_active(): 0 or 1
* ::string get_all():
* ::string get(): "#NET, NAME: 'xxxxxxxxxxx', NET:'NETxxxxxxxxxx', ORG:'xxxxxxxxxx', OWN:'BIDxxxxxxxxxx', ADM:'count,(BIDxxxxxxxxxx, BIDxxxxxxxxxx, ...)', SUP:'count,(BIDxxxxxxxxxx, BIDxxxxxxxxxx, ...)', MOD:'count,(BIDxxxxxxxxxx, BIDxxxxxxxxxx, ...)', USER:'count,(BIDxxxxxxxxxx, BIDxxxxxxxxxx, ...)', STD:'count,(STDxxxxxxxxxx, STDxxxxxxxxxx, ...)', CYC:'count,(CYCxxxxxxxxxx, CYCxxxxxxxxxx, ...)', LCK:'count,(LCKxxxxxxxxxx,LCKxxxxxxxxxx,...)', CAP:'count', TXN:'TXNxxxxxxxxxx'"
* ::string get_stats(): "#NET_STAT, INCOMPLETE"
* ::string get_admins(): "#NET_ADMS, count:'xxxx', 0:(BIDxxxxxxxxxx,Name,AID), 1:(BIDxxxxxxxxxx,Name,AID), ... n:(BIDxxxxxxxxxx,Name,AID)"
* ::string get_owner(): "#NET_OWN, BID:'BIDxxxxxxxxxx'";
* ::string update(): "RESPONSE CODE: Message, Remarks(if any)"
* ::string add(): "RESPONSE CODE: Message, NET"
* ::string remove(): "RESPONSE CODE: Message, Remarks(if any)"
*
* BAPI::NETWORK::STAND::
*
* ::bool is_present(): 0 or 1
* ::string get_all(): "#NET_STDS, count:'xxxx', 0:'STDxxxxxxxxxx', 1:'STDxxxxxxxxxx', ... n:'STDxxxxxxxxxx'";
* ::string get(): "#NET_STD, TIME:'00:00:00, DD/MMM/YYYY', STD:'STDxxxxxxxxxx', ACT_STAT:'0 or 1', STD_STAT:'xxxxxxxxxx', NAME:'xxxxxxxxxx', LOC:'xxxxxxxxxx', COORDINATE:(xxxxxx,xxxxxx), CAPACITY:'xxx', TXN_COUNT:'xxxxxxxxxx'"
* ::string get_stats(): "#NET_STD_STAT, INCOMPLETE"
* ::string get_nearest(): "#NET_NEAR_STD, 0:(DIST,STDxxxxxxxxxx), 1:(DIST,STDxxxxxxxxx), 2:(DIST,STDxxxxxxxxxx)";
* ::int get_distance(): int distance in meters
* ::string get_vacant(): "#NET_STD_VACANT, TIME:'00:00:00, DD/MMM/YYYY', count: 'xxxx', 0:('STDxxxxxxxxxx', 'number of slots empty'), 1:('STDxxxxxxxxxx', 'number of slots empty'), ... , n:('STDxxxxxxxxxx', 'number of slots empty')"
* ::string update_all(): "RESPONSE CODE: Message, Remarks(if any)"
* ::string update(): "RESPONSE CODE: Message, Remarks(if any)"
* ::string add(): "RESPONSE CODE: Message, STD"
* ::string remove(): "RESPONSE CODE: Message, Remarks(if any)"
*
* BAPI::NETWORK::CYCLE::
*
* ::bool is_present(): 0 or 1
* ::string get_all(): "#NET_CYCS, count:'xxxx', 0:'CYCxxxxxxxxxx', 1:'CYCxxxxxxxxxx', ... n:'CYCxxxxxxxxxx'";
* ::string get(): "#NET_CYC, TIME:'00:00:00,DD/MMM/YYYY', CYC:'CYCxxxxxxxxxx', CYC_STAT:'xxxxxxxxxx', ISSUED:'0 or 1', LOC:'STDxxxxxxxxxx or BIDxxxxxxxxxx', WITH:'BIDxxxxxxxxxx', HEALTH:'xxxxxx'";
* ::string get_available(): "#NET_CYC_AVAILABLE, TIME:'00:00:00, DD/MMM/YYYY', count: 'xxxx', 0:('CYCxxxxxxxxxx', 'STDxxxxxxxxxx'), 1:('CYCxxxxxxxxxx', 'STDxxxxxxxxxx'), ... , n:('CYCxxxxxxxxxx', 'STDxxxxxxxxxx')"
* ::string update_all(): "RESPONSE CODE: Message, Remarks(if any)"
* ::string update(): "RESPONSE CODE: Message, Remarks(if any)"
* ::string add(): "RESPONSE CODE: Message, CYC"
* ::string remove(): "RESPONSE CODE: Message, Remarks(if any)"
*
* BAPI::NETWORK::LOCK::
*
* ::string get_all(): "#NET_LCKS, count:'xxxx', 0:(STDxxxxxxxxxx,LCKxxxxxxxxxx,...LCKxxxxxxxxxx), 1:(STDxxxxxxxxxx,LCKxxxxxxxxxx,...LCKxxxxxxxxxx), ... n:(STDxxxxxxxxxx,LCKxxxxxxxxxx,...LCKxxxxxxxxxx)"
* ::string get(): "#NET_LCK, TIME:'00:00:00,DD/MMM/YYYY', STD:'STDxxxxxxxxxx', OPEN:'0 or 1', ACTIVE:'0 or 1'";
* ::string get_stats(): "#NET_STATS, INCOMPLETE"
* ::string update_all(): "RESPONSE CODE: Message, Remarks(if any)"
* ::string update(): "RESPONSE CODE: Message, Remarks(if any)"
* ::string add(): "RESPONSE CODE: Message, LCK"
* ::string remove(): "RESPONSE CODE: Message, Remarks(if any)"
*
* BAPI::NETWORK::TXN::
*
* ::string get_all_TXN(): "#NET_TXNS, TIME:'00:00:00,DD/MMM/YYYY', count:'xxxx', 0:(TXNxxxxxxxxxx,BIDxxxxxxxxxx,issue or deposit,'00:00:00,DD/MMM/YYYY'), 1:(TXNxxxxxxxxxx,BIDxxxxxxxxxx,issue or deposit,'00:00:00,DD/MMM/YYYY'), ... n:(TXNxxxxxxxxxx,BIDxxxxxxxxxx,issue or deposit,'00:00:00,DD/MMM/YYYY')"
* ::string get_user_TXN(): "#NET_USR_TXN, TIME:'00:00:00,DD/MMM/YYYY', count:'xxxx', 0:(TXNxxxxxxxxxx,txnStatus,issuedAt,overtime), 1:(TXNxxxxxxxxxx,txnStatus,issuedAt,overtime), ... n:(TXNxxxxxxxxxx,txnStatus,issuedAt,overtime)"
* ::string get_stand_TXN(): "#NET_STD_TXN, TIME:'00:00:00,DD/MMM/YYYY', count:'xxxx', 0:(TXNxxxxxxxxxx,BIDxxxxxxxxxx,issue or deposit,'00:00:00,DD/MMM/YYYY'), 1:(TXNxxxxxxxxxx,BIDxxxxxxxxxx,issue or deposit,'00:00:00,DD/MMM/YYYY'), ... n:(TXNxxxxxxxxxx,BIDxxxxxxxxxx,issue or deposit,'00:00:00,DD/MMM/YYYY')"
* ::string get_cycle_TXN(): "#NET_CYC_TXN, TIME:'00:00:00,DD/MMM/YYYY', count:'xxxx', 0:(TXNxxxxxxxxxx,BIDxxxxxxxxxx,issuedAt,'00:00:00,DD/MMM/YYYY'), 1:(TXNxxxxxxxxxx,BIDxxxxxxxxxx,issuedAt,'00:00:00,DD/MMM/YYYY'), ... n:(TXNxxxxxxxxxx,BIDxxxxxxxxxx,issuedAt,'00:00:00,DD/MMM/YYYY')"
* ::string get_TXN(): "#TXN, TXN:'TXNxxxxxxxxxx', ISSUED_AT:'00:00:00,DD/MMM/YYYY', DEPOSIT_AT:'time or NULL', FROM:'STDxxxxxxxxxx', AT:'STDxxxxxxxxxx or NULL', OVERTIME:'00:00:00', COMPLETE:'0 or 1', TXN_STAT:'xxxxxx', NOTE:'xxxxxxxxxxxxxxxxxx'"
*
*/