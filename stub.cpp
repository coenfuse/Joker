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

//Functions defs for BiUI
bool loginAdmin();
void sessionAdmin();
bool loginMod();
void sessionMod();

//Functions defs for Kernel library (Kernel stores critical information and functions of System)
bool checkBiKernel();
void updateBiKernel();

//Functions defs for Database Library (Database stores global data about the System)
bool checkBiData();
void saveBiData();
bool checkJokerRecord();
void updateJokerRecord();
void updateJokerData();
void checkJokerData();
void updateBiConfig();

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
                biFrontEnd();   // This will require a certain parameter. Refer to func. def.
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
    if (checkBiData()){
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
    if(checkJokerRecord()){
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
    cout<<"Admin named" + admin.getname() + "created. Please wait while we save the information";
    updateJokerRecord(admin); // This record saves the LOG of ADMIN(s) present in the system in a list.
    updateJokerData(admin);  // This will save data about an individual data securely in the system Database.
    cout<<"Information saved successfully";
}
bool checkBiConfig(Joker){
    //This function checks whether a particular Admin has a configured network underneath him/her.
    //i.e.; an operable Bi network instance that knows its Name, Admin and Attributes in it (no. of cycles, stands, etc)
    if(checkJokerData()){
        return TRUE;
    }
    else return FALSE;
}
void configureBi(Joker){
    // This function will configure the Bi network in the system.
    cout<<"Welcome to Bi's configuration screen. Here you'll configure the attributes of your own Bi network";
    cout<<"Enter name of your Network"; cin>>a;
    cout<<"Enter Number of Stands in your network"; cin>>b;
    cout<<"Enter capacity of each stand"; cin>>c;
    cout<<"Number of moderators (if any?)"; cin>>d;
    //And some other attributes
    updateBiConfig(Joker,a,b,c,d=0);
    cout<<"Your Bi network is configured";
}
int biFrontEnd(Joker){
    cout<<"Welcome to Bi Network" + Joker.getBiName();
    cout<<"Proceed as:";
    cout<<"To login as Admin: Press 1";
    cout<<"To login as Moderator: Press 2";
    cout<<"To login as User: Press 3";
    cin>>input;
    switch(input){
        case 1:
            cout<<"Enter your credentials";
            //Add a loop here
            if(loginAdmin(credentials)){
                sessionAdmin();
            }
            else cout<<"Incorrect Input";
            exit();
            break;
        case 2:
            cout<<"Enter your credentials";
            //Add a loop here
            if(loginMod(credentials)){
                sessionMod();
            }
            else cout<<"Incorrect Input";
            exit();
            break;
        case 3:
            cout<<"Enter you CID or EID";
            cin>>credentials;
            if(Bi.check_cred(credentials))
            {
                if(Bi.check_history(credentials)) //Checks pending issue status. Returns bool value.
                {
                    Bi.deposit(credentials){
                        //This will invoke the deposit function
                    }
                }
                Bi.issue(credentials){
                    //Accidently wrote the implementation here, it should be in the class.
                    //This will invoke the login process.
                    User User(credentials);
                    User.notification(); //Someone logged into your account
                    User.setloginstatus = TRUE; //Set user status to LOGGED IN
                    //The whole issue procedure comes here.
                }
            }
            cout<<"Invalid Input"; //else condition
            break;
        case default: cout<<"Invalid Choice";
        exit()
    }
}

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
bool checkJokerRecord(){
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
    if(Joker.getConfigStatus()){
        return TRUE;
    }
    else FALSE;
}
void updateBiConfig(Joker,string,int,int,int){
    //Some update procedure Here
    Joker.setConfigStatus(TRUE);
}
