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
