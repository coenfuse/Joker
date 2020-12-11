# Automated Robots for Joker (Experimental)
---
*This is a planned feature for Joker and is subject to undergo various changes in future*

Joker is prototype for Bi that is multi-user web application supposed to be working across various devices in the campus. Bi enjoys the ability to dive head-first into distributed enviroment to prove is metal and developed accordingly. But Joker, being just a prototype limited to single-user system it doesn't have natural opputunity to test its processing ability for multiple-users. Thus the idea of creating simple automated robots for Joker was conceived.
Fundametally, these bots will be very simple and would use a ***predefined behaviour tree*** that would govern their behaviour at various stages.
![Joker bots behavior tree structure](https://github.com/coenfuse/Joker/blob/master/docs/Behavior%20Tree.jpg)

The functioning of this tree is pretty simple. At the root of the behavior tree we have the common starting node for a robot's behaviour (expected to be a Login function). Now all the levels below this will have **predefined** sets of behavior that will include everything necessary except what's in the level above them (here, Login). This is used to prevent illegal behavior direction i.e.: Once the bot has logged into the system, it would need to log into it again so login function is not needed.

Even though the flow of behavior is controlled, the robot will have the ability to choose any random behavior at a certain level. This pseudorandom behavior of bots is expected to be enough to test the multi-processing ability of Joker

## How a valid behavior flow might look like?
As mentioned as we go down the levels of behavior, the range of possible options to choose from reduces for the robot, thus at the leaf nodes the robot is expected to do only one thing, even though the path to it might be different everytime the robot is told to run.

An invalid flow of behavior might look like this:
**Login  ---> View Account ---> Logout ---> Issue ---> Update Data ---> END**

*Here **Logout** is supposed to be the ending action of a robot. Logically, nothing else should be available to proceed to once the robot hits this stage but cleary here it executes **Issue** command and proceeds naturally. This abnormal behavior will do nothing except stressing out the BAPI unncessarily with invalid commands.*

A valid flow of behavior must be something like this:
**Login ---> View Account ---> Issue ---> View Account ---> Logout ---> END**

*Here we can see the behavior of robot is within valid range of behavior and closely mimics a real-life human interaction with Joker.*

## How these Robots will be implemented?
This is the tricky part. But current idea is to create a basic Robot class that will generate Robot objects on the fly, apart from containing a predefined behavior tree, the robots will contain a small memory module that will help it to make more logical decision. For example, consider a robot that has issued a cycle to its name, it would be very illogical for the robot to run for another time and request another issuing for the cycle (A user can issue only one cycle at a time). Thus a robot will remember a limited set of its previous actions and act accordingly (here, instead of requesting a Issue call again, it would then call for Deposit request or something else that is in the valid range). The last most important component of this robot will be the analytical engine. This simple engine will read and understand the responses given from the API to act accordingly. More details in this section of documentation will be added later on.

## How these Robots will be used in the system?
It is planned to provide a dial to the 'real' user to control the amounts of robots he/she would like to run in the system. Once the number of robots to run is defined, the robots will be created an distributed among available threads on the system. These threads will then run in parallel providing space of robots to exhibit their behavior. Eventually, mimicing a real-time multi-user experience at Joker.
