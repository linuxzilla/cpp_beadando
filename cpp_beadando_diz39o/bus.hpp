#pragma once

#include <iostream>
#include "vehicle.hpp"

using namespace std;

class Bus : public Vehicle
{
public:
    Bus(string lpn, string t, int yom, int c) : Vehicle(lpn, t, yom, c) {}
    string getDataFromated() {return "asd";}
};
