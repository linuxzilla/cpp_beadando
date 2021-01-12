#pragma once

#include <string>
#include <array>

#include "bus.hpp"
#include "excavator.hpp"
#include "truck.hpp"

class Sm_main_manu
{
public:
    enum States {
        ST_DRAW_MAIN_MANU,
        ST_ADDNEW_VEHICLE,
        ST_LIST_VEGICLES_DATA,
        ST_LIST_VEGICLES_BY_ID,
        ST_USAGE_BY_CATEGORY,
        ST_SET_LIMIT_BY_CATEGORY,
        ST_LIST_VEGICLES_OVERUSED,
        ST_EXIT
    };

    Sm_main_manu() : currentSate(ST_DRAW_MAIN_MANU), stateIndex(0) {}

    States getCurrentState() {return currentSate;}
    void executeMainMenu();

private:
    States currentSate;
    int stateIndex;
};
