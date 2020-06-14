// Bi proposed algorithm by Sarthak, 25 Feb 2020
// Classes are defined in separate files.
// This file aims to provide you a brief idea of flow of control and few implementations. */

# include <header>
int main()
{
    system_boot();  //System boot up process.
    printf("\n\n Welcome to Bi \n\n");
    short unsigned int attempts = 0;
    do {
        menu(attempts);      // Basic UI of Bi.
        printf("Do you want to exit the session? [Y/N]");
        scan(choice);
    } while(choice == 'Y' || choice == 'y');
    return 0;
}

// Function definitions
void menu(int attempts){
    if (attempts >= 0 && attempts < 5) {
        printf("Please enter your Enrollment number or Employee ID: ");
        scanf(input);
        input = input_formatting(input);    //Formatting the Input.
        index = search_db(input);           //Returns search index or -1 on unsuccessful search.
        if (index == -1) {
            print("\nSorry. No such user found. Retry? [Y/N]");
            scanf(choice);
            if(choice == 'Y' || choice == 'y'){
                menu(++attempts);           //Increment of attempt count. Limited recursion.
            }
            else{
                printf("Bi will now close.");
                exit();
            }
        } else {
            session(index);
        }
    } else if (attempts >= 5) {
        printf("\n Too many incorrect attempts. Please try after sometime");
    } else {
        printf("\n\n\nABNORMAL BEHAVIOUR DETECTED. Bi will now close.");
        exit();
    }
}
void session(){
    // This is the most important section and I'm currently writing this. Will update you shortly.
}
int search_db(string){
    printf("Processing...")
    // Search functions that will traverse through the database. Possibly an OVERLOADED FUNCTION.
}
void read_db(){
    // Thinking of turning into a IO.class whose objects will be created by other objects present in the system. Let me know about this.
}
string input_formatting(string){
    // Simple overloaded function that will organize input string
}
void create_objects(){
    stand stand_list[];                                              // Empty array named stand that will contain objects of stand type.
    for (i = 0; until the number of stands required; i++) {    // Number of stands required are fetched from the stands_data.
        stand Stand;                                           // Creating an object of type stand named Stand
        stand_list[i] = Stand(initialization values);          // This will create stand objects and will store them in a array.
    }
    // Thinking of returning a pointer datatype for this.
    // Similarily process for cycles and locks.
    // This is a one time process and will happen only during 'System Boot' or 'Maintainence' because it'd be infeasible to manually create objects for stands and other entities as the network expands.
}
void create_users(){
    // This function is also plaqued with my slow thinking. Anyway. I will figure it out.
    // This will basically create user objects with default values INITIALLY (that will be fetched from database).
}
int check_db(int){
    // INCOMPLETE. This function just reads the database, checks for corruption and returns index values.
    index = read(map_data);         //This will consist of mapped/geographical data of the network i.e., location of stands and distance between each one of them.
    index = read(stands_data);      //This data will comprise of everything related to stands and will be useful in initializing the stand's object.
    index = read(enr_data);         //This data will co-relate to the university's database of enrollment number and will have everything attached to the enrollment number. This will be updated daily.
    index = read(eid_data);         //This data will co-relate to university's database of employee ID (for employees)
    index = read(cycle_data);       //This data will be in perspective with the individual cycles, this will have information for each cycle in the system (By whom hired, for how much, current status etc)
    index = read(bid_data);         //This data will use BID as indexing. It is not a single file but a group of files containing data about each user of the network.
    return index;
}
void system_boot(){
    printf("/nLoading Database. Please wait...");
    int read_status = check_db(); //This func will contain all set of different individual functions that will read different files of the database
    if(read_status == -1)       // Considering usage of Try and Catch statements here instead.
    {
        println("/nError occured while loading database. The system will now exit");
        exit(); // Or recall system_boot() to Restart the system. I don't know the consequences. Possibly Recurision.
    }
    else {
        println("/nDatabase loaded successfully");
    }
    printf("/nCreating Network Objects. Please wait...");
    create_objects();   // This function will create Stand, Cycle and Lock create_objects.
    create_users();     //This will create base user objects with default values ready to be activated.
}

//Stub Iterative Attempt 30 May 2020
main(){
    Bapi Bi;    //Creating an object of Bapi = Bi's API named Bi. Global Bi object.
    //The following code will be encapsulated inside new menu function.
    cout<<"Take CID or EID input";
    cin>>credentials;
    if(Bi.check_cred(credentials))
    {
        if(Bi.check_history(credentials)) //Checks pending issue status. Returns bool value.
        {
            deposit(credentials){
                //This will invoke the deposit function
            }
        }
        issue(credentials){
            //This will invoke the login process.
            Bi.notification(); //Someone logged into your account
            Bi.setloginstatus = TRUE; //Set user status to LOGGED IN
            session();
        }
    }
    cout<<"Invalid Input"; //else condition
}

//Stub Iterative Attempt 2 June 2020
using namespace std;
main(){
    /*
    KEEP WINDOW's INSTALLATION IN MIND. TO USE WINDOWS YOU NEED AN ADMINISTRATOR FIRST.
    SOFTWARE WILL SEARCH FOR ANY PRESENT JOKERS ON ITS JOKER RECORDS
    IF NONE EXIST
        create_joker()
            The system isn't configured yet. Please configure
            Take input parameters for Joker Attributes and create an Joker Object.
            Joker(Attributes accepted above)    //Constructor
            Save the PERSISTANT OBJECT in JOKER RECORDS that will be used on next boot-up.
            ~Joker()
    ELSE IF(ADMIN_EXIST()==TRUE && NETWORK_EXIST()==FALSE)      //If Joker exists but Network Doesnt
        Show drop_down list of Admins with number of networks in them.
        IF (LOGIN_Joker()==TRUE)    //Checks Login Credentials for an admin
            Create Joker Object;
            Take inputs to deploy a new Bi network in the system
            Joker.deployBi()
            Save in DB
            Logout();
            Restart the system. exit()
        ELSE print("INCORRECT INPUT BRUH")
    ELSE IF(ADMIN_EXIST()==TRUE && NETWORK_EXIST()==TRUE)       //If Joker exists and a Network too
        menu()

    OR BETTER, check the Configuration Attribute of Bi. If it is set to false then create a JOKER
    Otherwise proceed with that instance of Bi.


    It is like a hen and an egg dilemma.
    I am worrying about installation of Bi within Bi itself.
    During this initial bootup, the system will create an Admin Object that will later be used to use Bi.

    Check presence of any Admin account, if not present Create and Admin Object by invoking its object.
    To invoke the Joker object, take initial details about the admin. Basically sign-up system shit.
    The initial details will be used invoke Joker's constructor parameters. Save the information into a separate file.
    A network can have only one Admin, and an admin can create only one network on a system and it will have multiple moderators inside it. (THIS WILL BE CHANGED LATER)

    Once this is done, take input for creating a Bi's network (Number of Stands, Capacity of Cycles, Types of Users etc)
    Invoke Joker.deploy(input parameters)
    If Bi's database file are present
    */
}

// Bi Stub Attempt 3, June 13 2020 - 23:20
/*
Consider this example. Windows is a software that is an intermediary b/w USER & HARDWARE.
Windows provide methods (API) to the user so that he/she can use the hardware.
In this situation there isn't any control to what degree a User can access the hardware.
To control that, Windows introduced a requirement of creating an ADMINISTRATOR account.
The ADMINISTRATOR account have the most complete access to HARDWARE possible. BUT not COMPLETE ACCESS.
ADMINISTRATOR can configure the system to their needs and create instances for others.
If every USER had control scope like ADMIN then it would create a deadlock in conflicting requests.
It would require a consensus to mitigate a conflict but that'd be an inefficient on big system.
ADMINISTRATOR provides a required governance in the system.
ADMIN creates a small scale instance of Windows that uses Windows Functions to operate the system.
Not even ADMIN can have the direct access to core system properties.
ADMIN can CREATE or DELETE users that will have limited access (only what they need).
If there is some problem in the Windows, then it tells Users to 'CONTACT SYSTEM ADMINISTRATOR'
SYSTEM ADMINISTRATOR or simply the ADMIN, with help of much larger access could solve the lower issues.
This keeps the system more operable and robust.
Also note that there are many critical functions in Windows that are beyond the access scope of any object in the system.
For eg; Bootstrap Program Location, Main Installation Directry, Registry Files even Login information for Users, etc.
They are usually Kernel functions and generally immutable values that are required for normal system operation.
=================================================================
Learning from this, Bi will work on the same principle.
In Bi, the operable hardware is Stand, Cycle, Lock and Database Server.
Having a direct access to any of these systems is a massive security loophole.
The library functions will provide APIs to access there. Basically ports to operate these hardware.
The objects in the system (Joker, Moderator, User, Bi, Cycle, Stand, etc) will have access to these APIs.
But none of these objects will have DIRECT access to all the APIs provided. This will ensure security in the system.
Joker will create an INSTANCE of Bi that will have Cycles, Stands, Locks etc in it.
Joker will have the highest access to configure the CONSTRUCTED instance of Bi network.
Moderators work under Joker but above Users. They have limited control to Bi network using Bi API.
Users will have access to basic APIs (maybe not a single one directly).
The Joker will have limited DIRECTED access to Bi API but Bi class will have vast access to Bi API.
The Bi Class will work in conjunction with the Database Class that will itself use Database API.
See, only system classes (Bi and Database) have the most access to Bi API.
And human operated object has a very limited access to the system and thus, it increases system's security.


GLOBAL INFORMATION
- Bi is a system or basically a small scale operating system.
- This OS will process Issue and Deposit of bicycles in a network.
- One could make only 1 Bi network in this OS (currently)
- This Bi network will have AT LEAST one Admin. Can have more than one.
- A network without an Admin is regarded 'Unconfigured Network' and will be inoperable.
- Bi will have some function libraries that will help in managing the OS itself. Functions that cannot be used in Bi class.
- These libraires CANNOT be accessed without a proper mechanism.
- These libraries will be used as API for front-end software later on.
- Libraries currently conceptualized: BiCore, BiDatabase
- BiCore can ONLY be accessed by JOKER(admin).
- BiDatabase will provide low handle data about the Bi OS itself. It might also provide prototypes for other DB objects.
- During first bootup, Bi will check its configuration data and will require at least one JOKER to operate.
- After that save that information which can be used for other regular sessions.
- On regular bootup, Bi will provide two interface with 3 options: Login as User, Moderator and JOKER.

LOCAL INFORMATION (Here Bi refers to Bi class that only JOKER can initialize)
- Bi HAS Stands that themselves HAVE Cycles AND Locks in them (Has-A relationship, Composition)
- Stand, Cycle and Locks have a cardinality of 1 to n.
- Bi USES Database
- Database will operate Database Libraries that will be updated routinely
- Employee AND Student ARE-A User (is-a relationship, Inheritance)
- Joker MANAGES Moderator, Not Vice-versa
- Moderators will have a limited control of the Bi API and much control of the Bi Network.
- Moderators can only be created and deleted by JOKER.
- Joker can MANAGE the SOURCE DATA from Database API
- Joker will CONVERT the IMPORTED data INTO Bi's OPERATIONAL data. (Rel.DB to Obj.Orie.DB)
- Joker will CREATE the initial copy (or Genesis Copy) of the data on which the Bi will operate.
- Joker CONTROLS Bi from BOTH outside and inside
- Moderator MANAGES User(s) and CONTROLS Bi from ONLY inside.

*/
