#include "..\src\client\util\json\JSON.h"
#include <string>

JSON_net::JSON_net(std::string net_data){
	NET = "xxxxx";				//NET (Network ID)
	TXNhead = "xxxxx";			//Transaction ID Header. All the transactions of this network will start with this header
	admin_count = 1;		//Admins of the network, Minimum 1
	organization = "xxxxx";		//Organization this network is operating in
	netActive = false;				//Boolean value representing whether the network is active or not
	netStatus = "xxxxx";			//Enumerated or String value representing the current state of network, Maintainence, Deactivated, Inactive, Frozen etc
	std_count = 0;			//No. of stands in the network
	cyc_count = 0;			//No. of cycles in the Network
	user_count = 0;		//No. of users in the network
	lock_count = 0;		//No.of locks in the network
	capacity = 0;
}

JSON_net::~JSON_net()
{
}
