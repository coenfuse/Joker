#ifndef BAPI_H
#define BAPI_H
#include <string>

/*	RETURN CONVENTIONS
*	
*	bool chk::user(): TRUE or FALSE;
*	string chk::authLogin(): "xxxxxxxxxx";
*	bool chk::logout(): TRUE or FALSE;
* 
*	string get::attr::users():	"#BLK_ADM, 0:(BIDxxxxxxxxxx,Name,AID), 1:(BIDxxxxxxxxxx,Name,AID), ... n:(BIDxxxxxxxxxx,Name,AID)"
*								"#BLK_STU, 0:(BIDxxxxxxxxxx,Name,SID), 1:(BIDxxxxxxxxxx,Name,SID), ... n:(BIDxxxxxxxxxx,Name,SID)"
*								"#BLK_EMP, 0:(BIDxxxxxxxxxx,Name,EID), 1:(BIDxxxxxxxxxx,Name,EID), ... n:(BIDxxxxxxxxxx,Name,EID)"
*								"#BLK_SUP, 0:(BIDxxxxxxxxxx,Name,SUP), 1:(BIDxxxxxxxxxx,Name,SUP), ... n:(BIDxxxxxxxxxx,Name,SUP)"
*								"#BLK_MOD, 0:(BIDxxxxxxxxxx,Name,MOD), 1:(BIDxxxxxxxxxx,Name,MOD), ... n:(BIDxxxxxxxxxx,Name,MOD)"
*								"#BLK_GUE, 0:(BGIDxxxxxxxxxx,Name,Duration), 1:(BGIDxxxxxxxxxx,Name,Duration), ... n:(BGIDxxxxxxxxxx,Name,Duration)"
*	string get::attr::user():	"#ADM, BID:'BIDxxxxxxxxxx', AID:'xxxxxxxxxx', NET:'NETxxxxxxxxxx', OWN:'0 or 1', NAME:'xxxxxxxxxx', GUARDIAN:'xxxxxxxxxx', DOB:'00/MON/0000', ACT_STAT:'0 or 1', PH1:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', PH2:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', EM1:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', EM2:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', ADD1:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), LOC:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ADD2:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), LOC:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ONLINE:'0 or 1', ACC_STAT:'xxxxxxxxxx'"
*								"#STU, BID:'BIDxxxxxxxxxx', SID:'xxxxxxxxxx', NET:'NETxxxxxxxxxx', PEN:'0 or 1', NAME:'xxxxxxxxxx', GUARDIAN:'xxxxxxxxxx', DOB:'00/MON/0000', ACT_STAT:'0 or 1', PH1:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', PH2:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', EM1:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', EM2:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', ADD1:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), LOC:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ADD2:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), LOC:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ONLINE:'0 or 1', ACC_STAT:'xxxxxxxxxx', DEPT:'xxxxxxxxxx', LOGCOUNT:'xxxxxxxxx'"
*								"#EMP, BID:'BIDxxxxxxxxxx', EID:'xxxxxxxxxx', NET:'NETxxxxxxxxxx', OWN:'0 or 1', NAME:'xxxxxxxxxx', GUARDIAN:'xxxxxxxxxx', SPOUSE:'xxxxxxxxxx', DOB:'00/MON/0000', ACT_STAT:'0 or 1', PH1:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', PH2:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', EM1:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', EM2:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', ADD1:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), LOC:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ADD2:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), LOC:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ONLINE:'0 or 1', ACC_STAT:'xxxxxxxxxx', DEPT:'xxxxxxxxxx', LOGCOUNT:'xxxxxxxxx'"
*				//INCOMPLETE	"#SUP, BID:'BIDxxxxxxxxxx', SUP:'xxxxxxxxxx', NET:'NETxxxxxxxxxx', OWN:'0 or 1', NAME:'xxxxxxxxxx', GUARDIAN:'xxxxxxxxxx', DOB:'00/MON/0000', ACT_STAT:'0 or 1', PH1:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', PH2:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', EM1:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', EM2:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', ADD1:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), LOC:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ADD2:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), LOC:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ONLINE:'0 or 1', ACC_STAT:'xxxxxxxxxx'"
*				//INCOMPLETE	"#MOD, BID:'BIDxxxxxxxxxx', MOD:'xxxxxxxxxx', NET:'NETxxxxxxxxxx', OWN:'0 or 1', NAME:'xxxxxxxxxx', GUARDIAN:'xxxxxxxxxx', DOB:'00/MON/0000', ACT_STAT:'0 or 1', PH1:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', PH2:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', EM1:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', EM2:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', ADD1:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), LOC:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ADD2:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), LOC:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ONLINE:'0 or 1', ACC_STAT:'xxxxxxxxxx'"
*				//INCOMPLETE	"#GUE, GID:'BGIDxxxxxxxxxx', Name:'xxxxxxxxxx', START:'00:00,00/00/00', END:'00:00,00/MON/0000', DUR:'00:00:00', IP:'000:000:000'"
* 
*	bool up::attr::users():		TRUE or FALSE;
*	bool up::attr::user():		TRUE or FALSE;
* 
*	bool post::attr::users():	TRUE or FALSE;
*	bool post::attr::user():	TRUE or FALSE;
* 
*	bool pop::attr::user():	TRUE or FALSE;
*/

namespace bapi {

	// USER APIs

	namespace user { // User Functions
		namespace chk { // Check Functions
			bool user(std::string token, short key, std::string username, std::string NET);
			std::string authLogin(std::string token, short key, std::string username, std::string password);
			bool logout(std::string token, std::string BID, std::string data);
		}
		namespace get { // Get Functions
			namespace attr { // Attribute Functions
				std::string users(std::string token, std::string session_code, char usertype);
				std::string user(std::string token, std::string session_code, std::string BID_requestedBy, std::string BID_requested);
				std::string user(std::string token, std::string session_code, std::string bid);
			}
			//namespace msg {}
			//namespace notif {}
			//namespace tkt {}
			//namespace fdbk {}
		}
		namespace up { //Update Functions
			namespace attr { //Attribute Functions
				bool users(std::string token, std::string bid, char action);	//Consider removal.
				bool user(std::string token, std::string bid, JSON user);
			}
			//namespace msg {}
			//namespace notif {}
			//namespace tkt {}
			//namespace fdbk {}
		}
		namespace post { //Post Functions
			namespace attr { //Attribute Functions
				bool users(std::string token, std::string BID_requestBy, char action, JSON* users);	//Consider removal
				bool user(std::string token, std::string BID_requestBy, char action, JSON user);
			}
			//namespace msg {}
			//namespace notif {}
			//namespace tkt {}
			//namespace fdbk {}
		}
		namespace pop { // Post Functions
			namespace attr { // Attribute Functions
				bool user(std::string token, std::string BID_requestBy, std::string BID_requestOn, char action);
			}
			//namespace msg {}
			//namespace notif {}
		}
	}

	// NETWORK APIs

	/*	RETURN CONVENTIONS
*
*	bool chk::user(): TRUE or FALSE;
*	bool chk::net(): TRUE or FALSE;
*	bool chk::owner(): TRUE or FALSE;
*	bool chk::active(): TRUE or FALSE;
*
*	string getUsers():  "#BLK_ADM, 0:(BIDxxxxxxxxxx,Name,AID), 1:(BIDxxxxxxxxxx,Name,AID), ... n:(BIDxxxxxxxxxx,Name,AID)"
*						"#BLK_STU, 0:(BIDxxxxxxxxxx,Name,SID), 1:(BIDxxxxxxxxxx,Name,SID), ... n:(BIDxxxxxxxxxx,Name,SID)"
*						"#BLK_EMP, 0:(BIDxxxxxxxxxx,Name,EID), 1:(BIDxxxxxxxxxx,Name,EID), ... n:(BIDxxxxxxxxxx,Name,EID)"
*						"#BLK_SUP, 0:(BIDxxxxxxxxxx,Name,SUP), 1:(BIDxxxxxxxxxx,Name,SUP), ... n:(BIDxxxxxxxxxx,Name,SUP)"
*						"#BLK_MOD, 0:(BIDxxxxxxxxxx,Name,MOD), 1:(BIDxxxxxxxxxx,Name,MOD), ... n:(BIDxxxxxxxxxx,Name,MOD)"
*						"#BLK_GUE, 0:(BGIDxxxxxxxxxx,Name,Duration), 1:(BGIDxxxxxxxxxx,Name,Duration), ... n:(BGIDxxxxxxxxxx,Name,Duration)"
*	string getUser():	"#ADM, BID:'BIDxxxxxxxxxx', AID:'xxxxxxxxxx', NET:'NETxxxxxxxxxx', OWN:'0 or 1', NAME:'xxxxxxxxxx', GUARDIAN:'xxxxxxxxxx', DOB:'00/MON/0000', ACT_STAT:'0 or 1', PH1:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', PH2:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', EM1:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', EM2:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', ADD1:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), LOC:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ADD2:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), LOC:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ONLINE:'0 or 1', ACC_STAT:'xxxxxxxxxx'"
*						"#STU, BID:'BIDxxxxxxxxxx', SID:'xxxxxxxxxx', NET:'NETxxxxxxxxxx', PEN:'0 or 1', NAME:'xxxxxxxxxx', GUARDIAN:'xxxxxxxxxx', DOB:'00/MON/0000', ACT_STAT:'0 or 1', PH1:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', PH2:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', EM1:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', EM2:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', ADD1:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), LOC:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ADD2:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), LOC:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ONLINE:'0 or 1', ACC_STAT:'xxxxxxxxxx', DEPT:'xxxxxxxxxx', LOGCOUNT:'xxxxxxxxx'"
*						"#EMP, BID:'BIDxxxxxxxxxx', EID:'xxxxxxxxxx', NET:'NETxxxxxxxxxx', OWN:'0 or 1', NAME:'xxxxxxxxxx', GUARDIAN:'xxxxxxxxxx', SPOUSE:'xxxxxxxxxx', DOB:'00/MON/0000', ACT_STAT:'0 or 1', PH1:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', PH2:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', EM1:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', EM2:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', ADD1:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), LOC:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ADD2:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), LOC:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ONLINE:'0 or 1', ACC_STAT:'xxxxxxxxxx', DEPT:'xxxxxxxxxx', LOGCOUNT:'xxxxxxxxx'"
*		//INCOMPLETE	"#SUP, BID:'BIDxxxxxxxxxx', SUP:'xxxxxxxxxx', NET:'NETxxxxxxxxxx', OWN:'0 or 1', NAME:'xxxxxxxxxx', GUARDIAN:'xxxxxxxxxx', DOB:'00/MON/0000', ACT_STAT:'0 or 1', PH1:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', PH2:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', EM1:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', EM2:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', ADD1:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), LOC:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ADD2:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), LOC:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ONLINE:'0 or 1', ACC_STAT:'xxxxxxxxxx'"
*		//INCOMPLETE	"#MOD, BID:'BIDxxxxxxxxxx', MOD:'xxxxxxxxxx', NET:'NETxxxxxxxxxx', OWN:'0 or 1', NAME:'xxxxxxxxxx', GUARDIAN:'xxxxxxxxxx', DOB:'00/MON/0000', ACT_STAT:'0 or 1', PH1:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', PH2:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', EM1:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', EM2:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', ADD1:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), LOC:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ADD2:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), LOC:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ONLINE:'0 or 1', ACC_STAT:'xxxxxxxxxx'"
*		//INCOMPLETE	"#GUE, GID:'BGIDxxxxxxxxxx', Name:'BGIDxxxxxxxxxx', START:'00:00,00/00/00', END:'00:00,00/MON/0000', DUR:'00:00:00', IP:'000:000:000'"
*
*	bool updateUsers():	TRUE or FALSE;
*	bool updateUser():	TRUE or FALSE;
*
*	bool postUsers():	TRUE or FALSE;
*	bool postUser():	TRUE or FALSE;
*
*	bool popUser():		TRUE or FALSE;
*/

	namespace net { // Network Functions
		namespace chk { // Check Functions
			bool net(std::string token, std::string NET);
			bool user(std::string token, short key, std::string NET, std::string BID);
			bool owner(std::string token, std::string NET, std::string BID);
			bool active(std::string token, std::string NET);
		}
		namespace get {
			std::string net(std::string token, std::string NET, std::string BID);
			std::string stat(std::string token, std::string NET, std::string BID);
			std::string admins(std::string token, std::string NET, std::string BID);
			std::string owner(std::string token, std::string NET, std::string BID);

			std::string stands(std::string token, std::string NET, std::string BID);
			std::string stand(std::string token, std::string NET, std::string STD, std::string BID);
			std::string standStat(std::string token, std::string NET, std::string STD, std::string BID);
			std::string nearestStand(std::string token, std::string NET, std::string LOC, std::string BID);
			int standDistance(std::string token, std::string NET, std::string STD1, std::string STD2, std::string BID);

			std::string cycles(std::string token, std::string NET, std::string BID);
			std::string cycle(std::string token, std::string NET, std::string CYC);
			std::string freeCycles(std::string token, std::string NET, std::string BID);
				
			std::string locks(std::string token, std::string NET, std::string BID);
			std::string lock(std::string token, std::string NET, std::string LCK, std::string BID);
		}
		namespace up {
			bool net(std::string token, std::string NET, std::string BID, short action, std::string data);

			bool stands(std::string token, std::string NET, std::string BID, short action, std::string data);
			bool stand(std::string token, std::string NET, std::string BID, short action, std::string STD, std::string data);

			bool cycles(std::string token, std::string NET, std::string BID, short action, std::string data);
			bool cycle(std::string token, std::string NET, std::string BID, short action, std::string CYC, std::string data);

			bool locks(std::string token, std::string NET, std::string BID, short action, std::string data);
			bool lock(std::string token, std::string NET, std::string BID, short action, std::string LCK, std::string data);
		}
		namespace post {
			std::string net(std::string token, std::string BID, std::string data);

			bool stand(std::string token, std::string BID, std::string NET, std::string data);

			bool cycle(std::string token, std::string BID, std::string NET, std::string data);

			bool lock(std::string token, std::string BID, std::string NET, std::string STD, std::string data);
		}
		namespace pop {
			bool net(std::string token, std::string BID, std::string NET);

			bool stand(std::string token, std::string BID, std::string NET, std::string STD);

			bool cycle(std::string token, std::string BID, std::string NET, std::string CYC);

			bool lock(std::string token, std::string BID, std::string NET, std::string STD, std::string LCK);
		}
	}
}

#endif // BAPI_H
