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
* ${DESCRIPTION}
*
* @author Patrick Schwab
*/
class Observer {
public:
	virtual void valueChanged(Observable* observable) = 0;
};
