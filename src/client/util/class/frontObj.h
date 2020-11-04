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
			std::string getFirstName();
            std::string getMiddleName();
            std::string getLastName();
            std::string getName();
		protected:
			// Protected Declarations
	};
	#endif

	#ifndef PHONE_H
	#define PHONE_H
	class Phone {
		private:
			unsigned int prefix;		// Contains 91 of (91) 123-456-7890
			unsigned short var1;		// Contains 123 of (91) 123-456-7890
			unsigned short var2;		// Contains 456 of (91) 123-456-7890
			unsigned short var3;		// Contains 7890 of (91) 123-456-7890
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
            std::string area;
            std::string city;
            std::string state;
            std::string country;
            unsigned int pincode;
		public:
			// Constructors
			Address();		//Default Constructor
            Address(unsigned short HNO, char BLO, std::string COL, std::string LAN, std::string AREA, std::string CIT, std::string STA, std::string COU, unsigned int PIN);
            int update(std::string, short key);    //Function to update address value
			std::string getFull();  //Returns full address as string value
            std::string getAddline1();		// Returns HNO + BLO + COL
			std::string getAddline2();		// Returns LAN + AREA + CIT
			std::string getAddline3();		// Returns STA + COU + PIN
			std::string getHNO();
            std::string getBLO();
            std::string getCOL();
            std::string getLAN();
            std::string getAREA();
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
			// Ctor and Dtor
			Email();		// Default Constructor
            Email(std::string);

			//Methods
            std::string getEmail();     //If email is someone@example.com, returns so***ne@example.com
            int sendEmail(std::string);
		protected:
			// Protected Declarations
	};
	#endif

	#ifndef COORDINATE_H
	#define COORDINATE_H
	class Coordinate {
	private:
		float longitude;
		float latitude;
	public:
		//Ctor and Dtor
		Coordinate();	//Default Constructor
		Coordinate(float longitude, float latitude);
		~Coordinate();

		//Methods
		//float[2] getCoordinates(); // Consider removal
		float getLongitude();
		float getLatitude();
	};
	#endif