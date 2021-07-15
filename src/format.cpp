#include <string>

#include "format.h"

#define HOUR 3600
#define MIN 60

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) {
    string HH, MM, SS;
    int hour=seconds/HOUR;
    int second=seconds % HOUR;
    int minute=second/MIN;
    second = second % MIN;
    if(hour%10 == hour){
        HH = "0"+std::to_string(hour);
    }
    else{
        HH = std::to_string(hour);
    }

    if(minute%10 == minute){
        MM = "0"+std::to_string(minute);
    }
    else{
        MM = std::to_string(minute);
    }

    if(second%10 == second){
        SS = "0"+std::to_string(second);
    }
    else{
        SS = std::to_string(second);
    }

    return HH + ":" + MM + ":" + SS;
}