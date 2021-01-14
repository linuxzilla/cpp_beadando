#pragma once

#include <string>
#include <iostream>

using namespace std;

class Vehicle
{
public:
    Vehicle(string lpn, string m, int yom, int c, double usage);

    virtual string getDataFromated();

    string getLicensePlateNumber() {return licensePlateNumber;}
    string getModel() {return model;}
    int getYearOfManufacture() {return yearOfManufacture;}
    int getCapacity() {return capacity;}
    double getUsage() {return usage;}

    double setUsage(double value) {usage = usage + value;}

protected:
    int capacity;
    double usage;
    string licensePlateNumber;
    string model;
    int yearOfManufacture;
};
