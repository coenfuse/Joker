#pragma once

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
std::string NET800_obj[] = { "caprilla","toggo","ibayrahim","edacryar","drisbud","etto","2013-690-001","2013-690-002","2013-690-003","2013-690-004","2013-690-005","2013-690-006","2013-690-007","2013-690-008","2013-690-009","2013-690-010" };
std::string NET900_obj[] = { "odin","tenamaro","retahyer","faizelek","keriprak","vilipolk","2012-480-323","2012-480-324","2012-480-325","2012-480-326","2012-480-327","2012-480-328","2012-480-329","2012-480-330","2012-480-331","2012-480-332" };
std::string NET110_obj[] = { "elezor","nuriceli","babu","walymeck","judafaur","capitalari","2011-369-111","2011-369-222","2011-369-333","2011-369-444","2011-369-555","2011-369-666","2011-369-777","2011-369-888","2011-369-999","2011-369-000" };
std::map<std::string, char> userTypes = { {"BID001",'A'},{"BID002",'A'},{"BID003",'A'},{"BID004",'A'},{"BID005",'A'},{"BID006",'A'},{"BID007",'U'},{"BID008",'U'},{"BID009",'U'},{"BID010",'U'},{"BID011",'U'},{"BID012",'U'},{"BID013",'U'},{"BID014",'U'},{"BID015",'U'},{"BID016",'U'} };
