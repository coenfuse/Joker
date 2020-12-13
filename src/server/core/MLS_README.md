# Multi-level scheduling
*This is an experimental concept that is planned to be implemented into Joker.*

At the grassroot level Joker does nothing that just flipping some specific variable values, and to be very specific it just flips ISSUED variable to either TRUE or FALSE.
Since its a distributed system where degree of concurrency is high, obtaining a read/write access to a file is very hard for competiting requests,
thus just like in many operating systems. Joker is planned to implement a multilevel queue where each of the queue will have an absolute priority over the queues below it.
Each of the queues are expected to maintain a round-robin scheduling individually to get processing time.
This should ensure much smoother experience for all the users to in the system and thus prevents a deadlock.
This is a complex topic to explain and it would be much better if there were relate illustrations to it, when the development hits this stage.
This document will surely be updated since its one of the most exciting parts of the system.
