// Testing Incomplete
#include "..\src\server\api\util\JSON.h"

// Public Implementations
JSON::JSON(JSON::Type wrapper_type) {
	// COMPLETE

	switch (wrapper_type)
	{
	case JSON::ALL_ADM: init_ALL_ADM();
		break;
	case JSON::ALL_SUP: init_ALL_SUP();
		break;
	case JSON::ALL_MOD: init_ALL_MOD();
		break;
	case JSON::ALL_STU: init_ALL_STU();
		break;
	case JSON::ALL_EMP: init_ALL_EMP();
		break;
	case JSON::ALL_GUE: init_ALL_GUE();
		break;
	case JSON::ALL_NET: init_ALL_NET();
		break;
	case JSON::ALL_STD: init_ALL_STD();
		break;
	case JSON::ALL_CYC: init_ALL_CYC();
		break;
	case JSON::ALL_LCK: init_ALL_LCK();
		break;
	case JSON::ALL_TXN: init_ALL_TXN();
		break;
	case JSON::ATR_ADM: init_ATR_ADM();
		break;
	case JSON::ATR_SUP: init_ATR_SUP();
		break;
	case JSON::ATR_MOD: init_ATR_MOD();
		break;
	case JSON::ATR_STU: init_ATR_STU();
		break;
	case JSON::ATR_EMP: init_ATR_EMP();
		break;
	case JSON::ATR_GUE: init_ATR_GUE();
		break;
	case JSON::NET_STAT: init_NET_STAT();
		break;
	case JSON::NET_ADMS: init_NET_ADMS();
		break;
	case JSON::NET_OWN: init_NET_OWN();
		break;
	case JSON::NET_STD: init_NET_STD();
		break;
	case JSON::NET_STD_STAT: init_NET_STD_STAT();
		break;
	case JSON::NET_NEAR_STD: init_NET_NEAR_STD();
		break;
	case JSON::NET_STD_VACANT: init_NET_STD_VACANT();
		break;
	case JSON::NET_CYC: init_NET_CYC();
		break;
	case JSON::NET_CYC_FREE: init_NET_CYC_FREE();
		break;
	case JSON::NET_LCK: init_NET_LCK();
		break;
	case JSON::NET_LCK_STAT: init_NET_LCK_STAT();
		break;
	case JSON::TXN: init_TXN();
		break;
	case JSON::NET_USR_TXN: init_NET_USR_TXN();
		break;
	case JSON::NET_STD_TXN: init_NET_STD_TXN();
		break;
	case JSON::NET_CYC_TXN: init_NET_CYC_TXN();
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
		_DATA = m_default_tag_list.at(TAG);
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
	for (auto each : m_default_tag_list) {
		if (each.second == "")
			empty_tags_list.emplace_back(each.first);
	}
	for (auto each : m_custom_tag_list) {
		if (each.second == "")
			empty_tags_list.emplace_back(each.first);
	}

	return empty_tags_list;
}

void JSON::fill_empty_tags(std::string fill_with = "0") {
	// COMPLETE

	for (auto each : m_default_tag_list) {
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

	for (auto each : m_default_tag_list)
		if (each.second != "")
			default_has_empty = true;
	for (auto each : m_custom_tag_list)
		if (each.second == "")
			custom_has_empty = true;

	return (default_has_empty && custom_has_empty);
}

inline size_t JSON::length() const {
	// COMPLETE

	return ( m_default_tag_list.size() + m_custom_tag_list.size() );
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

	std::string serailized_data = "{ " +  m_prefix;
	for (auto each : m_default_tag_list) {
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
	for (auto each : m_default_tag_list) {
		tag_list.emplace_back(each.first);
	}
	for (auto each : m_custom_tag_list) {
		tag_list.emplace_back(each.first);
	}

	return tag_list;
}

std::string JSON::type() const { return m_type; }

// Private Implementations
void JSON::init_ALL_ADM() {
	/*
	* SAMPLE_DATA : "#ALL_ADM, count, 0:(BIDxxxxxxxxxx,Name,AID), 1:(BIDxxxxxxxxxx,Name,AID), ... n:(BIDxxxxxxxxxx,Name,AID)"
	* 
	* TAG_LIST
	* 0:(BIDxxxxxxxxxx,Name,AID)
	* 1:(BIDxxxxxxxxxx,Name,AID)
	* 2:(BIDxxxxxxxxxx,Name,AID)
	* ...
	* n:(BIDxxxxxxxxxx,Name,AID)
	*/
	m_prefix = "#ALL_ADM";
	m_type = "string";
	//m_default_tag_list["0"] = "";
}

void JSON::init_ALL_SUP() {
	// Do something good today. Before it's too late
}
void JSON::init_ALL_MOD() {
	// Do something good today. Before it's too late
}
void JSON::init_ALL_STU() {
	// Do something good today. Before it's too late
}
void JSON::init_ALL_EMP() {
	// Do something good today. Before it's too late
}
void JSON::init_ALL_GUE() {
	// Do something good today. Before it's too late
}
void JSON::init_ALL_NET() {
	// Do something good today. Before it's too late
}
void JSON::init_ALL_STD() {
	// Do something good today. Before it's too late
}
void JSON::init_ALL_CYC() {
	// Do something good today. Before it's too late
}
void JSON::init_ALL_LCK() {
	// Do something good today. Before it's too late
}
void JSON::init_ALL_TXN() {
	// Do something good today. Before it's too late
}

void JSON::init_ATR_ADM() {
	// Do something good today. Before it's too late
}
void JSON::init_ATR_SUP() {
	// Do something good today. Before it's too late
}
void JSON::init_ATR_MOD() {
	// Do something good today. Before it's too late
}
void JSON::init_ATR_STU() {
	// Do something good today. Before it's too late
}
void JSON::init_ATR_EMP() {
	// Do something good today. Before it's too late
}
void JSON::init_ATR_GUE() {
	// Do something good today. Before it's too late
}

void JSON::init_NET_STAT() {
	// Do something good today. Before it's too late
}
void JSON::init_NET_ADMS() {
	// Do something good today. Before it's too late
}
void JSON::init_NET_OWN() {
	// Do something good today. Before it's too late
}

void JSON::init_NET_STD() {
	// Do something good today. Before it's too late
}
void JSON::init_NET_STD_STAT() {
	// Do something good today. Before it's too late
}
void JSON::init_NET_NEAR_STD() {
	// Do something good today. Before it's too late
}
void JSON::init_NET_STD_VACANT() {
	// Do something good today. Before it's too late
}

void JSON::init_NET_CYC() {
	// Do something good today. Before it's too late
}
void JSON::init_NET_CYC_FREE() {
	// Do something good today. Before it's too late
}

void JSON::init_NET_LCK() {
	// Do something good today. Before it's too late
}
void JSON::init_NET_LCK_STAT() {
	// Do something good today. Before it's too late
}

void JSON::init_TXN() {
	// Do something good today. Before it's too late
}
void JSON::init_NET_USR_TXN() {
	// Do something good today. Before it's too late
}
void JSON::init_NET_STD_TXN() {
	// Do something good today. Before it's too late
}
void JSON::init_NET_CYC_TXN() {
	// Do something good today. Before it's too late
}

void JSON::m_add_tag(std::string tag_to_add, std::string data_for_tag) {
	// Do something good today. Before it's too late
}
void JSON::m_remove_tag(std::string tag_to_remove) {
	// Do something good today. Before it's too late
}