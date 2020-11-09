#include <iostream>
#include <time.h>
#include <string>
#include "..\src\server\api\util\JSON.h"
//#include "..\src\client\util\json\JSON.h"
#include "..\src\client\vfx\graphics.h"
#include "..\src\client\cred\access.h"


short dashboard_adm(std::string adm_data, std::string session_code) { //INCOMPLETE
	std::cout << session_code << std::endl;
	std::cout << adm_data << std::endl;
	// Dashboard for Admin. INCOMPLETE
		/*
		settings
			update admin
		notifications
		network
			database
				updateDatabase
				deleteDatabase
				repairDatabase
				restoreDatabase
				importDatabase
				exportDatabase
			createNetwork
			updateNetwork
			deleteNetwork
			repairNetwork
			restoreNetwork
			exportNetwork
		admins
			getAdmins
			getAdmin
			updateAdmin
			createAdmin
			createAdmin
			deleteAdmin
			exportAdmin
		support
		moderator
		student
			getStudents
			getStudent
			updateStudents
			updateStudent
			createStudents
			createStudent
			deleteStudents
			deleteStudent
			exportStudents
			exportStudent
			restoreStudents
			restoreStudent
			repairStudents
			repairStudent
			getStats
			exportStats
		employee
		guest
			getAllGuests
			getGuests
			getGuest
			exportGuest
			exportGuest
		*/
	/*time_t session_start = time(NULL); //Log session starting time
	time_t session_end = time(NULL); //Log session ending time
	time_t session_dur = difftime(session_start, session_end); //Find session duration*/
	return 1;
}

short dashboard_stu(JSON stu_data, std::string session_code) { //INCOMPLETE
	std::cout << session_code << std::endl;
	/*
		student
			getStats
			getHistory
			getFullHistory
			getCredentials
			updateCredentials
			getStatus
			updateStatus
			getPassword
			updatePassword
			deletePassword
			checkLinking
			exportStats
			exportData
		notification
		network
			getStats
			getNetwork
		issue
			issueCycle
		deposit
			depositCycle
		support
			ticket
				postTicket
				getTicket
				updateTicket
			feedback
				postFeedback
		*/
	return 1;
}

short dashboard_emp(JSON stu_data, std::string session_code) { // INCOMPLETE
	std::cout << session_code << std::endl;
	return 1;
}

short dashboard_sup(JSON sup_data, std::string session_code) { // INCOMPLETE
	return 1;
}

short dashboard_mod(JSON mod_data, std::string session_code) { // INCOMPLETE
	return 1;
}

short dashboard_gue(JSON guest_data, std::string session_code) { // INCOMPLETE
	return 1;
}