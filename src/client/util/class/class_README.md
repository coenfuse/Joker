# Interfaces and Framework
To enforce a project-wide standard on the architecture of several components,
Joker uses a structure of defining the framework and distributing it for its implementation wherever necessary.
One example where this approach is implemented in Joker is when the Client uses BAPI.
BAPI, along with supplying API headers also provides virtual classes that needs to implemented whenever they are inheritied.
A User interface will contain stubs for trivial functionalities meanwhile it will supply its own definition for *issue* and *deposit* functions that cannot be overriden.
This does two benefits, it prevents re-writing of code and enforces a standard for certain definitions in the program that are regarded critical for core functioning.
