#include "..\include\classes\JSON.h"
#include <string>

JSON::JSON(std::string input, int func){
    /* Variable func specifies what type of string file we are receiving as an input and what kind of JSON object a user is expecting.
    func(0) = network data,
    func(1) = stand data,
    func(2) = cycle data,
    func(3) = lock data,
    func(4) = transaction data,
    func(5) = admin data,
    func(6) = student data,
    func(7) = employee data,
    */
    switch (func) {
        case 0:{
            //Code to convert Network string
        }
        break;
        case 1:{
            //Code to convert Stand string
        }
        break;
        case 2:{
            //Code to convert Cycle string
        }
        break;
        case 3:{
            //Code to convert Lock string
        }
        break;
        case 4:{
            //Code to convert Transaction string
        }
        break;
        case 5:{
            //Code to convert Admin string
        }
        break;
        case 6:{
            //Code to convert Student string
        }
        break;
        case 7:{
            //Code to convert Employee string
        }
        break;
        case 'default':{
            //Code for default string conversion
        }
        break;
    }
}
