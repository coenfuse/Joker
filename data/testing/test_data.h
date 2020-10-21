#pragma once
#include<vector>

Token token;

std::vector<std::string> network_list = {
	"NET100",
	"NET110",
	"NET200",
	"NET300",
	"NET400",
	"NET500",
	"NET600",
	"NET700",
	"NET800",
	"NET900"
};

std::vector<std::string>::iterator net_list_itr;

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

std::map<std::string, std::string> NET100_index = {
	{"vilidutt", "BID001"},
	{"armelo", "BID002"},
	{"armanza","BID003"},
	{"zakajuda", "BID004"},
	{"coenfuse", "BID005"},
	{"larochey","BID006"},
	{"2017-310-123", "BID007"},
	{"2017-310-124", "BID008"},
	{"2017-310-125","BID009"},
	{"2017-310-126", "BID0010"},
	{"2017-310-127", "BID011"},
	{"2017-310-128","BID012"},
	{"2017-310-129", "BID013"},
	{"2017-310-130", "BID014"},
	{"2017-310-131","BID015"},
	{"2017-310-132","BID016"}
};
std::map<std::string, std::string> NET200_index = {
	{"catibatz","BID001"},
	{"nurymato","BID002"},
	{"arayfero","BID003"},
	{"elenjudd","BID004"},
	{"bessbaro","BID005"},
	{"quastro","BID006"},
	{"2016-315-120","BID007"},
	{"2016-315-121","BID008"},
	{"2016-315-122","BID009"},
	{"2016-315-123","BID010"},
	{"2016-315-124","BID011"},
	{"2016-315-125","BID012"},
	{"2016-315-126","BID013"},
	{"2016-315-127","BID014"},
	{"2016-315-128","BID015"},
	{"2016-315-129","BID016"}
};
std::map<std::string, std::string> NET300_index = {
	{"morynern","BID001"},
	{"yoanison","BID002"},
	{"diaolani","BID003"},
	{"alissolt","BID004"},
	{"tzakary","BID005"},
	{"armygirl","BID006"},
	{"2018-335-093","BID007"},
	{"2018-335-094","BID008"},
	{"2018-335-095","BID009"},
	{"2018-335-096","BID010"},
	{"2018-335-097","BID011"},
	{"2018-335-098","BID012"},
	{"2018-335-099","BID013"},
	{"2018-335-100","BID014"},
	{"2018-335-101","BID015"},
	{"2018-335-102","BID016"}
};
std::map<std::string, std::string> NET400_index = {
	{"mussboi","BID001"},
	{"nosinoy","BID002"},
	{"inaload","BID003"},
	{"bolt","BID004"},
	{"carrotlover","BID005"},
	{"bongbro","BID006"},
	{"2014-815-120","BID007"},
	{"2014-815-121","BID008"},
	{"2014-815-122","BID009"},
	{"2014-815-123","BID010"},
	{"2014-815-124","BID011"},
	{"2014-815-125","BID012"},
	{"2014-815-126","BID013"},
	{"2014-815-127","BID014"},
	{"2014-815-128","BID015"},
	{"2014-815-129","BID016"}
};
std::map<std::string, std::string> NET500_index = {
	{"neriwirt","BID001"},
	{"foadbutt","BID002"},
	{"edamedin","BID003"},
	{"iramsolt","BID004"},
	{"elenjuda","BID005"},
	{"junazer","BID006"},
	{"2020-312-888","BID007"},
	{"2020-312-889","BID008"},
	{"2020-312-890","BID009"},
	{"2020-312-891","BID010"},
	{"2020-312-892","BID011"},
	{"2020-312-893","BID012"},
	{"2020-312-894","BID013"},
	{"2020-312-895","BID014"},
	{"2020-312-896","BID015"},
	{"2020-312-897","BID016"}
};
std::map<std::string, std::string> NET600_index = {
	{"arayjobe","BID001"},
	{"edaskutt","BID002"},
	{"egonelek","BID003"},
	{"javigroh","BID004"},
	{"jurimota","BID005"},
	{"jodychey","BID006"},
	{"2015-360-723","BID007"},
	{"2015-360-724","BID008"},
	{"2015-360-725","BID009"},
	{"2015-360-726","BID010"},
	{"2015-360-727","BID011"},
	{"2015-360-728","BID012"},
	{"2015-360-729","BID013"},
	{"2015-360-730","BID014"},
	{"2015-360-731","BID015"},
	{"2015-360-732","BID016"}
};
std::map<std::string, std::string> NET700_index = {
	{"corzar","BID001"},
	{"eberzani","BID002"},
	{"myelin","BID003"},
	{"toggo","BID004"},
	{"kerifaby","BID005"},
	{"hedifero","BID006"},
	{"2014-390-873","BID007"},
	{"2014-390-874","BID008"},
	{"2014-390-875","BID009"},
	{"2014-390-876","BID010"},
	{"2014-390-877","BID011"},
	{"2014-390-878","BID012"},
	{"2014-390-879","BID013"},
	{"2014-390-880","BID014"},
	{"2014-390-881","BID015"},
	{"2014-390-882","BID016"}
};
std::map<std::string, std::string> NET800_index = {
	{"caprilla","BID001"},
	{"ibra","BID002"},
	{"ibayrahim","BID003"},
	{"edacryar","BID004"},
	{"drisbud","BID005"},
	{"etto","BID006"},
	{"2013-690-001","BID007"},
	{"2013-690-002","BID008"},
	{"2013-690-003","BID009"},
	{"2013-690-004","BID010"},
	{"2013-690-005","BID011"},
	{"2013-690-006","BID012"},
	{"2013-690-007","BID013"},
	{"2013-690-008","BID014"},
	{"2013-690-009","BID015"},
	{"2013-690-010","BID016"}
};
std::map<std::string, std::string> NET900_index = {
	{"odin","BID001"},
	{"tenamaro","BID002"},
	{"retahyer","BID003"},
	{"faizelek","BID004"},
	{"keriprak","BID005"},
	{"vilipolk","BID006"},
	{"2012-480-323","BID007"},
	{"2012-480-324","BID008"},
	{"2012-480-325","BID009"},
	{"2012-480-326","BID010"},
	{"2012-480-327","BID011"},
	{"2012-480-328","BID012"},
	{"2012-480-329","BID013"},
	{"2012-480-330","BID014"},
	{"2012-480-331","BID015"},
	{"2012-480-332","BID016"}
};
std::map<std::string, std::string> NET110_index = {
	{"elezor","BID001"},
	{"nuriceli","BID002"},
	{"babu","BID003"},
	{"walymeck","BID004"},
	{"judafaur","BID005"},
	{"capitalari","BID006"},
	{"2011-369-111","BID007"},
	{"2011-369-222","BID008"},
	{"2011-369-333","BID009"},
	{"2011-369-444","BID010"},
	{"2011-369-555","BID011"},
	{"2011-369-666","BID012"},
	{"2011-369-777","BID013"},
	{"2011-369-888","BID014"},
	{"2011-369-999","BID015"},
	{"2011-369-000","BID016"}
};

// Network Objects (Contains 10 networks with each having 16 user objects. 6 Admins and 10 Students)
std::vector<std::string> NET100_user_list = { "vilidutt","armelo","armanza","zakajuda","coenfuse","larochey","2017-310-123","2017-310-124","2017-310-125","2017-310-126","2017-310-127","2017-310-128","2017-310-129","2017-310-130","2017-310-131","2017-310-132" };
std::vector<std::string> NET200_user_list = { "catibatz","nurymato","arayfero","elenjudd","bessbaro","quastro","2016-315-120","2016-315-121","2016-315-122","2016-315-123","2016-315-124","2016-315-125","2016-315-126","2016-315-127","2016-315-128","2016-315-129" };
std::vector<std::string> NET300_user_list = { "morynern","yoanison","diaolani","alissolt","tzakary","armygirl","2018-335-093","2018-335-094","2018-335-095","2018-335-096","2018-335-097","2018-335-098","2018-335-099","2018-335-100","2018-335-101","2018-335-102" };
std::vector<std::string> NET400_user_list = { "mussboi","nosinoy","inaload","bolt","carrotlover","bongbro","2014-815-120","2014-815-121","2014-815-122","2014-815-123","2014-815-124","2014-815-125","2014-815-126","2014-815-127","2014-815-128","2014-815-129" };
std::vector<std::string> NET500_user_list = { "neriwirt","foadbutt","edamedin","iramsolt","elenjuda","junazer","2020-312-888","2020-312-889","2020-312-890","2020-312-891","2020-312-892","2020-312-893","2020-312-894","2020-312-895","2020-312-896","2020-312-897" };
std::vector<std::string> NET600_user_list = { "arayjobe","edaskutt","egonelek","javigroh","jurimota","jodychey","2015-360-723","2015-360-724","2015-360-725","2015-360-726","2015-360-727","2015-360-728","2015-360-729","2015-360-730","2015-360-731","2015-360-732" };
std::vector<std::string> NET700_user_list = { "corzar", "eberzani", "myelin", "toggo", "kerifaby", "hedifero","2014-390-873","2014-390-874","2014-390-875","2014-390-876","2014-390-877","2014-390-878","2014-390-879","2014-390-880","2014-390-881","2014-390-882" };
std::vector<std::string> NET800_user_list = { "caprilla","toggo","ibayrahim","edacryar","drisbud","etto","2013-690-001","2013-690-002","2013-690-003","2013-690-004","2013-690-005","2013-690-006","2013-690-007","2013-690-008","2013-690-009","2013-690-010" };
std::vector<std::string> NET900_user_list = { "odin","tenamaro","retahyer","faizelek","keriprak","vilipolk","2012-480-323","2012-480-324","2012-480-325","2012-480-326","2012-480-327","2012-480-328","2012-480-329","2012-480-330","2012-480-331","2012-480-332" };
std::vector<std::string> NET110_user_list = { "elezor","nuriceli","babu","walymeck","judafaur","capitalari","2011-369-111","2011-369-222","2011-369-333","2011-369-444","2011-369-555","2011-369-666","2011-369-777","2011-369-888","2011-369-999","2011-369-000" };

std::vector<std::string>::iterator user_list_itr;

std::map<std::string, char> usertype_list = { {"BID001",'A'},{"BID002",'A'},{"BID003",'A'},{"BID004",'A'},{"BID005",'A'},{"BID006",'A'},{"BID007",'U'},{"BID008",'U'},{"BID009",'U'},{"BID010",'U'},{"BID011",'U'},{"BID012",'U'},{"BID013",'U'},{"BID014",'U'},{"BID015",'U'},{"BID016",'U'} };

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
std::map<std::string, std::map<std::string, std::string>> BID_pairs = {
	{"NET100", NET100_index},
	{"NET200", NET200_index},
	{"NET300", NET300_index},
	{"NET400", NET400_index},
	{"NET500", NET500_index},
	{"NET600", NET600_index},
	{"NET700", NET700_index},
	{"NET800", NET800_index},
	{"NET900", NET900_index},
	{"NET110", NET110_index}
};
std::map<std::string, std::vector<std::string>> Joker_Users = {
	{"NET100",NET100_user_list},
	{"NET200",NET200_user_list},
	{"NET300",NET300_user_list},
	{"NET400",NET400_user_list },
	{"NET500",NET500_user_list},
	{"NET600",NET600_user_list},
	{"NET700",NET700_user_list},
	{"NET800",NET800_user_list},
	{"NET900",NET900_user_list},
	{"NET110",NET110_user_list}
};

// Local Variable Inits
