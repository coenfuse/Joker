#include "..\src\client\util\json\JSON.h"
#include <map>
#include <string>

JSON_bulk::JSON_bulk(std::string bulk_data, short key){
	switch (key)
	{
	case 1: { // Parser for users
		/*	Inserting values into map.
		*	data["key"]=100;	<--- This is for type <string,int>
		*	data["key"]="value"; or data["key"]=["value"];
		*	Use a loop to that will run for 'amount of keys' present in bulk_data.
		*	
		*	Other syntax:
		*	map<char, int> map2 (map1.begin(), map1.end()); // Creates a map map2 which have entries copied from map1.begin() to map1.end()
		*	
		*	map<char, int> map3 (m); // Creates a map map3 which is a copy of map m.
		*/

	}
		break;
	case 2: { // Parser for stands

	}
		break;
	case 3: { // Parser for cycles

	}
		break;
	case 4: { // Parser for locks

	}
		  break;
	// Other parsers will be added as the network will support more functionalities
	default: { // Throw error code F103

	}
		break;
	}
}

JSON_bulk::~JSON_bulk() {

}

std::string JSON_bulk::getVal(std::string key) {
	return data.at(key);
}