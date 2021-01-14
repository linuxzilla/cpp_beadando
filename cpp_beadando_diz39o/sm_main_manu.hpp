#pragma once

#include <string>
#include <array>

#include "vehicle.hpp"
#include "bus.hpp"
#include "excavator.hpp"
#include "truck.hpp"

class Sm_main_menu
{
public:
    enum States
    {
        ST_DRAW_MAIN_MENU,
        ST_ADDNEW_VEHICLE,
        ST_LIST_VEHICLES_DATA,
        ST_LIST_VEHICLES_BY_ID,
        ST_USAGE_BY_CATEGORY,
        ST_SET_LIMIT_BY_CATEGORY,
        ST_LIST_VEGICLES_OVERUSED,
        ST_EXIT
    };

    Sm_main_menu() :
        currentSate(ST_DRAW_MAIN_MENU), stateIndex(0), limitBus(100), limitTruck(100), limitExcavator(100) {}

    States getCurrentState()
    {
        return currentSate;
    }
    void executeMainMenu();

private:
    array<Vehicle*, 100> vehicles;

    States currentSate;
    int stateIndex;
    double limitBus;
    double limitTruck;
    double limitExcavator;

    enum AddNewVehicleStates
    {
        ST_LICENSE_PLATE_NUMBER,
        ST_MODEL,
        ST_YEAR,
        ST_CAPACITY,
        ST_USAGE,
        ST_CATEGORY,
        ST_DONE
    };

    struct NewVehicle
    {
        string licencPlate;
        string model;
        int year;
        int capacity;
        double usage;
    };

    void AddNewVehicle();
    void ListAllVehicle();
    void ListVehicleByLicence(string licence);
    void SumUsageByCategory();
    void SetUsageLimitByCategory();
    void ListOverUsedVehicles();
    void DeleteArray();
};
