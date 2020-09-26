#ifndef JSON_H
#define JSON_H

class JSON{
	private:
		// Attributes Unique to User
		string BID = "xxxxx";				//BID for the user
		string fname = "xxxxx";				//First name of User object
		string mname= "xxxxx";				//Middle name of User object
		string lname = "xxxxx";				//Last name of User object
		string fguardian = "xxxxx";			//First name of User's guardian
		string mguardian = "xxxxx";			//Middle name of User's guardian
		string lguardian = "xxxxx";			//Last name of User's guardian
		string dob = "xxxxx";				//Date of birth of user
		string activeStatus = "xxxxx";		//A boolean value, representing whether account is Active or Inactive
		string phone = "xxxxx";				//Phone Number
		string email = "xxxxx";				//Primary Email
		string recoveryEmail = "xxxxx";		//Secondary Email
		string houseNo = "xxxxx";			//User house number of Primary residence
		string locality = "xxxxx";			//User locality of Primary residence
		string landmark = "xxxxx";			//User landmark of Primary residence
		string location = "xxxxx";			//User location of Primary residence
		string city = "xxxxx";				//User city of Primary residence
		string state = "xxxxx";				//User state of Primary residence
		string country = "xxxxx";			//User country of Primary residence
		string pincode = "xxxxx";			//User pincode of Primary residence
		string c_houseNo = "xxxxx";			//User house number of Secondary residence
		string c_locality = "xxxxx";		//User locality of Secondary residence
		string c_landmark = "xxxxx";		//User landmark of Secondary residence
		string c_location = "xxxxx";		//User location of Secondary residence
		string c_city = "xxxxx";			//User city of Secondary residence
		string c_state = "xxxxx";			//User state of Secondary residence
		string c_country = "xxxxx";			//User country of Secondary residence
		string c_pincode = "xxxxx";			//User pincode of Secondary residence
		string online = "xxxxx";			//Boolean value, showing online status
		string accStatus = "xxxxx";			//Status of the account, Disabled, Blocked, Deactivated, Under Review, etc

		// Attributes Unique to Admin

		string AID = "xxxxx";				//AID (Administrator ID or Username)
		string owner = "xxxxx";				//A bool value, attribute of Admin object

		// Attributes Unique to User(Student)
		string SID = "xxxxx";
		string issueStatus = "xxxxx";
		string department = "xxxxx";
		string loginCount = "xxxxx";

		// Attributes Unique to User(Employee)

		// Attributes Unique to Network
		string NET = "xxxxx";				//NET (Network ID)
		string TXNhead = "xxxxx";			//Transaction ID Header. All the transactions of this network will start with this header
		string admin_count = "xxxxx";		//Admins of the network
		string organization = "xxxxx";		//Organization this network is operating in
		string netActive = "xxxxx";			//Boolean value representing whether the network is active or not
		string netStatus = "xxxxx";			//Enumerated value representing the current state of network, Maintainence, Deactivated, Inactive, Frozen etc
		string std_count = "xxxxx";			//No. of stands in the network
		string cyc_count = "xxxxx";			//No. of cycles in the Network
		string user_count = "xxxxx";		//No. of users in the network

		// Attributes Unique to Stand
		string STD = "xxxxx";				//STD (Stand ID)
		string stdActive = "xxxxx";			//Boolean value representing whether the stand is active or not
		string stdStatus = "xxxxx";			//Representing current state of Stand, Disabled, Maintainence, Frozen, etc.
		string stdName = "xxxxx";			//The name of the stand. More memorable value
		string stdLoc = "xxxxx";				//The location code of the stand
		string stdCapacity = "xxxxx";		//Unsigned integer value representing the slots available in the stand
		string txn_count = "xxxxx";			//Consider removing this redundant attribute. This can be calculated on demand.

		// Attributes Unique to Cycle
		string CYC = "xxxxx";				//CYC (Cycle ID)
		string cycStatus = "xxxxx";			//Status of the cycle. Disabled, enabled, netActive, Busy (in a process of being returned or issued)
		string available = "xxxxx";			//Stores boolean value whether cycle is available for issue or not
		string currentLocation = "xxxxx";	//Stores SID if on stand, or BID of user if hired. This attribute would be later replaced with coordinates as GPS shall be implemented
		string issuedBy = "xxxxx";			//Stores BID of last or current issuer.
		string cycHealth = "xxxxx";			//The health of the Cycle represented by boolean value. Consider merging in cycStatus attribute.

		// Attributes Unique to Lock
		string LCK = "xxxxx";				//LCK (Lock ID)
		string lckStatus = "xxxxx";			//Locked or Opened

		// Attributes Unique to Transaction
		string TXN = "xxxxx";				//TXN ID of the Transaction
		string issuedAt = "xxxxx";			//Time of issue
		string depositAt = "xxxxx";			//Time of issue
		string issueFrom = "xxxxx";			//STD of stand from where the cycle is issued
		string depositTo = "xxxxx";			//STD of stand from where the cycle is deposited
		string overtime = "xxxxx";			//Amount of overtime
		string txnStatus = "xxxxx";			//Late, Stolen, Broken, Normal
		string remarks = "xxxxx";			//Any error code or output from system goes here

	public:
		//JSON(string, string, string);
	protected:
};

#endif
