#pragma once

#include <string>
#include <iostream>

using namespace std;

class Vehicle
{
public:
    Vehicle(string lpn, string t, int yom);
    string licensePlateNumber() {return licensePlateNumber_m;}
    string type() {return type_m;}
    int yearOfManufacture() {return yearOfManufacture_m;}

private:
    string licensePlateNumber_m;
    string type_m;
    int yearOfManufacture_m;
    double usageCurrent_m

};
