#pragma once

#include <iostream>
#include <string>
#include "vehicle.hpp"

using namespace std;

class Bus : public Vehicle
{
public:
    Bus(string lpn, string m, int yom, int c, double u) : Vehicle(lpn, m, yom, c, u) {}
    string getDataFromated();
};
