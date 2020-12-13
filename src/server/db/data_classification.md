# Data Classification
Data inside Joker is classified into many smaller categories for organizational purposes. Since the prototype is still in early stages, Joker currently employs STL data structures to organize files. The actual structure that will govern the storage of files in various location is yet to defined but the basic idea is to sort the data by Object types which is further subdivided into individual files for each object.
For example, whole structure can be divided into 2 primary categories:
- **Non-Static Data** : Containing data of objects that updates frequently, eg: Users, Network, etc.
- **Static Data** : Containing data of objects that updates comparatively less frequently, eg: Stands, Cycle, etc.

Out of these, take one for demonstration purpose. We take **Non-Static Data**, this section of data will contain many sub-categories containing similar type of data. In the **User_DAT** folder, instead of maintaining a single file for user data, we make individual data file for every user. The biggest benefit of doing this is that it avoids the Reader-Writer Problem (or at least reduces its impact by significantly.)
The data_manager now doesn't have to wait for any parallel running process that might have locked the access to the file.

***It is assumed that large scale concurrency problem with this classification method is only going to show its effect once Joker allows ability of simultaneous login for same User at multiple endpoints. Considering the current structural capacity of Joker, this scenario is extremely unlikely even while running the automated bots due to their controlled behavior tree.***
