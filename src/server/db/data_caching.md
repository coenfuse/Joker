# Data Caching

Data Caching is a process planned to be employed by Joker to keep a specified amount of user data into cache memory before writing it to the files on the hard-drive. Joker is planned to employ a Queue of defined length that will carry data of the recent Logins in the system. If a user logs in again into the system, the data retreiver will first search the queue for existing data, if found, it would pop that data from the queue and work upon it. Once the user is fininshed with its usage, the 'updated data' is now added again at the tail of the queue waiting to be written onto the files unless it is popped again.

![Data Caching Illustration](https://github.com/coenfuse/Joker/blob/master/docs/Data_Caching.png)
