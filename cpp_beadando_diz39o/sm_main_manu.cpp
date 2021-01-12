#include "sm_main_manu.hpp"

#include <string>
#include <array>

using namespace std;

void Sm_main_manu::executeMainMenu()
{
    string buffer;

    switch(currentSate)
    {
    case ST_DRAW_MAIN_MANU:
        break;
    case ST_ADDNEW_VEHICLE:
        break;
    case ST_LIST_VEGICLES_DATA:
        break;
    case ST_LIST_VEGICLES_BY_ID:
        break;
    case ST_USAGE_BY_CATEGORY:
        break;
    case ST_SET_LIMIT_BY_CATEGORY:
        break;
    case ST_LIST_VEGICLES_OVERUSED:
        break;
    default:
        break;
    }
}
