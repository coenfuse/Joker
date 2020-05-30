class Cycle
{
private:
    string id;
    enum status;
    string issued_from;
    string deposited_at;
    string issuer;
    static issue_count;
    bool health;
    string location;
protected:
public:
    getid()
    setid()
    getlocation()
    setlocation()
    getstatus()
    setstatus()
    getissuer()
    setissuer()
    gethealth()
    sethealth()
    getissue_loc()
    setissueloc()
    getdeposit_loc()
    setdeposit_loc()
    Cycle()     //ctor
    ~Cycle()    //dtor

// Responsibilites
};

class Lock
{
private:
    string id;
    string location;
    string std_ID;
    bool status;    //Locked or Unlocked
    string key;
    void encrypt()
    void decrypt()
    int open() //Opens the Lock
    int close() //Closes the Lock
protected:
public:
    getid()
    setid()
    getlocation()
    setlocation()
    getstandid()
    getstatus() //Uses key, encrypt(),decrypt(),open(),close()
    setstatus() //Uses key, encrypt(),decrypt(),open(),close()
    Lock()      //ctor
    ~Lock()     //dtor
//Responsibilites
};

class Stand
{
private:
    string id;
    enum status;    //Stand's status
    string name;
    string location;
    string loc_code;
    string capacity;
    Cycle cycle[]
    Lock lock[capacity]
    static unsigned int txn_count;
protected:
public:
    getcode()
    setcode()
    getstatus() //Stand's status
    setstatus()
    setname()
    getname()
    getlocation()
    setlocation()
    showcycles()
    updatecycles()
    Stand() //ctor
    ~Stand()    //dtor
//Responsibilites:
// Initializing Cycle objects present in it
// Facilitating in Issuing of the cycles
// Facilitating in Deposition of the cycles
// Cooperate with Bi to pass the locking code
};

class Database
{
//Thinking of incorporating this class in Bapi class itself
private:
protected:
public:
    integritycheck()
    fetchUserData()
    fetchCID()
    fetchEID()
    fetchStandData()
    fetchMapData()
    fetchCycleData()
    updateUserData()
    updateCID()
    updateEID()
    updateStandData()
    updateMapData()
    updateCycleData()

//Responsibilites
};

class Bi
{
//Bi's core reside here. It's a master class
private:
protected:
public:
    generatereport()
//Responsibilites
// The only front-end of Bi's software that will provide all the necessary API's for its usage.
};

class User
{
private:
    string firstname
    string middlename
    string lastname
    string fathername
    string mothername
    string guardian
    string dob
    string phone
    string email
    string address
    int login_count
protected:
public:
//Responsibilites
};

class Student : public User
{
private:
    string enr; //Enrollment number
    string department;
    string course;
    short course_year;
protected:
public:
//Responsibilites
};

class Employee : public User
{
private:
    string eid; //Employment ID
    string department;
    enum profile; //Job profile
protected:
public:
//Responsibilites
};

class Joker
{
//SuperUser of Bi network
private:
    string name;
    string username;
    string password;
protected:
public:
    deploy()
//Responsibilites
// Deploy Bi
// Expand Bi (Add Cycles, Add Stands)
// Edit Bi (Edit status of Bi, number of stands, number of cycles)
// Repair Bi
// Add Moderator
// Remove Moderator
// Revoke Access (Override Block/Unblock)
};

class Moderator
{
//Should I create this class in Joker itself? Doubt.
private:
    string name;
    string username;
    bool status; //Online or Offline
protected:
public:
//Responsibilites
};
