#include "bisystem.h"
#include "misc.h"
#include<string>
#include<fstream>

//Name's Implementations
Name::Name(std::string fName, std::string mName, std::string lName){
    firstName = fName;
    middleName = mName;
    lastName = lName;
}

Name::getfirst(){
    return firstName;
}

Name::getMiddle(){
    return firstName;
}

Name::getLast(){
    return firstName;
}

Name::getFull(){
    std::fname = firstName + " " middleName + " " + lastName;
    return fname;
}

// Phone's Implementations
Phone::Phone(std::string number, std::string country){
    //Value of Code derived by intrinsic numbering of countries in ascending order.
    //This code will be then used to fetch country's calling code from local database.
    setISD(country);
    number =
}

void Phone::setISD(std::string country){
    std::string countries[] = {"afghanistan","albania","algeria","american samoa","andorra","angola","anguilla","antarctica","antigua and barbuda","argentina","armenia","aruba","australia","austria","azerbaijan","bahamas","bahrain","bangladesh","barbados","belarus","belgium","belize","benin","bermuda","bhutan","bolivia","bosnia and herzegovina","botswana","brazil","british indian ocean territory","british virgin islands","brunei","bulgaria","burkina faso","burundi","cambodia","cameroon","canada","cape verde","cayman islands","central african republic","chad","chile","china","christmas island","cocos islands","colombia","comoros","cook islands","costa rica","croatia","cuba","curacao","cyprus","czech republic","democratic republic of the congo","denmark","djibouti","dominica","dominican republic","east timor","ecuador","egypt","el salvador","equatorial guinea","eritrea","estonia","ethiopia","falkland islands","faroe islands","fiji","finland","france","french polynesia","gabon","gambia","georgia","germany","ghana","gibraltar","greece","greenland","grenada","guam","guatemala","guernsey","guinea","guinea-bissau","guyana","haiti","honduras","hong kong","hungary","iceland","india","indonesia","iran","iraq","ireland","isle of Man","israel","italy","ivory coast","jamaica","japan","jersey","jordan","kazakhstan","kenya","kiribati","kosovo","kuwait","kyrgyzstan","laos","latvia","lebanon","lesotho","liberia","libya","liechtenstein","lithuania","luxembourg","macau","macedonia","madagascar","malawi","malaysia","maldives","mali","malta","marshall islands","mauritania","mauritius","mayotte","mexico","micronesia","moldova","monaco","mongolia","montenegro","montserrat","morocco","mozambique","myanmar","namibia","nauru","nepal","netherlands","netherlands antilles","new caledonia","new zealand","nicaragua","niger","nigeria","niue","north korea","northern mariana islands","norway","oman","pakistan","palau","palestine","panama","papua new guinea","paraguay","peru","philippines","pitcairn","poland","portugal","puerto rico","qatar","republic of the congo","reunion","romania","russia","rwanda","saint barthelemy","saint helena","saint kitts and nevis","saint lucia","saint martin","saint pierre and miquelon","saint vincent and the grenadines","samoa","san marino","sao tome and principe","saudi arabia","senegal","serbia","seychelles","sierra leone","singapore","sint maarten","slovakia","slovenia","solomon islands","somalia","south africa","south korea","south sudan","spain","sri lanka","sudan","suriname","svalbard and jan mayen","swaziland","sweden","switzerland","syria","taiwan","tajikistan","tanzania","thailand","togo","tokelau","tonga","trinidad and tobago","tunisia","turkey","turkmenistan","turks and caicos islands","tuvalu","u.s. virgin islands","uganda","ukraine","united arab emirates","united kingdom","united states","uruguay","uzbekistan","vanuatu","vatican","venezuela","vietnam","wallis and futuna","western sahara","yemen","zambia","zimbabwe"};
    int length = sizeof(countries)/sizeof(countries[0]);
    country = tolower(country);
    for(int index = 0; index < length; index++){
        if(country == countries[index]) break;
    }
    switch (index + 1) {
        case 1:return 93;
        break;
        case 2:return 355;
        break;
        case 3:return 213;
        break;
        case 4:return 1684;
        break;
        case 5:return 376;
        break;
        case 6:return 244,
        break;
        case 7:return 1-264,
        break;
        case 8:return 672,
        break;
        case 9:return 1-268,
        break;
        case 10:return 54,
        break;
        case 11:return 374,
        break;
        case 12:return 297,
        break;
        case 13:return 61,
        break;
        case 14:return 43,
        break;
        case 15:return 994,
        break;
        case 16:return 1-242,
        break;
        case 17:return 973,
        break;
        case 18:return 880,
        break;
        case 19:return 1-246,
        break;
        case 20:return 375,
        break;
        case 21,32,
        break;
        case 22,501,
        break;
        case 23,229,
        break;
        case 24,1-441,
        break;
        case 25,975,
        break;
        case 26,591,
        break;
        case 27,387,
        break;
        case 28,267,
        break;
        case 29,55,
        break;
        case 30,246,
        break;
        case 31,1-284,
        break;
        case 32,673,
        break;
        case 33,359,
        break;
        case 3,226,
        break;
        case 35,257,
        break;
        case 36,855,
        break;
        case 37,237,
        break;
        case 38,1,
        break;
        case 39,238,
        break;
        case 40,1-345,
        break;
        case 41,236,
        break;
        case 42,235,
        break;
        case 43,56,
        break;
        case 44,86,
        break;
        case 45,61,
        break;
        case 46,61,
        break;
        case 47,57,
        break;
        case 48,269,
        break;
        case 49,682,
        break;
        case 50,506,
        break;
        case 51,385,
        break;
        case 52,53,
        break;
        case 53,599,
        break;
        case 54,357,
        break;
        case 55,420,
        break;
        case 56,243,
        break;
        case 57,45,
        break;
        case 58,253,
        break;
        case 59,1-767,
        break;
        case 60,1-809,
        break;
        case 61,670,
        break;
        case 62,593,
        break;
        case 63,20,
        break;
        case 64,503,
        break;
        case 65,240,
        break;
        case 66,291,
        break;
        case 67,372,
        break;
        case 68,251,
        break;
        case 69,500,
        break;
        case 70,298,
        break;
        case 71,679,
        break;
        case 72,358,
        break;
        case 73,33,
        break;
        case 74,689,
        break;
        case 75,241,
        break;
        case 76,220,
        break;
        case 77,995,
        break;
        case 78,49,
        break;
        case 79,233,
        break;
        case 80,350,
        break;
        case 81,30,
        break;
        case 82,299,
        break;
        case 83,1-473,
        break;
        case 84,1-671,
        break;
        case 85,502,
        break;
        case 86,44-1481,
        break;
        case 87,224,
        break;
        case 88,245,
        break;
        case 89,592,
        break;
        case 90,509,
        break;
        case 91,504,
        break;
        case 92,852,
        break;
        case 93,36,
        break;
        case 94,354,
        break;
        case 95,91,
        break;
        case 96,62,
        break;
        case 97,98,
        break;
        case 98,964,
        break;
        case 99,353,
        break;
        case 100,44-1624,
        break;
        case 101,972,
        break;
        case 102,39,
        break;
        case 103,225,
        break;
        case 104,1-876,
        break;
        case 105,81,
        break;
        case 106,44-1534,
        break;
        case 107,962,
        break;
        case 108,7,
        break;
        case 109,254,
        break;
        case 110,686,
        break;
        case 111,383,
        break;
        case 112,965,
        break;
        case 113,996,
        break;
        case 114,856,
        break;
        case 115,371,
        break;
        case 116,961,
        break;
        case 117,266,
        break;
        case 118,231,
        break;
        case 119,218,
        break;
        case 120,423,
        break;
        case 121,370,
        break;
        case 122,352,
        break;
        case 123,853,
        break;
        case 124,389,
        break;
        case 125,261,
        break;
        case 126,265,
        break;
        case 127,60,
        break;
        case 128,960,
        break;
        case 129,223,
        break;
        case 130,356,
        break;
        case 131,692,
        break;
        case 132,222,
        break;
        case 133,230,
        break;
        case 134,262,
        break;
        case 135,52,
        break;
        case 136,691,
        break;
        case 137,373,
        break;
        case 138,377,
        break;
        case 139,976,
        break;
        case 140,382,
        break;
        case 141,1-664,
        break;
        case 142,212,
        break;
        case 143,258,
        break;
        case 144,95,
        break;
        case 145,264,
        break;
        case 146,674,
        break;
        case 147,977,
        break;
        case 148,31,
        break;
        case 149,599,
        break;
        case 150,687,
        break;
        case 151,64,
        break;
        case 152,505,
        break;
        case 153,227,
        break;
        case 154,234,
        break;
        case 155,683,
        break;
        case 156,850,
        break;
        case 157,1-670,
        break;
        case 158,47,
        break;
        case 159,968,
        break;
        case 160,92,
        break;
        case 161,680,
        break;
        case 162,970,
        break;
        case 163,507,
        break;
        case 164,675,
        break;
        case 165,595,
        break;
        case 166,51,
        break;
        case 167,63,
        break;
        case 168,64,
        break;
        case 169,48,
        break;
        case 170,351,
        break;
        case 171,1-787,
        break;
        case 172,974,
        break;
        case 173,242,
        break;
        case 174,262,
        break;
        case 175,40,
        break;
        case 176,7,
        break;
        case 177,250,
        break;
        case 178,590,
        break;
        case 179,290,
        break;
        case 180,1-869,
        break;
        case 181,1-758,
        break;
        case 182,590,
        break;
        case 183,508,
        break;
        case 184,1-784,
        break;
        case 185,685,
        break;
        case 186,378,
        break;
        case 187,239,
        break;
        case 188,966,
        break;
        case 189,221,
        break;
        case 190,381,
        break;
        case 191,248,
        break;
        case 192,232,
        break;
        case 193,65,
        break;
        case 194,1-721,
        break;
        case 195,421,
        break;
        case 196,386,
        break;
        case 197,677,
        break;
        case 198,252,
        break;
        case 199,27,
        break;
        case 200,82,
        break;
        case 201,211,
        break;
        case 202,34,
        break;
        case 203,94,
        break;
        case 204,249,
        break;
        case 205,597,
        break;
        case 206,47,
        break;
        case 207,268,
        break;
        case 208,46,
        break;
        case 209,41,
        break;
        case 210,963,
        break;
        case 211,886,
        break;
        case 212,992,
        break;
        case 213,255,
        break;
        case 214,66,
        break;
        case 215,228,
        break;
        case 216,690,
        break;
        case 217,676,
        break;
        case 218,1-868,
        break;
        case 219,216,
        break;
        case 220,90,
        break;
        case 221,993,
        break;
        case 222,1-649,
        break;
        case 223,688,
        break;
        case 224,1-340,
        break;
        case 225,256,
        break;
        case 226,380,
        break;
        case 227,971,
        break;
        case 228,44,
        break;
        case 229,1,
        break;
        case 230,598,
        break;
        case 231,998,
        break;
        case 232,678,
        break;
        case 233,379,
        break;
        case 234,58,
        break;
        case 235,84,
        break;
        case 236,681,
        break;
        case 237,212,
        break;
        case 238,967,
        break;
        case 239,260,
        break;
        case 240,263,
        break;
        case default: return -1;
    };
}
int Phone::sendText(std::string text){
    cout<<"Sending message "<<text<<" to : "<<prefix<<"-"<<number;
    cout<<"\nSent.";
    return 0;
}
