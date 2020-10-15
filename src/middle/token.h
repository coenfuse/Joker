#pragma once

#include <map>
#include <string>

// A simple access and session tokens generator that supports Bapi and is passed to Frontend.

class Token
{
	//INCOMPLETE
	// Method declarations
private:
	void fill();
public:
	bool checkAccess(std::string);
	bool checkSession(std::string);
	bool checkOTP(std::string);
	std::string giveAccess();
	std::string giveSession();
	std::string giveOTP();
	void log();
	Token();
	~Token();

	// Attribute declarations
private:
	// Would ofcourse change the datatype used here as I learn more stuff.
	// Consider using Tries or Hash Tables.
	std::map <std::string, std::string> m_session;
	std::map <std::string, std::string> m_access;
	std::string OTP;
};
