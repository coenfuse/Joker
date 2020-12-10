# BAPI
---
Bapi (short for Bi API) is the most critical connection point of this project. Bapi provides a wide set of API headers that enable Client to fetch useful information from the Server in a systematic manner. Currently Bi's API is divided into multiple parts:
- **USER** - APIs returning data about all user type and related objects of the system.
- **NETWORK** - APIs return data about the rest 'inactive' network objects.
- **...**
- **...**
- **...**

## What else does BAPI provides?
BAPI enforces few communication protocols between Client and Server using various enumerations. It is planned to provide interfaces and frameworks to the Client side that then can be implemented as per requirement but still preserving the internal protocol of the ecosystem. A more detailed description elaborating upon *What, Why and How* certain procedures and components are transfered through BAPI is coming very soon. In short, **BAPI** is the single most important link in the Joker project and enforces essential standards that are required in Joker.

***Disclaimer*** : The development of this documentation has been halted until the devlopment of [JSON](https://github.com/coenfuse/JSON) is complete. BAPI is expected to undergo major structural changes once the JSON sub-component is incorporated into Joker.

### USER
----
| Response Type | Header          | Required Parameters                                                                                                                            | Example Input | Example Response |
|---------------|-----------------|------------------------------------------------------------------------------------------------------------------------------------------------|---------------|------------------|
| **bool**      | is_present      | **string** access_code, **string** NET, **string** username, **short** usertype                                                                |               |                  |
| **string**    | authorize_login | **string** access_code, **string** NET, **string** username, **string** salt, **short** usertype                                               |               |                  |
| **short**     | logout          | **string** access_code, **string** session_code, **string** BID, string NET, **JSON** user_data, **JSON** log_dat                              |               |                  |
| **string**    | get_all         | **string** access_code, **string** session_code, **string** NET, **string** BID_requested_by, **short** usertype                               |               |                  |
| **string**    | get             | **string** access_code, **string** session_code, **string** BID_requested_by, **short** usertype                                               |               |                  |
| **string**    | update_all      | **string** access_code, **string** session_code, **string** BID_requested_by, **string** NET, short action                                     |               |                  |
| **string**    | update          | **string** access_code, **string** session_code, **string** BID_requested_by, **string** NET, **string** BID_to_be_updated, **JSON** user_data |               |                  |
| **string**    | update          | **string** access_code, **string** session_code, **string** BID_requested_by, **string** NET, **string** BID_to_be_updated                     |               |                  |
| **string**    | add_multiple    | **string** access_code, **string** session_code, **string** BID_requested_by, **string** NET, **JSON** multiple_user_data, **short** action    |               |                  |
| **string**    | add             | **string** access_code, **string** session_code, **string** BID_requested_by, **string** NET, **JSON** user_data, **short** action             |               |                  |
| **string**    | remove          | **string** access_code, **string** session_code, **string** BID_requested_by, **string** NET, **string** BID_to_remove, **short** action       |               |                  |

### NETWORK
----
API's specific to general lock functions of the network

### NETWORK::STAND
----
API's specific to stands within the network

### NETWORK::CYCLE
----
API's specific to cycles within the network

### NETWORK::LOCK
----
API's specific to locks within the network

### NETWORK::TXN
----
API's specific to transactions within the network

***This documentation has been made with the help of Dillinger.io and tablesgenerator.com***
