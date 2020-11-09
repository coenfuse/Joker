// JSON template wrapper definition

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

// Sample User Data

// "BID:'BID016', TYPE:'STU', IS_ACTIVE:'F', ONLINE:'F', ACCOUNT_STAT:'1',
// PROFILE_COMPLETE:'F', LOG_COUNT:'685', NET:'NET100', OWN:'F', SID:'2017-310-132',
// NET:'NET100', PEN:'0', NAME:'Owen Goldston', GUARDIAN:'Saleem Longford',
// DOB:'14/JAN/1994', GENDER:'M', PH1:'CODE:(972), NUM:(9477757029)', PH2:'CODE:(86),
// NUM:(2114977381)', EM1:'HEAD:(slongfordc), HOST:(digg.com)', EM2:'HEAD:(slongfordc),
// HOST:(woothemes.com)', ADD1:'HNO:(51775), BLO:(S), COL:(Buena Vista Park), LAN:NULL,
// AREA:NULL, CIT:NULL, STA:NULL, COU:NULL, PIN:NULL', ADD2==ADD1:'F', ADD2:'HNO:(245), BLO:(H),
// COL:NULL, LAN:NULL, AREA:(Lillian Hill), CIT:NULL, STA:NULL, COU:NULL, PIN:NULL', DEPT:'Sales'"

#pragma once
#include <string>

class JSON {
private:
	// Private Variables
	std::string m_prefix = "null";
	std::string m_type = "empty";
	size_t m_default_tags = 0;
	size_t m_custom_tags = 0;
	// vector default_tag_list[]
	// vector custom_tag_list[]

	struct Tag {
		std::string TAG_NAME;
		std::string tag_data;
		Tag* previous_tag = nullptr;
		Tag* next_Tag = nullptr;
	};

private:
	// Private Methods
	JSON() {
		// Default Constructor
		// Declaring in private section so user is forced to user parameterized.
	}

	void init_ALL_ADM();
	void init_ALL_SUP();
	void init_ALL_MOD();
	void init_ALL_STU();
	void init_ALL_EMP();
	void init_ALL_GUE();
	void init_ALL_NET();
	void init_ALL_STD();
	void init_ALL_CYC();
	void init_ALL_LCK();
	void init_ALL_TXN();

	void init_ATR_ADM();
	void init_ATR_SUP();
	void init_ATR_MOD();
	void init_ATR_STU();
	void init_ATR_EMP();
	void init_ATR_GUE();

	void init_NET_STAT();
	void init_NET_ADMS();
	void init_NET_OWN();

	void init_NET_STD();
	void init_NET_STD_STAT();
	void init_NET_NEAR_STD();
	void init_NET_STD_VACANT();

	void init_NET_CYC();
	void init_NET_CYC_FREE();

	void init_NET_LCK();
	void init_NET_LCK_STAT();

	void init_TXN();
	void init_NET_USR_TXN();
	void init_NET_STD_TXN();
	void init_NET_CYC_TXN();

	void m_add_tag(std::string tag_to_add, std::string data_for_tag);
	void m_remove_tag(std::string tag_to_remove);

public:
	// Public Variables
	enum Type{
		// Use if want to create JSON list of all Admins.
		ALL_ADM,
		// Use if want to create JSON list of all Support agents.
		ALL_SUP,
		// Use if want to create JSON list of all Moderators.
		ALL_MOD,
		// Use if want to create JSON list of all Students.
		ALL_STU,
		// Use if want to create JSON list of all Employees.
		ALL_EMP,
		// Use if want to create JSON list of all Guests.
		ALL_GUE,
		// Use if want to create JSON list of all Networks.
		ALL_NET,
		// Use if want to create JSON list of all Stands.
		ALL_STD,
		// Use if want to create JSON list of all Cycles.
		ALL_CYC,
		// Use if want to create JSON list of all Locks.
		ALL_LCK,
		// Use if want to create JSON list of all Transactions.
		ALL_TXN,

		// Use if want to create JSON for Admin's data.
		ATR_ADM,
		// Use if want to create JSON for Support agent's data.
		ATR_SUP,
		// Use if want to create JSON for Moderator's data.
		ATR_MOD,
		// Use if want to create JSON for Student's data.
		ATR_STU,
		// Use if want to create JSON for Employee's data.
		ATR_EMP,
		// Use if want to create JSON for Guest's data.
		ATR_GUE,

		// Use if want to create JSON for Network's data.
		NET_STAT,
		// Use if want to create JSON list for Admins of a Network.
		NET_ADMS,
		// Use if want to create JSON list for Owner of a Network.
		NET_OWN,

		// Use if want to create JSON for basic Stand's data.
		NET_STD,
		// Use if want to create JSON for advanced Stand's data.
		NET_STD_STAT,
		// Use if want to create JSON for Nearest Stands.
		NET_NEAR_STD,
		// Use if want to create JSON for Vacant Stands.
		NET_STD_VACANT,

		// Use if want to create JSON for Cycle's data.
		NET_CYC,
		// Use if want to create JSON for Available Cycles.
		NET_CYC_FREE,

		// Use if want to create JSON for basic Lock's data.
		NET_LCK,
		// Use if want to create JSON for advanced Lock's data.
		NET_LCK_STAT,

		// Use if want to create JSON for Transaction data.
		TXN,
		// Use if want to create JSON for User's Transaction data.
		NET_USR_TXN,
		// Use if want to create JSON for Stand's Transaction data.
		NET_STD_TXN,
		// Use if want to create JSON for Cycle's Transaction data.
		NET_CYC_TXN
	};
public:
	// Public Methods
	~JSON();
	JSON(Type wrapper_type);

	std::string at();
	std::string add(std::string custom_tag);
	std::string add(std::string custom_tag, std::string data);
	std::string empty_tags();
	void fill_empty_tags(std::string fill_with = "0");
	bool has_empty_tag();
	size_t length();
	void remove(std::string to_remove_tag);
	std::string serialize();
	std::string tag_list();
	std::string type();
};
