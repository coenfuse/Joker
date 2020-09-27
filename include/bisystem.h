#ifndef BI_SYSTEM_H
#define BI_SYSTEM_H
#include<string>

	#ifndef ACCESS_H
	#define ACCESS_H
		const std::string access_code = "Cmh3gdcQx&XZVbDQFQgcoen>9&kXUQ69u*(m7D#LWqx&uh6%CQ=4hb$LG";
	#endif

	#ifndef NAME_H
	#define NAME_H
	class Name {
		private:
			std::string firstName;
            std::string middleName;
            std::string lastName;
		public:
            // Constructor
            Name(std::string fName, std::string mName, std::string lName);
            //Other functions
			std::string getFirst();
            std::string getMiddle();
            std::string getLast();
            std::string getFull();
		protected:
			// Protected Declarations
	};
	#endif

	#ifndef PHONE_H
	#define PHONE_H
	class Phone {
		private:
			int prefix;
            int number;
		public:
			// Constructor
            Phone(std::string, unsigned int);
            std::string getNumber();        //If number is 123-456-7890, it returns 12*-***-*890
            int sendText(std::string);
		protected:
			// Protected Declarations
	};
	#endif

	#ifndef ADDRESS_H
	#define ADDRESS_H
	class Address {
		private:
            int houseNo;
            char block;
            std::string colony;
            std::string landmark;
            std::string location;
            std::string city;
            std::string state;
            std::string country;
            int pincode;
		public:
			// Constructor
            Address(int HNO, char BLO, std::string COL, std::string LAN, std::string LOC, std::string CIT, std::string STA, std::string COU, int PIN);
            std::string getFull();  //Returns full address as string value
            int update(std::string);    //Function to update address value
            std::string getHNO();
            std::string getBLO();
            std::string getCOL();
            std::string getLAN();
            std::string getLOC();
            std::string getCIT();
            std::string getSTA();
            std::string getCOU();
            std::string getPIN();
		protected:
			// Protected Declarations
	};
	#endif

	#ifndef EMAIL_H
	#define EMAIL_H

	class Email {
		private:
			std::string header;      //Stores 'someone' from someone@example.com
            std::string host;       //Stores 'example.com' from someone@example.com
		public:
			// Constructor
            Email(std::string);
            std::string getEmail();     //If email is someone@example.com, returns so***ne@example.com
            int sendEmail(std::string);
		protected:
			// Protected Declarations
	};
	#endif

#endif
