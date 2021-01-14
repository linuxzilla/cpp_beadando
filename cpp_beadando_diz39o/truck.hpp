#pragma once

#include <iostream>
#include "vehicle.hpp"

using namespace std;

class Truck : public Vehicle
{
public:
    Truck(string lpn, string m, int yom, int c, double u) : Vehicle(lpn, m, yom, c, u) {}
     string getDataFromated();
};
