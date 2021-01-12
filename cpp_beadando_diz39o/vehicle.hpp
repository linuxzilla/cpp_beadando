#pragma once

#include <string>
#include <iostream>

using namespace std;

class Vehicle
{
public:
    Vehicle(string lpn, string t, int yom, int c);

    virtual string getDataFromated() = 0;

    string getLicensePlateNumber() {return licensePlateNumber;}
    string getType() {return type;}
    int getYearOfManufacture() {return yearOfManufacture;}
    int getCapacity() {return capacity;}
    double getUsage() {return usage;}

protected:
    int capacity;
    double usage;
private:
    string licensePlateNumber;
    string type;
    int yearOfManufacture;
};
