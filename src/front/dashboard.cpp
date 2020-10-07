#include <iostream>
#include <time.h>
#include <string>
#include <JSON.h>
#include "graphics.h"
#include "access.h"


short dashboard(JSON atr, short type, std::string session_code) { //INCOMPLETE
	std::cout << session_code << std::endl;
	switch (type)
	{
	case 1: { // Dashboard for Admin. INCOMPLETE
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

	}
		  break;
	case 2: { // Dashboard for Support. INCOMPLETE

	}
		  break;
	case 3: { // Dashboard for Moderator. INCOMPLETE

	}
		  break;
	case 4: { // Dashboard for Student. INCOMPLETE
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

	}
		  break;
	case 5: { // Dashboard for Employee. INCOMPLETE

	}
		  break;
	case 6: { // Dashboard for Guest. INCOMPLETE

	}
	default: std::cout << "Abnormal behavior. System will terminate. Error Code: F100" << std::endl;
	}/*
	time_t session_start = time(NULL); //Log session starting time
	time_t session_end = time(NULL); //Log session ending time
	time_t session_dur = difftime(session_start, session_end); //Find session duration
	*/
	return 1;
}