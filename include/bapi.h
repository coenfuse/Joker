#ifndef BAPI_H
#define BAPI_H
#include <string>
#include <JSON.h>

namespace bapi {
	namespace user { // User Functions
		namespace chk { // Check Functions
			bool checkUser(std::string token, short key, std::string username, std::string net);
			std::string authLogin(std::string token, short key, std::string username, std::string password);
			bool logout(std::string token, std::string BID_user, JSON data);
		}
		namespace get { // Get Functions
			namespace atr { // Attribute Functions
				std::string getUsers(std::string token, std::string session_code, char usertype);
				std::string getUser(std::string token, std::string session_code, std::string BID_requestBy, std::string BID_requestOn);
				std::string getUser(std::string token, std::string session_code, std::string bid);
			}
			//namespace msg {}
			//namespace notif {}
			//namespace tkt {}
			//namespace fdbk {}
		}
		namespace up { //Update Functions
			namespace atr { //Attribute Functions
				bool updateUsers(std::string token, std::string bid, char action);	//Consider removal.
				bool updateUser(std::string token, std::string bid, JSON user);
			}
			//namespace msg {}
			//namespace notif {}
			//namespace tkt {}
			//namespace fdbk {}
		}
		namespace post { //Post Functions
			namespace atr { //Attribute Functions
				bool postUsers(std::string token, std::string BID_requestBy, char action, JSON* users);	//Consider removal
				bool postUser(std::string token, std::string BID_requestBy, char action, JSON user);
			}
			//namespace msg {}
			//namespace notif {}
			//namespace tkt {}
			//namespace fdbk {}
		}
		namespace pop { // Post Functions
			namespace atr { // Attribute Functions
				bool popUser(std::string token, std::string BID_requestBy, std::string BID_requestOn, char action);
			}
			//namespace msg {}
			//namespace notif {}
		}
	}
	namespace net { // Network Functions
		namespace chk { // Check Functions
			bool searchObj(std::string token, short key, std::string NET, std::string BID);
		}
		namespace get {}
		namespace up {}
		namespace post {}
		namespace pop {}
	}
}

#endif // BAPI_H
