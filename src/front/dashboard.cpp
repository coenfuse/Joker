#include <iostream>
#include <time.h>
#include <string>
#include <JSON.h>
#include "graphics.h"
#include "access.h"


short dashboard_adm(JSON_adm adm_data, std::string session_code) { //INCOMPLETE
	std::cout << session_code << std::endl;
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

short dashboard_stu(JSON_stu stu_data, std::string session_code) { //INCOMPLETE
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

short dashboard_emp(JSON_emp stu_data, std::string session_code) { // INCOMPLETE
	std::cout << session_code << std::endl;
	return 1;
}

short dashboard_sup(JSON_sup sup_data, std::string session_code) { // INCOMPLETE
	return 1;
}

short dashboard_mod(JSON_mod mod_data, std::string session_code) { // INCOMPLETE
	return 1;
}

short dashboard_gue(JSON_guest guest_data, std::string session_code) { // INCOMPLETE
	return 1;
}