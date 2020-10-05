//JSON works as a redundant (underlined) management tool.
//It just parses the strings received from bapi.h into useful chunks of trivial data types.
//The JSON object can then be passed to initialize the higher objects such as Admin and Users.
//JSON removes the requirement of translating recevived strings by the higher objects so that they can focus on other important stuff.
//It also helps in separting a specific part of the code so that it can be debugged later on.
/*
Example Usage:
...
JSON j_Network(getNetwork(par1, par2, ...),key);
Network network(j_Network);

in implementation it should simplify initialization as

Network::network(JSON j_Network){
	attribute1 = j_Network.getAttr1();
	attribute2 = j_Network.getAttr2();
	attribute3 = j_Network.getAttr3();
	...
}
*/

#ifndef JSON_H
#define JSON_H

#include<string>
#include "bisystem.h"
#include<time.h>
//#include<ctime>

class JSON
{
	private:
		// Attributes Unique to User
		std::string BID = "xxxxx";				//BID for the user
		Name name;
		Name guardian;
		std::string dob;					//Date of birth of user
		bool activeStatus = false;			//A boolean value, representing whether account is Active or Inactive
		Phone primaryNum;
		Phone secondaryNum;
		Email email;				//Primary Email
		Email recoveryEmail;		//Secondary Email
		Address primaryAdd;
		Address secondaryAdd;
		bool online = false;			//Boolean value, showing online status
		std::string accStatus = "xxxxx";			//Status of the account, Disabled, Blocked, Deactivated, Under Review, etc

		// Attributes Unique to Admin
		std::string AID = "xxxxx";				//AID (Administrator ID or Username)
		bool owner = false;					//A bool value, attribute of Admin object

		// Attributes Unique to User(Student)
		std::string SID = "xxxxx";				//Stores student's Enrollment no.
		bool issueStatus = false;			//TRUE if has a pending issue, otherwise FALSE
		std::string department = "xxxxx";
		unsigned int loginCount = 0;

		// Attributes Unique to User(Employee)
		std::string EID = "xxxxx";				//Stores employee's Employee ID

		// Attributes Unique to Network
		std::string NET = "xxxxx";				//NET (Network ID)
		std::string TXNhead = "xxxxx";			//Transaction ID Header. All the transactions of this network will start with this header
		unsigned int admin_count = 1;		//Admins of the network, Minimum 1
		std::string organization = "xxxxx";		//Organization this network is operating in
		bool netActive = false;				//Boolean value representing whether the network is active or not
		std::string netStatus = "xxxxx";			//Enumerated or String value representing the current state of network, Maintainence, Deactivated, Inactive, Frozen etc
		unsigned int std_count = 0;			//No. of stands in the network
		unsigned int cyc_count = 0;			//No. of cycles in the Network
		unsigned int user_count = 0;		//No. of users in the network

		// Attributes Unique to Stand
		std::string STD = "xxxxx";				//STD (Stand ID)
		bool stdActive = false;				//Boolean value representing whether the stand is active or not
		std::string stdStatus = "xxxxx";			//Representing current state of Stand, Disabled, Maintainence, Frozen, etc.
		std::string stdName = "xxxxx";			//The name of the stand. More memorable value
		std::string stdLoc = "xxxxx";			//The location code of the stand
		unsigned int stdCapacity = 0;		//Unsigned integer value representing the slots available in the stand
		unsigned int txn_count = 0;			//Consider removing this redundant attribute. This can be calculated on demand.

		// Attributes Unique to Cycle
		std::string CYC = "xxxxx";				//CYC (Cycle ID)
		std::string cycStatus = "xxxxx";			//Status of the cycle. Disabled, enabled, netActive, Busy (in a process of being returned or issued)
		bool available = false;				//Stores boolean value whether cycle is available for issue or not
		std::string currentLocation = "xxxxx";	//Stores SID if on stand, or BID of user if hired. This attribute would be later replaced with coordinates as GPS shall be implemented
		std::string issuedBy = "xxxxx";			//Stores BID of last or current issuer. NULL if available = TRUE
		std::string cycHealth = "xxxxx";			//The health of the Cycle represented by boolean value. Consider merging in cycStatus attribute.

		// Attributes Unique to Lock
		std::string LCK = "xxxxx";				//LCK (Lock ID)
		bool lckStatus = false;				//TRUE = Locked, FALSE = Unlocked

		// Attributes Unique to Transaction
		std::string TXN = "xxxxx";				//TXN ID of the Transaction
		time_t issuedAt = time(0);				//Time of issue
		time_t depositAt = time(0);				//Time of deposit
		std::string issueFrom = "xxxxx";			//STD of stand from where the cycle is issued
		std::string depositTo = "xxxxx";			//STD of stand from where the cycle is deposited
		time_t overtime = time(0);				//Amount of overtime
		std::string txnStatus = "xxxxx";			//Late, Stolen, Broken, Normal
		std::string remarks = "xxxxx";			//Any error code or output from system goes here

	public:
		JSON(std::string, int);
		~JSON();
	protected:
};

#endif
