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
* This class represents an observable object.
* Observable objects' state changes may be watched by Observers.
* To notify an Observables' Observers notify() must be called after a state change.
*
* @author Patrick Schwab
*/
class Observable {
public:
	Observable() {;}
    virtual ~Observable() {;}  
    
    /**
     * Registers an observer with the Observable object.
     *
     * @param observer The observer to be registered.
     */
    void addObserver(Observer* observer) 
    {
        observers_.push_back(observer);
    }
    
    /**
     * Removes an observer from the list of observers.
     *
     * @param observer The Observer to be removed.
     */
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
    /**
     *  Notifies the Observables' observers of state changes.
     */
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
