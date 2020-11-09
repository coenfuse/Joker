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

/*
#ifndef JSON_H
#define JSON_H

#include<string>
#include<time.h>
#include "..\class\frontObj.h"
#include <map>
#include <vector>
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

class JSON_bulk {
	public:
		JSON_bulk(std::string bulk_data, short key);
		~JSON_bulk();

		std::string getVal(std::string key);

	private:
		std::map<std::string, std::string> data;
};

class JSON_adm
{
public:
	JSON_adm(std::string adm_data);
	~JSON_adm();

private:
	std::string BID = "xxxxx";				//BID of the admin
	std::string AID = "xxxxx";				//AID (Administrator ID or Username)
	std::string NET = "xxxxx";				//Network ID managed by this admin
	bool owner = false;						//Defines whether the admin is owner of the network or not.
	Name name;								//Full name of Admin
	Name guardian;							//Guardian or Parent name of Admin
	std::string dob;						//Date of birth of admin
	bool activeStatus = false;				//Whether account is Active or Inactive
	Phone primaryNum;						//Primary contact number of admin
	Phone secondaryNum;						//Secondary contact number of admin
	Email email;							//Primary email of admin
	Email recoveryEmail;		            //Secondary email of admin
	Address primaryAdd;						//Primary address of admin
	Address secondaryAdd;					//Secondary address of admin
	bool online = false;					//Online status
	std::string accStatus = "xxxxx";		//Status of the account, Disabled, Blocked, Deactivated, Under Review, etc
};

class JSON_stu
{
public:
	JSON_stu(std::string stu_data);
	~JSON_stu();

private:
	std::string BID = "xxxxx";				//BID for the user
	std::string SID = "xxxxx";				//Student's Enrollment no. or College ID
	std::string NET = "xxxxx";				//Network ID of which the student is part of
	bool pendingIssue = false;				//TRUE if has a pending issue, otherwise FALSE
	Name name;								//Name of the student user.
	Name guardian;							//Guardian name of the student user
	std::string dob;						//Date of birth of user
	bool activeStatus = false;				//A boolean value, representing whether account is Active or Inactive
	Phone primaryNum;						//Primary contact number of student user
	Phone secondaryNum;						//Secondary contact number of student user
	Email email;							//Primary email of student user
	Email recoveryEmail;					//Secondary email of student user
	Address primaryAdd;						//Primary address of student user
	Address secondaryAdd;					//Secondary address of student user
	bool online = false;					//Online status
	std::string accStatus = "xxxxx";		//Status of the account, Disabled, Blocked, Deactivated, Under Review, etc
	std::string department = "xxxxx";		//Department this student belongs to
	unsigned int loginCount = 0;			//Total logins made by user in the system
};

class JSON_emp
{
public:
	JSON_emp(std::string emp_data);
	~JSON_emp();

private:
	std::string BID = "xxxxx";				//BID for the user
	std::string EID = "xxxxx";				//Employee's Employement ID
	std::string NET = "xxxxx";				//Network ID of which the employee is part of
	bool pendingIssue = false;				//TRUE if has a pending issue, otherwise FALSE
	Name name;								//Name of the employee user.
	Name guardian;							//Guardian name of the employee user
	Name spouse;							//Spouse name of the employee user
	std::string dob;						//Date of birth of user
	bool activeStatus = false;				//A boolean value, representing whether account is Active or Inactive
	Phone primaryNum;						//Primary contact number of employee user
	Phone secondaryNum;						//Secondary contact number of employee user
	Email email;							//Primary email of employee user
	Email recoveryEmail;					//Secondary email of employee user
	Address primaryAdd;						//Primary address of employee user
	Address secondaryAdd;					//Secondary address of employee user
	bool online = false;					//Online status
	std::string accStatus = "xxxxx";		//Status of the account, Disabled, Blocked, Deactivated, Under Review, etc
	std::string department = "xxxxx";		//Department this employee is employed in
	unsigned int loginCount = 0;			//Total logins made by user in the system
};

class JSON_sup
{
public:
	JSON_sup(std::string sup_data);
	~JSON_sup();

private:
	std::string support;

};

class JSON_mod
{
public:
	JSON_mod(std::string mod_data);
	~JSON_mod();

private:
	std::string moderator;

};

class JSON_guest
{
public:
	JSON_guest(std::string guest_data);
	~JSON_guest();

private:
	std::string guest;

};

class JSON_net
{
public:
	JSON_net(std::string net_data);
	~JSON_net();

private:
	std::string NET = "xxxxx";				//NET (Network ID)
	std::string TXNhead = "xxxxx";			//Transaction ID Header. All the transactions of this network will start with this header
	unsigned int admin_count = 1;		//Admins of the network, Minimum 1
	std::string organization = "xxxxx";		//Organization this network is operating in
	bool netActive = false;				//Boolean value representing whether the network is active or not
	std::string netStatus = "xxxxx";			//Enumerated or String value representing the current state of network, Maintainence, Deactivated, Inactive, Frozen etc
	unsigned int std_count = 0;			//No. of stands in the network
	unsigned int cyc_count = 0;			//No. of cycles in the Network
	unsigned int user_count = 0;		//No. of users in the network
	unsigned int lock_count = 0;		//No.of locks in the network
	unsigned int capacity = 0;				//Capacity of the network, equals to number of slots (locks) available in the network.

};

class JSON_std
{
public:
	JSON_std(std::string std_data);
	~JSON_std();

private:
	std::string STD = "xxxxx";				//STD (Stand ID)
	bool stdActive = false;				//Boolean value representing whether the stand is active or not
	std::string stdStatus = "xxxxx";			//Representing current state of Stand, Disabled, Maintainence, Frozen, etc.
	std::string stdName = "xxxxx";			//The name of the stand. More memorable value
	std::string stdLoc = "xxxxx";			//The location code of the stand
	Coordinate longlat;						//Location Coordinates
	unsigned int stdCapacity = 0;		//Unsigned integer value representing the slots available in the stand
	unsigned int txn_count = 0;			//Consider removing this redundant attribute. This can be calculated on demand.

};

class JSON_cyc
{
public:
	JSON_cyc(std::string cyc_data);
	~JSON_cyc();

private:
	std::string CYC = "xxxxx";				//CYC (Cycle ID)
	std::string cycStatus = "xxxxx";			//Status of the cycle. Disabled, enabled, netActive, Busy (in a process of being returned or issued)
	bool available = false;				//Stores boolean value whether cycle is available for issue or not
	std::string currentLocation = "xxxxx";	//Stores SID if on stand, or BID of user if hired. This attribute would be later replaced with coordinates as GPS shall be implemented
	std::string issuedBy = "xxxxx";			//Stores BID of last or current issuer. NULL if available = TRUE
	std::string cycHealth = "xxxxx";			//The health of the Cycle represented by boolean value. Consider merging in cycStatus attribute.

};

class JSON_lock
{
public:
	JSON_lock(std::string lock_data);
	~JSON_lock();

private:
	std::string LCK = "xxxxx";				//LCK (Lock ID)
	bool lckStatus = false;				//TRUE = Locked, FALSE = Unlocked
	bool able = true;				// Whether the lock is enabled or disabled for normal usage or not.
};

class JSON_txn
{
public:
	JSON_txn(std::string txn_data);
	~JSON_txn();

private:
	std::string TXN = "xxxxx";				//TXN ID of the Transaction
	time_t issuedAt = time(0);				//Time of issue
	time_t depositAt = time(0);				//Time of deposit
	std::string issueFrom = "xxxxx";			//STD of stand from where the cycle is issued
	std::string depositTo = "xxxxx";			//STD of stand from where the cycle is deposited
	time_t overtime = time(0);				//Amount of overtime
	bool complete = true;					//Whether the transaction has completed its cycle. A TXN cycle is from Issue to Deposit back.
	std::string txnStatus = "xxxxx";			//Pending, Late, Stolen, Broken, Normal
	std::string remarks = "xxxxx";			//Any error code or output from system goes here

};

#endif
*/