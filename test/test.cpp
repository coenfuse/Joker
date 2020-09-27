/*
	Name: Test Driving Code
	Author: Sarthak Sharma
	Date: 25-09-20 17:41
	Description: Test file to run various compilation tests
*/
#include<iostream>
#include "modules.h"
#include "bisystem.h"
using namespace std;

int main(){
	cout<<access_code;
	int a;
    a = area(98);
    cout<<"\nArea of circle with radius 98 is: "<<a;
    cout<<"\n"<<perimeter(88, 23);
    return 0;
}
