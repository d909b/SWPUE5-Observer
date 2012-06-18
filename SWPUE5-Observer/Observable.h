/**
*
*  @file Observable.h
*  
*  Declaration of class Observable.
*
*  @author Patrick Schwab 
*  @date 5/23/12
*
*/

#pragma once

#include <vector>
#include "Observer.h"

/**
* @class Observable
*
* ${DESCRIPTION}
*
* @author Patrick Schwab
*/
class Observable {
public:
	Observable() {;}
    virtual ~Observable() {;}  
    
    void addObserver(Observer* observer) 
    {
        observers_.push_back(observer);
    }
    
    void removeObserver(Observer* observer)
    {
        std::vector<Observer*>::iterator it;
        
        for(it = observers_.begin(); it != observers_.end(); ++it)
        {
            if(*it == observer)
            {
                observers_.erase(it);
            }
        }
    }
    
protected:
    void notify()
    {
        Q_FOREACH(Observer* observer, observers_)
        {
            observer->valueChanged(this);
        }
    }
    
private:
    std::vector<Observer*> observers_;
};
