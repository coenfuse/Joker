#include "..\src\server\api\util\JSON.h"


// Public Implementations
JSON::JSON(JSON::Type wrapper_type) {
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

bool JSON::has_empty_tag() {
	// INCOMPLETE
	return true;
}

inline size_t JSON::length() {
	return (m_default_tags + m_custom_tags);
}

void JSON::remove(std::string to_remove_tag) {
	if (m_custom_tags > 0) {
		// Cannot delete only custom_tag
	}
}

// Private Implementations
void JSON::init_ALL_ADM() {
	// Do something good today. Before it's too late
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