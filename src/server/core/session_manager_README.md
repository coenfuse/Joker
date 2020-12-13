# Session Manager
*Not to be confused with [Session Handler](), that is reponsible for maintaining session queues.*

Session manager is a simple system of co-routines that maintain and check the validity of a running login session in Joker.
It is yet to be implemented and currently is in theoretical phase.
The sole motive of this manager is to reduce inactivity in the system that is introduced by the human interaction.
A session manager mandates a time limit for inactivity for a session and if it exceeds, the session is closed and the user is logged out from the system.
Session manager is run in conjunction at both the Client and Server side. More detail into this later on.
