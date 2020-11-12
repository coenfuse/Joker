// Testing Incomplete
#include "..\src\server\api\util\JSON.h"

// Public Implementations
JSON::JSON(JSON::Type wrapper_type) {
	// COMPLETE

	switch (wrapper_type)
	{
	case JSON::Type::ALL_ADM: {
		m_prefix = JSON::prefix_type::_PTYPE_ALL_ADM;
		m_type = _DATA_TYPE.ALL_DATA;
	}
		break;
	case JSON::Type::ALL_SUP: {
		m_prefix = JSON::prefix_type::_PTYPE_ALL_SUP;
		m_type = _DATA_TYPE.ALL_DATA;
	}
		break;
	case JSON::Type::ALL_MOD: {
		m_prefix = JSON::prefix_type::_PTYPE_ALL_MOD;
		m_type = _DATA_TYPE.ALL_DATA;
	}
		break;
	case JSON::Type::ALL_STU: {
		m_prefix = JSON::prefix_type::_PTYPE_ALL_STU;
		m_type = _DATA_TYPE.ALL_DATA;
	}
		break;
	case JSON::Type::ALL_EMP: {
		m_prefix = JSON::prefix_type::_PTYPE_ALL_EMP;
		m_type = _DATA_TYPE.ALL_DATA;
	}
		break;
	case JSON::Type::ALL_GUE: {
		m_prefix = JSON::prefix_type::_PTYPE_ALL_GUE;
		m_type = _DATA_TYPE.ALL_DATA;
	}
		break;
	case JSON::Type::ALL_NET: {
		m_prefix = JSON::prefix_type::_PTYPE_ALL_NET;
		m_type = _DATA_TYPE.ALL_DATA;;
	}
		break;
	case JSON::Type::ALL_STD: {
		m_prefix = JSON::prefix_type::_PTYPE_ALL_STD;
		m_type = _DATA_TYPE.ALL_DATA;;
	}
		break;
	case JSON::Type::ALL_CYC: {
		m_prefix = JSON::prefix_type::_PTYPE_ALL_CYC;
		m_type = _DATA_TYPE.ALL_DATA;;
	}
		break;
	case JSON::Type::ALL_LCK: {
		m_prefix = JSON::prefix_type::_PTYPE_ALL_LCK;
		m_type = _DATA_TYPE.ALL_DATA;;
	}
		break;
	case JSON::Type::ALL_TXN: {
		m_prefix = JSON::prefix_type::_PTYPE_ALL_TXN;
		m_type = _DATA_TYPE.ALL_DATA;;
	}
		break;
	case JSON::Type::ATR_ADM: {
		m_prefix = JSON::prefix_type::_PTYPE_ATR_ADM;
		m_type = _DATA_TYPE.USR_DATA;
	}
		break;
	case JSON::Type::ATR_SUP: {
		m_prefix = JSON::prefix_type::_PTYPE_ATR_SUP;
		m_type = _DATA_TYPE.USR_DATA;
	}
		break;
	case JSON::Type::ATR_MOD: {
		m_prefix = JSON::prefix_type::_PTYPE_ATR_MOD;
		m_type = _DATA_TYPE.USR_DATA;
	}
		break;
	case JSON::Type::ATR_STU: {
		m_prefix = JSON::prefix_type::_PTYPE_ATR_STU;
		m_type = _DATA_TYPE.USR_DATA;
	}
		break;
	case JSON::Type::ATR_EMP: {
		m_prefix = JSON::prefix_type::_PTYPE_ATR_EMP;
		m_type = _DATA_TYPE.USR_DATA;
	}
		break;
	case JSON::Type::ATR_GUE: {
		m_prefix = JSON::prefix_type::_PTYPE_ATR_GUE;
		m_type = _DATA_TYPE.USR_DATA;
	}
		break;
	case JSON::Type::NET_STAT: {
		m_prefix = JSON::prefix_type::_PTYPE_NET_STAT;
		m_type = _DATA_TYPE.NET_DATA;
	}
		break;
	case JSON::Type::NET_ADMS: {
		m_prefix = JSON::prefix_type::_PTYPE_NET_ADMS;
		m_type = "NET_ADMS";
	}
		break;
	case JSON::Type::NET_OWN: {
		m_prefix = JSON::prefix_type::_PTYPE_NET_OWN;
		m_type = "NET_OWN";
	}
		break;
	case JSON::Type::NET_STD: {
		m_prefix = JSON::prefix_type::_PTYPE_NET_STD;
		m_type = "NET_STD";
	}
		break;
	case JSON::Type::NET_STD_STAT: {
		m_prefix = JSON::prefix_type::_PTYPE_NET_STD_STAT;
		m_type = "NET_STD_STAT";
	}
		break;
	case JSON::Type::NET_NEAR_STD: {
		m_prefix = JSON::prefix_type::_PTYPE_NET_NEAR_STD;
		m_type = "NET_NEAR_STD";
	}
		break;
	case JSON::Type::NET_STD_VACANT: {
		m_prefix = JSON::prefix_type::_PTYPE_NET_STD_VACANT;
		m_type = "NET_STD_VACANT";
	}
		break;
	case JSON::Type::NET_CYC: {
		m_prefix = JSON::prefix_type::_PTYPE_NET_CYC;
		m_type = "NET_CYC";
	}
		break;
	case JSON::Type::NET_CYC_FREE: {
		m_prefix = JSON::prefix_type::_PTYPE_NET_CYC_FREE;
		m_type = "NET_CYC_FREE";
	}
		break;
	case JSON::Type::NET_LCK: {
		m_prefix = JSON::prefix_type::_PTYPE_NET_LCK;
		m_type = "NET_LCK";
	}
		break;
	case JSON::Type::NET_LCK_STAT: {
		m_prefix = JSON::prefix_type::_PTYPE_NET_LCK_STAT;
		m_type = "NET_LCK_STAT";
	}
		break;
	case JSON::Type::TXN: {
		m_prefix = JSON::prefix_type::_PTYPE_TXN;
		m_type = "TXN";
	}
		break;
	case JSON::Type::NET_USR_TXN: {
		m_prefix = JSON::prefix_type::_PTYPE_NET_USR_TXN;
		m_type = "NET_USR_TXN";
	}
		break;
	case JSON::Type::NET_STD_TXN: {
		m_prefix = JSON::prefix_type::_PTYPE_NET_STD_TXN;
		m_type = "NET_STD_TXN";
	}
		break;
	case JSON::Type::NET_CYC_TXN: {
		m_prefix = JSON::prefix_type::_PTYPE_NET_CYC_TXN;
		m_type = "NET_CYC_TXN";
	}
		break;
	default:
		break;
	}
}

JSON::~JSON() {

}

std::string JSON::at(std::string TAG) const {
	// COMPLETE

	std::string _DATA = "0";
	try {
		_DATA = m_default_container.at(TAG);
	}
	catch (...) {
		try {
			_DATA = m_custom_tag_list.at(TAG);
		}
		catch (...) {
			return _DATA;
		}
		return _DATA;
	}
	return _DATA;	// Flow reaches here if m_default_tag_list contains the TAG specified.
}

void JSON::add(std::string custom_tag){
	// COMPLETE
	if  (m_custom_tag_list.find(custom_tag) != m_custom_tag_list.end()) {
		std::pair<std::string, std::string> data_pair = { custom_tag, "" };
		m_custom_tag_list.insert(data_pair);
	}
}

void JSON::add(std::string custom_tag, std::string data_attached) {
	// COMPLETE
	if (m_custom_tag_list.find(custom_tag) != m_custom_tag_list.end()) {
		std::pair<std::string, std::string> data_pair = { custom_tag, data_attached };
		m_custom_tag_list.insert(data_pair);
	}
	m_custom_tag_list[custom_tag] = data_attached;	// Overwrites new data to the key.
}

std::list<std::string> JSON::empty_tags() {
	// COMPLETE

	std::list<std::string> empty_tags_list = {""};
	for (auto each : m_default_container) {
		if (each.second == "")
			empty_tags_list.emplace_back(each.first);
	}
	for (auto each : m_custom_tag_list) {
		if (each.second == "")
			empty_tags_list.emplace_back(each.first);
	}

	return empty_tags_list;
}

void JSON::fill_empty_tags(std::string fill_with) {
	// COMPLETE

	for (auto each : m_default_container) {
		if (each.second == "")
			add(each.first, fill_with);
	}
	for (auto each : m_custom_tag_list) {
		if (each.second == "")
			add(each.first, fill_with);
	}
}

bool JSON::has_empty_tag() {
	// COMPLETE

	bool default_has_empty = false;
	bool custom_has_empty = false;

	for (auto each : m_default_container)
		if (each.second != "")
			default_has_empty = true;
	for (auto each : m_custom_tag_list)
		if (each.second == "")
			custom_has_empty = true;

	return (default_has_empty && custom_has_empty);
}

void JSON::insert(std::string input_data) {
	// INCOMPLETE
	// TODO: Create a parser inside this function that'll verify and concatenate all the data received.
	// TODO: This needs to be a variable input function.
	
	switch (m_prefix)
	{
	case JSON::JSON::prefix_type::_PTYPE_empty:	// At this case, no data will be inserted.
		break;
	case JSON::JSON::prefix_type::_PTYPE_ALL_ADM: {
		// Add parsing, data consistency checking here.
		// Upon success, create a concatenated input_data string that'll
		// be passed to the function below.
		add_ALL_ADM(input_data);
	}
		break;
	case JSON::prefix_type::_PTYPE_ALL_SUP: add_ALL_SUP(input_data);
		break;
	case JSON::prefix_type::_PTYPE_ALL_MOD:
		break;
	case JSON::prefix_type::_PTYPE_ALL_STU:
		break;
	case JSON::prefix_type::_PTYPE_ALL_EMP:
		break;
	case JSON::prefix_type::_PTYPE_ALL_GUE:
		break;
	case JSON::prefix_type::_PTYPE_ALL_NET:
		break;
	case JSON::prefix_type::_PTYPE_ALL_STD:
		break;
	case JSON::prefix_type::_PTYPE_ALL_CYC:
		break;
	case JSON::prefix_type::_PTYPE_ALL_LCK:
		break;
	case JSON::prefix_type::_PTYPE_ALL_TXN:
		break;
	case JSON::prefix_type::_PTYPE_ATR_ADM:
		break;
	case JSON::JSON::prefix_type::_PTYPE_ATR_SUP:
		break;
	case JSON::prefix_type::_PTYPE_ATR_MOD:
		break;
	case JSON::prefix_type::_PTYPE_ATR_STU:
		break;
	case JSON::prefix_type::_PTYPE_ATR_EMP:
		break;
	case JSON::prefix_type::_PTYPE_ATR_GUE:
		break;
	case JSON::prefix_type::_PTYPE_NET_STAT:
		break;
	case JSON::prefix_type::_PTYPE_NET_ADMS:
		break;
	case JSON::prefix_type::_PTYPE_NET_OWN:
		break;
	case JSON::prefix_type::_PTYPE_NET_STD:
		break;
	case JSON::prefix_type::_PTYPE_NET_STD_STAT:
		break;
	case JSON::prefix_type::_PTYPE_NET_NEAR_STD:
		break;
	case JSON::prefix_type::_PTYPE_NET_STD_VACANT:
		break;
	case JSON::prefix_type::_PTYPE_NET_CYC:
		break;
	case JSON::prefix_type::_PTYPE_NET_CYC_FREE:
		break;
	case JSON::prefix_type::_PTYPE_NET_LCK:
		break;
	case JSON::prefix_type::_PTYPE_NET_LCK_STAT:
		break;
	case JSON::prefix_type::_PTYPE_TXN:
		break;
	case JSON::prefix_type::_PTYPE_NET_USR_TXN:
		break;
	case JSON::prefix_type::_PTYPE_NET_STD_TXN:
		break;
	case JSON::prefix_type::_PTYPE_NET_CYC_TXN:
		break;
	default:
		break;
	}
}

bool JSON::is_type(std::string given_type) {
	return (m_type == given_type);
}

inline size_t JSON::length() const {
	// COMPLETE

	return ( m_default_container.size() + m_custom_tag_list.size() );
}

bool JSON::remove(std::string to_remove_tag) {
	// COMPLETE

	if (m_custom_tag_list.size() > 0) {
		try {
			m_custom_tag_list.erase(to_remove_tag);
		}
		catch (...) {
			// Exception Caught
			return false;
		}
		return true;
	}
	return false;
}

std::string JSON::serialize() {
	// COMPLETE
	std::string serailized_data = "{ " + int(m_prefix);
	for (auto each : m_default_container) {
		serailized_data += "\"" + each.first + "\":\"" + each.second + ", ";
	}
	for (auto each : m_custom_tag_list) {
		serailized_data += "\"" + each.first + "\":\"" + each.second + ",";
	}

	return serailized_data.substr(0,serailized_data.length()-1) + " }";
}

std::list<std::string> JSON::tag_list() {
	// COMPLETE

	std::list<std::string> tag_list;
	for (auto each : m_default_container) {
		tag_list.emplace_back(each.first);
	}
	for (auto each : m_custom_tag_list) {
		tag_list.emplace_back(each.first);
	}

	return tag_list;
}

std::string JSON::type() const { return m_type; }

// Private Implementations

void JSON::add_ALL_ADM(std::string input_data) {
	/*
	* SAMPLE_DATA : "#ALL_ADM, count:'xxxx', 00:(BIDxxxxxxxxxx,Name,AID), 01:(BIDxxxxxxxxxx,Name,AID), ... n:(BIDxxxxxxxxxx,Name,AID)"
	*
	* TAG_LIST
	* 00:(BIDxxxxxxxxxx,Name,AID)
	* 01:(BIDxxxxxxxxxx,Name,AID)
	* ...
	* 09:(BIDxxxxxxxxxx,Name,AID)
	*/

	size_t size = m_default_container.size();
	std::string TAG;

	if (size < 10)
		TAG = "0" + std::to_string(size);
	else
		TAG = std::to_string(size);

	try {
		m_default_container[TAG] = input_data;
	}
	catch (...) {
		// Handled any exception
	}
}
void JSON::add_ALL_SUP(std::string input_data) {
	/*
	* SAMPLE_DATA : "#ALL_SUP, count:'xxxx', 00:(BIDxxxxxxxxxx,Name,SUP), 01:(BIDxxxxxxxxxx,Name,SUP), ... n:(BIDxxxxxxxxxx,Name,SUP)"
	*
	* TAG_LIST
	* 00:(BIDxxxxxxxxxx,Name,SUP)
	* 01:(BIDxxxxxxxxxx,Name,SUP)
	* ...
	* 09:(BIDxxxxxxxxxx,Name,SUP)
	*/

	size_t size = m_default_container.size();
	std::string TAG;

	if (size < 10)
		TAG = "0" + std::to_string(size);
	else
		TAG = std::to_string(size);

	try {
		m_default_container[TAG] = input_data;
	}
	catch (...) {
		// Handled any exception
	}
}
void JSON::add_ALL_MOD(std::string input_data) {
	/*
	* SAMPLE_DATA : "#ALL_MOD, count:'xxxx', 00:(BIDxxxxxxxxxx,Name,MOD), 01:(BIDxxxxxxxxxx,Name,MOD), ... n:(BIDxxxxxxxxxx,Name,MOD)"
	*
	* TAG_LIST
	* 00:(BIDxxxxxxxxxx,Name,MOD)
	* 01:(BIDxxxxxxxxxx,Name,MOD)
	* ...
	* 09:(BIDxxxxxxxxxx,Name,MOD)
	*/

	size_t size = m_default_container.size();
	std::string TAG;

	if (size < 10)
		TAG = "0" + std::to_string(size);
	else
		TAG = std::to_string(size);

	try {
		m_default_container[TAG] = input_data;
	}
	catch (...) {
		// Handled all exceptions.
	}
}
void JSON::add_ALL_STU(std::string input_data) {
	/*
	* SAMPLE_DATA : "#ALL_STU, count:'xxxx', 0:(BIDxxxxxxxxxx,Name,SID), 1:(BIDxxxxxxxxxx,Name,SID), ... n:(BIDxxxxxxxxxx,Name,SID)"
	*
	* TAG_LIST
	* 00:(BIDxxxxxxxxxx,Name,SID)
	* 01:(BIDxxxxxxxxxx,Name,SID)
	* ...
	* n:(BIDxxxxxxxxxx,Name,SID)
	*/

	size_t size = m_default_container.size();
	std::string TAG;

	if (size < 10)
		TAG = "0" + std::to_string(size);
	else
		TAG = std::to_string(size);

	try {
		m_default_container[TAG] = input_data;
	}
	catch (...) {
		// Handled all exceptions.
	}
}
void JSON::add_ALL_EMP(std::string input_data) {
	/*
	* SAMPLE_DATA : "#ALL_EMP, count:'xxxx', 0:(BIDxxxxxxxxxx,Name,EID), 1:(BIDxxxxxxxxxx,Name,EID), ... n:(BIDxxxxxxxxxx,Name,EID)"
	*
	* TAG_LIST
	* 00:(BIDxxxxxxxxxx,Name,EID)
	* 01:(BIDxxxxxxxxxx,Name,EID)
	* ...
	* n:(BIDxxxxxxxxxx,Name,EID)
	*/

	size_t size = m_default_container.size();
	std::string TAG;

	if (size < 10)
		TAG = "0" + std::to_string(size);
	else
		TAG = std::to_string(size);

	try {
		m_default_container[TAG] = input_data;
	}
	catch (...) {
		// Handled all exceptions.
	}
}
void JSON::add_ALL_GUE(std::string input_data) {
	/*
	* SAMPLE_DATA : "#ALL_EMP, count:'xxxx', 00:(BGIDxxxxxxxxxx,Name,Duration), 01:(BIDxxxxxxxxxx,Name,Duration), ... n:(BIDxxxxxxxxxx,Name,Duration)"
	*
	* TAG_LIST
	* 00:(BGIDxxxxxxxxxx,Name,Duration)
	* 01:(BGIDxxxxxxxxxx,Name,Duration)
	* ...
	* n:(BGIDxxxxxxxxxx,Name,Duration)
	*/

	size_t size = m_default_container.size();
	std::string TAG;

	if (size < 10)
		TAG = "0" + std::to_string(size);
	else
		TAG = std::to_string(size);

	try {
		m_default_container[TAG] = input_data;
	}
	catch (...) {
		// Handled all exceptions.
	}
}
void JSON::add_ALL_NET(std::string input_data) {
	/*
	* SAMPLE_DATA : "#ALL_NET, count:'xxxx', 00:(NETxxxx,Name,ORG,User_Count), 01:(NETxxxx,Name,ORG,User_Count), ... n:(NETxxxx,Name,ORG,User_Count)
	*
	* TAG_LIST
	* 00:(NETxxxx,Name,ORG,User_Count)
	* 01:(NETxxxx,Name,ORG,User_Count)
	* ...
	* n:(NETxxxx,Name,ORG,User_Count)
	*/

	size_t size = m_default_container.size();
	std::string TAG;

	if (size < 10)
		TAG = "0" + std::to_string(size);
	else
		TAG = std::to_string(size);

	try {
		m_default_container[TAG] = input_data;
	}
	catch (...) {
		// Handled all exceptions.
	}
}
void JSON::add_ALL_STD(std::string input_data) {
	/*
	* SAMPLE_DATA : "#ALL_STD, count:'xxxx', 00:'STDxxxxxxxxxx', 01:'STDxxxxxxxxxx', ... n:'STDxxxxxxxxxx'"
	*
	* TAG_LIST
	* 00:'STDxxxxxxxxxx'
	* 01:'STDxxxxxxxxxx'
	* ...
	* n:'STDxxxxxxxxxx'
	*/

	size_t size = m_default_container.size();
	std::string TAG;

	if (size < 10)
		TAG = "0" + std::to_string(size);
	else
		TAG = std::to_string(size);

	try {
		m_default_container[TAG] = input_data;
	}
	catch (...) {
		// Handled all exceptions.
	}
}
void JSON::add_ALL_CYC(std::string input_data) {
	/*
	* SAMPLE_DATA : "#ALL_CYC, count:'xxxx', 00:'CYCxxxxxxxxxx', 01:'CYCxxxxxxxxxx', ... n:'CYCxxxxxxxxxx'"
	*
	* TAG_LIST
	* 00:'CYCxxxxxxxxxx'
	* 01:'CYCxxxxxxxxxx'
	* ...
	* n:'CYCxxxxxxxxxx'
	*/

	size_t size = m_default_container.size();
	std::string TAG;

	if (size < 10)
		TAG = "0" + std::to_string(size);
	else
		TAG = std::to_string(size);

	try {
		m_default_container[TAG] = input_data;
	}
	catch (...) {
		// Handled all exceptions.
	}
}
void JSON::add_ALL_LCK(std::string input_data) {

	// INCOMPLETE

	/*
	* SAMPLE_DATA : "#ALL_LCK, count:'xxxx', 0:(STDxxxxxxxxxx,LCKxxxxxxxxxx,...LCKxxxxxxxxxx), 1:(STDxxxxxxxxxx,LCKxxxxxxxxxx,...LCKxxxxxxxxxx), ... n:(STDxxxxxxxxxx,LCKxxxxxxxxxx,...LCKxxxxxxxxxx)"
	*
	* TAG_LIST
	* STDxxxx:(LCKxxxxxxxxxx,...LCKxxxxxxxxxx)
	* STDxxxx:(LCKxxxxxxxxxx,...LCKxxxxxxxxxx)
	* ...
	* STDxxxx:(LCKxxxxxxxxxx,...LCKxxxxxxxxxx)
	*/

	size_t size = m_default_container.size();
	std::string TAG;

	if (size < 10)
		TAG = "0" + std::to_string(size);
	else
		TAG = std::to_string(size);

	try {
		m_default_container[TAG] = input_data;
	}
	catch (...) {
		// Handled all exceptions.
	}
}
void JSON::add_ALL_TXN(std::string input_data) {

	// INCOMPLETE

	/*
	* SAMPLE_DATA : "#ALL_TXN, TIME:'00:00:00,DD/MMM/YYYY', count:'xxxx', 0:(TXNxxxxxxxxxx,BIDxxxxxxxxxx,issue or deposit,'00:00:00,DD/MMM/YYYY'), 1:(TXNxxxxxxxxxx,BIDxxxxxxxxxx,issue or deposit,'00:00:00,DD/MMM/YYYY'), ... n:(TXNxxxxxxxxxx,BIDxxxxxxxxxx,issue or deposit,'00:00:00,DD/MMM/YYYY')"
	*
	* TAG_LIST
	* 00:(TXNxxxxxxxxxx,BIDxxxxxxxxxx,issue or deposit,'00:00:00,DD/MMM/YYYY')
	* 01:(TXNxxxxxxxxxx,BIDxxxxxxxxxx,issue or deposit,'00:00:00,DD/MMM/YYYY')
	* ...
	* n:(TXNxxxxxxxxxx,BIDxxxxxxxxxx,issue or deposit,'00:00:00,DD/MMM/YYYY')
	*/

	size_t size = m_default_container.size();
	std::string TAG;

	if (size < 10)
		TAG = "0" + std::to_string(size);
	else
		TAG = std::to_string(size);

	try {
		m_default_container[TAG] = input_data;
	}
	catch (...) {
		// Handled all exceptions.
	}
}

void JSON::add_ATR_ADM() {
	// Do something good today. Before it's too late
}
void JSON::add_ATR_SUP() {
	// Do something good today. Before it's too late
}
void JSON::add_ATR_MOD() {
	// Do something good today. Before it's too late
}
void JSON::add_ATR_STU() {
	// Do something good today. Before it's too late
}
void JSON::add_ATR_EMP() {
	// Do something good today. Before it's too late
}
void JSON::add_ATR_GUE() {
	// Do something good today. Before it's too late
}

void JSON::add_NET_STAT() {
	// Do something good today. Before it's too late
}
void JSON::add_NET_ADMS() {
	// Do something good today. Before it's too late
}
void JSON::add_NET_OWN() {
	// Do something good today. Before it's too late
}

void JSON::add_NET_STD() {
	// Do something good today. Before it's too late
}
void JSON::add_NET_STD_STAT() {
	// Do something good today. Before it's too late
}
void JSON::add_NET_NEAR_STD() {
	// Do something good today. Before it's too late
}
void JSON::add_NET_STD_VACANT() {
	// Do something good today. Before it's too late
}

void JSON::add_NET_CYC() {
	// Do something good today. Before it's too late
}
void JSON::add_NET_CYC_FREE() {
	// Do something good today. Before it's too late
}

void JSON::add_NET_LCK() {
	// Do something good today. Before it's too late
}
void JSON::add_NET_LCK_STAT() {
	// Do something good today. Before it's too late
}

void JSON::add_TXN() {
	// Do something good today. Before it's too late
}
void JSON::add_NET_USR_TXN() {
	// Do something good today. Before it's too late
}
void JSON::add_NET_STD_TXN() {
	// Do something good today. Before it's too late
}
void JSON::add_NET_CYC_TXN() {
	// Do something good today. Before it's too late
}

void JSON::m_add_tag(std::string tag_to_add, std::string data_for_tag) {
	// Do something good today. Before it's too late
}
void JSON::m_remove_tag(std::string tag_to_remove) {
	// Do something good today. Before it's too late
}