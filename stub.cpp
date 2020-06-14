#include<iostream>
//Other Library Headers that should contain functions given below
//Functions defs for BiCore library (BiCore is the available API for Bi users)
bool checkBiInstallation();
void installBi();
bool checkJoker();
void createJoker();
bool checkBiConfig();
void configureBi();
int biFrontEnd();

//Functions defs for Kernel library (Kernel stores critical information and functions of System)
bool checkBiKernel();
void updateBiKernel();

//Functions defs for Database Library (Database stores global data about the System)
bool checkBiData();
void saveBiData();
bool checkJokerRecords();
void updateJokerRecord();
void updateJokerData();
void checkJokerData();

//Main program
using namespace std;
int main()
{
    if(checkBiInstallation())
    {
        if(checkJoker())
        {
            if(checkBiConfig()) // This will require a certain parameter. Refer to func. def.
            {
                biFrontEnd();
            }
            else configureBi(); // This will require a certain parameter. Refer to func. def.
        }
        else createJoker();
    }
    else installBi();
}

// BiCore implementations
bool checkBiInstallation(){
    //This function will check existing Bi configurations in the system.
    if (fetchBiData()){
        return TRUE;
    }
    else return FALSE;
}
void installBi(){
    //This function will install the Bi in the system.
    cout<<"Installing...";
    void saveBiData();
    cout<<"Bi installed Successfully";
    cout<<"Want to create a system Admin? [Y/N]";
    createJoker();
    cout<<"Want to configure a Bi network? [Y/N]";
    configureBi();
}
bool checkJoker(){
    //This function will check presence of any existing ADMINS in the system.
    if(checkJokerRecords()){
        return TRUE;
    }
    else return FALSE;
}
void createJoker(){
    //This function will create the first admin of the system.
    //This function will take input from user to INITIALIZE a new JOKER object.
    cout<<"Enter Desired Username";
    cout<<"Enter Desired Password";
    Joker admin("Admin", "password"); // And some other parameter values
    cout<<"Admin named" + Joker.getname() + "created. Please wait while we save the information";
    updateJokerRecord(admin); // This record saves the LOG of ADMIN(s) present in the system in a list.
    updateJokerData(admin);  // This will save data about an individual data securely in the system Database.
}
bool checkBiConfig(Joker){
    //This function checks whether a particular Admin has a configured network underneath him/her.
    //i.e.; an operable Bi network instance that knows its Name, Admin and Attributes in it (no. of cycles, stands, etc)
    if(checkJokerData()){
        return TRUE;
    }
    else return FALSE;
}
void configureBi(){
    
}
int biFrontEnd(){}

// Kernel implementations
bool checkBiKernel(){
    //This function will check the Bi installation Data.
    return TRUE;
}
void updateBiKernel(){
    //This function will save the actual data of the installation in the system.
    cout<<"Updating Bi Kernel files. Don't turn off the system";
}

// Database implementations
bool checkBiData(){
    //This function will read the basic installation location data from Database
    if(checkBiKernel()){
        return TRUE;
    }
    else return FALSE;
}
void saveBiData(){
    //This function will save the attributes of Bi into an installation LOG.
    cout<<"Updating Registery Files";
    updateBiKernel();
}
bool checkJokerRecords(){
    //This function will check read the files in system for presence of ADMIN
    return TRUE;
}
void updateJokerRecord(Joker){
    string name = Joker.getname();
    // Some datahandling updating method, that will add the 'name' into JokerRecords.dat
}
void updateJokerData(Joker){
    string name = Joker.getname();
    string password = Joker.getpassword();
    //Create a new file if not present and save this attribute data in possibly encrypted data.
}
void checkJokerData(Joker){
    //Possibly an overloaded function that serves many needs. Requires revison.
    if(Joker.configStatus()){
        return TRUE;
    }
    else FALSE;
}
