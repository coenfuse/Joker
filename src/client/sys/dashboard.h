#pragma once
#include "..\src\server\api\util\JSON.h"
#include <string>

short dashboard_adm(std::string, std::string);
short dashboard_stu(JSON, std::string);
short dashboard_emp(JSON, std::string);
short dashboard_sup(JSON, std::string);
short dashboard_mod(JSON, std::string);
short dashboard_guest(JSON, std::string);
