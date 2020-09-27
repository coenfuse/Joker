#include "bisystem.h"
#include<string>
#include<fstream>

//Name's Implementations
Name::Name(std::string fName, std::string mName, std::string lName){
    firstName = fName;
    middleName = mName;
    lastName = lName;
}

Name::getfirst(){
    return firstName;
}

Name::getMiddle(){
    return firstName;
}

Name::getLast(){
    return firstName;
}

Name::getFull(){
    std::fname = firstName + " " middleName + " " + lastName;
    return fname;
}

// Phone's Implementations
Phone::Phone(std::string number, unsigned int code){
    //Value of Code derived by intrinsic numbering of countries in ascending order.
    //This code will be then used to fetch country's calling code from local database.
    prefix = isd[code];

}
