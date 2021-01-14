#include "excavator.hpp"

#include <string>
#include <sstream>

using namespace std;

string Excavator::getDataFromated()
{
    ostringstream stringStream;
    stringStream << "Excavator - ";
    stringStream << "Licence plate number: ";
    stringStream << licensePlateNumber << " ";
    stringStream << "Model: ";
    stringStream << model << " ";
    stringStream << "Manufactured: ";
    stringStream << to_string(yearOfManufacture) << " ";
    stringStream << "Capacity: ";
    stringStream << to_string(capacity) << " kW ";
    stringStream << "Usage: ";
    stringStream << to_string(usage) << " work hours/week";
    return stringStream.str();
}
