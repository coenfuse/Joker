#ifndef BAPI_H
#define BAPI_H
#include <string>
#include <JSON.h>

namespace bapi {
	namespace user {
		namespace check {
			bool checkUser(std::string token, char key, std::string username);
			bool login(std::string token, char key, std::string username, std::string password);
			bool logut(std::string token, std::string BID_user);
		}
		namespace get {
			namespace attributes {
				std::string getUsers(std::string token, char usertype);
				std::string getUser(std::string token, std::string BID_requestBy, std::string BID_requestOn);
				std::string getUser(std::string token, std::string bid);
			}
			//namespace messages {}
			//namespace notification {}
			//namespace ticket {}
			//namespace feedback {}
		}
		namespace update {
			namespace attributes {
				bool updateUsers(std::string token, std::string bid, char action);	//Consider removal.
				bool updateUser(std::string token, std::string bid, JSON user);
			}
			//namespace messages {}
			//namespace notification {}
			//namespace ticket {}
			//namespace feedback {}
		}
		namespace post {
			namespace attributes {
				bool postUsers(std::string token, std::string BID_requestBy, char action, JSON* users);	//Consider removal
				bool postUser(std::string token, std::string BID_requestBy, char action, JSON user);
			}
			//namespace messages {}
			//namespace notification {}
			//namespace ticket {}
			//namespace feedback {}
		}
		namespace pop {
			namespace attributes {
				bool popUser(std::string token, std::string BID_requestBy, std::string BID_requestOn, char action);
			}
			//namespace messages {}
			//namespace notification {}
		}
	}
	namespace network {
		namespace check {}
		namespace get {}
		namespace update {}
		namespace post {}
		namespace pop {}
	}
}

#endif // BAPI_H
