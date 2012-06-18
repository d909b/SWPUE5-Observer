/**
*
*  @file Observer.h
*  
*  Declaration of class Observer.
*
*  @author Patrick Schwab 
*  @date 5/23/12
*
*/

#pragma once

class Observable;

/**
* @class Observer
*
* This interface represents an Observer watching over an Observable object's state changes.
*
* @author Patrick Schwab
*/
class Observer {
public:
    /**
     *  This callback is triggered on every state change of the observed Observable.
     */
	virtual void valueChanged(Observable* observable) = 0;
};
