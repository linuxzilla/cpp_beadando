#include "vehicle.hpp"

Vehicle::Vehicle(string lpn, string m, int yom, int c, double u)
 : licensePlateNumber(lpn), model(m), yearOfManufacture(yom), capacity(c), usage(u) {}

string Vehicle::getDataFromated(){}
