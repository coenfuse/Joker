# Data Indexing
Data indexing is nothing but a simple indexing method employed by Joker that helps it in uniquely identifying data and accessing them without any collisions.
***This document is incomplete and is subject to undergo major changes as the development continues in this project.***
The different types of tags Joker uses to index its data is described below:

### User Tags
---
- **BID** --- Currently BID uses a simple **BIDxxx** string format that can uniquely identify only 1000 types of data.
As the development will run its course, the format of BID will also change.
It will then be pool of 16-bit alphanumeric code that will given to every user object in the system.
BID will override all the other sub-tags that Joker contains and it used for internal indexing within the system [Read More](## BID overriding other tags?).
This pool of BIDs will be available for a single network only i.e: it will be used for internal referecing withing the network's domain only.
Also, BID cannot be used alone to distinguish between data across networks. To do so, a combination of other data tags are recommended to used.

- **SID** --- This tag type carries the student ID or their enrollment number.
The responsibility of maintaining the 'uniqueness' in this tag is beyon the scope of Joker. Thus, omitted.
This tag will be used by the student USER to login into the system.

- **EID** --- This tag type behaves similar to SID (not enforcing uniqueness) and stores Employee ID (of faculty and other staff members).
This tag will be used by employee USER type to login into the system.

- **GID** --- GID will be the guest's username. This username is provided to the guest user upon logging into the system.
The username is fetched randomly from pool of undefined usernames. Internally, every guest user will have a unique identification tag with a format GIDxxxxxxxxxx.

- **ADM** --- ADM tag will contain the network administrator's usernames.
An admin can have a username of its choice, provided it doesn't conflicts with any existing username.

- **SUP** --- SUP tag will contain support agent's username, it will have a format of SUPxxxxxxxxxx.

- **MOD** --- MOD tag will contain moderator's username, it will have a format of MODxxxxxxxxxx.

### Network Tags
---
- **NET** --- Every **Network** in the Joker is uniquely identified with its network ID.
Currently the Network ID format is simply NETxxx chosen by careful consideration of the amount of multiple networks Joker can currently handle.
- **STD** --- Every **Stand** within a Network inside Joker will have its uniquely identifying stand ID. The string format will be STDxxxxxxxxxx.
- **CYC** --- Every **Cycle** within a network inside Joker will have its own unique identifier. The string format will be CYCxxxxxxxxxx.
- **LCK** --- Every **Lock** will have its own lock ID with the following format LCKxxxxxxxxxx.

### Other Tags
---
- **TXN** --- This tag will used to identify all the transaction data that is happening inside the network. The string format is TXNxxxxxxxxxx.
- **STAT** --- This tag is used to identify statistical data of both user and various network object in the system.
More details on this data type will be described once the development hits appropriate stage.

## BID overriding other tags?

As briefly mentioned, all the other tags in the user section of Joker are more or less influenced by variables outside of Joker.
The uniqueness of student's enrollment number or employee's employement ID is not always guaranteed.
Thus an internal indexing tag was needed so Joker can identify within its entities.
The tags like SID, GID, ADM etc are just an abstraction for the comfort of the user and used solely for cosmetic purposes. Joker uses BID internally.
