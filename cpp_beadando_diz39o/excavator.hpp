#pragma once

#include <iostream>
#include "vehicle.hpp"

using namespace std;

class Excavator : public Vehicle
{
public:
    Excavator(string lpn, string m, int yom, int c, double u) : Vehicle(lpn, m, yom, c, u) {}
    string getDataFromated();
};
