#include "../../include/bisystem.h"
#include <sstream>
#include <string>
#include <map>
#include <iostream>

//Name's Implementations
Name::Name(std::string fName, std::string mName, std::string lName) {
    firstName = fName;
    middleName = mName;
    lastName = lName;
}

std::string Name::getFirst() {
    return firstName;
}

std::string Name::getMiddle() {
    return middleName;
}

std::string Name::getLast() {
    return lastName;
}

std::string Name::getFull() {
    std::string fname = firstName + " " + middleName + " " + lastName;
    return fname;
}

// Phone's Implementations
Phone::Phone(std::string number, std::string country) {
    //Value of Code derived by intrinsic numbering of countries in ascending order.
    //This code will be then used to fetch country's calling code from local database.
    setPrefix(country);
    setNumber(number);
}

void Phone::setPrefix(std::string country) {
    //A simple map that contains prefixes or calling codes of 240 countries.
    //The integer prefix can be obtained by proving a string key (case sensitive) in map.at(country)

    std::map<std::string, int> countries{ {"afghanistan",93},{"albania",355},{"algeria",213},{"american samoa",1684},{"andorra",376},{"anglola",244},{"anguilla",1264},{"antarctica",672},{"antigua and barbuda",1268},{"argentina",54},{"armenia",374},{"aruba",297},{"australia",61},{"austria",43},{"azerbaijan",994},{"bahamas",1242},{"bahrain",973},{"bangladesh",880},{"barbados",1246},{"belarus",375},{"belgium",32},{"belize",501},{"benin",229},{"bermuda",1441},{"bhutan",975},{"bolivia",591},{"bosnia and herzegovina",387},{"botswana",267},{"brazil",55},{"british indian ocean territory",246},{"british virgin islands",1284},{"brunei",673},{"bulgaria",359},{"burkina faso",226},{"burundi",257},{"cambodia",855},{"cameroon",237},{"canada",1},{"cape verde",238},{"cayman islands",1 - 345},{"central african republic",236},{"chad",235},{"chile",56},{"china",86},{"christmas island",61},{"cocos islands",61},{"colombia",57},{"comoros",269},{"cook islands",682},{"costa rica",506},{"croatia",385},{"cuba",53},{"curacao",599},{"cyprus",357},{"czech republic",420},{"democratic republic of congo",243},{"denmark",45},{"djibouti",253},{"dominica",1767},{"dominican republic",1809},{"east timor",670},{"ecuador",593},{"egypt",20},{"el salvador",503},{"equatorial guinea",240},{"eritrea",291},{"estonia",372},{"ethiopia",251},{"falkland islands",500},{"faroe islands",298},{"fiji",279},{"finland",358},{"france",33},{"french polynesia",689},{"gabon",241},{"gambia",220},{"georgia",995},{"germany",49},{"ghana",233},{"gibraltar",350},{"greece",30},{"greenland",299},{"grenada",1473},{"guam",1671},{"guatemala",502},{"guernsey",441481},{"guinea",224},{"guinea bissau",245},{"guyana",592},{"haiti",509},{"honduras",504},{"hong kong",852},{"hungary",36},{"iceland",354},{"india",91},{"indonesia",62},{"iran",98},{"iraq",964},{"ireland",353},{"isle of man",441624},{"israel",972},{"italy",39},{"ivory coast",225},{"jamaica",1876},{"japan",81},{"jersey",441534},{"jordon",962},{"kazakhstan",7},{"kenya",254},{"kiribati",686},{"kosovo",383},{"kuwait",965},{"kyrgyzstan",996},{"laos",856},{"latvia",371},{"lebanon",961},{"lesotho",266},{"liberia",231},{"libya",218},{"liechtenstein",423},{"lithuania",370},{"luxembourg",352},{"macau",853},{"macedonia",389},{"madagascar",261},{"malawi",265},{"malaysia",60},{"maldives",960},{"mali",223},{"malta",356},{"marshall islands",692},{"mauritania",222},{"mauritius",230},{"mayotte",262},{"mexico",52},{"micronesia",691},{"moldova",373},{"monaco",377},{"mongolia",976},{"montenegro",382},{"montserrat",1664},{"morocco",212},{"mozambique",258},{"myanmar",95},{"namibia",264},{"nauru",674},{"nepal",977},{"netherlands",31},{"netherlands antilles",599},{"new caledonia",687},{"new zealand",64},{"nicaragua",505},{"niger",227},{"niue",683},{"north korea",850},{"northern mariana islands",1670},{"norway",47},{"oman",968},{"pakistan",92},{"palau",680},{"palestine",970},{"panama",507},{"papua new guinea",675},{"paraguay",595},{"peru",51},{"philippines",63},{"pitcairn",64},{"poland",48},{"portugal",351},{"puerto rico",1787},{"qatar",974},{"republic of the congo",242},{"reunion",262},{"romania",40},{"russia",7},{"rwanda",250},{"saint barthelemy",590},{"saint helena",290},{"saint kitts and nevis",1869},{"saint lucia",1758},{"saint martin",590},{"saint pierre and miquelon",508},{"saint vincent and the grenadines",1784},{"samoa",685},{"san marino",378},{"sao tome and principe",239},{"saudi arabia",966},{"senegal",221},{"serbia",381},{"seychelles",248},{"sierra leone",232},{"singapore",65},{"sint maarten",1721},{"slovakia",421},{"slovenia",386},{"solomon islands",667},{"somalia",252},{"south korea",82},{"south sudan",211},{"spain",34},{"sri lanka",94},{"sudan",249},{"suriname",597},{"svalbard and jan mayen",47},{"swaziland",268},{"sweden",46},{"switzerland",268},{"syria",963},{"taiwan",886},{"tajikistan",992},{"tanzania",255},{"thailand",66},{"togo",228},{"tokelau",690},{"tonga",676},{"trinidad and tobago",1868},{"tunisia",216},{"turkey",90},{"turkmenistan",993},{"turks and caicos islands",1649},{"tuvalu",688},{"u.s. virgin islands",1340},{"uganda",256},{"ukraine",380},{"united arab emirates",971},{"united kingdom",44},{"united states",1},{"uruguay",598},{"uzbekistan",998},{"vanuatu",678},{"vatican",379},{"venezuela",58},{"vietnam",84},{"wallis and futuna",681},{"western sahara",212},{"yemen",967},{"zambia",260},{"zimbabwe",263} };
    //Add a function to convert the received country into lowercase. IMPORTANT
    //Implement exception handling here.
    prefix = countries.at(country);      //Assigning to private attribute prefix
}

void Phone::setNumber(std::string input) {
    //Checking if the number entered is of 10 digits or not. If not, then just store -1;
    std::stringstream convert(input);       //Using sstream file
    int num;
    convert >> num;
    number = int(num);
}

int Phone::sendText(std::string text) {
    std::cout << "Sending message " << text << " to : " << prefix << "-" << number;
    std::cout << "\nSent.";
    return 0;
}

std::string Phone::getNumber() {
    return "0";     //Change this later
}
