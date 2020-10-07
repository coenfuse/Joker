#pragma once
#include<string>

	#ifndef NAME_H
	#define NAME_H
	class Name {
		private:
			std::string firstName;
            std::string middleName;
            std::string lastName;
		public:
            // Constructor
			Name();
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
			unsigned int prefix;
			unsigned short var1;
			unsigned short var2;
			unsigned short var3;
			void setPrefix(std::string);
			void setNumber(std::string);

		public:
			// Constructor
			Phone();
            Phone(std::string, std::string);
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
            unsigned short houseNo;
            char block;
            std::string colony;
            std::string landmark;
            std::string location;
            std::string city;
            std::string state;
            std::string country;
            unsigned int pincode;
		public:
			// Constructors
			Address();		//Default Constructor
            Address(unsigned short HNO, char BLO, std::string COL, std::string LAN, std::string LOC, std::string CIT, std::string STA, std::string COU, unsigned int PIN);
            int update(std::string, short key);    //Function to update address value
			std::string getFull();  //Returns full address as string value
            std::string getAddline1();
			std::string getAddline2();
			std::string getAddline3();
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
			// Constructors
			Email();		// Default Constructor
            Email(std::string);
            std::string getEmail();     //If email is someone@example.com, returns so***ne@example.com
            int sendEmail(std::string);
		protected:
			// Protected Declarations
	};
	#endif
