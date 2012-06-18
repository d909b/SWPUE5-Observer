/**
*
*  @file ClockModel.h
*  
*  Declaration of class ClockModel.
*
*  @author Patrick Schwab 
*  @date 5/23/12
*
*/

#pragma once

#include "Observable.h"

/**
* @class ClockModel
*
* This class represents a time model for clocks, including 
* seconds, minutes and hours.
*
* @author Patrick Schwab
*/
class ClockModel : public Observable {    
public:
	ClockModel(int h, int m, int s) : hours(h), minutes(m), seconds(s) {;}
    
    void setTime(int h, int m, int s) 
    {
        hours = h;
        minutes = m;
        seconds = s;
        
        notify();
    }
    
    int getHours()
    {
        return hours;
    }
    
    int getMinutes()
    {
        return minutes;
    }
    
    int getSeconds()
    {
        return seconds;
    }
private:
    int hours, minutes, seconds;
};
