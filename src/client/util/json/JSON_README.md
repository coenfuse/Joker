# JSON System

Staying true to its intention of mimicking a web-application in a C++ project, Joker uses a proprietary JSON sub-system that acts as the communication backbone between Client and Server side. Unlike its name JSON doesn't works with any actual JSON files, instead it works with string data-type and deals with their serialization, deserialization etc. It can be said that JSON is an very expensive yet unncessary data wrapper that somehow improves the readability of code.
This introduction to JSON system is expected to give a distaste in the fingers of an efficient programmer and for sure it should. But once the development of JSON subsystem is complete, this documentation will be refreshed completely and a hope is there to remove the past bad experience.
Main points served by JSON:
- Mandates a standard of communication within Client and JSON
- Reduces the return type variance in BAPI
- Removes necessity of manual serialization and deserialization of data.

The actual development of JSON sub-system can be viewed [here.](https://github.com/coenfuse/JSON)
