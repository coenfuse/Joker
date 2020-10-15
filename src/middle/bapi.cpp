#include <bapi.h>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <map>
#include "..\src\middle\token.h"

#define TEST	// Set this TEST to RELASE to unload the system from testing mode.

#ifdef TEST
	
// Local Variables

Token token;
std::map<std::string, std::string> NET100_data = {
	{"BID001","BID:'BID001', AID:'vilidutt', NET:'NET100', OWN:'1', NAME:'Villi Dutt Jr.', GUARDIAN:'Villi Dutt', DOB:'02/NOV/2001', ACT_STAT:'1', PH1:'CODE:(91), NUM:(7892561425)', PH2:'CODE:(91), NUM:(9982998175)', EM1:'HEAD:(villionly), HOST:(gmail.com)', EM2:'HEAD:(villiduttjr), HOST:(outlook.com)', ADD1:'HNO:(16), BLO:(H), COL:(Wazira), LAN:(FICCI), AREA:(Barakhamba), CIT:(New Delhi), STA:(Delhi), COU:(India), PIN:(110001)', ADD2==ADD1:'1', ADD2:'HNO:(16), BLO:(H), COL:(Wazira), LAN:(FICCI), AREA:(Barakhamba), CIT:(New Delhi), STA:(Delhi), COU:(India), PIN:(110001)', ONLINE:'1', ACC_STAT:'enabled'"},
	{"BID002","BID:'BID002', AID:'armelo', NET:'NET100', OWN:'0', NAME:'Amara Konzuke', GUARDIAN:'Noriyuki Haga', DOB:'26/MAR/1996', ACT_STAT:'1', PH1:'CODE:(91), NUM:(8452365789)', PH2:'CODE:(91), NUM:(9236785165)', EM1:'HEAD:(amara), HOST:(gmail.com)', EM2:'HEAD:(smallpox), HOST:(outlook.com)', ADD1:'HNO:(16), BLO:(H), COL:(Wazira), LAN:(FICCI), AREA:(Barakhamba), CIT:(New Delhi), STA:(Delhi), COU:(India), PIN:(110001)', ADD2==ADD1:'1', ADD2:'HNO:(16), BLO:(H), COL:(Wazira), LAN:(FICCI), AREA:(Barakhamba), CIT:(New Delhi), STA:(Delhi), COU:(India), PIN:(110001)', ONLINE:'0', ACC_STAT:'enabled'"},
	{"BID003","BID:'BID003', AID:'armanza', NET:'NET100', OWN:'0', NAME:'Arman Mullick', GUARDIAN:'Javedd Mullick', DOB:'01/APR/1999', ACT_STAT:'1', PH1:'CODE:(91), NUM:(9153179289)', PH2:'CODE:(91), NUM:(9851265758)', EM1:'HEAD:(armanmullick), HOST:(gmail.com)', EM2:'HEAD:(armanmere), HOST:(outlook.com)', ADD1:'HNO:(16), BLO:(H), COL:(Wazira), LAN:(FICCI), AREA:(Barakhamba), CIT:(New Delhi), STA:(Delhi), COU:(India), PIN:(110001)', ADD2==ADD1:'1', ADD2:'HNO:(16), BLO:(H), COL:(Wazira), LAN:(FICCI), AREA:(Barakhamba), CIT:(New Delhi), STA:(Delhi), COU:(India), PIN:(110001)', ONLINE:'0', ACC_STAT:'enabled'"},
	{"BID004","BID:'BID004', AID:'zakajuda', NET:'NET100', OWN:'0', NAME:'Zaka Juda', GUARDIAN:'Zaka', DOB:'06/OCT/1988', ACT_STAT:'1', PH1:'CODE:(91), NUM:(9256142585)', PH2:'CODE:(91), NUM:(9981759982)', EM1:'HEAD:(zakajuda), HOST:(hotmail.com)', EM2:'HEAD:(judaizaka), HOST:(outlook.com)', ADD1:'HNO:(16), BLO:(H), COL:(Wazira), LAN:(FICCI), AREA:(Barakhamba), CIT:(New Delhi), STA:(Delhi), COU:(India), PIN:(110001)', ADD2==ADD1:'1', ADD2:'HNO:(16), BLO:(H), COL:(Wazira), LAN:(FICCI), AREA:(Barakhamba), CIT:(New Delhi), STA:(Delhi), COU:(India), PIN:(110001)', ONLINE:'1', ACC_STAT:'enabled'"},
	{"BID005","BID:'BID005', AID:'coenfuse', NET:'NET100', OWN:'0', NAME:'Fonken Bhattacharya', GUARDIAN:'Swami Miheer Bhattacharya', DOB:'08/FEB/2002', ACT_STAT:'1', PH1:'CODE:(91), NUM:(9717268459)', PH2:'CODE:(91), NUM:(8175998299)', EM1:'HEAD:(coenfuse), HOST:(gmail.com)', EM2:'HEAD:(fonken), HOST:(outlook.com)', ADD1:'HNO:(16), BLO:(H), COL:(Wazira), LAN:(FICCI), AREA:(Barakhamba), CIT:(New Delhi), STA:(Delhi), COU:(India), PIN:(110001)', ADD2==ADD1:'1', ADD2:'HNO:(16), BLO:(H), COL:(Wazira), LAN:(FICCI), AREA:(Barakhamba), CIT:(New Delhi), STA:(Delhi), COU:(India), PIN:(110001)', ONLINE:'0', ACC_STAT:'disabled'"},
	{"BID006","BID:'BID006', AID:'larochey', NET:'NET100', OWN:'0', NAME:'Laro Paul Bendiek', GUARDIAN:'Christian Bendiek', DOB:'11/DEC/1998', ACT_STAT:'1', PH1:'CODE:(91), NUM:(7142589256)', PH2:'CODE:(91), NUM:(9759829981)', EM1:'HEAD:(larochan), HOST:(gmail.com)', EM2:'HEAD:(danydaniel), HOST:(outlook.com)', ADD1:'HNO:(16), BLO:(H), COL:(Wazira), LAN:(FICCI), AREA:(Barakhamba), CIT:(New Delhi), STA:(Delhi), COU:(India), PIN:(110001)', ADD2==ADD1:'1', ADD2:'HNO:(16), BLO:(H), COL:(Wazira), LAN:(FICCI), AREA:(Barakhamba), CIT:(New Delhi), STA:(Delhi), COU:(India), PIN:(110001)', ONLINE:'1', ACC_STAT:'reported'"},
	{"BID007","BID:'BID007', SID:'2017-310-123', NET:'NET100', PEN:'0', NAME:'Sarthak Sharma', GUARDIAN:'Om Prakash Sharma', DOB:'11/FEB/1999', ACT_STAT:'1', PH1:'CODE:(91), NUM:(8153338479)', PH2:'CODE:(91), NUM:(8606157348)', EM1:'HEAD:(iamthedeveloper), HOST:(gmail.com)', EM2:'HEAD:(contactherebitch), HOST:(outlook.com)', ADD1:'HNO:(16), BLO:(H), COL:(Depression), LAN:(FICCI), AREA:(Manhoos Corner), CIT:(New Delhi), STA:(Delhi), COU:(India), PIN:(110001)', ADD2==ADD1:'1', ADD2:'HNO:(16), BLO:(H), COL:(Wazira), LAN:(FICCI), AREA:(Barakhamba), CIT:(New Delhi), STA:(Delhi), COU:(India), PIN:(110001)', ONLINE:'0', ACC_STAT:'Under Investigation', DEPT:'SEST', LOGCOUNT:'28'"},
	{"BID008","BID:'BID008', SID:'2017-310-124', NET:'NET100', PEN:'0', NAME:'Mere Mortal', GUARDIAN:'Om Prakash Sharma', DOB:'11/FEB/1999', ACT_STAT:'1', PH1:'CODE:(91), NUM:(8153338479)', PH2:'CODE:(91), NUM:(8606157348)', EM1:'HEAD:(iamthedeveloper), HOST:(gmail.com)', EM2:'HEAD:(contactherebitch), HOST:(outlook.com)', ADD1:'HNO:(16), BLO:(H), COL:(Depression), LAN:(FICCI), AREA:(Manhoos Corner), CIT:(New Delhi), STA:(Delhi), COU:(India), PIN:(110001)', ADD2==ADD1:'1', ADD2:'HNO:(16), BLO:(H), COL:(Wazira), LAN:(FICCI), AREA:(Barakhamba), CIT:(New Delhi), STA:(Delhi), COU:(India), PIN:(110001)', ONLINE:'0', ACC_STAT:'Under Investigation', DEPT:'SEST', LOGCOUNT:'21'"},
	{"BID009","BID:'BID009', SID:'2017-310-125', NET:'NET100', PEN:'0', NAME:'Other Mere Mortal', GUARDIAN:'Om Prakash Sharma', DOB:'11/FEB/1999', ACT_STAT:'1', PH1:'CODE:(91), NUM:(8153338479)', PH2:'CODE:(91), NUM:(8606157348)', EM1:'HEAD:(iamthedeveloper), HOST:(gmail.com)', EM2:'HEAD:(contactherebitch), HOST:(outlook.com)', ADD1:'HNO:(16), BLO:(H), COL:(Depression), LAN:(FICCI), AREA:(Manhoos Corner), CIT:(New Delhi), STA:(Delhi), COU:(India), PIN:(110001)', ADD2==ADD1:'1', ADD2:'HNO:(16), BLO:(H), COL:(Wazira), LAN:(FICCI), AREA:(Barakhamba), CIT:(New Delhi), STA:(Delhi), COU:(India), PIN:(110001)', ONLINE:'1', ACC_STAT:'enabled', DEPT:'SEST', LOGCOUNT:'38'"},
	{"BID010","BID:'BID010', SID:'2017-310-126', NET:'NET100', PEN:'0', NAME:'Another Mere Mortal', GUARDIAN:'Om Prakash Sharma', DOB:'11/FEB/1999', ACT_STAT:'1', PH1:'CODE:(91), NUM:(8153338479)', PH2:'CODE:(91), NUM:(8606157348)', EM1:'HEAD:(iamthedeveloper), HOST:(gmail.com)', EM2:'HEAD:(contactherebitch), HOST:(outlook.com)', ADD1:'HNO:(16), BLO:(H), COL:(Depression), LAN:(FICCI), AREA:(Manhoos Corner), CIT:(New Delhi), STA:(Delhi), COU:(India), PIN:(110001)', ADD2==ADD1:'1', ADD2:'HNO:(16), BLO:(H), COL:(Wazira), LAN:(FICCI), AREA:(Barakhamba), CIT:(New Delhi), STA:(Delhi), COU:(India), PIN:(110001)', ONLINE:'0', ACC_STAT:'Disabled', DEPT:'SEST', LOGCOUNT:'2'"},
	{"BID011","BID:'BID011', SID:'2017-310-127', NET:'NET100', PEN:'0', NAME:'Basic Mere Mortal', GUARDIAN:'Om Prakash Sharma', DOB:'11/FEB/1999', ACT_STAT:'1', PH1:'CODE:(91), NUM:(8153338479)', PH2:'CODE:(91), NUM:(8606157348)', EM1:'HEAD:(iamthedeveloper), HOST:(gmail.com)', EM2:'HEAD:(contactherebitch), HOST:(outlook.com)', ADD1:'HNO:(16), BLO:(H), COL:(Depression), LAN:(FICCI), AREA:(Manhoos Corner), CIT:(New Delhi), STA:(Delhi), COU:(India), PIN:(110001)', ADD2==ADD1:'1', ADD2:'HNO:(16), BLO:(H), COL:(Wazira), LAN:(FICCI), AREA:(Barakhamba), CIT:(New Delhi), STA:(Delhi), COU:(India), PIN:(110001)', ONLINE:'0', ACC_STAT:'Banned', DEPT:'SEST', LOGCOUNT:'2365'"},
	{"BID012","BID:'BID012', SID:'2017-310-128', NET:'NET100', PEN:'0', NAME:'Sad Mere Mortal', GUARDIAN:'Om Prakash Sharma', DOB:'11/FEB/1999', ACT_STAT:'1', PH1:'CODE:(91), NUM:(8153338479)', PH2:'CODE:(91), NUM:(8606157348)', EM1:'HEAD:(iamthedeveloper), HOST:(gmail.com)', EM2:'HEAD:(contactherebitch), HOST:(outlook.com)', ADD1:'HNO:(16), BLO:(H), COL:(Depression), LAN:(FICCI), AREA:(Manhoos Corner), CIT:(New Delhi), STA:(Delhi), COU:(India), PIN:(110001)', ADD2==ADD1:'1', ADD2:'HNO:(16), BLO:(H), COL:(Wazira), LAN:(FICCI), AREA:(Barakhamba), CIT:(New Delhi), STA:(Delhi), COU:(India), PIN:(110001)', ONLINE:'1', ACC_STAT:'Enabled', DEPT:'SEST', LOGCOUNT:'68'"},
	{"BID013","BID:'BID013', SID:'2017-310-129', NET:'NET100', PEN:'0', NAME:'Depressed Mere Mortal', GUARDIAN:'Om Prakash Sharma', DOB:'11/FEB/1999', ACT_STAT:'1', PH1:'CODE:(91), NUM:(8153338479)', PH2:'CODE:(91), NUM:(8606157348)', EM1:'HEAD:(iamthedeveloper), HOST:(gmail.com)', EM2:'HEAD:(contactherebitch), HOST:(outlook.com)', ADD1:'HNO:(16), BLO:(H), COL:(Depression), LAN:(FICCI), AREA:(Manhoos Corner), CIT:(New Delhi), STA:(Delhi), COU:(India), PIN:(110001)', ADD2==ADD1:'1', ADD2:'HNO:(16), BLO:(H), COL:(Wazira), LAN:(FICCI), AREA:(Barakhamba), CIT:(New Delhi), STA:(Delhi), COU:(India), PIN:(110001)', ONLINE:'1', ACC_STAT:'Enabled', DEPT:'SEST', LOGCOUNT:'68'"},
	{"BID014","BID:'BID014', SID:'2017-310-130', NET:'NET100', PEN:'0', NAME:'Angry Mere Mortal', GUARDIAN:'Om Prakash Sharma', DOB:'11/FEB/1999', ACT_STAT:'1', PH1:'CODE:(91), NUM:(8153338479)', PH2:'CODE:(91), NUM:(8606157348)', EM1:'HEAD:(iamthedeveloper), HOST:(gmail.com)', EM2:'HEAD:(contactherebitch), HOST:(outlook.com)', ADD1:'HNO:(16), BLO:(H), COL:(Depression), LAN:(FICCI), AREA:(Manhoos Corner), CIT:(New Delhi), STA:(Delhi), COU:(India), PIN:(110001)', ADD2==ADD1:'1', ADD2:'HNO:(16), BLO:(H), COL:(Wazira), LAN:(FICCI), AREA:(Barakhamba), CIT:(New Delhi), STA:(Delhi), COU:(India), PIN:(110001)', ONLINE:'1', ACC_STAT:'Enabled', DEPT:'SEST', LOGCOUNT:'68'"},
	{"BID015","BID:'BID015', SID:'2017-310-131', NET:'NET100', PEN:'0', NAME:'Dead Mere Mortal', GUARDIAN:'Om Prakash Sharma', DOB:'11/FEB/1999', ACT_STAT:'1', PH1:'CODE:(91), NUM:(8153338479)', PH2:'CODE:(91), NUM:(8606157348)', EM1:'HEAD:(iamthedeveloper), HOST:(gmail.com)', EM2:'HEAD:(contactherebitch), HOST:(outlook.com)', ADD1:'HNO:(16), BLO:(H), COL:(Depression), LAN:(FICCI), AREA:(Manhoos Corner), CIT:(New Delhi), STA:(Delhi), COU:(India), PIN:(110001)', ADD2==ADD1:'1', ADD2:'HNO:(16), BLO:(H), COL:(Wazira), LAN:(FICCI), AREA:(Barakhamba), CIT:(New Delhi), STA:(Delhi), COU:(India), PIN:(110001)', ONLINE:'1', ACC_STAT:'Enabled', DEPT:'SEST', LOGCOUNT:'68'"},
	{"BID016","BID:'BID016', SID:'2017-310-132', NET:'NET100', PEN:'0', NAME:'Some Mere Mortal', GUARDIAN:'Om Prakash Sharma', DOB:'11/FEB/1999', ACT_STAT:'1', PH1:'CODE:(91), NUM:(8153338479)', PH2:'CODE:(91), NUM:(8606157348)', EM1:'HEAD:(iamthedeveloper), HOST:(gmail.com)', EM2:'HEAD:(contactherebitch), HOST:(outlook.com)', ADD1:'HNO:(16), BLO:(H), COL:(Depression), LAN:(FICCI), AREA:(Manhoos Corner), CIT:(New Delhi), STA:(Delhi), COU:(India), PIN:(110001)', ADD2==ADD1:'1', ADD2:'HNO:(16), BLO:(H), COL:(Wazira), LAN:(FICCI), AREA:(Barakhamba), CIT:(New Delhi), STA:(Delhi), COU:(India), PIN:(110001)', ONLINE:'1', ACC_STAT:'Enabled', DEPT:'SEST', LOGCOUNT:'68'"},
};
std::map<std::string, std::string> NET200_data = {
	{"BID001","data"},
	{"BID002","data"},
	{"BID003","data"},
	{"BID004","data"},
	{"BID005","data"},
	{"BID006","data"},
	{"BID007","data"},
	{"BID008","data"},
	{"BID009","data"},
	{"BID010","data"},
	{"BID011","data"},
	{"BID012","data"},
	{"BID013","data"},
	{"BID014","data"},
	{"BID015","data"},
	{"BID016","data"},
};
std::map<std::string, std::string> NET300_data = {
	{"BID001","data"},
	{"BID002","data"},
	{"BID003","data"},
	{"BID004","data"},
	{"BID005","data"},
	{"BID006","data"},
	{"BID007","data"},
	{"BID008","data"},
	{"BID009","data"},
	{"BID010","data"},
	{"BID011","data"},
	{"BID012","data"},
	{"BID013","data"},
	{"BID014","data"},
	{"BID015","data"},
	{"BID016","data"},
};
std::map<std::string, std::string> NET400_data = {
	{"BID001","data"},
	{"BID002","data"},
	{"BID003","data"},
	{"BID004","data"},
	{"BID005","data"},
	{"BID006","data"},
	{"BID007","data"},
	{"BID008","data"},
	{"BID009","data"},
	{"BID010","data"},
	{"BID011","data"},
	{"BID012","data"},
	{"BID013","data"},
	{"BID014","data"},
	{"BID015","data"},
	{"BID016","data"},
};
std::map<std::string, std::string> NET500_data = {
	{"BID001","data"},
	{"BID002","data"},
	{"BID003","data"},
	{"BID004","data"},
	{"BID005","data"},
	{"BID006","data"},
	{"BID007","data"},
	{"BID008","data"},
	{"BID009","data"},
	{"BID010","data"},
	{"BID011","data"},
	{"BID012","data"},
	{"BID013","data"},
	{"BID014","data"},
	{"BID015","data"},
	{"BID016","data"},
};
std::map<std::string, std::string> NET600_data = {
	{"BID001","data"},
	{"BID002","data"},
	{"BID003","data"},
	{"BID004","data"},
	{"BID005","data"},
	{"BID006","data"},
	{"BID007","data"},
	{"BID008","data"},
	{"BID009","data"},
	{"BID010","data"},
	{"BID011","data"},
	{"BID012","data"},
	{"BID013","data"},
	{"BID014","data"},
	{"BID015","data"},
	{"BID016","data"},
};
std::map<std::string, std::string> NET700_data = {
	{"BID001","data"},
	{"BID002","data"},
	{"BID003","data"},
	{"BID004","data"},
	{"BID005","data"},
	{"BID006","data"},
	{"BID007","data"},
	{"BID008","data"},
	{"BID009","data"},
	{"BID010","data"},
	{"BID011","data"},
	{"BID012","data"},
	{"BID013","data"},
	{"BID014","data"},
	{"BID015","data"},
	{"BID016","data"},
};
std::map<std::string, std::string> NET800_data = {
	{"BID001","data"},
	{"BID002","data"},
	{"BID003","data"},
	{"BID004","data"},
	{"BID005","data"},
	{"BID006","data"},
	{"BID007","data"},
	{"BID008","data"},
	{"BID009","data"},
	{"BID010","data"},
	{"BID011","data"},
	{"BID012","data"},
	{"BID013","data"},
	{"BID014","data"},
	{"BID015","data"},
	{"BID016","data"},
};
std::map<std::string, std::string> NET900_data = {
	{"BID001","data"},
	{"BID002","data"},
	{"BID003","data"},
	{"BID004","data"},
	{"BID005","data"},
	{"BID006","data"},
	{"BID007","data"},
	{"BID008","data"},
	{"BID009","data"},
	{"BID010","data"},
	{"BID011","data"},
	{"BID012","data"},
	{"BID013","data"},
	{"BID014","data"},
	{"BID015","data"},
	{"BID016","data"},
};
std::map<std::string, std::string> NET110_data = {
	{"BID001","data"},
	{"BID002","data"},
	{"BID003","data"},
	{"BID004","data"},
	{"BID005","data"},
	{"BID006","data"},
	{"BID007","data"},
	{"BID008","data"},
	{"BID009","data"},
	{"BID010","data"},
	{"BID011","data"},
	{"BID012","data"},
	{"BID013","data"},
	{"BID014","data"},
	{"BID015","data"},
	{"BID016","data"},
};
std::map<std::string, std::map<std::string, std::string>> Joker_DB = {
	{"NET100", NET100_data},
	{"NET200", NET200_data},
	{"NET300", NET300_data},
	{"NET400", NET400_data},
	{"NET500", NET500_data},
	{"NET600", NET600_data},
	{"NET700", NET700_data},
	{"NET800", NET800_data},
	{"NET900", NET900_data},
	{"NET110", NET110_data}
};

// Local Variable Inits

	// Network Objects (Contains 10 networks with each having 16 user objects. 6 Admins and 10 Students)
	std::string NET100_obj[] = { "vilidutt","armelo","armanza","zakajuda","coenfuse","larochey","2017-310-123","2017-310-124","2017-310-125","2017-310-126","2017-310-127","2017-310-128","2017-310-129","2017-310-130","2017-310-131","2017-310-132" };
	std::string NET200_obj[] = { "catibatz","nurymato","arayfero","elenjudd","bessbaro","quastro","2016-315-120","2016-315-121","2016-315-122","2016-315-123","2016-315-124","2016-315-125","2016-315-126","2016-315-127","2016-315-128","2016-315-129" };
	std::string NET300_obj[] = { "morynern","yoanison","diaolani","alissolt","tzakary","armygirl","2018-335-093","2018-335-094","2018-335-095","2018-335-096","2018-335-097","2018-335-098","2018-335-099","2018-335-100","2018-335-101","2018-335-102" };
	std::string NET400_obj[] = { "morynern","yoanison","diaolani","alissolt","tzakary","armygirl","2018-335-093","2018-335-094","2018-335-095","2018-335-096","2018-335-097","2018-335-098","2018-335-099","2018-335-100","2018-335-101","2018-335-102" };
	std::string NET500_obj[] = { "neriwirt","foadbutt","edamedin","iramsolt","elenjuda","junazer","2020-312-123","2020-312-889","2020-312-890","2020-312-891","2020-312-892","2020-312-893","2020-312-894","2020-312-895","2020-312-896","2020-312-897" };
	std::string NET600_obj[] = { "arayjobe","edaskutt","egonelek","javigroh","jurimota","jodychey","2015-360-723","2015-360-724","2015-360-725","2015-360-726","2015-360-727","2015-360-728","2015-360-729","2015-360-730","2015-360-731","2015-360-732" };
	std::string NET700_obj[] = { "corzar", "eberzani", "myelin", "toggo", "kerifaby", "hedifero","2014-390-873","2014-390-874","2014-390-875","2014-390-876","2014-390-877","2014-390-878","2014-390-879","2014-390-880","2014-390-881","2014-390-882" };
	std::string NET800_obj[] = { "caprilla","toggo","ibayrahim","edacryar","drisbud","etto","2013-690-001","2013-690-002","2013-690-003","2013-690-004","2013-690-005","2013-690-006","2013-690-007","2013-690-008","2013-690-009","2013-690-010"};
	std::string NET900_obj[] = { "odin","tenamaro","retahyer","faizelek","keriprak","vilipolk","2012-480-323","2012-480-324","2012-480-325","2012-480-326","2012-480-327","2012-480-328","2012-480-329","2012-480-330","2012-480-331","2012-480-332"};
	std::string NET110_obj[] = { "elezor","nuriceli","babu","walymeck","judafaur","capitalari","2011-369-111","2011-369-222","2011-369-333","2011-369-444","2011-369-555","2011-369-666","2011-369-777","2011-369-888","2011-369-999","2011-369-000"};


// Local Declarations
bool checkNetObj(std::string username, std::string NET);
bool writeUserData(std::string BID, std::string DATA);

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
		unsigned short objects = sizeof(NET200_obj) / sizeof(NET200_obj[0]);
		for (int i = 0; i < objects; i++)
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

bool writeUserData(std::string BID, std::string DATA){	// INCOMPLETE
	return true;
}

/*=================================================================================================================*/
//USER/CHECK FUNCTIONS
/*-----------------------------------------------------------------------------------------------*/
bool bapi::user::chk::user(std::string access_code, short key, std::string username, std::string net) {
	
	//COMPLETE
	
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
		switch (key)
		{
		case 1: {	// Invoked if the user key is ADMIN
			return (checkNetObj(username, net));
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
			return (checkNetObj(username, net));
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

std::string bapi::user::chk::authLogin(std::string access_code, short key, std::string username, std::string NET, std::string password) {
	// COMPLETE
	//return "-1";
	if (token.checkAccess(access_code)) {
		if (checkNetObj(username, NET) && password == "0000")
			return token.giveSession();
	}
	return "-1";
}

bool bapi::user::chk::logout(std::string access_code, std::string session_code, std::string bid, std::string data) {
	// COMPLETE

	if (token.checkAccess(access_code) && token.checkSession(session_code)) {
		return writeUserData(bid,data); // Implement this function later
	}
	return false;
}

//USER/GET/ATTRIBUTES Functions
/*-----------------------------------------------------------------------------------------------*/
std::string bapi::user::get::attr::users(std::string access_code, std::string session_code, std::string net, short usertype) {
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

	if (net == "NET100") {
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
			unsigned object_count = sizeof(NET100_obj) / sizeof(NET100_obj[0]);
			for (int i = 5; i < object_count; i++)	// Skips first 6 admins and logs in the rest.
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
	else if (net == "NET200") {
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
			unsigned object_count = sizeof(NET200_obj) / sizeof(NET200_obj[0]);
			for (int i = 5; i < object_count; i++)	// Skips first 6 admins and logs in the rest.
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
	else if (net == "NET300") {
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
			unsigned object_count = sizeof(NET300_obj) / sizeof(NET300_obj[0]);
			for (int i = 5; i < object_count; i++)	// Skips first 6 admins and logs in the rest.
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
	else if (net == "NET400") {
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
			unsigned object_count = sizeof(NET400_obj) / sizeof(NET400_obj[0]);
			for (int i = 5; i < object_count; i++)	// Skips first 6 admins and logs in the rest.
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
	else if (net == "NET500") {
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
		unsigned object_count = sizeof(NET500_obj) / sizeof(NET500_obj[0]);
		for (int i = 5; i < object_count; i++)	// Skips first 6 admins and logs in the rest.
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
	else if (net == "NET600") {
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
		for (int i = 5; i < object_count; i++)	// Skips first 6 admins and logs in the rest.
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
	else if (net == "NET700") {
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
			for (int i = 5; i < object_count; i++)	// Skips first 6 admins and logs in the rest.
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
	else if (net == "NET800") {
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
		for (int i = 5; i < object_count; i++)	// Skips first 6 admins and logs in the rest.
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
	else if (net == "NET900") {
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
		for (int i = 5; i < object_count; i++)	// Skips first 6 admins and logs in the rest.
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
	else if (net == "NET110") {
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
		for (int i = 5; i < object_count; i++)	// Skips first 6 admins and logs in the rest.
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
	else return pass_data;
}

std::string bapi::user::get::attr::user(std::string access_code, std::string session_code, std::string NET, std::string BID_requestedBy, std::string BID_requested) {
	//COMPLETE
	
	/* Return Convention
	"	"#USR_ATTR_ADM, BID:'BIDxxxxxxxxxx', AID:'xxxxxxxxxx', NET:'NETxxxxxxxxxx', OWN:'0 or 1', NAME:'xxxxxxxxxx', GUARDIAN:'xxxxxxxxxx', DOB:'00/MON/0000', ACT_STAT:'0 or 1', PH1:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', PH2:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', EM1:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', EM2:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', ADD1:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), AREA:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ADD2==ADD1:'0', ADD2:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), LOC:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ONLINE:'0 or 1', ACC_STAT:'xxxxxxxxxx'"
	*	"#USR_ATTR_STU, BID:'BIDxxxxxxxxxx', SID:'xxxxxxxxxx', NET:'NETxxxxxxxxxx', PEN:'0 or 1', NAME:'xxxxxxxxxx', GUARDIAN:'xxxxxxxxxx', DOB:'00/MON/0000', ACT_STAT:'0 or 1', PH1:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', PH2:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', EM1:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', EM2:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', ADD1:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), AREA:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ADD2==ADD1:'0', ADD2:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), LOC:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ONLINE:'0 or 1', ACC_STAT:'xxxxxxxxxx', DEPT:'xxxxxxxxxx', LOGCOUNT:'xxxxxxxxx'"
	*	"#USR_ATTR_EMP, BID:'BIDxxxxxxxxxx', EID:'xxxxxxxxxx', NET:'NETxxxxxxxxxx', OWN:'0 or 1', NAME:'xxxxxxxxxx', GUARDIAN:'xxxxxxxxxx', SPOUSE:'xxxxxxxxxx', DOB:'00/MON/0000', ACT_STAT:'0 or 1', PH1:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', PH2:'CODE:(xxxxxx), NUM:(xxxxxxxxxx)', EM1:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', EM2:'HEAD:(xxxxxxxxxx), HOST:(xxxxxxxxxx)', ADD1:'HNO:(xxx), BLO:(xxx), COL:(xxxxxxxxxx), LAN:(xxxxxxxxxx), AREA:(xxxxxxxxxx), CIT:(xxxxxxxxxx), STA:(xxxxxxxxxx), COU:(xxxxxxxxxx), PIN:(xxxxxxxxxx)', ADD2==ADD1:'1', ADD2:'NULL', ONLINE:'0 or 1', ACC_STAT:'xxxxxxxxxx', DEPT:'xxxxxxxxxx', LOGCOUNT:'xxxxxxxxx'"
	*/

	std::string prefix[] = { "#USR_ATTR_ADM, ","#USR_ATTR_STU, ","#USR_ATTR_EMP, ","#USR_ATTR_SUP, ","#USR_ATTR_MOD, ","#USR_ATTR_GUE, " };
	std::string pass_data = "NULL";

	if (token.checkAccess(access_code) && token.checkSession(session_code))
	{
		if (NET == "NET100") {
			// Not implementing check method for authenticating type of BID_requested_by
			std::map <std::string, std::string> data_container;
			data_container = Joker_DB.at(NET);
			pass_data = data_container.at(BID_requested);
			return prefix[0] + pass_data;		// Not implementing checking user type method right now.
		}
		else if (NET == "NET200") {
			// Not implementing check method for authenticating type of BID_requested_by
			std::map <std::string, std::string> data_container;
			data_container = Joker_DB.at(NET);
			pass_data = data_container.at(BID_requested);
			return prefix[1] + pass_data;		// Not implementing checking user type method right now.
		}
		else if (NET == "NET300") {
			// Not implementing check method for authenticating type of BID_requested_by
			std::map <std::string, std::string> data_container;
			data_container = Joker_DB.at(NET);
			pass_data = data_container.at(BID_requested);
			return prefix[0] + pass_data;		// Not implementing checking user type method right now.
		}
		else if (NET == "NET400") {
			// Not implementing check method for authenticating type of BID_requested_by
			std::map <std::string, std::string> data_container;
			data_container = Joker_DB.at(NET);
			pass_data = data_container.at(BID_requested);
			return prefix[1] + pass_data;		// Not implementing checking user type method right now.
		}
		else if (NET == "NET500") {
			// Not implementing check method for authenticating type of BID_requested_by
			std::map <std::string, std::string> data_container;
			data_container = Joker_DB.at(NET);
			pass_data = data_container.at(BID_requested);
			return prefix[0] + pass_data;		// Not implementing checking user type method right now.
		}
		else if (NET == "NET600") {
			// Not implementing check method for authenticating type of BID_requested_by
			std::map <std::string, std::string> data_container;
			data_container = Joker_DB.at(NET);
			pass_data = data_container.at(BID_requested);
			return prefix[0] + pass_data;		// Not implementing checking user type method right now.
		}
		else if (NET == "NET700") {
			// Not implementing check method for authenticating type of BID_requested_by
			std::map <std::string, std::string> data_container;
			data_container = Joker_DB.at(NET);
			pass_data = data_container.at(BID_requested);
			return prefix[0] + pass_data;		// Not implementing checking user type method right now.
		}
		else if (NET == "NET800") {
			// Not implementing check method for authenticating type of BID_requested_by
			std::map <std::string, std::string> data_container;
			data_container = Joker_DB.at(NET);
			pass_data = data_container.at(BID_requested);
			return prefix[0] + pass_data;		// Not implementing checking user type method right now.
		}
		else if (NET == "NET900") {
			// Not implementing check method for authenticating type of BID_requested_by
			std::map <std::string, std::string> data_container;
			data_container = Joker_DB.at(NET);
			pass_data = data_container.at(BID_requested);
			return prefix[0] + pass_data;		// Not implementing checking user type method right now.
		}
		else if (NET == "NET110") {
			// Not implementing check method for authenticating type of BID_requested_by
			std::map <std::string, std::string> data_container;
			data_container = Joker_DB.at(NET);
			pass_data = data_container.at(BID_requested);
			return prefix[0] + pass_data;		// Not implementing checking user type method right now.
		}
		else return pass_data;
	}
	return "ERROR CODE: M100 - Unauthorized access. Bad Access or Session Key";
}

//USER/UPDATE/ATTRIBUTES Functions
/*-----------------------------------------------------------------------------------------------*/
bool bapi::user::up::attr::users(std::string access_code, std::string session_code, std::string bid, short action) {	//Consider removal.
	//INCOMPLETE
	if (token.checkAccess(access_code) && token.checkSession(session_code)) {
		
		return true;
	}
	else return false;
}

bool bapi::user::up::attr::user(std::string access_code, std::string session_code, std::string bid, std::string data) {
	//INCOMPLETE
	
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return true;
	else return false;
}

//USER/POST/ATTRIBUTES Functions
/*-----------------------------------------------------------------------------------------------*/
bool bapi::user::post::attr::users(std::string access_code, std::string session_code, std::string BID_requestBy, short action, std::string data) {	//Consider removal
	//INCOMPLETE
	
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return true;
	else return false;
}

bool bapi::user::post::attr::user(std::string access_code, std::string session_code, std::string BID_requestBy, short action, std::string data) {
	//INCOMPLETE
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return true;
	else return false;
}

//USER/POP/ATTRIBUTES Functions
/*-----------------------------------------------------------------------------------------------*/
bool bapi::user::pop::attr::user(std::string access_code, std::string session_code, std::string BID_requestBy, std::string BID_requestOn, short action) {
	//INCOMPLETE
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return true;
	else return false;
}


/*=================================================================================================================*/
//NETWORK/CHECK Functions
/*-----------------------------------------------------------------------------------------------*/
bool bapi::net::chk::net(std::string access_code, std::string NET) { //INCOMPLETE
	
	if (token.checkAccess(access_code))
		return true;
	else return false;
}

bool bapi::net::chk::user(std::string access_code, short key, std::string NET, std::string BID) { //INCOMPLETE
	
	if (token.checkAccess(access_code))
		return true;
	else return false;
}

bool bapi::net::chk::owner(std::string access_code, std::string NET, std::string BID) { //INCOMPLETE
	
	if (token.checkAccess(access_code))
		return true;
	else return false;
}

bool bapi::net::chk::active(std::string access_code, std::string NET) { //INCOMPLETE
	
	if (token.checkAccess(access_code))
		return true;
	else return false;
}

//NETWORK/GET Functions
/*-----------------------------------------------------------------------------------------------*/
std::string bapi::net::get::net(std::string access_code, std::string session_code, std::string NET, std::string BID) { //INCOMPLETE
	std::string prefix = "#NET";

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::stats(std::string access_code, std::string session_code, std::string NET, std::string BID) { //INCOMPLETE
	std::string prefix = "#NET_STAT";

	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::admins(std::string access_code, std::string session_code, std::string NET, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_ADMS";
	
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::owner(std::string access_code, std::string session_code, std::string NET, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_OWN";
	
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::stands(std::string access_code, std::string session_code, std::string NET, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_STDS";
	
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::stand(std::string access_code, std::string session_code, std::string NET, std::string STD, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_STD";
	
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::standStats(std::string access_code, std::string session_code, std::string NET, std::string STD, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_STD_STAT";
	
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::nearestStand(std::string access_code, std::string session_code, std::string NET, std::string LOC, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_NEAR_STD";
	
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

int bapi::net::get::standDistance(std::string access_code, std::string session_code, std::string NET, std::string STD1, std::string STD2, std::string BID) { // INCOMPLETE
	
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return 100;
	else return 100;
}

std::string bapi::net::get::cycles(std::string access_code, std::string session_code, std::string NET, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_CYCS";
	
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::cycle(std::string access_code, std::string session_code, std::string NET, std::string CYC) { // INCOMPLETE
	std::string prefix = "#NET_CYC";
	
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::freeCycles(std::string access_code, std::string session_code, std::string NET, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_FREE_CYC";
	
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::locks(std::string access_code, std::string session_code, std::string NET, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_LCKS";
	
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::lock(std::string access_code, std::string session_code, std::string NET, std::string LCK, std::string BID) { // INCOMPLETE
	std::string prefix = "#NET_LCK";
	
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::allTXN(std::string access_code, std::string session_code, std::string NET, std::string BID_requester) {
	std::string prefix = "#NET_TXNS";
	
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::userTXN(std::string access_code, std::string session_code, std::string NET, std::string BID_requester, std::string BID_requested) {
	std::string prefix = "#NET_USR_TXN";
	
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::stdTXN(std::string access_code, std::string session_code, std::string NET, std::string STD, std::string BID_requester) {
	std::string prefix = "#NET_STD_TXN";
	
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::cycTXN(std::string access_code, std::string session_code, std::string NET, std::string CYC, std::string BID_requester) {
	std::string prefix = "#NET_CYC_TXN";
	
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

std::string bapi::net::get::TXN(std::string access_code, std::string session_code, std::string NET, std::string BID_requester, std::string TXN) {
	std::string prefix = "#NET_TXN";
	
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return prefix + "0";
	else return prefix + "0";
}

//NETWORK/UP Functions
/*-----------------------------------------------------------------------------------------------*/
bool bapi::net::up::net(std::string access_code, std::string session_code, std::string NET, std::string BID, short action, std::string data) { // INCOMPLETE
	
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::up::stands(std::string access_code, std::string session_code, std::string NET, std::string BID, short action, std::string data) { // INCOMPLETE
	
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::up::stand(std::string access_code, std::string session_code, std::string NET, std::string BID, short action, std::string STD, std::string data) { // INCOMPLETE
	
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::up::cycles(std::string access_code, std::string session_code, std::string NET, std::string BID, short action, std::string data) { // INCOMPLETE
	
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::up::cycle(std::string access_code, std::string session_code, std::string NET, std::string BID, short action, std::string CYC, std::string data) { // INCOMPLETE
	
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::up::locks(std::string access_code, std::string session_code, std::string NET, std::string BID, short action, std::string data) { // INCOMPLETE
	
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::up::lock(std::string access_code, std::string session_code, std::string NET, std::string BID, short action, std::string LCK, std::string data) { // INCOMPLETE
	
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

//NETWORK/POST Functions
/*-----------------------------------------------------------------------------------------------*/
bool bapi::net::post::net(std::string access_code, std::string session_code, std::string BID, std::string data) { //INCOMPLETE
	
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::post::stand(std::string access_code, std::string session_code, std::string BID, std::string NET, std::string data) { //INCOMPLETE
	
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::post::cycle(std::string access_code, std::string session_code, std::string BID, std::string NET, std::string data) { //INCOMPLETE
	
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::post::lock(std::string access_code, std::string session_code, std::string BID, std::string NET, std::string STD, std::string data) { //INCOMPLETE
	
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

//NETWORK/POP Functions
/*-----------------------------------------------------------------------------------------------*/
bool bapi::net::pop::net(std::string access_code, std::string session_code, std::string BID, std::string NET) { // INCOMPLETE
	
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::pop::stand(std::string access_code, std::string session_code, std::string BID, std::string NET, std::string STD) { // INCOMPLETE
	
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::pop::cycle(std::string access_code, std::string session_code, std::string BID, std::string NET, std::string CYC) { // INCOMPLETE
	
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
}

bool bapi::net::pop::lock(std::string access_code, std::string session_code, std::string BID, std::string NET, std::string STD, std::string LCK) { // INCOMPLETE
	
	if (token.checkAccess(access_code) && token.checkSession(session_code))
		return false;
	else return true;
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